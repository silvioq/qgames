/*
 *
 * QGames. Procesador de archivos qgames.
 * Haga lo que quiera con el programa, pero no hay garantias
 * Silvio Quadri (c) 2009
 *
 * */

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <unistd.h>
#include  <time.h>
#include  <qgames.h>
#include  <qgames_analyzer.h>
#include  "log.h"
#include  "../parser/pgn_scanner.h"

void usage(char* prg){

   puts( "Uso:" );
   printf( "  %s [-d] [-v] [-c] [filename.qgame | filename.pgn]\n", prg );
   exit( EXIT_FAILURE );
   
}

int   check_game(char* pgnfile, int flags){
    Tipojuego* tj;
    Partida* par;
    int  ret;
    char filename[256];
    char* res;
    int  abandonado = 0;
    int  esperado = 0;
    int  result;
    clock_t  inicio, final;

    if( !pgntag_variant ){
        printf( "No definida la variante\n" );
        return 0;
    }
    sprintf( filename, "../games/%s.qgame", pgntag_variant );
    tj = qgz_parse_filename( filename, flags );
    if( !tj ){
        LOGPRINT( 2, "Error al analizar %s", filename );
        return 0;
    }
    LOGPRINT( 5, "Analisis de tipojuego completo %s", pgntag_variant );
    if( pgntag_result ){
        LOGPRINT( 5, "Resultado esperado : %s", pgntag_result );
    }

    if( pgntag_termination ){
        abandonado = 1;
    }  

    inicio = clock();
    par = tipojuego_create_partida( tj );
    ret = partida_mover_serie( par, pgnmoves );
    final = clock();
    LOGPRINT( 5, "Total %s: %.6f", pgnfile, ((double) (final - inicio)) / CLOCKS_PER_SEC );

    if( !ret ){
        LOGPRINT( 2, "Error al analizar partida %s", pgnmoves );
        partida_free( par );
        return 0;
    }

    if( !pgntag_result ){
        esperado = FINAL_ENJUEGO;
    } else if( strcmp( pgntag_result, "1-0" ) == 0 ){
        esperado = 1;
    } else if ( strcmp( pgntag_result, "0-1" ) == 0 ){
        esperado = 2;
    } else if ( strcmp( pgntag_result, "1/2-1/2" ) == 0 ){
        esperado = FINAL_EMPATE;
    } else if ( strcmp( pgntag_result, "*" ) == 0 ){
        esperado = FINAL_ENJUEGO;
    } else {
        LOGPRINT( 2, "Resultado esperado incorrecto %s", pgntag_result );
        partida_free( par );
        return 0;
    }

    result = partida_final( par, &res );
    if( abandonado && ( result != FINAL_ENJUEGO )  ){
        LOGPRINT( 2, "Resultado con error => %d (term:%s res:%s)", result, pgntag_termination, pgntag_result );
        ret = 0;
    } else if( abandonado ){
        LOGPRINT( 5, "Partida abandonada: %s (term:%s)", (res ? res : "En juego" ), pgntag_termination );
        ret = 1;
    } else if( result != esperado ){
        LOGPRINT( 2, "Resultado con error => %d (%s) (espera:%d res:%s)", result, res, esperado, pgntag_result );
        ret = 0;
    } else {
        LOGPRINT( 5, "Resultado: %s", (res ? res : "En juego" ) );
        ret = 1;
    }
        
    partida_free( par );
    return ret;
    
}


int  main(int argc, char** argv) {
    int  opt = 0, ret;
    int  flags = 0;
    loglevel = 3;

    while(( opt = getopt( argc, argv, "cdhv" )) != -1 ){
        switch(opt){
            case 'd':
                flags |= QGZ_DEBUG;
                break;
            case 'v':
                flags |= QGZ_VERBOSE;
                loglevel = 5;
                break;
            case 'c':
                break;
            default:
                usage(argv[0]);
        }
    }


    if( optind == argc ){
        ret = pgnscan_file( stdin );
        if( !ret ){
            ret = qgz_parse( stdin, "-", flags );
        } else {
            ret = check_game( "-", flags );
        }
    } else {
        char* filename = argv[optind];
        if( flags & QGZ_VERBOSE ) printf( "Abriendo %s\n", filename );
        ret = pgnscan_fname( filename );
        if( !ret ){
            ret = qgz_parse( NULL, filename, flags );
        } else {
            ret = check_game( filename, flags );
        }
    }

    if( ret ) return EXIT_SUCCESS; else return EXIT_FAILURE;
}
