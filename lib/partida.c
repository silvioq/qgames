/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2010.
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <qgames.h>
#include "tipojuego.h"
#include "pieza.h"
#include "posicion.h"
#include "partida.h"

/* 
 * Esta funcion devuelve la proxima secuencia, a partir
 * del estado de la partida y de la definicion misma de secuencia
 * */
void    secuencia_actual   ( Partida* par, int* color, int* tmov );
void    secuencia_siguiente( Partida* par, int* color, int* tmov );


Partida*  partida_new( Tipojuego* tjuego ){
    Partida*  par = ALLOC( sizeof( Partida ) );
    memset( par, 0, sizeof( Partida ) );
    par->tjuego = tjuego;
    par->pos    = posicion_dup( tjuego->inicial );
    secuencia_actual( par, &(par->color), &(par->tmov) );
    par->flags |= PORCOMENZAR;
    par->inicio = time( NULL );

    return  par;    
}
