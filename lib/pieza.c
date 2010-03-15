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

/*
 * Crea una pieza nueva
 * */

Pieza*   pieza_new( Tipopieza* tpieza, Casillero* cas, int color ){
  Pieza *p;
  p = (Pieza*)ALLOC( sizeof( Pieza ) );
  memset( p, 0, sizeof( Pieza ) );
  p->tpieza = tpieza;
  p->casillero = cas;
  p->color     = color;
  return p;
}

/*
 * Para borrar una pieza, hay que ser prolijos
 * */
void   pieza_free( Pieza* p ){
  if( p->atributos ){
      list_free( p->atributos );
  }
  free( p );
}
