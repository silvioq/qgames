%{

#include <stdio.h>
#include "defines.h"

/*
   1. Event: the name of the tournament or match event.
   2. Site: the location of the event. This is in "City, Region COUNTRY" format, where COUNTRY is the 3-letter International Olympic Committee code for the country. An example is "New York City, NY USA".
   3. Date: the starting date of the game, in YYYY.MM.DD form. "??" are used for unknown values.
   4. Round: the playing round ordinal of the game within the event.
   5. White: the player of the white pieces, in "last name, first name" format.
   6. Black: the player of the black pieces, same format as White.
   7. Result: the result of the game. This can only have four possible values: "1-0" (White won), "0-1" (Black won), "1/2-1/2" (Draw), or "*" (other, e.g., the game is ongoing).
*/

char* pgntag_event = NULL;
char* pgntag_site = NULL;
char* pgntag_date = NULL;
char* pgntag_round = NULL;
char* pgntag_white = NULL;
char* pgntag_black = NULL;
char* pgntag_result = NULL;

/*
    * Annotator: The person providing notes to the game.
    * PlyCount: String value denoting total number of half-moves played.
    * TimeControl: "40/7200:3600" (moves per seconds: sudden death seconds)
    * Time: Time the game started, in "HH:MM:SS" format, in local clock time.
    * Termination: Gives more details about the termination of the game. It may be "abandoned", "adjudication" (result determined by third-party adjudication), "death", "emergency", "normal", "rules infraction", "time forfeit", or "unterminated".
    * Mode: "OTB" (over-the-board) "ICS" (Internet Chess Server)
    * FEN: The initial position of the chess board, in Forsyth-Edwards Notation. This is used to record partial games (starting at some initial position). It is also necessary for chess variants such as Fischer random chess, where the initial position is not always the same as traditional chess. If a FEN tag is used, a separate tag pair "SetUp" must also appear and have its value set to "1".
*/

char* pgntag_fen = NULL;

/*
    Many chess variants can be recorded using PGN, provided the names of the pieces can be limited to one character, usually a letter and not a number. They are typically noted with a tag named "Variant" giving the name of the rules. The term "Variation" must be avoided, as that refers to the name of an opening variation. Note that traditional chess programs can only handle, at most, a few variants. Forsyth-Edwards Notation (FEN) is used to record the starting position for variants (such as Chess960) which have initial positions other than the orthodox chess initial position.

*/

char* pgntag_variant = NULL;

char* pgnmoves = NULL;
int   pgnmvchcount = 0;
int   pgnmvchalloc = 0;

/* -------------------------------------------------------- */
int   pgnlineno;
int   pgncolno;

char* pgnerror = NULL;


char*   extracttag(char*);
void    addmove(char*);

%}

%option batch
%option case-insensitive

TAGDEF  \"[^\"]*\"
SPACES  [:space:]+
MOVENUMBER   [:digit:]+\.
MOVE         [:alnum:]+

%%
.       { if( yytext[0] == '\n' ){
            pgnlineno ++; pgncolno = 1;
          } else { pgncolno ++; }
          REJECT;
        }

\[event{SPACES}{TAGDEF}\]      {  pgntag_event   = extracttag( yytext ); }
\[result{SPACES}{TAGDEF}\]     {  pgntag_result  = extracttag( yytext ); }
\[variant{SPACES}{TAGDEF}\]    {  pgntag_variant = extracttag( yytext ); }

MOVENUMBER                     /* Por ahora ignoro los numeros de movidas */
MOVE                           {  addmove( yytext ); }

[ \t\r\n]+                     /* ignore whitespace */
.                              {
                                  pgnerror = ALLOC( 256 );
                                  sprintf( pgnerror, "Caracter no reconocido Linea: %d, Col: %d", pgnlineno, pgncolno );
                                  yyterminate();
                               };

%%

char*  extracttag(char* line){
    char*  initquote = strchr( line, '"' );
    initquote ++;
    char*  endquote = strchr( initquote, '"' );
    endquote --;

    int  len = endquote - initquote;
    char* ret = ALLOC( len + 1 );
    strncpy( ret, initquote, len );
    ret[len] = 0;
    return ret;
}

void    addmove(char* move){
    if( !pgnmoves ){ 
        pgnmoves = ALLOC( 32 ); 
        pgnmvchcount = 0;
        pgnmvchalloc = 32;
     }
    int  len = strlen( move );
    if( pgnmvchcount + len + 1 >= pgnmvchalloc ){
        pgnmvchalloc += len + 32;
        pgnmoves = REALLOC( pgnmoves, pgnmvchalloc );
    }

    strcat( pgnmoves + pgnmvchcount, " " );
    strcat( pgnmoves + pgnmvchcount, move );
    pgnmvchcount += len + 1;
}


void   initpgn( ){
    freepgn( );
}


#define  FREEVARIABLE(var) if( var ){ free( var ); var = NULL; }

void   freepgn( ){

    FREEVARIABLE( pgntag_event )
    FREEVARIABLE( pgntag_site )
    FREEVARIABLE( pgntag_date )
    FREEVARIABLE( pgntag_round )
    FREEVARIABLE( pgntag_white )
    FREEVARIABLE( pgntag_black )
    FREEVARIABLE( pgntag_result )
    FREEVARIABLE( pgntag_fen )
    FREEVARIABLE( pgntag_variant )
    FREEVARIABLE( pgnmoves )
    FREEVARIABLE( pgnerror )
    pgnmvchcount = 0;
    pgnmvchalloc = 0;
}
