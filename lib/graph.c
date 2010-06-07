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

/*
 * Esta funcion arma un tablero tipo damero (checkerboard)
 * */
#if  HAVE_GD_H
gdImagePtr  graph_dibujar_checkerboard( int w, int h, int cw, int ch, int f, int b ){
    int i, j;
    gdImagePtr  gd = gdImageCreateTrueColor( h, w );
    int  fondo  = gdImageColorAllocate( gd, ( b | 0xFF0000 ) >> 24, ( b | 0xFF00 ) >> 16 , b | 0xFF );
    int  frente = gdImageColorAllocate( gd, ( f | 0xFF0000 ) >> 24, ( f | 0xFF00 ) >> 16 , f | 0xFF );
    gdImageFilledRectangle( gd, 0, 0, w - 1, h - 1, fondo );
    for( i = 0; i < cw; i ++ ){
        int color_f = ( i % 2 == 0 ? fondo : frente );
        for( j = 0; j < cw; j ++ ){
            if( color_f == frente ){
                gdImageFilledRectangle( gd, w - cw * ( i + 1 ), ch * j,
                                            w - cw * i  - 1   , ch * ( j + 1 ) - 1,
                                        frente );
                color_f = fondo;
            } else color_f = frente;
        }
    }
}


gdImagePtr  graph_dibujar_grid( int w, int h, int cw, int ch, int f, int b ){
    int i, j;

    gdImagePtr  gd = gdImageCreateTrueColor( h + 4, w + 4 );
    int  fondo  = gdImageColorAllocate( gd, ( b | 0xFF0000 ) >> 24, ( b | 0xFF00 ) >> 16 , b | 0xFF );
    int  frente = gdImageColorAllocate( gd, ( f | 0xFF0000 ) >> 24, ( f | 0xFF00 ) >> 16 , f | 0xFF );
    gdImageFilledRectangle( gd, 0, 0, w - 3, h - 3, fondo );
    gdImageSetThickness( gd, 4 ); // La linea de cuatro pixel que pienso dibujar por el borde
    // Dibujo un rectangulo alrededor de todo el tablero.
    gdImageRectangle( gd, 0, 0, w - 3, h - 3, frente );
    gdImageSetThickness( gd, 2 ); // La linea de dos pixel que pienso dibujar

    for( i = 1; i < cw; i ++ ){
        gdImageLine( gd, cw * i, 0, cw * i, h, frente );
    }
    for( i = 1; i < ch; i ++ ){
        gdImageLine( gd, 0, ch * i, w, ch * i, frente );
    }
    return  gd;

}

#endif

int    tipojuego_get_tablero_png( Tipojuego* tj, int board_number, void** png ){
#if HAVE_GD_H
    Graphdef*  g;
    int size;
    if( board_number == BOARD_ACTUAL ) return tipojuego_get_tablero_png( tj, tj->tablero_actual, png );
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
    if( g->cus ){
        if( !g->gd ){
            FILE* fpng = fopen( g->cus, "r" );
            if( !fpng ){
                LOGPRINT( 2, "No puede abrir %s", fpng );
                return 0;
            }
            g->gd = gdImageCreateFromPng( fpng );
            fclose( fpng );
        }
    } else {
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
        switch(g->std){
            case  TYPE_CHECKERBOARD   :
                g->gd = graph_dibujar_checkerboard( g->w, g->h, tt->dimmax[0], tt->dimmax[1], g->f, g->b );
                break;
            case  TYPE_GRID           :
                g->gd = graph_dibujar_grid( g->w, g->h, tt->dimmax[0], tt->dimmax[1], g->f, g->b );
            case  TYPE_INTERSECTIONS  :
                LOGPRINT( 2, "No implementado %d", g->std );
                return 0;
            default:
                LOGPRINT( 2, "No implementado %d", g->std );
                return 0;
        }
    }
    if( png ) *png = gdImagePngPtr( g->gd, &size );
    return size;
#else
    LOGPRINT( 2, "No compilado con el modulo GD board = %d", board_number );
    return 0;
#endif
}
