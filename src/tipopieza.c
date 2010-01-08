/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#include  <stdlib.h>
#include  <string.h>
#include  <assert.h>

#include  "qgames.h"
#include  "tipojuego.h"


/*
 * Crea un nuevo tipo de pieza. Nada más ni nada menos.
 * */
Tipopieza*  tipopieza_new( Tipojuego* tj, char* nombre ){

    Tipopieza* t = ALLOC( sizeof( Tipopieza ) );
    memset( t, 0, sizeof( Tipopieza ) );
    t->nombre = strdup( nombre );
    t->tipojuego = tj;
    return t;

}
