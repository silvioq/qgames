/****************************************************************************
 * Copyright (c) 2009-2010 Silvio Quadri                                    *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, distribute with modifications, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is    *
 * furnished to do so, subject to the following conditions:                 *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 ****************************************************************************/

#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <stdarg.h>
#include  <qgames.h>
#include  <qgames_analyzer.h>

#include  "config.h"
#include  "qgames_core.h"
#include  "list.h"
#include  "tipojuego.h"
#include  "graphdef.h"
#include  "simbolos.h"
#include  "pieza.h"
#include  "movida.h"
#include  "partida.h"
#include  "posicion.h"
#include  "log.h"
#include "../parser/pgn_scanner.h"


/*  
 * El inicio de todo tipo juego es su creación ... algo muy sencillo
 * por cierto.
 * Hay que crear la tabla de simbolos, agregar el nombre y no mucho más
 * por el momento
 * */
DLL_PUBLIC Tipojuego*   qg_tipojuego_new( char* nombre ){
    return tipojuego_new( nombre );
}

/*
 * Devuelve el puntero al directorio path de las definiciones
 * de juegos
 * */
const char* qg_path_games( ){
    return  tipojuego_path_def;
}

/*
 * Permite setear el directorio por defecto
 * donde se tomaran los archivso de definiciones
 * de juego
 * */

void   qg_path_set( const char* path ){
    tipojuego_path_def = path;
}


/*
 * Dado un nombre de tipo de juego, lee el archivo estandard
 * de acuerdo al directorio donde se alojan
 * */
DLL_PUBLIC Tipojuego*  qg_tipojuego_open( char* nombre ){
    char  filename[512];
    sprintf( filename, "%s/%s.qgame", qg_path_games(), nombre );
    return  qgz_parse_filename( filename, 0 );
}


DLL_PUBLIC Partida*     qg_tipojuego_create_partida( Tipojuego* tj, char* id ){
    return  partida_new( tj, id );
}
DLL_PUBLIC  int         qg_tipojuego_genera_dimensiones( Tipojuego* tj, int dimc, char** dimv ){
    return  tipojuego_genera_dimensiones( tj, dimc, dimv );
}

DLL_PUBLIC int         qg_tipojuego_get_casillero_bycell( Tipojuego* tj, char** casillero, int pos[MAXDIMS] ){
    Casillero* cas = tipojuego_get_casillero_by_relpos( tj, tj->tablero_actual, pos );
    if( !cas ) return 0;
    if( casillero ){
        *casillero = cas->nombre;
    }
    return 1;
}
DLL_PUBLIC int         qg_tipojuego_get_cell_bycasillero( Tipojuego* tj, char* casillero,  int** pos){
    int  ccc = tipojuego_get_casillero( tj, casillero );
    if( ccc == NOT_FOUND ) return 0;
    Casillero* cas = (Casillero*)( tj->casilleros->data[ccc] );
    if( pos ){
        *pos = cas->posicion;
    }
    return 1;
}
/* 
 * Muy sencillo ... determino si el tipo de juego es o no es valido
 * */
DLL_PUBLIC  int         qg_tipojuego_valido( Tipojuego* tj ){ return TJVALIDO(tj); }
DLL_PUBLIC  int         qg_tipojuego_get_color    ( Tipojuego* tj, char* color ){
    return  tipojuego_get_color( tj, color );
}
DLL_PUBLIC  int         qg_tipojuego_get_casillero( Tipojuego* tj, char* cas ){
    return  tipojuego_get_casillero(tj, cas);
}
DLL_PUBLIC  int         qg_tipojuego_get_tipopieza( Tipojuego* tj, char* tpieza ){
    return  tipojuego_get_tipopieza( tj, tpieza );
}
DLL_PUBLIC  int         qg_tipojuego_get_direccion( Tipojuego* tj, char* dir ){
    return  tipojuego_get_direccion( tj, dir );
}
DLL_PUBLIC  int         qg_tipojuego_get_att      ( Tipojuego* tj, char* tpieza, char* att ){
    return  tipojuego_get_att( tj, tpieza, att );
}
DLL_PUBLIC  int         qg_tipojuego_get_zona     ( Tipojuego* tj, char* zona ){
    return  tipojuego_get_zona( tj, zona );
}
DLL_PUBLIC  int         qg_tipojuego_get_tipomov  ( Tipojuego* tj, char* tipomov ){
    return  tipojuego_get_tipomov( tj, tipomov );
}

/*
 * Devuelve el nombre del tipo juego ...
 * */
const char* qg_tipojuego_get_nombre   ( Tipojuego* tj ){
    return (const char*) tj->nombre;
}

DLL_PUBLIC int         qg_tipojuego_get_dims( Tipojuego* tj ){
    if( !qg_tipojuego_valido( tj ) ) return 0;
    if( !tj->tablero_actual ) return 0;
    int  dimensiones = ((Tablero*) tj->tableros->data[tj->tablero_actual - 1] )->dimc;
    return  dimensiones;
}


/*
 * Devuelve el nombre del color de acuerdo a su numero
 * */

DLL_PUBLIC   const char*  qg_tipojuego_info_color( Tipojuego* tj, int color ){
    if( color == 0 || color > tj->colores ) return NULL;
    return  tipojuego_get_colorname( tj, color );
}

DLL_PUBLIC   int          qg_tipojuego_info_color_rotado( Tipojuego* tj, int color ){
    if( color == 0 || color > tj->colores ) return 0;
    int i = 0;
    if( !tj->simetrias ) return 0;
    for( i = 0; i < tj->simetrias->entradas; i ++ ){
        Simetria* s = tj->simetrias->data[i];
        if( s->color == color ) return 1;
    }
    return 0;
}


DLL_PUBLIC   const char*  qg_tipojuego_info_tpieza( Tipojuego* tj, int tpieza ){
    if( tpieza == 0 || tpieza > tj->tipo_piezas->entradas ) return NULL;
    Tipopieza* tp = (Tipopieza*)(tj->tipo_piezas->data[tpieza-1]);
    return  (const char*)(tp->nombre);
}

DLL_PUBLIC   const char*  qg_tipojuego_info_casillero( Tipojuego* tj, int cas, int** pos ){
    if( cas == 0 || cas > tj->casilleros->entradas ) return NULL;
    Casillero* c = (Casillero*)(tj->casilleros->data[cas-1]);
    if( pos ) *pos = c->posicion;
    return  (const char*)(c->nombre);
}




/*
 * Agregaciones varias
 * */
DLL_PUBLIC  int        qg_tipojuego_add_casillero( Tipojuego* tj, char* casillero ){
    return  tipojuego_add_casillero( tj, casillero );
}
DLL_PUBLIC  int         qg_tipojuego_add_direccion( Tipojuego* tj, char* direccion ){
    return  tipojuego_add_direccion( tj, direccion );
}
// DLL_PUBLIC  int         qg_tipojuego_add_direccion_rel( Tipojuego* tj, char* direccion, ... );
DLL_PUBLIC  int         qg_tipojuego_add_direccion_arr( Tipojuego* tj, char* direccion, int* dirv ){
    return  tipojuego_add_direccion_arr( tj, direccion, dirv );
}
DLL_PUBLIC  int         qg_tipojuego_add_color ( Tipojuego* tj, char* color ){
    return  tipojuego_add_color( tj, color );
}
DLL_PUBLIC  int         qg_tipojuego_add_tipo_mov ( Tipojuego* tj, char* tipo_mov, int priority ){
    return  tipojuego_add_tipo_mov( tj, tipo_mov, priority );
}
DLL_PUBLIC  int         qg_tipojuego_add_tipopieza( Tipojuego* tj, char* tpieza ){
    return  tipojuego_add_tipopieza( tj, tpieza );
}
DLL_PUBLIC  int         qg_tipojuego_add_tpieza_att( Tipojuego* tj, char* tpieza, char* att, int default_value ){
    return  tipojuego_add_tpieza_att( tj, tpieza, att, default_value );
}
DLL_PUBLIC  int         qg_tipojuego_add_zona     ( Tipojuego* tj, char* zona ){
    return  tipojuego_add_zona     ( tj, zona );
}
DLL_PUBLIC  int         qg_tipojuego_add_cas_to_zona( Tipojuego* tj, char* cas, char* color, char* zona ){
    return tipojuego_add_cas_to_zona( tj, cas, color, zona );
}
DLL_PUBLIC  int         qg_tipojuego_add_simetria ( Tipojuego* tj, char* color, char* dir1, char* dir2 ){
    return tipojuego_add_simetria ( tj, color, dir1, dir2 );
}
DLL_PUBLIC  int         qg_tipojuego_add_secuencia( Tipojuego* tj, char* color, char* tipomov ){
    return tipojuego_add_secuencia( tj, color, tipomov );
}
DLL_PUBLIC  int         qg_tipojuego_add_secuencia_rep( Tipojuego* tj ){
    return tipojuego_add_secuencia_rep( tj );
}
DLL_PUBLIC  int         qg_tipojuego_add_pieza( Tipojuego* tj, char* tpieza, char* casillero, char* color ){
    return tipojuego_add_pieza( tj, tpieza, casillero, color );
}


/*
 * Esta funcion devuelve el color actual que mueve en la partida
 * */
DLL_PUBLIC const char* qg_partida_color         ( Partida* par ){
    int c = par->color;
    if( c ){
        return (const char*) tipojuego_get_colorname( par->tjuego, c );
    } else {
        return NULL;
    }
}

/*
 * Funciones de definicion de graficacion
 * */

DLL_PUBLIC int    qg_tipojuego_graph_tablero_std     ( Tipojuego* tj, int board_number, char graphtype, int width, int height, int forecolor, int backcolor ){
    return tipojuego_graph_tablero_std( tj, board_number, graphtype, width, height, forecolor, backcolor );
}
DLL_PUBLIC int    qg_tipojuego_graph_tablero_cus     ( Tipojuego* tj, int board_number, char* file  ){
    // return tipojuego_graph_tablero_cus( tj, board_number, file  );
    return 0; // no implementado
}
DLL_PUBLIC int    qg_tipojuego_graph_tipopieza_std   ( Tipojuego* tj, char* tpieza, int stdimg, int width, int height, int forecolor ){
    return tipojuego_graph_tipopieza_std   ( tj, tpieza, stdimg, width, height, forecolor );
}
DLL_PUBLIC int    qg_tipojuego_graph_tipopieza_cus   ( Tipojuego* tj, char* tpieza, char* color, char* file ){
    // return tipojuego_graph_tipopieza_cus ( tj, tpieza, color, file );
    return 0; // no implementado
}
DLL_PUBLIC int    qg_tipojuego_graph_casillero_std   ( Tipojuego* tj, char* casillero, int resaltado, int color ){
    // return tipojuego_graph_casillero_std   ( tj, casillero, resaltado, color );
    return 0; // no implementado
}
DLL_PUBLIC int    qg_tipojuego_graph_casillero_cus   ( Tipojuego* tj, char* casillero, char* file ){
    // tipojuego_graph_casillero_cus   ( tj, casillero, file );
    return 0; // no implementado
}

DLL_PUBLIC int     qg_tipojuego_graph_logofile     ( Tipojuego* tj, char* file ){
    return  tipojuego_graph_logo( tj, file, NULL );
}

DLL_PUBLIC int     qg_tipojuego_graph_logopgn      ( Tipojuego* tj, char* pgn ){
    return  tipojuego_graph_logo( tj, NULL, pgn );
}

/*
 * Funciones de definicion de notacion
 */
void   qg_tipojuego_add_notacion_def( Tipojuego* tj, char elemento ){
    tipojuego_add_notacion_def( tj, elemento );
}
void   qg_tipojuego_add_notacion_rep( Tipojuego* tj, char elemento ){
    tipojuego_add_notacion_rep( tj, elemento );
}
int    qg_tipojuego_add_notacion_tmov( Tipojuego* tj, char* tmov, char* notacion ){
    return tipojuego_add_notacion_tmov( tj, tmov, notacion );
}
int    qg_tipojuego_add_notacion_tpieza( Tipojuego* tj, char* tpieza, char* color, char* abbr ){
    return  tipojuego_add_notacion_tpieza( tj, tpieza, color, abbr );
}
void   qg_tipojuego_set_notacion_marca( Tipojuego* tj, char* marca, char* captura ){
    tipojuego_set_notacion_marca( tj, marca, captura );
}

/*
 * Devuelve verdadero o falso, dependiendo si la partida esta en continuacion
 * o no
 * */
DLL_PUBLIC int         qg_partida_es_continuacion( Partida* par ){
    return  PARTIDACONT( par );
}


DLL_PUBLIC int          qg_partida_mover_serie   ( Partida* par, char* serie ){
    return  partida_mover_serie ( par, serie );
}

DLL_PUBLIC void         qg_partida_free( Partida* par ){
    partida_free( par );
}
DLL_PUBLIC char*        qg_partida_id( Partida* par ){
    return  par->id;
} 

/*
 * Devuelve el final de la partida ... en el caso
 * que haya terminado
 * */
DLL_PUBLIC int          qg_partida_final         ( Partida* par, char** resultado ){
    if( resultado ){
      *resultado = par->resultado;
    }
    if( PARTIDAESTADO(par) == TERMINADA ){
        if( PARTIDATABLAS(par) ){
            return  FINAL_EMPATE;
        } else {
            return  par->color_ganador;
        }
    } else return  FINAL_ENJUEGO;
}

DLL_PUBLIC   int       qg_partida_mover_notacion( Partida* par, char* mov ){
    return     partida_mover_notacion( par, mov );
}
DLL_PUBLIC   char*       qg_partida_pgn( Partida* par ){
    return  partida_pgn( par );
}
DLL_PUBLIC   int         qg_partida_mover         ( Partida* par, int mov ){
    return  partida_mover( par, mov );
}
DLL_PUBLIC   int         qg_partida_count_piezas    ( Partida* par, char* casillero, char* tipopieza ){
    return  partida_count_piezas( par, casillero, tipopieza );
}
/* 
 * Esta funcion parsea la entrada como si fuera un archivo pgn
 * y ejecuta los movimientos establecidos
 * */
DLL_PUBLIC   int         qg_partida_mover_pgn     ( Partida* par, char* pgn ){
    int i = pgnscan_string( pgn );
    if( !i ){
        LOGPRINT( 2, "Error al analizar PGN: %s", pgnerror );
        return 0;
    }
    return  partida_mover_serie( par, pgnmoves );
}

/*
 * Esta funcion especial imprime en la consola de texto
 * las posiciones de las piezas 
 * */
DLL_PUBLIC   void        qg_partida_tablero_ascii ( Partida* par ){
    int i;
    printf( "Partida: %s (%s)\n", par->id, par->tjuego->nombre );
    for( i = 0; i < par->pos->piezas_count; i ++ ){
        Pieza* pie = &( par->pos->piezas[i]);
        if( CASILLERO_VALIDO( pie->casillero ) ){
            printf( "%s %s en %s\n", pie->tpieza->nombre,
                tipojuego_get_colorname( par->tjuego, pie->color ),
                pie->casillero->nombre );
        }
    }
}




DLL_PUBLIC   int         qg_partida_get_png( Partida* par, int flags, int movida, void** png ){
     return partida_get_png( par, flags, movida, png );
}
DLL_PUBLIC   int    qg_tipojuego_get_tablero_png( Tipojuego* tj, int board_number, int flags, void** png, int* width, int* height ){
    return  tipojuego_get_tablero_png( tj, board_number, flags, png, width, height );
}
DLL_PUBLIC   int    qg_tipojuego_get_tpieza_png( Tipojuego* tj, const char* color, const char* tpieza, int flags,
                                                void** png, int* width, int* height){
    return  tipojuego_get_tpieza_png( tj,(char*) color,(char*) tpieza, flags, png, width, height );
}
DLL_PUBLIC   int    qg_tipojuego_get_logo( Tipojuego* tj, void** png, int* width, int* height ){
  return     tipojuego_get_logo( tj, png, width, height );
}

DLL_PUBLIC   void        qgames_free_png( void* png){ graph_free_png( png ); }
DLL_PUBLIC   void        qgames_graph_image_dir( const char* imagedir ){ graph_image_dir( imagedir ); }
DLL_PUBLIC   int         qg_partida_dump( Partida* par, void** data, int* size ){
    return  partida_dump( par, data, size );
}
DLL_PUBLIC   const char* qg_partida_load_tj( void* data, int size ){
    return  partida_load_tj( data, size );
}
DLL_PUBLIC   Partida*    qg_partida_load( Tipojuego* tj, void* data, int size ){
    return  partida_load( tj, data, size );
}
