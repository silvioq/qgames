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
 * En este test intentaremos controlar la informacion devuelta por
 * las funciones de datos de partidas
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
    Tipojuego* ajedrez = qg_tipojuego_open( "Ajedrez" );
    Partida* partida;
    assert( ajedrez );
    assert( partida = qg_tipojuego_create_partida( ajedrez, NULL ) );

    int  movidas = qg_partida_movidas_count( partida );
    int  i;
    assert( movidas == 20 ); // son 20
    for( i = 0 ; i < movidas ; i ++ ){
        assert( qg_partida_movidas_data( partida, i, NULL ) );
        assert( !qg_partida_movidas_capturas( partida, i, 0, NULL, NULL, NULL ) );
    }
    assert( !qg_partida_movidas_data( partida, i, NULL ) );
    assert( !qg_partida_movidas_capturas( partida, i, 0, NULL, NULL, NULL ) );

    assert( qg_partida_mover_pgn( partida, "e4 d5" ) );
    movidas = qg_partida_movidas_count( partida );
    int  esta = 0;
    for( i = 0; i < movidas; i ++ ){
        char* n;
        assert( qg_partida_movidas_data( partida, i, &n ) );
        if( strcmp( n, "exd5" ) == 0 ){
            esta = 1;
            assert( qg_partida_movidas_capturas( partida, i, 0, NULL, NULL, NULL ) ); 
            assert( !qg_partida_movidas_capturas( partida, i, 1, NULL, NULL, NULL ) ); 
        } else {
            printf( "mov: %s\n", n );
            assert( !qg_partida_movidas_capturas( partida, i, 0, NULL, NULL, NULL ) ); 
        }
    }
    assert( esta );
    

  
    exit( EXIT_SUCCESS );
}
