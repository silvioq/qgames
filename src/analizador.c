/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/


#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <stdarg.h>
#include  <qgames.h>
#include  <qgames_code.h>

#include  "list.h"
#include  "tipojuego.h"
#include  "pieza.h"
#include  "movida.h"
#include  "posicion.h"
#include  "analizador.h"

#include  "log.h"

#define  MARCAS_Q         16    // hasta 16 marcas!
#define  CHECK_STATUS     if( z->status != STATUS_NORMAL ) return STATUS_ERROR;
#define  CHECK_END_CODE   if( z->tipo_analisis != ANALISIS_FINAL ) return STATUS_ERROR;

_list*   analizador_evalua_movidas( Regla* regla, Posicion* pos, Pieza* pieza, Casillero* cas, char tipoanalisis, int tipomovida, int color ){

    Analizador* z = (Analizador*)malloc( sizeof( Analizador ) );
    _list* movidas ;

    memset( z, 0, sizeof( Analizador ) );
    // z->pos     = posicion_dup(pos);   // OPTIMIZE: Dejar de utilizar el puntero para tenerlo estatico
    posicion_copy( &z->pos, pos );
    z->pieza   = posicion_get_pieza(&z->pos,pieza);
    z->cas     = cas;
    z->cas_ori = cas;
    z->color   = color;
    z->tipo_analisis = tipoanalisis;
    z->tmov    = tipomovida;
    LOGPRINT( 6, "Inicio analisis pieza %s casillero %p %s tipomovida = %d", 
          z->pieza->tpieza->nombre, 
          z->cas_ori, ( !CASILLERO_VALIDO(z->cas_ori) ? "(no)" : z->cas_ori->nombre ),
          z->tmov );

    code_execute_rule( z, regla->pc );

    if( z->flags & CON_TRANSFORMACION ) movida_split_transformaciones( z->movidas );

    if( z->mov_actual ) movida_free( z->mov_actual );
    movidas = z->movidas;
    
    LOGPRINT( 6, "Fin analisis pieza casillero %s %p %s Movidas %p", 
          z->pieza->tpieza->nombre, 
          z->cas_ori, ( !CASILLERO_VALIDO(z->cas_ori) ? "(no)" : z->cas_ori->nombre ), 
          movidas );

    if( z->marcas ) free( z->marcas );
    posicion_free_data( ZPOSICION(z) );
    free( z );


    return movidas;

}

int      analizador_evalua_final  ( Regla* regla, Posicion* pos, Pieza* pieza, Casillero* cas, int color, int color_siguiente, char** resultado ){

    Analizador* z = (Analizador*)malloc( sizeof( Analizador ) );
    int  ret;
    memset( z, 0, sizeof( Analizador ) );
    posicion_copy( &z->pos, pos );
    z->cas     = cas;
    z->cas_ori = cas;
    z->pieza = pieza;
    z->color = color;
    z->color_siguiente = color_siguiente;
    z->tipo_analisis = ANALISIS_FINAL;

    if( regla->tregla != END ){
        LOGPRINT( 1, "Regla debe ser de final (%d)", regla->tregla );
        return STATUS_ERROR;
    }
    code_execute_rule( z, regla->pc );

    LOGPRINT( 6, "Fin del analisis de final status = %d", z->status );

    if( z->status == STATUS_EOG ){
        if( resultado ) *resultado = strdup( z->resultado );
        ret =  z->color_ganador ? z->color_ganador : FINAL_EMPATE;
        LOGPRINT( 4, "Fin de partida detectado %d => %s", ret, z->resultado );
        if( z->resultado ) free( z->resultado ); 
    } else ret =  FINAL_ENJUEGO;
    posicion_free_data( ZPOSICION(z) );
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
    Pieza *p;
    int i;
    if( z->tipo_analisis == ANALISIS_ATAQUE ) return 0;
    CHECK_STATUS ;
    if( !CASILLERO_VALIDO(ccc) ) return 0;
    Posicion* pos = posicion_dup( &z->pos );
    if( TIPOJUEGO_CAPTURAIMPLICITA(z->pos.tjuego ) ){
        for( i = 0; i < pos->piezas_count; i ++ ){
            p = & pos->piezas[i];
            if( p->number != z->pieza->number && p->casillero == ccc ) p->casillero = OUTOFBOARD ;
        }
    }
    for( i = 1; i <= z->pos.tjuego->colores; i ++ ){
        if( z->color == i ) continue;
        Movida* mov;
        LOGPRINT( 6, "Inico de analisis para color %d en %s", i, ccc->nombre );
        posicion_analiza_movidas( pos, ANALISIS_ATAQUE, i, 0, NULL );
        list_inicio( pos->movidas );
        while( mov = (Movida*) list_siguiente( pos->movidas ) ){
            if( movida_casillero_destino( mov ) == ccc ){
                posicion_free( pos );
                return 1;
            }
        }
    }
    posicion_free( pos );
    return 0;
}

/*
 * Esta funcion evalua si la movida anterior tuvo como destino
 * el casillero pasado como parametro
 * */
int    analizador_destino_ant( Analizador* z, Casillero* cas ){
    Casillero* ccc = ( cas ? cas : z->cas );
    LOGPRINT( 6, "Viendo destino anterior en %s", ccc->nombre );
    if( !ccc ) return 0;
    if( !z->pos.mov_anterior ) return 0;
    Casillero* ret = movida_casillero_destino( z->pos.mov_anterior );
    LOGPRINT( 6, "Destino anterior fue %s", CASILLERO_VALIDO(ret)? ret->nombre : "(no se)" );
    return( ccc == ret );
}

/*
 * Esta funcion evalua si la movida anterior tuvo como origen
 * el casillero pasado como parametro
 * */
int    analizador_origen_ant( Analizador* z, Casillero* cas ){
    Casillero* ccc = ( cas ? cas : z->cas );
    if( !ccc ) return 0;
    if( !z->pos.mov_anterior ) return 0;
    return( ccc == movida_casillero_origen( z->pos.mov_anterior ) );
}


/*
 * El cuenta piezas, funcion fundamental para saber cuantas piezas
 * hay de un determinado tipo ... je je!
 * Los parametros son el casillero donde buscar, el color que buscar
 * (puede ser PROPIO, ENEMIGO, CUALQUIERA o un color determinado)
 * y un tipo de pieza específico 
 * */

int    analizador_cuenta_piezas( Analizador* z, Casillero* cas, int owner, Tipopieza* tpieza ){

    Pieza* p;
    int  total = 0, i;
    LOGPRINT( 6, "Pregunta por cuentapiezas al casillero %s owner = %d tipo pieza %s", 
            ( cas ? cas->nombre : "Sin casillero" ),
            owner, 
            ( tpieza ? tpieza->nombre : "Sin tpieza" ) );              

    for( i = 0; i < z->pos.piezas_count; i ++ ){
        p = &(z->pos.piezas[i] );
        // Controlo si me pasaron el casillero
        if( cas && cas != p->casillero ) continue;
        if( (!cas) && !CASILLERO_VALIDO( p->casillero ) ) continue;
        // Controlo si me pasaron el tipo de pieza
        if( tpieza  && tpieza != p->tpieza ) continue;
        // Controlo el tema del color
        if( owner != CUALQUIERA ){
            if( owner == PROPIO && p->color != z->color ) continue;
            if( owner == ENEMIGO && p->color == z->color ) continue;
            if( owner >  0 && p->color != owner ) continue;
        }
        total ++;
    }
    LOGPRINT( 6, "Devuelve %d", total );

    return total;


}



/*
 * Devuelve uno o cero, si se encuentra ocupado el casillero pasado como parametro
 * Detalle:
 *  cas  : Casillero. Si es nulo, toma el casillero actual
 *  owner: Dueño. Puede ser ENEMIGO, PROPIO, CUALQUIERA o un color
 *
 *  */

int    analizador_ocupado( Analizador* z, Casillero* cas, int owner, Tipopieza* tpieza ){
    Casillero*  ccc = ( cas ? cas : z->cas );
   
    CHECK_STATUS ;
    if( CASILLERO_VALIDO(ccc) ){
        LOGPRINT( 6, "Pregunta por ocupado al casillero %s owner = %d tipopieza = %s", 
            ccc->nombre, owner, tpieza ? tpieza->nombre : "(cualquiera)" );
    } else {
        return 0;
    }
    int i;
    for( i = 0; i < z->pos.piezas_count; i ++ ){
        Pieza* pp = &(z->pos.piezas[i]);
        if( pp == z->pieza ) continue;
        if( tpieza && tpieza != pp->tpieza ) continue;
        if( pp->casillero == ccc ){
            if( owner == CUALQUIERA ){
                return  1;
            } else if( owner == PROPIO ){
                if( z->color == pp->color ){ LOGPRINT( 6, " ... ocupado propio  %d", 1 ); return 1; }
            } else if( owner == ENEMIGO ) {
                if( z->color != pp->color ){ LOGPRINT( 6, " ... ocupado enemigo %d", 1 );return 1; }
            } else if( pp->color == owner ){ LOGPRINT( 6, " ... ocupado %d", 1 ); return 1; }
        }
    }
    LOGPRINT( 6, " ... no ocupado %d", 0 );
    return 0;

}

/*
 * Devuelve verdadero o falso, dependiendo si actualmente
 * estamos en el tablero o hemos salido de el
 * */
int    analizador_entablero( Analizador* z ){
    return( CASILLERO_VALIDO(z->cas) );
}

/*
 * Esta funcion setea la marca pasada como parametro, con el casillero
 * definido. Si el casillero es nulo, entonces tomara el actual
 * */
int    analizador_setmarca( Analizador* z, int marca, Casillero* cas){
    Casillero* ccc = ( cas ? cas : z->cas );
    CHECK_STATUS;
    if( !z->marcas ) z->marcas = malloc( sizeof( Casillero* ) * MARCAS_Q );
    if( marca >= MARCAS_Q ){
        LOGPRINT( 1, "Error cantidad de marcas pedidas %d >= %d", marca, MARCAS_Q );
        return  STATUS_ERROR;
    }
    z->marcas[marca] = ccc;
    return  STATUS_NORMAL;
}

/*
 * Esta funcion setea la marca pasada como parametro, con el casillero
 * definido. Si el casillero es nulo, entonces tomara el actual
 * */
int    analizador_gotomarca( Analizador* z, int marca){
    CHECK_STATUS;
    if( !z->marcas ){ 
        LOGPRINT( 1, "Marca no seteada %d", marca );
    }
    if( marca >= MARCAS_Q ){
        LOGPRINT( 1, "Error cantidad de marcas pedidas %d >= %d", marca, MARCAS_Q );
        return  STATUS_ERROR;
    }
    if( z->marcas[marca] ) z->cas = z->marcas[marca];
    return  STATUS_NORMAL;
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

    if( z->tipo_analisis == ANALISIS_FINAL ){
        for( i = 0; i < z->pos.piezas_count; i ++ ){
            Pieza* ppp = &(z->pos.piezas[i]);
            if( !CASILLERO_VALIDO(ppp->casillero ) ) continue;
            if( ppp->color != colorcheck ) continue;
            if( tpieza && ppp->tpieza != tpieza ) continue;
            if(  tipojuego_casillero_en_zona( z->pos.tjuego, ppp->casillero, zona, colorcheck ) ){
                LOGPRINT( 6, "En zona acertó! zona=%d color=%d cas=%s tpieza=%p", zona, colorcheck, ppp->casillero->nombre, tpieza );
                return 1;
            }
        }
    } else {
        if( tipojuego_casillero_en_zona( z->pos.tjuego, z->cas, zona, z->color ) ){
            LOGPRINT( 6, "En zona acertó! zona=%d color=%d cas=%s tpieza=%p", zona, z->color, z->cas->nombre, tpieza );
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
    if( !z->mov_actual ) z->mov_actual = movida_new( &z->pos, z->pieza, z->tmov );
    movida_accion_mueve( z->mov_actual, z->pieza, ccc );
    LOGPRINT( 6, "Juega %s en %s captura = %d", z->pieza->tpieza->nombre, ccc->nombre, con_captura );
    if( TIPOJUEGO_CAPTURAIMPLICITA(z->pos.tj) || con_captura ){
        analizador_captura( z, ccc );
/*        int i;
        for( i = 0; i < z->pos.piezas->entradas; i ++ ){
            Pieza* pp = (Pieza*)z->pos.piezas->data[i];
            if( pp == z->pieza ) continue;
            if( pp->casillero == ccc){
                movida_accion_captura( z->mov_actual, pp );
            }
        }*/
    }
    list_agrega( z->movidas, z->mov_actual );
    z->mov_actual = NULL;
    return  STATUS_NORMAL;
}


int    analizador_mueve  ( Analizador* z, char fromto_flags, void* from, void* to ){
    Casillero* cas_from;
    Casillero* cas_to;
    int  marca, i;
    switch((fromto_flags&FROM_MASK)){
        case  FROM_AQUI:
            cas_from = z->cas;
            break;
        case  FROM_MARCA:
            marca = (long)from;
            if( marca >= MARCAS_Q ){
                LOGPRINT( 1, "Error cantidad de marcas disponibles %d >= %d", marca, MARCAS_Q );
                return STATUS_ERROR;
            }
            cas_from = z->marcas[marca];
            break;
        case  FROM_CASILLERO:
            cas_from = (Casillero*) from;
            break;
        default:
            LOGPRINT( 1, "From-To flags contiene un valor incorrecto %x", fromto_flags );
            return STATUS_ERROR;
    }
    if( !CASILLERO_VALIDO( cas_from ) ) return STATUS_OUTOFBOARD;

    switch((fromto_flags&TO_MASK)){
        case  TO_AQUI:
            cas_to = z->cas;
            break;
        case  TO_MARCA:
            marca = (long)to;
            if( marca >= MARCAS_Q ){
                LOGPRINT( 1, "Error cantidad de marcas disponibles %d >= %d", marca, MARCAS_Q );
                return STATUS_ERROR;
            }
            cas_to = z->marcas[marca];
            break;
        case  TO_CASILLERO:
            cas_to = (Casillero*)to;
            break;
        default:
            LOGPRINT( 1, "From-To flags contiene un valor incorrecto %x", fromto_flags );
            return STATUS_ERROR;
    }
    if( !CASILLERO_VALIDO( cas_to ) ) return STATUS_OUTOFBOARD;

    int hay_piezas = 0;
    for( i = 0; i < z->pos.piezas_count; i ++ ){
        Pieza* pp = &(z->pos.piezas[i]);
        if( !pp ) continue;
        if( pp == z->pieza ) continue;
        if( pp->casillero == cas_from ){
            if( !z->mov_actual ) z->mov_actual = movida_new( &z->pos, z->pieza, z->tmov );
            LOGPRINT( 6, "Mueve %s a %s", pp->tpieza->nombre, cas_to->nombre );
            movida_accion_mueve( z->mov_actual, pp, cas_to );
            hay_piezas = 1;
        }
    }
    if( !hay_piezas ) LOGPRINT( 3, "Atencion, no habia piezas en %s", cas_from->nombre );
    return  STATUS_NORMAL;

}



int    analizador_captura  ( Analizador* z, Casillero* cas  ){
    CHECK_STATUS ;
    Casillero* ccc = ( cas ? cas : z->cas );
#if(OUTOFBOARD_ISERROR)
    if( !CASILLERO_VALIDO( ccc ) ) return STATUS_OUTOFBOARD;
#else
    if( !CASILLERO_VALIDO( ccc ) ) return STATUS_NORMAL;
#endif
    if( !z->movidas ) z->movidas = list_nueva( NULL );
    if( !z->mov_actual ) z->mov_actual = movida_new( &z->pos, z->pieza, z->tmov );
    int i;
    for( i = 0; i < z->pos.piezas_count; i ++ ){
        Pieza* pp = &(z->pos.piezas[i]);
        if( pp == z->pieza ) continue;
        if( pp->casillero == ccc){
            movida_accion_captura( z->mov_actual, pp );
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
    dir2 = tipojuego_dir_by_sym( z->pos.tjuego, dir, z->color );
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
    if( z->pieza ) posicion_mueve_pieza( &z->pos, z->pieza, z->cas );
    return  STATUS_NORMAL;
}


int   analizador_casillero( Analizador* z, Casillero* cas ){
    CHECK_STATUS;
  
    LOGPRINT( 6, "Estoy en %s moviendome hacia %s%s", 
            (CASILLERO_VALIDO(z->cas) ? z->cas->nombre : "?" ), 
            (cas ? cas->nombre : z->cas_ori->nombre ),  
            (cas ? ""  : " (original)" ) );
    z->cas = cas ? cas : z->cas_ori;
    if( z->pieza && CASILLERO_VALIDO( z->cas ) ) posicion_mueve_pieza( &z->pos, z->pieza, z->cas );
    return  STATUS_NORMAL;
}

int    analizador_jaquemate( Analizador* z, Tipopieza* tpieza ){
    int i;
    LOGPRINT( 6, "jaquemate: Ingresa a controlar jaquemate para pieza %s", tpieza->nombre )
    if( !analizador_ahogado( z ) ) return 0;
    LOGPRINT( 6, "jaquemate: esta ahogado %s", tpieza->nombre )
    for( i = 1; i <= z->pos.tjuego->colores ; i ++ ){
        if( i == z->color ) continue;
        if( posicion_en_jaque( &z->pos, tpieza, i ) ){
            LOGPRINT( 6, "jaquemate: la posicion esta en jaquemate para %s", tpieza->nombre );
            return 1;
        }
    }
    LOGPRINT( 6, "jaquemate: la posicion no era jaque %s", tpieza->nombre )
    return 0;
}

int    analizador_transforma( Analizador* z, int owner, Tipopieza* tpieza, int flags ){
    CHECK_STATUS;
    int color;

    if( !z->mov_actual ) z->mov_actual = movida_new( &z->pos, z->pieza, z->tmov );
    if( !flags ){
        if( owner == ENEMIGO ){
            color = z->color + 1;
            if( color > z->pos.tjuego->colores ) color = 1;
        } else if ( owner == CAMBIOCOLOR ){
            color = z->pieza->color + 1;
            if( color > z->pos.tjuego->colores ) color = 1;
        } else if ( owner == PROPIO ){
            color = z->color;
        } else if ( owner == NOCOLOR ){
            color = z->color;
        } else if ( owner > 0 ){
            color = owner;
        }
        z->flags |= CON_TRANSFORMACION;
        LOGPRINT( 6, "transformando %s en %s", z->pieza->tpieza->nombre, tpieza->nombre );
        movida_accion_transforma( z->mov_actual, z->pieza, color, tpieza );
    } else if( flags == FROM_AQUI ) {
        int i;
        for( i = 0; i < z->pos.piezas_count; i ++ ){
            Pieza* pp = &(z->pos.piezas[i]);
            if( !pp ) continue;
            if( pp == z->pieza ) continue;
            if( pp->casillero == z->cas ){
                if( owner == ENEMIGO ){
                    color = z->color + 1;
                    if( color > z->pos.tjuego->colores ) color = 1;
                } else if ( owner == CAMBIOCOLOR ){
                    color = pp->color + 1;
                    if( color > z->pos.tjuego->colores ) color = 1;
                } else if ( owner == PROPIO ){
                    color = z->color;
                } else if ( owner == NOCOLOR ){
                    color = z->color;
                } else if ( owner > 0 ){
                    color = owner;
                }
                z->flags |= CON_TRANSFORMACION;
                movida_accion_transforma( z->mov_actual, pp, color, tpieza );
                LOGPRINT( 6, "transformando %s", pp->tpieza->nombre );
            }
        }
    } else {
        return  STATUS_ERROR;
    }
    return  STATUS_NORMAL;
}

int    analizador_asigna_att( Analizador* z, int att, int val ){
    if( !z->mov_actual ) z->mov_actual = movida_new( &z->pos, z->pieza, z->tmov );
    movida_accion_asigna_att( z->mov_actual, z->pieza, att, val );
    return  STATUS_NORMAL;
}

int    analizador_evalua_att( Analizador* z, int att ){
    int ret = pieza_get_att( z->pieza, att );
    LOGPRINT( 6, "Evaluando atributo %s de %s = %d", att, z->pieza->tpieza->nombre, ret );
    return  ret;
}

/*
 * El analisis de ahogado es muy simple. 
 * Tomo el proximo color (en el caso que haya alguno, armo una 
 * nueva posicion e intento mover ... si hay alguna movida
 * entonces NO es ahogado!
 * */
int   analizador_ahogado( Analizador* z ){
    Posicion* pos = posicion_dup( &z->pos );
    int i;
    if( !z->color_siguiente ){
        LOGPRINT( 2, "Error, color siguiente no definido %p", z );
        return 0;
    }
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
            z->resultado     = malloc( 256 );
            sprintf( z->resultado, "%s Gana", tipojuego_get_colorname( z->pos.tjuego, z->color_ganador ) );
            break;
        case PIERDE:
            z->color_ganador = ( color ? tipojuego_get_coloroponente( z->pos.tjuego, color ) : z->color_siguiente );
            z->status        = STATUS_EOG;
            z->resultado     = malloc( 256 );
            sprintf( z->resultado, "%s Pierde", tipojuego_get_colorname( z->pos.tjuego, ( color ? color : z->color ) ) );
            break;
        default:
            LOGPRINT(1, "Resultado entrante %d incorrecto", res );
            return STATUS_ERROR;
    }
    return z->status;
}

