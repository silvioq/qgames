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
     TOK_AQUI = 290,
     TOK_ASIGNA_ATT = 291,
     TOK_ATACADO_ENEMIGO = 292,
     TOK_CAPTURA = 293,
     TOK_CAPTURA_SI = 294,
     TOK_CAPTURA_Y_JUEGA = 295,
     TOK_CAPTURA_Y_JUEGA_SI = 296,
     TOK_CASILLERO_INICIAL = 297,
     TOK_DESTINO_ANT = 298,
     TOK_EMPATA = 299,
     TOK_EMPATA_SI = 300,
     TOK_ENTABLERO = 301,
     TOK_ENZONA = 302,
     TOK_GANA = 303,
     TOK_GANA_SI = 304,
     TOK_JAQUEMATE = 305,
     TOK_JUEGA = 306,
     TOK_JUEGA_SI = 307,
     TOK_MARCA = 308,
     TOK_MUEVE = 309,
     TOK_MUEVE_SI = 310,
     TOK_IF = 311,
     TOK_OCUPADO = 312,
     TOK_OCUPADOENEMIGO = 313,
     TOK_OCUPADOPROPIO = 314,
     TOK_ORIGEN_ANT = 315,
     TOK_PARA = 316,
     TOK_PARA_SI = 317,
     TOK_PIERDE = 318,
     TOK_PIERDE_SI = 319,
     TOK_PIEZAS_EN_CAS = 320,
     TOK_TRANSFORMA = 321,
     TOK_REPITEPOS = 322,
     TOK_AND = 323,
     TOK_OR = 324,
     TOK_NOT = 325,
     TOK_EQUAL = 326,
     TOK_DEQUAL = 327,
     TOK_WHILE = 328,
     TOK_DO = 329,
     TOK_END = 330
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
#define TOK_AQUI 290
#define TOK_ASIGNA_ATT 291
#define TOK_ATACADO_ENEMIGO 292
#define TOK_CAPTURA 293
#define TOK_CAPTURA_SI 294
#define TOK_CAPTURA_Y_JUEGA 295
#define TOK_CAPTURA_Y_JUEGA_SI 296
#define TOK_CASILLERO_INICIAL 297
#define TOK_DESTINO_ANT 298
#define TOK_EMPATA 299
#define TOK_EMPATA_SI 300
#define TOK_ENTABLERO 301
#define TOK_ENZONA 302
#define TOK_GANA 303
#define TOK_GANA_SI 304
#define TOK_JAQUEMATE 305
#define TOK_JUEGA 306
#define TOK_JUEGA_SI 307
#define TOK_MARCA 308
#define TOK_MUEVE 309
#define TOK_MUEVE_SI 310
#define TOK_IF 311
#define TOK_OCUPADO 312
#define TOK_OCUPADOENEMIGO 313
#define TOK_OCUPADOPROPIO 314
#define TOK_ORIGEN_ANT 315
#define TOK_PARA 316
#define TOK_PARA_SI 317
#define TOK_PIERDE 318
#define TOK_PIERDE_SI 319
#define TOK_PIEZAS_EN_CAS 320
#define TOK_TRANSFORMA 321
#define TOK_REPITEPOS 322
#define TOK_AND 323
#define TOK_OR 324
#define TOK_NOT 325
#define TOK_EQUAL 326
#define TOK_DEQUAL 327
#define TOK_WHILE 328
#define TOK_DO 329
#define TOK_END 330




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
#line 348 "qgames_parser.c"

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
#define YYLAST   283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNRULES -- Number of states.  */
#define YYNSTATES  239

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      77,    78,     2,     2,    76,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
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
     283,   287,   288,   293,   295,   298,   299,   304,   305,   310,
     313,   316,   318,   320,   322,   324,   326,   328,   331,   335,
     337,   340,   344,   348,   353,   357,   361,   365,   369,   372,
     377,   378,   384,   386,   387,   391,   393,   394,   399,   404,
     405,   411,   413,   415,   417,   419,   421,   423,   425,   427,
     429,   431,   433,   435,   437,   439,   441,   442,   444,   448
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     151,     0,    -1,     4,    -1,     5,    -1,    80,    -1,    81,
      80,    -1,    81,    76,    80,    -1,     3,    -1,    82,     3,
      -1,    34,    -1,    34,    80,    -1,    37,    -1,    10,    -1,
      11,    -1,    12,    -1,    85,    81,    -1,    85,     3,    -1,
      85,    -1,    43,    -1,    43,    80,    -1,    60,    -1,    60,
      80,    -1,    46,    -1,    47,    80,    80,    -1,    47,    80,
      -1,    50,    80,    -1,    57,    -1,    59,    -1,    58,    -1,
      57,    80,    -1,    67,     3,    -1,    71,    -1,    72,    -1,
      70,    96,    -1,    -1,    96,    68,    95,    96,    -1,    96,
      69,    96,    -1,    96,    93,     3,    -1,     3,    93,    96,
      -1,    77,    96,    78,    -1,    94,    -1,    83,    -1,    84,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,
      -1,    91,    -1,    92,    -1,     4,    -1,    44,    -1,    45,
      96,    -1,    48,    -1,    49,    96,    -1,    63,    -1,    64,
      96,    -1,    42,    -1,    -1,    66,    99,    81,    -1,    36,
      80,     3,    -1,    36,    80,    76,     3,    -1,    51,    -1,
      40,    -1,    52,    96,    -1,    41,    96,    -1,    38,    -1,
      61,    -1,    62,    96,    -1,    54,    65,     4,    -1,    54,
      65,   106,    -1,    54,     4,     4,    -1,    54,   106,    -1,
      35,    -1,    80,    -1,    53,     3,   104,    -1,    53,   104,
      -1,    53,     3,    -1,    53,    -1,   106,    -1,    -1,    -1,
      56,    96,   109,   116,   110,    75,    -1,    -1,    -1,    73,
     112,    96,    74,   113,   116,    75,    -1,   100,    -1,   101,
      -1,    97,    -1,   108,    -1,   105,    -1,   107,    -1,    98,
      -1,   103,    -1,   102,    -1,   111,    -1,     4,    -1,   114,
      -1,    -1,   115,    -1,   116,    33,   115,    -1,     7,    80,
       3,    -1,    -1,     8,   119,    81,    -1,    -1,    13,   121,
      81,    -1,    -1,    15,    80,   123,    82,    -1,    16,    -1,
      16,    80,    -1,    16,    80,    80,    -1,    -1,   124,     6,
     126,   116,    -1,    20,    -1,    20,    80,    -1,    -1,   127,
       6,   129,   116,    -1,    -1,    17,     6,   131,   116,    -1,
      18,    80,    -1,    21,    80,    -1,    26,    -1,    24,    -1,
      31,    -1,    19,    -1,     9,    -1,   134,    -1,   135,   134,
      -1,   135,    76,   134,    -1,   134,    -1,   136,   134,    -1,
     136,    76,   134,    -1,    22,    80,    80,    -1,    22,    80,
      80,    80,    -1,    22,    19,    80,    -1,    22,     9,    80,
      -1,    22,    14,   136,    -1,    22,    23,   135,    -1,    25,
      80,    -1,    29,    80,    80,     3,    -1,    -1,    29,    80,
      80,   140,    81,    -1,    81,    -1,    -1,    28,   143,   141,
      -1,   142,    -1,    -1,   142,    27,   145,   141,    -1,    30,
      80,    80,    80,    -1,    -1,    32,    80,    80,   148,    81,
      -1,   117,    -1,   118,    -1,   120,    -1,   122,    -1,   125,
      -1,   130,    -1,   132,    -1,   128,    -1,   133,    -1,   137,
      -1,   138,    -1,   144,    -1,   139,    -1,   146,    -1,   147,
      -1,    -1,   149,    -1,   150,     6,   149,    -1,   150,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   152,   156,   157,   158,   161,   162,   169,
     173,   179,   185,   190,   195,   204,   224,   228,   234,   238,
     248,   252,   267,   273,   297,   308,   321,   325,   329,   333,
     351,   359,   359,   362,   366,   366,   372,   374,   378,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   434,   438,   444,   448,   454,   458,   468,   472,   472,
     495,   499,   507,   511,   515,   521,   527,   534,   538,   549,
     550,   551,   552,   559,   560,   573,   577,   584,   585,   589,
     598,   601,   598,   606,   609,   606,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   648,   648,   652,
     653,   665,   675,   675,   687,   687,   697,   697,   708,   709,
     710,   713,   713,   724,   725,   729,   729,   741,   741,   750,
     760,   767,   768,   769,   770,   771,   774,   775,   776,   779,
     780,   781,   785,   797,   820,   821,   822,   823,   827,   835,
     842,   842,   851,   871,   871,   874,   875,   875,   882,   888,
     888,   906,   907,   908,   909,   910,   911,   912,   913,   914,
     915,   916,   917,   918,   919,   920,   920,   927,   928,   932
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
  "TOK_AQUI", "TOK_ASIGNA_ATT", "TOK_ATACADO_ENEMIGO", "TOK_CAPTURA",
  "TOK_CAPTURA_SI", "TOK_CAPTURA_Y_JUEGA", "TOK_CAPTURA_Y_JUEGA_SI",
  "TOK_CASILLERO_INICIAL", "TOK_DESTINO_ANT", "TOK_EMPATA",
  "TOK_EMPATA_SI", "TOK_ENTABLERO", "TOK_ENZONA", "TOK_GANA",
  "TOK_GANA_SI", "TOK_JAQUEMATE", "TOK_JUEGA", "TOK_JUEGA_SI", "TOK_MARCA",
  "TOK_MUEVE", "TOK_MUEVE_SI", "TOK_IF", "TOK_OCUPADO",
  "TOK_OCUPADOENEMIGO", "TOK_OCUPADOPROPIO", "TOK_ORIGEN_ANT", "TOK_PARA",
  "TOK_PARA_SI", "TOK_PIERDE", "TOK_PIERDE_SI", "TOK_PIEZAS_EN_CAS",
  "TOK_TRANSFORMA", "TOK_REPITEPOS", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_EQUAL", "TOK_DEQUAL", "TOK_WHILE", "TOK_DO", "TOK_END", "','",
  "'('", "')'", "$accept", "word_or_string", "word_or_string_list",
  "number_list", "instexpr_ahogado", "instexpr_atacado",
  "cantidad_piezas_preludio", "instexpr_cantidad_piezas",
  "instexpr_movidas_anteriores", "instexpr_entablero", "instexpr_enzona",
  "instexpr_jaquemate", "instexpr_ocupado", "instexpr_repitepos",
  "es_igual_a", "instexpr_logical", "@1", "instexpr", "instaction_final",
  "instaction_movs", "@2", "instaction_asigna_att", "instaction_juega",
  "instaction_para", "instaction_mueve", "instaction_marca_casillero",
  "instaction_set_marca", "instaction_get_marca", "instaction_goto_marca",
  "instaction_if", "@3", "@4", "instaction_while", "@5", "@6",
  "instaction", "instcode", "code_list", "instruction_attr",
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
     325,   326,   327,   328,   329,   330,    44,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    80,    81,    81,    81,    82,    82,    83,
      83,    84,    85,    85,    85,    86,    86,    86,    87,    87,
      87,    87,    88,    89,    89,    90,    91,    91,    91,    91,
      92,    93,    93,    94,    95,    94,    94,    94,    94,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    97,    97,    97,    97,    97,    97,    98,    99,    98,
     100,   100,   101,   101,   101,   101,   101,   102,   102,   103,
     103,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     109,   110,   108,   112,   113,   111,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   115,   115,   116,
     116,   117,   119,   118,   121,   120,   123,   122,   124,   124,
     124,   126,   125,   127,   127,   129,   128,   131,   130,   132,
     133,   134,   134,   134,   134,   134,   135,   135,   135,   136,
     136,   136,   137,   137,   137,   137,   137,   137,   138,   139,
     140,   139,   141,   143,   142,   144,   145,   144,   146,   148,
     147,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   150,   150,   151
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
       3,     0,     4,     1,     2,     0,     4,     0,     4,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       2,     3,     3,     4,     3,     3,     3,     3,     2,     4,
       0,     5,     1,     0,     3,     1,     0,     4,     4,     0,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     166,     0,   102,   104,     0,   108,     0,     0,   113,     0,
       0,     0,   143,     0,     0,     0,   151,   152,   153,   154,
       0,   155,     0,   158,   156,   157,   159,   160,   161,   163,
     145,   162,   164,   165,   167,   169,     0,     2,     3,     0,
       0,     0,   106,   109,   117,   119,   114,   120,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,   111,   115,
     146,   166,     1,   101,     4,   103,   105,     0,   110,    98,
     135,   125,   124,   122,   121,   123,   129,   136,   134,   126,
     137,   132,   142,   144,   140,     0,   149,    98,    98,     0,
     168,     0,     5,     7,   107,    96,     0,    66,    63,     0,
      57,    51,     0,    53,     0,    62,     0,    78,     0,     0,
      67,     0,    55,     0,    58,    83,    88,    92,    86,    87,
      94,    93,    90,    79,    91,    89,    95,    97,    99,   118,
       0,   130,     0,   127,   133,   139,     0,   148,     0,   112,
     116,   147,     6,     8,     0,     0,    50,    12,    13,    14,
       9,    11,    18,    22,     0,     0,    26,    28,    27,    20,
       0,     0,     0,    41,    42,    17,    43,    44,    45,    46,
      47,    48,    49,    40,    65,    52,    54,    64,    77,    73,
      74,    76,     0,    78,     0,    72,    80,    68,    56,     0,
       0,    98,   131,   128,   141,   150,    60,     0,    31,    32,
       0,    10,    19,    24,    25,    29,    21,    30,    33,     0,
      16,    15,    34,     0,     0,    75,    71,    77,    69,    70,
      98,    59,     0,   100,    61,    38,    23,    39,     0,    36,
      37,    81,    84,    35,     0,    98,    82,     0,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    64,    82,    94,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   214,   173,   228,   174,   116,   117,
     189,   118,   119,   120,   121,   181,   122,   123,   124,   125,
     220,   234,   126,   190,   235,   127,   128,   129,    16,    17,
      40,    18,    41,    19,    67,    20,    21,    87,    22,    23,
      88,    24,    69,    25,    26,    76,    80,    77,    27,    28,
      29,   136,    83,    30,    54,    31,    89,    32,    33,   138,
      34,    35,    36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -98
static const yytype_int16 yypact[] =
{
     238,    41,   -98,   -98,    41,    41,    12,    41,    41,    41,
     260,    41,   -98,    41,    41,    41,   -98,   -98,   -98,   -98,
      14,   -98,    19,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
       0,   -98,   -98,   -98,   -98,    42,    32,   -98,   -98,    58,
      41,    41,   -98,    41,   -98,   -98,   -98,   -98,    41,    77,
      41,    77,    41,   -98,    41,    41,    41,    41,   -98,   -98,
     -98,   238,   -98,   -98,   -98,    18,    18,    80,   -98,   177,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,    43,   -98,   -98,
      44,    41,    18,   -98,    82,    41,   -98,   177,   177,    41,
     -98,    41,   -98,   -98,    85,   -98,    41,   -98,   -98,   128,
     -98,   -98,   128,   -98,   128,   -98,   128,    31,    26,   128,
     -98,   128,   -98,   128,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,    59,
      77,   -98,    77,   -98,   -98,   -98,    41,   -98,    41,    59,
      59,   -98,   -98,   -98,     2,     1,   -98,   -98,   -98,   -98,
      41,   -98,    41,   -98,    41,    41,    41,   -98,   -98,    41,
      90,   128,   128,   -98,   -98,    34,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,    45,    45,    45,    45,    54,   -98,
     -98,   -98,    94,    97,    29,   -98,    45,    45,    45,    41,
     128,   177,   -98,   -98,    18,    18,   -98,    99,   -98,   -98,
     128,   -98,   -98,    41,   -98,   -98,   -98,   -98,    45,   -28,
     -98,    18,   -98,   128,   101,   -98,   -98,   -98,   -98,   -98,
     177,    18,    53,   -98,   -98,    45,   -98,   -98,   128,    45,
     -98,    59,   -98,    45,    36,   177,   -98,    -4,   -98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,    -1,   -39,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -38,   -98,   -98,   -85,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -69,   -98,   -97,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -73,   -72,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -20,   -98,   -98,   -98,   -98,
     -98,   -98,    40,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
      62,   -98,   -98
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,    65,    66,    42,    43,   196,    45,    46,    47,    52,
      53,   185,    55,    56,    57,   139,   140,   175,    44,   176,
      58,   177,    37,    38,   186,    59,   187,    60,   188,   191,
     182,    79,    62,   218,   178,    37,    38,   210,    37,    38,
     212,   213,    68,   198,   199,    37,    38,    70,    61,    78,
     227,    81,    71,    71,    84,    85,    86,   131,    37,    38,
     133,    63,    72,    72,    92,    92,   179,    73,    73,    74,
      74,   238,   198,   199,    75,    75,   208,   209,   197,   183,
     134,    92,   183,    93,   137,   135,    71,   219,   143,   179,
     142,   184,   191,   207,    91,   144,    72,   194,   216,   195,
     217,    73,   224,    74,   230,   222,   180,   200,    75,   215,
     192,   236,   193,   212,   213,   225,   198,   199,   223,   130,
     132,   212,   213,    90,   198,   199,   211,   232,   229,   141,
       0,   145,   146,     0,     0,     0,     0,     0,   147,   148,
     149,     0,     0,   233,     0,     0,     0,     0,   231,   201,
     221,   202,     0,   203,   204,   205,     0,     0,   206,     0,
       0,     0,   150,   237,     0,   151,     0,     0,     0,     0,
       0,   152,     0,     0,   153,   154,     0,   180,   155,     0,
       0,    95,     0,     0,     0,   156,   157,   158,   159,     0,
       0,     0,     0,    92,    92,   160,     0,     0,   161,     0,
       0,     0,   226,     0,     0,   162,     0,     0,     0,     0,
      92,     0,     0,    96,     0,    97,     0,    98,    99,   100,
      92,   101,   102,     0,     0,   103,   104,     0,   105,   106,
     107,   108,     0,   109,     0,     0,     0,     0,   110,   111,
     112,   113,     0,   114,     0,     1,     2,     0,     0,     0,
     115,     3,     0,     4,     5,     6,     7,     0,     8,     9,
      10,     0,     0,    11,    37,    38,    12,    13,    14,    48,
      15,     0,     0,     0,    49,     0,     0,     0,     0,    50,
       0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
       1,    40,    41,     4,     5,     3,     7,     8,     9,    10,
      11,   108,    13,    14,    15,    87,    88,   102,     6,   104,
       6,   106,     4,     5,   109,     6,   111,    27,   113,    33,
       4,    51,     0,     4,     3,     4,     5,     3,     4,     5,
      68,    69,    43,    71,    72,     4,     5,    48,     6,    50,
      78,    52,     9,     9,    55,    56,    57,    77,     4,     5,
      80,     3,    19,    19,    65,    66,    35,    24,    24,    26,
      26,    75,    71,    72,    31,    31,   161,   162,    76,    53,
      81,    82,    53,     3,    85,     3,     9,   184,     3,    35,
      91,    65,    33,     3,    76,    96,    19,   136,     4,   138,
       3,    24,     3,    26,     3,   190,   107,   145,    31,   178,
     130,    75,   132,    68,    69,   200,    71,    72,   191,    76,
      76,    68,    69,    61,    71,    72,   165,    74,   213,    89,
      -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,   228,    -1,    -1,    -1,    -1,   220,   150,
     189,   152,    -1,   154,   155,   156,    -1,    -1,   159,    -1,
      -1,    -1,    34,   235,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    46,    47,    -1,   178,    50,    -1,
      -1,     4,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,   194,   195,    67,    -1,    -1,    70,    -1,
      -1,    -1,   203,    -1,    -1,    77,    -1,    -1,    -1,    -1,
     211,    -1,    -1,    36,    -1,    38,    -1,    40,    41,    42,
     221,    44,    45,    -1,    -1,    48,    49,    -1,    51,    52,
      53,    54,    -1,    56,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    -1,    66,    -1,     7,     8,    -1,    -1,    -1,
      73,    13,    -1,    15,    16,    17,    18,    -1,    20,    21,
      22,    -1,    -1,    25,     4,     5,    28,    29,    30,     9,
      32,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    13,    15,    16,    17,    18,    20,    21,
      22,    25,    28,    29,    30,    32,   117,   118,   120,   122,
     124,   125,   127,   128,   130,   132,   133,   137,   138,   139,
     142,   144,   146,   147,   149,   150,   151,     4,     5,    80,
     119,   121,    80,    80,     6,    80,    80,    80,     9,    14,
      19,    23,    80,    80,   143,    80,    80,    80,     6,     6,
      27,     6,     0,     3,    80,    81,    81,   123,    80,   131,
      80,     9,    19,    24,    26,    31,   134,   136,    80,   134,
     135,    80,    81,   141,    80,    80,    80,   126,   129,   145,
     149,    76,    80,     3,    82,     4,    36,    38,    40,    41,
      42,    44,    45,    48,    49,    51,    52,    53,    54,    56,
      61,    62,    63,    64,    66,    73,    97,    98,   100,   101,
     102,   103,   105,   106,   107,   108,   111,   114,   115,   116,
      76,   134,    76,   134,    80,     3,   140,    80,   148,   116,
     116,   141,    80,     3,    80,     3,     4,    10,    11,    12,
      34,    37,    43,    46,    47,    50,    57,    58,    59,    60,
      67,    70,    77,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    94,    96,    96,    96,    96,     3,    35,
      80,   104,     4,    53,    65,   106,    96,    96,    96,    99,
     112,    33,   134,   134,    81,    81,     3,    76,    71,    72,
      93,    80,    80,    80,    80,    80,    80,     3,    96,    96,
       3,    81,    68,    69,    93,   104,     4,     3,     4,   106,
     109,    81,    96,   115,     3,    96,    80,    78,    95,    96,
       3,   116,    74,    96,   110,   113,    75,   116,    75
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
#line 151 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 3:
#line 152 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 4:
#line 156 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(1) - (1)]) ); }
    break;

  case 5:
#line 157 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(2) - (2)]) ); }
    break;

  case 6:
#line 158 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(3) - (3)]) ); }
    break;

  case 7:
#line 161 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(1) - (1)]) ); }
    break;

  case 8:
#line 162 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(2) - (2)]) ); }
    break;

  case 9:
#line 169 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_ahogado( tipojuego, NULL );
    }
    break;

  case 10:
#line 173 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_ahogado( tipojuego, (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 11:
#line 179 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_atacado( tipojuego, NULL );
    }
    break;

  case 12:
#line 185 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = CUALQUIERA;
            init_parameters(); 
    }
    break;

  case 13:
#line 190 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = PROPIO;
            init_parameters(); 
    }
    break;

  case 14:
#line 195 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = ENEMIGO;
            init_parameters(); 
    }
    break;

  case 15:
#line 204 "qgames_parser.y"
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
#line 224 "qgames_parser.y"
    {
            tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (2)]), NULL, NULL );
            tipojuego_code_op_equal( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 17:
#line 228 "qgames_parser.y"
    { 
            tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (1)]), NULL, NULL );
    }
    break;

  case 18:
#line 234 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_destino_ant( tipojuego, NULL );
    }
    break;

  case 19:
#line 238 "qgames_parser.y"
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
#line 248 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_origen_ant( tipojuego, NULL );
    }
    break;

  case 21:
#line 252 "qgames_parser.y"
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
#line 267 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_entablero( tipojuego );
    }
    break;

  case 23:
#line 273 "qgames_parser.y"
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
#line 297 "qgames_parser.y"
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
#line 308 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ){
                tipojuego_code_jaquemate( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
            } else {
                qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (2)])) );
                yyerror( "Debe ser un tipo de pieza" );
            }
            FREE( (void*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 26:
#line 321 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL, NULL );
    }
    break;

  case 27:
#line 325 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, PROPIO, NULL, NULL );
    }
    break;

  case 28:
#line 329 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, ENEMIGO, NULL, NULL );
    }
    break;

  case 29:
#line 333 "qgames_parser.y"
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
        FREE( (void*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 30:
#line 351 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_op_false( tipojuego );
        NOT_IMPLEMENTED_WARN( "repite-posicion" );
    }
    break;

  case 33:
#line 362 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_not( tipojuego );
    }
    break;

  case 34:
#line 366 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 35:
#line 369 "qgames_parser.y"
    { 
                tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 36:
#line 372 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 37:
#line 374 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(3) - (3)]) );
    }
    break;

  case 38:
#line 378 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(1) - (3)]) );
    }
    break;

  case 50:
#line 396 "qgames_parser.y"
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
                      char* sin_pregunta = STRDUP( (char*) (yyvsp[(1) - (1)]) );
                      sin_pregunta[len-1] = 0;
                      if( tipojuego_get_att( tipojuego, last_pieza, sin_pregunta ) != NOT_FOUND ){
                          hay_algo = 1;
                          tipojuego_code_evalua_att( tipojuego, sin_pregunta );
                      }
                      FREE(sin_pregunta);
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
#line 434 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, EMPATA );
    }
    break;

  case 52:
#line 438 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, EMPATA );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 53:
#line 444 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, GANA );
    }
    break;

  case 54:
#line 448 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, GANA );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 55:
#line 454 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, PIERDE );
    }
    break;

  case 56:
#line 458 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, PIERDE );
            tipojuego_code_end_condblock( tipojuego );
     }
    break;

  case 57:
#line 468 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_casillero( tipojuego, NULL );
    }
    break;

  case 58:
#line 472 "qgames_parser.y"
    {  CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 59:
#line 472 "qgames_parser.y"
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
#line 495 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) );
    }
    break;

  case 61:
#line 499 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]) );
    }
    break;

  case 62:
#line 507 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_juega( tipojuego, NULL, 0 );
    }
    break;

  case 63:
#line 511 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_juega( tipojuego, NULL, 1 );
    }
    break;

  case 64:
#line 515 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_juega( tipojuego, NULL, 0 );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 65:
#line 521 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_juega( tipojuego, NULL, 1 );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 66:
#line 527 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_captura( tipojuego, NULL );
    }
    break;

  case 67:
#line 534 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_para( tipojuego );
    }
    break;

  case 68:
#line 538 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_para( tipojuego );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 69:
#line 549 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve" ); }
    break;

  case 70:
#line 550 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve" ); }
    break;

  case 71:
#line 551 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve" ); }
    break;

  case 72:
#line 552 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve" ); }
    break;

  case 73:
#line 559 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 74:
#line 560 "qgames_parser.y"
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
#line 573 "qgames_parser.y"
    { 
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_setmarca( tipojuego, (yyvsp[(2) - (3)]), (char*)(yyvsp[(3) - (3)]) );
    }
    break;

  case 76:
#line 577 "qgames_parser.y"
    { 
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_setmarca( tipojuego,  0, (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 77:
#line 584 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 78:
#line 585 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 79:
#line 589 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "marca" ); }
    break;

  case 80:
#line 598 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 81:
#line 601 "qgames_parser.y"
    {
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 83:
#line 606 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            (yyval) = tipojuego_code_start_block( tipojuego );
    }
    break;

  case 84:
#line 609 "qgames_parser.y"
    {
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 85:
#line 611 "qgames_parser.y"
    {
            tipojuego_code_continue_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_else_condblock( tipojuego );
            tipojuego_code_break_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_end_condblock( tipojuego );
            tipojuego_code_end_block( tipojuego, (yyvsp[(2) - (7)]) );
    }
    break;

  case 96:
#line 631 "qgames_parser.y"
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
#line 666 "qgames_parser.y"
    {  CHECK_TIPOJUEGO ;
                      CHECK_LAST_PIEZA;
                      tipojuego_add_tpieza_att( tipojuego, last_pieza, ((char*)(yyvsp[(2) - (3)])), (yyvsp[(3) - (3)]) );
                    }
    break;

  case 102:
#line 675 "qgames_parser.y"
    { CHECK_TIPOJUEGO; 
                     init_parameters(); }
    break;

  case 103:
#line 678 "qgames_parser.y"
    {
                     char*  dims[MAX_PARAMS]; int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                        dims[i] = ((char*)qgz_param_list[i].par);
                      }
                     tipojuego_genera_dimensiones( tipojuego, qgz_param_count, dims );
                   }
    break;

  case 104:
#line 687 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 105:
#line 688 "qgames_parser.y"
    { int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                       char* col = ((char*)qgz_param_list[i].par);
                       tipojuego_add_color( tipojuego, col );
                     }
                   }
    break;

  case 106:
#line 697 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 107:
#line 698 "qgames_parser.y"
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
#line 708 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 109:
#line 709 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 110:
#line 710 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 111:
#line 713 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, DROP, last_pieza, (char*)((yyvsp[(1) - (2)])) );
    }
    break;

  case 112:
#line 718 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 113:
#line 724 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 114:
#line 725 "qgames_parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 115:
#line 729 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, MOVE, last_pieza, (char*)((yyvsp[(1) - (2)])) );
    }
    break;

  case 116:
#line 734 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 117:
#line 741 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO; 
            change_to_code_mode(); 
            tipojuego_start_codeend( tipojuego );
    }
    break;

  case 118:
#line 745 "qgames_parser.y"
    {
            tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 119:
#line 750 "qgames_parser.y"
    { 
        if( tipojuego ){
            yyerror( "Ya fue definido el tipo juego" );
            YYERROR;
        } else {
            tipojuego = tipojuego_new( ((char*)(yyvsp[(2) - (2)])) );
        }
    }
    break;

  case 120:
#line 760 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        qgzprintf( "Definiendo %s", ((char*)(yyvsp[(2) - (2)])) );
        tipojuego_add_tipo_mov( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
    }
    break;

  case 121:
#line 767 "qgames_parser.y"
    { (yyval) =  NOTACION_PIEZA; }
    break;

  case 122:
#line 768 "qgames_parser.y"
    { (yyval) =  NOTACION_ORIGEN; }
    break;

  case 123:
#line 769 "qgames_parser.y"
    { (yyval) =  NOTACION_DESTINO; }
    break;

  case 124:
#line 770 "qgames_parser.y"
    { (yyval) =  NOTACION_MARCA ; }
    break;

  case 125:
#line 771 "qgames_parser.y"
    { (yyval) =  NOTACION_CAPTURA; }
    break;

  case 126:
#line 774 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 127:
#line 775 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 128:
#line 776 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 129:
#line 779 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 130:
#line 780 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 131:
#line 781 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 132:
#line 785 "qgames_parser.y"
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

  case 133:
#line 797 "qgames_parser.y"
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

  case 134:
#line 820 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN("notacion: mark"); }
    break;

  case 135:
#line 821 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN("notacion: captured_mark"); }
    break;

  case 138:
#line 827 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO; 
        tipojuego_add_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ); 
        if( last_pieza ) FREE( last_pieza );
        last_pieza = STRDUP( ((char*)(yyvsp[(2) - (2)])) );
    }
    break;

  case 139:
#line 835 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < (yyvsp[(4) - (4)]); i ++ ){
          tipojuego_add_pieza( tipojuego, ((char*)(yyvsp[(2) - (4)])), CASILLERO_POZO, ((char*)(yyvsp[(3) - (4)])) );
        }
    }
    break;

  case 140:
#line 842 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 141:
#line 842 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < qgz_param_count; i ++ ){
          tipojuego_add_pieza( tipojuego, ((char*)(yyvsp[(2) - (5)])), (char*)qgz_param_list[i].par, ((char*)(yyvsp[(3) - (5)])) );
        }
    }
    break;

  case 142:
#line 851 "qgames_parser.y"
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

  case 143:
#line 871 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 146:
#line 875 "qgames_parser.y"
    {
        tipojuego_add_secuencia_rep( tipojuego );
    }
    break;

  case 148:
#line 882 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        tipojuego_add_simetria( tipojuego, ((char*)(yyvsp[(2) - (4)])), (char*)(yyvsp[(3) - (4)]), (char*)(yyvsp[(4) - (4)]) );
    }
    break;

  case 149:
#line 888 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 150:
#line 888 "qgames_parser.y"
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
#line 2857 "qgames_parser.c"
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


#line 936 "qgames_parser.y"


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


