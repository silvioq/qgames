%{

#include  <stdarg.h>
#include  <errno.h>
#include  "qgames_analyzer.h"

int  qgz_verbose  = 0;
#define YYSTYPE long
#define YYDEBUG 1

extern  int  qgzlineno;
extern FILE* qgzin;


void yyerror(const char *str) { 
    fprintf(stderr,"error: %s (linea: %d)\n",str, qgzlineno); 
}

int qgzwrap() { return 1; } 


void  qgzprintf( char* format, ... ){
  if( !qgz_verbose ) return;
  va_list  a;
  va_start( a, format );
  printf( "%.4d: ", qgzlineno );
  vprintf( format, a );
  printf( "\n" );
  va_end( a );
}


%}

%token    TOK_NUMBER  TOK_WORD   TOK_STRING
%token    TOK_LABEL

%start    game_definition

%%
/*
word_or_string:
         TOK_WORD   { $$ = $1; } | 
         TOK_STRING { $$ = $1; } ;
*/

parameter:
    TOK_NUMBER  |
    TOK_WORD    |
    TOK_STRING  ;

parameter_list:
    parameter   | parameter_list   parameter;


instruction:
    TOK_LABEL   parameter_list;


instruction_list:
    instruction | instruction_list instruction;


game_definition:
    instruction_list;



%%




int   qgz_parse( FILE* f, char* filename, int flags ){

    FILE* ff;

    if( flags & QGZ_VERBOSE ) qgz_verbose = 1; else qgz_verbose = 0;
    if( qgz_verbose ) printf( "En modo verbose!\n" );
#if YYDEBUG==1
    if( flags & QGZ_DEBUG ) yydebug = 1; else yydebug = 0;
    if( qgz_verbose && yydebug ) printf( "En modo debug también (%d)\n", flags );
#endif

    if( f ){
        qgzin = f;
        ff = NULL;
    } else {
        ff = fopen( filename, "r" );
        if( !ff ){
            qgzprintf( "Error %d (%s) al abrir \"%s\"\n", errno, strerror( errno ), filename );
            return  0;
        } else {
            qgzin = ff;
        }
    }

    if( qgzparse() ){
        puts( "Salimos por error!" );
        if( ff ) fclose( ff );
        return 0;
    }
    if( ff ) fclose( ff );
    if( qgz_verbose )printf( "Total analizado: %d lineas\n", qgzlineno );
    return 1;
}
