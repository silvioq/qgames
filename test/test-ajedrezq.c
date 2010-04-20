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
Tipojuego* losalamos;

int   los_alamos(){

    Partida*   partida;
    char* notacion;
    char *filename = "../games/AjedrezLosAlamos.qgame";

    printf( "." );
    assert( losalamos = qgz_parse_filename( filename, 0 ) );
    assert( partida = tipojuego_create_partida( losalamos, "x" ) );
    assert( partida_mover_notacion( partida, "e3" ) );

    printf( "." );
    char* prueba1 = "1. d3 d4 2. Qf4 Kd5";
    assert( partida = tipojuego_create_partida( losalamos, "x" ) );
    assert( partida_mover_pgn( partida, prueba1 ) );
    assert( partida_movidas_count( partida ) > 10 );
    assert( partida_mover_notacion( partida, "Qf3" ) );
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );


    printf( "." );
    char* prueba2 = " 1. d3 a4 2. Qe3 a3 3. d4 axb2";
    assert( partida = tipojuego_create_partida( losalamos, "x" ) );
    assert( partida_mover_pgn( partida, prueba2 ) );
    if( partida_movidas_count( partida ) != 21 ){
        partida_movidas_posibles_ascii( partida );
    }
    assert( partida_movidas_count( partida ) == 21 );
    assert( partida_mover_notacion( partida, "Qxe5" ) );
    assert( partida_final( partida, NULL ) == 1 );

    printf( "." );
    char* prueba3 = "d3 e4 2. Qf4";
    assert( partida = tipojuego_create_partida( losalamos, "x" ) );
    assert( partida_mover_pgn( partida, prueba3 ) );
    assert( partida_movidas_count( partida ) == 1 );
    assert( partida_mover_notacion( partida, "Nxf4" ) );
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    
    printf( "." );
    char* prueba4 = "1. a3 e4 2. a4 e3 3. axb5 exf2";
    assert( partida = tipojuego_create_partida( losalamos, "x" ) );
    assert( partida_mover_pgn( partida, prueba4 ) );
    assert( partida_movida_valida( partida, "bxa6=R" ) );
    assert( partida_movida_valida( partida, "bxa6=Q" ) );
    assert( partida_movida_valida( partida, "bxa6=N" ) );
    assert( partida_mover_notacion( partida, "bxa6=N" ) );
    assert( partida_count_piezas( partida, NULL, "caballo" ) == 5 );

    printf( "." );
    char* prueba5 = "1. a3 Nc4 2. a4 Nb6 3. Ra3 Nc4 4. f3 Nb6 5. f4 Nc4";
    assert( partida = tipojuego_create_partida( losalamos, "x" ) );
    assert( partida_mover_pgn( partida, prueba5 ) );
    assert( partida_mover_notacion( partida, "Rf1-f3" ) );
    assert( partida_mover_notacion( partida, "Nb6" ) );
    assert( partida_movidas_count( partida ) == 20 );
    assert( partida_movida_valida( partida, "Ra3-b3" ) );
    assert( partida_movida_valida( partida, "Ra3-c3" ) );
    assert( partida_movida_valida( partida, "Ra3-d3" ) );
    assert( partida_movida_valida( partida, "Ra3-e3" ) );
    assert( partida_movida_valida( partida, "Rf3-b3" ) );
    assert( partida_movida_valida( partida, "Rf3-c3" ) );
    assert( partida_movida_valida( partida, "Rf3-d3" ) );
    assert( partida_movida_valida( partida, "Rf3-e3" ) );
    assert( !partida_movida_valida( partida, "Re3" ) );
    
}




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

    assert( partida = tipojuego_create_partida( aje, "x" ) );
    assert( 12 == partida_count_piezas( partida, NULL, NULL ) );
    assert( 1 == partida_count_piezas( partida, "c1", NULL ) );
    assert( 0 == partida_count_piezas( partida, "b1", NULL ) );
    printf( "." );

    char* prueba1 = "1. c3 bxc3 2. Kc2 Kb5";
    assert( partida_mover_pgn( partida, prueba1 ) );
    assert( partida_movidas_count( partida ) == 9 );
    assert( 11 == partida_count_piezas( partida, NULL, NULL ) );
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
    assert( partida = tipojuego_create_partida( aje, "x" ) );
    assert( partida_mover_pgn( partida, prueba2 ) );
    assert( !partida_mover_notacion( partida, "Kxa3" ) );
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );

    printf( "." );
    char* prueba3 = "1. c3 bxc3 2. dxc3 dxc3 3. bxc3 a3 4. Kd2 Kd5 5. Ke3 Kc5 6. Kxe4 Kb5"; // 7. Kd5";
    assert( partida = tipojuego_create_partida( aje, "x" ) );
    assert( partida_mover_pgn( partida, prueba3 ) );
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    assert( partida_movidas_count( partida ) > 0 );
    assert( partida_mover_notacion( partida, "Kd5" ) );
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );

    printf( "." );
    char* prueba4 = "1. c3 bxc3 2. Kc2 cxd2 3. Kxd2 Kb4 4. a3 Kb3 5. Kc1 Ka2 6. Kd2 Kxb2 7. e3 "
                    "dxe3 8. Kxe3 Kxa3 9. Kxe4 Kb4 10. Ke5 a3 11. Kd4 a2 12. Ke4 a1 ";
    assert( partida = tipojuego_create_partida( aje, "x" ) );
    assert( partida_mover_pgn( partida, prueba4 ) );
    assert( partida_final( partida, NULL ) == 2 ); // gana el negro

    los_alamos() ;


    printf( "\n" );

    return  EXIT_SUCCESS;
}
