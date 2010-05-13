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
     TOK_CASILLERO_INICIAL = 298,
     TOK_DESTINO_ANT = 299,
     TOK_EMPATA = 300,
     TOK_EMPATA_SI = 301,
     TOK_ENTABLERO = 302,
     TOK_ENZONA = 303,
     TOK_GANA = 304,
     TOK_GANA_SI = 305,
     TOK_JAQUEMATE = 306,
     TOK_JUEGA = 307,
     TOK_JUEGA_SI = 308,
     TOK_MARCA = 309,
     TOK_MUEVE = 310,
     TOK_MUEVE_SI = 311,
     TOK_IF = 312,
     TOK_OCUPADO = 313,
     TOK_OCUPADOENEMIGO = 314,
     TOK_OCUPADOPROPIO = 315,
     TOK_ORIGEN_ANT = 316,
     TOK_PARA = 317,
     TOK_PARA_SI = 318,
     TOK_PIERDE = 319,
     TOK_PIERDE_SI = 320,
     TOK_PIEZAS_EN_CAS = 321,
     TOK_TRANSFORMA = 322,
     TOK_REPITEPOS = 323,
     TOK_AND = 324,
     TOK_OR = 325,
     TOK_NOT = 326,
     TOK_EQUAL = 327,
     TOK_DEQUAL = 328,
     TOK_WHILE = 329,
     TOK_DO = 330,
     TOK_END = 331,
     TOK_GRAPH_BOARD = 332,
     TOK_GRAPH_PIECE = 333,
     TOK_GRAPH_SQUARE = 334,
     TOK_GRID = 335,
     TOK_CHECKERBOARD = 336,
     TOK_INTERSECTIONS = 337,
     TOK_HIGHLIGHTED = 338,
     TOK_STANDARD_GEM = 339,
     TOK_STANDARD_BISHOP = 340,
     TOK_STANDARD_KING = 341,
     TOK_STANDARD_KNIGHT = 342,
     TOK_STANDARD_PAWN = 343,
     TOK_STANDARD_QUEEN = 344,
     TOK_STANDARD_ROOK = 345
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
#define TOK_CASILLERO_INICIAL 298
#define TOK_DESTINO_ANT 299
#define TOK_EMPATA 300
#define TOK_EMPATA_SI 301
#define TOK_ENTABLERO 302
#define TOK_ENZONA 303
#define TOK_GANA 304
#define TOK_GANA_SI 305
#define TOK_JAQUEMATE 306
#define TOK_JUEGA 307
#define TOK_JUEGA_SI 308
#define TOK_MARCA 309
#define TOK_MUEVE 310
#define TOK_MUEVE_SI 311
#define TOK_IF 312
#define TOK_OCUPADO 313
#define TOK_OCUPADOENEMIGO 314
#define TOK_OCUPADOPROPIO 315
#define TOK_ORIGEN_ANT 316
#define TOK_PARA 317
#define TOK_PARA_SI 318
#define TOK_PIERDE 319
#define TOK_PIERDE_SI 320
#define TOK_PIEZAS_EN_CAS 321
#define TOK_TRANSFORMA 322
#define TOK_REPITEPOS 323
#define TOK_AND 324
#define TOK_OR 325
#define TOK_NOT 326
#define TOK_EQUAL 327
#define TOK_DEQUAL 328
#define TOK_WHILE 329
#define TOK_DO 330
#define TOK_END 331
#define TOK_GRAPH_BOARD 332
#define TOK_GRAPH_PIECE 333
#define TOK_GRAPH_SQUARE 334
#define TOK_GRID 335
#define TOK_CHECKERBOARD 336
#define TOK_INTERSECTIONS 337
#define TOK_HIGHLIGHTED 338
#define TOK_STANDARD_GEM 339
#define TOK_STANDARD_BISHOP 340
#define TOK_STANDARD_KING 341
#define TOK_STANDARD_KNIGHT 342
#define TOK_STANDARD_PAWN 343
#define TOK_STANDARD_QUEEN 344
#define TOK_STANDARD_ROOK 345




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
#line 381 "qgames_parser.c"

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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   313

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  198
/* YYNRULES -- Number of states.  */
#define YYNSTATES  284

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   345

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      92,    93,     2,     2,    91,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      94,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    16,    18,    21,
      23,    26,    28,    30,    32,    34,    37,    40,    42,    44,
      47,    49,    52,    54,    58,    61,    64,    66,    68,    70,
      73,    76,    78,    80,    83,    84,    89,    93,    97,   101,
     105,   107,   109,   111,   113,   115,   117,   119,   121,   123,
     125,   127,   129,   132,   134,   137,   139,   142,   144,   145,
     149,   153,   158,   160,   162,   165,   168,   170,   172,   175,
     179,   183,   187,   190,   192,   194,   198,   201,   204,   206,
     208,   209,   210,   217,   218,   219,   227,   229,   231,   233,
     235,   237,   239,   241,   243,   245,   247,   249,   251,   252,
     254,   258,   262,   263,   267,   268,   272,   273,   278,   280,
     283,   284,   289,   291,   294,   295,   300,   301,   306,   309,
     313,   316,   320,   324,   327,   328,   333,   337,   342,   346,
     348,   350,   352,   354,   356,   358,   360,   362,   363,   365,
     367,   369,   374,   378,   383,   387,   391,   395,   399,   402,
     404,   406,   408,   410,   412,   414,   417,   421,   423,   426,
     430,   434,   439,   443,   447,   451,   455,   458,   463,   464,
     470,   472,   473,   477,   479,   480,   485,   490,   491,   497,
     499,   501,   503,   505,   507,   509,   511,   513,   515,   517,
     519,   521,   523,   525,   527,   529,   530,   532,   536
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     175,     0,    -1,     4,    -1,     5,    -1,    96,    -1,    97,
      96,    -1,    97,    91,    96,    -1,     3,    -1,    98,     3,
      -1,    35,    -1,    35,    96,    -1,    38,    -1,    11,    -1,
      12,    -1,    13,    -1,   101,    97,    -1,   101,     3,    -1,
     101,    -1,    44,    -1,    44,    96,    -1,    61,    -1,    61,
      96,    -1,    47,    -1,    48,    96,    96,    -1,    48,    96,
      -1,    51,    96,    -1,    58,    -1,    60,    -1,    59,    -1,
      58,    96,    -1,    68,     3,    -1,    72,    -1,    73,    -1,
      71,   112,    -1,    -1,   112,    69,   111,   112,    -1,   112,
      70,   112,    -1,   112,   109,     3,    -1,     3,   109,   112,
      -1,    92,   112,    93,    -1,   110,    -1,    99,    -1,   100,
      -1,   102,    -1,   103,    -1,   104,    -1,   105,    -1,   106,
      -1,   107,    -1,   108,    -1,     4,    -1,    45,    -1,    46,
     112,    -1,    49,    -1,    50,   112,    -1,    64,    -1,    65,
     112,    -1,    43,    -1,    -1,    67,   115,    97,    -1,    37,
      96,     3,    -1,    37,    96,    91,     3,    -1,    52,    -1,
      41,    -1,    53,   112,    -1,    42,   112,    -1,    39,    -1,
      62,    -1,    63,   112,    -1,    55,    66,     4,    -1,    55,
      66,   122,    -1,    55,     4,     4,    -1,    55,   122,    -1,
      36,    -1,    96,    -1,    54,     3,   120,    -1,    54,   120,
      -1,    54,     3,    -1,    54,    -1,   122,    -1,    -1,    -1,
      57,   112,   125,   132,   126,    76,    -1,    -1,    -1,    74,
     128,   112,    75,   129,   132,    76,    -1,   116,    -1,   117,
      -1,   113,    -1,   124,    -1,   121,    -1,   123,    -1,   114,
      -1,   119,    -1,   118,    -1,   127,    -1,     4,    -1,   130,
      -1,    -1,   131,    -1,   132,    34,   131,    -1,     8,    96,
       3,    -1,    -1,     9,   135,    97,    -1,    -1,    14,   137,
      97,    -1,    -1,    16,    96,   139,    98,    -1,    17,    -1,
      17,    96,    -1,    -1,   140,     7,   142,   132,    -1,    21,
      -1,    21,    96,    -1,    -1,   143,     7,   145,   132,    -1,
      -1,    18,     7,   147,   132,    -1,    19,    96,    -1,     6,
      91,     6,    -1,     6,     6,    -1,     3,    91,     3,    -1,
       3,    94,     3,    -1,     3,     3,    -1,    -1,   151,   149,
      91,   150,    -1,   151,   149,   150,    -1,   151,   150,    91,
     149,    -1,   151,   150,   149,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,
       3,    -1,    -1,    81,    -1,    80,    -1,    82,    -1,    77,
     154,   155,   152,    -1,    77,   154,    96,    -1,    78,    96,
     153,   150,    -1,    78,    96,    96,    -1,    79,    96,    96,
      -1,    79,    96,     6,    -1,    79,    96,    83,    -1,    22,
      96,    -1,    27,    -1,    25,    -1,    32,    -1,    20,    -1,
      10,    -1,   158,    -1,   159,   158,    -1,   159,    91,   158,
      -1,   158,    -1,   160,   158,    -1,   160,    91,   158,    -1,
      23,    96,    96,    -1,    23,    96,    96,    96,    -1,    23,
      20,    96,    -1,    23,    10,    96,    -1,    23,    15,   160,
      -1,    23,    24,   159,    -1,    26,    96,    -1,    30,    96,
      96,     3,    -1,    -1,    30,    96,    96,   164,    97,    -1,
      97,    -1,    -1,    29,   167,   165,    -1,   166,    -1,    -1,
     166,    28,   169,   165,    -1,    31,    96,    96,    96,    -1,
      -1,    33,    96,    96,   172,    97,    -1,   133,    -1,   134,
      -1,   136,    -1,   138,    -1,   141,    -1,   146,    -1,   148,
      -1,   156,    -1,   144,    -1,   157,    -1,   161,    -1,   162,
      -1,   168,    -1,   163,    -1,   170,    -1,   171,    -1,    -1,
     173,    -1,   174,     7,   173,    -1,   174,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   171,   171,   172,   176,   177,   178,   181,   182,   189,
     193,   199,   205,   210,   215,   224,   244,   248,   254,   258,
     268,   272,   287,   293,   317,   328,   341,   345,   349,   353,
     371,   379,   379,   382,   386,   386,   392,   394,   398,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   454,   458,   464,   468,   474,   478,   488,   492,   492,
     515,   519,   527,   531,   535,   541,   547,   554,   558,   569,
     579,   583,   584,   591,   592,   605,   609,   616,   617,   621,
     630,   633,   630,   638,   641,   638,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   680,   680,   684,
     685,   697,   707,   707,   719,   719,   729,   729,   740,   741,
     744,   744,   755,   756,   760,   760,   772,   772,   781,   795,
     796,   799,   800,   801,   804,   807,   808,   809,   810,   813,
     814,   815,   816,   817,   818,   819,   822,   822,   825,   826,
     827,   830,   834,   835,   844,   845,   846,   847,   856,   864,
     865,   866,   867,   868,   871,   872,   873,   876,   877,   878,
     882,   894,   920,   925,   930,   931,   935,   943,   950,   950,
     959,   979,   979,   982,   983,   983,   990,   996,   996,  1014,
    1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,  1029,  1036,  1037,  1041
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
  "TOK_CAPTURA_Y_JUEGA", "TOK_CAPTURA_Y_JUEGA_SI", "TOK_CASILLERO_INICIAL",
  "TOK_DESTINO_ANT", "TOK_EMPATA", "TOK_EMPATA_SI", "TOK_ENTABLERO",
  "TOK_ENZONA", "TOK_GANA", "TOK_GANA_SI", "TOK_JAQUEMATE", "TOK_JUEGA",
  "TOK_JUEGA_SI", "TOK_MARCA", "TOK_MUEVE", "TOK_MUEVE_SI", "TOK_IF",
  "TOK_OCUPADO", "TOK_OCUPADOENEMIGO", "TOK_OCUPADOPROPIO",
  "TOK_ORIGEN_ANT", "TOK_PARA", "TOK_PARA_SI", "TOK_PIERDE",
  "TOK_PIERDE_SI", "TOK_PIEZAS_EN_CAS", "TOK_TRANSFORMA", "TOK_REPITEPOS",
  "TOK_AND", "TOK_OR", "TOK_NOT", "TOK_EQUAL", "TOK_DEQUAL", "TOK_WHILE",
  "TOK_DO", "TOK_END", "TOK_GRAPH_BOARD", "TOK_GRAPH_PIECE",
  "TOK_GRAPH_SQUARE", "TOK_GRID", "TOK_CHECKERBOARD", "TOK_INTERSECTIONS",
  "TOK_HIGHLIGHTED", "TOK_STANDARD_GEM", "TOK_STANDARD_BISHOP",
  "TOK_STANDARD_KING", "TOK_STANDARD_KNIGHT", "TOK_STANDARD_PAWN",
  "TOK_STANDARD_QUEEN", "TOK_STANDARD_ROOK", "','", "'('", "')'", "'x'",
  "$accept", "word_or_string", "word_or_string_list", "number_list",
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
     345,    44,    40,    41,   120
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    96,    97,    97,    97,    98,    98,    99,
      99,   100,   101,   101,   101,   102,   102,   102,   103,   103,
     103,   103,   104,   105,   105,   106,   107,   107,   107,   107,
     108,   109,   109,   110,   111,   110,   110,   110,   110,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   113,   113,   113,   113,   113,   113,   114,   115,   114,
     116,   116,   117,   117,   117,   117,   117,   118,   118,   119,
     119,   119,   119,   120,   120,   121,   121,   122,   122,   123,
     125,   126,   124,   128,   129,   127,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   131,   131,   132,
     132,   133,   135,   134,   137,   136,   139,   138,   140,   140,
     142,   141,   143,   143,   145,   144,   147,   146,   148,   149,
     149,   150,   150,   150,   151,   152,   152,   152,   152,   153,
     153,   153,   153,   153,   153,   153,   154,   154,   155,   155,
     155,   156,   156,   156,   156,   156,   156,   156,   157,   158,
     158,   158,   158,   158,   159,   159,   159,   160,   160,   160,
     161,   161,   161,   161,   161,   161,   162,   163,   164,   163,
     165,   167,   166,   168,   169,   168,   170,   172,   171,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   174,   174,   175
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     3,     1,     2,     1,
       2,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       1,     2,     1,     3,     2,     2,     1,     1,     1,     2,
       2,     1,     1,     2,     0,     4,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     2,     1,     0,     3,
       3,     4,     1,     1,     2,     2,     1,     1,     2,     3,
       3,     3,     2,     1,     1,     3,     2,     2,     1,     1,
       0,     0,     6,     0,     0,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       3,     3,     0,     3,     0,     3,     0,     4,     1,     2,
       0,     4,     1,     2,     0,     4,     0,     4,     2,     3,
       2,     3,     3,     2,     0,     4,     3,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     4,     3,     4,     3,     3,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     2,     3,
       3,     4,     3,     3,     3,     3,     2,     4,     0,     5,
       1,     0,     3,     1,     0,     4,     4,     0,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     195,     0,   102,   104,     0,   108,     0,     0,   112,     0,
       0,     0,   171,     0,     0,     0,   137,     0,     0,   179,
     180,   181,   182,     0,   183,     0,   187,   184,   185,   186,
     188,   189,   190,   192,   173,   191,   193,   194,   196,   198,
       0,     2,     3,     0,     0,     0,   106,   109,   116,   118,
     113,   148,     0,     0,     0,     0,     0,   166,     0,     0,
       0,     0,   136,     0,     0,     0,   110,   114,   174,   195,
       1,   101,     4,   103,   105,     0,    98,   163,   153,   152,
     150,   149,   151,   157,   164,   162,   154,   165,   160,   170,
     172,   168,     0,   177,   139,   138,   140,   142,   124,   129,
     130,   131,   132,   133,   134,   135,   144,     0,   146,   147,
     145,    98,    98,     0,   197,     0,     5,     7,   107,    96,
       0,    66,    63,     0,    57,    51,     0,    53,     0,    62,
       0,    78,     0,     0,    67,     0,    55,     0,    58,    83,
      88,    92,    86,    87,    94,    93,    90,    79,    91,    89,
      95,    97,    99,   117,     0,   158,     0,   155,   161,   167,
       0,   176,     0,     0,   141,     0,   143,   111,   115,   175,
       6,     8,     0,     0,    50,    12,    13,    14,     9,    11,
      18,    22,     0,     0,    26,    28,    27,    20,     0,     0,
       0,    41,    42,    17,    43,    44,    45,    46,    47,    48,
      49,    40,    65,    52,    54,    64,    77,    73,    74,    76,
       0,    78,     0,    72,    80,    68,    56,     0,     0,    98,
     159,   156,   169,   178,     0,     0,     0,   123,     0,     0,
      60,     0,    31,    32,     0,    10,    19,    24,    25,    29,
      21,    30,    33,     0,    16,    15,    34,     0,     0,    75,
      71,    77,    69,    70,    98,    59,     0,   100,   120,     0,
       0,   126,     0,   128,   121,   122,    61,    38,    23,    39,
       0,    36,    37,    81,    84,   119,   125,   127,    35,     0,
      98,    82,     0,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    72,    89,   118,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   248,   201,   270,   202,   140,   141,
     217,   142,   143,   144,   145,   209,   146,   147,   148,   149,
     254,   279,   150,   218,   280,   151,   152,   153,    19,    20,
      44,    21,    45,    22,    75,    23,    24,   111,    25,    26,
     112,    27,    76,    28,   225,   166,   163,   164,   107,    63,
      98,    29,    30,    83,    87,    84,    31,    32,    33,   160,
      90,    34,    58,    35,   113,    36,    37,   162,    38,    39,
      40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -194
static const yytype_int16 yypact[] =
{
     234,    52,  -194,  -194,    52,    52,    43,    52,    52,    52,
     170,    52,  -194,    52,    52,    52,    38,    52,    52,  -194,
    -194,  -194,  -194,    45,  -194,    54,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,    62,  -194,  -194,  -194,  -194,    82,
      48,  -194,  -194,    93,    52,    52,  -194,  -194,  -194,  -194,
    -194,  -194,    52,   106,    52,   106,    52,  -194,    52,    52,
      52,    52,  -194,    77,    61,    34,  -194,  -194,  -194,   234,
    -194,  -194,  -194,    31,    31,    97,   229,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,    22,  -194,  -194,   146,    52,    31,
    -194,    98,    52,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,   102,  -194,  -194,
    -194,   229,   229,    52,  -194,    52,  -194,  -194,   112,  -194,
      52,  -194,  -194,   149,  -194,  -194,   149,  -194,   149,  -194,
     149,    71,    26,   149,  -194,   149,  -194,   149,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,    89,   106,  -194,   106,  -194,  -194,  -194,
      52,  -194,    52,   118,  -194,     8,  -194,    89,    89,  -194,
    -194,  -194,    12,     6,  -194,  -194,  -194,  -194,    52,  -194,
      52,  -194,    52,    52,    52,  -194,  -194,    52,   122,   149,
     149,  -194,  -194,   208,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,    -2,    -2,    -2,    -2,    41,  -194,  -194,  -194,
     123,   126,    39,  -194,    -2,    -2,    -2,    52,   149,   229,
    -194,  -194,    31,    31,    19,    18,    20,  -194,   132,   134,
    -194,   136,  -194,  -194,   149,  -194,  -194,    52,  -194,  -194,
    -194,  -194,    -2,    25,  -194,    31,  -194,   149,   137,  -194,
    -194,  -194,  -194,  -194,   229,    31,   129,  -194,  -194,   148,
     102,  -194,   157,  -194,  -194,  -194,  -194,    -2,  -194,  -194,
     149,    -2,  -194,    89,  -194,  -194,  -194,  -194,    -2,    56,
     229,  -194,    10,  -194
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -194,    -1,   -26,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,   -31,  -194,  -194,  -106,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,   -63,  -194,  -104,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,   -64,  -110,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -193,  -140,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,   -50,  -194,  -194,  -194,  -194,  -194,  -194,
      55,  -194,  -194,  -194,  -194,  -194,  -194,  -194,    96,  -194,
    -194
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      43,   167,   168,    46,    47,    86,    49,    50,    51,    56,
      57,   227,    59,    60,    61,   230,    64,    65,    73,    74,
     203,   165,   204,   226,   205,   258,   224,   214,   213,   215,
     210,   216,    78,   263,   155,    41,    42,   157,    41,    42,
     108,    62,    79,   252,   219,    41,    42,    80,    70,    81,
      48,    77,    66,    85,    82,    88,    41,    42,    91,    92,
      93,    67,    97,   106,   110,    41,    42,   246,   247,   277,
     232,   233,   116,   116,   206,    41,    42,   207,   232,   233,
     211,    41,    42,   242,   243,   261,   283,   158,   116,    69,
      68,   161,   212,   211,   246,   247,    71,   232,   233,   228,
     117,   159,   229,   231,   220,   165,   221,   207,   253,   260,
     259,   262,   256,   154,   170,   171,    78,   109,   269,   172,
     276,   165,   115,   219,   224,   241,    79,   250,   267,   251,
     208,    80,   281,    81,   222,   264,   223,   265,    82,   266,
     272,   271,   234,   249,   273,    99,   100,   101,   102,   103,
     104,   105,   173,   174,   275,   257,    78,    94,    95,    96,
     175,   176,   177,   224,   278,   114,    79,   245,   169,     0,
     282,    80,     0,    81,    41,    42,     0,   235,    82,   236,
      52,   237,   238,   239,   178,    53,   240,   179,     0,     0,
      54,   255,     0,   180,    55,     0,   181,   182,   246,   247,
     183,   232,   233,     0,   274,   208,     0,   184,   185,   186,
     187,   244,    41,    42,     0,     0,     0,   188,     0,     0,
     189,   116,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,     0,     0,   268,   156,     0,     0,
       0,   190,     1,     2,   116,     0,     0,     0,     3,     0,
       4,     5,     6,     7,   116,     8,     9,    10,     0,     0,
      11,     0,     0,    12,    13,    14,   120,    15,   121,     0,
     122,   123,   124,     0,   125,   126,     0,     0,   127,   128,
       0,   129,   130,   131,   132,     0,   133,     0,     0,     0,
       0,   134,   135,   136,   137,     0,   138,     0,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    18
};

static const yytype_int16 yycheck[] =
{
       1,   111,   112,     4,     5,    55,     7,     8,     9,    10,
      11,     3,    13,    14,    15,     3,    17,    18,    44,    45,
     126,     3,   128,   163,   130,     6,     6,   133,   132,   135,
       4,   137,    10,   226,    84,     4,     5,    87,     4,     5,
       6,     3,    20,     4,    34,     4,     5,    25,     0,    27,
       7,    52,     7,    54,    32,    56,     4,     5,    59,    60,
      61,     7,    63,    64,    65,     4,     5,    69,    70,   262,
      72,    73,    73,    74,     3,     4,     5,    36,    72,    73,
      54,     4,     5,   189,   190,   225,    76,    88,    89,     7,
      28,    92,    66,    54,    69,    70,     3,    72,    73,    91,
       3,     3,    94,    91,   154,     3,   156,    36,   212,    91,
      91,    91,   218,    91,   115,     3,    10,    83,    93,   120,
     260,     3,    91,    34,     6,     3,    20,     4,   234,     3,
     131,    25,    76,    27,   160,     3,   162,     3,    32,     3,
       3,   247,   173,   206,   254,    84,    85,    86,    87,    88,
      89,    90,     3,     4,     6,   219,    10,    80,    81,    82,
      11,    12,    13,     6,   270,    69,    20,   193,   113,    -1,
     280,    25,    -1,    27,     4,     5,    -1,   178,    32,   180,
      10,   182,   183,   184,    35,    15,   187,    38,    -1,    -1,
      20,   217,    -1,    44,    24,    -1,    47,    48,    69,    70,
      51,    72,    73,    -1,    75,   206,    -1,    58,    59,    60,
      61,     3,     4,     5,    -1,    -1,    -1,    68,    -1,    -1,
      71,   222,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,    -1,    -1,   237,    91,    -1,    -1,
      -1,    92,     8,     9,   245,    -1,    -1,    -1,    14,    -1,
      16,    17,    18,    19,   255,    21,    22,    23,    -1,    -1,
      26,    -1,    -1,    29,    30,    31,    37,    33,    39,    -1,
      41,    42,    43,    -1,    45,    46,    -1,    -1,    49,    50,
      -1,    52,    53,    54,    55,    -1,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    14,    16,    17,    18,    19,    21,    22,
      23,    26,    29,    30,    31,    33,    77,    78,    79,   133,
     134,   136,   138,   140,   141,   143,   144,   146,   148,   156,
     157,   161,   162,   163,   166,   168,   170,   171,   173,   174,
     175,     4,     5,    96,   135,   137,    96,    96,     7,    96,
      96,    96,    10,    15,    20,    24,    96,    96,   167,    96,
      96,    96,     3,   154,    96,    96,     7,     7,    28,     7,
       0,     3,    96,    97,    97,   139,   147,    96,    10,    20,
      25,    27,    32,   158,   160,    96,   158,   159,    96,    97,
     165,    96,    96,    96,    80,    81,    82,    96,   155,    84,
      85,    86,    87,    88,    89,    90,    96,   153,     6,    83,
      96,   142,   145,   169,   173,    91,    96,     3,    98,     4,
      37,    39,    41,    42,    43,    45,    46,    49,    50,    52,
      53,    54,    55,    57,    62,    63,    64,    65,    67,    74,
     113,   114,   116,   117,   118,   119,   121,   122,   123,   124,
     127,   130,   131,   132,    91,   158,    91,   158,    96,     3,
     164,    96,   172,   151,   152,     3,   150,   132,   132,   165,
      96,     3,    96,     3,     4,    11,    12,    13,    35,    38,
      44,    47,    48,    51,    58,    59,    60,    61,    68,    71,
      92,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   110,   112,   112,   112,   112,     3,    36,    96,   120,
       4,    54,    66,   122,   112,   112,   112,   115,   128,    34,
     158,   158,    97,    97,     6,   149,   150,     3,    91,    94,
       3,    91,    72,    73,   109,    96,    96,    96,    96,    96,
      96,     3,   112,   112,     3,    97,    69,    70,   109,   120,
       4,     3,     4,   122,   125,    97,   112,   131,     6,    91,
      91,   150,    91,   149,     3,     3,     3,   112,    96,    93,
     111,   112,     3,   132,    75,     6,   150,   149,   112,   126,
     129,    76,   132,    76
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
#line 171 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 3:
#line 172 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 4:
#line 176 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(1) - (1)]) ); }
    break;

  case 5:
#line 177 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(2) - (2)]) ); }
    break;

  case 6:
#line 178 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(3) - (3)]) ); }
    break;

  case 7:
#line 181 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(1) - (1)]) ); }
    break;

  case 8:
#line 182 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(2) - (2)]) ); }
    break;

  case 9:
#line 189 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_ahogado( tipojuego, NULL );
    }
    break;

  case 10:
#line 193 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_ahogado( tipojuego, (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 11:
#line 199 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_atacado( tipojuego, NULL );
    }
    break;

  case 12:
#line 205 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = CUALQUIERA;
            init_parameters(); 
    }
    break;

  case 13:
#line 210 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = PROPIO;
            init_parameters(); 
    }
    break;

  case 14:
#line 215 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = ENEMIGO;
            init_parameters(); 
    }
    break;

  case 15:
#line 224 "qgames_parser.y"
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
#line 244 "qgames_parser.y"
    {
            tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (2)]), NULL, NULL );
            tipojuego_code_op_equal( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 17:
#line 248 "qgames_parser.y"
    { 
            tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (1)]), NULL, NULL );
    }
    break;

  case 18:
#line 254 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_destino_ant( tipojuego, NULL );
    }
    break;

  case 19:
#line 258 "qgames_parser.y"
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

  case 20:
#line 268 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_origen_ant( tipojuego, NULL );
    }
    break;

  case 21:
#line 272 "qgames_parser.y"
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

  case 22:
#line 287 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_entablero( tipojuego );
    }
    break;

  case 23:
#line 293 "qgames_parser.y"
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

  case 24:
#line 317 "qgames_parser.y"
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

  case 25:
#line 328 "qgames_parser.y"
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

  case 26:
#line 341 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL, NULL );
    }
    break;

  case 27:
#line 345 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, PROPIO, NULL, NULL );
    }
    break;

  case 28:
#line 349 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, ENEMIGO, NULL, NULL );
    }
    break;

  case 29:
#line 353 "qgames_parser.y"
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

  case 30:
#line 371 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_op_false( tipojuego );
        NOT_IMPLEMENTED_WARN( "repite-posicion" );
    }
    break;

  case 33:
#line 382 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_not( tipojuego );
    }
    break;

  case 34:
#line 386 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 35:
#line 389 "qgames_parser.y"
    { 
                tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 36:
#line 392 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 37:
#line 394 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(3) - (3)]) );
    }
    break;

  case 38:
#line 398 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(1) - (3)]) );
    }
    break;

  case 50:
#line 416 "qgames_parser.y"
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

  case 51:
#line 454 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, EMPATA );
    }
    break;

  case 52:
#line 458 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, EMPATA );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 53:
#line 464 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, GANA );
    }
    break;

  case 54:
#line 468 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, GANA );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 55:
#line 474 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, PIERDE );
    }
    break;

  case 56:
#line 478 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, PIERDE );
            tipojuego_code_end_condblock( tipojuego );
     }
    break;

  case 57:
#line 488 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_casillero( tipojuego, NULL );
    }
    break;

  case 58:
#line 492 "qgames_parser.y"
    {  CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 59:
#line 492 "qgames_parser.y"
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

  case 60:
#line 515 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) );
    }
    break;

  case 61:
#line 519 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]) );
    }
    break;

  case 62:
#line 527 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_juega( tipojuego, NULL, 0 );
    }
    break;

  case 63:
#line 531 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_juega( tipojuego, NULL, 1 );
    }
    break;

  case 64:
#line 535 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_juega( tipojuego, NULL, 0 );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 65:
#line 541 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_juega( tipojuego, NULL, 1 );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 66:
#line 547 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_captura( tipojuego, NULL );
    }
    break;

  case 67:
#line 554 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_para( tipojuego );
    }
    break;

  case 68:
#line 558 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_para( tipojuego );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 69:
#line 569 "qgames_parser.y"
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

  case 70:
#line 579 "qgames_parser.y"
    { 
                          CHECK_TIPOJUEGO;
                          tipojuego_code_mueve( tipojuego, FROM_AQUI | TO_MARCA, 0, (void*)(yyvsp[(3) - (3)]) );
     }
    break;

  case 71:
#line 583 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve cas  => casillero" ); }
    break;

  case 72:
#line 584 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve      => marca" ); }
    break;

  case 73:
#line 591 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 74:
#line 592 "qgames_parser.y"
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

  case 75:
#line 605 "qgames_parser.y"
    { 
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_setmarca( tipojuego, (yyvsp[(2) - (3)]), (char*)(yyvsp[(3) - (3)]) );
    }
    break;

  case 76:
#line 609 "qgames_parser.y"
    { 
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_setmarca( tipojuego,  0, (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 77:
#line 616 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 78:
#line 617 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 79:
#line 621 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "marca" ); }
    break;

  case 80:
#line 630 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 81:
#line 633 "qgames_parser.y"
    {
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 83:
#line 638 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            (yyval) = tipojuego_code_start_block( tipojuego );
    }
    break;

  case 84:
#line 641 "qgames_parser.y"
    {
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 85:
#line 643 "qgames_parser.y"
    {
            tipojuego_code_continue_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_else_condblock( tipojuego );
            tipojuego_code_break_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_end_condblock( tipojuego );
            tipojuego_code_end_block( tipojuego, (yyvsp[(2) - (7)]) );
    }
    break;

  case 96:
#line 663 "qgames_parser.y"
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

  case 101:
#line 698 "qgames_parser.y"
    {  CHECK_TIPOJUEGO ;
                      CHECK_LAST_PIEZA;
                      tipojuego_add_tpieza_att( tipojuego, last_pieza, ((char*)(yyvsp[(2) - (3)])), (yyvsp[(3) - (3)]) );
                    }
    break;

  case 102:
#line 707 "qgames_parser.y"
    { CHECK_TIPOJUEGO; 
                     init_parameters(); }
    break;

  case 103:
#line 710 "qgames_parser.y"
    {
                     char*  dims[MAX_PARAMS]; int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                        dims[i] = ((char*)qgz_param_list[i].par);
                      }
                     tipojuego_genera_dimensiones( tipojuego, qgz_param_count, dims );
                   }
    break;

  case 104:
#line 719 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 105:
#line 720 "qgames_parser.y"
    { int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                       char* col = ((char*)qgz_param_list[i].par);
                       tipojuego_add_color( tipojuego, col );
                     }
                   }
    break;

  case 106:
#line 729 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 107:
#line 730 "qgames_parser.y"
    {
                      int  dirs[MAX_PARAMS]; int i; 
                      tipojuego_add_direccion( tipojuego, ((char*)(yyvsp[(2) - (4)])) );
                      for( i = 0; i < qgz_param_count; i ++ ){
                          dirs[i] = qgz_param_list[i].par;
                      }
                      tipojuego_add_direccion_arr( tipojuego, ((char*)(yyvsp[(2) - (4)])), dirs );
                    }
    break;

  case 108:
#line 740 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 109:
#line 741 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 110:
#line 744 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, DROP, last_pieza, (char*)((yyvsp[(1) - (2)])) );
    }
    break;

  case 111:
#line 749 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 112:
#line 755 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 113:
#line 756 "qgames_parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 114:
#line 760 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, MOVE, last_pieza, (char*)((yyvsp[(1) - (2)])) );
    }
    break;

  case 115:
#line 765 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 116:
#line 772 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO; 
            change_to_code_mode(); 
            tipojuego_start_codeend( tipojuego );
    }
    break;

  case 117:
#line 776 "qgames_parser.y"
    {
            tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 118:
#line 781 "qgames_parser.y"
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

  case 119:
#line 795 "qgames_parser.y"
    { html_color1 = (yyvsp[(1) - (3)]); html_color2 = (yyvsp[(3) - (3)]); }
    break;

  case 120:
#line 796 "qgames_parser.y"
    { html_color1 = (yyvsp[(1) - (2)]); html_color2 = (yyvsp[(2) - (2)]); }
    break;

  case 121:
#line 799 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (3)]); graph_dim2 = (yyvsp[(3) - (3)]); }
    break;

  case 122:
#line 800 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (3)]); graph_dim2 = (yyvsp[(3) - (3)]); }
    break;

  case 123:
#line 801 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (2)]); graph_dim2 = (yyvsp[(2) - (2)]); }
    break;

  case 124:
#line 804 "qgames_parser.y"
    { graph_dim1 = 0; graph_dim2 = 0; html_color1 = 0; html_color2 = 0; }
    break;

  case 129:
#line 813 "qgames_parser.y"
    { (yyval) = STANDARD_GEM; }
    break;

  case 130:
#line 814 "qgames_parser.y"
    { (yyval) = STANDARD_BISHOP; }
    break;

  case 131:
#line 815 "qgames_parser.y"
    { (yyval) = STANDARD_KING; }
    break;

  case 132:
#line 816 "qgames_parser.y"
    { (yyval) = STANDARD_KNIGHT; }
    break;

  case 133:
#line 817 "qgames_parser.y"
    { (yyval) = STANDARD_PAWN; }
    break;

  case 134:
#line 818 "qgames_parser.y"
    { (yyval) = STANDARD_QUEEN ; }
    break;

  case 135:
#line 819 "qgames_parser.y"
    { (yyval) = STANDARD_ROOK; }
    break;

  case 136:
#line 822 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 137:
#line 822 "qgames_parser.y"
    { (yyval) = BOARD_ACTUAL; }
    break;

  case 138:
#line 825 "qgames_parser.y"
    { (yyval) = TYPE_CHECKERBOARD; }
    break;

  case 139:
#line 826 "qgames_parser.y"
    { (yyval) = TYPE_GRID; }
    break;

  case 140:
#line 827 "qgames_parser.y"
    { (yyval) = TYPE_INTERSECTIONS; }
    break;

  case 141:
#line 830 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        tipojuego_graph_tablero_std( tipojuego, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), graph_dim1, graph_dim2, html_color1, html_color2 );
     }
    break;

  case 142:
#line 834 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-board file" ) }
    break;

  case 143:
#line 835 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (4)])) ) == NOT_FOUND ){ 
            qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (4)])) );
            yyerror( "Debe ser un tipo de pieza" ); YYERROR;
        }
        tipojuego_graph_tipopieza_std( tipojuego, ((char*)(yyvsp[(2) - (4)])), (yyvsp[(3) - (4)]), graph_dim1, graph_dim2 );
    }
    break;

  case 144:
#line 844 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-piece string" ); }
    break;

  case 145:
#line 845 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square file" ); }
    break;

  case 146:
#line 846 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square color" ); }
    break;

  case 147:
#line 847 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square highlighted" ); }
    break;

  case 148:
#line 856 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        qgzprintf( "Definiendo %s", ((char*)(yyvsp[(2) - (2)])) );
        tipojuego_add_tipo_mov( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
        free((void*)(yyvsp[(2) - (2)]));
    }
    break;

  case 149:
#line 864 "qgames_parser.y"
    { (yyval) =  NOTACION_PIEZA; }
    break;

  case 150:
#line 865 "qgames_parser.y"
    { (yyval) =  NOTACION_ORIGEN; }
    break;

  case 151:
#line 866 "qgames_parser.y"
    { (yyval) =  NOTACION_DESTINO; }
    break;

  case 152:
#line 867 "qgames_parser.y"
    { (yyval) =  NOTACION_MARCA ; }
    break;

  case 153:
#line 868 "qgames_parser.y"
    { (yyval) =  NOTACION_CAPTURA; }
    break;

  case 154:
#line 871 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 155:
#line 872 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 156:
#line 873 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 157:
#line 876 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 158:
#line 877 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 159:
#line 878 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 160:
#line 882 "qgames_parser.y"
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

  case 161:
#line 894 "qgames_parser.y"
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

  case 162:
#line 920 "qgames_parser.y"
    { 
                  CHECK_TIPOJUEGO;
                  tipojuego_set_notacion_marca( tipojuego, (char*)(yyvsp[(3) - (3)]), NULL );
                  free((void*)(yyvsp[(3) - (3)]));
             }
    break;

  case 163:
#line 925 "qgames_parser.y"
    { 
                  CHECK_TIPOJUEGO;
                  tipojuego_set_notacion_marca( tipojuego, NULL, (char*)(yyvsp[(3) - (3)]) );
                  free((void*)(yyvsp[(3) - (3)]));
             }
    break;

  case 166:
#line 935 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO; 
        tipojuego_add_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ); 
        if( last_pieza ) free( last_pieza );
        last_pieza = strdup( ((char*)(yyvsp[(2) - (2)])) );
    }
    break;

  case 167:
#line 943 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < (yyvsp[(4) - (4)]); i ++ ){
          tipojuego_add_pieza( tipojuego, ((char*)(yyvsp[(2) - (4)])), CASILLERO_POZO, ((char*)(yyvsp[(3) - (4)])) );
        }
    }
    break;

  case 168:
#line 950 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 169:
#line 950 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < qgz_param_count; i ++ ){
          tipojuego_add_pieza( tipojuego, ((char*)(yyvsp[(2) - (5)])), (char*)qgz_param_list[i].par, ((char*)(yyvsp[(3) - (5)])) );
        }
    }
    break;

  case 170:
#line 959 "qgames_parser.y"
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

  case 171:
#line 979 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 174:
#line 983 "qgames_parser.y"
    {
        tipojuego_add_secuencia_rep( tipojuego );
    }
    break;

  case 176:
#line 990 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        tipojuego_add_simetria( tipojuego, ((char*)(yyvsp[(2) - (4)])), (char*)(yyvsp[(3) - (4)]), (char*)(yyvsp[(4) - (4)]) );
    }
    break;

  case 177:
#line 996 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 178:
#line 996 "qgames_parser.y"
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
#line 3100 "qgames_parser.c"
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


#line 1045 "qgames_parser.y"


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


