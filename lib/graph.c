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
    gdImagePtr  gd = gdImageCreateTrueColor( w, h );
    int  fondo  = gdImageColorAllocate( gd, b >> 16, ( b & 0xFF00 ) >> 8 , b & 0xFF );
    int  frente = gdImageColorAllocate( gd, f >> 16, ( f & 0xFF00 ) >> 8 , f & 0xFF );
    gdImageFilledRectangle( gd, 0, 0, w - 1 , h - 1 , fondo );
    int  cantx  = w / cw;
    int  canty  = h / cw;
    for( i = 0; i < cantx; i ++ ){
        int color_f = ( i % 2 == 0 ? fondo : frente );
        for( j = 0; j < canty; j ++ ){
            if( color_f == frente ){
                LOGPRINT( 5, "y1=%d y2=%d",  h - ch * ( j + 1 ),  h - ch * j - 1 );
                gdImageFilledRectangle( gd, cw * i,             h - ch * ( j + 1 ) ,
                                            cw * ( i + 1 ) - 1, h - ch * j - 1, 
                                        frente );
                color_f = fondo;
            } else color_f = frente;
        }
    }
    return gd;
}


gdImagePtr  graph_dibujar_grid( int w, int h, int cw, int ch, int f, int b ){
    int i, j;

    gdImagePtr  gd = gdImageCreateTrueColor( h + 6, w + 6 );
    int  fondo  = gdImageColorAllocate( gd, b >> 16, ( b & 0xFF00 ) >> 8 , b & 0xFF );
    int  frente = gdImageColorAllocate( gd, f >> 16, ( f & 0xFF00 ) >> 8 , f & 0xFF );
    gdImageFilledRectangle( gd, 0, 0, w + 5, h + 5, fondo );
    gdImageSetThickness( gd, 1 ); // La linea de cuatro pixel que pienso dibujar por el borde
    // Dibujo un rectangulo alrededor de todo el tablero.
    // gdImageRectangle( gd, 0, 0, w + 3 , h + 3 , frente );
    gdImageRectangle( gd, 1, 1, w + 4 , h + 4 , frente );
    gdImageRectangle( gd, 2, 2, w + 3 , h + 3 , frente );
    gdImageRectangle( gd, 3, 3, w + 2 , h + 2 , frente );
    gdImageSetThickness( gd, 2 ); // La linea de dos pixel que pienso dibujar

    for( i = 1; i < cw - 1; i ++ ){
        gdImageLine( gd, 3 + cw * i, 3 + 0, 3 + cw * i, 3 + h, frente );
    }
    for( i = 1; i < ch - 1; i ++ ){
        gdImageLine( gd, 3 + 0, 3 + ch * i, 3 + w, 3 + ch * i, frente );
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
    assert( tt );

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
                g->gd = graph_dibujar_checkerboard( g->w, g->h, g->w / tt->dimmax[0], g->h / tt->dimmax[1], g->f, g->b );
                break;
            case  TYPE_GRID           :
                g->gd = graph_dibujar_grid( g->w, g->h, g->w / tt->dimmax[0], g->h / tt->dimmax[1], g->f, g->b );
                break;
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
