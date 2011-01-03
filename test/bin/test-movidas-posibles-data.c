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
    int  i, contador;
    int  esta = 0;

    qg_path_set( TEST_GAMESDIR );
    Tipojuego* ajedrez = qg_tipojuego_open( "Ajedrez" );
    Tipojuego* pente = qg_tipojuego_open( "Pente" );

    Partida* partida;
    assert( ajedrez );
    assert( partida = qg_tipojuego_create_partida( ajedrez, NULL ) );
    assert( !qg_partida_movidas_analizadas( partida ) );

    int  movidas = qg_partida_movidas_count( partida );
    assert( qg_partida_movidas_analizadas( partida ) );

    assert( movidas == 20 ); // son 20
    for( i = 0 ; i < movidas ; i ++ ){
        Movdata  movd;
        assert( qg_partida_movidas_data( partida, i, &movd ) );
        assert( !qg_partida_movidas_capturas( partida, i, 0, NULL, NULL, NULL ) );
        if( strcmp( "d4", movd.notacion ) == 0 ){
            char* p, *c, *o, *d, *tp, *tc;
            assert( qg_partida_movidas_pieza( partida, i, &o, &p, &c, &d, &tp, &tc ) );
            assert( strcmp( "peon", p ) == 0 ) ;
            assert( strcmp( "blanco", c ) == 0 ) ;
            assert( strcmp( "d2", o ) == 0 ) ;
            assert( strcmp( "d4", d ) == 0 ) ;
            assert( tp == NULL );
            assert( tc == NULL );
            esta = 1;
        } else if( strcmp( "Nf3", movd.notacion ) == 0 ){
            char* p, *c, *o, *d, *tp, *tc;
            assert( qg_partida_movidas_pieza( partida, i, &o, &p, &c, &d, &tp, &tc ) );
            assert( strcmp( "caballo", p ) == 0 ) ;
            assert( strcmp( "blanco", c ) == 0 ) ;
            assert( strcmp( "g1", o ) == 0 ) ;
            assert( strcmp( "f3", d ) == 0 ) ;
            assert( tp == NULL );
            assert( tc == NULL );
        }
    }
    assert( !qg_partida_movidas_data( partida, i, NULL ) );
    assert( !qg_partida_movidas_capturas( partida, i, 0, NULL, NULL, NULL ) );
    assert( esta );

    assert( qg_partida_mover_pgn( partida, "e4 d5" ) );
    movidas = qg_partida_movidas_count( partida );
    esta = 0;
    for( i = 0; i < movidas; i ++ ){
        Movdata  movd;
        assert( qg_partida_movidas_data( partida, i, &movd ) );
        if( strcmp( movd.notacion, "exd5" ) == 0 ){
            esta = 1;
            assert( qg_partida_movidas_capturas( partida, i, 0, NULL, NULL, NULL ) ); 
            assert( !qg_partida_movidas_capturas( partida, i, 1, NULL, NULL, NULL ) ); 
        } else {
            assert( !qg_partida_movidas_capturas( partida, i, 0, NULL, NULL, NULL ) ); 
        }
    }
    assert( esta );
    qg_partida_free( partida );



    // Vamos ahora por una partida de ajedrez con coronacion para averiguar si se ve
    // bien el tema de la transformacion
    assert( partida = qg_tipojuego_create_partida( ajedrez, NULL ) );
    assert( qg_partida_mover_pgn( partida, "1. b4 h6 2. b5 h5 3. b6 h4 4. bxc7 h3" ) );
    assert( strcmp( qg_partida_color( partida ), "blanco" ) == 0 );
    movidas = qg_partida_movidas_count( partida );
    contador = 0;
    for( i = 0; i < movidas; i ++ ){
        Movdata movd;
        assert( qg_partida_movidas_data( partida, i, &movd ) );
        if( strcmp( movd.notacion, "cxb8=Q" ) == 0 ){
            assert( strcmp( movd.transforma_tipo , "dama" ) == 0 );
            assert( strcmp( movd.transforma_color, "blanco" ) == 0 );
            contador ++;
        } else if( strcmp( movd.notacion, "cxb8=R" ) == 0 ){
            assert( strcmp( movd.transforma_tipo , "torre" ) == 0 );
            assert( strcmp( movd.transforma_color, "blanco" ) == 0 );
            contador ++;
        } else if( strcmp( movd.notacion, "cxb8=N" ) == 0 ){
            assert( strcmp( movd.transforma_tipo , "caballo" ) == 0 );
            assert( strcmp( movd.transforma_color, "blanco" ) == 0 );
            contador ++;
        } else if( strcmp( movd.notacion, "cxb8=B" ) == 0 ){
            assert( strcmp( movd.transforma_tipo , "alfil" ) == 0 );
            assert( strcmp( movd.transforma_color, "blanco" ) == 0 );
            contador ++;
        } else if( strcmp( movd.notacion, "cxd8=Q" ) == 0 ){
            assert( strcmp( movd.transforma_tipo , "dama" ) == 0 );
            assert( strcmp( movd.transforma_color, "blanco" ) == 0 );
            contador ++;
        } else if( strcmp( movd.notacion, "cxd8=R" ) == 0 ){
            assert( strcmp( movd.transforma_tipo , "torre" ) == 0 );
            assert( strcmp( movd.transforma_color, "blanco" ) == 0 );
            contador ++;
        } else if( strcmp( movd.notacion, "cxd8=N" ) == 0 ){
            assert( strcmp( movd.transforma_tipo , "caballo" ) == 0 );
            assert( strcmp( movd.transforma_color, "blanco" ) == 0 );
            contador ++;
        } else if( strcmp( movd.notacion, "cxd8=B" ) == 0 ){
            assert( strcmp( movd.transforma_tipo , "alfil" ) == 0 );
            assert( strcmp( movd.transforma_color, "blanco" ) == 0 );
            contador ++;
        } else {
            assert( movd.transforma_tipo  == NULL );
            assert( movd.transforma_color == NULL );
        }

    }
    assert( contador == 8 );
    



    // Ahora comenzamos con el pente, que tiene pozo y capturas!
    assert( partida = qg_tipojuego_create_partida( pente, NULL ) );
    movidas = qg_partida_movidas_count( partida );
    assert( movidas == 13 * 13 );
    assert( strcmp( qg_partida_color( partida ), "blanco" ) == 0 );
    for( i = 0 ; i < movidas ; i ++ ){
        Movdata  movd;
        assert( qg_partida_movidas_data( partida, i, &movd ) );
        if( strcmp( "d4", movd.notacion ) == 0 ){
            char* p, *c, *o, *d;
            assert( qg_partida_movidas_pieza( partida, i, &o, &p, &c, &d, NULL, NULL ) );
            assert( strcmp( "gema", p ) == 0 ) ;
            assert( strcmp( "blanco", c ) == 0 ) ;
            assert( o == CASILLERO_POZO ) ;
            assert( strcmp( "d4", d ) == 0 ) ;
            esta = 1;
            assert( !qg_partida_movidas_capturas( partida, i, 0, NULL, NULL, NULL ) ); 
        }
    }
    assert( esta );
    assert( qg_partida_mover_pgn( partida, "1.d4 d5 2. e5 d6" ) ); // Ahora, el blanco puede comer dos
    movidas = qg_partida_movidas_count( partida );
    assert( movidas == 13 * 13 - 4 );
    assert( strcmp( qg_partida_color( partida ), "blanco" ) == 0 );

    for( i = 0 ; i < movidas ; i ++ ){
        Movdata  movd;
        assert( qg_partida_movidas_data( partida, i, &movd ) );
        assert( strcmp( "d4", movd.notacion ) != 0 ); // Aca hay una pieza y no puede mover
        if( strcmp( "d7", movd.notacion ) == 0 ){
            char* p, *c, *o, *d;
            assert( qg_partida_movidas_pieza( partida, i, &o, &p, &c, &d, NULL, NULL ) );
            assert( strcmp( "gema", p ) == 0 ) ;
            assert( strcmp( "blanco", c ) == 0 ) ;
            assert( o == CASILLERO_POZO ) ;
            assert( strcmp( "d7", d ) == 0 ) ;
            esta = 1;
            assert( qg_partida_movidas_capturas( partida, i, 0, &d, &p, &c ) ); 
            assert( strcmp( "negro", c ) == 0 );
            assert( strcmp( "gema", p ) == 0 );
            assert( strcmp( "d6", d ) == 0 );
            assert( qg_partida_movidas_capturas( partida, i, 1, &d, &p, &c ) ); 
            assert( strcmp( "negro", c ) == 0 );
            assert( strcmp( "gema", p ) == 0 );
            assert( strcmp( "d5", d ) == 0 );
            assert( !qg_partida_movidas_capturas( partida, i, 2, NULL, NULL, NULL ) ); 

        } else {
            assert( !qg_partida_movidas_capturas( partida, i, 0, NULL, NULL, NULL ) ); 
        }
      
    }
    assert( esta );
    
    
    

  
    exit( EXIT_SUCCESS );
}
