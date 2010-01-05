%{

#include <stdio.h>
#include "qgames_parser.h"
#include "qgames.h"

%}

%option batch
%option yylineno
%option case-sensitive
%x      string    code

WORD      ([a-zA-Z\?][a-zA-Z0-9\-\_]*\??)

%%



\"              { BEGIN(string); }
<string>[^\"]*  { qgzlval = (long)strdup(yytext); 
                  return TOK_STRING;
                }
<string>\"      { BEGIN(INITIAL); }


<code>^{WORD}\: { BEGIN(INITIAL); yyless(0); return  TOK_SEPARATOR; }


board\:         { return TOK_BOARD ;    }
color\:         { return TOK_COLOR;     }
directions?\:   { return TOK_DIRECTION; }
drop\:          { return TOK_DROP;      }
ending\:        { return TOK_ENDING;    }
gametype\:      { return TOK_GAMETYPE;  }
piece\:         { return TOK_PIECE;     }
start\:         { return TOK_START;     }


<code>ahogado\?? { return TOK_AHOGADO;   }
<code>empata     { return TOK_EMPATA;    }
<code>gana       { return TOK_GANA;      }
<code>juega      { return TOK_JUEGA;     }
<code>if         { return TOK_IF;        }
<code>ocupado\?? { return TOK_OCUPADO;   }
<code>ocupado\_propio\?? { return TOK_OCUPADOPROPIO;   }
<code>parar?     { return  TOK_PARA;     }
<code>pierde     { return  TOK_PIERDE;   }


<INITIAL,code>\-?[0-9]+  { 
                  qgzlval = atol(yytext); 
                  return TOK_NUMBER;
                }

<INITIAL,code>{WORD}  { 
                  qgzlval = (long)strdup(yytext); 
                  ((char*)(long)qgzlval)[yyleng - 1] = 0;
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
