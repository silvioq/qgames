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
#include  "posicion.h"

/*
 * Una posicion nueva!
 * */

Posicion*   posicion_new( Tipojuego* tpieza ){
  Posicion* pos;
  pos = ALLOC( sizeof( Posicion ) );
  memset( pos, 0, sizeof( Posicion ) );
  return  pos;

}

