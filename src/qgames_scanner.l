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

\-?[0-9]+       { yylval = atol(yytext); 
                  return TOK_NUMBER;
                }

{WORD}          { yylval = (long)strdup(yytext); 
                  ((char*)(long)yylval)[yyleng - 1] = 0;
                  return  TOK_WORD; 
                }

\"              { BEGIN(string); }
<string>[^\"]*  { yylval = (long)strdup(yytext); 
                  return TOK_STRING;
                }
<string>\"      { BEGIN(INITIAL); }

<code>\n        { return  TOK_SEPARATOR; }
<code>\;        { return  TOK_SEPARATOR; }
<code>^{WORD}\: { YYREJECT; BEGIN(INITIAL); }


^{WORD}\:       { yylval = (long)strdup(yytext); 
                  ((char*)(long)yylval)[yyleng - 1] = 0;
                  return  TOK_LABEL; 
                }

[ \t\r]+        /* ignore whitespace */
\#[^\n]*        /* ignora comentario */
