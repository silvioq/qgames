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
#include  "errno.h"

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


gdImagePtr  graph_tpieza_get_png( Tipopieza* tp, int color ){
    if( !tp->tipojuego->graphdefs ) return NULL;
    int i;
    Graphdef* g = NULL;
    Graphdef* g0 = NULL;


    for( i = 0; i < tp->tipojuego->graphdefs->entradas; i ++ ){
        Graphdef* g2 = tp->tipojuego->graphdefs->data[i];
        if( g2->tipo == TIPOGRAPH_TPIEZA && g2->tpieza == tp  ){
            if( g2->color == color ){
                g = g2;
                break;
            } else if( g2->color == 0 ){
                g0 = g2;
            }
        }
    }

    if( !g && !g0 ){
        LOGPRINT( 2, "No se puede encontrar grafico para %s", tp->nombre );
        return NULL;
    } else if ( !g ) g = g0;

    if( g->gd ) return g->gd;
    if( g->cus ){
        FILE* fpng = fopen( g->cus, "r" );
        if( !fpng ){
            LOGPRINT( 2, "No puede abrir %s", fpng );
            return NULL;
        }
        g->gd = gdImageCreateFromPng( fpng );
        g->w  = gdImageSX( g->gd );
        g->h  = gdImageSY( g->gd );
        fclose( fpng );
        return  g->gd;
    }

    char* piece;
    char* colorname;
    char  size[24];
    char  filename[1024];
    switch( g->std ){
        case  STANDARD_GEM        :
            piece = "gema";
            break;
        case  STANDARD_BISHOP     :
            piece = "alfil";
            break;
        case  STANDARD_KING       :
            piece = "rey";
            break;
        case  STANDARD_KNIGHT     :
            piece = "caballo";
            break;
        case  STANDARD_PAWN       :
            piece = "peon";
            break;
        case  STANDARD_QUEEN      :
            piece = "dama";
            break;
        case  STANDARD_ROOK       :
            piece = "torre";
            break;
        default:
            LOGPRINT( 2, "No esta definido pieza estandar %d", g->std );
            return NULL;
    }

    sprintf( size, "%dx%d", g->w, g->h );
    colorname = tipojuego_get_colorname( tp->tipojuego, color );
    sprintf( filename, "%s/%s/%s-%s.png", IMGDIR, size, piece, colorname );
    FILE* f = fopen( filename, "r" );
    if( !f ){
        LOGPRINT( 2, "Error al abrir %s (%d - %s)", filename, errno, strerror(errno) );
        return NULL;
    }
    gdImagePtr gd = gdImageCreateFromPng( f );
    fclose( f );

    // Ahora lo que hago es volver a crear una imagen para ponerlo en la 
    // lista para luego poder tomarla como corresponde, ya que las estandares
    // no tienen color
    g0 = malloc( sizeof( Graphdef ) );
    memset( g0, 0, sizeof( Graphdef ) );
    g0->tipo   = TIPOGRAPH_TPIEZA;
    g0->tpieza = tp;
    g0->std    = g->std;
    g0->w      = g->w;
    g0->h      = g->h;
    g0->gd     = gd;
    
    list_agrega( tp->tipojuego->graphdefs, g0 );
    return gd;
}


#endif

int    tipojuego_get_tablero_png( Tipojuego* tj, int board_number, int flags, void** png ){
#if HAVE_GD_H
    Graphdef*  g;
    gdImagePtr gd;
    int size;
    if( board_number == BOARD_ACTUAL ) return tipojuego_get_tablero_png( tj, tj->tablero_actual, flags, png );
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
            g->w  = gdImageSX( g->gd );
            g->h  = gdImageSY( g->gd );
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
        if( !g->gd ){
            switch(g->std){
                case  TYPE_CHECKERBOARD   :
                    g->gd = graph_dibujar_checkerboard( g->w, g->h, g->w / tt->dimmax[0], g->h / tt->dimmax[1], g->f, g->b );
                    g->gd_r = g->gd;
                    break;
                case  TYPE_GRID           :
                    g->gd = graph_dibujar_grid( g->w, g->h, g->w / tt->dimmax[0], g->h / tt->dimmax[1], g->f, g->b );
                    g->gd_r = g->gd;
                    break;
                case  TYPE_INTERSECTIONS  :
                    LOGPRINT( 2, "No implementado %d", g->std );
                    return 0;
                default:
                    LOGPRINT( 2, "No implementado %d", g->std );
                    return 0;
            }
        }
    }
    if( !(flags & GETPNG_ROTADO ) ){
        gd = g->gd;
    } else {
        if( !g->gd_r ){
            g->gd_r = gdImageCreateTrueColor( g->w, g->h );
            gdImageCopyRotated( g->gd_r, g->gd, g->w / 2.0, g->h / 2.0, 0, 0, g->w - 1, g->h - 1, 180 );
        }
        gd = g->gd_r;
    }
    if( png ) *png = gdImagePngPtr( gd, &size );
    return size;
#else
    LOGPRINT( 2, "No compilado con el modulo GD board = %d", board_number );
    return 0;
#endif
}


/*
 * Bueno, vamos a ver si podemos obtener la pieza
 * */
int    tipojuego_get_tpieza_png( Tipojuego* tj, char* color, char* tpieza, void** png ){
#if HAVE_GD_H
    Tipopieza* tp = tj->tipo_piezas->data[ GETTIPOPIEZA(tj,tpieza) ];
    int  col      = GETCOLOR(tj,color);
    gdImagePtr gd = graph_tpieza_get_png( tp, col );
    int  size = 0;
    if( png ) *png = gdImagePngPtr( gd, &size );
    return size;
#endif
    LOGPRINT( 2, "No compilado con el modulo GD tpieza = %s", tpieza );
    return 0;
}
/*
 *
 * Esta es la funcion que libera lo alocado por la librería GD
 *
 * */
void   qgames_free_png( void* png ){
#if HAVE_GD_H
    gdFree( png );
#endif
}


