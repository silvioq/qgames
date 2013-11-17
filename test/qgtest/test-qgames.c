/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2010.
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>
#include  <string.h>
#include  <errno.h>

#include  "log.h"

static int  benchmark = 0;
void   show_benchmark();

void usage(char* prg){
    puts( "Uso:" );
    printf( "  %s [-bv] [filename.qgtest]\n", prg );
    exit( EXIT_FAILURE );
}

int  main(int argc, char** argv) {

    int  opt;

    loglevel = 2;
    while(( opt = getopt( argc, argv, "hbv" )) != -1 ){
        switch(opt){
            case 'v':
                loglevel = 5;
                break;
            case 'b':
                benchmark = 1;
                break;
            default:
                usage(argv[0]);
        }
    }

    qg_path_set( TEST_GAMESDIR );
    if( optind == argc ){
        qgtest_file( stdin );
    } else {
        char* filename = argv[optind];
        FILE* f = fopen( filename, "r" );
        if( !f ){
            LOGPRINT( 2, "Error al abrir archivo %s => %s", filename, strerror( errno ) );
            exit( EXIT_FAILURE );
        }
        qgtest_file( f );
        fclose( f );
    }

    if( benchmark ){
        show_benchmark();
    }

    exit( EXIT_SUCCESS );
}
