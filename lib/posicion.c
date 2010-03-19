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
#include  "analizador.h"
#include  "posicion.h"

/* ---------------------------------------------------------------------------------------- */
void        posicion_free_movidas( Posicion* pos );
void        posicion_add_movida( Posicion* pos, Movida* mov );
void        posicion_add_movidas( Posicion* pos, _list* movs );




/* ---------------------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------------------- */
void  posicion_free_movidas( Posicion* pos ){
    if( pos->movidas ){
        int  i;
        for( i = 0; i < pos->movidas->entradas; i ++ ){
            Movida* mov = (Movida*)pos->movidas->data[i];
            movida_free( mov );
        }
        list_free( pos->movidas );
        pos->movidas = NULL;
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
        posicion_add_movida( pos, m );
    }
}


/*
 * Una posicion nueva!
 * */

Posicion*   posicion_new( Tipojuego* tpieza ){
  Posicion* pos;
  pos = ALLOC( sizeof( Posicion ) );
  memset( pos, 0, sizeof( Posicion ) );
  return  pos;
}

/*
 * Esta funcion es muy simple, pero es fundamental.
 * Solo agrega una pieza a la posicion.
 * */

void        posicion_add_pieza( Posicion* pos, Pieza* pie ){
  if( !pos->piezas ) pos->piezas = list_nueva( NULL );
  list_agrega( pos->piezas, pie );
}

/*
 * Aca se viene el analisis de movidas. Esta funcion realiza el siguiente trabajo.
 * 1. Chequea los parametros, de tal forma que no entre basura
 * 2. Limpia las movidas que se encuentren en la posicion
 * 3. Verifica las piezas en el pozo e intenta una movida por cada tipo de pieza
 *    distinta que se halle en el pozo
 * 4. Verifica pieza por pieza en el tablero e intenta una movida por cada una
 *    de ellas
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

    // 1. chequeo de parametros
    assert( color > 0 );
    assert( ( tipoanalisis == ANALISIS_MOVIDA ) || 
            ( tipoanalisis == ANALISIS_PRIMER_MOVIDA ) ||
            ( tipoanalisis == ANALISIS_ATAQUE ) );

    // 2. Limpiamos las movidas
    posicion_free_movidas( pos );

    // 3. Vamos por las piezas en pozo.
    if( !pieza ){
        int  i;
        Pieza* piezas_arr[1024];
        int    piezas_cnt = 0;
        for( i = 0; i < pos->piezas->entradas; i ++ ){
            Pieza* pp = (Pieza*) pos->piezas->data[i];
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
            int  r;
            for( c = 0; c < pos->tjuego->casilleros->entradas; c ++ ){
                Casillero* cas = (Casillero*) pos->tjuego->casilleros->data[c];
                for( r = 0; r < pp->tpieza->rules->entradas; r ++ ){
                    Posicion* newpos = posicion_dup( pos );
                    Regla*  regla = (Regla*) pp->tpieza->rules->data[r];
                    _list*  movs;
                    movs =  analizador_evalua_movidas( regla, pos, pp, cas, tipoanalisis, tipomov, color );
                    if( movs ){
                        if( tipoanalisis == ANALISIS_PRIMER_MOVIDA ) return 1;
                        posicion_add_movidas( pos, movs );
                    }
                }
            }
        }
    }
      


    return 0;
}


/*
 * La duplicacion de la posicion es algo que hacemos todo el tiempo
 * la idea es generar una nueva posicion con todo listo como para
 * hacer otro analisis o lo que sea.
 * */

Posicion*   posicion_dup( Posicion* pos ){
    Posicion* pnew = posicion_new( pos->tjuego );
    pnew->pos_anterior = pos->pos_anterior;
    int p;
    for( p = 0; p < pos->piezas->entradas; p ++ ){
        Pieza* pie = (Pieza*)pos->piezas->data[p];
        Pieza* pienew = pieza_dup( pie );
        posicion_add_pieza( pnew, pienew );
    }
    
}
