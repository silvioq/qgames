%{
/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2010.
*/

#include  <stdio.h>
#include  <stdlib.h>

#include  "config.h"
#include  <qgames.h>
#include  <qgames_analyzer.h>
#include  "list.h"
#include  "log.h"

int    nuevo_juego( char* );
void   add_movida( char* );

int    inciar_chequeo( int );
void   count_piezas_add_parameter( char* );
int    chequear();
void   chequear_resultado(int);
void   check_count_piezas(int);
void   chequear_count_movidas(int);
void   chequear_movida_valida(char*);

Partida*  partida    = NULL;
Tipojuego* tjuego    = NULL;
_list*    tipojuegos = NULL;
_list*    checklist  = NULL;

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
%x      movidas check_movida  check_result check_piezas  nombre_juego

SPACES       [ ]+
BAR          (\_|\-)?
NUM          [0-9]+
WORD         ([a-zA-Z\?][a-zA-Z0-9\-\_]*\??)
MOVENUMBER   [0-9]+\.
MOVE         [a-z][0-9a-z\-\+\#\/\=]+
WWIN         1\-0
BWIN         0\-1
DRAW         1\/2\-1\/2
RESULT       ({DRAW}|{BWIN}|{WWIN}|\*)

%%

<INITIAL>mueve                  { BEGIN(movidas);      }
<INITIAL>nuevo{BAR}juego        { BEGIN(nombre_juego); }
<INITIAL>check{BAR}piezas       { iniciar_chequeo( ); BEGIN(check_piezas); }
<INITIAL>check{BAR}movidas?     { BEGIN(check_movida); }  
<INITIAL>check{BAR}result       { BEGIN(check_result); }  

<nombre_juego>{WORD}            { nuevo_juego( yytext ); BEGIN(INITIAL); }

<movidas>{MOVENUMBER}           /* no hago nada */
<movidas>(nuevo.*)|(check.*)|(mueve)    { yyless( 0 ); BEGIN(INITIAL); }
<movidas>{MOVE}                 { add_movida( yytext ); }
<movidas>\n                     /* no hago nada */

<check_piezas>{WORD}            { count_piezas_add_parameter( yytext ); }
<check_piezas>{NUM}             { check_count_piezas( atol(yytext) ); BEGIN(INITIAL); }

<check_movida>{MOVE}            { chequear_movida_valida( yytext ); }
<check_movida>{NUM}             { chequear_count_movidas( atol(yytext) ); }

<check_result>{WWIN}            { chequear_resultado(1); BEGIN(INITIAL); }
<check_result>{BWIN}            { chequear_resultado(2); BEGIN(INITIAL); }
<check_result>{DRAW}            { chequear_resultado(FINAL_EMPATE); BEGIN(INITIAL); }
<check_result>\*                { chequear_resultado(FINAL_ENJUEGO); BEGIN(INITIAL); }

<check_movida,check_result,check_piezas>\n   { BEGIN(INITIAL); }

<*>{RESULT}                     { yyless( 0 ); BEGIN(check_result); }

<*>\#[^\n]*                     /* ignora comentario */


<*>[ \t\r]+                     /* ignore whitespace */
<*><<EOF>>                      { 
                                  LOGPRINT( 5, "Terminando file %d por EOF", yyin );
                                   yyterminate( );
                                }
<INITIAL>\n                     /* Ignora para inicial */
<*>.                            {
                                  LOGPRINT( 2, "Caracter no esperado %d (%d)", yytext[0], yylineno );
                                  exit( EXIT_FAILURE );
                                }

%%


int    nuevo_juego( char* t ){
    if( !tipojuegos ) tipojuegos = list_nueva( NULL );
    tjuego = NULL;
    int i;
    for( i = 0; i < tipojuegos->entradas; i ++ ){
        if( strcmp( t, tipojuego_get_nombre( ((Tipojuego*)tipojuegos->data[i]) ) ) == 0 ){
            tjuego = (Tipojuego*)tipojuegos->data[i];
            break;
        }
    }

    if( !tjuego ){
        char* filename = ALLOC( strlen( t ) + 25 );
        sprintf( filename, "../games/%s.qgame", t );
        LOGPRINT( 5, "Voy a abrir %s", filename );
        tjuego = qgz_parse_filename( filename, 0 );
        if( !tjuego ) {
            LOGPRINT( 2, "Error al analizar %s %d", filename, yylineno );
            exit( EXIT_FAILURE );
        }
        list_agrega( tipojuegos, tjuego );
        FREE( filename );
    }

    if( partida ) partida_free( partida );
    partida = tipojuego_create_partida( tjuego, NULL );
    LOGPRINT( 5, "Partida de %s creada", t );

}


void   add_movida( char* movs ){
    if( !partida ){
        LOGPRINT( 2, "No fue inicializada la partida (%d)", yylineno );
        exit( EXIT_FAILURE );
    }
    if( !partida_mover_notacion( partida, movs ) ){
        LOGPRINT( 2, "Error al intentar mover %s (%d)", movs, yylineno );
        exit( EXIT_FAILURE ) ;
    }
    LOGPRINT( 5, "Agrega movida %s", movs );
}

void  free_struct(strcheck* str){
    if( str->casillero ) FREE( str->casillero);
    if( str->tipopieza ) FREE( str->tipopieza);
    if( str->color     ) FREE( str->color    );
    if( str->movida    ) FREE( str->movida   );
    FREE( str );
}


int   iniciar_chequeo(  ){
    LOGPRINT( 5, "Inicio de chequeo, con  lista = %p", checklist );
    if( checklist ) list_free( checklist );
    checklist = list_nueva( (_list_freefunc)free_struct );
}


void   count_piezas_add_parameter( char* param ){
    strcheck* str = ALLOC(sizeof( strcheck ) );
    LOGPRINT( 5, "Agrega parametro %s", param );
    memset( str, 0, sizeof( strcheck ) );
    if( tipojuego_get_casillero( tjuego, param ) != NOT_FOUND ){
        str->casillero = STRDUP( param );
    } else if( tipojuego_get_tipopieza( tjuego, param ) != NOT_FOUND ){
        str->tipopieza = STRDUP( param );
    } else if( tipojuego_get_color( tjuego, param ) != NOT_FOUND ){
        str->color = STRDUP( param );
    } else {
        LOGPRINT( 2, "Parametro %s no reconocido (%d)", param, yylineno );
        exit( EXIT_FAILURE );
    }
    list_agrega( checklist, str );
}




void  chequear_resultado(int resultado){
    char* restxt;
    int res = partida_final( partida, &restxt );
    if( res == resultado ) return ;
    LOGPRINT( 3, "Resultado inesperado %d != %d (%s) (%d)", resultado, res, restxt, yylineno );
    exit( EXIT_FAILURE );
}

void  check_count_piezas(int resultado){
    int  contador = 0;
    int  total    = partida_tablero_count( partida );
    int  i;
    for( i = 0; i < total; i ++ ){
        char* casillero, *tipopieza, *color;
        strcheck* strc;
        int       valido = 1;
        partida_tablero_data( partida, i, &casillero, &tipopieza, &color );
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
    LOGPRINT( 3, "Resultado inesperado %d != %d en count piezas (%d)", resultado, contador, yylineno );
    exit( EXIT_FAILURE );
}

void   chequear_count_movidas(int movs){
    int  count = partida_movidas_count( partida );
    LOGPRINT( 5, "Comparando cantidad movidas %d con %d", count, movs );
    if( movs != count ){
        LOGPRINT( 3, "Resultado inesperado %d != %d en count movidas (%d)", movs, count, yylineno );
        exit( EXIT_FAILURE );
    }
}

void   chequear_movida_valida(char* mov){
    LOGPRINT( 5, "Verificando movida valida %s", mov );
    if( !partida_movida_valida( partida, mov ) ){
        LOGPRINT( 3, "Movida %s invalida (%d)", mov, yylineno );
        exit( EXIT_FAILURE );
    }
}


int    qgtest_file(FILE* f){
    yyin = f;
    return yylex();
}
