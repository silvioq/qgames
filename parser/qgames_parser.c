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
     TOK_CREA = 270,
     TOK_DEFAULT = 271,
     TOK_DIRECTION = 272,
     TOK_DROP = 273,
     TOK_ENDING = 274,
     TOK_GAMETYPE = 275,
     TOK_MARK = 276,
     TOK_MOVE = 277,
     TOK_MOVETYPE = 278,
     TOK_NOTATION = 279,
     TOK_ONREPEAT = 280,
     TOK_ORIGIN = 281,
     TOK_PIECE = 282,
     TOK_PIECE_NAME = 283,
     TOK_REPEAT = 284,
     TOK_SEQUENCE = 285,
     TOK_START = 286,
     TOK_SYMMETRY = 287,
     TOK_TARGET = 288,
     TOK_ZONE = 289,
     TOK_SEPCODE = 290,
     TOK_AHOGADO = 291,
     TOK_AQUI = 292,
     TOK_ASIGNA_ATT = 293,
     TOK_ATACADO_ENEMIGO = 294,
     TOK_CAMBIA_COLOR = 295,
     TOK_CAPTURA = 296,
     TOK_CAPTURA_SI = 297,
     TOK_CAPTURA_Y_JUEGA = 298,
     TOK_CAPTURA_Y_JUEGA_SI = 299,
     TOK_CAPTURADAS_ENEMIGO = 300,
     TOK_CAPTURADAS_PROPIO = 301,
     TOK_CASILLERO_INICIAL = 302,
     TOK_DESTINO_ANT = 303,
     TOK_EMPATA = 304,
     TOK_EMPATA_SI = 305,
     TOK_ENTABLERO = 306,
     TOK_ENZONA = 307,
     TOK_GANA = 308,
     TOK_GANA_SI = 309,
     TOK_JAQUEMATE = 310,
     TOK_JUEGA = 311,
     TOK_JUEGA_SI = 312,
     TOK_GOTO_MARCA = 313,
     TOK_MARCA = 314,
     TOK_MUEVE = 315,
     TOK_MUEVE_SI = 316,
     TOK_IF = 317,
     TOK_OCUPADO = 318,
     TOK_OCUPADOENEMIGO = 319,
     TOK_OCUPADOPROPIO = 320,
     TOK_ORIGEN_ANT = 321,
     TOK_PARA = 322,
     TOK_PARA_SI = 323,
     TOK_PIERDE = 324,
     TOK_PIERDE_SI = 325,
     TOK_PIEZAS_EN_CAS = 326,
     TOK_TRANSFORMA = 327,
     TOK_REPITEPOS = 328,
     TOK_AND = 329,
     TOK_OR = 330,
     TOK_NOT = 331,
     TOK_EQUAL = 332,
     TOK_DEQUAL = 333,
     TOK_WHILE = 334,
     TOK_DO = 335,
     TOK_END = 336,
     TOK_BREAK = 337,
     TOK_GRAPH_BOARD = 338,
     TOK_GRAPH_PIECE = 339,
     TOK_GRAPH_SQUARE = 340,
     TOK_GRID = 341,
     TOK_CHECKERBOARD = 342,
     TOK_INTERSECTIONS = 343,
     TOK_HIGHLIGHTED = 344,
     TOK_STANDARD_GEM = 345,
     TOK_STANDARD_BISHOP = 346,
     TOK_STANDARD_KING = 347,
     TOK_STANDARD_KNIGHT = 348,
     TOK_STANDARD_PAWN = 349,
     TOK_STANDARD_QUEEN = 350,
     TOK_STANDARD_ROOK = 351
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
#define TOK_CREA 270
#define TOK_DEFAULT 271
#define TOK_DIRECTION 272
#define TOK_DROP 273
#define TOK_ENDING 274
#define TOK_GAMETYPE 275
#define TOK_MARK 276
#define TOK_MOVE 277
#define TOK_MOVETYPE 278
#define TOK_NOTATION 279
#define TOK_ONREPEAT 280
#define TOK_ORIGIN 281
#define TOK_PIECE 282
#define TOK_PIECE_NAME 283
#define TOK_REPEAT 284
#define TOK_SEQUENCE 285
#define TOK_START 286
#define TOK_SYMMETRY 287
#define TOK_TARGET 288
#define TOK_ZONE 289
#define TOK_SEPCODE 290
#define TOK_AHOGADO 291
#define TOK_AQUI 292
#define TOK_ASIGNA_ATT 293
#define TOK_ATACADO_ENEMIGO 294
#define TOK_CAMBIA_COLOR 295
#define TOK_CAPTURA 296
#define TOK_CAPTURA_SI 297
#define TOK_CAPTURA_Y_JUEGA 298
#define TOK_CAPTURA_Y_JUEGA_SI 299
#define TOK_CAPTURADAS_ENEMIGO 300
#define TOK_CAPTURADAS_PROPIO 301
#define TOK_CASILLERO_INICIAL 302
#define TOK_DESTINO_ANT 303
#define TOK_EMPATA 304
#define TOK_EMPATA_SI 305
#define TOK_ENTABLERO 306
#define TOK_ENZONA 307
#define TOK_GANA 308
#define TOK_GANA_SI 309
#define TOK_JAQUEMATE 310
#define TOK_JUEGA 311
#define TOK_JUEGA_SI 312
#define TOK_GOTO_MARCA 313
#define TOK_MARCA 314
#define TOK_MUEVE 315
#define TOK_MUEVE_SI 316
#define TOK_IF 317
#define TOK_OCUPADO 318
#define TOK_OCUPADOENEMIGO 319
#define TOK_OCUPADOPROPIO 320
#define TOK_ORIGEN_ANT 321
#define TOK_PARA 322
#define TOK_PARA_SI 323
#define TOK_PIERDE 324
#define TOK_PIERDE_SI 325
#define TOK_PIEZAS_EN_CAS 326
#define TOK_TRANSFORMA 327
#define TOK_REPITEPOS 328
#define TOK_AND 329
#define TOK_OR 330
#define TOK_NOT 331
#define TOK_EQUAL 332
#define TOK_DEQUAL 333
#define TOK_WHILE 334
#define TOK_DO 335
#define TOK_END 336
#define TOK_BREAK 337
#define TOK_GRAPH_BOARD 338
#define TOK_GRAPH_PIECE 339
#define TOK_GRAPH_SQUARE 340
#define TOK_GRID 341
#define TOK_CHECKERBOARD 342
#define TOK_INTERSECTIONS 343
#define TOK_HIGHLIGHTED 344
#define TOK_STANDARD_GEM 345
#define TOK_STANDARD_BISHOP 346
#define TOK_STANDARD_KING 347
#define TOK_STANDARD_KNIGHT 348
#define TOK_STANDARD_PAWN 349
#define TOK_STANDARD_QUEEN 350
#define TOK_STANDARD_ROOK 351




/* Copy the first part of user declarations.  */
#line 1 "qgames_parser.y"

/****************************************************************************
 * Copyright (c) 2009-2010 Silvio Quadri                                    *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, distribute with modifications, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is    *
 * furnished to do so, subject to the following conditions:                 *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 ****************************************************************************/

#include  <stdio.h>
#include  <stdarg.h>
#include  <string.h>
#include  <stdlib.h>
#include  <errno.h>
#include  <qgames.h>
#include  <qgames_analyzer.h>
#include  "qgames_code_impl.h"



typedef  struct StrParam {
  int   typ;
  union {
      long  par;
      char* str;
 };
} str_param;


static  int    qgz_verbose  = 0;

static  str_param*  qgz_param_list  = NULL;
static  int    qgz_param_count = 0;
static  void  add_parameter( int  type, long param );
static  void  init_parameters( );

#define  MAX_PARAMS   32

#define YYSTYPE long
#define YYDEBUG 1

extern  int  qgzlineno;
extern FILE* qgzin;

static  Tipojuego*   tipojuego  = NULL;
static  char*        last_pieza = NULL;
static  long         last_block = 0;
static  long         html_color1, html_color2;
static  long         graph_dim1, graph_dim2;

const  char*  defname_actual( );

#define  CHECK_TIPOJUEGO   \
    if( !tipojuego ){ yyerror( "gametype no definido aun" ); YYERROR; }\
    if( !qg_tipojuego_valido( tipojuego ) ){ yyerror( "tipojuego no es valido" ); YYERROR; }
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
#line 414 "qgames_parser.c"

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
#define YYLAST   385

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  211
/* YYNRULES -- Number of states.  */
#define YYNSTATES  304

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   351

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      99,   100,     2,     2,    97,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    98,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     101,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96
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
     151,   152,   156,   159,   163,   165,   168,   172,   177,   182,
     187,   189,   191,   194,   197,   199,   201,   204,   208,   212,
     216,   219,   221,   223,   227,   230,   233,   235,   238,   240,
     241,   242,   249,   251,   252,   253,   261,   263,   265,   267,
     269,   271,   273,   275,   277,   279,   281,   283,   285,   287,
     289,   290,   292,   296,   300,   301,   305,   306,   310,   311,
     316,   318,   321,   322,   327,   329,   332,   333,   338,   339,
     344,   347,   351,   354,   358,   362,   365,   366,   371,   375,
     380,   384,   386,   388,   390,   392,   394,   396,   398,   400,
     401,   403,   405,   407,   412,   416,   421,   426,   430,   434,
     438,   442,   445,   447,   449,   451,   453,   455,   457,   460,
     464,   466,   469,   473,   477,   482,   486,   490,   494,   498,
     501,   506,   507,   513,   515,   516,   520,   522,   523,   528,
     533,   534,   540,   542,   544,   546,   548,   550,   552,   554,
     556,   558,   560,   562,   564,   566,   568,   570,   572,   573,
     575,   579
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     184,     0,    -1,     4,    -1,     5,    -1,   103,    -1,   104,
     103,    -1,   104,    97,   103,    -1,     3,    -1,   105,     3,
      -1,    36,    -1,    36,   103,    -1,    39,    -1,    11,    -1,
      12,    -1,    13,    -1,   108,   104,    -1,   108,     3,    -1,
      45,    98,     3,    -1,    45,     3,    -1,   108,    -1,    48,
      -1,    48,   103,    -1,    66,    -1,    66,   103,    -1,    51,
      -1,    52,   103,   103,    -1,    52,   103,    -1,    55,   103,
      -1,    63,    -1,    65,    -1,    64,    -1,    63,   103,    -1,
      73,     3,    -1,    77,    -1,    78,    -1,    76,   119,    -1,
      -1,   119,    74,   118,   119,    -1,   119,    75,   119,    -1,
     119,   116,     3,    -1,     3,   116,   119,    -1,    99,   119,
     100,    -1,   117,    -1,   106,    -1,   107,    -1,   109,    -1,
     110,    -1,   111,    -1,   112,    -1,   113,    -1,   114,    -1,
     115,    -1,     4,    -1,    49,    -1,    50,   119,    -1,    53,
      -1,    54,   119,    -1,    69,    -1,    70,   119,    -1,    47,
      -1,    -1,    72,   122,   104,    -1,    40,    37,    -1,    40,
     103,    37,    -1,    40,    -1,    40,   103,    -1,    38,   103,
       3,    -1,    38,   103,    97,     3,    -1,    15,   103,   103,
     103,    -1,    15,   103,   103,    37,    -1,    56,    -1,    43,
      -1,    57,   119,    -1,    44,   119,    -1,    41,    -1,    67,
      -1,    68,   119,    -1,    60,    71,     4,    -1,    60,    71,
     130,    -1,    60,     4,     4,    -1,    60,   130,    -1,    37,
      -1,   103,    -1,    59,     3,   128,    -1,    59,   128,    -1,
      59,     3,    -1,    59,    -1,    58,     3,    -1,    58,    -1,
      -1,    -1,    62,   119,   133,   141,   134,    81,    -1,    82,
      -1,    -1,    -1,    79,   137,   119,    80,   138,   141,    81,
      -1,   123,    -1,   135,    -1,   124,    -1,   125,    -1,   120,
      -1,   132,    -1,   129,    -1,   131,    -1,   121,    -1,   127,
      -1,   126,    -1,   136,    -1,     4,    -1,   139,    -1,    -1,
     140,    -1,   141,    35,   140,    -1,     8,   103,     3,    -1,
      -1,     9,   144,   104,    -1,    -1,    14,   146,   104,    -1,
      -1,    17,   103,   148,   105,    -1,    18,    -1,    18,   103,
      -1,    -1,   149,     7,   151,   141,    -1,    22,    -1,    22,
     103,    -1,    -1,   152,     7,   154,   141,    -1,    -1,    19,
       7,   156,   141,    -1,    20,   103,    -1,     6,    97,     6,
      -1,     6,     6,    -1,     3,    97,     3,    -1,     3,   101,
       3,    -1,     3,     3,    -1,    -1,   160,   158,    97,   159,
      -1,   160,   158,   159,    -1,   160,   159,    97,   158,    -1,
     160,   159,   158,    -1,    90,    -1,    91,    -1,    92,    -1,
      93,    -1,    94,    -1,    95,    -1,    96,    -1,     3,    -1,
      -1,    87,    -1,    86,    -1,    88,    -1,    83,   163,   164,
     161,    -1,    83,   163,   103,    -1,    84,   162,   103,   159,
      -1,    84,   103,   162,   159,    -1,    84,   103,   103,    -1,
      85,   103,   103,    -1,    85,   103,     6,    -1,    85,   103,
      89,    -1,    23,   103,    -1,    28,    -1,    26,    -1,    33,
      -1,    21,    -1,    10,    -1,   167,    -1,   168,   167,    -1,
     168,    97,   167,    -1,   167,    -1,   169,   167,    -1,   169,
      97,   167,    -1,    24,   103,   103,    -1,    24,   103,   103,
     103,    -1,    24,    21,   103,    -1,    24,    10,   103,    -1,
      24,    16,   169,    -1,    24,    25,   168,    -1,    27,   103,
      -1,    31,   103,   103,     3,    -1,    -1,    31,   103,   103,
     173,   104,    -1,   104,    -1,    -1,    30,   176,   174,    -1,
     175,    -1,    -1,   175,    29,   178,   174,    -1,    32,   103,
     103,   103,    -1,    -1,    34,   103,   103,   181,   104,    -1,
     142,    -1,   143,    -1,   145,    -1,   147,    -1,   150,    -1,
     155,    -1,   157,    -1,   165,    -1,   153,    -1,   166,    -1,
     170,    -1,   171,    -1,   177,    -1,   172,    -1,   179,    -1,
     180,    -1,    -1,   182,    -1,   183,     7,   182,    -1,   183,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   195,   195,   196,   200,   201,   202,   205,   206,   213,
     217,   224,   230,   235,   240,   249,   269,   274,   279,   284,
     291,   295,   306,   310,   326,   332,   358,   370,   383,   387,
     391,   395,   413,   421,   421,   424,   428,   428,   434,   436,
     440,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   497,   501,   507,   511,   517,   521,   531,
     535,   535,   555,   559,   564,   568,   577,   582,   589,   593,
     600,   604,   608,   614,   620,   627,   631,   642,   653,   657,
     658,   665,   666,   679,   684,   692,   693,   697,   701,   713,
     716,   713,   721,   731,   736,   731,   748,   749,   750,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   778,
     778,   782,   783,   795,   806,   806,   818,   818,   828,   828,
     840,   841,   844,   844,   855,   856,   860,   860,   873,   873,
     882,   896,   897,   901,   902,   903,   906,   909,   910,   911,
     912,   915,   916,   917,   918,   919,   920,   921,   924,   926,
     929,   930,   931,   934,   938,   939,   948,   957,   958,   959,
     960,   969,   977,   978,   979,   980,   981,   984,   985,   986,
     989,   990,   991,   995,  1009,  1035,  1040,  1045,  1046,  1050,
    1059,  1068,  1068,  1079,  1099,  1099,  1102,  1103,  1103,  1110,
    1116,  1116,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1149,  1156,
    1157,  1161
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
  "TOK_COLOR", "TOK_CREA", "TOK_DEFAULT", "TOK_DIRECTION", "TOK_DROP",
  "TOK_ENDING", "TOK_GAMETYPE", "TOK_MARK", "TOK_MOVE", "TOK_MOVETYPE",
  "TOK_NOTATION", "TOK_ONREPEAT", "TOK_ORIGIN", "TOK_PIECE",
  "TOK_PIECE_NAME", "TOK_REPEAT", "TOK_SEQUENCE", "TOK_START",
  "TOK_SYMMETRY", "TOK_TARGET", "TOK_ZONE", "TOK_SEPCODE", "TOK_AHOGADO",
  "TOK_AQUI", "TOK_ASIGNA_ATT", "TOK_ATACADO_ENEMIGO", "TOK_CAMBIA_COLOR",
  "TOK_CAPTURA", "TOK_CAPTURA_SI", "TOK_CAPTURA_Y_JUEGA",
  "TOK_CAPTURA_Y_JUEGA_SI", "TOK_CAPTURADAS_ENEMIGO",
  "TOK_CAPTURADAS_PROPIO", "TOK_CASILLERO_INICIAL", "TOK_DESTINO_ANT",
  "TOK_EMPATA", "TOK_EMPATA_SI", "TOK_ENTABLERO", "TOK_ENZONA", "TOK_GANA",
  "TOK_GANA_SI", "TOK_JAQUEMATE", "TOK_JUEGA", "TOK_JUEGA_SI",
  "TOK_GOTO_MARCA", "TOK_MARCA", "TOK_MUEVE", "TOK_MUEVE_SI", "TOK_IF",
  "TOK_OCUPADO", "TOK_OCUPADOENEMIGO", "TOK_OCUPADOPROPIO",
  "TOK_ORIGEN_ANT", "TOK_PARA", "TOK_PARA_SI", "TOK_PIERDE",
  "TOK_PIERDE_SI", "TOK_PIEZAS_EN_CAS", "TOK_TRANSFORMA", "TOK_REPITEPOS",
  "TOK_AND", "TOK_OR", "TOK_NOT", "TOK_EQUAL", "TOK_DEQUAL", "TOK_WHILE",
  "TOK_DO", "TOK_END", "TOK_BREAK", "TOK_GRAPH_BOARD", "TOK_GRAPH_PIECE",
  "TOK_GRAPH_SQUARE", "TOK_GRID", "TOK_CHECKERBOARD", "TOK_INTERSECTIONS",
  "TOK_HIGHLIGHTED", "TOK_STANDARD_GEM", "TOK_STANDARD_BISHOP",
  "TOK_STANDARD_KING", "TOK_STANDARD_KNIGHT", "TOK_STANDARD_PAWN",
  "TOK_STANDARD_QUEEN", "TOK_STANDARD_ROOK", "','", "'='", "'('", "')'",
  "'x'", "$accept", "word_or_string", "word_or_string_list", "number_list",
  "instexpr_ahogado", "instexpr_atacado", "cantidad_piezas_preludio",
  "instexpr_cantidad_piezas", "instexpr_movidas_anteriores",
  "instexpr_entablero", "instexpr_enzona", "instexpr_jaquemate",
  "instexpr_ocupado", "instexpr_repitepos", "es_igual_a",
  "instexpr_logical", "@1", "instexpr", "instaction_final",
  "instaction_movs", "@2", "instaction_asigna_att", "instaction_crea",
  "instaction_juega", "instaction_para", "instaction_mueve",
  "instaction_marca_casillero", "instaction_set_marca",
  "instaction_get_marca", "instaction_goto_marca", "instaction_if", "@3",
  "@4", "instaction_break", "instaction_while", "@5", "@6", "instaction",
  "instcode", "code_list", "instruction_attr", "instruction_board", "@7",
  "instruction_color", "@8", "instruction_direction", "@9",
  "instruction_drop_prelude", "instruction_drop", "@10",
  "instruction_move_prelude", "instruction_move", "@11",
  "instruction_ending", "@12", "instruction_gametype",
  "instruction_graph_colors", "instruction_graph_dimensions",
  "instruction_graph_def_prelude", "instruction_graph_def",
  "instruction_graph_standard", "board_number", "board_std_type",
  "instruction_graph", "instruction_movetype",
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
     345,   346,   347,   348,   349,   350,   351,    44,    61,    40,
      41,   120
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   103,   104,   104,   104,   105,   105,   106,
     106,   107,   108,   108,   108,   109,   109,   109,   109,   109,
     110,   110,   110,   110,   111,   112,   112,   113,   114,   114,
     114,   114,   115,   116,   116,   117,   118,   117,   117,   117,
     117,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   120,   120,   120,   120,   121,
     122,   121,   121,   121,   121,   121,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   126,   126,   127,   127,   127,
     127,   128,   128,   129,   129,   130,   130,   131,   131,   133,
     134,   132,   135,   137,   138,   136,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   140,
     140,   141,   141,   142,   144,   143,   146,   145,   148,   147,
     149,   149,   151,   150,   152,   152,   154,   153,   156,   155,
     157,   158,   158,   159,   159,   159,   160,   161,   161,   161,
     161,   162,   162,   162,   162,   162,   162,   162,   163,   163,
     164,   164,   164,   165,   165,   165,   165,   165,   165,   165,
     165,   166,   167,   167,   167,   167,   167,   168,   168,   168,
     169,   169,   169,   170,   170,   170,   170,   170,   170,   171,
     172,   173,   172,   174,   176,   175,   177,   178,   177,   179,
     181,   180,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   183,
     183,   184
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
       0,     3,     2,     3,     1,     2,     3,     4,     4,     4,
       1,     1,     2,     2,     1,     1,     2,     3,     3,     3,
       2,     1,     1,     3,     2,     2,     1,     2,     1,     0,
       0,     6,     1,     0,     0,     7,     1,     1,     1,     1,
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
     208,     0,   114,   116,     0,   120,     0,     0,   124,     0,
       0,     0,   184,     0,     0,     0,   149,     0,     0,   192,
     193,   194,   195,     0,   196,     0,   200,   197,   198,   199,
     201,   202,   203,   205,   186,   204,   206,   207,   209,   211,
       0,     2,     3,     0,     0,     0,   118,   121,   128,   130,
     125,   161,     0,     0,     0,     0,     0,   179,     0,     0,
       0,     0,   148,     0,   141,   142,   143,   144,   145,   146,
     147,     0,     0,     0,   122,   126,   187,   208,     1,   113,
       4,   115,   117,     0,   110,   176,   166,   165,   163,   162,
     164,   170,   177,   175,   167,   178,   173,   183,   185,   181,
       0,   190,   151,   150,   152,   154,   136,   157,     0,     0,
     159,   160,   158,   110,   110,     0,   210,     0,     5,     7,
     119,   108,     0,     0,    64,    74,    71,     0,    59,    53,
       0,    55,     0,    70,     0,    88,     0,     0,     0,    75,
       0,    57,     0,    60,    93,    92,   100,   104,    96,    98,
      99,   106,   105,   102,   103,   101,    97,   107,   109,   111,
     129,     0,   171,     0,   168,   174,   180,     0,   189,     0,
       0,   153,     0,   156,   155,   123,   127,   188,     6,     8,
       0,     0,    62,    65,     0,    52,    12,    13,    14,     9,
      11,     0,    20,    24,     0,     0,    28,    30,    29,    22,
       0,     0,     0,    43,    44,    19,    45,    46,    47,    48,
      49,    50,    51,    42,    73,    54,    56,    72,    87,     0,
      81,    82,    84,     0,    86,     0,    80,    89,    76,    58,
       0,     0,   110,   172,   169,   182,   191,     0,     0,     0,
     135,     0,     0,     0,    66,     0,    63,    33,    34,     0,
      10,    18,     0,    21,    26,    27,    31,    23,    32,    35,
       0,    16,    15,    36,     0,     0,    83,    79,    85,    77,
      78,   110,    61,     0,   112,   132,     0,     0,   138,     0,
     140,   133,   134,    69,    68,    67,    40,    17,    25,    41,
       0,    38,    39,    90,    94,   131,   137,   139,    37,     0,
     110,    91,     0,    95
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    80,    97,   120,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   265,   213,   290,   214,   146,   147,
     230,   148,   149,   150,   151,   152,   222,   153,   226,   154,
     155,   271,   299,   156,   157,   231,   300,   158,   159,   160,
      19,    20,    44,    21,    45,    22,    83,    23,    24,   113,
      25,    26,   114,    27,    84,    28,   238,   173,   170,   171,
      72,    63,   106,    29,    30,    91,    95,    92,    31,    32,
      33,   167,    98,    34,    58,    35,   115,    36,    37,   169,
      38,    39,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -212
static const yytype_int16 yypact[] =
{
     300,   107,  -212,  -212,   107,   107,    23,   107,   107,   107,
     176,   107,  -212,   107,   107,   107,    29,    59,   107,  -212,
    -212,  -212,  -212,    41,  -212,    43,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,    -3,  -212,  -212,  -212,  -212,    50,
      65,  -212,  -212,    66,   107,   107,  -212,  -212,  -212,  -212,
    -212,  -212,   107,   157,   107,   157,   107,  -212,   107,   107,
     107,   107,  -212,    78,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,    59,   107,    38,  -212,  -212,  -212,   300,  -212,  -212,
    -212,    20,    20,    72,   234,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,    28,  -212,  -212,    64,   107,    20,  -212,    74,
     107,  -212,  -212,  -212,  -212,  -212,  -212,  -212,    81,    81,
    -212,  -212,  -212,   234,   234,   107,  -212,   107,  -212,  -212,
      86,  -212,   107,   107,    30,  -212,  -212,   200,  -212,  -212,
     200,  -212,   200,  -212,   200,    90,    42,    48,   200,  -212,
     200,  -212,   200,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
      67,   157,  -212,   157,  -212,  -212,  -212,   107,  -212,   107,
      88,  -212,     8,  -212,  -212,    67,    67,  -212,  -212,  -212,
     107,    17,  -212,    61,    91,  -212,  -212,  -212,  -212,   107,
    -212,    12,   107,  -212,   107,   107,   107,  -212,  -212,   107,
     103,   200,   200,  -212,  -212,   142,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,    54,    54,    54,    54,  -212,    83,
    -212,  -212,  -212,   104,   130,    19,  -212,    54,    54,    54,
     107,   200,   234,  -212,  -212,    20,    20,    16,    18,    21,
    -212,   136,   155,    99,  -212,   167,  -212,  -212,  -212,   200,
    -212,  -212,   168,  -212,   107,  -212,  -212,  -212,  -212,    54,
      82,  -212,    20,  -212,   200,   169,  -212,  -212,  -212,  -212,
    -212,   234,    20,    63,  -212,  -212,   171,    81,  -212,   178,
    -212,  -212,  -212,  -212,  -212,  -212,    54,  -212,  -212,  -212,
     200,    54,  -212,    67,  -212,  -212,  -212,  -212,    54,    93,
     234,  -212,     5,  -212
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,    -1,   -43,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,    -9,  -212,  -212,  -101,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,   -23,  -212,   -26,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,   -32,   -95,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -211,  -104,  -212,  -212,
     131,  -212,  -212,  -212,  -212,   -19,  -212,  -212,  -212,  -212,
    -212,  -212,    92,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
     129,  -212,  -212
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      43,    81,    82,    46,    47,   174,    49,    50,    51,    56,
      57,   240,    59,    60,    61,   251,    71,    73,   175,   176,
     244,   172,   275,   269,    41,    42,    76,   237,   280,   215,
      48,   216,    62,   217,    41,    42,    94,   227,    86,   228,
     232,   229,    41,    42,   110,   219,    41,    42,    74,    87,
      75,    85,   223,    93,    88,    96,    89,    77,    99,   100,
     101,    90,   105,    41,    42,    78,   239,   182,   297,    79,
     107,   109,   112,   162,    86,   119,   164,   166,   224,   220,
     118,   118,    41,    42,   172,    87,   303,    41,    42,   179,
      88,   172,    89,   218,   237,   165,   118,    90,   246,   168,
     259,   260,   232,    41,    42,   241,   258,   224,   267,   242,
     252,    41,    42,   276,   245,   277,   178,   117,   279,   225,
     220,   180,   181,   183,   235,   161,   236,   111,   263,   264,
     273,   247,   248,   268,   278,   221,   283,   263,   264,   281,
     247,   248,   233,   294,   234,   261,    41,    42,   286,    64,
      65,    66,    67,    68,    69,    70,   263,   264,   282,   247,
     248,   163,   262,   291,   102,   103,   104,    86,   247,   248,
     285,   287,   292,   296,   301,   249,   293,   295,    87,   243,
      41,    42,   289,    88,   237,    89,    52,   272,   250,   298,
      90,   253,    53,   254,   255,   256,   266,    54,   257,   270,
     274,    55,   108,   184,   185,   302,   116,   177,     0,     0,
       0,   186,   187,   188,     0,     0,     0,     0,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,   118,   189,     0,   121,   190,
       0,     0,   284,     0,     0,   191,     0,     0,   192,   122,
       0,   193,   194,   288,     0,   195,     0,     0,     0,     0,
       0,   118,     0,   196,   197,   198,   199,     0,     0,     0,
       0,   118,   123,   200,   124,   125,   201,   126,   127,     0,
       0,   128,     0,   129,   130,     0,     0,   131,   132,     0,
     133,   134,   135,   136,   137,     0,   138,     0,     0,   202,
       0,   139,   140,   141,   142,     0,   143,     0,     1,     2,
       0,     0,     0,   144,     3,     0,   145,     4,     5,     6,
       7,     0,     8,     9,    10,     0,     0,    11,     0,     0,
      12,    13,    14,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    18
};

static const yytype_int16 yycheck[] =
{
       1,    44,    45,     4,     5,   109,     7,     8,     9,    10,
      11,     3,    13,    14,    15,     3,    17,    18,   113,   114,
       3,     3,     6,     4,     4,     5,    29,     6,   239,   130,
       7,   132,     3,   134,     4,     5,    55,   138,    10,   140,
      35,   142,     4,     5,     6,     3,     4,     5,     7,    21,
       7,    52,     4,    54,    26,    56,    28,     7,    59,    60,
      61,    33,    63,     4,     5,     0,   170,    37,   279,     3,
      71,    72,    73,    92,    10,     3,    95,     3,    59,    37,
      81,    82,     4,     5,     3,    21,    81,     4,     5,     3,
      26,     3,    28,     3,     6,    96,    97,    33,    37,   100,
     201,   202,    35,     4,     5,    97,     3,    59,     4,   101,
      98,     4,     5,    97,    97,    97,   117,    97,    97,    71,
      37,   122,   123,   124,   167,    97,   169,    89,    74,    75,
     231,    77,    78,     3,   238,   136,    37,    74,    75,     3,
      77,    78,   161,    80,   163,     3,     4,     5,   249,    90,
      91,    92,    93,    94,    95,    96,    74,    75,     3,    77,
      78,    97,   205,   264,    86,    87,    88,    10,    77,    78,
       3,     3,     3,   277,    81,   184,   271,     6,    21,   180,
       4,     5,   100,    26,     6,    28,    10,   230,   189,   290,
      33,   192,    16,   194,   195,   196,   219,    21,   199,   225,
     232,    25,    71,     3,     4,   300,    77,   115,    -1,    -1,
      -1,    11,    12,    13,    -1,    -1,    -1,    -1,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,   236,    36,    -1,     4,    39,
      -1,    -1,   243,    -1,    -1,    45,    -1,    -1,    48,    15,
      -1,    51,    52,   254,    -1,    55,    -1,    -1,    -1,    -1,
      -1,   262,    -1,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,   272,    38,    73,    40,    41,    76,    43,    44,    -1,
      -1,    47,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    58,    59,    60,    -1,    62,    -1,    -1,    99,
      -1,    67,    68,    69,    70,    -1,    72,    -1,     8,     9,
      -1,    -1,    -1,    79,    14,    -1,    82,    17,    18,    19,
      20,    -1,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      30,    31,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    14,    17,    18,    19,    20,    22,    23,
      24,    27,    30,    31,    32,    34,    83,    84,    85,   142,
     143,   145,   147,   149,   150,   152,   153,   155,   157,   165,
     166,   170,   171,   172,   175,   177,   179,   180,   182,   183,
     184,     4,     5,   103,   144,   146,   103,   103,     7,   103,
     103,   103,    10,    16,    21,    25,   103,   103,   176,   103,
     103,   103,     3,   163,    90,    91,    92,    93,    94,    95,
      96,   103,   162,   103,     7,     7,    29,     7,     0,     3,
     103,   104,   104,   148,   156,   103,    10,    21,    26,    28,
      33,   167,   169,   103,   167,   168,   103,   104,   174,   103,
     103,   103,    86,    87,    88,   103,   164,   103,   162,   103,
       6,    89,   103,   151,   154,   178,   182,    97,   103,     3,
     105,     4,    15,    38,    40,    41,    43,    44,    47,    49,
      50,    53,    54,    56,    57,    58,    59,    60,    62,    67,
      68,    69,    70,    72,    79,    82,   120,   121,   123,   124,
     125,   126,   127,   129,   131,   132,   135,   136,   139,   140,
     141,    97,   167,    97,   167,   103,     3,   173,   103,   181,
     160,   161,     3,   159,   159,   141,   141,   174,   103,     3,
     103,   103,    37,   103,     3,     4,    11,    12,    13,    36,
      39,    45,    48,    51,    52,    55,    63,    64,    65,    66,
      73,    76,    99,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   117,   119,   119,   119,   119,     3,     3,
      37,   103,   128,     4,    59,    71,   130,   119,   119,   119,
     122,   137,    35,   167,   167,   104,   104,     6,   158,   159,
       3,    97,   101,   103,     3,    97,    37,    77,    78,   116,
     103,     3,    98,   103,   103,   103,   103,   103,     3,   119,
     119,     3,   104,    74,    75,   116,   128,     4,     3,     4,
     130,   133,   104,   119,   140,     6,    97,    97,   159,    97,
     158,     3,     3,    37,   103,     3,   119,     3,   103,   100,
     118,   119,     3,   141,    80,     6,   159,   158,   119,   134,
     138,    81,   141,    81
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
#line 195 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 3:
#line 196 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 4:
#line 200 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(1) - (1)]) ); }
    break;

  case 5:
#line 201 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(2) - (2)]) ); }
    break;

  case 6:
#line 202 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(3) - (3)]) ); }
    break;

  case 7:
#line 205 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(1) - (1)]) ); }
    break;

  case 8:
#line 206 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(2) - (2)]) ); }
    break;

  case 9:
#line 213 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_ahogado( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 10:
#line 217 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_ahogado( tipojuego, (char*)(yyvsp[(2) - (2)]) ) ) YYERROR;
            free(  (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 11:
#line 224 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_atacado( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 12:
#line 230 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = CUALQUIERA;
            init_parameters(); 
    }
    break;

  case 13:
#line 235 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = PROPIO;
            init_parameters(); 
    }
    break;

  case 14:
#line 240 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = ENEMIGO;
            init_parameters(); 
    }
    break;

  case 15:
#line 249 "qgames_parser.y"
    { 
            int i;
            char* cas = NULL; char* color = NULL; char *tpieza = NULL;
            for( i = 0; i < qgz_param_count; i ++ ){
                if( NOT_FOUND != qg_tipojuego_get_color( tipojuego, qgz_param_list[i].str ) ){
                    if( color ){ yyerror( "Color definido mas de una vez en cuentapiezas" ); YYERROR; }
                    color = qgz_param_list[i].str ;
                } else if( NOT_FOUND != qg_tipojuego_get_casillero( tipojuego,  qgz_param_list[i].str ) ){
                    if( cas ) { yyerror( "Casillero definido mas de una vez en cuentapiezas" ); YYERROR; }
                    cas = qgz_param_list[i].str ;
                } else if( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, qgz_param_list[i].str ) ){
                    if( tpieza ){ yyerror( "Tipo de pieza definida mas de una vez en cuentapiezas" ); YYERROR; }
                    tpieza = qgz_param_list[i].str;
                } else {
                    qgzprintf( "Elemento no reconocido %s", qgz_param_list[i].str );
                    yyerror( "Elemento no reconocido en cuentapiezas" ); YYERROR;
                }
            }
            if( !tipojuego_code_cuenta_piezas( tipojuego, cas, (yyvsp[(1) - (2)]), color, tpieza ) ) YYERROR;
    }
    break;

  case 16:
#line 269 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (2)]), NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 17:
#line 274 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, ENEMIGO, NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, (yyvsp[(3) - (3)]) );
    }
    break;

  case 18:
#line 279 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, ENEMIGO, NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 19:
#line 284 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (1)]), NULL, NULL ) ) YYERROR;;
    }
    break;

  case 20:
#line 291 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_destino_ant( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 21:
#line 295 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != qg_tipojuego_get_casillero( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ){
                if( !tipojuego_code_destino_ant( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ) YYERROR;
            } else {
                qgzprintf( "Debe ser un casillero %s", ((char*)(yyvsp[(2) - (2)])) );
                yyerror( "Debe ser un casillero");
                YYERROR;
            }
            free( (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 22:
#line 306 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_origen_ant( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 23:
#line 310 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != qg_tipojuego_get_casillero( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ){
                if( !tipojuego_code_origen_ant( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ) YYERROR;
            } else {
                qgzprintf( "Debe ser un casillero %s", ((char*)(yyvsp[(2) - (2)])) );
                yyerror( "Debe ser un casillero");
                YYERROR;
            }
            free( (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 24:
#line 326 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_entablero( tipojuego ) ) YYERROR;
    }
    break;

  case 25:
#line 332 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            char*  zona = NULL;
            char*  tpieza = NULL;
            if( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (3)])) ) ){
                tpieza = ((char*)(yyvsp[(2) - (3)]));
            } else if( NOT_FOUND != qg_tipojuego_get_zona( tipojuego, ((char*)(yyvsp[(2) - (3)])) ) ) {
                zona  = ((char*)(yyvsp[(2) - (3)]));
            } else {
                qgzprintf( "%s debe ser un tipo de pieza o una zona", ((char*)(yyvsp[(2) - (3)]) ) );
                yyerror( "Instruccion enzona mal formada" );
            }

            if( tpieza && ( NOT_FOUND != qg_tipojuego_get_zona( tipojuego, ((char*)(yyvsp[(3) - (3)]))  ) ) ){
                zona  = ((char*)(yyvsp[(3) - (3)]));
            } 
            if( zona && ( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(3) - (3)])) ) ) ){
                tpieza = ((char*)(yyvsp[(3) - (3)]));
            }
            if( !zona || !tpieza ){
                yyerror( "Instruccion enzona mal formada" );
            }
            if( !tipojuego_code_enzona( tipojuego, zona, tpieza ) ) YYERROR;
            free( (char*) (yyvsp[(2) - (3)]) );
            free( (char*) (yyvsp[(3) - (3)]) );
    }
    break;

  case 26:
#line 358 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != qg_tipojuego_get_zona( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ) {
                if( !tipojuego_code_enzona( tipojuego, (char*)(yyvsp[(2) - (2)]), NULL ) ) YYERROR;
            } else { 
                qgzprintf( "%s debe ser una zona", ((char*)(yyvsp[(2) - (2)]) ) );
                yyerror( "Instruccion enzona mal formada" );
            }
            free( (char*) (yyvsp[(2) - (2)]) );
    }
    break;

  case 27:
#line 370 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ){
                if( !tipojuego_code_jaquemate( tipojuego, ((char*)(yyvsp[(2) - (2)])) ) ) YYERROR;
            } else {
                qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (2)])) );
                yyerror( "Debe ser un tipo de pieza" );
            }
            free( (void*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 28:
#line 383 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( !tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL, NULL ) ) YYERROR;
    }
    break;

  case 29:
#line 387 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( !tipojuego_code_ocupado( tipojuego, NULL, PROPIO, NULL, NULL ) ) YYERROR;
    }
    break;

  case 30:
#line 391 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( !tipojuego_code_ocupado( tipojuego, NULL, ENEMIGO, NULL, NULL ) ) YYERROR;
    }
    break;

  case 31:
#line 395 "qgames_parser.y"
    {
        char* nombre = (char*)(yyvsp[(2) - (2)]);
        CHECK_TIPOJUEGO;
        if( qg_tipojuego_get_casillero( tipojuego, nombre ) != NOT_FOUND ){
             if( !tipojuego_code_ocupado( tipojuego, nombre, CUALQUIERA, NULL, NULL ) ) YYERROR;
        } else if( qg_tipojuego_get_color( tipojuego, nombre ) != NOT_FOUND ){
             if( !tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, nombre, NULL ) ) YYERROR;
        } else if( qg_tipojuego_get_tipopieza( tipojuego, nombre ) != NOT_FOUND ){
             if( !tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL, nombre ) ) YYERROR;
        } else {
            yyerror( "Ocupado?" );
            YYERROR;
        }
        free( (void*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 32:
#line 413 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_op_false( tipojuego );
        NOT_IMPLEMENTED_WARN( "repite-posicion" );
    }
    break;

  case 35:
#line 424 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_not( tipojuego );
    }
    break;

  case 36:
#line 428 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 37:
#line 431 "qgames_parser.y"
    { 
                tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 38:
#line 434 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 39:
#line 436 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(3) - (3)]) );
    }
    break;

  case 40:
#line 440 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(1) - (3)]) );
    }
    break;

  case 52:
#line 458 "qgames_parser.y"
    {    
            CHECK_TIPOJUEGO;
            /* una direccion podria ser */
            if( qg_tipojuego_get_direccion( tipojuego, (char*)(yyvsp[(1) - (1)]) ) != NOT_FOUND ){
                    qgzprintf( "Direccion %s no esperada", (char*)(yyvsp[(1) - (1)]) );
                    yyerror( "Direccion no esperada" );
                    YYERROR;
            } else {
                if( qg_tipojuego_get_casillero( tipojuego, (char*)(yyvsp[(1) - (1)]) ) != NOT_FOUND ){
                    qgzprintf( "Casillero %s no esperado", (char*)(yyvsp[(1) - (1)]) );
                    yyerror( "Casillero no esperado" );
                    YYERROR;
                } else if( qg_tipojuego_get_att( tipojuego, last_pieza, (char*)(yyvsp[(1) - (1)]) ) != NOT_FOUND ) {
                      if( !tipojuego_code_evalua_att( tipojuego, (char*)(yyvsp[(1) - (1)]) ) ) YYERROR;
                } else {
                   int  len = strlen( (char*)(yyvsp[(1) - (1)]) );
                   int  hay_algo = 0;
                   if( len > 0 && ((char*)((yyvsp[(1) - (1)])))[len-1] == '?' ){
                      char* sin_pregunta = strdup( (char*) (yyvsp[(1) - (1)]) );
                      sin_pregunta[len-1] = 0;
                      if( qg_tipojuego_get_att( tipojuego, last_pieza, sin_pregunta ) != NOT_FOUND ){
                          hay_algo = 1;
                          if( !tipojuego_code_evalua_att( tipojuego, sin_pregunta ) ) YYERROR;
                      }
                      free(sin_pregunta);
                  }

                  if( !hay_algo ){
                    qgzprintf( "%s no es nada", (char*)(yyvsp[(1) - (1)]) );
                    yyerror( "Comando no reconocido" );
                    YYERROR;
                  }
                  free( (char*)(yyvsp[(1) - (1)]) );
                }
            }
    }
    break;

  case 53:
#line 497 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_final( tipojuego, NULL, EMPATA ) ) YYERROR;
    }
    break;

  case 54:
#line 501 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_final( tipojuego, NULL, EMPATA ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 55:
#line 507 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_final( tipojuego, NULL, GANA ) ) YYERROR;
    }
    break;

  case 56:
#line 511 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_final( tipojuego, NULL, GANA ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 57:
#line 517 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_final( tipojuego, NULL, PIERDE ) ) YYERROR;
    }
    break;

  case 58:
#line 521 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_final( tipojuego, NULL, PIERDE ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
     }
    break;

  case 59:
#line 531 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_casillero( tipojuego, NULL );
    }
    break;

  case 60:
#line 535 "qgames_parser.y"
    {  CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 61:
#line 535 "qgames_parser.y"
    {
                    int    i;
                    char*  color = NULL;
                    for( i = 0; i < qgz_param_count; i ++ ){
                        int x = qg_tipojuego_get_color( tipojuego, qgz_param_list[i].str );
                        if( x != NOT_FOUND ){
                            color = qgz_param_list[i].str;
                            break;
                        }
                    }
                    for( i = 0; i < qgz_param_count; i ++ ){
                        if( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, qgz_param_list[i].str ) ){
                            qgzprintf( "Se va a transformar a %s %s", qgz_param_list[i].str, color );
                            if( !tipojuego_code_transforma( tipojuego, NOCOLOR, color, qgz_param_list[i].str, 0 ) ) YYERROR;
                        } else if ( NOT_FOUND != qg_tipojuego_get_color( tipojuego, qgz_param_list[i].str ) ){
                            qgzprintf( "Parametro incorrecto en transforma: %s", qgz_param_list[i].str ); 
                            yyerror( "Error de parametros en transforma, debe ser color o tipo de pieza" );
                        }
                    }
    }
    break;

  case 62:
#line 555 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, CAMBIOCOLOR, NULL, NULL, FROM_AQUI ) ) YYERROR; 
    }
    break;

  case 63:
#line 559 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, NOCOLOR, (char*)(yyvsp[(2) - (3)]), NULL, FROM_AQUI ) ) YYERROR; 
            free( (char*)(yyvsp[(2) - (3)]) );
    }
    break;

  case 64:
#line 564 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, CAMBIOCOLOR, NULL, NULL, 0 ) ) YYERROR; 
    }
    break;

  case 65:
#line 568 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, NOCOLOR, (char*)(yyvsp[(2) - (2)]), NULL, 0 ) ) YYERROR; 
            free( (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 66:
#line 577 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          if( !tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) ) ) YYERROR;
          free( (char*)(yyvsp[(2) - (3)]) );
    }
    break;

  case 67:
#line 582 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          if( !tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]) ) ) YYERROR;
          free( (char*)(yyvsp[(2) - (4)]) );
    }
    break;

  case 68:
#line 589 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            NOT_IMPLEMENTED_WARN( "crea" );
    }
    break;

  case 69:
#line 593 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            NOT_IMPLEMENTED_WARN( "crea" );
    }
    break;

  case 70:
#line 600 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_juega( tipojuego, NULL, 0 ) ) YYERROR;
    }
    break;

  case 71:
#line 604 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_juega( tipojuego, NULL, 1 ) ) YYERROR;
    }
    break;

  case 72:
#line 608 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_juega( tipojuego, NULL, 0 ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 73:
#line 614 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_juega( tipojuego, NULL, 1 ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 74:
#line 620 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_captura( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 75:
#line 627 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_para( tipojuego );
    }
    break;

  case 76:
#line 631 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_para( tipojuego );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 77:
#line 642 "qgames_parser.y"
    { 
                          CHECK_TIPOJUEGO;
                          if( NOT_FOUND == qg_tipojuego_get_casillero( tipojuego, (char*)(yyvsp[(3) - (3)]) ) ){
                              qgzprintf( "%s debe ser un casillero", (char*)(yyvsp[(3) - (3)]) );
                              yyerror( "Debe ser un casillero" );
                              YYERROR;
                          } else {
                              if( !tipojuego_code_mueve( tipojuego, FROM_AQUI | TO_CASILLERO, 0, (char*)(yyvsp[(3) - (3)]) ) ) YYERROR;
                          }
                          free( (char*)(yyvsp[(3) - (3)]) );
     }
    break;

  case 78:
#line 653 "qgames_parser.y"
    { 
                          CHECK_TIPOJUEGO;
                          if( !tipojuego_code_mueve( tipojuego, FROM_AQUI | TO_MARCA, 0, (void*)(yyvsp[(3) - (3)]) ) ) YYERROR;
     }
    break;

  case 79:
#line 657 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve cas  => casillero" ); }
    break;

  case 80:
#line 658 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve      => marca" ); }
    break;

  case 81:
#line 665 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 82:
#line 666 "qgames_parser.y"
    {
                          CHECK_TIPOJUEGO;
                          if( NOT_FOUND == qg_tipojuego_get_casillero( tipojuego, (char*)(yyvsp[(1) - (1)]) ) ){
                              qgzprintf( "%s debe ser un casillero", (char*)(yyvsp[(1) - (1)]) );
                              yyerror( "Debe ser un casillero" );
                              YYERROR;
                          } else {
                              (yyval) = (yyvsp[(1) - (1)]);
                          }
    }
    break;

  case 83:
#line 679 "qgames_parser.y"
    { 
                        CHECK_TIPOJUEGO; 
                        if( !tipojuego_code_setmarca( tipojuego, (yyvsp[(2) - (3)]), (char*)(yyvsp[(3) - (3)]) ) ) YYERROR;
                        if( (char*)(yyvsp[(3) - (3)]) ) free( (char*)(yyvsp[(3) - (3)]) );
    }
    break;

  case 84:
#line 684 "qgames_parser.y"
    { 
                        CHECK_TIPOJUEGO; 
                        if( !tipojuego_code_setmarca( tipojuego,  0, (char*)(yyvsp[(2) - (2)]) ) ) YYERROR;
                        if( (char*)(yyvsp[(2) - (2)]) ) free( (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 85:
#line 692 "qgames_parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 86:
#line 693 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 87:
#line 697 "qgames_parser.y"
    {
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_gotomarca( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 88:
#line 701 "qgames_parser.y"
    {
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_gotomarca( tipojuego, 0 );
    }
    break;

  case 89:
#line 713 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 90:
#line 716 "qgames_parser.y"
    {
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 92:
#line 721 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !last_block ){
                yyerror( "Break por fuera de bloque" );
                YYERROR;
            }
            tipojuego_code_break_block( tipojuego, last_block );
    }
    break;

  case 93:
#line 731 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            (yyval) = tipojuego_code_start_block( tipojuego );
            // FIXME: Debe usar un stack de bloques.
            last_block = (yyval);
    }
    break;

  case 94:
#line 736 "qgames_parser.y"
    {
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 95:
#line 738 "qgames_parser.y"
    {
            tipojuego_code_continue_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_else_condblock( tipojuego );
            tipojuego_code_break_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_end_condblock( tipojuego );
            tipojuego_code_end_block( tipojuego, (yyvsp[(2) - (7)]) );
    }
    break;

  case 108:
#line 760 "qgames_parser.y"
    {   
            CHECK_TIPOJUEGO;
            /* una direccion podria ser */
            // qgzprintf( "Reconociendo %s", (char*)$1 );
            if( qg_tipojuego_get_direccion( tipojuego, (char*)(yyvsp[(1) - (1)]) ) != NOT_FOUND ){
                    if( !tipojuego_code_direccion( tipojuego, (char*)(yyvsp[(1) - (1)]) ) ) YYERROR;
            } else if( qg_tipojuego_get_casillero( tipojuego, (char*)(yyvsp[(1) - (1)]) ) != NOT_FOUND ){
                    if( !tipojuego_code_casillero( tipojuego, (char*)(yyvsp[(1) - (1)]) ) ) YYERROR;
            } else {
                    qgzprintf( "%s no es nada", (char*)(yyvsp[(1) - (1)]) );
                    yyerror( "Comando no reconocido" );
                    YYERROR;
            }
            free( (char*)(yyvsp[(1) - (1)]) );
    }
    break;

  case 113:
#line 796 "qgames_parser.y"
    {  CHECK_TIPOJUEGO ;
                      CHECK_LAST_PIEZA;
                      if( !tipojuego_add_tpieza_att( tipojuego, last_pieza, ((char*)(yyvsp[(2) - (3)])), (yyvsp[(3) - (3)]) ) ) YYERROR;
                      free( (char*)(yyvsp[(2) - (3)]));
                    }
    break;

  case 114:
#line 806 "qgames_parser.y"
    { CHECK_TIPOJUEGO; 
                     init_parameters(); }
    break;

  case 115:
#line 809 "qgames_parser.y"
    {
                     char*  dims[MAX_PARAMS]; int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                        dims[i] = ((char*)qgz_param_list[i].par);
                     }
                     qg_tipojuego_genera_dimensiones( tipojuego, qgz_param_count, dims );
                   }
    break;

  case 116:
#line 818 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 117:
#line 819 "qgames_parser.y"
    { int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                       char* col = ((char*)qgz_param_list[i].par);
                       qg_tipojuego_add_color( tipojuego, col );
                     }
                   }
    break;

  case 118:
#line 828 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 119:
#line 829 "qgames_parser.y"
    {
                      int  dirs[MAX_PARAMS]; int i; 
                      qg_tipojuego_add_direccion( tipojuego, ((char*)(yyvsp[(2) - (4)])) );
                      for( i = 0; i < qgz_param_count; i ++ ){
                          dirs[i] = qgz_param_list[i].par;
                      }
                      if( !qg_tipojuego_add_direccion_arr( tipojuego, ((char*)(yyvsp[(2) - (4)])), dirs ) ) YYERROR;
                      free( (char*)(yyvsp[(2) - (4)]));
                    }
    break;

  case 120:
#line 840 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 121:
#line 841 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 122:
#line 844 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, DROP, last_pieza, (char*)((yyvsp[(1) - (2)])) );
    }
    break;

  case 123:
#line 849 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 124:
#line 855 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 125:
#line 856 "qgames_parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 126:
#line 860 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, MOVE, last_pieza, (char*)((yyvsp[(1) - (2)])) );
        free( (char*)((yyvsp[(1) - (2)])) );
    }
    break;

  case 127:
#line 866 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 128:
#line 873 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO; 
            change_to_code_mode(); 
            tipojuego_start_codeend( tipojuego );
    }
    break;

  case 129:
#line 877 "qgames_parser.y"
    {
            tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 130:
#line 882 "qgames_parser.y"
    { 
        if( tipojuego ){
            yyerror( "Ya fue definido el tipo juego" );
            YYERROR;
        } else {
            tipojuego = qg_tipojuego_new( ((char*)(yyvsp[(2) - (2)])) );
            free((void*)(yyvsp[(2) - (2)]));
        }
    }
    break;

  case 131:
#line 896 "qgames_parser.y"
    { html_color1 = (yyvsp[(1) - (3)]); html_color2 = (yyvsp[(3) - (3)]); }
    break;

  case 132:
#line 897 "qgames_parser.y"
    { html_color1 = (yyvsp[(1) - (2)]); html_color2 = (yyvsp[(2) - (2)]);
                                      qgzprintf( "Frente: %x Fondo: %x", html_color1, html_color2 ); }
    break;

  case 133:
#line 901 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (3)]); graph_dim2 = (yyvsp[(3) - (3)]); }
    break;

  case 134:
#line 902 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (3)]); graph_dim2 = (yyvsp[(3) - (3)]); }
    break;

  case 135:
#line 903 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (2)]); graph_dim2 = (yyvsp[(2) - (2)]); qgzprintf( "%dx%d", (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]) ); }
    break;

  case 136:
#line 906 "qgames_parser.y"
    { graph_dim1 = 0; graph_dim2 = 0; html_color1 = 0; html_color2 = 0; }
    break;

  case 141:
#line 915 "qgames_parser.y"
    { (yyval) = STANDARD_GEM; }
    break;

  case 142:
#line 916 "qgames_parser.y"
    { (yyval) = STANDARD_BISHOP; }
    break;

  case 143:
#line 917 "qgames_parser.y"
    { (yyval) = STANDARD_KING; }
    break;

  case 144:
#line 918 "qgames_parser.y"
    { (yyval) = STANDARD_KNIGHT; }
    break;

  case 145:
#line 919 "qgames_parser.y"
    { (yyval) = STANDARD_PAWN; }
    break;

  case 146:
#line 920 "qgames_parser.y"
    { (yyval) = STANDARD_QUEEN ; }
    break;

  case 147:
#line 921 "qgames_parser.y"
    { (yyval) = STANDARD_ROOK; }
    break;

  case 148:
#line 924 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); 
                  qgzprintf( "Tablero %d", (yyvsp[(1) - (1)]) ); }
    break;

  case 149:
#line 926 "qgames_parser.y"
    { (yyval) = BOARD_ACTUAL; qgzprintf( "Tablero actual" ); }
    break;

  case 150:
#line 929 "qgames_parser.y"
    { (yyval) = TYPE_CHECKERBOARD; }
    break;

  case 151:
#line 930 "qgames_parser.y"
    { (yyval) = TYPE_GRID; }
    break;

  case 152:
#line 931 "qgames_parser.y"
    { (yyval) = TYPE_INTERSECTIONS; }
    break;

  case 153:
#line 934 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        if( !tipojuego_graph_tablero_std( tipojuego, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), graph_dim1, graph_dim2, html_color1, html_color2 ) ) YYERROR;
     }
    break;

  case 154:
#line 938 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-board file" ) }
    break;

  case 155:
#line 939 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( qg_tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(3) - (4)])) ) == NOT_FOUND ){ 
            qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(3) - (4)])) );
            yyerror( "Debe ser un tipo de pieza" ); YYERROR;
        }
        if( !tipojuego_graph_tipopieza_std( tipojuego, ((char*)(yyvsp[(3) - (4)])), (yyvsp[(2) - (4)]), graph_dim1, graph_dim2 ) ) YYERROR;
        free( (char*)(yyvsp[(3) - (4)]) );
    }
    break;

  case 156:
#line 948 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( qg_tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (4)])) ) == NOT_FOUND ){ 
            qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (4)])) );
            yyerror( "Debe ser un tipo de pieza" ); YYERROR;
        }
        if( !tipojuego_graph_tipopieza_std( tipojuego, ((char*)(yyvsp[(2) - (4)])), (yyvsp[(3) - (4)]), graph_dim1, graph_dim2 ) ) YYERROR;
        free( (char*)(yyvsp[(2) - (4)]) );
    }
    break;

  case 157:
#line 957 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-piece string" ); }
    break;

  case 158:
#line 958 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square file" ); }
    break;

  case 159:
#line 959 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square color" ); }
    break;

  case 160:
#line 960 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square highlighted" ); }
    break;

  case 161:
#line 969 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        qgzprintf( "Definiendo %s", ((char*)(yyvsp[(2) - (2)])) );
        tipojuego_add_tipo_mov( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
        free((void*)(yyvsp[(2) - (2)]));
    }
    break;

  case 162:
#line 977 "qgames_parser.y"
    { (yyval) =  NOTACION_PIEZA; }
    break;

  case 163:
#line 978 "qgames_parser.y"
    { (yyval) =  NOTACION_ORIGEN; }
    break;

  case 164:
#line 979 "qgames_parser.y"
    { (yyval) =  NOTACION_DESTINO; }
    break;

  case 165:
#line 980 "qgames_parser.y"
    { (yyval) =  NOTACION_MARCA ; }
    break;

  case 166:
#line 981 "qgames_parser.y"
    { (yyval) =  NOTACION_CAPTURA; }
    break;

  case 167:
#line 984 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_rep( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 168:
#line 985 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_rep( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 169:
#line 986 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_rep( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 170:
#line 989 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_def( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 171:
#line 990 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_def( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 172:
#line 991 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_def( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 173:
#line 995 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        if( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, (char*)(yyvsp[(2) - (3)]) ) ){
            if( !tipojuego_add_notacion_tpieza( tipojuego, (char*)(yyvsp[(2) - (3)]), NULL, (char*)(yyvsp[(3) - (3)]) ) ) YYERROR ;
        } else if ( NOT_FOUND != qg_tipojuego_get_tipomov( tipojuego, (char*)(yyvsp[(2) - (3)]) ) ){
            if( !tipojuego_add_notacion_tmov( tipojuego, (char*)(yyvsp[(2) - (3)]), (char*)(yyvsp[(3) - (3)]) ) ) YYERROR ;
        } else {
            qgzprintf( "%s debe ser un tipo de pieza o un tipo de movimiento", (char*)(yyvsp[(2) - (3)]) );
            yyerror( "Notacion mal formada" );
            YYERROR;
        }
        free( (char*)(yyvsp[(2) - (3)]) );
        free( (char*)(yyvsp[(3) - (3)]) );
     }
    break;

  case 174:
#line 1009 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        char* tpieza; char* color; char* abbr;
        if( NOT_FOUND != qg_tipojuego_get_tipopieza( tipojuego, (char*)(yyvsp[(2) - (4)]) ) ){
            tpieza = (char*)(yyvsp[(2) - (4)]);
        } else {
            qgzprintf( "%s debe ser un tipo de pieza" );
            yyerror( "Notacion mal formada (tipo de pieza incorrecta)" );
            YYERROR;
        }
        if( NOT_FOUND != qg_tipojuego_get_color( tipojuego, (char*)(yyvsp[(3) - (4)]) ) ){
            color = (char*)(yyvsp[(3) - (4)]);
            abbr  = (char*)(yyvsp[(4) - (4)]);
        } else if ( NOT_FOUND != qg_tipojuego_get_color( tipojuego, (char*)(yyvsp[(4) - (4)]) ) ){
            color = (char*)(yyvsp[(4) - (4)]);
            abbr  = (char*)(yyvsp[(3) - (4)]);
        } else {
            qgzprintf( "%s debe ser un color",  (char*)(yyvsp[(3) - (4)]) );
            yyerror( "Notacion mal formada (color incorrecto)" );
            YYERROR;
        } 
        if( !tipojuego_add_notacion_tpieza( tipojuego, tpieza, color, abbr ) ) YYERROR;
        free((void*)(yyvsp[(2) - (4)]));
        free((void*)(yyvsp[(3) - (4)]));
        free((void*)(yyvsp[(4) - (4)]));
    }
    break;

  case 175:
#line 1035 "qgames_parser.y"
    { 
                  CHECK_TIPOJUEGO;
                  tipojuego_set_notacion_marca( tipojuego, (char*)(yyvsp[(3) - (3)]), NULL );
                  free((void*)(yyvsp[(3) - (3)]));
             }
    break;

  case 176:
#line 1040 "qgames_parser.y"
    { 
                  CHECK_TIPOJUEGO;
                  tipojuego_set_notacion_marca( tipojuego, NULL, (char*)(yyvsp[(3) - (3)]) );
                  free((void*)(yyvsp[(3) - (3)]));
             }
    break;

  case 179:
#line 1050 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO; 
        tipojuego_add_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ); 
        if( last_pieza ) free( last_pieza );
        last_pieza = strdup( ((char*)(yyvsp[(2) - (2)])) );
        free( (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 180:
#line 1059 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < (yyvsp[(4) - (4)]); i ++ ){
            if( !tipojuego_add_pieza( tipojuego, ((char*)(yyvsp[(2) - (4)])), CASILLERO_POZO, ((char*)(yyvsp[(3) - (4)])) ) ) YYERROR;
        }
        free( (char*)(yyvsp[(2) - (4)]) );
        free( (char*)(yyvsp[(3) - (4)]) );
    }
    break;

  case 181:
#line 1068 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 182:
#line 1068 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int i;
        for( i = 0; i < qgz_param_count; i ++ ){
          if( !tipojuego_add_pieza( tipojuego, ((char*)(yyvsp[(2) - (5)])), (char*)qgz_param_list[i].par, ((char*)(yyvsp[(3) - (5)])) ) ) YYERROR;
        }
        free( (char*)(yyvsp[(2) - (5)]) );
        free( (char*)(yyvsp[(3) - (5)]) );
    }
    break;

  case 183:
#line 1079 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        int  i;
        for( i = 0; i < qgz_param_count; i ++ ){
            char* val1 =  (char*)qgz_param_list[i].par;
            int  color = qg_tipojuego_get_color( tipojuego, val1 );
            if( color && i < qgz_param_count - 1 ){
                char* val2 = (char*)qgz_param_list[i+1].par;
                int  tmov = qg_tipojuego_get_tipomov( tipojuego, val2 );
                if( tmov != NOT_FOUND ){
                    if( !tipojuego_add_secuencia( tipojuego, val1, val2 ) ) YYERROR;
                    i ++;
                } else {
                    if( !tipojuego_add_secuencia( tipojuego, val1, NULL ) ) YYERROR;
                }
            } else if( !tipojuego_add_secuencia( tipojuego, val1, NULL ) ) YYERROR;
        } 
    }
    break;

  case 184:
#line 1099 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 187:
#line 1103 "qgames_parser.y"
    {
        if( !tipojuego_add_secuencia_rep( tipojuego ) ) YYERROR;
    }
    break;

  case 189:
#line 1110 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        if( !tipojuego_add_simetria( tipojuego, ((char*)(yyvsp[(2) - (4)])), (char*)(yyvsp[(3) - (4)]), (char*)(yyvsp[(4) - (4)]) ) ) YYERROR;
    }
    break;

  case 190:
#line 1116 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 191:
#line 1116 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            char* color = (char*)(yyvsp[(3) - (5)]);
            char* zona  = (char*)(yyvsp[(2) - (5)]);
            if( qg_tipojuego_get_zona( tipojuego, zona ) == NOT_FOUND ){
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
#line 3305 "qgames_parser.c"
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


#line 1165 "qgames_parser.y"


/*
 *
 * 
 * 
 */










int   parser_qgames( FILE* f, char* filename, int flags ){

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
    
    // Desinicializo los parametros.
    init_parameters( );
    return 1;
}




/*
 * Agrega un parametro
 * */
static  void  add_parameter( int  type, long param ){
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

static  void  init_parameters(){ 
    int i;
    for( i = 0; i < qgz_param_count; i ++ ){
        if( qgz_param_list[i].typ == TOK_STRING ) free( qgz_param_list[i].str ) ;
    }
    qgz_param_count = 0; 
}

/*
 * Estos son los analizadores. Ojo, son no reentrantes ... deberia 
 * yo manejar algun tipo de semaforo!
 * */
Tipojuego*  parser_qgames_filename( char* filename, int flags ){
    int  ret;
    ret = parser_qgames( NULL, filename, flags );
    return( ret ? tipojuego : NULL );
}

Tipojuego*  parser_qgames_file    ( FILE* file, int flags ){
    int  ret;
    ret = parser_qgames( file, NULL, flags );
    return( ret ? tipojuego : NULL );
}
Tipojuego*  parser_qgames_string  ( char* string, int flags ){
    fprintf( stderr, "parser_qgames_string no implementado\n" );
    exit( EXIT_FAILURE );
}


