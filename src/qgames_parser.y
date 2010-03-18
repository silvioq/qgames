%{

#include  <stdio.h>
#include  <stdarg.h>
#include  <string.h>
#include  <errno.h>
#include  "qgames.h"
#include  "qgames_analyzer.h"
#include  "qcode.h"

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

Tipojuego*   tipojuego  = NULL;
char*        last_pieza = NULL;
char*        last_tmov  = NULL;


#define  CHECK_TIPOJUEGO   \
    if( !tipojuego ){ yyerror( "gametype no definido aun" ); YYERROR; }
#define  CHECK_LAST_PIEZA   \
    if( !last_pieza ){ yyerror( "pieza no definida" ); YYERROR; }
#define  NOT_IMPLEMENTED   \
    { yyerror( "Funcion no implementada" ); YYERROR; }

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


%token    TOK_ATTR
%token    TOK_BOARD
%token    TOK_COLOR
%token    TOK_DIRECTION
%token    TOK_DROP
%token    TOK_ENDING
%token    TOK_PIECE
%token    TOK_GAMETYPE  
%token    TOK_MOVE
%token    TOK_MOVETYPE
%token    TOK_SYMMETRY
%token    TOK_START
%token    TOK_ZONE

%token    TOK_SEPCODE

%token    TOK_AHOGADO
%token    TOK_EMPATA
%token    TOK_GANA
%token    TOK_JUEGA     TOK_JUEGA_SI
%token    TOK_IF
%token    TOK_OCUPADO
%token    TOK_OCUPADOENEMIGO
%token    TOK_OCUPADOPROPIO
%token    TOK_PARA      TOK_PARA_SI
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
/* A partir de aqui van las instrucciones de acciones por piezas y por final
   de partida */
/* --------------------------------------------------------------------------- */
instexpr_ahogado:
    TOK_AHOGADO { NOT_IMPLEMENTED };

instexpr_ocupado:
    TOK_OCUPADO         {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL );
    } |
    TOK_OCUPADOPROPIO   {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, PROPIO, NULL );
    } |
    TOK_OCUPADOENEMIGO   {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, ENEMIGO, NULL );
    } |
    TOK_OCUPADO  word_or_string {
        char* nombre = (char*)$2;
        CHECK_TIPOJUEGO;
        if( tipojuego_get_casillero( tipojuego, nombre ) != NOT_FOUND ){
             tipojuego_code_ocupado( tipojuego, nombre, CUALQUIERA, NULL );
        } else if( tipojuego_get_color( tipojuego, nombre ) != NOT_FOUND ){
             tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, nombre );
        } else {
            yyerror( "Ocupado?" );
            YYERROR;
        }
    };

instexpr:
    '!' instexpr  |
    '(' instexpr ')' |
    instexpr_ocupado |
    instexpr_ahogado ;

/* --------------------------------------------------------------------------- */
instaction_final:
    TOK_EMPATA {  NOT_IMPLEMENTED; }|
    TOK_GANA   {  NOT_IMPLEMENTED; } |
    TOK_PIERDE {  NOT_IMPLEMENTED; };

instaction_juega:
    TOK_JUEGA   {
        CHECK_TIPOJUEGO;
        tipojuego_code_juega( tipojuego, NULL, 0 );
    }  | 
    TOK_JUEGA_SI   instexpr {
        CHECK_TIPOJUEGO;
        tipojuego_code_start_condblock( tipojuego );
        tipojuego_code_juega( tipojuego, NULL, 0 );
        tipojuego_code_end_condblock( tipojuego );
    };
        
      

instaction_para:
    TOK_PARA   {  NOT_IMPLEMENTED; } |
    TOK_PARA_SI {  NOT_IMPLEMENTED; };

instaction:
    instaction_juega |
    instaction_final |
    instaction_para  |
    TOK_WORD    {  NOT_IMPLEMENTED } ; /* una direccion podria ser */

/* --------------------------------------------------------------------------- */
instcode:
    instaction   /* |
    instaction   TOK_IF  instexpr*/  |
    ;

code_list:
    instcode |
    code_list  TOK_SEPCODE  instcode;







/* --------------------------------------------------------------------------- */
/* A partir de aqui van las instrucciones generales del tipo de juego          */
/* --------------------------------------------------------------------------- */
instruction_attr:
    TOK_ATTR     word_or_string  word_or_string
                   {  CHECK_TIPOJUEGO ;
                      CHECK_LAST_PIEZA;
                      int  def = 0;
                      if( strcasecmp( ((char*)$3), "false" ) == 0 ){
                          def = 0;
                      } else if( strcasecmp( ((char*)$3), "true" ) == 0 ){
                          def = 1;
                      } else {
                          def = atoi( ((char*)$3) );
                      }
                      tipojuego_add_tpieza_att( tipojuego, last_pieza, ((char*)$2), def );
                    }
                 ;



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
    TOK_COLOR      { CHECK_TIPOJUEGO; init_parameters(); }  word_or_string_list
                   { int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                       char* col = ((char*)qgz_param_list[i].par);
                       tipojuego_add_color( tipojuego, col );
                     }
                   }
                   ;

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
    instruction_drop_prelude  TOK_SEPARATOR { 
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, DROP, last_pieza, last_tmov );
    }  code_list;


instruction_move_prelude:
    TOK_MOVE                   { NOT_IMPLEMENTED  } |
    TOK_MOVE   word_or_string  { NOT_IMPLEMENTED  } ;


instruction_move:
    instruction_move_prelude  TOK_SEPARATOR {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, MOVE, last_pieza, last_tmov );
    }  code_list;



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

instruction_movetype:
    TOK_MOVETYPE     word_or_string {
        CHECK_TIPOJUEGO;
        tipojuego_add_tipo_mov( tipojuego, ((char*)$2) );
    }

instruction_piece:
    TOK_PIECE        word_or_string  { 
        CHECK_TIPOJUEGO; 
        tipojuego_add_tipopieza( tipojuego, ((char*)$2) ); 
        if( last_pieza ) free( last_pieza );
        last_pieza = strdup( ((char*)$2) );
    };

instruction_start:
    TOK_START        word_or_string  word_or_string  TOK_NUMBER {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < $4; i ++ ){
          tipojuego_add_pieza( tipojuego, ((char*)$2), CASILLERO_POZO, ((char*)$3) );
        }
    } |
    TOK_START        word_or_string  word_or_string { init_parameters(); } word_or_string_list  {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < qgz_param_count; i ++ ){
          tipojuego_add_pieza( tipojuego, ((char*)$2), (char*)qgz_param_list[i].par, ((char*)$3) );
        }
    } ;

instruction_sym:
    TOK_SYMMETRY     word_or_string  word_or_string  word_or_string { NOT_IMPLEMENTED } ;

instruction_zone:
    TOK_ZONE         word_or_string  word_or_string { init_parameters(); } word_or_string_list { NOT_IMPLEMENTED } ;

instruction:
    instruction_attr       |
    instruction_board      |
    instruction_color      |
    instruction_direction  |
    instruction_drop       |
    instruction_ending     |
    instruction_gametype   |
    instruction_move       |
    instruction_movetype   |
    instruction_piece      |
    instruction_start      |
    instruction_sym        |
    instruction_zone       |
                           ;
    
    


instruction_list:
    instruction  | 
    instruction_list  TOK_SEPARATOR  instruction;


game_definition:
    instruction_list;



%%

/*
 *
 * 
 * 
 */











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



