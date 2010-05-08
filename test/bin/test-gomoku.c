/*
 *
 * QGames. Testeo del gomoku!
 * Haga lo que quiera con el programa, pero no hay garantias
 * Silvio Quadri (c) 2009
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include <time.h>

#include <qgames.h>
#include <qgames_analyzer.h>

#include "../parser/pgn_scanner.h"
#include "log.h"

Tipojuego* gomoku;

int  check_game( char* fname ){
    Partida* par;
    int  ret;
    int abandonado = 0;
    int esperado;
    clock_t  inicio, final;
    int result;
    char* res;


    LOGPRINT( 5, "Analisis de tipojuego completo %s", pgntag_variant );
    if( pgntag_result ){
        LOGPRINT( 5, "Resultado esperado : %s", pgntag_result );
    }

    if( pgntag_termination ){
        abandonado = 1;
    }  

    inicio = clock();
    assert( par = tipojuego_create_partida( gomoku, "x" ) );
    ret = partida_mover_serie( par, pgnmoves );
    final = clock();

    LOGPRINT( 5, "Total %s: %.6f", fname, ((double) (final - inicio)) / CLOCKS_PER_SEC );

    if( !ret ){
        LOGPRINT( 2, "Error al analizar partida %s", pgnmoves );
        partida_free( par );
        return 0;
    }

    if( !pgntag_result ){
        esperado = FINAL_ENJUEGO;
    } else if( strcmp( pgntag_result, "1-0" ) == 0 ){
        esperado = 1;
    } else if ( strcmp( pgntag_result, "0-1" ) == 0 ){
        esperado = 2;
    } else if ( strcmp( pgntag_result, "1/2-1/2" ) == 0 ){
        esperado = FINAL_EMPATE;
    } else if ( strcmp( pgntag_result, "*" ) == 0 ){
        esperado = FINAL_ENJUEGO;
    } else {
        LOGPRINT( 2, "Resultado esperado incorrecto %s", pgntag_result );
        partida_free( par );
        return 0;
    }

    result = partida_final( par, &res );
    if( abandonado && ( result != FINAL_ENJUEGO )  ){
        LOGPRINT( 2, "Resultado con error => %d (term:%s res:%s)", result, pgntag_termination, pgntag_result );
        ret = 0;
    } else if( abandonado ){
        LOGPRINT( 5, "Partida abandonada: %s (term:%s)", (res ? res : "En juego" ), pgntag_termination );
        ret = 1;
    } else if( result != esperado ){
        LOGPRINT( 2, "Resultado con error => %d (%s) (espera:%d res:%s)", result, res, esperado, pgntag_result );
        ret = 0;
    } else {
        LOGPRINT( 5, "Resultado: %s", (res ? res : "En juego" ) );
        ret = 1;
    }
        
    partida_free( par );
    return ret;
    
}

int  main(int argc, char** argv) {
    Partida*   partida;
    int  count = 0;
    char *filename = "../../games/Gomoku.qgame";
    assert( gomoku = qgz_parse_filename( filename, 0 ) );

    loglevel = 2;

    printf( "." );

    assert( tipojuego_get_casillero( gomoku, "a14" ) == NOT_FOUND );
    assert( tipojuego_get_casillero( gomoku, "a13" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( gomoku, "a2" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( gomoku, "a3" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( gomoku, "b1" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( gomoku, "b2" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( gomoku, "b3" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( gomoku, "c1" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( gomoku, "c2" ) != NOT_FOUND );
    assert( tipojuego_get_casillero( gomoku, "c3" ) != NOT_FOUND );
    printf( "." );

    assert( tipojuego_get_color( gomoku, "rojo" ) == NOT_FOUND );
    assert( tipojuego_get_color( gomoku, "blanco" ) == 1 );
    assert( tipojuego_get_color( gomoku, "negro" )  == 2 ) ;
    printf( "." );

    assert( partida = tipojuego_create_partida( gomoku, "x" ) );
    assert( 0 == partida_count_piezas( partida, NULL, NULL ) );
    assert( 99 * 2 == partida_count_piezas( partida, CASILLERO_POZO, NULL ) );
    assert( 0 == partida_count_piezas( partida, "c1", NULL ) );
    assert( 0 == partida_count_piezas( partida, "b1", NULL ) );
    assert( partida_mover_notacion( partida, "c1" ) ); 
    assert( 1 == partida_count_piezas( partida, "c1", NULL ) );
    assert( 0 == partida_count_piezas( partida, "b1", NULL ) );

    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    assert( partida_mover_notacion( partida, "c1" ) == 0 ); 
    assert( partida_mover_notacion( partida, "b1" )  ); 
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    assert( partida_mover_notacion( partida, "c2" )  ); 
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    assert( partida_mover_notacion( partida, "b2" )  ); 
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );

    partida_free( partida );
    printf( "." );

    printf( "\n" );
    return  EXIT_SUCCESS;
}