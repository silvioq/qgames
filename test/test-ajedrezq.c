/*
 *
 * QGames. Testeo de ajedreces varios
 * Haga lo que quiera con el programa, pero no hay garantias
 * Silvio Quadri (c) 2010
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include <sys/types.h>
#include <dirent.h>
#include <time.h>

#include <qgames.h>
#include <qgames_analyzer.h>

#include "../parser/pgn_scanner.h"
#include "log.h"

Tipojuego* aje;


int  main(int argc, char** argv) {
    Partida*   partida;
    char* notacion;
    char *filename = "../games/AjedrezQGames.qgame";
    assert( aje = qgz_parse_filename( filename, 0 ) );

    loglevel = 2;

    printf( "." );

    assert( tipojuego_get_casillero( aje, "a14" ) == NOT_FOUND );
    assert( tipojuego_get_casillero( aje, "a6" ) == NOT_FOUND );
    assert( tipojuego_get_casillero( aje, "a2" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( aje, "a3" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( aje, "b1" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( aje, "b2" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( aje, "b3" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( aje, "c1" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( aje, "c2" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( aje, "c3" ) != NOT_FOUND );
    printf( "." );

    assert( tipojuego_get_color( aje, "rojo" ) == NOT_FOUND );
    assert( tipojuego_get_color( aje, "blanco" ) == 1 );
    assert( tipojuego_get_color( aje, "negro" )  == 2 ) ;
    printf( "." );

    assert( partida = tipojuego_create_partida( aje ) );
    assert( 12 == partida_count_piezas( partida, NULL ) );
    assert( 1 == partida_count_piezas( partida, "c1" ) );
    assert( 0 == partida_count_piezas( partida, "b1" ) );
    printf( "." );

    char* prueba1 = "1. c3 bxc3 2. Kc2 Kb5";
    assert( partida_mover_pgn( partida, prueba1 ) );
    assert( partida_movidas_count( partida ) == 9 );
    assert( 11 == partida_count_piezas( partida, NULL ) );
    partida_movidas_data( partida, 0, &notacion );
    assert( strcmp( notacion, "Kc1" ) == 0 ) ;
    partida_movidas_data( partida, 1, &notacion );
    assert( strcmp( notacion, "Kb1" ) == 0 ) ;
    partida_movidas_data( partida, 2, &notacion );
    assert( strcmp( notacion, "Kd1" ) == 0 ) ;
    
    // No puede mover a b3, porque lo amenazan
    assert( !partida_mover_notacion( partida, "Kb3" ) );
    // No puede mover a d3, porque lo amenazan
    assert( !partida_mover_notacion( partida, "Kd3" ) );
    // En c3 hay un peon
    assert( !partida_mover_notacion( partida, "Kc3" ) );

    printf( "." );
    char* prueba2 = " 1. c3 bxc3 2. dxc3 dxc3 3. e3 cxb2 4. Kxb2 Kb4 5. a3";
    assert( partida = tipojuego_create_partida( aje ) );
    assert( partida_mover_pgn( partida, prueba2 ) );
    assert( !partida_mover_notacion( partida, "Kxa3" ) );
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );

    printf( "." );
    char* prueba3 = "1. c3 bxc3 2. dxc3 dxc3 3. bxc3 a3 4. Kd2 Kd5 5. Ke3 Kc5 6. Kxe4 Kb5"; // 7. Kd5";
    assert( partida = tipojuego_create_partida( aje ) );
    assert( partida_mover_pgn( partida, prueba3 ) );
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    assert( partida_movidas_count( partida ) > 0 );
    loglevel = 5;
    assert( partida_mover_notacion( partida, "Kd5" ) );
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    


    printf( "\n" );
    return  EXIT_SUCCESS;
}
