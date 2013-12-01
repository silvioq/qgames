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
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <unistd.h>
#include  <time.h>
#include  <config.h>
#include  <qgames.h>
#include  <qgames_analyzer.h>

#if HAVE_LIBREADLINE
#include  <readline/readline.h>
#endif

#include  "log.h"
#include  "../parser/pgn_scanner.h"

void usage(char* prg){

    puts( "Uso:" );
    printf( "  %s [-d] [-i] [-vv] [-c] [filename.qgame | filename.pgn]\n", prg );
    printf( "  -i : Interactivo (requiere archivo de definiciones de juego)\n" );
    printf( "  -v : Modo verbose. Loglevel 5\n" );
    printf( "  -vv: Modo verbose. Loglevel 6\n" );
    exit( EXIT_FAILURE );
   
}

int isnumeric(char *str)
{
  while(*str)
  {
    if(!isdigit(*str))
      return 0;
    str++;
  }

  return 1;
}


#if(HAVE_LIBREADLINE)

static char * my_getline (const char *prompt)
{
  static char *buf = NULL;        /* Always allocated and freed
                                   from inside this function.  */
  if(buf) free(buf);

  buf = readline(prompt);
  if (buf && *buf) add_history (buf);
  return buf;
}

#else
static char * my_getline (const char *prompt)
{
  static char *buf = NULL;        /* Always allocated and freed
                                   from inside this function.  */
  int count;
  if(!buf) buf = malloc( 1024 );
  printf( prompt );
  fgets(buf, 1024, stdin);
  buf[strlen(buf)-1] = 0;
  return buf;
}
#endif



void  jugar_partida(Partida* par){

    qg_partida_tablero_ascii( par );
    qg_partida_movidas_posibles_ascii( par );
    while( 1 ){
        char* line;
        line = my_getline( "# " );
        if( isnumeric( line ) ){
            if( !qg_partida_mover( par, atol( line ) ) ){
                printf( "No se puede mover %d\n", atoi( line ) );
                continue;
            }
        } else if( strcasecmp( line, "quit" ) == 0 ){
            break;
        } else {
            if( !qg_partida_mover_notacion( par, line ) ){
                printf( "No se puede mover %s\n", line );
                continue;
            }
        }
        qg_partida_tablero_ascii( par );
        qg_partida_movidas_posibles_ascii( par );
    }
};


Partida*  procesar_partida( Tipojuego* tj, char* m, char* filename ){
    clock_t  inicio, final;
    int ret;
    inicio = clock();
    Partida* par = qg_tipojuego_create_partida( tj, NULL );
    if( !m ) return  par;
    ret = qg_partida_mover_serie( par, m );
    final = clock();
    LOGPRINT( 5, "Total %s: %.6f", filename, ((double) (final - inicio)) / CLOCKS_PER_SEC );
    if( !ret ){ qg_partida_free( par ); return NULL ; }
    return  par;
}



Partida*  check_game(char* pgnfile, int flags){
    Tipojuego* tj;
    Partida* par;
    int  ret;
    char filename[256];
    char* res;
    int  abandonado = 0;
    int  esperado = 0;
    int  result;

    if( !pgntag_variant ){
        printf( "No definida la variante\n" );
        return 0;
    }
    sprintf( filename, "../games/%s.qgame", pgntag_variant );
    tj = qgz_parse_filename( filename, flags );
    if( !tj ){
        LOGPRINT( 2, "Error al analizar %s", filename );
        return NULL;
    }
    LOGPRINT( 5, "Analisis de tipojuego completo %s", pgntag_variant );
    if( pgntag_result ){
        LOGPRINT( 5, "Resultado esperado : %s", pgntag_result );
    }

    if( pgntag_termination ){
        abandonado = 1;
    }  

    par =  procesar_partida( tj, pgnmoves, pgnfile );

    if( !par ){
        LOGPRINT( 2, "Error al analizar partida %s", pgnmoves );
        return 0;
    }
    ret = 1;

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
        qg_partida_free( par );
        return 0;
    }

    result = qg_partida_final( par, &res );
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
       
    if( ret ) return par;
    else { 
        qg_partida_free( par );
        return NULL;
    }
    
}


int  main(int argc, char** argv) {
    int  opt = 0, ret;
    int  flags = 0;
    loglevel = 3;
    int  interactivo = 0;
    Partida*  par = NULL;
    Tipojuego* tj = NULL;

    while(( opt = getopt( argc, argv, "cdhiv" )) != -1 ){
        switch(opt){
            case 'd':
                flags |= QGZ_DEBUG;
                break;
            case 'v':
                flags |= QGZ_VERBOSE;
                if( loglevel == 5 ) loglevel = 6;
                else loglevel = 5;
                break;
            case 'c':
                break;
            case 'i':
                interactivo = 1;
                break;
            default:
                usage(argv[0]);
        }
    }


    if( optind == argc ){
        if( interactivo ) usage(argv[0]);
        ret = pgnscan_file( stdin );
        if( !ret ){
            ret = (int)(long)qgz_parse_file( stdin, flags );
        } else {
            par = check_game( "-", flags );
            if( par ) ret = 1; else ret = 0;
        }
    } else {
        char* filename = argv[optind];
        if( tj = qg_tipojuego_open( filename ) ){
            ret = 1;
        } else {
            if( flags & QGZ_VERBOSE ) printf( "Abriendo %s\n", filename );
            ret = pgnscan_fname( filename );
            if( !ret ){
                if( flags & QGZ_VERBOSE ) printf( "Salio por error en pgn %s\n", pgnerror );
                tj = qgz_parse_filename( filename, flags );
                ret = tj ? 1 : 0;
            } else {
                par = check_game( filename, flags );
                if( par ) ret = 1; else ret = 0;
            }
        }
    }

    if( ret && interactivo && par ){
        jugar_partida(par);
    } else if ( ret && interactivo && tj ){
        par = qg_tipojuego_create_partida( tj, NULL );
        jugar_partida(par);
    }
    if( par )    qg_partida_free( par );
    if( ret ) return EXIT_SUCCESS; else return EXIT_FAILURE;
}
