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
    char *filename = "../../games/Ajedrez.qgame";
    void * ajedrez_png;
    FILE*  fpng; 
    int  size, size2, size1;
    int  w, h;

    printf( "." );
    assert( ajedrez = qgz_parse_filename( filename, 0 ) );
    assert( strcmp( "blanco", qg_tipojuego_info_color( ajedrez, 1 ) ) == 0 );
    assert( strcmp( "negro",  qg_tipojuego_info_color( ajedrez, 2 ) ) == 0 );
    assert( qg_tipojuego_info_color( ajedrez, 3 ) == NULL );
    assert( qg_tipojuego_info_color( ajedrez, 0 ) == NULL );

    assert( strcmp( "torre", qg_tipojuego_info_tpieza( ajedrez, 1 ) ) == 0 );
    assert( strcmp( "alfil", qg_tipojuego_info_tpieza( ajedrez, 2 ) ) == 0 );
    assert( qg_tipojuego_info_color( ajedrez, 0 ) == NULL );
    assert( qg_tipojuego_info_color( ajedrez, 7 ) == NULL );

    assert( !qg_tipojuego_info_color_rotado( ajedrez, 1 ) );
    assert( qg_tipojuego_info_color_rotado( ajedrez, 2 ) );
    

#if GRAPH_ENABLED
    qgames_graph_image_dir( TEST_IMGDIR );
    size = qg_tipojuego_get_tablero_png( ajedrez, BOARD_ACTUAL, 0, &ajedrez_png, &w, &h );
    printf( "." );
    assert( size );
    assert( w == 384 );
    assert( h == 384 );

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
    size = qg_tipojuego_get_tablero_png( ajedrez, BOARD_ACTUAL, GETPNG_ROTADO, &ajedrez_png, &w, &h );
    fpng = fopen( "../../tmp/ajedrez-r.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    assert( w == 384 );
    assert( h == 384 );
    fclose( fpng ); 
    
    assert( size == 1426 );
    assert( md5_mem( ajedrez_png, size ) == -1446965539 );
    qgames_free_png( ajedrez_png );  

    printf( "." );
    size = qg_tipojuego_get_tpieza_png( ajedrez, "blanco", "peon", 0, &ajedrez_png, &w, &h );
    fpng = fopen( "../../tmp/ajedrez-peon.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    assert( size == 298 );
    assert( w == 48 );
    assert( h == 48 );
    qgames_free_png( ajedrez_png );  

    printf( "." );
    size = qg_tipojuego_get_tpieza_png( ajedrez, "blanco", "peon", GETPNG_PIEZA_CAPTURADA, &ajedrez_png, &w, &h );
    fpng = fopen( "../../tmp/ajedrez-peon-capturado.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    assert( w == 24 );
    assert( h == 24 );
    qgames_free_png( ajedrez_png );  

    printf( "." );
    size = qg_tipojuego_get_tpieza_png( ajedrez, "negro", "rey", 0, &ajedrez_png, &w, &h );
    fpng = fopen( "../../tmp/ajedrez-rey.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    assert( size == 433 );
    assert( w == 48 );
    assert( h == 48 );
    qgames_free_png( ajedrez_png );  

    printf( "." );
    size = qg_tipojuego_get_tpieza_png( ajedrez, "negro", "rey", GETPNG_PIEZA_CAPTURADA, &ajedrez_png, &w, &h );
    fpng = fopen( "../../tmp/ajedrez-rey-capturado.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    assert( w == 24 );
    assert( h == 24 );
    qgames_free_png( ajedrez_png );  

    printf( "." );
    partida = qg_tipojuego_create_partida( ajedrez, NULL );
    size = qg_partida_get_png( partida, 0, LAST_MOVE, &ajedrez_png );
    assert( size > 0 );
    fpng = fopen( "../../tmp/ajedrez-inicio.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size == 10759 );

    size = qg_partida_get_png( partida, GETPNG_ROTADO, LAST_MOVE, &ajedrez_png );
    assert( size > 0 );
    fpng = fopen( "../../tmp/ajedrez-inicio-r.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size == 10773 );

    assert( !qg_partida_es_continuacion( partida )  );
    assert( qg_partida_mover_notacion( partida, "e4" ) );
    assert( !qg_partida_es_continuacion( partida )  );
    assert( strcmp( "negro", qg_partida_color( partida ) ) == 0 );
    size = qg_partida_get_png( partida, 0, LAST_MOVE, &ajedrez_png );
    assert( size > 0 );
    fpng = fopen( "../../tmp/ajedrez-01.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  

    size2 = qg_partida_get_png( partida, GETPNG_HIGHLIGHT_RED, LAST_MOVE, &ajedrez_png );
    assert( size2 > 0 );
    fpng = fopen( "../../tmp/ajedrez-01-h.png", "w" );
    assert( fwrite( ajedrez_png, size2, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size2 > size );
    size1 = size2;

    size = qg_partida_get_png( partida, GETPNG_ROTADO, LAST_MOVE, &ajedrez_png );
    assert( size > 0 );
    fpng = fopen( "../../tmp/ajedrez-01-r.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  

    size2 = qg_partida_get_png( partida, GETPNG_HIGHLIGHT_RED | GETPNG_ROTADO, LAST_MOVE, &ajedrez_png );
    assert( size2 > 0 );
    fpng = fopen( "../../tmp/ajedrez-01-rh.png", "w" );
    assert( fwrite( ajedrez_png, size2, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size2 > size );

    printf( "." );
    assert( qg_partida_mover_notacion( partida, "e5" ) );
    assert( !qg_partida_es_continuacion( partida )  );
    size = qg_partida_get_png( partida, 0, LAST_MOVE, &ajedrez_png );
    assert( size > 0 );
    fpng = fopen( "../../tmp/ajedrez-02.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  

    size2 = qg_partida_get_png( partida, GETPNG_HIGHLIGHT_RED, LAST_MOVE, &ajedrez_png );
    assert( size2 > 0 );
    fpng = fopen( "../../tmp/ajedrez-02-h.png", "w" );
    assert( fwrite( ajedrez_png, size2, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size2 > size );

    size = qg_partida_get_png( partida, GETPNG_ROTADO, LAST_MOVE, &ajedrez_png );
    assert( size > 0 );
    fpng = fopen( "../../tmp/ajedrez-02-r.png", "w" );
    assert( fwrite( ajedrez_png, size, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  

    size2 = qg_partida_get_png( partida, GETPNG_HIGHLIGHT_RED | GETPNG_ROTADO, LAST_MOVE, &ajedrez_png );
    assert( size2 > 0 );
    fpng = fopen( "../../tmp/ajedrez-02-rh.png", "w" );
    assert( fwrite( ajedrez_png, size2, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size2 > size );

    /* Ahora vuelvo a dibujar la movida 1 deberia estar viendo lo mismo
       que vi oportunamente */
    size2 = qg_partida_get_png( partida, GETPNG_HIGHLIGHT_RED, 1, &ajedrez_png );
    assert( size2 > 0 );
    fpng = fopen( "../../tmp/ajedrez-01-old.png", "w" );
    assert( fwrite( ajedrez_png, size2, 1, fpng ) );
    fclose( fpng ); 
    qgames_free_png( ajedrez_png );  
    assert( size1 == size2 );

    qg_partida_free( partida );
#else
    // Si no tengo los graficos habilitados, esto tiene que volver con
    // cero
    assert( qg_tipojuego_get_tablero_png( ajedrez, BOARD_ACTUAL, 0, NULL, NULL, NULL ) == 0 );
#endif
    
    
}

int   los_alamos(){

    Partida*   partida;
    char *filename = "../../games/AjedrezLosAlamos.qgame";

    printf( "." );
    assert( losalamos = qgz_parse_filename( filename, 0 ) );
    assert( partida = qg_tipojuego_create_partida( losalamos, "x" ) );
    assert( qg_partida_mover_notacion( partida, "e3" ) );
    qg_partida_free( partida );

    printf( "." );
    char* prueba1 = "1. d3 d4 2. Qf4 Kd5";
    assert( partida = qg_tipojuego_create_partida( losalamos, "x" ) );
    assert( qg_partida_mover_pgn( partida, prueba1 ) );
    assert( qg_partida_movidas_count( partida ) > 10 );
    assert( qg_partida_mover_notacion( partida, "Qf3" ) );
    assert( qg_partida_final( partida, NULL ) == FINAL_ENJUEGO );
    qg_partida_free( partida );


    printf( "." );
    char* prueba2 = " 1. d3 a4 2. Qe3 a3 3. d4 axb2";
    assert( partida = qg_tipojuego_create_partida( losalamos, "x" ) );
    assert( qg_partida_mover_pgn( partida, prueba2 ) );
    if( qg_partida_movidas_count( partida ) != 21 ){
        qg_partida_movidas_posibles_ascii( partida );
    }
    assert( qg_partida_movidas_count( partida ) == 21 );
    assert( qg_partida_mover_notacion( partida, "Qxe5" ) );
    assert( qg_partida_final( partida, NULL ) == 1 );
    qg_partida_free( partida );

    printf( "." );
    char* prueba3 = "d3 e4 2. Qf4";
    assert( partida = qg_tipojuego_create_partida( losalamos, "x" ) );
    assert( qg_partida_mover_pgn( partida, prueba3 ) );
    assert( qg_partida_movidas_count( partida ) == 1 );
    assert( qg_partida_mover_notacion( partida, "Nxf4" ) );
    assert( qg_partida_final( partida, NULL ) == FINAL_ENJUEGO );
    qg_partida_free( partida );
    
    printf( "." );
    char* prueba4 = "1. a3 e4 2. a4 e3 3. axb5 exf2";
    assert( partida = qg_tipojuego_create_partida( losalamos, "x" ) );
    assert( qg_partida_mover_pgn( partida, prueba4 ) );
    assert( qg_partida_movida_valida( partida, "bxa6=R" ) );
    assert( qg_partida_movida_valida( partida, "bxa6=Q" ) );
    assert( qg_partida_movida_valida( partida, "bxa6=N" ) );
    assert( strcmp( "blanco", qg_partida_color( partida ) ) == 0 );
    assert( qg_partida_mover_notacion( partida, "bxa6=N" ) );
    assert( !qg_partida_es_continuacion( partida )  );
    assert( strcmp( "negro", qg_partida_color( partida ) ) == 0 );
    assert( qg_partida_count_piezas( partida, NULL, "caballo" ) == 5 );
    qg_partida_free( partida );

    printf( "." );
    char* prueba5 = "1. a3 Nc4 2. a4 Nb6 3. Ra3 Nc4 4. f3 Nb6 5. f4 Nc4";
    assert( partida = qg_tipojuego_create_partida( losalamos, "x" ) );
    assert( qg_partida_mover_pgn( partida, prueba5 ) );
    assert( qg_partida_mover_notacion( partida, "Rf1-f3" ) );
    assert( qg_partida_mover_notacion( partida, "Nb6" ) );
    assert( qg_partida_movidas_count( partida ) == 20 );
    assert( qg_partida_movida_valida( partida, "Ra3-b3" ) );
    assert( qg_partida_movida_valida( partida, "Ra3-c3" ) );
    assert( qg_partida_movida_valida( partida, "Ra3-d3" ) );
    assert( qg_partida_movida_valida( partida, "Ra3-e3" ) );
    assert( qg_partida_movida_valida( partida, "Rf3-b3" ) );
    assert( qg_partida_movida_valida( partida, "Rf3-c3" ) );
    assert( qg_partida_movida_valida( partida, "Rf3-d3" ) );
    assert( qg_partida_movida_valida( partida, "Rf3-e3" ) );
    assert( !qg_partida_movida_valida( partida, "Re3" ) );
    qg_partida_free( partida );
    
}




int  main(int argc, char** argv) {
    Partida*   partida;
    char *filename = "../../games/AjedrezQGames.qgame";
    assert( aje = qgz_parse_filename( filename, 0 ) );

    loglevel = 2;
    Movdata movd;

    printf( "." );

    assert( qg_tipojuego_get_casillero( aje, "a14" ) == NOT_FOUND );
    assert( qg_tipojuego_get_casillero( aje, "a6" ) == NOT_FOUND );
    assert( qg_tipojuego_get_casillero( aje, "a2" ) != NOT_FOUND );
    assert( qg_tipojuego_get_casillero( aje, "a3" ) != NOT_FOUND );
    assert( qg_tipojuego_get_casillero( aje, "b1" ) != NOT_FOUND );
    assert( qg_tipojuego_get_casillero( aje, "b2" ) != NOT_FOUND );
    assert( qg_tipojuego_get_casillero( aje, "b3" ) != NOT_FOUND );
    assert( qg_tipojuego_get_casillero( aje, "c1" ) != NOT_FOUND );
    assert( qg_tipojuego_get_casillero( aje, "c2" ) != NOT_FOUND );
    assert( qg_tipojuego_get_casillero( aje, "c3" ) != NOT_FOUND );
    printf( "." );

    assert( qg_tipojuego_get_color( aje, "rojo" ) == NOT_FOUND );
    assert( qg_tipojuego_get_color( aje, "blanco" ) == 1 );
    assert( qg_tipojuego_get_color( aje, "negro" )  == 2 ) ;
    printf( "." );

    assert( partida = qg_tipojuego_create_partida( aje, "x" ) );
    assert( 12 == qg_partida_count_piezas( partida, NULL, NULL ) );
    assert( 1 == qg_partida_count_piezas( partida, "c1", NULL ) );
    assert( 0 == qg_partida_count_piezas( partida, "b1", NULL ) );
    printf( "." );

    char* prueba1 = "1. c3 bxc3 2. Kc2 Kb5";
    assert( qg_partida_mover_pgn( partida, prueba1 ) );
    assert( qg_partida_movidas_count( partida ) == 9 );
    assert( 11 == qg_partida_count_piezas( partida, NULL, NULL ) );
    qg_partida_movidas_data( partida, 0, &movd );
    assert( strcmp( movd.notacion, "Kc1" ) == 0 ) ;
    qg_partida_movidas_data( partida, 1, &movd );
    assert( strcmp( movd.notacion, "Kb1" ) == 0 ) ;
    qg_partida_movidas_data( partida, 2, &movd );
    assert( strcmp( movd.notacion, "Kd1" ) == 0 ) ;
    
    // No puede mover a b3, porque lo amenazan
    assert( !qg_partida_mover_notacion( partida, "Kb3" ) );
    // No puede mover a d3, porque lo amenazan
    assert( !qg_partida_mover_notacion( partida, "Kd3" ) );
    // En c3 hay un peon
    assert( !qg_partida_mover_notacion( partida, "Kc3" ) );
    qg_partida_free( partida );

    printf( "." );
    char* prueba2 = " 1. c3 bxc3 2. dxc3 dxc3 3. e3 cxb2 4. Kxb2 Kb4 5. a3";
    assert( partida = qg_tipojuego_create_partida( aje, "x" ) );
    assert( qg_partida_mover_pgn( partida, prueba2 ) );
    assert( !qg_partida_mover_notacion( partida, "Kxa3" ) );
    assert( qg_partida_final( partida, NULL ) == FINAL_ENJUEGO );
    qg_partida_free( partida );

    printf( "." );
    char* prueba3 = "1. c3 bxc3 2. dxc3 dxc3 3. bxc3 a3 4. Kd2 Kd5 5. Ke3 Kc5 6. Kxe4 Kb5"; // 7. Kd5";
    assert( partida = qg_tipojuego_create_partida( aje, "x" ) );
    assert( qg_partida_mover_pgn( partida, prueba3 ) );
    assert( qg_partida_final( partida, NULL ) == FINAL_ENJUEGO );
    assert( qg_partida_movidas_count( partida ) > 0 );
    assert( qg_partida_mover_notacion( partida, "Kd5" ) );
    assert( qg_partida_final( partida, NULL ) == FINAL_ENJUEGO );
    qg_partida_free( partida );

    printf( "." );
    char* prueba4 = "1. c3 bxc3 2. Kc2 cxd2 3. Kxd2 Kb4 4. a3 Kb3 5. Kc1 Ka2 6. Kd2 Kxb2 7. e3 "
                    "dxe3 8. Kxe3 Kxa3 9. Kxe4 Kb4 10. Ke5 a3 11. Kd4 a2 12. Ke4 a1 ";
    assert( partida = qg_tipojuego_create_partida( aje, "x" ) );
    assert( qg_partida_mover_pgn( partida, prueba4 ) );
    assert( qg_partida_final( partida, NULL ) == 2 ); // gana el negro
    qg_partida_free( partida );

    // Controlo que no falle el tema de los graficos
#if GRAPH_ENABLED
    assert( qg_tipojuego_get_tablero_png( aje, BOARD_ACTUAL, 0, NULL, NULL, NULL ) == 0 );
#endif
    



    los_alamos() ;

    ajedrez_check();
    printf( "\n" );

    return  EXIT_SUCCESS;
}
