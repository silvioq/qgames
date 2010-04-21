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


Vinculo* vinculo_new( Casillero* ori, Direccion* dir, Casillero* des ){
    Vinculo* c = ALLOC( sizeof( Vinculo ) );
    c->origen    = ori; 
    c->direccion = dir;
    c->destino   = des;
    return c;

}

void    vinculo_free( Vinculo* vin ){
    FREE( vin );
}
