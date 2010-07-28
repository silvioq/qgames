%{
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

#include  "config.h"
#include  <qgames.h>
#include  <qgames_analyzer.h>
#include <time.h>
#include <sys/time.h>
#include  "list.h"
#include  "log.h"

int    nuevo_juego( char* );
void   add_movida( char* );

int    inciar_chequeo( int );
void   count_piezas_add_parameter( char* );
int    chequear();
void   show_benchmark();
void   chequear_resultado(int);
void   check_count_piezas(int);
void   chequear_count_movidas(int);
void   chequear_movida_valida(char*);

Partida*  partida    = NULL;
Tipojuego* tjuego    = NULL;
_list*    tipojuegos = NULL;
_list*    checklist  = NULL;
extern  int benchmark ;

static  double   time_scanning = 0.0;
static  double   time_moves    = 0.0;

typedef  struct strCheck{
    char*   casillero;
    char*   tipopieza;
    char*   color;
    char*   movida;
} strcheck;

%}

%option batch
%option yylineno
%option noyywrap
%x      check_movida  check_result check_piezas  nombre_juego   verbose_state

SPACES       [ ]+
BAR          (\_|\-)?
NUM          [0-9]+
WORD         ([a-zA-Z\?][a-zA-Z0-9\-\_]*\??)
MOVENUMBER   [0-9]+\.
DOTS         \.{2,3}
MOVE         [0a-zA-Z][0-9a-zA-Z\-\+\#\/\=]+
WWIN         1\-0
BWIN         0\-1
DRAW         1\/2\-1\/2
RESULT       ({DRAW}|{BWIN}|{WWIN}|\*)

%%

<INITIAL>nuevo{BAR}juego        { BEGIN(nombre_juego); }
<INITIAL>check{BAR}piezas       { iniciar_chequeo( ); BEGIN(check_piezas); }
<INITIAL>check{BAR}movidas?     { BEGIN(check_movida); }  
<INITIAL>check{BAR}result       { BEGIN(check_result); }  
<INITIAL>show{BAR}movidas       { qg_partida_movidas_posibles_ascii( partida ) ; }
<INITIAL>show{BAR}tablero       { qg_partida_tablero_ascii( partida ) ; }
<INITIAL>show{BAR}benchmark     { show_benchmark() ; }
<INITIAL>verbose                { BEGIN(verbose_state); }

<nombre_juego>{WORD}            { nuevo_juego( yytext ); BEGIN(INITIAL); }

<INITIAL>{RESULT}               { yyless( 0 ); BEGIN(check_result); }
<INITIAL>{MOVENUMBER}           /* no hago nada */
<INITIAL>{DOTS}                 /* no hago nada */
<INITIAL>{MOVE}                 { add_movida( yytext ); }
<INITIAL>\n                     /* no hago nada */

<check_piezas>{WORD}            { count_piezas_add_parameter( yytext ); }
<check_piezas>{NUM}             { check_count_piezas( atol(yytext) ); BEGIN(INITIAL); }

<check_movida>{MOVE}            { chequear_movida_valida( yytext ); }
<check_movida>{NUM}             { chequear_count_movidas( atol(yytext) ); }

<check_result>{WWIN}            { chequear_resultado(1); BEGIN(INITIAL); }
<check_result>{BWIN}            { chequear_resultado(2); BEGIN(INITIAL); }
<check_result>{DRAW}            { chequear_resultado(FINAL_EMPATE); BEGIN(INITIAL); }
<check_result>\*                { chequear_resultado(FINAL_ENJUEGO); BEGIN(INITIAL); }

<verbose_state>{NUM}            { loglevel = atol( yytext ); BEGIN(INITIAL); }

<check_movida,check_result,check_piezas>\n   { BEGIN(INITIAL); }


<*>\#[^\n]*                     /* ignora comentario */


<*>[ \t\r]+                     /* ignore whitespace */
<*><<EOF>>                      { 
                                   if( partida ) qg_partida_free( partida );
                                   yyterminate( );
                                }
<INITIAL>\n                     /* Ignora para inicial */
<*>.                            {
                                  LOGPRINT( 2, "Caracter no esperado '%c' (%d)", yytext[0], yylineno );
                                  exit( EXIT_FAILURE );
                                }

%%


int    nuevo_juego( char* t ){
    if( !tipojuegos ) tipojuegos = list_nueva( NULL );
    tjuego = NULL;
    int i;
    for( i = 0; i < tipojuegos->entradas; i ++ ){
        if( strcmp( t, qg_tipojuego_get_nombre( ((Tipojuego*)tipojuegos->data[i]) ) ) == 0 ){
            tjuego = (Tipojuego*)tipojuegos->data[i];
            break;
        }
    }

    if( !tjuego ){
        clock_t  inicio;
        clock_t  final ;
        char* filename = malloc( strlen( t ) + 25 );
        sprintf( filename, "../../games/%s.qgame", t );
        LOGPRINT( 5, "Voy a abrir %s", filename );
        inicio = clock();
        tjuego = qgz_parse_filename( filename, 0 );
        if( !tjuego ) {
            LOGPRINT( 2, "Error al analizar %s %d", filename, yylineno );
            exit( EXIT_FAILURE );
        }
        final = clock();
        list_agrega( tipojuegos, tjuego );
        free( filename );
        time_scanning += ((double) (final - inicio)) / CLOCKS_PER_SEC;
    }

    if( partida ) qg_partida_free( partida );
    partida = qg_tipojuego_create_partida( tjuego, NULL );
    LOGPRINT( 5, "Partida de %s creada", t );

}


void   add_movida( char* movs ){
    clock_t  inicio;
    clock_t  final ;
    inicio = clock();
    if( !partida ){
        LOGPRINT( 2, "No fue inicializada la partida (%d)", yylineno );
        exit( EXIT_FAILURE );
    }
    LOGPRINT( 5, "Agrega movida %s", movs );
    if( !qg_partida_mover_serie( partida, movs ) ){
        LOGPRINT( 2, "Error al intentar mover %s (%d)", movs, yylineno );
        exit( EXIT_FAILURE ) ;
    }
    final = clock();
    time_moves += ((double) (final - inicio)) / CLOCKS_PER_SEC;
}

void  free_struct(strcheck* str){
    if( str->casillero ) free( str->casillero);
    if( str->tipopieza ) free( str->tipopieza);
    if( str->color     ) free( str->color    );
    if( str->movida    ) free( str->movida   );
    free( str );
}


int   iniciar_chequeo(  ){
    LOGPRINT( 5, "Inicio de chequeo, con  lista = %p", checklist );
    if( checklist ) list_free( checklist );
    checklist = list_nueva( (_list_freefunc)free_struct );
}


void   count_piezas_add_parameter( char* param ){
    strcheck* str = malloc(sizeof( strcheck ) );
    LOGPRINT( 5, "Agrega parametro %s", param );
    memset( str, 0, sizeof( strcheck ) );
    if( qg_tipojuego_get_casillero( tjuego, param ) != NOT_FOUND ){
        str->casillero = strdup( param );
    } else if( qg_tipojuego_get_tipopieza( tjuego, param ) != NOT_FOUND ){
        str->tipopieza = strdup( param );
    } else if( qg_tipojuego_get_color( tjuego, param ) != NOT_FOUND ){
        str->color = strdup( param );
    } else {
        LOGPRINT( 2, "Parametro %s no reconocido (%d)", param, yylineno );
        exit( EXIT_FAILURE );
    }
    list_agrega( checklist, str );
}




void  chequear_resultado(int resultado){
    char* restxt;
    int res = qg_partida_final( partida, &restxt );
    if( res == resultado ) return ;
    LOGPRINT( 2, "Resultado inesperado %d != %d (%s) (%d)", resultado, res, restxt, yylineno );
    exit( EXIT_FAILURE );
}

void  check_count_piezas(int resultado){
    int  contador = 0;
    int  total    = qg_partida_tablero_count( partida );
    int  i;
    for( i = 0; i < total; i ++ ){
        char* casillero, *tipopieza, *color;
        strcheck* strc;
        int       valido = 1;
        qg_partida_tablero_data( partida, i, &casillero, &tipopieza, &color );
        list_inicio( checklist );
        while( strc = list_siguiente( checklist ) ){
            if( strc->color && strcmp( color, strc->color ) != 0 ){
                valido = 0; 
                break;
            }
            if( strc->casillero && strcmp( casillero, strc->casillero ) != 0 ){
                valido = 0; 
                break;
            }
            if( strc->tipopieza && strcmp( tipopieza, strc->tipopieza ) != 0 ){
                valido = 0; 
                break;
            }
        }
        if( valido ) contador ++;
    }
    LOGPRINT( 5, "Comparando resultado %d con %d", contador, resultado );
    if( contador == resultado ) return;
    LOGPRINT( 2, "Resultado inesperado %d != %d en count piezas (%d)", resultado, contador, yylineno );
    exit( EXIT_FAILURE );
}

void   chequear_count_movidas(int movs){
    int  count = qg_partida_movidas_count( partida );
    LOGPRINT( 5, "Comparando cantidad movidas %d con %d", count, movs );
    if( movs != count ){
        LOGPRINT( 2, "Resultado inesperado %d != %d en count movidas (%d)", movs, count, yylineno );
        exit( EXIT_FAILURE );
    }
}

void   chequear_movida_valida(char* mov){
    LOGPRINT( 5, "Verificando movida valida %s", mov );
    if( !qg_partida_movida_valida( partida, mov ) ){
        LOGPRINT( 2, "Movida %s invalida (%d)", mov, yylineno );
        exit( EXIT_FAILURE );
    }
}

void  show_benchmark(){
    printf( "Analisis: %.6f Movidas: %.6f\n", time_scanning, time_moves );
}


int    qgtest_file(FILE* f){
    yyin = f;
    return yylex();
}
