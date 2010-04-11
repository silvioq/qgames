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

%%



<INITIAL,code>\"    { string_ret = YYSTATE; BEGIN(string); }
<string>[^\"]*      { qgzlval = (long)strdup(yytext); 
                      return TOK_STRING;
                    }
<string>\"          { BEGIN(string_ret); }

<INITIAL,code>\'    { string_ret = YYSTATE; BEGIN(string2);  }
<string2>[^\']*     { qgzlval = (long)strdup(yytext); 
                      return TOK_STRING;
                    }
<string2>\'         { BEGIN(string_ret); }


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

<params>\'[^\']*\'        { 
                            char* str = strdup( ((char*)yytext) + 1 );
                            str[yyleng - 2] = 0;
                            
                            if( !add_parameter_to_def( str ) ) yyterminate();
                            if( parmcount == totalparm ){
                                if( ! switch_to_define( )) yyterminate();
                            }
                            free( str );
                          }
<params>\"[^\"]*\"        { 
                            char* str = strdup( ((char*)yytext) + 1 );
                            str[yyleng - 2] = 0;
                            
                            if( !add_parameter_to_def( str ) ) yyterminate();
                            if( parmcount == totalparm ){
                                if( ! switch_to_define( )) yyterminate();
                            }
                            free( str );
                          }
<params>[^ \n\r,]+        { if( !add_parameter_to_def( yytext ) ) yyterminate();
                            if( parmcount == totalparm ){
                                if( ! switch_to_define( ) )yyterminate();
                            }
                          }
<params>.                 // No hago nada!


<code>and                 { return TOK_AND;       }
<code>&&                  { return TOK_AND;       }
<code>\!                  { return TOK_NOT;       }
<code>not                 { return TOK_NOT;       }

<code>ahogado\??                  { return  TOK_AHOGADO;   }
<code>atacado(\-|\_)enemigo\??   { return  TOK_ATACADO_ENEMIGO; }
<code>casillero(\-|\_)inicial     { return  TOK_CASILLERO_INICIAL; }
<code>empata              { return TOK_EMPATA;    }
<code>empata\-si          { return TOK_EMPATA_SI; }
<code>en(\-|\_)tablero\?? { return TOK_ENTABLERO;   }
<code>en(\-|\_)zona\??    { return TOK_ENZONA;    }
<code>gana                { return TOK_GANA;      }
<code>gana\-si            { return TOK_GANA_SI;   }
<code>jaquemate\??        { return TOK_JAQUEMATE; }
<code>juega               { return TOK_JUEGA;     } 
<code>juega\-si           { return TOK_JUEGA_SI;  }
<code>ocupado\??          { return TOK_OCUPADO;   }
<code>ocupado\_enemigo\?? { return TOK_OCUPADOENEMIGO;   }
<code>ocupado\_propio\??  { return TOK_OCUPADOPROPIO;   }
<code>ocupado\-enemigo\?? { return TOK_OCUPADOENEMIGO;   }
<code>ocupado\-propio\??  { return TOK_OCUPADOPROPIO;   }
<code>parar?              { return  TOK_PARA;        }
<code>parar?\-si          { return  TOK_PARA_SI;     }
<code>pierde              { return  TOK_PIERDE;      }
<code>pierde\-si          { return  TOK_PIERDE_SI;   }
<code>transformar?        { return  TOK_TRANSFORMA;  }

<code>do                  { return TOK_DO;        }
<code>if                  { return TOK_IF;        }
<code>end                 { return TOK_END;       }
<code>while               { return  TOK_WHILE;       }


<INITIAL,code>\-?[0-9]+  { 
                  qgzlval = atol(yytext); 
                  return TOK_NUMBER;
                }

<INITIAL>{WORD} { 
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

       
    // buffers[sp_buffer] = yybuffer
    buffers[sp_buffer] = YY_CURRENT_BUFFER;
    line_buffer[sp_buffer] = yylineno;
    yylineno = 1;
    newdata_buffer[sp_buffer] = data;
    defname_buffer[sp_buffer] = strdup( defactual );
    sp_buffer ++;

    for( i = 0; i < parmcount ; i ++ ){
        free( defparms[i] );
    }
    free( defactual );

    yy_scan_string( data );
    BEGIN(code);

    return 1;
    
}


char*  defname_actual( ){
    if( sp_buffer == 0 ) return NULL;
    return( defname_buffer[sp_buffer-1] );
}


