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

// -----------------------------------------------------------------

Movida*   movida_new( Posicion* pos ){
  Movida* m;
  m = ALLOC( sizeof( Movida ) );
  memset( m, 0, sizeof( Movida ) );
  m->pos = pos;
  return m;
}

static inline Accion*   accion_new(){
    Accion* acc;
    acc = ALLOC( sizeof( Accion ) );
    memset( acc, 0, sizeof( Accion ) );
    return  acc;
}

/*
 *
 * Esta es la generacion de la movida de movimiento
 *
 * */
void  movida_accion_mueve  ( Movida* mov, Pieza* p, Casillero* destino ){
    Accion* acc = accion_new();
    acc->tipo = ACCION_MUEVE;
    acc->pieza = p;
    acc->destino = destino;
    if( !mov->acciones ) mov->acciones = list_nueva( NULL );
    list_agrega( mov->acciones, acc );
}

/*
 * Esta es la generacion de accion de captura para una movida
 * */
void  movida_accion_captura( Movida* mov, Pieza* p ) {
    Accion* acc = accion_new();
    acc->tipo = ACCION_CAPTURA;
    acc->pieza = p;
    if( !mov->acciones ) mov->acciones = list_nueva( NULL );
    list_agrega( mov->acciones, acc );
}


/*
 * Limpia todo lo que tiene la movida, que no es mucho, por 
 * cierto
 * */
void  movida_free( Movida* mov ){
    if( mov->acciones ){
        int i;
        for( i = 0; i < mov->acciones->entradas; i ++ ){
            // La accion se puede borrar tranquilamente
            free( mov->acciones->data[i] );
        }
        list_free( mov->acciones );
    }
    free( mov );
}




/*
 * Devuelve el casillero de origen de la movida, de acuerdo al analisis
 * las acciones que la conforman. 
 * */
Casillero*   movida_casillero_origen( Movida* mov ){
    Pieza*  pieza = movida_pieza( mov );
    return( pieza ? pieza->casillero : NULL );
}


/*
 * Devuelve el casillero de destino de la movida, de acuerdo al analisis
 * las acciones que la conforman. De paso, se actualiza el elemento
 * destino de la estructura, para posteriores usos
 * */
Casillero*   movida_casillero_destino( Movida* mov ){
    Accion* acc;
    if( mov->destino ) return mov->destino;
    if( !mov->acciones ) return NULL;
    list_inicio( mov->acciones );
    while( acc = (Accion*)list_siguiente( mov->acciones ) ){
        if( acc->destino ){
            mov->destino = acc->destino;
            return acc->destino;
        }
    }
    return  NULL;
}

/*
 * Devuelve la pieza primaria de la movida, de acuerdo al analisis
 * las acciones que la conforman. De paso, se actualiza el elemento
 * pieza de la estructura, para posteriores usos
 * */
Pieza*       movida_pieza( Movida* mov ){
    Accion* acc;
    if( mov->pieza ) return mov->pieza;
    if( !mov->acciones ) return NULL;
    list_inicio( mov->acciones );
    while( acc = (Accion*)list_siguiente( mov->acciones ) ){
        if( acc->pieza ){
            mov->pieza = acc->pieza;
            return acc->pieza;
        }
    }
    return  NULL;
}



int          movida_es_captura( Movida* mov ){
    Accion* acc;
    if( !mov->acciones ) return 0;
    list_inicio( mov->acciones );
    while( acc = (Accion*)list_siguiente( mov->acciones ) ){
        if( acc->tipo == ACCION_CAPTURA ) return 1;
    }
    return  0;
}

