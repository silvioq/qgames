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
#include  "analizador.h"
#include  "posicion.h"

#include  "log.h"





/* ---------------------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------------------- */
void  posicion_free_movidas( Posicion* pos ){
    if( pos->movidas ){
        int  i;
        for( i = 0; i < pos->movidas->entradas; i ++ ){
            Movida* mov = (Movida*)pos->movidas->data[i];
            movida_free( mov );
        }/*
        list_free( pos->movidas );
        pos->movidas = NULL;*/
        pos->movidas->entradas = 0;
    }
}

void  posicion_add_movida( Posicion* pos, Movida* mov ){
    if( !pos->movidas ) pos->movidas = list_nueva( NULL );
    list_agrega( pos->movidas, mov );
}

void  posicion_add_movidas( Posicion* pos, _list* movs ){
    int i;
    for( i = 0; i < movs->entradas; i ++ ){
        Movida* m = (Movida*) movs->data[i];
        m->pos = pos;
        posicion_add_movida( pos, m );
    }
}


/*
 * Una posicion nueva!
 * */

Posicion*   posicion_new( Tipojuego* tj ){
  Posicion* pos;
  pos = malloc( sizeof( Posicion ) );
  memset( pos, 0, sizeof( Posicion ) );
  pos->tjuego = tj;
  return  pos;
}

void      posicion_free( Posicion* pos ){
    if( pos->movidas ){
        posicion_free_movidas( pos );
        list_free( pos->movidas );
    }
    if( pos->piezas ){
        int i;
        for( i = 0; i < pos->piezas_count; i ++ ){
            pieza_att_free( &pos->piezas[i] );
        }
    }
    free(pos);
}


Pieza*     posicion_get_pieza( Posicion* pos, Pieza* pieza ){
    if( !pos->piezas ) return  NULL;
    return &pos->piezas[pieza->number];
}

/*
 * Recorro las movidas que tengo e intento descartarlas por
 * posibles jaques a las piezas que se le puede hacer 
 * jaquemate
 * */
void        posicion_descartar_por_jaques( Posicion* pos, _list* movs, int color ){
    if( !TJJAQUEMATE(pos->tjuego) ) return;
    if( !movs ) return ;
    LOGPRINT( 6, "Descartar por jaques controlando para color %d", color );
    int i;
    for( i = 0; i < movs->entradas; i ++ ){
        Movida* mov = (Movida*) movs->data[i];
        mov->pos = pos;
        Posicion* pos2 = movida_ejecuta( mov );
        if( posicion_en_jaque( pos2, NULL, color ) ){
            LOGPRINT( 6, "Movida descartada %s => %s %p", 
                    movida_pieza( mov )->tpieza->nombre, 
                    movida_casillero_destino( mov )->nombre , mov->pos = pos) ;
            list_quita( movs, i );
            movida_free( mov );
            i --;
        }
        posicion_free( pos2 );
    }
}


/*
 * Esta funcion es muy simple, pero es fundamental.
 * Solo agrega una pieza a la posicion.
 * */
#define  PIEZAS_ALLOC 50
Pieza*      posicion_add_pieza( Posicion* pos ){
  Pieza* pie;
  if( !pos->piezas ){
      pos->piezas = malloc( sizeof( Pieza ) * PIEZAS_ALLOC );
      pos->piezas_count = 0;
      pos->piezas_alloc = PIEZAS_ALLOC;
  } else if ( pos->piezas_count >= pos->piezas_alloc ){
      pos->piezas_alloc += PIEZAS_ALLOC;
      pos->piezas = realloc( pos->piezas, sizeof( Pieza ) * pos->piezas_alloc );
  }  
  pie = & pos->piezas[pos->piezas_count];
  pie->number = pos->piezas_count;
  pos->piezas_count ++;
  return pie;
}

/*
 * Esta funcion devuelve 1, si, una vez ejecutada la movida, 
 * alguna de las piezas afectadas queda en jaque.
 * */
int         posicion_en_jaque( Posicion* pos, Tipopieza* tpieza, int color ){
    int i, j;
    if( !TJJAQUEMATE(pos->tjuego) ) return 0; 
    Pieza* pieza;

    for( i = 0 ; i < pos->piezas_count; i ++ ){
        pieza = &(pos->piezas[i] );
        if( !TJJAQUEMATE(pieza->tpieza) ) continue;
        if( tpieza && pieza->tpieza != tpieza ) continue;
        if( pieza->color != color ) continue;
        if( !CASILLERO_VALIDO(pieza->casillero)) continue;

        // Ahora ejecuto las posibles movidas del enemigo
        for( j = 1; j <= pos->tjuego->colores; j ++ ){
            if( color == j ) continue;
            Movida* mov2;
            LOGPRINT( 6, "Inico de analisis para color %d en %s", j, pieza->casillero->nombre );
            posicion_analiza_movidas( pos, ANALISIS_ATAQUE, j, 0, NULL );
            if( !pos->movidas || pos->movidas->entradas == 0 ) continue;
            list_inicio( pos->movidas );
            while( mov2 = (Movida*) list_siguiente( pos->movidas ) ){
                if( movida_casillero_destino( mov2 ) == pieza->casillero ){
                    return 1;
                }
            }
        }
    }

    return 0;
}


/*
 * Aca se viene el analisis de movidas. Esta funcion realiza el siguiente trabajo.
 * 1. Chequea los parametros, de tal forma que no entre basura
 * 2. Limpia las movidas que se encuentren en la posicion
 * 3. Verifica las piezas en el pozo e intenta una movida por cada tipo de pieza
 *    distinta que se halle en el pozo
 * 4. Verifica pieza por pieza en el tablero e intenta una movida por cada una
 *    de ellas
 * 5. Si se paso una pieza como parametro, ejecuta eso.
 *
 * Parametros:
 *   - tipo de analisis
 *   - color
 *   - tipo de movimiento: No obligatorio, solo se analizaran las reglas asociadas a ese tipo
 *   - pieza: No obligatorio, solo se analizaran las reglas asociadas a esa piea
 *
 * Retorna:
 *   cantidad de movidas encontradas
 **/

int        posicion_analiza_movidas( Posicion* pos, char tipoanalisis, int color, int tipomov, Pieza* pieza ){

    LOGPRINT( 6, "Ingreso a analisis movidas tipoanalisis = %d, color = %d, tipomov = %d", 
        tipoanalisis, color, tipomov )

    // 1. chequeo de parametros
    if( !color ){
        LOGPRINT( 1, "Color debe estar definido (%d)", color );
        return 0;
    };
    if(! ( ( tipoanalisis == ANALISIS_MOVIDA ) || 
           ( tipoanalisis == ANALISIS_PRIMER_MOVIDA ) ||
           ( tipoanalisis == ANALISIS_ATAQUE ) ) ){
        LOGPRINT( 1, "Tipo analisis incorrecto (%d)", tipoanalisis );
        return 0;
    }

    // 2. Limpiamos las movidas
    posicion_free_movidas( pos );

    // 3. Vamos por las piezas en pozo.
    if( !pieza ){
        int  i;
        Pieza* piezas_arr[1024];
        int    piezas_cnt = 0;
        for( i = 0; i < pos->piezas_count; i ++ ){
            Pieza* pp = &pos->piezas[i];
            if( pp->casillero != ENPOZO ) continue;
            if( pp->color != color ) continue;
            int j; int existe = 0;
            for( j = 0; j < piezas_cnt; j ++ ){
                if( pieza_equal( pp, piezas_arr[j] ) ){
                    existe = 1;
                    break;
                }
            }
            if( existe ) continue;
            piezas_arr[piezas_cnt] = pp; piezas_cnt ++;
            int  c;
            for( c = 0; c < pos->tjuego->casilleros->entradas; c ++ ){
                Casillero* cas = (Casillero*) pos->tjuego->casilleros->data[c];
                
                int  r;
                for( r = 0; r < pp->tpieza->rules->entradas; r ++ ){
                    Regla*  regla = (Regla*) pp->tpieza->rules->data[r];
                    if( regla->tregla != DROP ) continue;
                    if( tipomov && tipomov == regla->tmov ) continue;
                    _list*  movs;
                    movs =  analizador_evalua_movidas( regla, pos, pp, cas, tipoanalisis, 
                                    regla->tmov, color );
                    if( movs ){
                        if( tipoanalisis != ANALISIS_ATAQUE ) posicion_descartar_por_jaques( pos, movs, color ) ;
                        posicion_add_movidas( pos, movs );
                        list_free( movs );
                        if( pos->movidas && pos->movidas->entradas > 0 && tipoanalisis == ANALISIS_PRIMER_MOVIDA ) return 1;
                    }
                }
            }
        }
    }

    // 4. Vamos por las piezas en el tablero
    if( !pieza ){
        int i;
        for( i = 0; i < pos->piezas_count; i ++ ){
            Pieza* pp = & pos->piezas[i];
            int  r;
            if( pp->casillero == ENPOZO ) continue;
            if( pp->casillero == ENCAPTURA ) continue;
            if( pp->color != color ) continue;
            LOGPRINT( 6, "Analizando reglas para pieza %s en %s (%s)", 
                  pp->tpieza->nombre, pp->casillero->nombre, 
                  tipojuego_get_colorname( pos->tjuego, color ) );
            for( r = 0; r < pp->tpieza->rules->entradas; r ++ ){
                Regla*  regla = (Regla*) pp->tpieza->rules->data[r];
                if( regla->tregla != MOVE ) continue;
                if( tipomov && tipomov == regla->tmov ) continue;
                _list*  movs;
                LOGPRINT( 6, "Regla %d", r );
                movs =  analizador_evalua_movidas( regla, pos, pp, pp->casillero, tipoanalisis, 
                                regla->tmov, color );
                if( movs ){
                    if( tipoanalisis != ANALISIS_ATAQUE ) posicion_descartar_por_jaques( pos, movs, color ) ;
                    posicion_add_movidas( pos, movs );
                    list_free( movs );
                    if( pos->movidas && pos->movidas->entradas > 0 && tipoanalisis == ANALISIS_PRIMER_MOVIDA ) return 1;
                    LOGPRINT( 6, "Regla %d %d entradas", r, movs->entradas );
                }
            }
        }
    }

    // 5. Esta es con la pieza pasada como parametro
    if( pieza  ){
        Pieza* pp = pieza;
        int  r;
        if( pp->casillero != ENPOZO && pp->casillero != ENCAPTURA ){
            for( r = 0; r < pp->tpieza->rules->entradas; r ++ ){
                Regla*  regla = (Regla*) pp->tpieza->rules->data[r];
                if( regla->tregla != MOVE ) continue;
                if( tipomov && tipomov == regla->tmov ) continue;
                _list*  movs;
                movs =  analizador_evalua_movidas( regla, pos, pp, pp->casillero, tipoanalisis, 
                                regla->tmov, color );
                if( movs ){
                    if( tipoanalisis != ANALISIS_ATAQUE ) posicion_descartar_por_jaques( pos, movs, color ) ;
                    posicion_add_movidas( pos, movs );
                    list_free( movs );
                    if( pos->movidas && pos->movidas->entradas > 0 && tipoanalisis == ANALISIS_PRIMER_MOVIDA ) return 1;
                }
            }
        }
    }


    if( pos->movidas ) return pos->movidas->entradas; else return 0;
}


/*
 * Funcion de analisis de finales.
 * De acuerdo a las condiciones establecidas en el final,
 * se analizará pieza por pieza o casillero por casillero
 * Para tateti, es necesario analizar pieza por pieza y verificar
 * que se cumpla la secuencia como corresponda
 * */

int        posicion_analiza_final( Posicion* pos, int  color_actual, int color_sig, char** resultado ){
    
    int  i;
    for( i = 0; i < pos->tjuego->rules->entradas; i ++ ){
        Regla*  rule = pos->tjuego->rules->data[i];
        int analizado = 0;
        if( rule->tregla != END ) continue;
        // analizamos casillero por casillero!
        if( rule->flags & RULEFLAG_DIRECCION ){
            analizado = 1;
            int  c;
            for( c = 0; c < pos->tjuego->casilleros->entradas ; c ++ ){
                Casillero* cas = (Casillero*)pos->tjuego->casilleros->data[c];
                int res = analizador_evalua_final( rule, pos, NULL, cas, color_actual, color_sig, resultado );
                if( res == STATUS_ERROR ) return FINAL_ENJUEGO;
                if( res == FINAL_EMPATE || res > 0 ) return res;
            }
        }
        if( rule->flags & RULEFLAG_PIEZAS ){
            analizado = 1;
            int p;
            for( p = 0; p < pos->piezas_count; p ++ ){
                Pieza* pieza = & pos->piezas[i];
                if( pieza->color != color_actual ) continue;
                int res = analizador_evalua_final( rule, pos, pieza, pieza->casillero, color_actual, color_sig, resultado );
                if( res == STATUS_ERROR ) return FINAL_ENJUEGO;
                if( res == FINAL_EMPATE || res > 0 ) return res;
            }
        }
        if( !analizado ){
            int res = analizador_evalua_final( rule, pos, NULL, NULL, color_actual, color_sig, resultado );
            if( res == STATUS_ERROR ) return FINAL_ENJUEGO;
            if( res == FINAL_EMPATE || res > 0 ) return res;
        }
    }
    return  FINAL_ENJUEGO;

}


/*
 * La duplicacion de la posicion es algo que hacemos todo el tiempo
 * la idea es generar una nueva posicion con todo listo como para
 * hacer otro analisis o lo que sea.
 * */

Posicion*   posicion_dup( Posicion* pos ){
    Posicion* pnew = posicion_new( pos->tjuego );
    pnew->pos_anterior = pos->pos_anterior;
    pnew->mov_anterior = pos->mov_anterior;
    int p;
    for( p = 0; p < pos->piezas_count; p ++ ){
        Pieza* pie = & pos->piezas[p];
        Pieza* pienew = posicion_add_pieza( pnew );
        pieza_copy( pienew, pie );
    }
    return  pnew;
}

/*
 * Vamos a cambiar de lugar una pieza
 * */
void       posicion_mueve_pieza( Posicion* pos, Pieza* pieza, Casillero* destino ){
    int i;
    pieza->casillero = destino;
}
