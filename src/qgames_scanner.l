%{

#include <stdio.h>
#include "qgames_parser.h"
#include "qgames.h"

void   create_define( char* d );
void   add_parameter_to_def( char* p );
int    define_created;
int    define_head;

%}

%option batch
%option yylineno
%option case-sensitive
%x      string    code  define  define_head

WORD      ([a-zA-Z\?][a-zA-Z0-9\-\_]*\??)

%%



\"              { BEGIN(string); }
<string>[^\"]*  { qgzlval = (long)strdup(yytext); 
                  return TOK_STRING;
                }
<string>\"      { BEGIN(INITIAL); }


<code>^{WORD}\:   { BEGIN(INITIAL); yyless(0); return  TOK_SEPARATOR; }
<define>^{WORD}\: { BEGIN(INITIAL); yyless(0); return  TOK_SEPARATOR; }
<define>\n        ;
<define>.         ;

<define_head>{WORD} { if( !define_created) 
                          create_define( yytext );
                      else add_parameter_to_def( yytext );
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
start\:         { return TOK_START;     }
symmetry\:      { return TOK_SYMMETRY;  }
zone\:          { return TOK_ZONE;      }


define\:        { define_created = 0; BEGIN(define_head);   }


<code>ahogado\??          { return TOK_AHOGADO;   }
<code>empata              { return TOK_EMPATA;    }
<code>gana                { return TOK_GANA;      }
<code>juega               { return TOK_JUEGA;     } 
<code>juega\-si           { return TOK_JUEGA_SI;  }
<code>if                  { return TOK_IF;        }
<code>ocupado\??          { return TOK_OCUPADO;   }
<code>ocupado\_enemigo\?? { return TOK_OCUPADOENEMIGO;   }
<code>ocupado\_propio\??  { return TOK_OCUPADOPROPIO;   }
<code>parar?              { return  TOK_PARA;        }
<code>parar?\-si          { return  TOK_PARA_SI;     }
<code>pierde              { return  TOK_PIERDE;      }


<INITIAL,code>\-?[0-9]+  { 
                  qgzlval = atol(yytext); 
                  return TOK_NUMBER;
                }

<INITIAL,code>{WORD}  { 
                  qgzlval = (long)strdup(yytext); 
                  ((char*)(long)qgzlval)[yyleng] = 0;
                  return  TOK_WORD; 
                }

<INITIAL,code>[ \t\r]+        /* ignore whitespace */
<INITIAL,code>\#[^\n]*        /* ignora comentario */


\n              { return  TOK_SEPARATOR ; }

<code>\n        { return  TOK_SEPCODE; }
<code>\;        { return  TOK_SEPCODE; }
<code>.         { return (int) yytext[0]; }

.               


%%

void   change_to_code_mode(){
    BEGIN(code);
}


void   create_define( char* d ){
    define_created = 1;    
}

void   add_parameter_to_def( char* p ){

}
