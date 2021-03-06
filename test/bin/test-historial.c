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

/*
 * En este test intentaremos controlar el historial de movimientos
 * de una partida
 * */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include <sys/types.h>
#include <time.h>
#include "log.h"

#include <qgames.h>
#include <qgames_analyzer.h>

int  main( int argc, char** argv ){
    qg_path_set( TEST_GAMESDIR );
    Tipojuego* ajedrez = qg_tipojuego_open( "Ajedrez" );
    Partida* partida;
    Movdata  movd;

    assert( ajedrez );
    assert( partida = qg_tipojuego_create_partida( ajedrez, NULL ) );
  
    assert( qg_partida_movhist_count( partida ) == 0 );
    assert( qg_partida_mover_notacion( partida, "e4" ) );
    assert( qg_partida_movhist_count( partida ) == 1 );

    assert( strcmp( "e4", qg_partida_movhist_destino( partida, 0, 0 ) ) == 0 );
    assert( strcmp( "negro", qg_partida_color( partida ) ) == 0 );
    assert( qg_partida_movhist_destino( partida, 0, 1 ) == NULL  );
    assert( qg_partida_movhist_destino( partida, 1, 0 ) == NULL  );

    assert( !qg_partida_movhist_data( partida, 1, &movd ) );
    assert( qg_partida_movhist_data( partida, 0, &movd ) );
    assert( strcmp( movd.origen, "e2" ) == 0 );
    assert( strcmp( movd.destino, "e4" ) == 0 );
    assert( strcmp( movd.notacion, "e4" ) == 0 );
    assert( strcmp( movd.color, "blanco" ) == 0 );
    assert( strcmp( movd.pieza, "peon" ) == 0 );
    assert( movd.captura == 0 );
    assert( movd.transforma == 0 );

    assert( qg_partida_mover_notacion( partida, "e5" ) );
    assert( qg_partida_movhist_count( partida ) == 2 );
    assert( strcmp( "e4", qg_partida_movhist_destino( partida, 0, 0 ) ) == 0 );
    assert( qg_partida_movhist_destino( partida, 0, 1 ) == NULL  );
    assert( strcmp( "e5", qg_partida_movhist_destino( partida, 1, 0 ) ) == 0 );
    assert( qg_partida_movhist_destino( partida, 1, 1 ) == NULL  );
    assert( strcmp( "blanco", qg_partida_color( partida ) ) == 0 );

    assert( qg_partida_movhist_data( partida, 1, &movd ) );
    assert( strcmp( movd.origen, "e7" ) == 0 );
    assert( strcmp( movd.destino, "e5" ) == 0 );
    assert( strcmp( movd.notacion, "e5" ) == 0 );
    assert( strcmp( movd.color, "negro" ) == 0 );
    assert( strcmp( movd.pieza, "peon" ) == 0 );
    assert( movd.captura == 0 );
    assert( movd.movida  == 1 );
    assert( movd.transforma == 0 );

    assert( qg_partida_mover_pgn( partida, "2. Nf3 Nf6 3. Bc4 Bc5 4. 0-0" ) );
    assert( qg_partida_movhist_count( partida ) == 7 );
    assert( strcmp( "f1", qg_partida_movhist_destino( partida, 6, 0 ) ) == 0 );
    assert( strcmp( "g1", qg_partida_movhist_destino( partida, 6, 1 ) ) == 0 );

    assert( qg_partida_movhist_data( partida, 6, & movd ) );
    assert( strcmp( movd.origen, "e1" ) == 0 );
    assert( strcmp( movd.destino, "g1" ) == 0 );
    assert( strcmp( movd.notacion, "0-0" ) == 0 );
    assert( strcmp( movd.color, "blanco" ) == 0 );
    assert( strcmp( movd.pieza, "rey" ) == 0 );
    assert( movd.captura == 0 );
    assert( movd.movida  == 2 );
    assert( movd.transforma == 0 );

    assert( qg_partida_mover_pgn( partida, "Nxe4" ) );
    assert( qg_partida_movhist_data( partida, 7, & movd ) );
    assert( strcmp( movd.origen, "f6" ) == 0 );
    assert( strcmp( movd.destino, "e4" ) == 0 );
    assert( strcmp( movd.notacion, "Nxe4" ) == 0 );
    assert( strcmp( movd.color, "negro" ) == 0 );
    assert( strcmp( movd.pieza, "caballo" ) == 0 );
    assert( movd.captura );
    assert( strcmp( movd.captura_pieza, "peon" ) == 0 );
    assert( strcmp( movd.captura_color, "blanco" ) == 0 );
    assert( strcmp( movd.captura_casillero, "e4" ) == 0 );
    assert( movd.transforma == 0 );
    qg_partida_free( partida );

    Tipojuego* jubilado = qg_tipojuego_open( "Jubilado" );
    assert( partida = qg_tipojuego_create_partida( jubilado, NULL ) );
    assert( qg_partida_mover_pgn( partida, "b4 b6 c4 g6 g4 g5 a3 b5 c5 Kd8 d3 h6 h4 Ke8 hxg5 a6 gxh6 c6 h7 f6 f3 Kf8 a4 d6 h8=R" ) );

    
    assert( qg_partida_movhist_data( partida, 24, & movd ) );
    printf( "Movida seleccionada es %s\n", movd.notacion );
    assert( strcmp( movd.notacion, "h8=R" ) == 0 );
    assert( movd.transforma );
    assert( strcmp( movd.transforma_pieza, "torre" ) == 0 );
    assert( strcmp( movd.transforma_color, "blanco" ) == 0 );
    assert( !qg_partida_movdata_nextmov( partida, &movd ) );
    qg_partida_free( partida );

    assert( partida = qg_tipojuego_create_partida( ajedrez, NULL ) );
    assert( qg_partida_mover_pgn( partida, "1. g4 e6 2. f3 Qh4" ) );
    assert( qg_partida_final( partida, NULL ) == 2 );
    assert( qg_partida_movhist_count( partida ) == 4 );
    qg_partida_free( partida );

    exit( EXIT_SUCCESS );
}
