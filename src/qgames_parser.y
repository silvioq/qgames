{



}

%token    TOK_NUMBER  TOK_WORD   TOK_STRING
%token    TOK_LABEL

%start    game_definition


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

