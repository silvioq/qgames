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

#include <time.h>
#include  <sys/types.h>
#include  <dirent.h>
#include  <errno.h>
#include "log.h"

#include <qgames.h>
#include "config.h"
#include <qgames_analyzer.h>



int  main(int argc, char** argv) {
    Tipojuego* ajedrez, *africa;
    Partida*  p1, *p2;
    char* filename ;
    int i;

    qg_path_set( TEST_GAMESDIR );
    qgames_graph_image_dir( TEST_IMGDIR );
    loglevel = 2;

#if GRAPH_ENABLED
    const char* dirname = qg_path_games( );
    DIR*  d = opendir( dirname );
    struct  dirent*  ent;
    if( !d ){
        LOGPRINT( 2, "Error al abrir directorio %s => %d %s", dirname, errno, strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    while( ent = readdir( d ) ){
        char nombre[256];
        if( ent->d_name[0] == '.' ) continue;
        strcpy( nombre, ent->d_name );
        char* aux = strstr( nombre, ".qgame" );
        if( !aux ) { continue; }
        aux[0] = 0;
        LOGPRINT( 5, "Definicion encontrada => %s", nombre );
        Tipojuego* tj = qg_tipojuego_open( nombre );
        assert( tj );
        int size;
        void* datapng;
        /* Controlo que tenga imagen el tablero */
        size = qg_tipojuego_get_tablero_png( tj, BOARD_ACTUAL, 0, &datapng, NULL, NULL );
        if( size ){
            qgames_free_png( datapng );
            size = qg_tipojuego_get_logo( tj, &datapng, NULL, NULL );
            assert( size );
            static char  filename[256];
            FILE* fpng;
            sprintf( filename, "../../tmp/logo-%s.png", nombre );
            fpng = fopen( filename, "w" );
            assert( fwrite( datapng, size, 1, fpng ) );
            fclose( fpng ); 
            qgames_free_png( datapng );
        } else {
            LOGPRINT( 2, "No hay tablero para %s", nombre );
        }
    }

    return EXIT_SUCCESS;

#else
    printf( "Graficos no habilitados\n" );
    return 0;
#endif

}

