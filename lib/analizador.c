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



/*
 * Devuelve uno o cero, si se encuentra ocupado el casillero pasado como parametro
 * Detalle:
 *  cas  : Casillero. Si es nulo, toma el casillero actual
 *  owner: Dueño. Puede ser ENEMIGO, PROPIO, CUALQUIERA o un color
 *
 *  */

int    analizador_ocupado( Analizador* z, Casillero* cas, int owner ){
    Casillero*  ccc = ( cas ? cas : z->cas );
    
    int i;
    for( i = 0; i < z->pos->piezas->entradas; i ++ ){
        Pieza* pp = (Pieza*)z->pos->piezas->data[i];
        if( pp->casillero == ccc ){
            if( owner == CUALQUIERA ){
                return  1;
            } else if( owner == PROPIO ){
                if( z->color == pp->color ) return 1;
            } else if( owner == ENEMIGO ) {
                if( z->color != pp->color ) return 1;
            } else if( pp->color == owner ) return 1;
        }
    }
    return 0;

}



int    analizador_juega  ( Analizador* z, Casillero* cas, int con_captura ){
    if( !z->movidas ) z->movidas = list_nueva( NULL );
    Movida* mov = movida_new( z->pos );
    movida_accion_mueve( mov, z->pieza, cas );
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
    return  z->movidas->entradas;
}
