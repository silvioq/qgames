/*
 *
 * QGames. Testeo del tateti!
 * Haga lo que quiera con el programa, pero no hay garantias
 * Silvio Quadri (c) 2009
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <qgames.h>
#include <qgames_analyzer.h>

#include "log.h"


int  main(int argc, char** argv) {
    Tipojuego* tateti;
    Partida*   partida;
    int  count = 0;
    char *filename = "../games/TaTeTi.qgame";
    assert( tateti = qgz_parse_filename( filename, 0 ) );

    loglevel = 4;

    printf( "." );

    assert( tipojuego_get_casillero( tateti, "a4" ) == NOT_FOUND );
    assert( tipojuego_get_casillero( tateti, "a1" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( tateti, "a2" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( tateti, "a3" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( tateti, "b1" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( tateti, "b2" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( tateti, "b3" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( tateti, "c1" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( tateti, "c2" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( tateti, "c3" ) != NOT_FOUND );
    printf( "." );

    assert( tipojuego_get_color( tateti, "rojo" ) == NOT_FOUND );
    assert( tipojuego_get_color( tateti, "blanco" ) == 1 );
    assert( tipojuego_get_color( tateti, "negro" )  == 2 ) ;
    printf( "." );

    assert( partida = tipojuego_create_partida( tateti ) );
    assert( count = partida_count_piezas( partida, NULL ) );
    assert( count == partida_count_piezas( partida, CASILLERO_POZO ) );
    assert( 0 == partida_count_piezas( partida, "c1" ) );
    assert( 0 == partida_count_piezas( partida, "b1" ) );
    assert( partida_mover_notacion( partida, "c1" ) ); 
    printf( "Muevo en c1\n" );
    assert( 1 == partida_count_piezas( partida, "c1" ) );
    assert( 0 == partida_count_piezas( partida, "b1" ) );

    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    assert( partida_mover_notacion( partida, "c1" ) == 0 ); 
    printf( "Muevo en b1\n" );
    assert( partida_mover_notacion( partida, "b1" )  ); 
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    printf( "Muevo en c2\n" );
    assert( partida_mover_notacion( partida, "c2" )  ); 
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    assert( partida_mover_notacion( partida, "b2" )  ); 
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    printf( "Muevo en c3\n" );
    assert( partida_mover_notacion( partida, "c3" )  ); 
    assert( partida_final( partida, NULL ) != FINAL_ENJUEGO );
    assert( partida_final( partida, NULL ) == 1 );

    printf( "." );
    printf( "\n" );
    return  EXIT_SUCCESS;
}
