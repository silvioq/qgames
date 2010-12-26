%{

#include <stdio.h>
#include <string.h>
#include "symtable.h"
#include "qgames_parser.h"
#include "qgames.h"

/*
 * Crea una definicion (para substitucion)
 * */
void   create_define( char* d );
void   generate_define( );
int    add_parameter_to_def( char* p );
void   init_scanner();
int    defined( char* d );
int    switch_to_define( );

#define   HEXTOI(x)  ( x >= 'A' && x <= 'F' ? x - 'A' + 10 : ( x >= 'a' && x <= 'f' ? x - 'a' + 10 : x - '0' ) )


symtable*  symt = NULL;
char*  defactual = NULL;
#define  MAXPARMS  16
char*  defparms[MAXPARMS];
char*  define_body;
int    define_created;
int    define_bodyc = 0;
int    parmcount = 0;
int    totalparm;

#define  MAXBUFFSTACK  16
YY_BUFFER_STATE  buffers[MAXBUFFSTACK];
int        line_buffer[MAXBUFFSTACK];
char*      newdata_buffer[MAXBUFFSTACK];
char*      defname_buffer[MAXBUFFSTACK];
int        sp_buffer = 0;

char       string_ret ; // donde retorna



%}

%option batch
%option yylineno
%option case-sensitive
%x      string  string2   code  define  define_head   params

WORD      ([a-zA-Z\?][a-zA-Z0-9\-\_]*\??)
SPACES    [ ]+
BAR       (\_|\-)?
HTMLCOL   (\$[0-9a-fA-F]{6})|(\$[0-9a-fA-F]{3})

%%



<INITIAL,code>\"    { string_ret = YYSTATE; BEGIN(string); qgzlval = 0; }
<string>[^\"]*      { qgzlval = (long)strdup(yytext); 
                      return TOK_STRING;
                    }
<string>\"          { BEGIN(string_ret); 
                      if( !qgzlval ){ 
                          qgzlval = (long)strdup(""); 
                          return TOK_STRING; }  
                    }

<INITIAL,code>\'    { string_ret = YYSTATE; BEGIN(string2); qgzlval = 0;  }
<string2>[^\']*     { qgzlval = (long)strdup(yytext); 
                      return TOK_STRING;
                    }
<string2>\'         { BEGIN(string_ret); 
                      if( !qgzlval ){ 
                          qgzlval = (long)strdup(""); 
                          return TOK_STRING; }  
                    }

<INITIAL,code>{HTMLCOL}  { 
                    if( yyleng == 4 ){
                          qgzlval = HEXTOI(yytext[1]) * 16 * 16 * 16 * 16 + 
                                    HEXTOI(yytext[2]) * 16 * 16 + 
                                    HEXTOI(yytext[3]) ;
                      } else if( yyleng == 7 ){
                          qgzlval = HEXTOI(yytext[1]) * 16 * 16 * 16 * 16 * 16 + 
                                    HEXTOI(yytext[2]) * 16 * 16 * 16 * 16 + 
                                    HEXTOI(yytext[3]) * 16 * 16 * 16 +  
                                    HEXTOI(yytext[4]) * 16 * 16  +  
                                    HEXTOI(yytext[5]) * 16 +  
                                    HEXTOI(yytext[6]) ; 
                      } else yyterminate();
                      return  TOK_HTMLCOLOR;
                    }


<code>^{WORD}\:     { BEGIN(INITIAL); yyless(0); return  TOK_SEPARATOR; }
<define>^{WORD}\:   { generate_define(); BEGIN(INITIAL); yyless(0); return  TOK_SEPARATOR; }
<define>.|\n        { define_body[define_bodyc++] = yytext[0]; }

<define_head>{WORD} { if( !define_created) 
                          create_define( yytext );
                      else{
                          if( !add_parameter_to_def( yytext ) ) yyterminate();
                      }
                    } ;
<define_head>\n     { BEGIN(define); }
<define_head>.


attribute\:         { return  TOK_ATTR;      }
board\:             { return  TOK_BOARD ;    }
captured{BAR}mark   { return  TOK_CAPTURED_MARK; }
color\:             { return  TOK_COLOR;     }
checkerboard        { return  TOK_CHECKERBOARD; }
default             { return  TOK_DEFAULT;   }
directions?\:       { return  TOK_DIRECTION; }
drop\:              { return  TOK_DROP;      }
ending\:            { return  TOK_ENDING;    }
gametype\:          { return  TOK_GAMETYPE;  }
graph{BAR}board\:   { return  TOK_GRAPH_BOARD; }
graph{BAR}piece\:   { return  TOK_GRAPH_PIECE; }
graph{BAR}square\:  { return  TOK_GRAPH_SQUARE; }
grid                { return  TOK_GRID;    }
highlight(ed)?      { return  TOK_HIGHLIGHTED;  }
intersections?      { return  TOK_INTERSECTIONS; }
mark                { return  TOK_MARK;      }
move\:              { return  TOK_MOVE;      }
movetype\:          { return  TOK_MOVETYPE;  }
notation\:          { return  TOK_NOTATION;  }
origin          { return TOK_ORIGIN;    }
onrepeat        { return TOK_ONREPEAT;  }
piece\:         { return TOK_PIECE;     }
piece{BAR}name  { return TOK_PIECE_NAME; }
repeat          { return TOK_REPEAT;    }
sequence\:      { return TOK_SEQUENCE;  }
symmetry\:      { return TOK_SYMMETRY;  }
start\:         { return TOK_START;     }
standard{BAR}gem    { return  TOK_STANDARD_GEM      ; }
standard{BAR}bishop { return  TOK_STANDARD_BISHOP   ; }
standard{BAR}king   { return  TOK_STANDARD_KING     ; }
standard{BAR}knight { return  TOK_STANDARD_KNIGHT   ; }
standard{BAR}pawn   { return  TOK_STANDARD_PAWN     ; }
standard{BAR}queen  { return  TOK_STANDARD_QUEEN    ; }
standard{BAR}rook   { return  TOK_STANDARD_ROOK     ; }
target          { return TOK_TARGET;    }
zone\:          { return TOK_ZONE;      }

define\:        { define_created = 0; BEGIN(define_head);   }

<params>\'[^\']*\'        { 
                            char* str = strdup( ((char*)yytext) + 1 );
                            str[yyleng - 2] = 0;
                            
                            if( !add_parameter_to_def( str ) ) yyterminate();
                            // free( str );
                            if( parmcount == totalparm ){
                                if( ! switch_to_define( )) yyterminate();
                            }
                          }
<params>\"[^\"]*\"        { 
                            char* str = strdup( ((char*)yytext) + 1 );
                            str[yyleng - 2] = 0;
                            
                            if( !add_parameter_to_def( str ) ) yyterminate();
                            // free( str );
                            if( parmcount == totalparm ){
                                if( ! switch_to_define( )) yyterminate();
                            }
                          }
<params>[^ \n\r,]+        { if( !add_parameter_to_def( yytext ) ) yyterminate();
                            if( parmcount == totalparm ){
                                if( ! switch_to_define( ) )yyterminate();
                            }
                          }
<params>.                 // No hago nada!


<code>and                 { return TOK_AND;       }
<code>\=\=                { return TOK_DEQUAL;    }
<code>\=                  { return TOK_EQUAL;     }
<code>&&                  { return TOK_AND;       }
<code>\!                  { return TOK_NOT;       }
<code>not                 { return TOK_NOT;       }

<code>ahogado\??                  { return  TOK_AHOGADO;   }
<code>aqui                        { return  TOK_AQUI;      }
<code>asigna{BAR}atributo         { return  TOK_ASIGNA_ATT; }
<code>asigna{BAR}att              { return  TOK_ASIGNA_ATT; }
<code>atacado{BAR}enemigo\??      { return  TOK_ATACADO_ENEMIGO; }
<code>cambiar?{BAR}color          { return  TOK_CAMBIA_COLOR; }
<code>cantidad{BAR}piezas\??                  { return  TOK_CANTIDAD_PIEZAS; }
<code>cantidad{BAR}piezas{BAR}propi(a|o)s?    { return  TOK_CANTIDAD_PIEZAS_PROPIAS; }
<code>cantidad{BAR}piezas{BAR}enemig(a|o)s?   { return  TOK_CANTIDAD_PIEZAS_ENEMIGAS; }
<code>captura                                 { return  TOK_CAPTURA; }
<code>captura{BAR}y{BAR}juega                 { return  TOK_CAPTURA_Y_JUEGA; }
<code>captura{BAR}y{BAR}juega{BAR}si          { return  TOK_CAPTURA_Y_JUEGA_SI; }
<code>captura{BAR}y{BAR}juega{SPACES}if       { return  TOK_CAPTURA_Y_JUEGA_SI; }
<code>capturadas{BAR}enemigo                  { return  TOK_CAPTURADAS_ENEMIGO; }
<code>capturadas{BAR}propio                   { return  TOK_CAPTURADAS_PROPIO; }
<code>casillero{BAR}inicial                   { return  TOK_CASILLERO_INICIAL; }
<code>destino{BAR}ant(erior)?\??              { return  TOK_DESTINO_ANT; }
<code>empata                 { return TOK_EMPATA;    }
<code>empata{BAR}si          { return TOK_EMPATA_SI; }
<code>empata{SPACES}if       { return TOK_EMPATA_SI; }
<code>en{BAR}tablero\??      { return TOK_ENTABLERO; }
<code>en{BAR}zona\??         { return TOK_ENZONA;    }
<code>gana                   { return TOK_GANA;      }
<code>gana{BAR}si            { return TOK_GANA_SI;   }
<code>gana{SPACES}if         { return TOK_GANA_SI;   }
<code>goto{BAR}marca         { return TOK_GOTO_MARCA; }
<code>marca                  { return TOK_MARCA;     }
<code>mover                  { return TOK_MUEVE;     }
<code>mueve                  { return TOK_MUEVE;     }
<code>jaquemate\??           { return TOK_JAQUEMATE; }
<code>juega                  { return TOK_JUEGA;     } 
<code>juega{BAR}si           { return TOK_JUEGA_SI;  }
<code>juega{SPACES}if        { return TOK_JUEGA_SI;  }
<code>ocupado\??             { return TOK_OCUPADO;   }
<code>ocupado{BAR}enemigo\??                  { return  TOK_OCUPADOENEMIGO;   }
<code>ocupado{BAR}propio\??                   { return  TOK_OCUPADOPROPIO;   }
<code>origen{BAR}ant(erior)?\??               { return  TOK_ORIGEN_ANT; }
<code>parar?                                  { return  TOK_PARA;        }
<code>parar?{BAR}si                           { return  TOK_PARA_SI;     }
<code>parar{SPACES}if                         { return  TOK_PARA_SI;     }
<code>pierde                                  { return  TOK_PIERDE;      }
<code>pierde{BAR}si                           { return  TOK_PIERDE_SI;   }
<code>piezas{BAR}en{BAR}casillero             { return  TOK_PIEZAS_EN_CAS; }
<code>transformar?           { return  TOK_TRANSFORMA;  }
<code>repite{BAR}posicion\?? { return  TOK_REPITEPOS; }

<code>do                  { return TOK_DO;        }
<code>break               { return TOK_BREAK;     }
<code>if                  { return TOK_IF;        }
<code>end                 { return TOK_END;       }
<code>while               { return  TOK_WHILE;       }


<INITIAL,code>\-?[0-9]+           { 
                                    qgzlval = atol(yytext); 
                                    return TOK_NUMBER;
                                  }

<INITIAL,code>true                { qgzlval = 1; return TOK_NUMBER; }
<INITIAL,code>false               { qgzlval = 0; return TOK_NUMBER; }
<INITIAL>{WORD}                   { 
                                    qgzlval = (long)strdup(yytext); 
                                    ((char*)(long)qgzlval)[yyleng] = 0;
                                    qgzprintf( "WORD: %s", (char*)(long)qgzlval  );
                                    return  TOK_WORD; 
                                  }

<INITIAL,code>[ \t\r]+        /* ignore whitespace */
<INITIAL,code>\#[^\n]*        /* ignora comentario */ 


\n              { return  TOK_SEPARATOR ; }

<code>\n        { return  TOK_SEPCODE; }
<code>\;        { return  TOK_SEPCODE; }
<code>{WORD}    {
                  int  argc = ( symt ? symtable_argc( symt, yytext ) : -1 );
                  if( argc == 0 ){
                      parmcount = 0;
                      defactual = strdup( yytext );
                      switch_to_define( );
                  } else if( argc >= 0 ){
                      parmcount = 0;
                      totalparm = argc;
                      defactual = strdup( yytext );
                      BEGIN(params);
                  } else {
                      qgzlval = (long)strdup(yytext); 
                      ((char*)(long)qgzlval)[yyleng] = 0;
                      return  TOK_WORD; 
                  }
                }
<code>.         { return (int) yytext[0]; }

<<EOF>>         { if( sp_buffer == 0 ){
                      yyterminate();
                  } else {  
                      sp_buffer --;
                      if( newdata_buffer[sp_buffer] ) free( newdata_buffer[sp_buffer] );
                      if( defname_buffer[sp_buffer] ) free( defname_buffer[sp_buffer] );
                      yy_delete_buffer( YY_CURRENT_BUFFER );
                      yy_switch_to_buffer( buffers[sp_buffer] );
                      yylineno = line_buffer[sp_buffer]  ;
                  }
                }

.


%%


void   init_scanner(){
    if( symt ){
        symtable_free( symt );
        symt = NULL;
    }
    define_created = 0;
    parmcount = 0;
    sp_buffer = 0;
   
}

void   change_to_code_mode(){
    BEGIN(code);
}

int    defined( char* d ){
    if( !symt ) return 0;
    return  symtable_search( symt, d );
}


void   create_define( char* d ){
    define_created = 1;    
    defactual     = strdup( d );
    define_body   = malloc( 1024 );
    define_body[0] = 0;
    define_bodyc  = 0;
    parmcount     = 0;
}

int    add_parameter_to_def( char* p ){
    defparms[parmcount++] = strdup( p );   
    if( parmcount >= MAXPARMS ){ 
        qgzerror( "Se alcanzo el maximo de parametros admitidos" );
        return 0;
    }
    return 1;
}


void   generate_define( ){
    int i;
    if( !symt ) symt = symtable_init( );
    define_body[define_bodyc] = 0;
    symtable_adddef( symt, defactual    , parmcount, defparms, define_body );
    free( define_body );
    free( defactual );
    for( i = 0; i < parmcount ; i ++ ){
        free( defparms[i] );
    }
}


int    switch_to_define( ){
    if( !symt ){
        qgzerror( "Error resolviendo symt" );
        return 0;
    }

    if( sp_buffer + 1 >= MAXBUFFSTACK ){
        qgzerror( "Maximo alcanzado en stack buffer de defines" );
        return 0;
    }

    char*  data; 
    int i;
    if (!symtable_resolve( symt, defactual, parmcount, defparms, &data ) ){
        qgzerror( "Error resolviendo define" );
        return 0;
    }
       
    // buffers[sp_buffer] = yybuffer
    buffers[sp_buffer] = YY_CURRENT_BUFFER;
    line_buffer[sp_buffer] = yylineno;
    yylineno = 1;
    newdata_buffer[sp_buffer] = data;
    defname_buffer[sp_buffer] = defactual;
    sp_buffer ++;

    for( i = 0; i < parmcount ; i ++ ){
        free( defparms[i] );
    }
    defactual = NULL;

    yy_scan_string( data );
    BEGIN(code);

    return 1;
    
}


const char*  defname_actual( ){
    if( sp_buffer == 0 ) return NULL;
    return( defname_buffer[sp_buffer-1] );
}


