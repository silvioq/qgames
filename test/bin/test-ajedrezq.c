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
 *
 * QGames. Testeo de ajedreces varios
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
#include "config.h"

Tipojuego* aje;
Tipojuego* losalamos;
Tipojuego* ajedrez;

int   ajedrez_check(){

    Partida*   partida;
    char* notacion;
    char *filename = "../../games/Ajedrez.qgame";
    void * ajedrez_png;
    FILE*  fpng; 
    int  size, size2, size1;

    printf( "." );
    assert( ajedrez = qgz_parse_filename( filename, 0 ) );

#if GRAPH_ENABLED
    qgames_graph_image_dir( TEST_IMGDIR );
    size = tipojuego_get_tablero_png( ajedrez, BOARD_ACTUAL, 0, &ajedrez_png );
    printf( "." );
    assert( size );

    fpng = fopen( "../../tmp/ajedrez.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 

    assert( size == 1426 );
    if( md5_mem( ajedrez_png, size ) != -1446965539 ){
        printf( "Atencion cambio el md5 => %d\n", md5_mem( ajedrez_png, size ) );
    }
    assert( md5_mem( ajedrez_png, size ) == -1446965539 );
    qgames_free_png( ajedrez_png );  

    printf( "." );
    size = tipojuego_get_tablero_png( ajedrez, BOARD_ACTUAL, GETPNG_ROTADO, &ajedrez_png );
    fpng = fopen( "../../tmp/ajedrez-r.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    
    assert( size == 1426 );
    assert( md5_mem( ajedrez_png, size ) == -1446965539 );
    qgames_free_png( ajedrez_png );  

    printf( "." );
    size = tipojuego_get_tpieza_png( ajedrez, "blanco", "peon", &ajedrez_png );
    fpng = fopen( "../../tmp/ajedrez-peon.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    assert( size == 298 );
    qgames_free_png( ajedrez_png );  


    printf( "." );
    size = tipojuego_get_tpieza_png( ajedrez, "negro", "rey", &ajedrez_png );
    fpng = fopen( "../../tmp/ajedrez-rey.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    assert( size == 433 );
    qgames_free_png( ajedrez_png );  

    printf( "." );
    partida = tipojuego_create_partida( ajedrez, NULL );
    size = partida_get_png( partida, 0, LAST_MOVE, &ajedrez_png );
    assert( size > 0 );
    fpng = fopen( "../../tmp/ajedrez-inicio.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size == 10759 );

    size = partida_get_png( partida, GETPNG_ROTADO, LAST_MOVE, &ajedrez_png );
    assert( size > 0 );
    fpng = fopen( "../../tmp/ajedrez-inicio-r.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size == 10773 );

    assert( partida_mover_notacion( partida, "e4" ) );
    size = partida_get_png( partida, 0, LAST_MOVE, &ajedrez_png );
    assert( size > 0 );
    fpng = fopen( "../../tmp/ajedrez-01.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  

    size2 = partida_get_png( partida, GETPNG_HIGHLIGHT_RED, LAST_MOVE, &ajedrez_png );
    assert( size2 > 0 );
    fpng = fopen( "../../tmp/ajedrez-01-h.png", "w" );
    assert( fwrite( ajedrez_png, size2, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size2 > size );
    size1 = size2;

    size = partida_get_png( partida, GETPNG_ROTADO, LAST_MOVE, &ajedrez_png );
    assert( size > 0 );
    fpng = fopen( "../../tmp/ajedrez-01-r.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  

    size2 = partida_get_png( partida, GETPNG_HIGHLIGHT_RED | GETPNG_ROTADO, LAST_MOVE, &ajedrez_png );
    assert( size2 > 0 );
    fpng = fopen( "../../tmp/ajedrez-01-rh.png", "w" );
    assert( fwrite( ajedrez_png, size2, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size2 > size );

    printf( "." );
    assert( partida_mover_notacion( partida, "e5" ) );
    size = partida_get_png( partida, 0, LAST_MOVE, &ajedrez_png );
    assert( size > 0 );
    fpng = fopen( "../../tmp/ajedrez-02.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  

    size2 = partida_get_png( partida, GETPNG_HIGHLIGHT_RED, LAST_MOVE, &ajedrez_png );
    assert( size2 > 0 );
    fpng = fopen( "../../tmp/ajedrez-02-h.png", "w" );
    assert( fwrite( ajedrez_png, size2, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size2 > size );

    size = partida_get_png( partida, GETPNG_ROTADO, LAST_MOVE, &ajedrez_png );
    assert( size > 0 );
    fpng = fopen( "../../tmp/ajedrez-02-r.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  

    size2 = partida_get_png( partida, GETPNG_HIGHLIGHT_RED | GETPNG_ROTADO, LAST_MOVE, &ajedrez_png );
    assert( size2 > 0 );
    fpng = fopen( "../../tmp/ajedrez-02-rh.png", "w" );
    assert( fwrite( ajedrez_png, size2, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size2 > size );

    /* Ahora vuelvo a dibujar la movida 1 deberia estar viendo lo mismo
       que vi oportunamente */
    size2 = partida_get_png( partida, GETPNG_HIGHLIGHT_RED, 1, &ajedrez_png );
    assert( size2 > 0 );
    fpng = fopen( "../../tmp/ajedrez-01-old.png", "w" );
    assert( fwrite( ajedrez_png, size2, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size1 == size2 );
#else
    // Si no tengo los graficos habilitados, esto tiene que volver con
    // cero
    assert( tipojuego_get_tablero_png( ajedrez, BOARD_ACTUAL, 0, NULL ) == 0 );
#endif
    
    
}

int   los_alamos(){

    Partida*   partida;
    char* notacion;
    char *filename = "../../games/AjedrezLosAlamos.qgame";

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
    char *filename = "../../games/AjedrezQGames.qgame";
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

    ajedrez_check();


    printf( "\n" );

    return  EXIT_SUCCESS;
}
