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
     TOK_SEPARATOR = 261,
     TOK_ATTR = 262,
     TOK_BOARD = 263,
     TOK_CAPTURED_MARK = 264,
     TOK_CANTIDAD_PIEZAS = 265,
     TOK_CANTIDAD_PIEZAS_PROPIAS = 266,
     TOK_CANTIDAD_PIEZAS_ENEMIGAS = 267,
     TOK_COLOR = 268,
     TOK_DEFAULT = 269,
     TOK_DIRECTION = 270,
     TOK_DROP = 271,
     TOK_ENDING = 272,
     TOK_GAMETYPE = 273,
     TOK_MARK = 274,
     TOK_MOVE = 275,
     TOK_MOVETYPE = 276,
     TOK_NOTATION = 277,
     TOK_ONREPEAT = 278,
     TOK_ORIGIN = 279,
     TOK_PIECE = 280,
     TOK_PIECE_NAME = 281,
     TOK_REPEAT = 282,
     TOK_SEQUENCE = 283,
     TOK_START = 284,
     TOK_SYMMETRY = 285,
     TOK_TARGET = 286,
     TOK_ZONE = 287,
     TOK_SEPCODE = 288,
     TOK_AHOGADO = 289,
     TOK_ASIGNA_ATT = 290,
     TOK_ATACADO_ENEMIGO = 291,
     TOK_CAPTURA = 292,
     TOK_CAPTURA_SI = 293,
     TOK_CAPTURA_Y_JUEGA = 294,
     TOK_CAPTURA_Y_JUEGA_SI = 295,
     TOK_CASILLERO_INICIAL = 296,
     TOK_DESTINO_ANT = 297,
     TOK_EMPATA = 298,
     TOK_EMPATA_SI = 299,
     TOK_ENTABLERO = 300,
     TOK_ENZONA = 301,
     TOK_GANA = 302,
     TOK_GANA_SI = 303,
     TOK_JAQUEMATE = 304,
     TOK_JUEGA = 305,
     TOK_JUEGA_SI = 306,
     TOK_IF = 307,
     TOK_OCUPADO = 308,
     TOK_OCUPADOENEMIGO = 309,
     TOK_OCUPADOPROPIO = 310,
     TOK_ORIGEN_ANT = 311,
     TOK_PARA = 312,
     TOK_PARA_SI = 313,
     TOK_PIERDE = 314,
     TOK_PIERDE_SI = 315,
     TOK_TRANSFORMA = 316,
     TOK_REPITEPOS = 317,
     TOK_AND = 318,
     TOK_OR = 319,
     TOK_NOT = 320,
     TOK_EQUAL = 321,
     TOK_DEQUAL = 322,
     TOK_WHILE = 323,
     TOK_DO = 324,
     TOK_END = 325
   };
#endif
/* Tokens.  */
#define TOK_NUMBER 258
#define TOK_WORD 259
#define TOK_STRING 260
#define TOK_SEPARATOR 261
#define TOK_ATTR 262
#define TOK_BOARD 263
#define TOK_CAPTURED_MARK 264
#define TOK_CANTIDAD_PIEZAS 265
#define TOK_CANTIDAD_PIEZAS_PROPIAS 266
#define TOK_CANTIDAD_PIEZAS_ENEMIGAS 267
#define TOK_COLOR 268
#define TOK_DEFAULT 269
#define TOK_DIRECTION 270
#define TOK_DROP 271
#define TOK_ENDING 272
#define TOK_GAMETYPE 273
#define TOK_MARK 274
#define TOK_MOVE 275
#define TOK_MOVETYPE 276
#define TOK_NOTATION 277
#define TOK_ONREPEAT 278
#define TOK_ORIGIN 279
#define TOK_PIECE 280
#define TOK_PIECE_NAME 281
#define TOK_REPEAT 282
#define TOK_SEQUENCE 283
#define TOK_START 284
#define TOK_SYMMETRY 285
#define TOK_TARGET 286
#define TOK_ZONE 287
#define TOK_SEPCODE 288
#define TOK_AHOGADO 289
#define TOK_ASIGNA_ATT 290
#define TOK_ATACADO_ENEMIGO 291
#define TOK_CAPTURA 292
#define TOK_CAPTURA_SI 293
#define TOK_CAPTURA_Y_JUEGA 294
#define TOK_CAPTURA_Y_JUEGA_SI 295
#define TOK_CASILLERO_INICIAL 296
#define TOK_DESTINO_ANT 297
#define TOK_EMPATA 298
#define TOK_EMPATA_SI 299
#define TOK_ENTABLERO 300
#define TOK_ENZONA 301
#define TOK_GANA 302
#define TOK_GANA_SI 303
#define TOK_JAQUEMATE 304
#define TOK_JUEGA 305
#define TOK_JUEGA_SI 306
#define TOK_IF 307
#define TOK_OCUPADO 308
#define TOK_OCUPADOENEMIGO 309
#define TOK_OCUPADOPROPIO 310
#define TOK_ORIGEN_ANT 311
#define TOK_PARA 312
#define TOK_PARA_SI 313
#define TOK_PIERDE 314
#define TOK_PIERDE_SI 315
#define TOK_TRANSFORMA 316
#define TOK_REPITEPOS 317
#define TOK_AND 318
#define TOK_OR 319
#define TOK_NOT 320
#define TOK_EQUAL 321
#define TOK_DEQUAL 322
#define TOK_WHILE 323
#define TOK_DO 324
#define TOK_END 325




/* Copy the first part of user declarations.  */
#line 1 "qgames_parser.y"


#include  <stdio.h>
#include  <stdarg.h>
#include  <string.h>
#include  <stdlib.h>
#include  <errno.h>
#include  <qgames.h>
#include  <qgames_analyzer.h>
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
char*        last_tmov  = NULL;

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
#line 339 "qgames_parser.c"

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
#define YYFINAL  62
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNRULES -- Number of states.  */
#define YYNSTATES  220

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      72,    73,     2,     2,    71,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70
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
     176,   177,   184,   185,   186,   194,   196,   198,   200,   202,
     204,   206,   208,   210,   212,   213,   215,   219,   223,   224,
     228,   229,   233,   234,   239,   241,   244,   248,   249,   254,
     256,   259,   260,   265,   266,   271,   274,   277,   279,   281,
     283,   285,   287,   289,   292,   296,   298,   301,   305,   309,
     314,   318,   322,   326,   330,   333,   338,   339,   345,   347,
     348,   352,   354,   355,   360,   365,   366,   372,   374,   376,
     378,   380,   382,   384,   386,   388,   390,   392,   394,   396,
     398,   400,   402,   403,   405,   409
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     141,     0,    -1,     4,    -1,     5,    -1,    75,    -1,    76,
      75,    -1,    76,    71,    75,    -1,     3,    -1,    77,     3,
      -1,    34,    -1,    34,    75,    -1,    36,    -1,    10,    -1,
      11,    -1,    12,    -1,    80,    76,    -1,    80,     3,    -1,
      80,    -1,    42,    -1,    42,    75,    -1,    56,    -1,    56,
      75,    -1,    45,    -1,    46,    75,    75,    -1,    46,    75,
      -1,    49,    75,    -1,    53,    -1,    55,    -1,    54,    -1,
      53,    75,    -1,    62,     3,    -1,    66,    -1,    67,    -1,
      65,    91,    -1,    -1,    91,    63,    90,    91,    -1,    91,
      64,    91,    -1,    91,    88,     3,    -1,     3,    88,    91,
      -1,    72,    91,    73,    -1,    89,    -1,    78,    -1,    79,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,     4,    -1,    43,    -1,    44,
      91,    -1,    47,    -1,    48,    91,    -1,    59,    -1,    60,
      91,    -1,    41,    -1,    -1,    61,    94,    76,    -1,    35,
      75,     3,    -1,    35,    75,    71,     3,    -1,    50,    -1,
      39,    -1,    51,    91,    -1,    40,    91,    -1,    37,    -1,
      57,    -1,    58,    91,    -1,    -1,    -1,    52,    91,    99,
     106,   100,    70,    -1,    -1,    -1,    68,   102,    91,    69,
     103,   106,    70,    -1,    95,    -1,    96,    -1,    92,    -1,
      98,    -1,    93,    -1,    97,    -1,   101,    -1,     4,    -1,
     104,    -1,    -1,   105,    -1,   106,    33,   105,    -1,     7,
      75,     3,    -1,    -1,     8,   109,    76,    -1,    -1,    13,
     111,    76,    -1,    -1,    15,    75,   113,    77,    -1,    16,
      -1,    16,    75,    -1,    16,    75,    75,    -1,    -1,   114,
       6,   116,   106,    -1,    20,    -1,    20,    75,    -1,    -1,
     117,     6,   119,   106,    -1,    -1,    17,     6,   121,   106,
      -1,    18,    75,    -1,    21,    75,    -1,    26,    -1,    24,
      -1,    31,    -1,    19,    -1,     9,    -1,   124,    -1,   125,
     124,    -1,   125,    71,   124,    -1,   124,    -1,   126,   124,
      -1,   126,    71,   124,    -1,    22,    75,    75,    -1,    22,
      75,    75,    75,    -1,    22,    19,    75,    -1,    22,     9,
      75,    -1,    22,    14,   126,    -1,    22,    23,   125,    -1,
      25,    75,    -1,    29,    75,    75,     3,    -1,    -1,    29,
      75,    75,   130,    76,    -1,    76,    -1,    -1,    28,   133,
     131,    -1,   132,    -1,    -1,   132,    27,   135,   131,    -1,
      30,    75,    75,    75,    -1,    -1,    32,    75,    75,   138,
      76,    -1,   107,    -1,   108,    -1,   110,    -1,   112,    -1,
     115,    -1,   120,    -1,   122,    -1,   118,    -1,   123,    -1,
     127,    -1,   128,    -1,   134,    -1,   129,    -1,   136,    -1,
     137,    -1,    -1,   139,    -1,   140,     6,   139,    -1,   140,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   149,   153,   154,   155,   158,   159,   166,
     170,   176,   182,   187,   192,   201,   221,   225,   231,   235,
     245,   249,   264,   270,   294,   305,   317,   321,   325,   329,
     346,   354,   354,   357,   361,   361,   367,   369,   373,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   412,   416,   422,   426,   432,   436,   446,   450,   450,
     473,   477,   485,   489,   493,   499,   505,   512,   516,   527,
     530,   527,   535,   538,   535,   550,   551,   552,   553,   554,
     555,   556,   557,   580,   580,   584,   585,   597,   607,   607,
     619,   619,   629,   629,   640,   641,   642,   645,   645,   656,
     657,   661,   661,   673,   673,   682,   692,   698,   699,   700,
     701,   702,   705,   706,   707,   710,   711,   712,   716,   728,
     751,   752,   753,   754,   758,   766,   773,   773,   782,   802,
     802,   805,   806,   806,   813,   819,   819,   837,   838,   839,
     840,   841,   842,   843,   844,   845,   846,   847,   848,   849,
     850,   851,   851,   858,   859,   863
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_NUMBER", "TOK_WORD", "TOK_STRING",
  "TOK_SEPARATOR", "TOK_ATTR", "TOK_BOARD", "TOK_CAPTURED_MARK",
  "TOK_CANTIDAD_PIEZAS", "TOK_CANTIDAD_PIEZAS_PROPIAS",
  "TOK_CANTIDAD_PIEZAS_ENEMIGAS", "TOK_COLOR", "TOK_DEFAULT",
  "TOK_DIRECTION", "TOK_DROP", "TOK_ENDING", "TOK_GAMETYPE", "TOK_MARK",
  "TOK_MOVE", "TOK_MOVETYPE", "TOK_NOTATION", "TOK_ONREPEAT", "TOK_ORIGIN",
  "TOK_PIECE", "TOK_PIECE_NAME", "TOK_REPEAT", "TOK_SEQUENCE", "TOK_START",
  "TOK_SYMMETRY", "TOK_TARGET", "TOK_ZONE", "TOK_SEPCODE", "TOK_AHOGADO",
  "TOK_ASIGNA_ATT", "TOK_ATACADO_ENEMIGO", "TOK_CAPTURA", "TOK_CAPTURA_SI",
  "TOK_CAPTURA_Y_JUEGA", "TOK_CAPTURA_Y_JUEGA_SI", "TOK_CASILLERO_INICIAL",
  "TOK_DESTINO_ANT", "TOK_EMPATA", "TOK_EMPATA_SI", "TOK_ENTABLERO",
  "TOK_ENZONA", "TOK_GANA", "TOK_GANA_SI", "TOK_JAQUEMATE", "TOK_JUEGA",
  "TOK_JUEGA_SI", "TOK_IF", "TOK_OCUPADO", "TOK_OCUPADOENEMIGO",
  "TOK_OCUPADOPROPIO", "TOK_ORIGEN_ANT", "TOK_PARA", "TOK_PARA_SI",
  "TOK_PIERDE", "TOK_PIERDE_SI", "TOK_TRANSFORMA", "TOK_REPITEPOS",
  "TOK_AND", "TOK_OR", "TOK_NOT", "TOK_EQUAL", "TOK_DEQUAL", "TOK_WHILE",
  "TOK_DO", "TOK_END", "','", "'('", "')'", "$accept", "word_or_string",
  "word_or_string_list", "number_list", "instexpr_ahogado",
  "instexpr_atacado", "cantidad_piezas_preludio",
  "instexpr_cantidad_piezas", "instexpr_movidas_anteriores",
  "instexpr_entablero", "instexpr_enzona", "instexpr_jaquemate",
  "instexpr_ocupado", "instexpr_repitepos", "es_igual_a",
  "instexpr_logical", "@1", "instexpr", "instaction_final",
  "instaction_movs", "@2", "instaction_asigna_att", "instaction_juega",
  "instaction_para", "instaction_if", "@3", "@4", "instaction_while", "@5",
  "@6", "instaction", "instcode", "code_list", "instruction_attr",
  "instruction_board", "@7", "instruction_color", "@8",
  "instruction_direction", "@9", "instruction_drop_prelude",
  "instruction_drop", "@10", "instruction_move_prelude",
  "instruction_move", "@11", "instruction_ending", "@12",
  "instruction_gametype", "instruction_movetype",
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
     325,    44,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    76,    77,    77,    78,
      78,    79,    80,    80,    80,    81,    81,    81,    82,    82,
      82,    82,    83,    84,    84,    85,    86,    86,    86,    86,
      87,    88,    88,    89,    90,    89,    89,    89,    89,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    92,    92,    92,    92,    92,    92,    93,    94,    93,
      95,    95,    96,    96,    96,    96,    96,    97,    97,    99,
     100,    98,   102,   103,   101,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   106,   107,   109,   108,
     111,   110,   113,   112,   114,   114,   114,   116,   115,   117,
     117,   119,   118,   121,   120,   122,   123,   124,   124,   124,
     124,   124,   125,   125,   125,   126,   126,   126,   127,   127,
     127,   127,   127,   127,   128,   129,   130,   129,   131,   133,
     132,   134,   135,   134,   136,   138,   137,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   140,   140,   141
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
       3,     4,     1,     1,     2,     2,     1,     1,     2,     0,
       0,     6,     0,     0,     7,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     3,     3,     0,     3,
       0,     3,     0,     4,     1,     2,     3,     0,     4,     1,
       2,     0,     4,     0,     4,     2,     2,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     2,     3,     3,     4,
       3,     3,     3,     3,     2,     4,     0,     5,     1,     0,
       3,     1,     0,     4,     4,     0,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     152,     0,    88,    90,     0,    94,     0,     0,    99,     0,
       0,     0,   129,     0,     0,     0,   137,   138,   139,   140,
       0,   141,     0,   144,   142,   143,   145,   146,   147,   149,
     131,   148,   150,   151,   153,   155,     0,     2,     3,     0,
       0,     0,    92,    95,   103,   105,   100,   106,     0,     0,
       0,     0,     0,   124,     0,     0,     0,     0,    97,   101,
     132,   152,     1,    87,     4,    89,    91,     0,    96,    84,
     121,   111,   110,   108,   107,   109,   115,   122,   120,   112,
     123,   118,   128,   130,   126,     0,   135,    84,    84,     0,
     154,     0,     5,     7,    93,    82,     0,    66,    63,     0,
      57,    51,     0,    53,     0,    62,     0,     0,    67,     0,
      55,     0,    58,    72,    77,    79,    75,    76,    80,    78,
      81,    83,    85,   104,     0,   116,     0,   113,   119,   125,
       0,   134,     0,    98,   102,   133,     6,     8,     0,     0,
      50,    12,    13,    14,     9,    11,    18,    22,     0,     0,
      26,    28,    27,    20,     0,     0,     0,    41,    42,    17,
      43,    44,    45,    46,    47,    48,    49,    40,    65,    52,
      54,    64,    69,    68,    56,     0,     0,    84,   117,   114,
     127,   136,    60,     0,    31,    32,     0,    10,    19,    24,
      25,    29,    21,    30,    33,     0,    16,    15,    34,     0,
       0,    84,    59,     0,    86,    61,    38,    23,    39,     0,
      36,    37,    70,    73,    35,     0,    84,    71,     0,    74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    64,    82,    94,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   200,   167,   209,   168,   114,   115,
     175,   116,   117,   118,   119,   201,   215,   120,   176,   216,
     121,   122,   123,    16,    17,    40,    18,    41,    19,    67,
      20,    21,    87,    22,    23,    88,    24,    69,    25,    26,
      76,    80,    77,    27,    28,    29,   130,    83,    30,    54,
      31,    89,    32,    33,   132,    34,    35,    36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -100
static const yytype_int16 yypact[] =
{
     219,    35,  -100,  -100,    35,    35,    11,    35,    35,    35,
      99,    35,  -100,    35,    35,    35,  -100,  -100,  -100,  -100,
      13,  -100,    20,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
       1,  -100,  -100,  -100,  -100,    31,    41,  -100,  -100,    32,
      35,    35,  -100,    35,  -100,  -100,  -100,  -100,    35,    51,
      35,    51,    35,  -100,    35,    35,    35,    35,  -100,  -100,
    -100,   219,  -100,  -100,  -100,    25,    25,    54,  -100,   163,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,    12,  -100,  -100,
      43,    35,    25,  -100,    55,    35,  -100,   163,   163,    35,
    -100,    35,  -100,  -100,    56,  -100,    35,  -100,  -100,   120,
    -100,  -100,   120,  -100,   120,  -100,   120,   120,  -100,   120,
    -100,   120,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,    28,    51,  -100,    51,  -100,  -100,  -100,
      35,  -100,    35,    28,    28,  -100,  -100,  -100,     2,   -21,
    -100,  -100,  -100,  -100,    35,  -100,    35,  -100,    35,    35,
      35,  -100,  -100,    35,    60,   120,   120,  -100,  -100,    29,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,    22,    22,
      22,    22,    22,    22,    22,    35,   120,   163,  -100,  -100,
      25,    25,  -100,    63,  -100,  -100,   120,  -100,  -100,    35,
    -100,  -100,  -100,  -100,    22,    97,  -100,    25,  -100,   120,
      65,   163,    25,    71,  -100,  -100,    22,  -100,  -100,   120,
      22,  -100,    28,  -100,    22,   -26,   163,  -100,   -22,  -100
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,    -1,   -39,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,   -63,  -100,  -100,   -84,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,   -99,   -72,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
     -27,  -100,  -100,  -100,  -100,  -100,  -100,   -10,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,    26,  -100,  -100
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,    65,    66,    42,    43,   182,    45,    46,    47,    52,
      53,   177,    55,    56,    57,   133,   134,    44,   169,    58,
     170,    71,   171,   172,    79,   173,    59,   174,    60,    37,
      38,    72,   196,    37,    38,    63,    73,    61,    74,    37,
      38,    62,    68,    75,   217,   184,   185,    70,   219,    78,
     125,    81,    71,   127,    84,    85,    86,    93,   129,   137,
      71,   177,    72,   193,    92,    92,   205,    73,   211,    74,
      72,   194,   195,   183,    75,    73,   186,    74,   204,   135,
     128,    92,    75,   124,   131,   198,   199,    90,   184,   185,
     136,   180,   203,   181,     0,   138,    91,   178,     0,   179,
       0,     0,   206,    37,    38,     0,     0,     0,    48,     0,
       0,     0,     0,    49,   126,   210,     0,     0,    50,     0,
     197,     0,    51,   139,   140,   214,     0,     0,     0,   212,
     141,   142,   143,     0,   198,   199,   202,   184,   185,     0,
     213,     0,     0,   187,   218,   188,     0,   189,   190,   191,
       0,     0,   192,     0,   144,     0,   145,     0,     0,     0,
     198,   199,   146,   184,   185,   147,   148,    95,     0,   149,
     208,     0,     0,   150,   151,   152,   153,     0,     0,    92,
      92,     0,   154,     0,     0,   155,     0,     0,   207,     0,
       0,     0,   156,     0,     0,     0,    92,     0,    96,     0,
      97,    92,    98,    99,   100,     0,   101,   102,     0,     0,
     103,   104,     0,   105,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,     0,     1,     2,     0,     0,
       0,   113,     3,     0,     4,     5,     6,     7,     0,     8,
       9,    10,     0,     0,    11,     0,     0,    12,    13,    14,
       0,    15
};

static const yytype_int16 yycheck[] =
{
       1,    40,    41,     4,     5,     3,     7,     8,     9,    10,
      11,    33,    13,    14,    15,    87,    88,     6,   102,     6,
     104,     9,   106,   107,    51,   109,     6,   111,    27,     4,
       5,    19,     3,     4,     5,     3,    24,     6,    26,     4,
       5,     0,    43,    31,    70,    66,    67,    48,    70,    50,
      77,    52,     9,    80,    55,    56,    57,     3,     3,     3,
       9,    33,    19,     3,    65,    66,     3,    24,     3,    26,
      19,   155,   156,    71,    31,    24,   139,    26,   177,    89,
      81,    82,    31,    71,    85,    63,    64,    61,    66,    67,
      91,   130,   176,   132,    -1,    96,    71,   124,    -1,   126,
      -1,    -1,   186,     4,     5,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    14,    71,   199,    -1,    -1,    19,    -1,
     159,    -1,    23,     3,     4,   209,    -1,    -1,    -1,   201,
      10,    11,    12,    -1,    63,    64,   175,    66,    67,    -1,
      69,    -1,    -1,   144,   216,   146,    -1,   148,   149,   150,
      -1,    -1,   153,    -1,    34,    -1,    36,    -1,    -1,    -1,
      63,    64,    42,    66,    67,    45,    46,     4,    -1,    49,
      73,    -1,    -1,    53,    54,    55,    56,    -1,    -1,   180,
     181,    -1,    62,    -1,    -1,    65,    -1,    -1,   189,    -1,
      -1,    -1,    72,    -1,    -1,    -1,   197,    -1,    35,    -1,
      37,   202,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      47,    48,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    -1,     7,     8,    -1,    -1,
      -1,    68,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    -1,    -1,    25,    -1,    -1,    28,    29,    30,
      -1,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    13,    15,    16,    17,    18,    20,    21,
      22,    25,    28,    29,    30,    32,   107,   108,   110,   112,
     114,   115,   117,   118,   120,   122,   123,   127,   128,   129,
     132,   134,   136,   137,   139,   140,   141,     4,     5,    75,
     109,   111,    75,    75,     6,    75,    75,    75,     9,    14,
      19,    23,    75,    75,   133,    75,    75,    75,     6,     6,
      27,     6,     0,     3,    75,    76,    76,   113,    75,   121,
      75,     9,    19,    24,    26,    31,   124,   126,    75,   124,
     125,    75,    76,   131,    75,    75,    75,   116,   119,   135,
     139,    71,    75,     3,    77,     4,    35,    37,    39,    40,
      41,    43,    44,    47,    48,    50,    51,    52,    57,    58,
      59,    60,    61,    68,    92,    93,    95,    96,    97,    98,
     101,   104,   105,   106,    71,   124,    71,   124,    75,     3,
     130,    75,   138,   106,   106,   131,    75,     3,    75,     3,
       4,    10,    11,    12,    34,    36,    42,    45,    46,    49,
      53,    54,    55,    56,    62,    65,    72,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    89,    91,    91,
      91,    91,    91,    91,    91,    94,   102,    33,   124,   124,
      76,    76,     3,    71,    66,    67,    88,    75,    75,    75,
      75,    75,    75,     3,    91,    91,     3,    76,    63,    64,
      88,    99,    76,    91,   105,     3,    91,    75,    73,    90,
      91,     3,   106,    69,    91,   100,   103,    70,   106,    70
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
#line 148 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 3:
#line 149 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 4:
#line 153 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(1) - (1)]) ); }
    break;

  case 5:
#line 154 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(2) - (2)]) ); }
    break;

  case 6:
#line 155 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(3) - (3)]) ); }
    break;

  case 7:
#line 158 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(1) - (1)]) ); }
    break;

  case 8:
#line 159 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(2) - (2)]) ); }
    break;

  case 9:
#line 166 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_ahogado( tipojuego, NULL );
    }
    break;

  case 10:
#line 170 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_ahogado( tipojuego, (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 11:
#line 176 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_atacado( tipojuego, NULL );
    }
    break;

  case 12:
#line 182 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = CUALQUIERA;
            init_parameters(); 
    }
    break;

  case 13:
#line 187 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = PROPIO;
            init_parameters(); 
    }
    break;

  case 14:
#line 192 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = ENEMIGO;
            init_parameters(); 
    }
    break;

  case 15:
#line 201 "qgames_parser.y"
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
#line 221 "qgames_parser.y"
    {
            tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (2)]), NULL, NULL );
            tipojuego_code_op_equal( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 17:
#line 225 "qgames_parser.y"
    { 
            tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (1)]), NULL, NULL );
    }
    break;

  case 18:
#line 231 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_destino_ant( tipojuego, NULL );
    }
    break;

  case 19:
#line 235 "qgames_parser.y"
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
#line 245 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_origen_ant( tipojuego, NULL );
    }
    break;

  case 21:
#line 249 "qgames_parser.y"
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
#line 264 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_entablero( tipojuego );
    }
    break;

  case 23:
#line 270 "qgames_parser.y"
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
#line 294 "qgames_parser.y"
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
#line 305 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ){
                tipojuego_code_jaquemate( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
            } else {
                qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (2)])) );
                yyerror( "Debe ser un tipo de pieza" );
            }
    }
    break;

  case 26:
#line 317 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL, NULL );
    }
    break;

  case 27:
#line 321 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, PROPIO, NULL, NULL );
    }
    break;

  case 28:
#line 325 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, ENEMIGO, NULL, NULL );
    }
    break;

  case 29:
#line 329 "qgames_parser.y"
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
    }
    break;

  case 30:
#line 346 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_op_false( tipojuego );
        NOT_IMPLEMENTED_WARN( "repite-posicion" );
    }
    break;

  case 33:
#line 357 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_not( tipojuego );
    }
    break;

  case 34:
#line 361 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 35:
#line 364 "qgames_parser.y"
    { 
                tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 36:
#line 367 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 37:
#line 369 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(3) - (3)]) );
    }
    break;

  case 38:
#line 373 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(1) - (3)]) );
    }
    break;

  case 50:
#line 391 "qgames_parser.y"
    {    
            int  algo;
            CHECK_TIPOJUEGO;
            /* una direccion podria ser */
            algo = tipojuego_get_direccion( tipojuego, (char*)(yyvsp[(1) - (1)]) );
            if( algo != NOT_FOUND ){
                qgzprintf( "Direccion %s no esperada", (char*)(yyvsp[(1) - (1)]) );
            } else {
                algo = tipojuego_get_casillero( tipojuego, (char*)(yyvsp[(1) - (1)]) );
                if( algo != NOT_FOUND ){
                    qgzprintf( "Casillero %s no esperado", (char*)(yyvsp[(1) - (1)]) );
                } else {
                    qgzprintf( "%s no es nada", (char*)(yyvsp[(1) - (1)]) );
                    yyerror( "Comando no reconocido" );
                    YYERROR;
                }
            }
    }
    break;

  case 51:
#line 412 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, EMPATA );
    }
    break;

  case 52:
#line 416 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, EMPATA );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 53:
#line 422 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, GANA );
    }
    break;

  case 54:
#line 426 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, GANA );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 55:
#line 432 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, PIERDE );
    }
    break;

  case 56:
#line 436 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, PIERDE );
            tipojuego_code_end_condblock( tipojuego );
     }
    break;

  case 57:
#line 446 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_casillero( tipojuego, NULL );
    }
    break;

  case 58:
#line 450 "qgames_parser.y"
    {  CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 59:
#line 450 "qgames_parser.y"
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
#line 473 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) );
    }
    break;

  case 61:
#line 477 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]) );
    }
    break;

  case 62:
#line 485 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_juega( tipojuego, NULL, 0 );
    }
    break;

  case 63:
#line 489 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_juega( tipojuego, NULL, 1 );
    }
    break;

  case 64:
#line 493 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_juega( tipojuego, NULL, 0 );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 65:
#line 499 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_juega( tipojuego, NULL, 1 );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 66:
#line 505 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_captura( tipojuego, NULL );
    }
    break;

  case 67:
#line 512 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_para( tipojuego );
    }
    break;

  case 68:
#line 516 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_para( tipojuego );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 69:
#line 527 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 70:
#line 530 "qgames_parser.y"
    {
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 72:
#line 535 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            (yyval) = tipojuego_code_start_block( tipojuego );
    }
    break;

  case 73:
#line 538 "qgames_parser.y"
    {
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 74:
#line 540 "qgames_parser.y"
    {
            tipojuego_code_continue_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_else_condblock( tipojuego );
            tipojuego_code_break_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_end_condblock( tipojuego );
            tipojuego_code_end_block( tipojuego, (yyvsp[(2) - (7)]) );
    }
    break;

  case 82:
#line 557 "qgames_parser.y"
    {   
            int  algo;
            CHECK_TIPOJUEGO;
            /* una direccion podria ser */
            // qgzprintf( "Reconociendo %s", (char*)$1 );
            algo = tipojuego_get_direccion( tipojuego, (char*)(yyvsp[(1) - (1)]) );
            if( algo != NOT_FOUND ){
                tipojuego_code_direccion( tipojuego, (char*)(yyvsp[(1) - (1)]) );
            } else {
                algo = tipojuego_get_casillero( tipojuego, (char*)(yyvsp[(1) - (1)]) );
                if( algo != NOT_FOUND ){
                    tipojuego_code_casillero( tipojuego, (char*)(yyvsp[(1) - (1)]) );
                } else {
                    qgzprintf( "%s no es nada", (char*)(yyvsp[(1) - (1)]) );
                    yyerror( "Comando no reconocido" );
                    YYERROR;
                }
            }

    }
    break;

  case 87:
#line 598 "qgames_parser.y"
    {  CHECK_TIPOJUEGO ;
                      CHECK_LAST_PIEZA;
                      tipojuego_add_tpieza_att( tipojuego, last_pieza, ((char*)(yyvsp[(2) - (3)])), (yyvsp[(3) - (3)]) );
                    }
    break;

  case 88:
#line 607 "qgames_parser.y"
    { CHECK_TIPOJUEGO; 
                     init_parameters(); }
    break;

  case 89:
#line 610 "qgames_parser.y"
    {
                     char*  dims[MAX_PARAMS]; int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                        dims[i] = ((char*)qgz_param_list[i].par);
                      }
                     tipojuego_genera_dimensiones( tipojuego, qgz_param_count, dims );
                   }
    break;

  case 90:
#line 619 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 91:
#line 620 "qgames_parser.y"
    { int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                       char* col = ((char*)qgz_param_list[i].par);
                       tipojuego_add_color( tipojuego, col );
                     }
                   }
    break;

  case 92:
#line 629 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 93:
#line 630 "qgames_parser.y"
    {
                      int  dirs[MAX_PARAMS]; int i; 
                      tipojuego_add_direccion( tipojuego, ((char*)(yyvsp[(2) - (4)])) );
                      for( i = 0; i < qgz_param_count; i ++ ){
                          dirs[i] = qgz_param_list[i].par;
                      }
                      tipojuego_add_direccion_arr( tipojuego, ((char*)(yyvsp[(2) - (4)])), dirs );
                    }
    break;

  case 95:
#line 641 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 96:
#line 642 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 97:
#line 645 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, DROP, last_pieza, last_tmov );
    }
    break;

  case 98:
#line 650 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 100:
#line 657 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 101:
#line 661 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, MOVE, last_pieza, last_tmov );
    }
    break;

  case 102:
#line 666 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 103:
#line 673 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO; 
            change_to_code_mode(); 
            tipojuego_start_codeend( tipojuego );
    }
    break;

  case 104:
#line 677 "qgames_parser.y"
    {
            tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 105:
#line 682 "qgames_parser.y"
    { 
        if( tipojuego ){
            yyerror( "Ya fue definido el tipo juego" );
            YYERROR;
        } else {
            tipojuego = tipojuego_new( ((char*)(yyvsp[(2) - (2)])) );
        }
    }
    break;

  case 106:
#line 692 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_add_tipo_mov( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
    }
    break;

  case 107:
#line 698 "qgames_parser.y"
    { (yyval) =  NOTACION_PIEZA; }
    break;

  case 108:
#line 699 "qgames_parser.y"
    { (yyval) =  NOTACION_ORIGEN; }
    break;

  case 109:
#line 700 "qgames_parser.y"
    { (yyval) =  NOTACION_DESTINO; }
    break;

  case 110:
#line 701 "qgames_parser.y"
    { (yyval) =  NOTACION_MARCA ; }
    break;

  case 111:
#line 702 "qgames_parser.y"
    { (yyval) =  NOTACION_CAPTURA; }
    break;

  case 112:
#line 705 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 113:
#line 706 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 114:
#line 707 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 115:
#line 710 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 116:
#line 711 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 117:
#line 712 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 118:
#line 716 "qgames_parser.y"
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

  case 119:
#line 728 "qgames_parser.y"
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
    }
    break;

  case 120:
#line 751 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN("notacion: mark"); }
    break;

  case 121:
#line 752 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN("notacion: captured_mark"); }
    break;

  case 124:
#line 758 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO; 
        tipojuego_add_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ); 
        if( last_pieza ) FREE( last_pieza );
        last_pieza = STRDUP( ((char*)(yyvsp[(2) - (2)])) );
    }
    break;

  case 125:
#line 766 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < (yyvsp[(4) - (4)]); i ++ ){
          tipojuego_add_pieza( tipojuego, ((char*)(yyvsp[(2) - (4)])), CASILLERO_POZO, ((char*)(yyvsp[(3) - (4)])) );
        }
    }
    break;

  case 126:
#line 773 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 127:
#line 773 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < qgz_param_count; i ++ ){
          tipojuego_add_pieza( tipojuego, ((char*)(yyvsp[(2) - (5)])), (char*)qgz_param_list[i].par, ((char*)(yyvsp[(3) - (5)])) );
        }
    }
    break;

  case 128:
#line 782 "qgames_parser.y"
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

  case 129:
#line 802 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 132:
#line 806 "qgames_parser.y"
    {
        tipojuego_add_secuencia_rep( tipojuego );
    }
    break;

  case 134:
#line 813 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        tipojuego_add_simetria( tipojuego, ((char*)(yyvsp[(2) - (4)])), (char*)(yyvsp[(3) - (4)]), (char*)(yyvsp[(4) - (4)]) );
    }
    break;

  case 135:
#line 819 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 136:
#line 819 "qgames_parser.y"
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
#line 2729 "qgames_parser.c"
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


#line 867 "qgames_parser.y"


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
    qgz_param_list = ALLOC( sizeof( str_param  ) * MAX_PARAMS );
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


