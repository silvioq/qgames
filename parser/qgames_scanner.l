%{

#include <stdio.h>
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
int        sp_buffer = 0;


%}

%option batch
%option yylineno
%option case-sensitive
%x      string    code  define  define_head   params

WORD      ([a-zA-Z\?][a-zA-Z0-9\-\_]*\??)

%%



\"              { BEGIN(string); }
<string>[^\"]*  { qgzlval = (long)strdup(yytext); 
                  return TOK_STRING;
                }
<string>\"      { BEGIN(INITIAL); }


<code>^{WORD}\:   { BEGIN(INITIAL); yyless(0); return  TOK_SEPARATOR; }
<define>^{WORD}\: { generate_define(); BEGIN(INITIAL); yyless(0); return  TOK_SEPARATOR; }
<define>.|\n      { define_body[define_bodyc++] = yytext[0]; }

<define_head>{WORD} { if( !define_created) 
                          create_define( yytext );
                      else{
                          if( !add_parameter_to_def( yytext ) ) yyterminate();
                      }
                    } ;
<define_head>\n     { BEGIN(define); }
<define_head>.


attribute\:     { return TOK_ATTR;      }
board\:         { return TOK_BOARD ;    }
color\:         { return TOK_COLOR;     }
directions?\:   { return TOK_DIRECTION; }
drop\:          { return TOK_DROP;      }
ending\:        { return TOK_ENDING;    }
gametype\:      { return TOK_GAMETYPE;  }
move\:          { return TOK_MOVE;      }
movetype\:      { return TOK_MOVETYPE;  }
piece\:         { return TOK_PIECE;     }
repeat          { return TOK_REPEAT;    }
sequence\:      { return TOK_SEQUENCE;  }
symmetry\:      { return TOK_SYMMETRY;  }
start\:         { return TOK_START;     }
zone\:          { return TOK_ZONE;      }

define\:        { define_created = 0; BEGIN(define_head);   }

<params>\"[^\"]*\"        { if( !add_parameter_to_def( yytext ) ) yyterminate();
                            if( parmcount == totalparm ){
                                if( ! switch_to_define( )) yyterminate();
                            }
                          }
<params>[^ \n\r,;]+       { if( !add_parameter_to_def( yytext ) ) yyterminate();
                            if( parmcount == totalparm ){
                                if( ! switch_to_define( ) )yyterminate();
                            }
                          }
<params>.                 // No hago nada!


<code>ahogado\??          { return TOK_AHOGADO;   }
<code>empata              { return TOK_EMPATA;    }
<code>empata\-si          { return TOK_EMPATA_SI; }
<code>gana                { return TOK_GANA;      }
<code>gana\-si            { return TOK_GANA_SI;   }
<code>juega               { return TOK_JUEGA;     } 
<code>juega\-si           { return TOK_JUEGA_SI;  }
<code>if                  { return TOK_IF;        }
<code>ocupado\??          { return TOK_OCUPADO;   }
<code>ocupado\_enemigo\?? { return TOK_OCUPADOENEMIGO;   }
<code>ocupado\_propio\??  { return TOK_OCUPADOPROPIO;   }
<code>parar?              { return  TOK_PARA;        }
<code>parar?\-si          { return  TOK_PARA_SI;     }
<code>pierde              { return  TOK_PIERDE;      }
<code>pierde\-si          { return  TOK_PIERDE_SI;   }


<INITIAL,code>\-?[0-9]+  { 
                  qgzlval = atol(yytext); 
                  return TOK_NUMBER;
                }

<INITIAL>{WORD} { 
                  qgzlval = (long)strdup(yytext); 
                  ((char*)(long)qgzlval)[yyleng] = 0;
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
    define_body   = ALLOC( 1024 );
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
    for( i = 0 ; i < parmcount; i ++ ){ free( defparms[i] ); }
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

    for( i = 0; i < parmcount ; i ++ ){
        free( defparms[i] );
    }
    free( defactual );

       
    // buffers[sp_buffer] = yybuffer
    qgzerror( "No implementado switch to define" );
    return 0;
    
}

