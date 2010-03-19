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


#define  CHECK_STATUS     assert( z->status == STATUS_NORMAL );

_list*   analizador_evalua_movidas( Regla* regla, Posicion* pos, Pieza* pieza, Casillero* cas, char tipoanalisis, int tipomovida, int color ){

    Analizador* z = (Analizador*)ALLOC( sizeof( Analizador ) );
    memset( z, 0, sizeof( Analizador ) );
    z->pos = pos;
    z->pieza = pieza;
    z->cas   = cas;
    z->color = color;
    z->tipo_analisis = tipoanalisis;
    z->tipo_movida   = tipomovida;

    code_execute_rule( z, regla->pc );

    return z->movidas;

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
    return STATUS_NORMAL;

}



int    analizador_juega  ( Analizador* z, Casillero* cas, int con_captura ){
    CHECK_STATUS ;
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
    return  STATUS_NORMAL;
}



int   analizador_direccion( Analizador* z, Direccion* dir ){

    Vinculo* v;
    CHECK_STATUS;
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

