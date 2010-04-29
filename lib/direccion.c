/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#include <stdlib.h>
#include <string.h>
#include "qgames.h"
#include "tipojuego.h"


Direccion* direccion_new( char* dir ){
    Direccion* c = malloc( sizeof( Direccion ) );
    memset( c, 0, sizeof( Direccion ) );
    c->nombre = strdup( dir );
    return c;
}
