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

