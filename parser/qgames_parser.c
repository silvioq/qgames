/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse qgzparse
#define yylex   qgzlex
#define yyerror qgzerror
#define yylval  qgzlval
#define yychar  qgzchar
#define yydebug qgzdebug
#define yynerrs qgznerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_NUMBER = 258,
     TOK_WORD = 259,
     TOK_STRING = 260,
     TOK_HTMLCOLOR = 261,
     TOK_SEPARATOR = 262,
     TOK_ATTR = 263,
     TOK_BOARD = 264,
     TOK_CAPTURED_MARK = 265,
     TOK_CANTIDAD_PIEZAS = 266,
     TOK_CANTIDAD_PIEZAS_PROPIAS = 267,
     TOK_CANTIDAD_PIEZAS_ENEMIGAS = 268,
     TOK_COLOR = 269,
     TOK_DEFAULT = 270,
     TOK_DIRECTION = 271,
     TOK_DROP = 272,
     TOK_ENDING = 273,
     TOK_GAMETYPE = 274,
     TOK_MARK = 275,
     TOK_MOVE = 276,
     TOK_MOVETYPE = 277,
     TOK_NOTATION = 278,
     TOK_ONREPEAT = 279,
     TOK_ORIGIN = 280,
     TOK_PIECE = 281,
     TOK_PIECE_NAME = 282,
     TOK_REPEAT = 283,
     TOK_SEQUENCE = 284,
     TOK_START = 285,
     TOK_SYMMETRY = 286,
     TOK_TARGET = 287,
     TOK_ZONE = 288,
     TOK_SEPCODE = 289,
     TOK_AHOGADO = 290,
     TOK_AQUI = 291,
     TOK_ASIGNA_ATT = 292,
     TOK_ATACADO_ENEMIGO = 293,
     TOK_CAPTURA = 294,
     TOK_CAPTURA_SI = 295,
     TOK_CAPTURA_Y_JUEGA = 296,
     TOK_CAPTURA_Y_JUEGA_SI = 297,
     TOK_CAPTURADAS_ENEMIGO = 298,
     TOK_CAPTURADAS_PROPIO = 299,
     TOK_CASILLERO_INICIAL = 300,
     TOK_DESTINO_ANT = 301,
     TOK_EMPATA = 302,
     TOK_EMPATA_SI = 303,
     TOK_ENTABLERO = 304,
     TOK_ENZONA = 305,
     TOK_GANA = 306,
     TOK_GANA_SI = 307,
     TOK_JAQUEMATE = 308,
     TOK_JUEGA = 309,
     TOK_JUEGA_SI = 310,
     TOK_MARCA = 311,
     TOK_MUEVE = 312,
     TOK_MUEVE_SI = 313,
     TOK_IF = 314,
     TOK_OCUPADO = 315,
     TOK_OCUPADOENEMIGO = 316,
     TOK_OCUPADOPROPIO = 317,
     TOK_ORIGEN_ANT = 318,
     TOK_PARA = 319,
     TOK_PARA_SI = 320,
     TOK_PIERDE = 321,
     TOK_PIERDE_SI = 322,
     TOK_PIEZAS_EN_CAS = 323,
     TOK_TRANSFORMA = 324,
     TOK_REPITEPOS = 325,
     TOK_AND = 326,
     TOK_OR = 327,
     TOK_NOT = 328,
     TOK_EQUAL = 329,
     TOK_DEQUAL = 330,
     TOK_WHILE = 331,
     TOK_DO = 332,
     TOK_END = 333,
     TOK_GRAPH_BOARD = 334,
     TOK_GRAPH_PIECE = 335,
     TOK_GRAPH_SQUARE = 336,
     TOK_GRID = 337,
     TOK_CHECKERBOARD = 338,
     TOK_INTERSECTIONS = 339,
     TOK_HIGHLIGHTED = 340,
     TOK_STANDARD_GEM = 341,
     TOK_STANDARD_BISHOP = 342,
     TOK_STANDARD_KING = 343,
     TOK_STANDARD_KNIGHT = 344,
     TOK_STANDARD_PAWN = 345,
     TOK_STANDARD_QUEEN = 346,
     TOK_STANDARD_ROOK = 347
   };
#endif
/* Tokens.  */
#define TOK_NUMBER 258
#define TOK_WORD 259
#define TOK_STRING 260
#define TOK_HTMLCOLOR 261
#define TOK_SEPARATOR 262
#define TOK_ATTR 263
#define TOK_BOARD 264
#define TOK_CAPTURED_MARK 265
#define TOK_CANTIDAD_PIEZAS 266
#define TOK_CANTIDAD_PIEZAS_PROPIAS 267
#define TOK_CANTIDAD_PIEZAS_ENEMIGAS 268
#define TOK_COLOR 269
#define TOK_DEFAULT 270
#define TOK_DIRECTION 271
#define TOK_DROP 272
#define TOK_ENDING 273
#define TOK_GAMETYPE 274
#define TOK_MARK 275
#define TOK_MOVE 276
#define TOK_MOVETYPE 277
#define TOK_NOTATION 278
#define TOK_ONREPEAT 279
#define TOK_ORIGIN 280
#define TOK_PIECE 281
#define TOK_PIECE_NAME 282
#define TOK_REPEAT 283
#define TOK_SEQUENCE 284
#define TOK_START 285
#define TOK_SYMMETRY 286
#define TOK_TARGET 287
#define TOK_ZONE 288
#define TOK_SEPCODE 289
#define TOK_AHOGADO 290
#define TOK_AQUI 291
#define TOK_ASIGNA_ATT 292
#define TOK_ATACADO_ENEMIGO 293
#define TOK_CAPTURA 294
#define TOK_CAPTURA_SI 295
#define TOK_CAPTURA_Y_JUEGA 296
#define TOK_CAPTURA_Y_JUEGA_SI 297
#define TOK_CAPTURADAS_ENEMIGO 298
#define TOK_CAPTURADAS_PROPIO 299
#define TOK_CASILLERO_INICIAL 300
#define TOK_DESTINO_ANT 301
#define TOK_EMPATA 302
#define TOK_EMPATA_SI 303
#define TOK_ENTABLERO 304
#define TOK_ENZONA 305
#define TOK_GANA 306
#define TOK_GANA_SI 307
#define TOK_JAQUEMATE 308
#define TOK_JUEGA 309
#define TOK_JUEGA_SI 310
#define TOK_MARCA 311
#define TOK_MUEVE 312
#define TOK_MUEVE_SI 313
#define TOK_IF 314
#define TOK_OCUPADO 315
#define TOK_OCUPADOENEMIGO 316
#define TOK_OCUPADOPROPIO 317
#define TOK_ORIGEN_ANT 318
#define TOK_PARA 319
#define TOK_PARA_SI 320
#define TOK_PIERDE 321
#define TOK_PIERDE_SI 322
#define TOK_PIEZAS_EN_CAS 323
#define TOK_TRANSFORMA 324
#define TOK_REPITEPOS 325
#define TOK_AND 326
#define TOK_OR 327
#define TOK_NOT 328
#define TOK_EQUAL 329
#define TOK_DEQUAL 330
#define TOK_WHILE 331
#define TOK_DO 332
#define TOK_END 333
#define TOK_GRAPH_BOARD 334
#define TOK_GRAPH_PIECE 335
#define TOK_GRAPH_SQUARE 336
#define TOK_GRID 337
#define TOK_CHECKERBOARD 338
#define TOK_INTERSECTIONS 339
#define TOK_HIGHLIGHTED 340
#define TOK_STANDARD_GEM 341
#define TOK_STANDARD_BISHOP 342
#define TOK_STANDARD_KING 343
#define TOK_STANDARD_KNIGHT 344
#define TOK_STANDARD_PAWN 345
#define TOK_STANDARD_QUEEN 346
#define TOK_STANDARD_ROOK 347




/* Copy the first part of user declarations.  */
#line 1 "qgames_parser.y"


#include  <stdio.h>
#include  <stdarg.h>
#include  <string.h>
#include  <stdlib.h>
#include  <errno.h>
#include  <qgames.h>
#include  <qgames_analyzer.h>
#include  <qgames_code.h>
#include  "qcode.h"





typedef  struct StrParam {
  int   typ;
  union {
      long  par;
      char* str;
 };
} str_param;


int    qgz_verbose  = 0;

str_param*  qgz_param_list  = NULL;
int    qgz_param_count = 0;
void  add_parameter( int  type, long param );
void  init_parameters( );

#define  MAX_PARAMS   32

#define YYSTYPE long
#define YYDEBUG 1

extern  int  qgzlineno;
extern FILE* qgzin;

Tipojuego*   tipojuego  = NULL;
char*        last_pieza = NULL;
long         html_color1, html_color2;
long         graph_dim1, graph_dim2;

const  char*  defname_actual( );

#define  CHECK_TIPOJUEGO   \
    if( !tipojuego ){ yyerror( "gametype no definido aun" ); YYERROR; }
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




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 385 "qgames_parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   310

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  98
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  201
/* YYNRULES -- Number of states.  */
#define YYNSTATES  291

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   347

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      95,    96,     2,     2,    93,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    94,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      97,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    16,    18,    21,
      23,    26,    28,    30,    32,    34,    37,    40,    44,    47,
      49,    51,    54,    56,    59,    61,    65,    68,    71,    73,
      75,    77,    80,    83,    85,    87,    90,    91,    96,   100,
     104,   108,   112,   114,   116,   118,   120,   122,   124,   126,
     128,   130,   132,   134,   136,   139,   141,   144,   146,   149,
     151,   152,   156,   160,   165,   167,   169,   172,   175,   177,
     179,   182,   186,   190,   194,   197,   199,   201,   205,   208,
     211,   213,   215,   216,   217,   224,   225,   226,   234,   236,
     238,   240,   242,   244,   246,   248,   250,   252,   254,   256,
     258,   259,   261,   265,   269,   270,   274,   275,   279,   280,
     285,   287,   290,   291,   296,   298,   301,   302,   307,   308,
     313,   316,   320,   323,   327,   331,   334,   335,   340,   344,
     349,   353,   355,   357,   359,   361,   363,   365,   367,   369,
     370,   372,   374,   376,   381,   385,   390,   395,   399,   403,
     407,   411,   414,   416,   418,   420,   422,   424,   426,   429,
     433,   435,   438,   442,   446,   451,   455,   459,   463,   467,
     470,   475,   476,   482,   484,   485,   489,   491,   492,   497,
     502,   503,   509,   511,   513,   515,   517,   519,   521,   523,
     525,   527,   529,   531,   533,   535,   537,   539,   541,   542,
     544,   548
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     178,     0,    -1,     4,    -1,     5,    -1,    99,    -1,   100,
      99,    -1,   100,    93,    99,    -1,     3,    -1,   101,     3,
      -1,    35,    -1,    35,    99,    -1,    38,    -1,    11,    -1,
      12,    -1,    13,    -1,   104,   100,    -1,   104,     3,    -1,
      43,    94,     3,    -1,    43,     3,    -1,   104,    -1,    46,
      -1,    46,    99,    -1,    63,    -1,    63,    99,    -1,    49,
      -1,    50,    99,    99,    -1,    50,    99,    -1,    53,    99,
      -1,    60,    -1,    62,    -1,    61,    -1,    60,    99,    -1,
      70,     3,    -1,    74,    -1,    75,    -1,    73,   115,    -1,
      -1,   115,    71,   114,   115,    -1,   115,    72,   115,    -1,
     115,   112,     3,    -1,     3,   112,   115,    -1,    95,   115,
      96,    -1,   113,    -1,   102,    -1,   103,    -1,   105,    -1,
     106,    -1,   107,    -1,   108,    -1,   109,    -1,   110,    -1,
     111,    -1,     4,    -1,    47,    -1,    48,   115,    -1,    51,
      -1,    52,   115,    -1,    66,    -1,    67,   115,    -1,    45,
      -1,    -1,    69,   118,   100,    -1,    37,    99,     3,    -1,
      37,    99,    93,     3,    -1,    54,    -1,    41,    -1,    55,
     115,    -1,    42,   115,    -1,    39,    -1,    64,    -1,    65,
     115,    -1,    57,    68,     4,    -1,    57,    68,   125,    -1,
      57,     4,     4,    -1,    57,   125,    -1,    36,    -1,    99,
      -1,    56,     3,   123,    -1,    56,   123,    -1,    56,     3,
      -1,    56,    -1,   125,    -1,    -1,    -1,    59,   115,   128,
     135,   129,    78,    -1,    -1,    -1,    76,   131,   115,    77,
     132,   135,    78,    -1,   119,    -1,   120,    -1,   116,    -1,
     127,    -1,   124,    -1,   126,    -1,   117,    -1,   122,    -1,
     121,    -1,   130,    -1,     4,    -1,   133,    -1,    -1,   134,
      -1,   135,    34,   134,    -1,     8,    99,     3,    -1,    -1,
       9,   138,   100,    -1,    -1,    14,   140,   100,    -1,    -1,
      16,    99,   142,   101,    -1,    17,    -1,    17,    99,    -1,
      -1,   143,     7,   145,   135,    -1,    21,    -1,    21,    99,
      -1,    -1,   146,     7,   148,   135,    -1,    -1,    18,     7,
     150,   135,    -1,    19,    99,    -1,     6,    93,     6,    -1,
       6,     6,    -1,     3,    93,     3,    -1,     3,    97,     3,
      -1,     3,     3,    -1,    -1,   154,   152,    93,   153,    -1,
     154,   152,   153,    -1,   154,   153,    93,   152,    -1,   154,
     153,   152,    -1,    86,    -1,    87,    -1,    88,    -1,    89,
      -1,    90,    -1,    91,    -1,    92,    -1,     3,    -1,    -1,
      83,    -1,    82,    -1,    84,    -1,    79,   157,   158,   155,
      -1,    79,   157,    99,    -1,    80,   156,    99,   153,    -1,
      80,    99,   156,   153,    -1,    80,    99,    99,    -1,    81,
      99,    99,    -1,    81,    99,     6,    -1,    81,    99,    85,
      -1,    22,    99,    -1,    27,    -1,    25,    -1,    32,    -1,
      20,    -1,    10,    -1,   161,    -1,   162,   161,    -1,   162,
      93,   161,    -1,   161,    -1,   163,   161,    -1,   163,    93,
     161,    -1,    23,    99,    99,    -1,    23,    99,    99,    99,
      -1,    23,    20,    99,    -1,    23,    10,    99,    -1,    23,
      15,   163,    -1,    23,    24,   162,    -1,    26,    99,    -1,
      30,    99,    99,     3,    -1,    -1,    30,    99,    99,   167,
     100,    -1,   100,    -1,    -1,    29,   170,   168,    -1,   169,
      -1,    -1,   169,    28,   172,   168,    -1,    31,    99,    99,
      99,    -1,    -1,    33,    99,    99,   175,   100,    -1,   136,
      -1,   137,    -1,   139,    -1,   141,    -1,   144,    -1,   149,
      -1,   151,    -1,   159,    -1,   147,    -1,   160,    -1,   164,
      -1,   165,    -1,   171,    -1,   166,    -1,   173,    -1,   174,
      -1,    -1,   176,    -1,   177,     7,   176,    -1,   177,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   172,   172,   173,   177,   178,   179,   182,   183,   190,
     194,   200,   206,   211,   216,   225,   245,   249,   253,   257,
     263,   267,   277,   281,   296,   302,   326,   337,   350,   354,
     358,   362,   380,   388,   388,   391,   395,   395,   401,   403,
     407,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   463,   467,   473,   477,   483,   487,   497,
     501,   501,   524,   528,   536,   540,   544,   550,   556,   563,
     567,   578,   588,   592,   593,   600,   601,   614,   618,   625,
     626,   630,   639,   642,   639,   647,   650,   647,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   689,
     689,   693,   694,   706,   716,   716,   728,   728,   738,   738,
     749,   750,   753,   753,   764,   765,   769,   769,   781,   781,
     790,   804,   805,   809,   810,   811,   814,   817,   818,   819,
     820,   823,   824,   825,   826,   827,   828,   829,   832,   834,
     837,   838,   839,   842,   846,   847,   855,   863,   864,   865,
     866,   875,   883,   884,   885,   886,   887,   890,   891,   892,
     895,   896,   897,   901,   913,   939,   944,   949,   950,   954,
     962,   969,   969,   978,   998,   998,  1001,  1002,  1002,  1009,
    1015,  1015,  1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,
    1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,  1048,  1055,
    1056,  1060
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_NUMBER", "TOK_WORD", "TOK_STRING",
  "TOK_HTMLCOLOR", "TOK_SEPARATOR", "TOK_ATTR", "TOK_BOARD",
  "TOK_CAPTURED_MARK", "TOK_CANTIDAD_PIEZAS",
  "TOK_CANTIDAD_PIEZAS_PROPIAS", "TOK_CANTIDAD_PIEZAS_ENEMIGAS",
  "TOK_COLOR", "TOK_DEFAULT", "TOK_DIRECTION", "TOK_DROP", "TOK_ENDING",
  "TOK_GAMETYPE", "TOK_MARK", "TOK_MOVE", "TOK_MOVETYPE", "TOK_NOTATION",
  "TOK_ONREPEAT", "TOK_ORIGIN", "TOK_PIECE", "TOK_PIECE_NAME",
  "TOK_REPEAT", "TOK_SEQUENCE", "TOK_START", "TOK_SYMMETRY", "TOK_TARGET",
  "TOK_ZONE", "TOK_SEPCODE", "TOK_AHOGADO", "TOK_AQUI", "TOK_ASIGNA_ATT",
  "TOK_ATACADO_ENEMIGO", "TOK_CAPTURA", "TOK_CAPTURA_SI",
  "TOK_CAPTURA_Y_JUEGA", "TOK_CAPTURA_Y_JUEGA_SI",
  "TOK_CAPTURADAS_ENEMIGO", "TOK_CAPTURADAS_PROPIO",
  "TOK_CASILLERO_INICIAL", "TOK_DESTINO_ANT", "TOK_EMPATA",
  "TOK_EMPATA_SI", "TOK_ENTABLERO", "TOK_ENZONA", "TOK_GANA",
  "TOK_GANA_SI", "TOK_JAQUEMATE", "TOK_JUEGA", "TOK_JUEGA_SI", "TOK_MARCA",
  "TOK_MUEVE", "TOK_MUEVE_SI", "TOK_IF", "TOK_OCUPADO",
  "TOK_OCUPADOENEMIGO", "TOK_OCUPADOPROPIO", "TOK_ORIGEN_ANT", "TOK_PARA",
  "TOK_PARA_SI", "TOK_PIERDE", "TOK_PIERDE_SI", "TOK_PIEZAS_EN_CAS",
  "TOK_TRANSFORMA", "TOK_REPITEPOS", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_EQUAL", "TOK_DEQUAL", "TOK_WHILE", "TOK_DO", "TOK_END",
  "TOK_GRAPH_BOARD", "TOK_GRAPH_PIECE", "TOK_GRAPH_SQUARE", "TOK_GRID",
  "TOK_CHECKERBOARD", "TOK_INTERSECTIONS", "TOK_HIGHLIGHTED",
  "TOK_STANDARD_GEM", "TOK_STANDARD_BISHOP", "TOK_STANDARD_KING",
  "TOK_STANDARD_KNIGHT", "TOK_STANDARD_PAWN", "TOK_STANDARD_QUEEN",
  "TOK_STANDARD_ROOK", "','", "'='", "'('", "')'", "'x'", "$accept",
  "word_or_string", "word_or_string_list", "number_list",
  "instexpr_ahogado", "instexpr_atacado", "cantidad_piezas_preludio",
  "instexpr_cantidad_piezas", "instexpr_movidas_anteriores",
  "instexpr_entablero", "instexpr_enzona", "instexpr_jaquemate",
  "instexpr_ocupado", "instexpr_repitepos", "es_igual_a",
  "instexpr_logical", "@1", "instexpr", "instaction_final",
  "instaction_movs", "@2", "instaction_asigna_att", "instaction_juega",
  "instaction_para", "instaction_mueve", "instaction_marca_casillero",
  "instaction_set_marca", "instaction_get_marca", "instaction_goto_marca",
  "instaction_if", "@3", "@4", "instaction_while", "@5", "@6",
  "instaction", "instcode", "code_list", "instruction_attr",
  "instruction_board", "@7", "instruction_color", "@8",
  "instruction_direction", "@9", "instruction_drop_prelude",
  "instruction_drop", "@10", "instruction_move_prelude",
  "instruction_move", "@11", "instruction_ending", "@12",
  "instruction_gametype", "instruction_graph_colors",
  "instruction_graph_dimensions", "instruction_graph_def_prelude",
  "instruction_graph_def", "instruction_graph_standard", "board_number",
  "board_std_type", "instruction_graph", "instruction_movetype",
  "instruction_notation_element", "instruction_notation_rep",
  "instruction_notation_def", "instruction_notation", "instruction_piece",
  "instruction_start", "@13", "instruction_sequence_list",
  "instruction_sequence_prelude", "@14", "instruction_sequence", "@15",
  "instruction_sym", "instruction_zone", "@16", "instruction",
  "instruction_list", "game_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,    44,    61,    40,    41,   120
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    98,    99,    99,   100,   100,   100,   101,   101,   102,
     102,   103,   104,   104,   104,   105,   105,   105,   105,   105,
     106,   106,   106,   106,   107,   108,   108,   109,   110,   110,
     110,   110,   111,   112,   112,   113,   114,   113,   113,   113,
     113,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   116,   116,   116,   116,   116,   116,   117,
     118,   117,   119,   119,   120,   120,   120,   120,   120,   121,
     121,   122,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   128,   129,   127,   131,   132,   130,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   134,
     134,   135,   135,   136,   138,   137,   140,   139,   142,   141,
     143,   143,   145,   144,   146,   146,   148,   147,   150,   149,
     151,   152,   152,   153,   153,   153,   154,   155,   155,   155,
     155,   156,   156,   156,   156,   156,   156,   156,   157,   157,
     158,   158,   158,   159,   159,   159,   159,   159,   159,   159,
     159,   160,   161,   161,   161,   161,   161,   162,   162,   162,
     163,   163,   163,   164,   164,   164,   164,   164,   164,   165,
     166,   167,   166,   168,   170,   169,   171,   172,   171,   173,
     175,   174,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   177,
     177,   178
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     3,     1,     2,     1,
       2,     1,     1,     1,     1,     2,     2,     3,     2,     1,
       1,     2,     1,     2,     1,     3,     2,     2,     1,     1,
       1,     2,     2,     1,     1,     2,     0,     4,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     2,     1,
       0,     3,     3,     4,     1,     1,     2,     2,     1,     1,
       2,     3,     3,     3,     2,     1,     1,     3,     2,     2,
       1,     1,     0,     0,     6,     0,     0,     7,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     3,     3,     0,     3,     0,     3,     0,     4,
       1,     2,     0,     4,     1,     2,     0,     4,     0,     4,
       2,     3,     2,     3,     3,     2,     0,     4,     3,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     4,     3,     4,     4,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     2,     3,     3,     4,     3,     3,     3,     3,     2,
       4,     0,     5,     1,     0,     3,     1,     0,     4,     4,
       0,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     198,     0,   104,   106,     0,   110,     0,     0,   114,     0,
       0,     0,   174,     0,     0,     0,   139,     0,     0,   182,
     183,   184,   185,     0,   186,     0,   190,   187,   188,   189,
     191,   192,   193,   195,   176,   194,   196,   197,   199,   201,
       0,     2,     3,     0,     0,     0,   108,   111,   118,   120,
     115,   151,     0,     0,     0,     0,     0,   169,     0,     0,
       0,     0,   138,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,   112,   116,   177,   198,     1,   103,
       4,   105,   107,     0,   100,   166,   156,   155,   153,   152,
     154,   160,   167,   165,   157,   168,   163,   173,   175,   171,
       0,   180,   141,   140,   142,   144,   126,   147,     0,     0,
     149,   150,   148,   100,   100,     0,   200,     0,     5,     7,
     109,    98,     0,    68,    65,     0,    59,    53,     0,    55,
       0,    64,     0,    80,     0,     0,    69,     0,    57,     0,
      60,    85,    90,    94,    88,    89,    96,    95,    92,    81,
      93,    91,    97,    99,   101,   119,     0,   161,     0,   158,
     164,   170,     0,   179,     0,     0,   143,     0,   146,   145,
     113,   117,   178,     6,     8,     0,     0,    52,    12,    13,
      14,     9,    11,     0,    20,    24,     0,     0,    28,    30,
      29,    22,     0,     0,     0,    43,    44,    19,    45,    46,
      47,    48,    49,    50,    51,    42,    67,    54,    56,    66,
      79,    75,    76,    78,     0,    80,     0,    74,    82,    70,
      58,     0,     0,   100,   162,   159,   172,   181,     0,     0,
       0,   125,     0,     0,    62,     0,    33,    34,     0,    10,
      18,     0,    21,    26,    27,    31,    23,    32,    35,     0,
      16,    15,    36,     0,     0,    77,    73,    79,    71,    72,
     100,    61,     0,   102,   122,     0,     0,   128,     0,   130,
     123,   124,    63,    40,    17,    25,    41,     0,    38,    39,
      83,    86,   121,   127,   129,    37,     0,   100,    84,     0,
      87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    80,    97,   120,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   254,   205,   277,   206,   142,   143,
     221,   144,   145,   146,   147,   213,   148,   149,   150,   151,
     260,   286,   152,   222,   287,   153,   154,   155,    19,    20,
      44,    21,    45,    22,    83,    23,    24,   113,    25,    26,
     114,    27,    84,    28,   229,   168,   165,   166,    72,    63,
     106,    29,    30,    91,    95,    92,    31,    32,    33,   162,
      98,    34,    58,    35,   115,    36,    37,   164,    38,    39,
      40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -195
static const yytype_int16 yypact[] =
{
     214,    38,  -195,  -195,    38,    38,    31,    38,    38,    38,
     286,    38,  -195,    38,    38,    38,    46,    63,    38,  -195,
    -195,  -195,  -195,    47,  -195,    49,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,    41,  -195,  -195,  -195,  -195,    66,
      83,  -195,  -195,    87,    38,    38,  -195,  -195,  -195,  -195,
    -195,  -195,    38,   114,    38,   114,    38,  -195,    38,    38,
      38,    38,  -195,    60,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,    63,    38,    35,  -195,  -195,  -195,   214,  -195,  -195,
    -195,    29,    29,    88,   216,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,    25,  -195,  -195,    77,    38,    29,  -195,    90,
      38,  -195,  -195,  -195,  -195,  -195,  -195,  -195,    95,    95,
    -195,  -195,  -195,   216,   216,    38,  -195,    38,  -195,  -195,
      97,  -195,    38,  -195,  -195,   154,  -195,  -195,   154,  -195,
     154,  -195,   154,    43,    26,   154,  -195,   154,  -195,   154,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,    69,   114,  -195,   114,  -195,
    -195,  -195,    38,  -195,    38,    86,  -195,     8,  -195,  -195,
      69,    69,  -195,  -195,  -195,    18,     3,  -195,  -195,  -195,
    -195,    38,  -195,    12,    38,  -195,    38,    38,    38,  -195,
    -195,    38,   105,   154,   154,  -195,  -195,   207,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,    89,    89,    89,    89,
      71,  -195,  -195,  -195,   106,   120,    28,  -195,    89,    89,
      89,    38,   154,   216,  -195,  -195,    29,    29,    19,    20,
      22,  -195,   123,   125,  -195,   128,  -195,  -195,   154,  -195,
    -195,   130,  -195,    38,  -195,  -195,  -195,  -195,    89,   102,
    -195,    29,  -195,   154,   132,  -195,  -195,  -195,  -195,  -195,
     216,    29,   107,  -195,  -195,   111,    95,  -195,   131,  -195,
    -195,  -195,  -195,    89,  -195,  -195,  -195,   154,    89,  -195,
      69,  -195,  -195,  -195,  -195,    89,    62,   216,  -195,    10,
    -195
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -195,    -1,   -26,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,   -20,  -195,  -195,  -108,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,   -63,  -195,   -97,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,   -64,  -112,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -194,  -104,  -195,  -195,   101,  -195,
    -195,  -195,  -195,   -29,  -195,  -195,  -195,  -195,  -195,  -195,
      53,  -195,  -195,  -195,  -195,  -195,  -195,  -195,   116,  -195,
    -195
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      43,   170,   171,    46,    47,   169,    49,    50,    51,    56,
      57,   231,    59,    60,    61,   240,    71,    73,    81,    82,
     207,   234,   208,   167,   209,   264,    94,   218,   228,   219,
     214,   220,   258,    41,    42,    86,   269,   217,    48,    41,
      42,   110,    41,    42,   223,    87,   210,    41,    42,    62,
      88,    85,    89,    93,    74,    96,    75,    90,    99,   100,
     101,   230,   105,   157,    41,    42,   159,    41,    42,    76,
     107,   109,   112,    77,   284,    41,    42,   236,   237,   211,
     118,   118,   215,    78,   215,   248,   249,    86,   290,   167,
      79,   119,   228,   161,   216,   160,   118,    87,   167,   163,
     174,   232,    88,   223,    89,   233,   241,   211,   247,    90,
     256,   235,   265,   266,   262,   268,   173,   282,   156,   259,
     111,   175,   117,   257,    86,   267,   270,   224,   271,   225,
     273,   272,   212,   274,    87,   279,   226,   228,   227,    88,
     288,    89,   102,   103,   104,   278,    90,   255,   280,    64,
      65,    66,    67,    68,    69,    70,   238,   176,   177,   263,
     252,   253,   283,   236,   237,   178,   179,   180,   172,   285,
     158,   251,   108,   252,   253,   289,   236,   237,   252,   253,
     239,   236,   237,   242,   281,   243,   244,   245,     0,   181,
     246,     0,   182,   116,     0,   261,     0,   183,   276,     0,
     184,     0,     0,   185,   186,     0,     0,   187,     0,   212,
     250,    41,    42,     0,   188,   189,   190,   191,     0,     0,
     121,     0,     1,     2,   192,   118,   118,   193,     3,     0,
       4,     5,     6,     7,     0,     8,     9,    10,     0,     0,
      11,     0,   275,    12,    13,    14,     0,    15,     0,   194,
     118,     0,     0,   122,     0,   123,     0,   124,   125,     0,
     118,   126,     0,   127,   128,     0,     0,   129,   130,     0,
     131,   132,   133,   134,     0,   135,     0,     0,     0,     0,
     136,   137,   138,   139,     0,   140,     0,     0,     0,     0,
      41,    42,   141,    16,    17,    18,    52,     0,     0,     0,
       0,    53,     0,     0,     0,     0,    54,     0,     0,     0,
      55
};

static const yytype_int16 yycheck[] =
{
       1,   113,   114,     4,     5,   109,     7,     8,     9,    10,
      11,     3,    13,    14,    15,     3,    17,    18,    44,    45,
     128,     3,   130,     3,   132,     6,    55,   135,     6,   137,
       4,   139,     4,     4,     5,    10,   230,   134,     7,     4,
       5,     6,     4,     5,    34,    20,     3,     4,     5,     3,
      25,    52,    27,    54,     7,    56,     7,    32,    59,    60,
      61,   165,    63,    92,     4,     5,    95,     4,     5,    28,
      71,    72,    73,     7,   268,     4,     5,    74,    75,    36,
      81,    82,    56,     0,    56,   193,   194,    10,    78,     3,
       3,     3,     6,     3,    68,    96,    97,    20,     3,   100,
       3,    93,    25,    34,    27,    97,    94,    36,     3,    32,
       4,    93,    93,    93,   222,    93,   117,     6,    93,   216,
      85,   122,    93,     3,    10,   229,     3,   156,     3,   158,
     238,     3,   133,     3,    20,     3,   162,     6,   164,    25,
      78,    27,    82,    83,    84,   253,    32,   210,   260,    86,
      87,    88,    89,    90,    91,    92,   176,     3,     4,   223,
      71,    72,   266,    74,    75,    11,    12,    13,   115,   277,
      93,   197,    71,    71,    72,   287,    74,    75,    71,    72,
     181,    74,    75,   184,    77,   186,   187,   188,    -1,    35,
     191,    -1,    38,    77,    -1,   221,    -1,    43,    96,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    -1,   210,
       3,     4,     5,    -1,    60,    61,    62,    63,    -1,    -1,
       4,    -1,     8,     9,    70,   226,   227,    73,    14,    -1,
      16,    17,    18,    19,    -1,    21,    22,    23,    -1,    -1,
      26,    -1,   243,    29,    30,    31,    -1,    33,    -1,    95,
     251,    -1,    -1,    37,    -1,    39,    -1,    41,    42,    -1,
     261,    45,    -1,    47,    48,    -1,    -1,    51,    52,    -1,
      54,    55,    56,    57,    -1,    59,    -1,    -1,    -1,    -1,
      64,    65,    66,    67,    -1,    69,    -1,    -1,    -1,    -1,
       4,     5,    76,    79,    80,    81,    10,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    14,    16,    17,    18,    19,    21,    22,
      23,    26,    29,    30,    31,    33,    79,    80,    81,   136,
     137,   139,   141,   143,   144,   146,   147,   149,   151,   159,
     160,   164,   165,   166,   169,   171,   173,   174,   176,   177,
     178,     4,     5,    99,   138,   140,    99,    99,     7,    99,
      99,    99,    10,    15,    20,    24,    99,    99,   170,    99,
      99,    99,     3,   157,    86,    87,    88,    89,    90,    91,
      92,    99,   156,    99,     7,     7,    28,     7,     0,     3,
      99,   100,   100,   142,   150,    99,    10,    20,    25,    27,
      32,   161,   163,    99,   161,   162,    99,   100,   168,    99,
      99,    99,    82,    83,    84,    99,   158,    99,   156,    99,
       6,    85,    99,   145,   148,   172,   176,    93,    99,     3,
     101,     4,    37,    39,    41,    42,    45,    47,    48,    51,
      52,    54,    55,    56,    57,    59,    64,    65,    66,    67,
      69,    76,   116,   117,   119,   120,   121,   122,   124,   125,
     126,   127,   130,   133,   134,   135,    93,   161,    93,   161,
      99,     3,   167,    99,   175,   154,   155,     3,   153,   153,
     135,   135,   168,    99,     3,    99,     3,     4,    11,    12,
      13,    35,    38,    43,    46,    49,    50,    53,    60,    61,
      62,    63,    70,    73,    95,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   113,   115,   115,   115,   115,
       3,    36,    99,   123,     4,    56,    68,   125,   115,   115,
     115,   118,   131,    34,   161,   161,   100,   100,     6,   152,
     153,     3,    93,    97,     3,    93,    74,    75,   112,    99,
       3,    94,    99,    99,    99,    99,    99,     3,   115,   115,
       3,   100,    71,    72,   112,   123,     4,     3,     4,   125,
     128,   100,   115,   134,     6,    93,    93,   153,    93,   152,
       3,     3,     3,   115,     3,    99,    96,   114,   115,     3,
     135,    77,     6,   153,   152,   115,   129,   132,    78,   135,
      78
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 172 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 3:
#line 173 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 4:
#line 177 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(1) - (1)]) ); }
    break;

  case 5:
#line 178 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(2) - (2)]) ); }
    break;

  case 6:
#line 179 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(3) - (3)]) ); }
    break;

  case 7:
#line 182 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(1) - (1)]) ); }
    break;

  case 8:
#line 183 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(2) - (2)]) ); }
    break;

  case 9:
#line 190 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_ahogado( tipojuego, NULL );
    }
    break;

  case 10:
#line 194 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_ahogado( tipojuego, (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 11:
#line 200 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_atacado( tipojuego, NULL );
    }
    break;

  case 12:
#line 206 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = CUALQUIERA;
            init_parameters(); 
    }
    break;

  case 13:
#line 211 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = PROPIO;
            init_parameters(); 
    }
    break;

  case 14:
#line 216 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = ENEMIGO;
            init_parameters(); 
    }
    break;

  case 15:
#line 225 "qgames_parser.y"
    { 
            int i;
            char* cas = NULL; char* color = NULL; char *tpieza = NULL;
            for( i = 0; i < qgz_param_count; i ++ ){
                if( NOT_FOUND != tipojuego_get_color( tipojuego, qgz_param_list[i].str ) ){
                    if( color ){ yyerror( "Color definido mas de una vez en cuentapiezas" ); YYERROR; }
                    color = qgz_param_list[i].str ;
                } else if( NOT_FOUND != tipojuego_get_casillero( tipojuego,  qgz_param_list[i].str ) ){
                    if( cas ) { yyerror( "Casillero definido mas de una vez en cuentapiezas" ); YYERROR; }
                    cas = qgz_param_list[i].str ;
                } else if( NOT_FOUND != tipojuego_get_tipopieza( tipojuego, qgz_param_list[i].str ) ){
                    if( tpieza ){ yyerror( "Tipo de pieza definida mas de una vez en cuentapiezas" ); YYERROR; }
                    tpieza = qgz_param_list[i].str;
                } else {
                    qgzprintf( "Elemento no reconocido %s", qgz_param_list[i].str );
                    yyerror( "Elemento no reconocido en cuentapiezas" ); YYERROR;
                }
            }
            tipojuego_code_cuenta_piezas( tipojuego, cas, (yyvsp[(1) - (2)]), color, tpieza );
    }
    break;

  case 16:
#line 245 "qgames_parser.y"
    {
            tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (2)]), NULL, NULL );
            tipojuego_code_op_equal( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 17:
#line 249 "qgames_parser.y"
    {
            tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, ENEMIGO, NULL, NULL );
            tipojuego_code_op_equal( tipojuego, (yyvsp[(3) - (3)]) );
    }
    break;

  case 18:
#line 253 "qgames_parser.y"
    {
            tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, ENEMIGO, NULL, NULL );
            tipojuego_code_op_equal( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 19:
#line 257 "qgames_parser.y"
    { 
            tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (1)]), NULL, NULL );
    }
    break;

  case 20:
#line 263 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_destino_ant( tipojuego, NULL );
    }
    break;

  case 21:
#line 267 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != tipojuego_get_casillero( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ){
                tipojuego_code_destino_ant( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
            } else {
                qgzprintf( "Debe ser un casillero %s", ((char*)(yyvsp[(2) - (2)])) );
                yyerror( "Debe ser un casillero");
                YYERROR;
            }
    }
    break;

  case 22:
#line 277 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_origen_ant( tipojuego, NULL );
    }
    break;

  case 23:
#line 281 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != tipojuego_get_casillero( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ){
                tipojuego_code_origen_ant( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
            } else {
                qgzprintf( "Debe ser un casillero %s", ((char*)(yyvsp[(2) - (2)])) );
                yyerror( "Debe ser un casillero");
                YYERROR;
            }
    }
    break;

  case 24:
#line 296 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_entablero( tipojuego );
    }
    break;

  case 25:
#line 302 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            char*  zona = NULL;
            char*  tpieza = NULL;
            if( NOT_FOUND != tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (3)])) ) ){
                tpieza = ((char*)(yyvsp[(2) - (3)]));
            } else if( NOT_FOUND != tipojuego_get_zona( tipojuego, ((char*)(yyvsp[(2) - (3)])) ) ) {
                zona  = ((char*)(yyvsp[(2) - (3)]));
            } else {
                qgzprintf( "%s debe ser un tipo de pieza o una zona", ((char*)(yyvsp[(2) - (3)]) ) );
                yyerror( "Instruccion enzona mal formada" );
            }

            if( tpieza && ( NOT_FOUND != tipojuego_get_zona( tipojuego, ((char*)(yyvsp[(3) - (3)]))  ) ) ){
                zona  = ((char*)(yyvsp[(3) - (3)]));
            } 
            if( zona && ( NOT_FOUND != tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(3) - (3)])) ) ) ){
                tpieza = ((char*)(yyvsp[(3) - (3)]));
            }
            if( !zona || !tpieza ){
                yyerror( "Instruccion enzona mal formada" );
            }
            tipojuego_code_enzona( tipojuego, zona, tpieza );
    }
    break;

  case 26:
#line 326 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != tipojuego_get_zona( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ) {
                tipojuego_code_enzona( tipojuego, (char*)(yyvsp[(2) - (2)]), NULL );
            } else { 
                qgzprintf( "%s debe ser una zona", ((char*)(yyvsp[(2) - (2)]) ) );
                yyerror( "Instruccion enzona mal formada" );
            }
    }
    break;

  case 27:
#line 337 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ){
                tipojuego_code_jaquemate( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
            } else {
                qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (2)])) );
                yyerror( "Debe ser un tipo de pieza" );
            }
            free( (void*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 28:
#line 350 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL, NULL );
    }
    break;

  case 29:
#line 354 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, PROPIO, NULL, NULL );
    }
    break;

  case 30:
#line 358 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, ENEMIGO, NULL, NULL );
    }
    break;

  case 31:
#line 362 "qgames_parser.y"
    {
        char* nombre = (char*)(yyvsp[(2) - (2)]);
        CHECK_TIPOJUEGO;
        if( tipojuego_get_casillero( tipojuego, nombre ) != NOT_FOUND ){
             tipojuego_code_ocupado( tipojuego, nombre, CUALQUIERA, NULL, NULL );
        } else if( tipojuego_get_color( tipojuego, nombre ) != NOT_FOUND ){
             tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, nombre, NULL );
        } else if( tipojuego_get_tipopieza( tipojuego, nombre ) != NOT_FOUND ){
             tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL, nombre );
        } else {
            yyerror( "Ocupado?" );
            YYERROR;
        }
        free( (void*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 32:
#line 380 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_op_false( tipojuego );
        NOT_IMPLEMENTED_WARN( "repite-posicion" );
    }
    break;

  case 35:
#line 391 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_not( tipojuego );
    }
    break;

  case 36:
#line 395 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 37:
#line 398 "qgames_parser.y"
    { 
                tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 38:
#line 401 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 39:
#line 403 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(3) - (3)]) );
    }
    break;

  case 40:
#line 407 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(1) - (3)]) );
    }
    break;

  case 52:
#line 425 "qgames_parser.y"
    {    
            CHECK_TIPOJUEGO;
            /* una direccion podria ser */
            if( tipojuego_get_direccion( tipojuego, (char*)(yyvsp[(1) - (1)]) ) != NOT_FOUND ){
                    qgzprintf( "Direccion %s no esperada", (char*)(yyvsp[(1) - (1)]) );
                    yyerror( "Direccion no esperada" );
                    YYERROR;
            } else {
                if( tipojuego_get_casillero( tipojuego, (char*)(yyvsp[(1) - (1)]) ) != NOT_FOUND ){
                    qgzprintf( "Casillero %s no esperado", (char*)(yyvsp[(1) - (1)]) );
                    yyerror( "Casillero no esperado" );
                    YYERROR;
                } else if( tipojuego_get_att( tipojuego, last_pieza, (char*)(yyvsp[(1) - (1)]) ) != NOT_FOUND ) {
                      tipojuego_code_evalua_att( tipojuego, (char*)(yyvsp[(1) - (1)]) );
                } else {
                   int  len = strlen( (char*)(yyvsp[(1) - (1)]) );
                   int  hay_algo = 0;
                   if( len > 0 && ((char*)((yyvsp[(1) - (1)])))[len-1] == '?' ){
                      char* sin_pregunta = strdup( (char*) (yyvsp[(1) - (1)]) );
                      sin_pregunta[len-1] = 0;
                      if( tipojuego_get_att( tipojuego, last_pieza, sin_pregunta ) != NOT_FOUND ){
                          hay_algo = 1;
                          tipojuego_code_evalua_att( tipojuego, sin_pregunta );
                      }
                      free(sin_pregunta);
                  }

                  if( !hay_algo ){
                    qgzprintf( "%s no es nada", (char*)(yyvsp[(1) - (1)]) );
                    yyerror( "Comando no reconocido" );
                    YYERROR;
                  }
                }
            }
    }
    break;

  case 53:
#line 463 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, EMPATA );
    }
    break;

  case 54:
#line 467 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, EMPATA );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 55:
#line 473 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, GANA );
    }
    break;

  case 56:
#line 477 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, GANA );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 57:
#line 483 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, PIERDE );
    }
    break;

  case 58:
#line 487 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, PIERDE );
            tipojuego_code_end_condblock( tipojuego );
     }
    break;

  case 59:
#line 497 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_casillero( tipojuego, NULL );
    }
    break;

  case 60:
#line 501 "qgames_parser.y"
    {  CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 61:
#line 501 "qgames_parser.y"
    {
                    int    i;
                    char*  color = NULL;
                    for( i = 0; i < qgz_param_count; i ++ ){
                        int x = tipojuego_get_color( tipojuego, qgz_param_list[i].str );
                        if( x != NOT_FOUND ){
                            color = qgz_param_list[i].str;
                            break;
                        }
                    }
                    for( i = 0; i < qgz_param_count; i ++ ){
                        if( NOT_FOUND != tipojuego_get_tipopieza( tipojuego, qgz_param_list[i].str ) ){
                            qgzprintf( "Se va a transformar a %s %s", qgz_param_list[i].str, color );
                            tipojuego_code_transforma( tipojuego, NOCOLOR, color, qgz_param_list[i].str );
                        } else if ( NOT_FOUND != tipojuego_get_color( tipojuego, qgz_param_list[i].str ) ){
                            qgzprintf( "Parametro incorrecto en transforma: %s", qgz_param_list[i].str ); 
                            yyerror( "Error de parametros en transforma, debe ser color o tipo de pieza" );
                        }
                    }
    }
    break;

  case 62:
#line 524 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) );
    }
    break;

  case 63:
#line 528 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]) );
    }
    break;

  case 64:
#line 536 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_juega( tipojuego, NULL, 0 );
    }
    break;

  case 65:
#line 540 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_juega( tipojuego, NULL, 1 );
    }
    break;

  case 66:
#line 544 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_juega( tipojuego, NULL, 0 );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 67:
#line 550 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_juega( tipojuego, NULL, 1 );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 68:
#line 556 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_captura( tipojuego, NULL );
    }
    break;

  case 69:
#line 563 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_para( tipojuego );
    }
    break;

  case 70:
#line 567 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_para( tipojuego );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 71:
#line 578 "qgames_parser.y"
    { 
                          CHECK_TIPOJUEGO;
                          if( NOT_FOUND == tipojuego_get_casillero( tipojuego, (char*)(yyvsp[(3) - (3)]) ) ){
                              qgzprintf( "%s debe ser un casillero", (char*)(yyvsp[(3) - (3)]) );
                              yyerror( "Debe ser un casillero" );
                              YYERROR;
                          } else {
                              tipojuego_code_mueve( tipojuego, FROM_AQUI | TO_CASILLERO, 0, (char*)(yyvsp[(3) - (3)]) );
                          }
     }
    break;

  case 72:
#line 588 "qgames_parser.y"
    { 
                          CHECK_TIPOJUEGO;
                          tipojuego_code_mueve( tipojuego, FROM_AQUI | TO_MARCA, 0, (void*)(yyvsp[(3) - (3)]) );
     }
    break;

  case 73:
#line 592 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve cas  => casillero" ); }
    break;

  case 74:
#line 593 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve      => marca" ); }
    break;

  case 75:
#line 600 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 76:
#line 601 "qgames_parser.y"
    {
                          CHECK_TIPOJUEGO;
                          if( NOT_FOUND == tipojuego_get_casillero( tipojuego, (char*)(yyvsp[(1) - (1)]) ) ){
                              qgzprintf( "%s debe ser un casillero", (char*)(yyvsp[(1) - (1)]) );
                              yyerror( "Debe ser un casillero" );
                              YYERROR;
                          } else {
                              (yyval) = (yyvsp[(1) - (1)]);
                          }
    }
    break;

  case 77:
#line 614 "qgames_parser.y"
    { 
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_setmarca( tipojuego, (yyvsp[(2) - (3)]), (char*)(yyvsp[(3) - (3)]) );
    }
    break;

  case 78:
#line 618 "qgames_parser.y"
    { 
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_setmarca( tipojuego,  0, (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 79:
#line 625 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 80:
#line 626 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 81:
#line 630 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "marca" ); }
    break;

  case 82:
#line 639 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 83:
#line 642 "qgames_parser.y"
    {
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 85:
#line 647 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            (yyval) = tipojuego_code_start_block( tipojuego );
    }
    break;

  case 86:
#line 650 "qgames_parser.y"
    {
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 87:
#line 652 "qgames_parser.y"
    {
            tipojuego_code_continue_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_else_condblock( tipojuego );
            tipojuego_code_break_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_end_condblock( tipojuego );
            tipojuego_code_end_block( tipojuego, (yyvsp[(2) - (7)]) );
    }
    break;

  case 98:
#line 672 "qgames_parser.y"
    {   
            CHECK_TIPOJUEGO;
            /* una direccion podria ser */
            // qgzprintf( "Reconociendo %s", (char*)$1 );
            if( tipojuego_get_direccion( tipojuego, (char*)(yyvsp[(1) - (1)]) ) != NOT_FOUND ){
                    tipojuego_code_direccion( tipojuego, (char*)(yyvsp[(1) - (1)]) );
            } else if( tipojuego_get_casillero( tipojuego, (char*)(yyvsp[(1) - (1)]) ) != NOT_FOUND ){
                    tipojuego_code_casillero( tipojuego, (char*)(yyvsp[(1) - (1)]) );
            } else {
                    qgzprintf( "%s no es nada", (char*)(yyvsp[(1) - (1)]) );
                    yyerror( "Comando no reconocido" );
                    YYERROR;
            }
    }
    break;

  case 103:
#line 707 "qgames_parser.y"
    {  CHECK_TIPOJUEGO ;
                      CHECK_LAST_PIEZA;
                      tipojuego_add_tpieza_att( tipojuego, last_pieza, ((char*)(yyvsp[(2) - (3)])), (yyvsp[(3) - (3)]) );
                    }
    break;

  case 104:
#line 716 "qgames_parser.y"
    { CHECK_TIPOJUEGO; 
                     init_parameters(); }
    break;

  case 105:
#line 719 "qgames_parser.y"
    {
                     char*  dims[MAX_PARAMS]; int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                        dims[i] = ((char*)qgz_param_list[i].par);
                      }
                     tipojuego_genera_dimensiones( tipojuego, qgz_param_count, dims );
                   }
    break;

  case 106:
#line 728 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 107:
#line 729 "qgames_parser.y"
    { int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                       char* col = ((char*)qgz_param_list[i].par);
                       tipojuego_add_color( tipojuego, col );
                     }
                   }
    break;

  case 108:
#line 738 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 109:
#line 739 "qgames_parser.y"
    {
                      int  dirs[MAX_PARAMS]; int i; 
                      tipojuego_add_direccion( tipojuego, ((char*)(yyvsp[(2) - (4)])) );
                      for( i = 0; i < qgz_param_count; i ++ ){
                          dirs[i] = qgz_param_list[i].par;
                      }
                      tipojuego_add_direccion_arr( tipojuego, ((char*)(yyvsp[(2) - (4)])), dirs );
                    }
    break;

  case 110:
#line 749 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 111:
#line 750 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 112:
#line 753 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, DROP, last_pieza, (char*)((yyvsp[(1) - (2)])) );
    }
    break;

  case 113:
#line 758 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 114:
#line 764 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 115:
#line 765 "qgames_parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 116:
#line 769 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, MOVE, last_pieza, (char*)((yyvsp[(1) - (2)])) );
    }
    break;

  case 117:
#line 774 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 118:
#line 781 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO; 
            change_to_code_mode(); 
            tipojuego_start_codeend( tipojuego );
    }
    break;

  case 119:
#line 785 "qgames_parser.y"
    {
            tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 120:
#line 790 "qgames_parser.y"
    { 
        if( tipojuego ){
            yyerror( "Ya fue definido el tipo juego" );
            YYERROR;
        } else {
            tipojuego = tipojuego_new( ((char*)(yyvsp[(2) - (2)])) );
            free((void*)(yyvsp[(2) - (2)]));
        }
    }
    break;

  case 121:
#line 804 "qgames_parser.y"
    { html_color1 = (yyvsp[(1) - (3)]); html_color2 = (yyvsp[(3) - (3)]); }
    break;

  case 122:
#line 805 "qgames_parser.y"
    { html_color1 = (yyvsp[(1) - (2)]); html_color2 = (yyvsp[(2) - (2)]);
                                      qgzprintf( "Frente: %x Fondo: %x", html_color1, html_color2 ); }
    break;

  case 123:
#line 809 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (3)]); graph_dim2 = (yyvsp[(3) - (3)]); }
    break;

  case 124:
#line 810 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (3)]); graph_dim2 = (yyvsp[(3) - (3)]); }
    break;

  case 125:
#line 811 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (2)]); graph_dim2 = (yyvsp[(2) - (2)]); qgzprintf( "%dx%d", (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]) ); }
    break;

  case 126:
#line 814 "qgames_parser.y"
    { graph_dim1 = 0; graph_dim2 = 0; html_color1 = 0; html_color2 = 0; }
    break;

  case 131:
#line 823 "qgames_parser.y"
    { (yyval) = STANDARD_GEM; }
    break;

  case 132:
#line 824 "qgames_parser.y"
    { (yyval) = STANDARD_BISHOP; }
    break;

  case 133:
#line 825 "qgames_parser.y"
    { (yyval) = STANDARD_KING; }
    break;

  case 134:
#line 826 "qgames_parser.y"
    { (yyval) = STANDARD_KNIGHT; }
    break;

  case 135:
#line 827 "qgames_parser.y"
    { (yyval) = STANDARD_PAWN; }
    break;

  case 136:
#line 828 "qgames_parser.y"
    { (yyval) = STANDARD_QUEEN ; }
    break;

  case 137:
#line 829 "qgames_parser.y"
    { (yyval) = STANDARD_ROOK; }
    break;

  case 138:
#line 832 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); 
                  qgzprintf( "Tablero %d", (yyvsp[(1) - (1)]) ); }
    break;

  case 139:
#line 834 "qgames_parser.y"
    { (yyval) = BOARD_ACTUAL; qgzprintf( "Tablero actual" ); }
    break;

  case 140:
#line 837 "qgames_parser.y"
    { (yyval) = TYPE_CHECKERBOARD; }
    break;

  case 141:
#line 838 "qgames_parser.y"
    { (yyval) = TYPE_GRID; }
    break;

  case 142:
#line 839 "qgames_parser.y"
    { (yyval) = TYPE_INTERSECTIONS; }
    break;

  case 143:
#line 842 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        tipojuego_graph_tablero_std( tipojuego, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), graph_dim1, graph_dim2, html_color1, html_color2 );
     }
    break;

  case 144:
#line 846 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-board file" ) }
    break;

  case 145:
#line 847 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(3) - (4)])) ) == NOT_FOUND ){ 
            qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(3) - (4)])) );
            yyerror( "Debe ser un tipo de pieza" ); YYERROR;
        }
        tipojuego_graph_tipopieza_std( tipojuego, ((char*)(yyvsp[(3) - (4)])), (yyvsp[(2) - (4)]), graph_dim1, graph_dim2 );
    }
    break;

  case 146:
#line 855 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (4)])) ) == NOT_FOUND ){ 
            qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (4)])) );
            yyerror( "Debe ser un tipo de pieza" ); YYERROR;
        }
        tipojuego_graph_tipopieza_std( tipojuego, ((char*)(yyvsp[(2) - (4)])), (yyvsp[(3) - (4)]), graph_dim1, graph_dim2 );
    }
    break;

  case 147:
#line 863 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-piece string" ); }
    break;

  case 148:
#line 864 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square file" ); }
    break;

  case 149:
#line 865 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square color" ); }
    break;

  case 150:
#line 866 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square highlighted" ); }
    break;

  case 151:
#line 875 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        qgzprintf( "Definiendo %s", ((char*)(yyvsp[(2) - (2)])) );
        tipojuego_add_tipo_mov( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
        free((void*)(yyvsp[(2) - (2)]));
    }
    break;

  case 152:
#line 883 "qgames_parser.y"
    { (yyval) =  NOTACION_PIEZA; }
    break;

  case 153:
#line 884 "qgames_parser.y"
    { (yyval) =  NOTACION_ORIGEN; }
    break;

  case 154:
#line 885 "qgames_parser.y"
    { (yyval) =  NOTACION_DESTINO; }
    break;

  case 155:
#line 886 "qgames_parser.y"
    { (yyval) =  NOTACION_MARCA ; }
    break;

  case 156:
#line 887 "qgames_parser.y"
    { (yyval) =  NOTACION_CAPTURA; }
    break;

  case 157:
#line 890 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 158:
#line 891 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 159:
#line 892 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 160:
#line 895 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 161:
#line 896 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 162:
#line 897 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 163:
#line 901 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        if( NOT_FOUND != tipojuego_get_tipopieza( tipojuego, (char*)(yyvsp[(2) - (3)]) ) ){
            tipojuego_add_notacion_tpieza( tipojuego, (char*)(yyvsp[(2) - (3)]), NULL, (char*)(yyvsp[(3) - (3)]) ) ;
        } else if ( NOT_FOUND != tipojuego_get_tipomov( tipojuego, (char*)(yyvsp[(2) - (3)]) ) ){
            tipojuego_add_notacion_tmov( tipojuego, (char*)(yyvsp[(2) - (3)]), (char*)(yyvsp[(3) - (3)]) ) ;
        } else {
            qgzprintf( "%s debe ser un tipo de pieza o un tipo de movimiento", (char*)(yyvsp[(2) - (3)]) );
            yyerror( "Notacion mal formada" );
            YYERROR;
        }
     }
    break;

  case 164:
#line 913 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        char* tpieza; char* color; char* abbr;
        if( NOT_FOUND != tipojuego_get_tipopieza( tipojuego, (char*)(yyvsp[(2) - (4)]) ) ){
            tpieza = (char*)(yyvsp[(2) - (4)]);
        } else {
            qgzprintf( "%s debe ser un tipo de pieza" );
            yyerror( "Notacion mal formada (tipo de pieza incorrecta)" );
            YYERROR;
        }
        if( NOT_FOUND != tipojuego_get_color( tipojuego, (char*)(yyvsp[(3) - (4)]) ) ){
            color = (char*)(yyvsp[(3) - (4)]);
            abbr  = (char*)(yyvsp[(4) - (4)]);
        } else if ( NOT_FOUND != tipojuego_get_color( tipojuego, (char*)(yyvsp[(4) - (4)]) ) ){
            color = (char*)(yyvsp[(4) - (4)]);
            abbr  = (char*)(yyvsp[(3) - (4)]);
        } else {
            qgzprintf( "%s debe ser un color",  (char*)(yyvsp[(3) - (4)]) );
            yyerror( "Notacion mal formada (color incorrecto)" );
            YYERROR;
        } 
        tipojuego_add_notacion_tpieza( tipojuego, tpieza, color, abbr ) ;
        free((void*)(yyvsp[(2) - (4)]));
        free((void*)(yyvsp[(3) - (4)]));
        free((void*)(yyvsp[(4) - (4)]));
    }
    break;

  case 165:
#line 939 "qgames_parser.y"
    { 
                  CHECK_TIPOJUEGO;
                  tipojuego_set_notacion_marca( tipojuego, (char*)(yyvsp[(3) - (3)]), NULL );
                  free((void*)(yyvsp[(3) - (3)]));
             }
    break;

  case 166:
#line 944 "qgames_parser.y"
    { 
                  CHECK_TIPOJUEGO;
                  tipojuego_set_notacion_marca( tipojuego, NULL, (char*)(yyvsp[(3) - (3)]) );
                  free((void*)(yyvsp[(3) - (3)]));
             }
    break;

  case 169:
#line 954 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO; 
        tipojuego_add_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ); 
        if( last_pieza ) free( last_pieza );
        last_pieza = strdup( ((char*)(yyvsp[(2) - (2)])) );
    }
    break;

  case 170:
#line 962 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < (yyvsp[(4) - (4)]); i ++ ){
          tipojuego_add_pieza( tipojuego, ((char*)(yyvsp[(2) - (4)])), CASILLERO_POZO, ((char*)(yyvsp[(3) - (4)])) );
        }
    }
    break;

  case 171:
#line 969 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 172:
#line 969 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < qgz_param_count; i ++ ){
          tipojuego_add_pieza( tipojuego, ((char*)(yyvsp[(2) - (5)])), (char*)qgz_param_list[i].par, ((char*)(yyvsp[(3) - (5)])) );
        }
    }
    break;

  case 173:
#line 978 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int  i;
        for( i = 0; i < qgz_param_count; i ++ ){
            char* val1 =  (char*)qgz_param_list[i].par;
            int  color = tipojuego_get_color( tipojuego, val1 );
            if( color && i < qgz_param_count - 1 ){
                char* val2 = (char*)qgz_param_list[i+1].par;
                int  tmov = tipojuego_get_tipomov( tipojuego, val2 );
                if( tmov != NOT_FOUND ){
                    tipojuego_add_secuencia( tipojuego, val1, val2 );
                    i ++;
                } else {
                    tipojuego_add_secuencia( tipojuego, val1, NULL );
                }
            } else tipojuego_add_secuencia( tipojuego, val1, NULL );
        } 
    }
    break;

  case 174:
#line 998 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 177:
#line 1002 "qgames_parser.y"
    {
        tipojuego_add_secuencia_rep( tipojuego );
    }
    break;

  case 179:
#line 1009 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        tipojuego_add_simetria( tipojuego, ((char*)(yyvsp[(2) - (4)])), (char*)(yyvsp[(3) - (4)]), (char*)(yyvsp[(4) - (4)]) );
    }
    break;

  case 180:
#line 1015 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 181:
#line 1015 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            char* color = (char*)(yyvsp[(3) - (5)]);
            char* zona  = (char*)(yyvsp[(2) - (5)]);
            if( tipojuego_get_zona( tipojuego, zona ) == NOT_FOUND ){
                qgzprintf( "Nueva zona %s para %s", zona, color );
                tipojuego_add_zona( tipojuego, zona );
            } else {
                qgzprintf( "Define zona %s para %s", zona, color );
            }

            int i;
            for( i = 0; i < qgz_param_count; i ++ ){
                tipojuego_add_cas_to_zona( tipojuego, (char*)qgz_param_list[i].par, color, zona );
            }
    }
    break;


/* Line 1267 of yacc.c.  */
#line 3144 "qgames_parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1064 "qgames_parser.y"


/*
 *
 * 
 * 
 */










int   qgz_parse( FILE* f, char* filename, int flags ){

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
    return 1;
}




/*
 * Agrega un parametro
 * */
void  add_parameter( int  type, long param ){
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

void  init_parameters(){ qgz_param_count = 0; }

/*
 * Estos son los analizadores. Ojo, son no reentrantes ... deberia 
 * yo manejar algun tipo de semaforo!
 * */
Tipojuego*  qgz_parse_filename( char* filename, int flags ){
    int  ret;
    ret = qgz_parse( NULL, filename, flags );
    return( ret ? tipojuego : NULL );
}

Tipojuego*  qgz_parse_file    ( FILE* file, int flags ){
    int  ret;
    ret = qgz_parse( file, NULL, flags );
    return( ret ? tipojuego : NULL );
}
Tipojuego*  qgz_parse_string  ( char* string, int flags ){
    fprintf( stderr, "qgz_parse_string no implementado\n" );
    exit( EXIT_FAILURE );
}


