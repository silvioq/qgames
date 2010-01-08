%{

#include  <stdio.h>
#include  <stdarg.h>
#include  <string.h>
#include  <errno.h>
#include  "qgames.h"
#include  "qgames_analyzer.h"

int    qgz_verbose  = 0;
str_param*  qgz_param_list  = NULL;
int    qgz_param_count = 0;
void  add_parameter( int  type, long param );
void  init_parameters( );

#define  MAX_PARAMS   32

#define YYSTYPE long
#define YYDEBUG 1

extern  int  qgzlineno;
extern FILE* qgzin;

Tipojuego*   tipojuego;
#define  CHECK_TIPOJUEGO   \
    if( !tipojuego ){ yyerror( "gametype no definido aun" ); YYERROR; }

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

%token    TOK_NUMBER  TOK_WORD        TOK_STRING
%token    TOK_SEPARATOR


%token    TOK_BOARD
%token    TOK_COLOR
%token    TOK_DIRECTION
%token    TOK_DROP
%token    TOK_ENDING
%token    TOK_PIECE
%token    TOK_GAMETYPE  
%token    TOK_START

%token    TOK_SEPCODE

%token    TOK_AHOGADO
%token    TOK_EMPATA
%token    TOK_GANA
%token    TOK_JUEGA
%token    TOK_IF
%token    TOK_OCUPADO
%token    TOK_OCUPADOPROPIO
%token    TOK_PARA
%token    TOK_PIERDE


%start    game_definition

%%
word_or_string:
         TOK_WORD   { $$ = $1; } | 
         TOK_STRING { $$ = $1; } ;


word_or_string_list:
        word_or_string                      { add_parameter( TOK_STRING, $1 ); }    |  
        word_or_string_list  word_or_string { add_parameter( TOK_STRING, $2 ); }    ;

number_list:
        TOK_NUMBER                         { add_parameter( TOK_NUMBER, $1 ); } |   
        number_list  TOK_NUMBER            { add_parameter( TOK_NUMBER, $2 ); };

/* --------------------------------------------------------------------------- */
instexpr_ahogado:
    TOK_AHOGADO;

instexpr_ocupado:
    TOK_OCUPADO         |
    TOK_OCUPADOPROPIO   |
    TOK_OCUPADO  word_or_string ;

instexpr:
    '!' instexpr  |
    '(' instexpr ')' |
    instexpr_ocupado |
    instexpr_ahogado ;

/* --------------------------------------------------------------------------- */
instaction_final:
    TOK_EMPATA |
    TOK_GANA   |
    TOK_PIERDE ;

instaction_juega:
    TOK_JUEGA   ;

instaction_para:
    TOK_PARA   ;

instaction:
    instaction_juega |
    instaction_final |
    instaction_para  |
    TOK_WORD    ; /* una direccion podria ser */

/* --------------------------------------------------------------------------- */
instcode:
    instaction   |
    instaction   TOK_IF  instexpr |
    ;

code_list:
    instcode |
    code_list  TOK_SEPCODE  instcode;

/* --------------------------------------------------------------------------- */




instruction_board:
    TOK_BOARD      { CHECK_TIPOJUEGO; 
                     init_parameters(); }  
    word_or_string_list
                   {
                     char*  dims[MAX_PARAMS]; int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                        dims[i] = ((char*)qgz_param_list[i].par);
                      }
                     tipojuego_genera_dimensiones( tipojuego, qgz_param_count, dims );
                   };

instruction_color:
    TOK_COLOR      { init_parameters(); }  word_or_string_list;

instruction_direction:
    TOK_DIRECTION    word_or_string { CHECK_TIPOJUEGO; init_parameters(); } number_list 
                    {
                      int  dirs[MAX_PARAMS]; int i; 
                      tipojuego_add_direccion( tipojuego, ((char*)$2) );
                      for( i = 0; i < qgz_param_count; i ++ ){
                          dirs[i] = qgz_param_list[i].par;
                      }
                      tipojuego_add_direccion_arr( tipojuego, ((char*)$2), dirs );
                    };

instruction_drop_prelude:
    TOK_DROP   |
    TOK_DROP   word_or_string  |
    TOK_DROP   word_or_string  word_or_string  ;

instruction_drop:
    instruction_drop_prelude  TOK_SEPARATOR { change_to_code_mode(); }  code_list;

instruction_ending:
    TOK_ENDING  TOK_SEPARATOR  { change_to_code_mode(); }  code_list;

instruction_gametype:
    TOK_GAMETYPE     word_or_string { 
        if( tipojuego ){
            yyerror( "Ya fue definido el tipo juego" );
            YYERROR;
        } else {
            tipojuego = tipojuego_new( ((char*)$2) );
        }
    };

instruction_piece:
    TOK_PIECE        word_or_string  { CHECK_TIPOJUEGO; tipojuego_add_tipopieza( tipojuego, ((char*)$2) ); };

instruction_start:
    TOK_START        word_or_string  word_or_string  TOK_NUMBER  |
    TOK_START        word_or_string  word_or_string { init_parameters(); } word_or_string_list ;

instruction:
    instruction_board      |
    instruction_color      |
    instruction_direction  |
    instruction_drop       |
    instruction_ending     |
    instruction_gametype   |
    instruction_piece      |
    instruction_start      |
                           ;
    
    


instruction_list:
    instruction  | 
    instruction_list  TOK_SEPARATOR  instruction;


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
            char* xx = strerror( errno );
            qgzprintf( "Error %d (%s) al abrir \"%s\"\n", errno, xx, filename );
            return  0;
        } else {
            qgzin = ff;
        }
    }

    tipojuego = NULL;

    if( qgzparse() ){
        puts( "Salimos por error!" );
        if( ff ) fclose( ff );
        return 0;
    }
    if( ff ) fclose( ff );
    if( qgz_verbose )printf( "Total analizado: %d lineas\n", qgzlineno );
    return 1;
}




/*
 * Agrega un parametro
 * */
void  add_parameter( int  type, long param ){
  if( !qgz_param_list ){
    qgz_param_list = ALLOC( sizeof( str_param  ) * MAX_PARAMS );
  }
  if( qgz_param_count + 1 >= MAX_PARAMS ) {
      yyerror( "Cantidad maxima de parametros alcanzado" );
      return;
  }
  switch( type ){
      case TOK_NUMBER:
          qgzprintf( "Parametro N: %d", param );
          break;
      case TOK_STRING:
          qgzprintf( "Parametro C: %s", ((char*)param) );
          break;
      default:
          yyerror( "Tipo parametro incorrecto" );
          return;
  }
  qgz_param_list[qgz_param_count].par = param;
  qgz_param_list[qgz_param_count].typ = type;
  qgz_param_count ++;
}

void  init_parameters(){ qgz_param_count = 0; }



