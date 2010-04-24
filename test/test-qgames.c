/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2010.
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>

#include  "log.h"

void usage(char* prg){
    puts( "Uso:" );
    printf( "  %s [-v] [filename.qgtest]\n", prg );
    exit( EXIT_FAILURE );
}

int  main(int argc, char** argv) {

    int  opt;

    loglevel = 2;
    while(( opt = getopt( argc, argv, "hv" )) != -1 ){
        switch(opt){
            case 'v':
                loglevel = 5;
                break;
            default:
                usage(argv[0]);
        }
    }

    if( optind == argc ){
        qgtest_file( stdin );
    } else {
        char* filename = argv[optind];
        FILE* f = fopen( filename, "r" );
        if( !f ){
            LOGPRINT( 2, "Error al abrir archivo %s => %s", filename, strerror() );
            exit( EXIT_FAILURE );
        }
        qgtest_file( f );
        fclose( f );
    }
    exit( EXIT_SUCCESS );
}
