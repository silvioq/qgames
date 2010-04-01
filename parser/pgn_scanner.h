/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2010.
*/

/*
   1. Event: the name of the tournament or match event.
   2. Site:  the location of the event. This is in "City, Region COUNTRY" format, 
             where COUNTRY is the 3-letter International Olympic Committee code 
             for the country. An example is "New York City, NY USA".
   3. Date:  the starting date of the game, in YYYY.MM.DD form. "??" are used for 
             unknown values.
   4. Round: the playing round ordinal of the game within the event.
   5. White: the player of the white pieces, in "last name, first name" format.
   6. Black: the player of the black pieces, same format as White.
   7. Result: the result of the game. This can only have four possible values: 
              "1-0" (White won), 
              "0-1" (Black won), 
              "1/2-1/2" (Draw), or 
               "*" (other, e.g., the game is ongoing).
*/

extern  char* pgntag_event;
extern  char* pgntag_site;
extern  char* pgntag_date;
extern  char* pgntag_round;
extern  char* pgntag_white;
extern  char* pgntag_black;
extern  char* pgntag_result;

/*
    * Annotator: The person providing notes to the game.
    * PlyCount: String value denoting total number of half-moves played.
    * TimeControl: "40/7200:3600" (moves per seconds: sudden death seconds)
    * Time: Time the game started, in "HH:MM:SS" format, in local clock time.
    * Termination: Gives more details about the termination of the game. 
      It may be "abandoned", "adjudication" (result determined by third-party 
      adjudication), "death", "emergency", "normal", "rules infraction", 
      "time forfeit", or "unterminated".
    * Mode: "OTB" (over-the-board) "ICS" (Internet Chess Server)
    * FEN: The initial position of the chess board, in Forsyth-Edwards 
           Notation. This is used to record partial games (starting at some 
           initial position). It is also necessary for chess variants such 
           as Fischer random chess, where the initial position is not always 
           the same as traditional chess. If a FEN tag is used, a separate 
           tag pair "SetUp" must also appear and have its value set to "1".
*/

extern  char* pgntag_fen;

/*
    Many chess variants can be recorded using PGN, provided the names of 
    the pieces can be limited to one character, usually a letter and not a 
    number. They are typically noted with a tag named "Variant" giving the 
    name of the rules. The term "Variation" must be avoided, as that refers 
    to the name of an opening variation. Note that traditional chess 
    programs can only handle, at most, a few variants. Forsyth-Edwards 
    Notation (FEN) is used to record the starting position for variants 
    (such as Chess960) which have initial positions other than the orthodox 
    chess initial position.

*/

extern  char* pgntag_variant;

extern  char* pgnmoves;

extern  char* pgnerror;


int   pgnscan(char* scan);

