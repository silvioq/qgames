
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
#include  "log.h"
#include "../parser/pgn_scanner.h"

void DLL_LOCAL x(){
    qgz_parse_filename();
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

/*
 * Esta funcion especial imprime en la consola de texto
 * las posibles movidas que pueden realizarse en la 
 * posicion actual
 * */
DLL_PUBLIC    void        qg_partida_movidas_posibles_ascii( Partida* par ){
    int cant, i;
    if( PARTIDATERMINADA(par) ){
        printf( "Partida terminada %s\n", par->resultado );
        return;
    }
    cant = partida_analizar_movidas( par );
    for( i = 0; i < cant; i ++ ){
        Movida* mov = (Movida*) par->pos->movidas->data[i];
        if( ( i % 4 == 0 ) && i > 0 ){ printf( "\n" ); };
        printf( "%2d) %-16s", i, mov->notacion );
    }
    printf( "\n" );
}
