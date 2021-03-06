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
#include  <stdarg.h>
#include  <string.h>
#include  <stdlib.h>
#include  <errno.h>
#include  <qgames.h>
#include  <qgames_analyzer.h>
#include  "qgames_code_impl.h"



typedef  struct StrParam {
  int   typ;
  union {
      long  par;
      char* str;
 };
} str_param;


static  int    qgz_verbose  = 0;

static  str_param*  qgz_param_list  = NULL;
static  int    qgz_param_count = 0;
static  void  add_parameter( int  type, long param );
static  void  init_parameters( );

#define  MAX_PARAMS   32

#define YYSTYPE long
#define YYDEBUG 1

extern  int  qgzlineno;
extern FILE* qgzin;

static  Tipojuego*   tipojuego  = NULL;
static  char*        last_pieza = NULL;
static  long         last_block = 0;
static  long         html_color1, html_color2;
static  long         graph_dim1, graph_dim2;

const  char*  defname_actual( );

#define  CHECK_TIPOJUEGO   \
    if( !tipojuego ){ yyerror( "gametype no definido aun" ); YYERROR; }\
    if( !qg_tipojuego_valido( tipojuego ) ){ yyerror( "tipojuego no es valido" ); YYERROR; }
#define  CHECK_LAST_PIEZA   \
    if( !last_pieza ){ yyerror( "pieza no definida" ); YYERROR; }

#define  NOT_IMPLEMENTED   \
    { yyerror( "Funcion no implementada" ); YYERROR; }

#define  NOT_IMPLEMENTED_WARN(f) \
    { yyerror( "Aviso: funcion " f " no implementada" ); }

void yyerror(const char *str) { 
    const char  * define = defname_actual(  );
    if( define ){ 
        fprintf(stderr,"error: %s (linea: %d - %s)\n",str, qgzlineno, define); 
    } else {
        fprintf(stderr,"error: %s (linea: %d)\n",str, qgzlineno); 
    }
}

int qgzwrap() { return 1; } 


void  qgzprintf( char* format, ... ){
  if( !qgz_verbose ) return;
  va_list  a;
  const char* define;
  va_start( a, format );
  printf( "%.4d", qgzlineno );
  define = defname_actual( );
  if( define ) printf( "(%s)", define );
  printf( " :" );
  vprintf( format, a );
  printf( "\n" );
  va_end( a );
}


%}

%token    TOK_NUMBER  TOK_WORD        TOK_STRING
%token    TOK_HTMLCOLOR
%token    TOK_SEPARATOR


%token    TOK_ATTR
%token    TOK_BOARD
%token    TOK_CAPTURED_MARK
%token    TOK_CANTIDAD_PIEZAS   TOK_CANTIDAD_PIEZAS_PROPIAS  TOK_CANTIDAD_PIEZAS_ENEMIGAS
%token    TOK_COLOR
%token    TOK_CREA
%token    TOK_DEFAULT
%token    TOK_DIRECTION
%token    TOK_DROP
%token    TOK_ENDING
%token    TOK_GAMETYPE  
%token    TOK_LOGO
%token    TOK_MARK
%token    TOK_MOVE
%token    TOK_MOVETYPE   TOK_PRIORITY
%token    TOK_NOTATION
%token    TOK_ONREPEAT
%token    TOK_ORIGIN
%token    TOK_PIECE
%token    TOK_PIECE_NAME
%token    TOK_REPEAT
%token    TOK_SEQUENCE
%token    TOK_START
%token    TOK_SYMMETRY
%token    TOK_TARGET
%token    TOK_ZONE

%token    TOK_SEPCODE

%token    TOK_AHOGADO
%token    TOK_ASIGNA_ATT
%token    TOK_ATACADO_ENEMIGO
%token    TOK_CAMBIA_COLOR
%token    TOK_CAPTURA        TOK_CAPTURA_SI        TOK_CAPTURA_Y_JUEGA   TOK_CAPTURA_Y_JUEGA_SI
%token    TOK_CAPTURADAS     TOK_CAPTURADAS_ENEMIGO   TOK_CAPTURADAS_PROPIO
%token    TOK_CASILLERO_INICIAL
%token    TOK_DESTINO_ANT
%token    TOK_EMPATA    TOK_EMPATA_SI
%token    TOK_ENTABLERO
%token    TOK_ENZONA   
%token    TOK_GANA      TOK_GANA_SI
%token    TOK_JAQUEMATE
%token    TOK_JUEGA     TOK_JUEGA_SI
%token    TOK_GOTO_MARCA  TOK_MARCA
%token    TOK_MUEVE     TOK_MUEVE_SI
%token    TOK_CONTINUA  TOK_CONTINUA_SI
%token    TOK_IF
%token    TOK_OCUPADO
%token    TOK_OCUPADO_ENEMIGO
%token    TOK_OCUPADO_PROPIO
%token    TOK_ORIGEN_ANT
%token    TOK_PARA      TOK_PARA_SI
%token    TOK_PIERDE    TOK_PIERDE_SI
%token    TOK_PIEZAS_EN_CAS
%token    TOK_TRANSFORMA
%token    TOK_REPITEPOS

%token    TOK_AND       TOK_OR          TOK_NOT
%token    TOK_EQUAL     TOK_DEQUAL
%token    TOK_WHILE     TOK_DO   TOK_END  TOK_BREAK

%token    TOK_GRAPH_BOARD
%token    TOK_GRAPH_PIECE
%token    TOK_GRAPH_SQUARE
%token    TOK_GRID
%token    TOK_CHECKERBOARD
%token    TOK_INTERSECTIONS
%token    TOK_HIGHLIGHTED

%token    TOK_STANDARD_GEM
%token    TOK_STANDARD_BISHOP
%token    TOK_STANDARD_KING
%token    TOK_STANDARD_KNIGHT
%token    TOK_STANDARD_PAWN
%token    TOK_STANDARD_QUEEN
%token    TOK_STANDARD_RECT
%token    TOK_STANDARD_ROOK
%token    TOK_STANDARD_CHECKERS_PAWN
%token    TOK_STANDARD_CHECKERS_KING


%start    game_definition

%%
word_or_string:
         TOK_WORD   { $$ = $1; } | 
         TOK_STRING { $$ = $1; } ;


word_or_string_list:
        word_or_string                      { add_parameter( TOK_STRING, $1 ); }    |  
        word_or_string_list  word_or_string { add_parameter( TOK_STRING, $2 ); }    |
        word_or_string_list ','  word_or_string { add_parameter( TOK_STRING, $3 ); }    ;

number_list:
        TOK_NUMBER                         { add_parameter( TOK_NUMBER, $1 ); } |   
        number_list  TOK_NUMBER            { add_parameter( TOK_NUMBER, $2 ); };

/* --------------------------------------------------------------------------- */
/* A partir de aqui van las instrucciones de acciones por piezas y por final
   de partida */
/* --------------------------------------------------------------------------- */
instexpr_ahogado:
    TOK_AHOGADO { 
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_ahogado( tipojuego, NULL ) ) YYERROR;
    } | 
    TOK_AHOGADO  word_or_string {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_ahogado( tipojuego, (char*)$2 ) ) YYERROR;
            free(  (char*)$2 );
    };

instexpr_atacado:
    TOK_ATACADO_ENEMIGO {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_atacado( tipojuego, NULL ) ) YYERROR;
    };

cantidad_piezas_preludio:
    TOK_CANTIDAD_PIEZAS  {
            CHECK_TIPOJUEGO;
            $$ = CUALQUIERA;
            init_parameters(); 
    } | 
    TOK_CANTIDAD_PIEZAS_PROPIAS  { 
            CHECK_TIPOJUEGO;
            $$ = PROPIO;
            init_parameters(); 
    } |
    TOK_CANTIDAD_PIEZAS_ENEMIGAS  { 
            CHECK_TIPOJUEGO;
            $$ = ENEMIGO;
            init_parameters(); 
    } ;
    


instexpr_cantidad_piezas:
    cantidad_piezas_preludio  word_or_string_list  { 
            int i;
            char* cas = NULL; char* color = NULL; char *tpieza = NULL;
            for( i = 0; i < qgz_param_count; i ++ ){
                if( NOT_FOUND != qg_tipojuego_get_color( tipojuego, qgz_param_list[i].str ) ){
                    if( color ){ yyerror( "Color definido mas de una vez en cuentapiezas" ); YYERROR; }
                    color = qgz_param_list[i].str ;
                } else if( NOT_FOUND != qg_tipojuego_get_casillero( tipojuego,  qgz_param_list[i].str ) ){
                    if( cas ) { yyerror( "Casillero definido mas de una vez en cuentapiezas" ); YYERROR; }
                    cas = qgz_param_list[i].str ;
                } else if( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, qgz_param_list[i].str ) ){
                    if( tpieza ){ yyerror( "Tipo de pieza definida mas de una vez en cuentapiezas" ); YYERROR; }
                    tpieza = qgz_param_list[i].str;
                } else {
                    qgzprintf( "Elemento no reconocido %s", qgz_param_list[i].str );
                    yyerror( "Elemento no reconocido en cuentapiezas" ); YYERROR;
                }
            }
            if( !tipojuego_code_cuenta_piezas( tipojuego, cas, $1, color, tpieza ) ) YYERROR;
    } |
    cantidad_piezas_preludio  TOK_NUMBER  {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, NULL, $1, NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, $2 );
    } |
    cantidad_piezas_preludio  {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, NULL, $1, NULL, NULL ) ) YYERROR;;
    } |
    TOK_CAPTURADAS_ENEMIGO {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, ENEMIGO, NULL, NULL ) ) YYERROR;;
    } |
    TOK_CAPTURADAS_ENEMIGO  TOK_NUMBER {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, ENEMIGO, NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, $2 );
    } |
    TOK_CAPTURADAS_PROPIO {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, PROPIO, NULL, NULL ) ) YYERROR;;
    } |
    TOK_CAPTURADAS_PROPIO  TOK_NUMBER {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, PROPIO, NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, $2 );
    } |
    TOK_CAPTURADAS {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, NOCOLOR, NULL, NULL ) ) YYERROR;;
    }
    TOK_CAPTURADAS  TOK_NUMBER {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, NOCOLOR, NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, $2 );
    }
    cantidad_piezas_preludio                       { 
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, NULL, $1, NULL, NULL ) ) YYERROR;;
    } ;


instexpr_movidas_anteriores:
    TOK_DESTINO_ANT    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_destino_ant( tipojuego, NULL ) ) YYERROR;
    } |
    TOK_DESTINO_ANT   word_or_string  {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != qg_tipojuego_get_casillero( tipojuego, ((char*)$2) ) ){
                if( !tipojuego_code_destino_ant( tipojuego, ((char*)$2) ) ) YYERROR;
            } else {
                qgzprintf( "Debe ser un casillero %s", ((char*)$2) );
                yyerror( "Debe ser un casillero");
                YYERROR;
            }
            free( (char*)$2 );
    } |
    TOK_ORIGEN_ANT    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_origen_ant( tipojuego, NULL ) ) YYERROR;
    } |
    TOK_ORIGEN_ANT   word_or_string  {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != qg_tipojuego_get_casillero( tipojuego, ((char*)$2) ) ){
                if( !tipojuego_code_origen_ant( tipojuego, ((char*)$2) ) ) YYERROR;
            } else {
                qgzprintf( "Debe ser un casillero %s", ((char*)$2) );
                yyerror( "Debe ser un casillero");
                YYERROR;
            }
            free( (char*)$2 );
    };
                

    

instexpr_entablero:
    TOK_ENTABLERO {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_entablero( tipojuego ) ) YYERROR;
    };

instexpr_enzona:
    TOK_ENZONA   word_or_string   word_or_string {  
            CHECK_TIPOJUEGO;
            char*  zona = NULL;
            char*  tpieza = NULL;
            if( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, ((char*)$2) ) ){
                tpieza = ((char*)$2);
            } else if( NOT_FOUND != qg_tipojuego_get_zona( tipojuego, ((char*)$2) ) ) {
                zona  = ((char*)$2);
            } else {
                qgzprintf( "%s debe ser un tipo de pieza o una zona", ((char*)$2 ) );
                yyerror( "Instruccion enzona mal formada" );
            }

            if( tpieza && ( NOT_FOUND != qg_tipojuego_get_zona( tipojuego, ((char*)$3)  ) ) ){
                zona  = ((char*)$3);
            } 
            if( zona && ( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, ((char*)$3) ) ) ){
                tpieza = ((char*)$3);
            }
            if( !zona || !tpieza ){
                yyerror( "Instruccion enzona mal formada" );
            }
            if( !tipojuego_code_enzona( tipojuego, zona, tpieza ) ) YYERROR;
            free( (char*) $2 );
            free( (char*) $3 );
    } |
    TOK_ENZONA   word_or_string {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != qg_tipojuego_get_zona( tipojuego, ((char*)$2) ) ) {
                if( !tipojuego_code_enzona( tipojuego, (char*)$2, NULL ) ) YYERROR;
            } else { 
                qgzprintf( "%s debe ser una zona", ((char*)$2 ) );
                yyerror( "Instruccion enzona mal formada" );
            }
            free( (char*) $2 );
    } ; 

instexpr_jaquemate:
    TOK_JAQUEMATE  word_or_string {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, ((char*)$2) ) ){
                if( !tipojuego_code_jaquemate( tipojuego, ((char*)$2) ) ) YYERROR;
            } else {
                qgzprintf( "%s debe ser un tipo de pieza", ((char*)$2) );
                yyerror( "Debe ser un tipo de pieza" );
            }
            free( (void*)$2 );
    };


instexpr_ocupado:
    TOK_OCUPADO         {
        CHECK_TIPOJUEGO;
        if( !tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL, NULL ) ) YYERROR;
    } |
    TOK_OCUPADO_PROPIO   {
        CHECK_TIPOJUEGO;
        if( !tipojuego_code_ocupado( tipojuego, NULL, PROPIO, NULL, NULL ) ) YYERROR;
    } |
    TOK_OCUPADO_ENEMIGO   {
        CHECK_TIPOJUEGO;
        if( !tipojuego_code_ocupado( tipojuego, NULL, ENEMIGO, NULL, NULL ) ) YYERROR;
    } |
    TOK_OCUPADO  word_or_string {
        char* nombre = (char*)$2;
        CHECK_TIPOJUEGO;
        if( qg_tipojuego_get_casillero( tipojuego, nombre ) != NOT_FOUND ){
             if( !tipojuego_code_ocupado( tipojuego, nombre, CUALQUIERA, NULL, NULL ) ) YYERROR;
        } else if( qg_tipojuego_get_color( tipojuego, nombre ) != NOT_FOUND ){
             if( !tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, nombre, NULL ) ) YYERROR;
        } else if( qg_tipojuego_get_tipopieza( tipojuego, nombre ) != NOT_FOUND ){
             if( !tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL, nombre ) ) YYERROR;
        } else {
            yyerror( "Ocupado?" );
            YYERROR;
        }
        free( (void*)$2 );
    };


instexpr_repitepos:
    TOK_REPITEPOS   TOK_NUMBER  {
        CHECK_TIPOJUEGO;
        tipojuego_code_op_false( tipojuego );
        tipojuego_code_repeticion( tipojuego, $2 );
    }  



es_igual_a:  TOK_EQUAL | TOK_DEQUAL;

instexpr_logical:
    TOK_NOT   instexpr    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_not( tipojuego );
    } |
    instexpr TOK_AND    {
                CHECK_TIPOJUEGO;
                tipojuego_code_start_condblock( tipojuego );
    } instexpr  { 
                tipojuego_code_end_condblock( tipojuego );
    } |
    instexpr TOK_OR  instexpr  { NOT_IMPLEMENTED; } 
      |
    instexpr es_igual_a  TOK_NUMBER {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, $3 );
    } | 
    TOK_NUMBER es_igual_a  instexpr {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, $1 );
    }   
    ;

instexpr:
    '(' instexpr ')' |
    instexpr_logical |
    instexpr_ahogado |
    instexpr_atacado |
    instexpr_cantidad_piezas |
    instexpr_movidas_anteriores |
    instexpr_entablero |
    instexpr_enzona  |
    instexpr_jaquemate |
    instexpr_ocupado |
    instexpr_repitepos |
    TOK_WORD        {    
            CHECK_TIPOJUEGO;
            /* una direccion podria ser */
            if( qg_tipojuego_get_direccion( tipojuego, (char*)$1 ) != NOT_FOUND ){
                    qgzprintf( "Direccion %s no esperada", (char*)$1 );
                    yyerror( "Direccion no esperada" );
                    YYERROR;
            } else {
                if( qg_tipojuego_get_casillero( tipojuego, (char*)$1 ) != NOT_FOUND ){
                    qgzprintf( "Casillero %s no esperado", (char*)$1 );
                    yyerror( "Casillero no esperado" );
                    YYERROR;
                } else if( qg_tipojuego_get_att( tipojuego, last_pieza, (char*)$1 ) != NOT_FOUND ) {
                      if( !tipojuego_code_evalua_att( tipojuego, (char*)$1 ) ) YYERROR;
                } else {
                   int  len = strlen( (char*)$1 );
                   int  hay_algo = 0;
                   if( len > 0 && ((char*)($1))[len-1] == '?' ){
                      char* sin_pregunta = strdup( (char*) $1 );
                      sin_pregunta[len-1] = 0;
                      if( qg_tipojuego_get_att( tipojuego, last_pieza, sin_pregunta ) != NOT_FOUND ){
                          hay_algo = 1;
                          if( !tipojuego_code_evalua_att( tipojuego, sin_pregunta ) ) YYERROR;
                      }
                      free(sin_pregunta);
                  }

                  if( !hay_algo ){
                    qgzprintf( "%s no es nada", (char*)$1 );
                    yyerror( "Comando no reconocido" );
                    YYERROR;
                  }
                }
                free( (char*)$1 );
            }
    };

/* --------------------------------------------------------------------------- */
instaction_final:
    TOK_EMPATA    {  
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_final( tipojuego, NULL, EMPATA ) ) YYERROR;
    } |
    TOK_EMPATA_SI instexpr {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_final( tipojuego, NULL, EMPATA ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    } |
    TOK_GANA      {  
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_final( tipojuego, NULL, GANA ) ) YYERROR;
    } |
    TOK_GANA_SI   instexpr  {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_final( tipojuego, NULL, GANA ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    } |
    TOK_PIERDE    {  
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_final( tipojuego, NULL, PIERDE ) ) YYERROR;
    } |
    TOK_PIERDE_SI   instexpr  {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_final( tipojuego, NULL, PIERDE ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
     } ;

  

instaction_movs:
    TOK_CASILLERO_INICIAL { 
            CHECK_TIPOJUEGO;
            tipojuego_code_casillero( tipojuego, NULL );
    } |
    TOK_TRANSFORMA  {  
        CHECK_TIPOJUEGO; 
        init_parameters(); 
        qgzprintf( "Inicializa transformacion" );
        // FIXME: Puede tomar una pieza no definida aun y da error
    }  word_or_string_list {
                    int    i;
                    char*  color = NULL;
                    qgzprintf( "Cantidad de paramertos de transformacion : %d", qgz_param_count );
                    for( i = 0; i < qgz_param_count; i ++ ){
                        int x = qg_tipojuego_get_color( tipojuego, qgz_param_list[i].str );
                        if( x != NOT_FOUND ){
                            color = qgz_param_list[i].str;
                            break;
                        }
                    }
                    for( i = 0; i < qgz_param_count; i ++ ){
                        if( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, qgz_param_list[i].str ) ){
                            qgzprintf( "Se va a transformar a %s %s", qgz_param_list[i].str, color );
                            if( !tipojuego_code_transforma( tipojuego, NOCOLOR, color, qgz_param_list[i].str, 0 ) ) YYERROR;
                        } else if ( NOT_FOUND == qg_tipojuego_get_color( tipojuego, qgz_param_list[i].str ) ){
                            qgzprintf( "Parametro incorrecto en transforma: %s", qgz_param_list[i].str ); 
                            yyerror( "Error de parametros en transforma, debe ser color o tipo de pieza" );
                        }
                    }
    } |
    TOK_CAMBIA_COLOR  TOK_PIEZAS_EN_CAS {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, CAMBIOCOLOR, NULL, NULL, FROM_AQUI ) ) YYERROR; 
    } |
    TOK_CAMBIA_COLOR  word_or_string  TOK_PIEZAS_EN_CAS {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, NOCOLOR, (char*)$2, NULL, FROM_AQUI ) ) YYERROR; 
            free( (char*)$2 );
    } |
    TOK_CAMBIA_COLOR  {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, CAMBIOCOLOR, NULL, NULL, 0 ) ) YYERROR; 
    } |
    TOK_CAMBIA_COLOR  word_or_string  {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, NOCOLOR, (char*)$2, NULL, 0 ) ) YYERROR; 
            free( (char*)$2 );
    };
    


instaction_asigna_att:
    TOK_ASIGNA_ATT  word_or_string  TOK_NUMBER {
          CHECK_TIPOJUEGO;
          if( !tipojuego_code_asigna_att( tipojuego, (char*)$2, $3 ) ) YYERROR;
          free( (char*)$2 );
    } |
    TOK_ASIGNA_ATT  word_or_string ',' TOK_NUMBER {
          CHECK_TIPOJUEGO;
          if( !tipojuego_code_asigna_att( tipojuego, (char*)$2, $4 ) ) YYERROR;
          free( (char*)$2 );
    } ;

instaction_crea:
    TOK_CREA    word_or_string  word_or_string  word_or_string {
            CHECK_TIPOJUEGO;
            int tp  = qg_tipojuego_get_tipopieza( tipojuego, ((char*)$2) );
            if( tp == NOT_FOUND ){
                qgzprintf( "%s debe ser un tipo de pieza", ((char*)$2) );
                yyerror( "Debe ser un tipo de pieza" ); YYERROR;
            }
            int col = qg_tipojuego_get_color( tipojuego, ((char*)$3) );
            if( col == NOT_FOUND ){
                qgzprintf( "%s debe ser un color", ((char*)$3) );
                yyerror( "Debe ser un color" ); YYERROR;
            }
            int cas = qg_tipojuego_get_casillero( tipojuego, ((char*)$4));
            if( cas == NOT_FOUND ){
                qgzprintf( "%s debe ser un casillero", ((char*)$4) );
                yyerror( "Debe ser un casillero" ); YYERROR;
            }
            tipojuego_code_crea( tipojuego, ((char*)$2), NOCOLOR, ((char*)$3), ((char*)$4) );
            free( (char*) $2 );
            free( (char*) $3 );
            free( (char*) $4 );
            
    } |
    TOK_CREA    word_or_string  word_or_string {
            CHECK_TIPOJUEGO;
            int tp  = qg_tipojuego_get_tipopieza( tipojuego, ((char*)$2) );
            if( tp == NOT_FOUND ){
                qgzprintf( "%s debe ser un tipo de pieza", ((char*)$2) );
                yyerror( "Debe ser un tipo de pieza" ); YYERROR;
            }
            int col = qg_tipojuego_get_color( tipojuego, ((char*)$3) );
            if( col == NOT_FOUND ){
                qgzprintf( "%s debe ser un color", ((char*)$3) );
                yyerror( "Debe ser un color" ); YYERROR;
            }
            tipojuego_code_crea( tipojuego, ((char*)$2), NOCOLOR, ((char*)$3), NULL );
            free( (char*) $2 );
            free( (char*) $3 );
    } |
    TOK_CREA    word_or_string  {
            CHECK_TIPOJUEGO;
            CHECK_TIPOJUEGO;
            int tp  = qg_tipojuego_get_tipopieza( tipojuego, ((char*)$2) );
            if( tp == NOT_FOUND ){
                qgzprintf( "%s debe ser un tipo de pieza", ((char*)$2) );
                yyerror( "Debe ser un tipo de pieza" ); YYERROR;
            }
            tipojuego_code_crea( tipojuego, ((char*)$2), PROPIO, NULL, NULL );
            free( (char*) $2 );
    };


instaction_juega:
    TOK_JUEGA   {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_juega( tipojuego, NULL, 0, 0, NULL ) ) YYERROR;
    }  | 
    TOK_CAPTURA_Y_JUEGA {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_juega( tipojuego, NULL, 1, 0, NULL ) ) YYERROR;
    } |
    TOK_JUEGA_SI   instexpr {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_juega( tipojuego, NULL, 0, 0, NULL ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    } |
    TOK_CAPTURA_Y_JUEGA_SI  instexpr {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_juega( tipojuego, NULL, 1, 0, NULL ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    } |
    TOK_CAPTURA_SI  instexpr {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_captura( tipojuego, NULL ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    } |
    TOK_CAPTURA   { 
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_captura( tipojuego, NULL ) ) YYERROR;
    };

instaction_keep:
    TOK_CONTINUA{
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_juega( tipojuego, NULL, 0, 1, NULL ) ) YYERROR;
    } |
    TOK_CONTINUA  word_or_string {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_juega( tipojuego, NULL, 0, 1, (char*)$2 ) ) YYERROR;
            free( (char*) $2 );
    } |
    TOK_CONTINUA_SI instexpr {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_juega( tipojuego, NULL, 0, 1, NULL ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    } ;
 

instaction_para:
    TOK_PARA   {  
            CHECK_TIPOJUEGO;
            tipojuego_code_para( tipojuego );
    } |
    TOK_PARA_SI instexpr { 
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_para( tipojuego );
            tipojuego_code_end_condblock( tipojuego );
    };

/* ------------------------------------------------------ */
/* Moviendo las cosas de un lugar a otro                  */
/* ------------------------------------------------------ */
instaction_mueve:
    TOK_MUEVE   TOK_PIEZAS_EN_CAS  TOK_WORD               {
                          CHECK_TIPOJUEGO;
                          if( NOT_FOUND == qg_tipojuego_get_casillero( tipojuego, (char*)$3 ) ){
                              qgzprintf( "%s debe ser un casillero", (char*)$3 );
                              yyerror( "Debe ser un casillero" );
                              YYERROR;
                          } else {
                              if( !tipojuego_code_mueve( tipojuego, FROM_AQUI | TO_CASILLERO, 0, (char*)$3 ) ) YYERROR;
                          }
                          free( (char*)$3 );
     } |
    TOK_MUEVE   TOK_PIEZAS_EN_CAS  instaction_get_marca   {
                          CHECK_TIPOJUEGO;
                          if( !tipojuego_code_mueve( tipojuego, FROM_AQUI | TO_MARCA, 0, (void*)$3 ) ) YYERROR;
     } |
    TOK_MUEVE   TOK_WORD           TOK_WORD               { NOT_IMPLEMENTED_WARN( "mueve cas  => casillero" ); } |
    TOK_MUEVE   instaction_get_marca                      { NOT_IMPLEMENTED_WARN( "mueve      => marca" ); } ;


/* ------------------------------------------------------ */
/* Marcando un casillero para uso futuro                  */
/* ------------------------------------------------------ */
instaction_set_marca:
    TOK_MARCA   TOK_NUMBER   word_or_string  {
                        CHECK_TIPOJUEGO; 
                        if( NOT_FOUND == qg_tipojuego_get_casillero( tipojuego, (char*)$3 ) ){
                            qgzprintf( "%s debe ser un casillero", (char*)$3 );
                            yyerror( "Debe ser un casillero" );
                            YYERROR;
                        }
                        if( !tipojuego_code_setmarca( tipojuego, $2, (char*)$3 ) ) YYERROR;
                        if( (char*)$3 ) free( (char*)$3 );
    } |
    TOK_MARCA   TOK_NUMBER  {
                        CHECK_TIPOJUEGO; 
                        if( !tipojuego_code_setmarca( tipojuego, $2, 0 ) ) YYERROR;
    } |
    TOK_MARCA   word_or_string               {
                        CHECK_TIPOJUEGO;
                        if( NOT_FOUND == qg_tipojuego_get_casillero( tipojuego, (char*)$2 ) ){
                            qgzprintf( "%s debe ser un casillero", (char*)$2 );
                            yyerror( "Debe ser un casillero" );
                            YYERROR;
                        }
                        if( !tipojuego_code_setmarca( tipojuego,  0, (char*)$2 ) ) YYERROR;
                        if( (char*)$2 ) free( (char*)$2 );
    } | 
    TOK_MARCA {
                        CHECK_TIPOJUEGO; 
                        if( !tipojuego_code_setmarca( tipojuego,  0, 0 ) ) YYERROR;
    } ;


instaction_get_marca:
    TOK_MARCA   TOK_NUMBER                               { $$ = $2; } |
    TOK_MARCA                                            { $$ = 0; };


instaction_goto_marca:
    TOK_GOTO_MARCA   TOK_NUMBER                         {
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_gotomarca( tipojuego, $2 );
    } |
    TOK_GOTO_MARCA  {
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_gotomarca( tipojuego, 0 );
    };




/* ------------------------------------------------------ */
/* Instrucciones de control de flujo del programa         */
/* ------------------------------------------------------ */
instaction_if:
    TOK_IF   instexpr {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
    } code_list {
            tipojuego_code_end_condblock( tipojuego );
    } TOK_END ;

instaction_break:
    TOK_BREAK {
            CHECK_TIPOJUEGO;
            if( !last_block ){
                yyerror( "Break por fuera de bloque" );
                YYERROR;
            }
            tipojuego_code_break_block( tipojuego, last_block );
    }

instaction_while:
    TOK_WHILE  {
            CHECK_TIPOJUEGO;
            $$ = tipojuego_code_start_block( tipojuego );
            // FIXME: Debe usar un stack de bloques.
            last_block = $$;
    } instexpr TOK_DO {
            tipojuego_code_start_condblock( tipojuego );
    }  code_list TOK_END {
            tipojuego_code_continue_block( tipojuego, $2 );
            tipojuego_code_else_condblock( tipojuego );
            tipojuego_code_break_block( tipojuego, $2 );
            tipojuego_code_end_condblock( tipojuego );
            tipojuego_code_end_block( tipojuego, $2 );
    };
    

instaction:
    instaction_asigna_att |
    instaction_break  |
    instaction_crea  |
    instaction_juega |
    instaction_keep  |
    instaction_final |
    instaction_if    |
    instaction_set_marca |
    instaction_goto_marca |
    instaction_movs   |
    instaction_mueve  |
    instaction_para   |
    instaction_while  |
    TOK_WORD    {   
            CHECK_TIPOJUEGO;
            /* una direccion podria ser */
            // qgzprintf( "Reconociendo %s", (char*)$1 );
            if( qg_tipojuego_get_direccion( tipojuego, (char*)$1 ) != NOT_FOUND ){
                    if( !tipojuego_code_direccion( tipojuego, (char*)$1 ) ) YYERROR;
            } else if( qg_tipojuego_get_casillero( tipojuego, (char*)$1 ) != NOT_FOUND ){
                    if( !tipojuego_code_casillero( tipojuego, (char*)$1 ) ) YYERROR;
            } else {
                    qgzprintf( "%s no es nada", (char*)$1 );
                    yyerror( "Comando no reconocido" );
                    YYERROR;
            }
            free( (char*)$1 );
    } ; 

/* --------------------------------------------------------------------------- */
instcode:
    instaction | 
    ;

code_list:
    instcode |
    code_list  TOK_SEPCODE  instcode;







/* --------------------------------------------------------------------------- */
/* A partir de aqui van las instrucciones generales del tipo de juego          */
/* --------------------------------------------------------------------------- */
instruction_attr:
    TOK_ATTR     word_or_string  TOK_NUMBER
                   {  CHECK_TIPOJUEGO ;
                      CHECK_LAST_PIEZA;
                      if( !qg_tipojuego_add_tpieza_att( tipojuego, last_pieza, ((char*)$2), $3 ) ) YYERROR;
                      free( (char*)$2);
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
                     qg_tipojuego_genera_dimensiones( tipojuego, qgz_param_count, dims );
                   };

instruction_color:
    TOK_COLOR      { CHECK_TIPOJUEGO; init_parameters(); }  word_or_string_list
                   { int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                       char* col = ((char*)qgz_param_list[i].par);
                       qg_tipojuego_add_color( tipojuego, col );
                     }
                   }
                   ;

instruction_direction:
    TOK_DIRECTION    word_or_string { CHECK_TIPOJUEGO; init_parameters(); } number_list 
                    {
                      int  dirs[MAX_PARAMS]; int i; 
                      qg_tipojuego_add_direccion( tipojuego, ((char*)$2) );
                      for( i = 0; i < qgz_param_count; i ++ ){
                          dirs[i] = qgz_param_list[i].par;
                      }
                      if( !qg_tipojuego_add_direccion_arr( tipojuego, ((char*)$2), dirs ) ) YYERROR;
                      free( (char*)$2);
                    };

instruction_drop_prelude:
    TOK_DROP   { $$ = 0; } |
    TOK_DROP   word_or_string { NOT_IMPLEMENTED; } ;

instruction_drop:
    instruction_drop_prelude  TOK_SEPARATOR {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, DROP, last_pieza, (char*)($1) );
    }  code_list {
        tipojuego_end_code( tipojuego ) ;
    };


instruction_move_prelude:
    TOK_MOVE                   { $$ = 0; } |
    TOK_MOVE   word_or_string  { $$ = $2; } ;


instruction_move:
    instruction_move_prelude  TOK_SEPARATOR {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, MOVE, last_pieza, ((char*)$1) );
        if( $1 ) free( ((char*)$1) );
    }  code_list {
        tipojuego_end_code( tipojuego ) ;
    };



instruction_ending:
    TOK_ENDING  TOK_SEPARATOR  { 
            CHECK_TIPOJUEGO; 
            change_to_code_mode(); 
            tipojuego_start_codeend( tipojuego );
    }  code_list {
            tipojuego_end_code( tipojuego ) ;
    };

instruction_gametype:
    TOK_GAMETYPE     word_or_string { 
        if( tipojuego ){
            yyerror( "Ya fue definido el tipo juego" );
            YYERROR;
        } else {
            tipojuego = qg_tipojuego_new( ((char*)$2) );
            free((void*)$2);
        }
    };

/* ------------------------------------------------------------------------- */
/* La definicion de la graficacion                                           */
/* ------------------------------------------------------------------------- */
instruction_graph_colors:
    TOK_HTMLCOLOR  ','  TOK_HTMLCOLOR { html_color1 = $1; html_color2 = $3; }  |
    TOK_HTMLCOLOR       TOK_HTMLCOLOR { html_color1 = $1; html_color2 = $2;
                                      qgzprintf( "Frente: %x Fondo: %x", html_color1, html_color2 ); } ;

instruction_graph_dimensions:
    TOK_NUMBER     ','  TOK_NUMBER    { graph_dim1 = $1; graph_dim2 = $3; } |
    TOK_NUMBER     'x'  TOK_NUMBER    { graph_dim1 = $1; graph_dim2 = $3; } |
    TOK_NUMBER          TOK_NUMBER    { graph_dim1 = $1; graph_dim2 = $2; };

instruction_graph_def_prelude:
    { graph_dim1 = 0; graph_dim2 = 0; html_color1 = 0; html_color2 = 0; } ;

instruction_graph_def:
    instruction_graph_def_prelude   instruction_graph_colors ',' instruction_graph_dimensions |
    instruction_graph_def_prelude   instruction_graph_colors     instruction_graph_dimensions |
    instruction_graph_def_prelude   instruction_graph_dimensions ',' instruction_graph_colors |
    instruction_graph_def_prelude   instruction_graph_dimensions     instruction_graph_colors ;

instruction_graph_standard:
    TOK_STANDARD_GEM              { $$ = STANDARD_GEM; }  |
    TOK_STANDARD_BISHOP           { $$ = STANDARD_BISHOP; }|
    TOK_STANDARD_KING             { $$ = STANDARD_KING; }  |
    TOK_STANDARD_KNIGHT           { $$ = STANDARD_KNIGHT; }  |
    TOK_STANDARD_PAWN             { $$ = STANDARD_PAWN; }  |
    TOK_STANDARD_CHECKERS_PAWN    { $$ = STANDARD_CHECKERS_PAWN; }  |
    TOK_STANDARD_CHECKERS_KING    { $$ = STANDARD_CHECKERS_KING; }  |
    TOK_STANDARD_QUEEN            { $$ = STANDARD_QUEEN ; }  |
    TOK_STANDARD_ROOK             { $$ = STANDARD_ROOK; }  ;

board_number:
    TOK_NUMBER  { $$ = $1; 
                  qgzprintf( "Tablero %d", $1 ); } | 
                { $$ = BOARD_ACTUAL; qgzprintf( "Tablero actual" ); };

board_std_type:
    TOK_CHECKERBOARD { $$ = TYPE_CHECKERBOARD; } | 
    TOK_GRID         { $$ = TYPE_GRID; }  |
    TOK_INTERSECTIONS{ $$ = TYPE_INTERSECTIONS; };

instruction_graph:
    TOK_GRAPH_BOARD   board_number  board_std_type   instruction_graph_def     { 
        CHECK_TIPOJUEGO;
        if( !qg_tipojuego_graph_tablero_std( tipojuego, $2, $3, graph_dim1, graph_dim2, html_color1, html_color2 ) ) YYERROR;
     } |
    TOK_GRAPH_BOARD   board_number  word_or_string                             { NOT_IMPLEMENTED_WARN( "graph-board file" ) } |
    TOK_GRAPH_PIECE   instruction_graph_standard  word_or_string  instruction_graph_dimensions  {
        CHECK_TIPOJUEGO;
        if( qg_tipojuego_get_tipopieza( tipojuego, ((char*)$3) ) == NOT_FOUND ){ 
            qgzprintf( "%s debe ser un tipo de pieza", ((char*)$3) );
            yyerror( "Debe ser un tipo de pieza" ); YYERROR;
        }
        if( !qg_tipojuego_graph_tipopieza_std( tipojuego, ((char*)$3), $2, graph_dim1, graph_dim2, 0 ) ) YYERROR;
        free( (char*)$3 );
    } |
    TOK_GRAPH_PIECE   word_or_string  instruction_graph_standard  instruction_graph_dimensions  {
        CHECK_TIPOJUEGO;
        if( qg_tipojuego_get_tipopieza( tipojuego, ((char*)$2) ) == NOT_FOUND ){ 
            qgzprintf( "%s debe ser un tipo de pieza", ((char*)$2) );
            yyerror( "Debe ser un tipo de pieza" ); YYERROR;
        }
        if( !qg_tipojuego_graph_tipopieza_std( tipojuego, ((char*)$2), $3, graph_dim1, graph_dim2, 0 ) ) YYERROR;
        free( (char*)$2 );
    } |
    TOK_GRAPH_PIECE   word_or_string  TOK_STANDARD_RECT   instruction_graph_dimensions TOK_HTMLCOLOR  {
        CHECK_TIPOJUEGO;
        if( qg_tipojuego_get_tipopieza( tipojuego, ((char*)$2) ) == NOT_FOUND ){ 
            qgzprintf( "%s debe ser un tipo de pieza", ((char*)$2) );
            yyerror( "Debe ser un tipo de pieza" ); YYERROR;
        }
        if( !qg_tipojuego_graph_tipopieza_std( tipojuego, ((char*)$2), STANDARD_RECT, graph_dim1, graph_dim2, $5 ) ) YYERROR;
        free( (char*)$2 );
    } |
    TOK_GRAPH_PIECE   word_or_string  word_or_string   TOK_STANDARD_RECT   instruction_graph_dimensions TOK_HTMLCOLOR
                                                               { NOT_IMPLEMENTED_WARN( "graph-piece standard-rect" ); } |
    TOK_GRAPH_PIECE   word_or_string  word_or_string               { NOT_IMPLEMENTED_WARN( "graph-piece string" ); } |
    TOK_GRAPH_SQUARE  word_or_string  word_or_string               { NOT_IMPLEMENTED_WARN( "graph-square file" ); } |
    TOK_GRAPH_SQUARE  word_or_string  TOK_HTMLCOLOR                { NOT_IMPLEMENTED_WARN( "graph-square color" ); } |
    TOK_GRAPH_SQUARE  word_or_string  TOK_HIGHLIGHTED              { NOT_IMPLEMENTED_WARN( "graph-square highlighted" ); } ;


/* ------------------------------------------------------------------------- */
/* Defino el logo del juego                                                  */
/* ------------------------------------------------------------------------- */
instruction_logo:
    TOK_LOGO     {
        CHECK_TIPOJUEGO;
        init_parameters();
    }  word_or_string_list     { 
        if( qgz_param_count == 1 && strstr( (char*)(qgz_param_list[0].par ), "png" ) ){
            qg_tipojuego_graph_logofile( tipojuego, (char*)(qgz_param_list[0].par) );
        } else {
            int i;
            for( i = 0; i < qgz_param_count; i ++ ){
                qg_tipojuego_graph_logopgn( tipojuego, (char*)(qgz_param_list[i].par) );
            }
        }
    } ;



/* ------------------------------------------------------------------------- */
/* La definicion de los tipos de movidas                                     */
/* ------------------------------------------------------------------------- */

instruction_movetype:
    TOK_MOVETYPE     word_or_string {
        CHECK_TIPOJUEGO;
        qgzprintf( "Definiendo %s", ((char*)$2) );
        qg_tipojuego_add_tipo_mov( tipojuego, ((char*)$2), 0 );
        free((void*)$2);
    } |
    TOK_MOVETYPE     word_or_string   TOK_PRIORITY {
        CHECK_TIPOJUEGO;
        qgzprintf( "Definiendo %s", ((char*)$2) );
        qg_tipojuego_add_tipo_mov( tipojuego, ((char*)$2), 1 );
        free((void*)$2);
    } ;

instruction_notation_element:
    TOK_PIECE_NAME        { $$ =  NOTACION_PIEZA; }   |
    TOK_ORIGIN            { $$ =  NOTACION_ORIGEN; }  |
    TOK_TARGET            { $$ =  NOTACION_DESTINO; } |
    TOK_MARK              { $$ =  NOTACION_MARCA ; }  |
    TOK_CAPTURED_MARK     { $$ =  NOTACION_CAPTURA; } ;

instruction_notation_rep:
    instruction_notation_element                                  { CHECK_TIPOJUEGO; qg_tipojuego_add_notacion_rep( tipojuego, $1 ); } |
    instruction_notation_rep  instruction_notation_element        { CHECK_TIPOJUEGO; qg_tipojuego_add_notacion_rep( tipojuego, $2 ); } |
    instruction_notation_rep ','  instruction_notation_element    { CHECK_TIPOJUEGO; qg_tipojuego_add_notacion_rep( tipojuego, $3 ); } ;

instruction_notation_def:
    instruction_notation_element                                 { CHECK_TIPOJUEGO; qg_tipojuego_add_notacion_def( tipojuego, $1 ); } |
    instruction_notation_def      instruction_notation_element   { CHECK_TIPOJUEGO; qg_tipojuego_add_notacion_def( tipojuego, $2 ); } |
    instruction_notation_def ','  instruction_notation_element   { CHECK_TIPOJUEGO; qg_tipojuego_add_notacion_def( tipojuego, $3 ); };


instruction_notation:
    TOK_NOTATION    word_or_string      word_or_string  { 
        CHECK_TIPOJUEGO;
        if( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, (char*)$2 ) ){
            if( !qg_tipojuego_add_notacion_tpieza( tipojuego, (char*)$2, NULL, (char*)$3 ) ) YYERROR ;
        } else if ( NOT_FOUND != qg_tipojuego_get_tipomov( tipojuego, (char*)$2 ) ){
            if( !qg_tipojuego_add_notacion_tmov( tipojuego, (char*)$2, (char*)$3 ) ) YYERROR ;
        } else {
            qgzprintf( "%s debe ser un tipo de pieza o un tipo de movimiento", (char*)$2 );
            yyerror( "Notacion mal formada" );
            YYERROR;
        }
        free( (char*)$2 );
        free( (char*)$3 );
     } |
    TOK_NOTATION    word_or_string      word_or_string  word_or_string { 
        CHECK_TIPOJUEGO;
        char* tpieza; char* color; char* abbr;
        if( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, (char*)$2 ) ){
            tpieza = (char*)$2;
        } else {
            qgzprintf( "%s debe ser un tipo de pieza" );
            yyerror( "Notacion mal formada (tipo de pieza incorrecta)" );
            YYERROR;
        }
        if( NOT_FOUND != qg_tipojuego_get_color( tipojuego, (char*)$3 ) ){
            color = (char*)$3;
            abbr  = (char*)$4;
        } else if ( NOT_FOUND != qg_tipojuego_get_color( tipojuego, (char*)$4 ) ){
            color = (char*)$4;
            abbr  = (char*)$3;
        } else {
            qgzprintf( "%s debe ser un color",  (char*)$3 );
            yyerror( "Notacion mal formada (color incorrecto)" );
            YYERROR;
        } 
        if( !qg_tipojuego_add_notacion_tpieza( tipojuego, tpieza, color, abbr ) ) YYERROR;
        free((void*)$2);
        free((void*)$3);
        free((void*)$4);
    } |
    TOK_NOTATION    TOK_MARK            word_or_string  { 
                  CHECK_TIPOJUEGO;
                  qg_tipojuego_set_notacion_marca( tipojuego, (char*)$3, NULL );
                  free((void*)$3);
             } |
    TOK_NOTATION    TOK_CAPTURED_MARK   word_or_string  { 
                  CHECK_TIPOJUEGO;
                  qg_tipojuego_set_notacion_marca( tipojuego, NULL, (char*)$3 );
                  free((void*)$3);
             } |
    TOK_NOTATION    TOK_DEFAULT         instruction_notation_def  |
    TOK_NOTATION    TOK_ONREPEAT        instruction_notation_rep  ;


instruction_piece:
    TOK_PIECE        word_or_string  { 
        CHECK_TIPOJUEGO; 
        qg_tipojuego_add_tipopieza( tipojuego, ((char*)$2) ); 
        if( last_pieza ) free( last_pieza );
        last_pieza = strdup( ((char*)$2) );
        free( (char*)$2 );
    };

instruction_start:
    TOK_START        word_or_string  word_or_string  TOK_NUMBER {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < $4; i ++ ){
            if( !qg_tipojuego_add_pieza( tipojuego, ((char*)$2), CASILLERO_POZO, ((char*)$3) ) ) YYERROR;
        }
        free( (char*)$2 );
        free( (char*)$3 );
    } |
    TOK_START        word_or_string  word_or_string { init_parameters(); } word_or_string_list  {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < qgz_param_count; i ++ ){
          if( !qg_tipojuego_add_pieza( tipojuego, ((char*)$2), (char*)qgz_param_list[i].par, ((char*)$3) ) ) YYERROR;
        }
        free( (char*)$2 );
        free( (char*)$3 );
    } ;

instruction_sequence_list:
    word_or_string_list   {
        CHECK_TIPOJUEGO;
        int  i;
        for( i = 0; i < qgz_param_count; i ++ ){
            char* val1 =  (char*)qgz_param_list[i].par;
            int  color = qg_tipojuego_get_color( tipojuego, val1 );
            if( color && i < qgz_param_count - 1 ){
                char* val2 = (char*)qgz_param_list[i+1].par;
                int  tmov = qg_tipojuego_get_tipomov( tipojuego, val2 );
                if( tmov != NOT_FOUND ){
                    qgzprintf( "color secuencia %s - tipo mov %s",  val1, val2 );
                    if( !qg_tipojuego_add_secuencia( tipojuego, val1, val2 ) ) YYERROR;
                    i ++;
                } else {
                    qgzprintf( "color secuencia %s",  val1 );
                    if( !qg_tipojuego_add_secuencia( tipojuego, val1, NULL ) ) YYERROR;
                }
            } else {
                qgzprintf( "color secuencia %s",  val1 );
                if( !qg_tipojuego_add_secuencia( tipojuego, val1, NULL ) ) YYERROR;
            }
        } 
    };

instruction_sequence_prelude:
    TOK_SEQUENCE { init_parameters(); qgzprintf( "inicio secuencia %d", TOK_SEQUENCE ); }  instruction_sequence_list;

instruction_sequence:
    instruction_sequence_prelude |
    instruction_sequence_prelude  TOK_REPEAT {
        if( !qg_tipojuego_add_secuencia_rep( tipojuego ) ) YYERROR;
    }
    instruction_sequence_list;


instruction_sym:
    TOK_SYMMETRY     word_or_string  word_or_string  word_or_string { 
        CHECK_TIPOJUEGO;
        if( !qg_tipojuego_add_simetria( tipojuego, ((char*)$2), (char*)$3, (char*)$4 ) ) YYERROR;
        free( ((char*)$2) );
        free( ((char*)$3) );
        free( ((char*)$4) );
    } ;

instruction_zone:
    TOK_ZONE         word_or_string  word_or_string { init_parameters(); } word_or_string_list { 
            CHECK_TIPOJUEGO;
            char* color = (char*)$3;
            char* zona  = (char*)$2;
            if( qg_tipojuego_get_zona( tipojuego, zona ) == NOT_FOUND ){
                qgzprintf( "Nueva zona %s para %s", zona, color );
                qg_tipojuego_add_zona( tipojuego, zona );
            } else {
                qgzprintf( "Define zona %s para %s", zona, color );
            }

            int i;
            for( i = 0; i < qgz_param_count; i ++ ){
                qg_tipojuego_add_cas_to_zona( tipojuego, (char*)qgz_param_list[i].par, color, zona );
            }
            free( ((char*)$2) );
            free( ((char*)$3) );
    } ;

instruction:
    instruction_attr       |
    instruction_board      |
    instruction_color      |
    instruction_direction  |
    instruction_drop       |
    instruction_ending     |
    instruction_gametype   |
    instruction_graph      |
    instruction_logo       |
    instruction_move       |
    instruction_movetype   |
    instruction_notation   |
    instruction_piece      |
    instruction_sequence   |
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










int   parser_qgames( FILE* f, char* filename, int flags ){

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
    init_scanner();

    if( qgzparse() ){
        puts( "Salimos por error!" );
        if( ff ) fclose( ff );
        return 0;
    }
    if( ff ) fclose( ff );
    if( qgz_verbose )printf( "Total analizado: %d lineas\n", qgzlineno );
    
    // Desinicializo los parametros.
    init_parameters( );
    return 1;
}




/*
 * Agrega un parametro
 * */
static  void  add_parameter( int  type, long param ){
  if( !qgz_param_list ){
    qgz_param_list = malloc( sizeof( str_param  ) * MAX_PARAMS );
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

static  void  init_parameters(){ 
    int i;
    for( i = 0; i < qgz_param_count; i ++ ){
        if( qgz_param_list[i].typ == TOK_STRING ) free( qgz_param_list[i].str ) ;
    }
    qgz_param_count = 0; 
}

/*
 * Estos son los analizadores. Ojo, son no reentrantes ... deberia 
 * yo manejar algun tipo de semaforo!
 * */
Tipojuego*  parser_qgames_filename( char* filename, int flags ){
    int  ret;
    ret = parser_qgames( NULL, filename, flags );
    return( ret ? tipojuego : NULL );
}

Tipojuego*  parser_qgames_file    ( FILE* file, int flags ){
    int  ret;
    ret = parser_qgames( file, NULL, flags );
    return( ret ? tipojuego : NULL );
}
Tipojuego*  parser_qgames_string  ( char* string, int flags ){
    fprintf( stderr, "parser_qgames_string no implementado\n" );
    exit( EXIT_FAILURE );
}

