/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/


#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <assert.h>
#include  <stdarg.h>
#include  <qgames.h>

#include  "list.h"
#include  "simbolos.h"
#include  "tipojuego.h"
#include  "pieza.h"
#include  "movida.h"
#include  "posicion.h"
#include  "analizador.h"

#include  "log.h"

#define  CHECK_STATUS     assert( z->status == STATUS_NORMAL );
#define  CHECK_END_CODE   assert( z->tipo_analisis == ANALISIS_FINAL );

_list*   analizador_evalua_movidas( Regla* regla, Posicion* pos, Pieza* pieza, Casillero* cas, char tipoanalisis, int tipomovida, int color ){

    Analizador* z = (Analizador*)ALLOC( sizeof( Analizador ) );
    _list* movidas ;
    memset( z, 0, sizeof( Analizador ) );
    z->pos = pos;
    z->pieza = pieza;
    z->cas   = cas;
    z->color = color;
    z->tipo_analisis = tipoanalisis;
    z->tipo_movida   = tipomovida;

    code_execute_rule( z, regla->pc );
    movidas = z->movidas;
    free( z );

    return movidas;

}

int      analizador_evalua_final  ( Regla* regla, Posicion* pos, Pieza* pieza, Casillero* cas, int color, int color_siguiente, char** resultado ){

    Analizador* z = (Analizador*)ALLOC( sizeof( Analizador ) );
    int  ret;
    memset( z, 0, sizeof( Analizador ) );
    z->pos = pos;
    z->cas   = cas;
    z->pieza = pieza;
    z->color = color;
    z->color_siguiente = color_siguiente;
    z->tipo_analisis = ANALISIS_FINAL;

    assert( regla->tregla == END );
    code_execute_rule( z, regla->pc );

    LOGPRINT( 6, "Fin del analisis de final status = %d", z->status );

    if( z->status == STATUS_EOG ){
        if( resultado ) *resultado = z->resultado;
        ret =  z->color_ganador ? z->color_ganador : FINAL_EMPATE;
        LOGPRINT( 4, "Fin de partida detectado %d => %s", ret, z->resultado );
        if( z->resultado ) free( z->resultado );
    }       
    else ret =  FINAL_ENJUEGO;
    free( z );
    return ret;

}

/*
 * Devuelve uno o cero, si se encuentra ocupado el casillero pasado como parametro
 * Detalle:
 *  cas  : Casillero. Si es nulo, toma el casillero actual
 *  owner: Dueño. Puede ser ENEMIGO, PROPIO, CUALQUIERA o un color
 *
 *  */

int    analizador_ocupado( Analizador* z, Casillero* cas, int owner ){
    Casillero*  ccc = ( cas ? cas : z->cas );
   
    CHECK_STATUS ;
    if( CASILLERO_VALIDO(ccc) )  LOGPRINT( 6, "Pregunta por ocupado al casillero %s owner = %d", ccc->nombre, owner );
    int i;
    for( i = 0; i < z->pos->piezas->entradas; i ++ ){
        Pieza* pp = (Pieza*)z->pos->piezas->data[i];
        if( pp->casillero == ccc ){
            if( owner == CUALQUIERA ){
                return  1;
            } else if( owner == PROPIO ){
                if( z->color == pp->color ){ LOGPRINT( 6, " ... ocupado %d", 1 ); return 1; }
            } else if( owner == ENEMIGO ) {
                if( z->color != pp->color ){ LOGPRINT( 6, " ... ocupado %d", 1 );return 1; }
            } else if( pp->color == owner ){ LOGPRINT( 6, " ... ocupado %d", 1 ); return 1; }
        }
    }
    LOGPRINT( 6, " ... no ocupado %d", 1 );
    return 0;

}



int    analizador_juega  ( Analizador* z, Casillero* cas, int con_captura ){
    CHECK_STATUS ;
    if( !z->movidas ) z->movidas = list_nueva( NULL );
    Movida* mov = movida_new( z->pos );
    movida_accion_mueve( mov, z->pieza, ( cas ? cas : z->cas ) );
    list_agrega( z->movidas, mov );
    if( con_captura ){
        int i;
        for( i = 0; i < z->pos->piezas->entradas; i ++ ){
            Pieza* pp = (Pieza*)z->pos->piezas->data[i];
            if( pp->casillero == cas && pp != z->pieza ){
                movida_accion_captura( mov, pp );
            }
        }
    }
    return  STATUS_NORMAL;
}



int   analizador_direccion( Analizador* z, Direccion* dir ){

    Vinculo* v;
    CHECK_STATUS;
    assert( CASILLERO_VALIDO( z->cas ) );
    v = casillero_busca_vinculo_origen( z->cas, dir );
    if( !v ){
        z->status = STATUS_OUTOFBOARD;
        z->cas    = OUTOFBOARD;
        return STATUS_OUTOFBOARD;
    }

    z->cas = v->destino;
    return  STATUS_NORMAL;
}


int   analizador_casillero( Analizador* z, Casillero* cas ){
    CHECK_STATUS;
  
    z->cas = cas;
    return  STATUS_NORMAL;
}


/*
 * El analisis de ahogado es muy simple. 
 * Tomo el proximo color (en el caso que haya alguno, armo una 
 * nueva posicion e intento mover ... si hay alguna movida
 * entonces NO es ahogado!
 * */
int   analizador_ahogado( Analizador* z ){
    Posicion* pos = posicion_dup( z->pos );
    int i;
    assert( z->color_siguiente );
    i = posicion_analiza_movidas( pos, ANALISIS_PRIMER_MOVIDA, z->color_siguiente, 0, NULL );
    LOGPRINT( 6, "Llamando a posicion_analiza_movidas, para obtener ahogado con color %d resultado %d", z->color_siguiente, i );
    posicion_free( pos );
    return i > 0 ? 0 : 1;

}




int   analizador_final( Analizador* z, int color, int res ){
    CHECK_STATUS;
    CHECK_END_CODE;

    LOGPRINT( 6, "Se llama al final color %d, resultado %d", color, res );

    switch( res ){
        case EMPATA:
            z->color_ganador = 0;
            z->status        = STATUS_EOG;
            z->resultado     = strdup( "Draw" );
            break;
        case GANA:
            z->color_ganador = ( color ? color : z->color );
            z->status        = STATUS_EOG;
            z->resultado     = ALLOC( 256 );
            sprintf( z->resultado, "%s Gana", tipojuego_get_colorname( z->pos->tjuego, z->color_ganador ) );
            break;
        case PIERDE:
            z->color_ganador = ( color ? tipojuego_get_coloroponente( z->pos->tjuego, color ) : z->color_siguiente );
            z->status        = STATUS_EOG;
            z->resultado     = ALLOC( 256 );
            sprintf( z->resultado, "%s Pierde", tipojuego_get_colorname( z->pos->tjuego, ( color ? color : z->color ) ) );
            break;
        default:
            assert( !"Resultado entrante incorrecto" );
    }
    return z->status;
            
    
}

