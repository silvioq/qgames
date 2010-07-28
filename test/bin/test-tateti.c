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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <qgames.h>
#include <qgames_code.h>
#include <qgames_analyzer.h>

#include "log.h"


int  main(int argc, char** argv) {
    Tipojuego* tateti, *tateti2;
    Partida*   partida;
    char *filename = "../../games/TaTeTi.qgame";
    assert( tateti = qgz_parse_filename( filename, 0 ) );
    assert( tateti2 = qgz_parse_filename( filename, 0 ) );

    loglevel = 2;

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

    assert( partida = qg_tipojuego_create_partida( tateti, "x" ) );
    assert( 0 == partida_count_piezas( partida, NULL, NULL ) );
    assert( 10 == partida_count_piezas( partida, CASILLERO_POZO, NULL ) );
    assert( 0 == partida_count_piezas( partida, "c1", NULL ) );
    assert( 0 == partida_count_piezas( partida, "b1", NULL ) );
    assert( qg_partida_mover_notacion( partida, "c1" ) ); 
    assert( 1 == partida_count_piezas( partida, "c1", NULL ) );
    assert( 0 == partida_count_piezas( partida, "b1", NULL ) );

    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    assert( qg_partida_mover_notacion( partida, "c1" ) == 0 ); 
    assert( qg_partida_mover_notacion( partida, "b1" )  ); 
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    assert( qg_partida_mover_notacion( partida, "c2" )  ); 
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    assert( qg_partida_mover_notacion( partida, "b2" )  ); 
    assert( partida_final( partida, NULL ) == FINAL_ENJUEGO );
    assert( qg_partida_mover_notacion( partida, "c3" )  ); 
    assert( partida_final( partida, NULL ) != FINAL_ENJUEGO );
    assert( partida_final( partida, NULL ) == 1 );

    partida_free( partida );
    printf( "." );

    char* ahogado = "1. b2 c1 2. b1 b3 3. c3 a1 4. a2 c2 5. a3 1/2-1/2";
    assert( partida = qg_tipojuego_create_partida( tateti, "x" ) );
    assert( partida_mover_pgn( partida, ahogado ) );
    printf( "." );
    assert( partida_final( partida, NULL ) == FINAL_EMPATE );
    partida_free( partida );
    

    char* blancas = "1. b2 b1 2. a3 c1 3. a1 c3 4. a2 1-0";
    assert( partida = qg_tipojuego_create_partida( tateti, "x" ) );
    assert( partida_mover_pgn( partida, blancas ) );
    printf( "." );
    assert( partida_final( partida, NULL ) == 1 );
    partida_free( partida );

    printf( "." );
    assert( tipojuego_valido( tateti2 ) );
    assert( tipojuego_code_casillero( tateti2, "a1" ) );
    assert( tipojuego_valido( tateti2 ) );
    assert( !tipojuego_code_casillero( tateti2, "a4" ) );
    assert( !tipojuego_valido( tateti2 ) );

    printf( "\n" );
    return  EXIT_SUCCESS;
}
