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
     TOK_COLOR = 265,
     TOK_DEFAULT = 266,
     TOK_DIRECTION = 267,
     TOK_DROP = 268,
     TOK_ENDING = 269,
     TOK_GAMETYPE = 270,
     TOK_MARK = 271,
     TOK_MOVE = 272,
     TOK_MOVETYPE = 273,
     TOK_NOTATION = 274,
     TOK_ONREPEAT = 275,
     TOK_ORIGIN = 276,
     TOK_PIECE = 277,
     TOK_PIECE_NAME = 278,
     TOK_REPEAT = 279,
     TOK_SEQUENCE = 280,
     TOK_START = 281,
     TOK_SYMMETRY = 282,
     TOK_TARGET = 283,
     TOK_ZONE = 284,
     TOK_SEPCODE = 285,
     TOK_AHOGADO = 286,
     TOK_ATACADO_ENEMIGO = 287,
     TOK_AND = 288,
     TOK_OR = 289,
     TOK_NOT = 290,
     TOK_CASILLERO_INICIAL = 291,
     TOK_EMPATA = 292,
     TOK_EMPATA_SI = 293,
     TOK_ENTABLERO = 294,
     TOK_ENZONA = 295,
     TOK_GANA = 296,
     TOK_GANA_SI = 297,
     TOK_JAQUEMATE = 298,
     TOK_JUEGA = 299,
     TOK_JUEGA_SI = 300,
     TOK_IF = 301,
     TOK_OCUPADO = 302,
     TOK_OCUPADOENEMIGO = 303,
     TOK_OCUPADOPROPIO = 304,
     TOK_PARA = 305,
     TOK_PARA_SI = 306,
     TOK_PIERDE = 307,
     TOK_PIERDE_SI = 308,
     TOK_TRANSFORMA = 309,
     TOK_WHILE = 310,
     TOK_DO = 311,
     TOK_END = 312
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
#define TOK_COLOR 265
#define TOK_DEFAULT 266
#define TOK_DIRECTION 267
#define TOK_DROP 268
#define TOK_ENDING 269
#define TOK_GAMETYPE 270
#define TOK_MARK 271
#define TOK_MOVE 272
#define TOK_MOVETYPE 273
#define TOK_NOTATION 274
#define TOK_ONREPEAT 275
#define TOK_ORIGIN 276
#define TOK_PIECE 277
#define TOK_PIECE_NAME 278
#define TOK_REPEAT 279
#define TOK_SEQUENCE 280
#define TOK_START 281
#define TOK_SYMMETRY 282
#define TOK_TARGET 283
#define TOK_ZONE 284
#define TOK_SEPCODE 285
#define TOK_AHOGADO 286
#define TOK_ATACADO_ENEMIGO 287
#define TOK_AND 288
#define TOK_OR 289
#define TOK_NOT 290
#define TOK_CASILLERO_INICIAL 291
#define TOK_EMPATA 292
#define TOK_EMPATA_SI 293
#define TOK_ENTABLERO 294
#define TOK_ENZONA 295
#define TOK_GANA 296
#define TOK_GANA_SI 297
#define TOK_JAQUEMATE 298
#define TOK_JUEGA 299
#define TOK_JUEGA_SI 300
#define TOK_IF 301
#define TOK_OCUPADO 302
#define TOK_OCUPADOENEMIGO 303
#define TOK_OCUPADOPROPIO 304
#define TOK_PARA 305
#define TOK_PARA_SI 306
#define TOK_PIERDE 307
#define TOK_PIERDE_SI 308
#define TOK_TRANSFORMA 309
#define TOK_WHILE 310
#define TOK_DO 311
#define TOK_END 312




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

char*  defname_actual( );

#define  CHECK_TIPOJUEGO   \
    if( !tipojuego ){ yyerror( "gametype no definido aun" ); YYERROR; }
#define  CHECK_LAST_PIEZA   \
    if( !last_pieza ){ yyerror( "pieza no definida" ); YYERROR; }

#define  NOT_IMPLEMENTED   \
    { yyerror( "Funcion no implementada" ); YYERROR; }

#define  NOT_IMPLEMENTED_WARN(f) \
    { yyerror( "Aviso: funcion " f " no implementada" ); }

void yyerror(const char *str) { 
    char  * define = defname_actual(  );
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
  char* define;
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
#line 313 "qgames_parser.c"

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
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      59,    60,     2,     2,    58,     2,     2,     2,     2,     2,
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
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    16,    18,    21,
      23,    26,    28,    30,    34,    37,    40,    42,    44,    46,
      49,    52,    53,    58,    62,    66,    68,    70,    72,    74,
      76,    78,    80,    82,    84,    87,    89,    92,    94,    97,
      99,   100,   104,   106,   109,   111,   114,   115,   116,   123,
     124,   125,   133,   135,   137,   139,   141,   143,   145,   147,
     149,   150,   152,   156,   160,   161,   165,   166,   170,   171,
     176,   178,   181,   185,   186,   191,   193,   196,   197,   202,
     203,   208,   211,   214,   216,   218,   220,   222,   224,   226,
     229,   233,   235,   238,   242,   246,   251,   255,   259,   263,
     267,   270,   275,   276,   282,   284,   285,   289,   291,   292,
     297,   302,   303,   309,   311,   313,   315,   317,   319,   321,
     323,   325,   327,   329,   331,   333,   335,   337,   339,   340,
     342,   346
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
     122,     0,    -1,     4,    -1,     5,    -1,    62,    -1,    63,
      62,    -1,    63,    58,    62,    -1,     3,    -1,    64,     3,
      -1,    31,    -1,    31,    62,    -1,    32,    -1,    39,    -1,
      40,    62,    62,    -1,    40,    62,    -1,    43,    62,    -1,
      47,    -1,    49,    -1,    48,    -1,    47,    62,    -1,    35,
      73,    -1,    -1,    73,    33,    72,    73,    -1,    73,    34,
      73,    -1,    59,    73,    60,    -1,    71,    -1,    65,    -1,
      66,    -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,
       4,    -1,    37,    -1,    38,    73,    -1,    41,    -1,    42,
      73,    -1,    52,    -1,    53,    73,    -1,    36,    -1,    -1,
      54,    76,    63,    -1,    44,    -1,    45,    73,    -1,    50,
      -1,    51,    73,    -1,    -1,    -1,    46,    73,    80,    87,
      81,    57,    -1,    -1,    -1,    55,    83,    73,    56,    84,
      87,    57,    -1,    77,    -1,    74,    -1,    79,    -1,    75,
      -1,    78,    -1,    82,    -1,     4,    -1,    85,    -1,    -1,
      86,    -1,    87,    30,    86,    -1,     7,    62,    62,    -1,
      -1,     8,    90,    63,    -1,    -1,    10,    92,    63,    -1,
      -1,    12,    62,    94,    64,    -1,    13,    -1,    13,    62,
      -1,    13,    62,    62,    -1,    -1,    95,     6,    97,    87,
      -1,    17,    -1,    17,    62,    -1,    -1,    98,     6,   100,
      87,    -1,    -1,    14,     6,   102,    87,    -1,    15,    62,
      -1,    18,    62,    -1,    23,    -1,    21,    -1,    28,    -1,
      16,    -1,     9,    -1,   105,    -1,   106,   105,    -1,   106,
      58,   105,    -1,   105,    -1,   107,   105,    -1,   107,    58,
     105,    -1,    19,    62,    62,    -1,    19,    62,    62,    62,
      -1,    19,    16,    62,    -1,    19,     9,    62,    -1,    19,
      11,   107,    -1,    19,    20,   106,    -1,    22,    62,    -1,
      26,    62,    62,     3,    -1,    -1,    26,    62,    62,   111,
      63,    -1,    63,    -1,    -1,    25,   114,   112,    -1,   113,
      -1,    -1,   113,    24,   116,   112,    -1,    27,    62,    62,
      62,    -1,    -1,    29,    62,    62,   119,    63,    -1,    88,
      -1,    89,    -1,    91,    -1,    93,    -1,    96,    -1,   101,
      -1,   103,    -1,    99,    -1,   104,    -1,   108,    -1,   109,
      -1,   115,    -1,   110,    -1,   117,    -1,   118,    -1,    -1,
     120,    -1,   121,     6,   120,    -1,   121,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   142,   146,   147,   148,   151,   152,   159,
     163,   169,   175,   181,   205,   216,   228,   232,   236,   240,
     254,   258,   258,   264,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   297,   301,   307,   311,   317,   321,   331,
     335,   335,   357,   361,   370,   374,   385,   388,   385,   393,
     396,   393,   407,   408,   409,   410,   411,   412,   413,   436,
     436,   440,   441,   453,   471,   471,   483,   483,   493,   493,
     504,   505,   506,   509,   509,   520,   521,   525,   525,   537,
     537,   546,   556,   562,   563,   564,   565,   566,   569,   570,
     571,   574,   575,   576,   580,   592,   615,   616,   617,   618,
     622,   630,   637,   637,   646,   666,   666,   669,   670,   670,
     677,   683,   683,   701,   702,   703,   704,   705,   706,   707,
     708,   709,   710,   711,   712,   713,   714,   715,   715,   722,
     723,   727
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_NUMBER", "TOK_WORD", "TOK_STRING",
  "TOK_SEPARATOR", "TOK_ATTR", "TOK_BOARD", "TOK_CAPTURED_MARK",
  "TOK_COLOR", "TOK_DEFAULT", "TOK_DIRECTION", "TOK_DROP", "TOK_ENDING",
  "TOK_GAMETYPE", "TOK_MARK", "TOK_MOVE", "TOK_MOVETYPE", "TOK_NOTATION",
  "TOK_ONREPEAT", "TOK_ORIGIN", "TOK_PIECE", "TOK_PIECE_NAME",
  "TOK_REPEAT", "TOK_SEQUENCE", "TOK_START", "TOK_SYMMETRY", "TOK_TARGET",
  "TOK_ZONE", "TOK_SEPCODE", "TOK_AHOGADO", "TOK_ATACADO_ENEMIGO",
  "TOK_AND", "TOK_OR", "TOK_NOT", "TOK_CASILLERO_INICIAL", "TOK_EMPATA",
  "TOK_EMPATA_SI", "TOK_ENTABLERO", "TOK_ENZONA", "TOK_GANA",
  "TOK_GANA_SI", "TOK_JAQUEMATE", "TOK_JUEGA", "TOK_JUEGA_SI", "TOK_IF",
  "TOK_OCUPADO", "TOK_OCUPADOENEMIGO", "TOK_OCUPADOPROPIO", "TOK_PARA",
  "TOK_PARA_SI", "TOK_PIERDE", "TOK_PIERDE_SI", "TOK_TRANSFORMA",
  "TOK_WHILE", "TOK_DO", "TOK_END", "','", "'('", "')'", "$accept",
  "word_or_string", "word_or_string_list", "number_list",
  "instexpr_ahogado", "instexpr_atacado", "instexpr_entablero",
  "instexpr_enzona", "instexpr_jaquemate", "instexpr_ocupado",
  "instexpr_logical", "@1", "instexpr", "instaction_final",
  "instaction_movs", "@2", "instaction_juega", "instaction_para",
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
     305,   306,   307,   308,   309,   310,   311,   312,    44,    40,
      41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    63,    64,    64,    65,
      65,    66,    67,    68,    68,    69,    70,    70,    70,    70,
      71,    72,    71,    71,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    75,
      76,    75,    77,    77,    78,    78,    80,    81,    79,    83,
      84,    82,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    87,    87,    88,    90,    89,    92,    91,    94,    93,
      95,    95,    95,    97,    96,    98,    98,   100,    99,   102,
     101,   103,   104,   105,   105,   105,   105,   105,   106,   106,
     106,   107,   107,   107,   108,   108,   108,   108,   108,   108,
     109,   110,   111,   110,   112,   114,   113,   115,   116,   115,
     117,   119,   118,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   122
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     3,     1,     2,     1,
       2,     1,     1,     3,     2,     2,     1,     1,     1,     2,
       2,     0,     4,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     2,     1,
       0,     3,     1,     2,     1,     2,     0,     0,     6,     0,
       0,     7,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     3,     3,     0,     3,     0,     3,     0,     4,
       1,     2,     3,     0,     4,     1,     2,     0,     4,     0,
       4,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     2,     3,     3,     4,     3,     3,     3,     3,
       2,     4,     0,     5,     1,     0,     3,     1,     0,     4,
       4,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     128,     0,    64,    66,     0,    70,     0,     0,    75,     0,
       0,     0,   105,     0,     0,     0,   113,   114,   115,   116,
       0,   117,     0,   120,   118,   119,   121,   122,   123,   125,
     107,   124,   126,   127,   129,   131,     0,     2,     3,     0,
       0,     0,    68,    71,    79,    81,    76,    82,     0,     0,
       0,     0,     0,   100,     0,     0,     0,     0,    73,    77,
     108,   128,     1,    63,     4,    65,    67,     0,    72,    60,
      97,    87,    86,    84,    83,    85,    91,    98,    96,    88,
      99,    94,   104,   106,   102,     0,   111,    60,    60,     0,
     130,     0,     5,     7,    69,    58,    39,    33,     0,    35,
       0,    42,     0,     0,    44,     0,    37,     0,    40,    49,
      53,    55,    52,    56,    54,    57,    59,    61,    80,     0,
      92,     0,    89,    95,   101,     0,   110,     0,    74,    78,
     109,     6,     8,    32,     9,    11,     0,    12,     0,     0,
      16,    18,    17,     0,    26,    27,    28,    29,    30,    31,
      25,    34,    36,    43,    46,    45,    38,     0,     0,    60,
      93,    90,   103,   112,    10,    20,    14,    15,    19,     0,
      21,     0,    60,    41,     0,    62,    13,    24,     0,    23,
      47,    50,    22,     0,    60,    48,     0,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    64,    82,    94,   144,   145,   146,   147,   148,   149,
     150,   178,   151,   110,   111,   157,   112,   113,   114,   172,
     183,   115,   158,   184,   116,   117,   118,    16,    17,    40,
      18,    41,    19,    67,    20,    21,    87,    22,    23,    88,
      24,    69,    25,    26,    76,    80,    77,    27,    28,    29,
     125,    83,    30,    54,    31,    89,    32,    33,   127,    34,
      35,    36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -98
static const yytype_int16 yypact[] =
{
     141,    36,   -98,   -98,    36,    36,     5,    36,    36,    36,
     169,    36,   -98,    36,    36,    36,   -98,   -98,   -98,   -98,
      22,   -98,    24,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -19,   -98,   -98,   -98,   -98,    27,    20,   -98,   -98,    36,
      36,    36,   -98,    36,   -98,   -98,   -98,   -98,    36,   101,
      36,   101,    36,   -98,    36,    36,    36,    36,   -98,   -98,
     -98,   141,   -98,   -98,   -98,    14,    14,    33,   -98,    90,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,    16,   -98,   -98,
      50,    36,    14,   -98,    42,    36,   -98,    90,    90,    36,
     -98,    36,   -98,   -98,    55,   -98,   -98,   -98,    66,   -98,
      66,   -98,    66,    66,   -98,    66,   -98,    66,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,    31,   101,
     -98,   101,   -98,   -98,   -98,    36,   -98,    36,    31,    31,
     -98,   -98,   -98,   -98,    36,   -98,    66,   -98,    36,    36,
      36,   -98,   -98,    66,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,    19,    19,    19,    19,    19,    19,    36,    66,    90,
     -98,   -98,    14,    14,   -98,    19,    36,   -98,   -98,   -12,
     -98,    66,    90,    14,     1,   -98,   -98,   -98,    66,    19,
      31,   -98,    19,     6,    90,   -98,    -7,   -98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,    -1,   -39,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -76,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -97,   -72,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -34,   -98,   -98,   -98,   -98,   -98,
     -98,   -21,   -98,   -98,   -98,   -98,   -98,   -98,   -98,     8,
     -98,   -98
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,    65,    66,    42,    43,    60,    45,    46,    47,    52,
      53,    44,    55,    56,    57,   128,   129,    79,    37,    38,
      62,   170,   171,   159,   152,    71,   153,   154,    58,   155,
      59,   156,    72,    61,   170,   171,    93,    73,    63,    74,
      37,    38,    68,   120,    75,   124,   122,    70,   177,    78,
     187,    81,   170,   171,    84,    85,    86,   181,   132,    71,
     165,   159,   175,   185,    92,    92,    72,   169,   130,    90,
     133,    73,    91,    74,   119,     0,     0,     0,    75,     0,
     123,    92,   174,     0,   126,   160,   162,   161,   163,     0,
     131,     0,     0,     0,    95,   179,     0,   134,   135,     0,
     180,   136,   182,     0,     0,   137,   138,     0,   121,   139,
      71,     0,   186,   140,   141,   142,     0,    72,   173,     0,
       0,     0,    73,     0,    74,   143,    96,    97,    98,    75,
       0,    99,   100,   164,   101,   102,   103,   166,   167,   168,
     104,   105,   106,   107,   108,   109,     0,     0,     1,     2,
       0,     3,     0,     4,     5,     6,     7,     0,     8,     9,
      10,    92,    92,    11,     0,   176,    12,    13,    14,     0,
      15,     0,    92,    37,    38,     0,     0,     0,    48,     0,
      49,     0,     0,     0,     0,    50,     0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
       1,    40,    41,     4,     5,    24,     7,     8,     9,    10,
      11,     6,    13,    14,    15,    87,    88,    51,     4,     5,
       0,    33,    34,    30,   100,     9,   102,   103,     6,   105,
       6,   107,    16,     6,    33,    34,     3,    21,    39,    23,
       4,     5,    43,    77,    28,     3,    80,    48,    60,    50,
      57,    52,    33,    34,    55,    56,    57,    56,     3,     9,
     136,    30,   159,    57,    65,    66,    16,   143,    89,    61,
       4,    21,    58,    23,    58,    -1,    -1,    -1,    28,    -1,
      81,    82,   158,    -1,    85,   119,   125,   121,   127,    -1,
      91,    -1,    -1,    -1,     4,   171,    -1,    31,    32,    -1,
     172,    35,   178,    -1,    -1,    39,    40,    -1,    58,    43,
       9,    -1,   184,    47,    48,    49,    -1,    16,   157,    -1,
      -1,    -1,    21,    -1,    23,    59,    36,    37,    38,    28,
      -1,    41,    42,   134,    44,    45,    46,   138,   139,   140,
      50,    51,    52,    53,    54,    55,    -1,    -1,     7,     8,
      -1,    10,    -1,    12,    13,    14,    15,    -1,    17,    18,
      19,   162,   163,    22,    -1,   166,    25,    26,    27,    -1,
      29,    -1,   173,     4,     5,    -1,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    10,    12,    13,    14,    15,    17,    18,
      19,    22,    25,    26,    27,    29,    88,    89,    91,    93,
      95,    96,    98,    99,   101,   103,   104,   108,   109,   110,
     113,   115,   117,   118,   120,   121,   122,     4,     5,    62,
      90,    92,    62,    62,     6,    62,    62,    62,     9,    11,
      16,    20,    62,    62,   114,    62,    62,    62,     6,     6,
      24,     6,     0,    62,    62,    63,    63,    94,    62,   102,
      62,     9,    16,    21,    23,    28,   105,   107,    62,   105,
     106,    62,    63,   112,    62,    62,    62,    97,   100,   116,
     120,    58,    62,     3,    64,     4,    36,    37,    38,    41,
      42,    44,    45,    46,    50,    51,    52,    53,    54,    55,
      74,    75,    77,    78,    79,    82,    85,    86,    87,    58,
     105,    58,   105,    62,     3,   111,    62,   119,    87,    87,
     112,    62,     3,     4,    31,    32,    35,    39,    40,    43,
      47,    48,    49,    59,    65,    66,    67,    68,    69,    70,
      71,    73,    73,    73,    73,    73,    73,    76,    83,    30,
     105,   105,    63,    63,    62,    73,    62,    62,    62,    73,
      33,    34,    80,    63,    73,    86,    62,    60,    72,    73,
      87,    56,    73,    81,    84,    57,    87,    57
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
#line 141 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 3:
#line 142 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 4:
#line 146 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(1) - (1)]) ); }
    break;

  case 5:
#line 147 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(2) - (2)]) ); }
    break;

  case 6:
#line 148 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(2) - (3)]) ); }
    break;

  case 7:
#line 151 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(1) - (1)]) ); }
    break;

  case 8:
#line 152 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(2) - (2)]) ); }
    break;

  case 9:
#line 159 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_ahogado( tipojuego, NULL );
    }
    break;

  case 10:
#line 163 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_ahogado( tipojuego, (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 11:
#line 169 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_atacado( tipojuego, NULL );
    }
    break;

  case 12:
#line 175 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_entablero( tipojuego );
    }
    break;

  case 13:
#line 181 "qgames_parser.y"
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

  case 14:
#line 205 "qgames_parser.y"
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

  case 15:
#line 216 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ){
                NOT_IMPLEMENTED;
            } else {
                qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (2)])) );
                yyerror( "Debe ser un tipo de pieza" );
            }
    }
    break;

  case 16:
#line 228 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL );
    }
    break;

  case 17:
#line 232 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, PROPIO, NULL );
    }
    break;

  case 18:
#line 236 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_ocupado( tipojuego, NULL, ENEMIGO, NULL );
    }
    break;

  case 19:
#line 240 "qgames_parser.y"
    {
        char* nombre = (char*)(yyvsp[(2) - (2)]);
        CHECK_TIPOJUEGO;
        if( tipojuego_get_casillero( tipojuego, nombre ) != NOT_FOUND ){
             tipojuego_code_ocupado( tipojuego, nombre, CUALQUIERA, NULL );
        } else if( tipojuego_get_color( tipojuego, nombre ) != NOT_FOUND ){
             tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, nombre );
        } else {
            yyerror( "Ocupado?" );
            YYERROR;
        }
    }
    break;

  case 20:
#line 254 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_not( tipojuego );
    }
    break;

  case 21:
#line 258 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 22:
#line 261 "qgames_parser.y"
    { 
                tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 23:
#line 264 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 32:
#line 276 "qgames_parser.y"
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

  case 33:
#line 297 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, EMPATA );
    }
    break;

  case 34:
#line 301 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, EMPATA );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 35:
#line 307 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, GANA );
    }
    break;

  case 36:
#line 311 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, GANA );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 37:
#line 317 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_final( tipojuego, NULL, PIERDE );
    }
    break;

  case 38:
#line 321 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_final( tipojuego, NULL, PIERDE );
            tipojuego_code_end_condblock( tipojuego );
     }
    break;

  case 39:
#line 331 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_casillero( tipojuego, NULL );
    }
    break;

  case 40:
#line 335 "qgames_parser.y"
    {  CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 41:
#line 335 "qgames_parser.y"
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

  case 42:
#line 357 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_juega( tipojuego, NULL, 0 );
    }
    break;

  case 43:
#line 361 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_juega( tipojuego, NULL, 0 );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 44:
#line 370 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_para( tipojuego );
    }
    break;

  case 45:
#line 374 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_para( tipojuego );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 46:
#line 385 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 47:
#line 388 "qgames_parser.y"
    {
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 49:
#line 393 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_block( tipojuego );
    }
    break;

  case 50:
#line 396 "qgames_parser.y"
    {
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 51:
#line 398 "qgames_parser.y"
    {
            tipojuego_code_else_condblock( tipojuego );
            tipojuego_code_break_block( tipojuego );
            tipojuego_code_end_condblock( tipojuego );
            tipojuego_code_end_block( tipojuego );
    }
    break;

  case 58:
#line 413 "qgames_parser.y"
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

  case 63:
#line 454 "qgames_parser.y"
    {  CHECK_TIPOJUEGO ;
                      CHECK_LAST_PIEZA;
                      int  def = 0;
                      if( strcasecmp( ((char*)(yyvsp[(3) - (3)])), "false" ) == 0 ){
                          def = 0;
                      } else if( strcasecmp( ((char*)(yyvsp[(3) - (3)])), "true" ) == 0 ){
                          def = 1;
                      } else {
                          def = atoi( ((char*)(yyvsp[(3) - (3)])) );
                      }
                      tipojuego_add_tpieza_att( tipojuego, last_pieza, ((char*)(yyvsp[(2) - (3)])), def );
                    }
    break;

  case 64:
#line 471 "qgames_parser.y"
    { CHECK_TIPOJUEGO; 
                     init_parameters(); }
    break;

  case 65:
#line 474 "qgames_parser.y"
    {
                     char*  dims[MAX_PARAMS]; int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                        dims[i] = ((char*)qgz_param_list[i].par);
                      }
                     tipojuego_genera_dimensiones( tipojuego, qgz_param_count, dims );
                   }
    break;

  case 66:
#line 483 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 67:
#line 484 "qgames_parser.y"
    { int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                       char* col = ((char*)qgz_param_list[i].par);
                       tipojuego_add_color( tipojuego, col );
                     }
                   }
    break;

  case 68:
#line 493 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 69:
#line 494 "qgames_parser.y"
    {
                      int  dirs[MAX_PARAMS]; int i; 
                      tipojuego_add_direccion( tipojuego, ((char*)(yyvsp[(2) - (4)])) );
                      for( i = 0; i < qgz_param_count; i ++ ){
                          dirs[i] = qgz_param_list[i].par;
                      }
                      tipojuego_add_direccion_arr( tipojuego, ((char*)(yyvsp[(2) - (4)])), dirs );
                    }
    break;

  case 71:
#line 505 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 72:
#line 506 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 73:
#line 509 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, DROP, last_pieza, last_tmov );
    }
    break;

  case 74:
#line 514 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 76:
#line 521 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 77:
#line 525 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, MOVE, last_pieza, last_tmov );
    }
    break;

  case 78:
#line 530 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 79:
#line 537 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO; 
            change_to_code_mode(); 
            tipojuego_start_codeend( tipojuego );
    }
    break;

  case 80:
#line 541 "qgames_parser.y"
    {
            tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 81:
#line 546 "qgames_parser.y"
    { 
        if( tipojuego ){
            yyerror( "Ya fue definido el tipo juego" );
            YYERROR;
        } else {
            tipojuego = tipojuego_new( ((char*)(yyvsp[(2) - (2)])) );
        }
    }
    break;

  case 82:
#line 556 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_add_tipo_mov( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
    }
    break;

  case 83:
#line 562 "qgames_parser.y"
    { (yyval) =  NOTACION_PIEZA; }
    break;

  case 84:
#line 563 "qgames_parser.y"
    { (yyval) =  NOTACION_ORIGEN; }
    break;

  case 85:
#line 564 "qgames_parser.y"
    { (yyval) =  NOTACION_DESTINO; }
    break;

  case 86:
#line 565 "qgames_parser.y"
    { (yyval) =  NOTACION_MARCA ; }
    break;

  case 87:
#line 566 "qgames_parser.y"
    { (yyval) =  NOTACION_CAPTURA; }
    break;

  case 88:
#line 569 "qgames_parser.y"
    {  tipojuego_add_notacion_rep( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 91:
#line 574 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 92:
#line 575 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 93:
#line 576 "qgames_parser.y"
    {  tipojuego_add_notacion_def( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 94:
#line 580 "qgames_parser.y"
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

  case 95:
#line 592 "qgames_parser.y"
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

  case 96:
#line 615 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN("notacion: mark"); }
    break;

  case 97:
#line 616 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN("notacion: captured_mark"); }
    break;

  case 100:
#line 622 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO; 
        tipojuego_add_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ); 
        if( last_pieza ) free( last_pieza );
        last_pieza = strdup( ((char*)(yyvsp[(2) - (2)])) );
    }
    break;

  case 101:
#line 630 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < (yyvsp[(4) - (4)]); i ++ ){
          tipojuego_add_pieza( tipojuego, ((char*)(yyvsp[(2) - (4)])), CASILLERO_POZO, ((char*)(yyvsp[(3) - (4)])) );
        }
    }
    break;

  case 102:
#line 637 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 103:
#line 637 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < qgz_param_count; i ++ ){
          tipojuego_add_pieza( tipojuego, ((char*)(yyvsp[(2) - (5)])), (char*)qgz_param_list[i].par, ((char*)(yyvsp[(3) - (5)])) );
        }
    }
    break;

  case 104:
#line 646 "qgames_parser.y"
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

  case 105:
#line 666 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 108:
#line 670 "qgames_parser.y"
    {
        tipojuego_add_secuencia_rep( tipojuego );
    }
    break;

  case 110:
#line 677 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        tipojuego_add_simetria( tipojuego, ((char*)(yyvsp[(2) - (4)])), (char*)(yyvsp[(3) - (4)]), (char*)(yyvsp[(4) - (4)]) );
    }
    break;

  case 111:
#line 683 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 112:
#line 683 "qgames_parser.y"
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
#line 2475 "qgames_parser.c"
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


#line 731 "qgames_parser.y"


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


