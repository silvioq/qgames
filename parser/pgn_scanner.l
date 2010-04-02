%{

/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2010.
*/

#include <stdio.h>
#include "defines.h"
#include "pgn_scanner.h"


char* pgntag_event = NULL;
char* pgntag_site = NULL;
char* pgntag_date = NULL;
char* pgntag_round = NULL;
char* pgntag_white = NULL;
char* pgntag_black = NULL;
char* pgntag_result = NULL;
char* pgntag_fen = NULL;

char* pgntag_variant = NULL;

char* pgnmoves = NULL;
int   pgnmvchcount = 0;
int   pgnmvchalloc = 0;

/* -------------------------------------------------------- */
int   pgnlineno;
int   pgncolno;

char* pgnerror = NULL;


char*   extracttag(char*);
void    addmove(char*);

int     pgnwrap(void){ return 1; }

%}

%option batch
%option case-insensitive

TAGDEF       \"[^\"]*\"
SPACES       [ ]+
MOVENUMBER   [0-9]+\.
MOVE         [0-9a-z\-\+\/]+
DOTS         \.{2,3}
WWIN         1\-0
BWIN         0\-1
DRAW         1\/2\-1\/2
RESULT       ({DRAW}|{BWIN}|{WWIN})

%%

\[black{SPACES}{TAGDEF}\]      {  pgntag_black   = extracttag( yytext ); pgncolno += yyleng; }
\[date{SPACES}{TAGDEF}\]       {  pgntag_date    = extracttag( yytext ); pgncolno += yyleng; }
\[event{SPACES}{TAGDEF}\]      {  pgntag_event   = extracttag( yytext ); pgncolno += yyleng; }
\[fen{SPACES}{TAGDEF}\]        {  pgntag_fen     = extracttag( yytext ); pgncolno += yyleng; }
\[result{SPACES}{TAGDEF}\]     {  pgntag_result  = extracttag( yytext ); pgncolno += yyleng; }
\[round{SPACES}{TAGDEF}\]      {  pgntag_round   = extracttag( yytext ); pgncolno += yyleng; }
\[site{SPACES}{TAGDEF}\]       {  pgntag_site    = extracttag( yytext ); pgncolno += yyleng; }
\[variant{SPACES}{TAGDEF}\]    {  pgntag_variant = extracttag( yytext ); pgncolno += yyleng; }
\[white{SPACES}{TAGDEF}\]      {  pgntag_white   = extracttag( yytext ); pgncolno += yyleng; }
\[[a-z]+{SPACES}{TAGDEF}\]     {  printf( "Tag no reconocido en %d\n", pgnlineno );  pgncolno += yyleng ; }

{MOVENUMBER}                     { /* Por ahora ignoro los numeros de movidas */ pgncolno += yyleng; }
{RESULT}                         pgncolno += yyleng;
{MOVE}                           addmove( yytext ); pgncolno += yyleng ;
{DOTS}                           pgncolno += yyleng ;

[ \t\r]+                       { /* ignore whitespace */ pgncolno += yyleng ; }
\{[^\}]*\}                     /* ignore comments */ pgncolno += yyleng;
;[^\n]*\n                      /* ignore comments */ pgncolno += yyleng;

\n                             { pgncolno = 1; pgnlineno ++; }


.                              {
                                  pgnerror = ALLOC( 256 );
                                  sprintf( pgnerror, "Caracter no reconocido (%c) Linea: %d, Col: %d", yytext[0], pgnlineno, pgncolno );
                                  yyterminate();
                               };

%%

char*  extracttag(char* line){
    char*  initquote = strchr( line, '"' );
    initquote ++;
    char*  endquote = strchr( initquote, '"' );
    endquote --;

    int  len = endquote - initquote + 1;
    char* ret = ALLOC( len + 1 );
    strncpy( ret, initquote, len );
    ret[len] = 0;
    return ret;
}

void    addmove(char* move){
    if( !pgnmoves ){ 
        pgnmoves = ALLOC( 32 ); 
        pgnmoves[0] = 0;
        pgnmvchcount = 0;
        pgnmvchalloc = 32;
     }
    int  len = strlen( move );
    if( pgnmvchcount + len + 1 >= pgnmvchalloc ){
        pgnmvchalloc += len + 32;
        pgnmoves = REALLOC( pgnmoves, pgnmvchalloc );
    }

    if( pgnmvchcount ){ 
        strcat( pgnmoves + pgnmvchcount, " " ); 
        len ++; 
    }
    strcat( pgnmoves + pgnmvchcount, move );
    pgnmvchcount += len;
}




#define  FREEVARIABLE(var) if( var ){ free( var ); var = NULL; }

void   freepgn( ){

    FREEVARIABLE( pgntag_event )
    FREEVARIABLE( pgntag_site )
    FREEVARIABLE( pgntag_date )
    FREEVARIABLE( pgntag_round )
    FREEVARIABLE( pgntag_white )
    FREEVARIABLE( pgntag_black )
    FREEVARIABLE( pgntag_result )
    FREEVARIABLE( pgntag_fen )
    FREEVARIABLE( pgntag_variant )
    FREEVARIABLE( pgnmoves )
    FREEVARIABLE( pgnerror )
    pgnmvchcount = 0;
    pgnmvchalloc = 0;
}


void   initpgn( ){
    freepgn( );
    pgnlineno = 1;
    pgncolno  = 0;
}

int   pgnscan(char* scan){
    initpgn();
    YY_BUFFER_STATE buf = yy_scan_string( scan );
    yy_switch_to_buffer( buf );
    int ret = yylex();
    return pgnerror ? 0 : 1;
}

