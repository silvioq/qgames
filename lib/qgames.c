
#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <stdarg.h>
#include  <qgames.h>
#include  <qgames_code.h>

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

void DLL_LOCAL x(){
    qgz_parse_filename();
    pgnscan_string();
    tipojuego_get_tablero_png(NULL,NULL,NULL,NULL);
}

/*  
 * El inicio de todo tipo juego es su creación ... algo muy sencillo
 * por cierto.
 * Hay que crear la tabla de simbolos, agregar el nombre y no mucho más
 * por el momento
 * */
DLL_PUBLIC Tipojuego*   qg_tipojuego_new( char* nombre ){
    return tipojuego_new( nombre );
}

DLL_PUBLIC Partida*     qg_tipojuego_create_partida( Tipojuego* tj, char* id ){
    return  partida_new( tj, id );
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






DLL_PUBLIC int          qg_partida_mover_serie   ( Partida* par, char* serie ){
    return  partida_mover_serie ( par, serie );
}

DLL_PUBLIC void         qg_partida_free( Partida* par ){
    partida_free( par );
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

/*
 * Devuelve la cantidad de movidas que hay generadas
 * */
DLL_PUBLIC   int         qg_partida_movidas_count ( Partida* par ){
    if( PARTIDATERMINADA(par) ) return 0;
    return partida_analizar_movidas( par );
}
DLL_PUBLIC   int         qg_partida_movidas_data  ( Partida* par, int num, char** notacion ){
    return     partida_movidas_data  ( par, num, notacion );
}
DLL_PUBLIC   int         qg_partida_tablero_data  ( Partida* par, int num, char** casillero, char** pieza, char** color ){
    return     partida_tablero_data( par, num, casillero, pieza, color );
}
DLL_PUBLIC   int       qg_partida_mover_notacion( Partida* par, char* mov ){
    return     partida_mover_notacion( par, mov );
}
DLL_PUBLIC   char*       qg_partida_pgn( Partida* par ){
    return  partida_pgn( par );
}
