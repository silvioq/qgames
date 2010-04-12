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
    z->cas_ori = cas;
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
    z->cas_ori = cas;
    z->pieza = pieza;
    z->color = color;
    z->color_siguiente = color_siguiente;
    z->tipo_analisis = ANALISIS_FINAL;

    assert( regla->tregla == END );
    code_execute_rule( z, regla->pc );

    LOGPRINT( 6, "Fin del analisis de final status = %d", z->status );

    if( z->status == STATUS_EOG ){
        if( resultado ) *resultado = strdup( z->resultado );
        ret =  z->color_ganador ? z->color_ganador : FINAL_EMPATE;
        LOGPRINT( 4, "Fin de partida detectado %d => %s", ret, z->resultado );
        if( z->resultado ) free( z->resultado ); 
    }       
    else ret =  FINAL_ENJUEGO;
    free( z );
    return ret;

}

/*
 * Devuelve uno o cero, dependiendo si el casillero pasado como parametro
 * esta siendo atacado por el "enemigo" (o sea, todos los colores que no 
 * son el actual).
 * Para ello se ejecutan las movidas posibles por el adversario.
 * */
int    analizador_atacado( Analizador* z, Casillero* cas ){
    Casillero* ccc = cas ? cas : z->cas;
    int i;
    Posicion* pos;
    CHECK_STATUS ;
    if( !CASILLERO_VALIDO(ccc) ) return 0;
    for( i = 1; i <= z->pos->tjuego->colores; i ++ ){
        pos = posicion_dup( z->pos );
        Movida* mov;
        if( z->color == i ) continue;
        posicion_analiza_movidas( pos, ANALISIS_ATAQUE, i, 0, NULL );
        list_inicio( pos->movidas );
        while( mov = (Movida*) list_siguiente( pos->movidas ) ){
            if( movida_casillero_destino( mov ) == ccc ){
                posicion_free( pos );
                return 1;
            }
        }
    }
    return 0;
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
    if( CASILLERO_VALIDO(ccc) ){
        LOGPRINT( 6, "Pregunta por ocupado al casillero %s owner = %d", ccc->nombre, owner );
    } else {
        return 0;
    }
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

int    analizador_entablero( Analizador* z ){
    return( CASILLERO_VALIDO(z->cas) );
}

/*
 * Esta funcion revisa si en la zona especificada, se encuentra alguna pieza
 * del color pasado como parametro.
 * color: Dueño. Puede ser ENEMIGO, PROPIO, CUALQUIERA o un color
 * */
int    analizador_enzona( Analizador* z, int zona, int color, Tipopieza* tpieza ){
    CHECK_STATUS;
    int  i;
    int  colorcheck = ( color == PROPIO ? z->color : color );
    for( i = 0; i < z->pos->piezas->entradas; i ++ ){
        Pieza* ppp = (Pieza*)z->pos->piezas->data[i];
        if( !CASILLERO_VALIDO(ppp->casillero ) ) continue;
        if( ppp->color != colorcheck ) continue;
        if(  tipojuego_casillero_en_zona( z->pos->tjuego, ppp->casillero, zona, colorcheck ) ){
            LOGPRINT( 6, "En zona acertó! zona=%d color=%d cas=%s", zona, colorcheck, ppp->casillero->nombre );
            return 1;
        }
    }
    LOGPRINT( 6, "Zona salio por cero %d", zona );
    return 0;
}

#ifndef OUTOFBOARD_ISERROR
#define  OUTOFBOARD_ISERROR 0
#endif

int    analizador_juega  ( Analizador* z, Casillero* cas, int con_captura ){
    CHECK_STATUS ;
    Casillero* ccc = ( cas ? cas : z->cas );
#if(OUTOFBOARD_ISERROR)
    if( !CASILLERO_VALIDO( ccc ) ) return STATUS_OUTOFBOARD;
#else
    if( !CASILLERO_VALIDO( ccc ) ) return STATUS_NORMAL;
#endif
    if( !z->movidas ) z->movidas = list_nueva( NULL );
    Movida* mov = movida_new( z->pos );
    movida_accion_mueve( mov, z->pieza, ccc );
    list_agrega( z->movidas, mov );
    if( con_captura ){
        int i;
        for( i = 0; i < z->pos->piezas->entradas; i ++ ){
            Pieza* pp = (Pieza*)z->pos->piezas->data[i];
            if( pp->casillero == ccc){
                movida_accion_captura( mov, pp );
            }
        }
    }
    return  STATUS_NORMAL;
}



int   analizador_direccion( Analizador* z, Direccion* dir ){

    Vinculo* v;
    Direccion* dir2;
    CHECK_STATUS;
#if  OUTOFBOARD_ISERROR
    if( !CASILLERO_VALIDO( z->cas ) ) return STATUS_OUTOFBOARD;
#else
    if( !CASILLERO_VALIDO( z->cas ) ) return STATUS_NORMAL;
#endif
    dir2 = tipojuego_dir_by_sym( z->pos->tjuego, dir, z->color );
    v = casillero_busca_vinculo_pororigen( z->cas, dir2 );
    if( !v ){
        LOGPRINT( 6, "Estoy en %s moviendome hacia %s ... me voy del tablero", z->cas->nombre, dir2->nombre );
#if  OUTOFBOARD_ISERROR
        z->status = STATUS_OUTOFBOARD;
        z->cas    = OUTOFBOARD;
        return STATUS_OUTOFBOARD;
#else
        z->cas    = OUTOFBOARD;
        return STATUS_NORMAL;
#endif
    }

    LOGPRINT( 6, "Estoy en %s moviendome hacia %s ... mi destino es %s", 
              z->cas->nombre, dir2->nombre, v->destino->nombre );
    z->cas = v->destino;
    return  STATUS_NORMAL;
}


int   analizador_casillero( Analizador* z, Casillero* cas ){
    CHECK_STATUS;
  
    z->cas = cas ? cas : z->cas_ori;
    LOGPRINT( 6, "Estoy en %s moviendome hacia %s%s", z->cas->nombre, 
            cas ? cas : z->cas_ori, 
            cas ? ""  : " (original)" );
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
    if( i == 0 ) LOGPRINT( 6, "Dio ahogado controlando en color %d", z->color_siguiente );
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

