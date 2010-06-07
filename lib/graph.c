/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2010.
*/


#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <assert.h>
#include  <stdarg.h>
#include  <qgames.h>
#include  <config.h>

#include  "log.h"
#include  "tipojuego.h"
#include  "graphdef.h"


int    tipojuego_get_tablero_png( Tipojuego* tj, int board_number, void** png ){
#if HAVE_GD_H
    Graphdef*  g;
    if( board_number == BOARD_ACTUAL ) 
        return tipojuego_get_tablero_png( tj, tj->tablero_actual, png );
    if( !tj->graphdefs ){
        LOGPRINT( 2, "No hay definiciones de grafico board = %d", board_number );
        return 0;
    }
    Tablero* tt = tipojuego_get_tablero( tj, board_number );

    if( !(g = tablero_get_graphdef( tt ) ) ){
        LOGPRINT( 2, "No se encuentra definicion para board = %d", board_number );
        return 0;
    }
    // Si no tenemos ancho, calculemoslo.
    if( !g->w ){
        int i;
        Graphdef* gg = NULL;
        for( i == 0 ; i <  tj->graphdefs->entradas; i ++ ){
            Graphdef* ggg = tj->graphdefs->data[i];
            if( ggg->tipo == TIPOGRAPH_TPIEZA ){
                gg = ggg;
                break;
            }
        }
        if( !gg ){
            LOGPRINT( 2, "Error calculando tamaño board = %d", board_number );
            return 0;
        }
        g->w = gg->w * tt->dimmax[0];
        g->h = gg->h * tt->dimmax[1];
    }
#else
    LOGPRINT( 2, "No compilado con el modulo GD board = %d", board_number );
    return 0;
#endif
}
