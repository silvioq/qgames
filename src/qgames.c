/*
 *
 * QGames. Procesador de archivos qgames.
 * Haga lo que quiera con el programa, pero no hay garantias
 * Silvio Quadri (c) 2009
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include  <qgames.h>
#include  <qgames_analyzer.h>

void usage(char* prg){

   puts( "Uso:" );
   printf( "  %s [-d] [-v] [-c] [filename.qgame]\n", prg );
   exit( EXIT_FAILURE );
   
}


int  main(int argc, char** argv) {
    int  opt = 0, ret;
    int  flags = 0;

    while(( opt = getopt( argc, argv, "cdhv" )) != -1 ){
        switch(opt){
            case 'd':
                flags |= QGZ_DEBUG;
                break;
            case 'v':
                flags |= QGZ_VERBOSE;
                break;
            case 'c':
                break;
            default:
                usage(argv[0]);
        }
    }


    if( optind == argc ) 
        ret = qgz_parse( stdin, "-", flags );
    else{
        char* filename = argv[optind];
        if( flags & QGZ_VERBOSE ) printf( "Abriendo %s\n", filename );
        ret = qgz_parse( NULL, filename, flags );
    }

    if( ret ) return EXIT_SUCCESS; else return EXIT_FAILURE;
}
