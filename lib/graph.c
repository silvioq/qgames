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
#include  "pieza.h"
#include  "movida.h"
#include  "partida.h"
#include  "posicion.h"
#include  "graphdef.h"
#include  "errno.h"

/*
 * Esta funcion arma un tablero tipo damero (checkerboard)
 * */
#if  GRAPH_ENABLED
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


gdImagePtr  graph_tpieza_get_gd( Tipopieza* tp, int color ){
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


gdImagePtr    graph_get_tablero_png( Tipojuego* tj, int board_number, int flags ){
    Graphdef*  g;
    gdImagePtr gd;

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
    return  gd;
}
#endif


int    tipojuego_get_tablero_png( Tipojuego* tj, int board_number, int flags, void** png ){
#if GRAPH_ENABLED
    int size;
    if( board_number == BOARD_ACTUAL ) return tipojuego_get_tablero_png( tj, tj->tablero_actual, flags, png );
    gdImagePtr gd = graph_get_tablero_png( tj, board_number, flags );

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
#if GRAPH_ENABLED
    Tipopieza* tp = tj->tipo_piezas->data[ GETTIPOPIEZA(tj,tpieza) ];
    int  col      = GETCOLOR(tj,color);
    gdImagePtr gd = graph_tpieza_get_gd( tp, col );
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
#if GRAPH_ENABLED
    gdFree( png );
#endif
}


/*
 * Esta funcion es la encargada de dibujar una posicion cualquiera
 * a partir de una partida. Contamos con el flag, que indicara 
 * cuestiones como si la posicion debe verse rotada (la vista de
 * las negras en el ajedrez) o el color de resaltado de la ultima 
 * movida.
 * Ademas, es posible ver cualquier posicion, esto se indica mediante
 * la variable movida ...
 * */

int         partida_get_png( Partida* par, int flags, int movida, void** png ){
#if  GRAPH_ENABLED 
    int tablero_flags = ( flags | GETPNG_ROTADO );
    int i;
    Posicion* pos;

    if( movida == 0 ){
        pos = par->tjuego->inicial ;
    } else if ( movida == par->movimientos->entradas || movida == LAST_MOVE ){
        pos = par->pos;
    } else if ( movida > par->movimientos->entradas ){
        LOGPRINT( 2, "Movida pedida %d. Cantidad movimientos %d. Partida %s",
                        movida, par->movimientos->entradas, par->id );
        return 0;
    } else {
        Movida* mov = (Movida*) par->movimientos->data[movida];
        pos = mov->pos;
    }

    gdImagePtr gd = graph_get_tablero_png( par->tjuego, par->tjuego->tablero_actual, tablero_flags );
    if( !gd ){
        LOGPRINT( 2, "No es posible obtener la imagen del tablero para %s en partida %s", par->tjuego->nombre,
                       par->id );
        return  0;
    }
  
    for( i = 0; i < pos->piezas->entradas; i ++ ){
        Pieza* p = (Pieza*) pos->piezas->data[i];
        if( !CASILLERO_VALIDO( p->casillero ) ) continue;
        gdImagePtr gdp = graph_tpieza_get_gd( p->tpieza, p->color );
        if( !gdp ){
          gdFree( gd );
          return 0;
        }
        // Aca tengo que entontrar la posicion relativa de la pieza
        // y colocar el dibujo. No es otra cosa que la posicion
        // relativa del casillero por el tamaño (tablero->g->w / tablero->dimmax[0])
        // mas el offset del tablero
        if( flags | GETPNG_ROTADO ){
        } else {
        }
    }

    
    assert( !"partida_get_png no implementado aun"  );
    return 0;
#else
    LOGPRINT( 2, "No compilado con el modulo GD partida = %s", par->id );
    return 0;
#endif
    
}


