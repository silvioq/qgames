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
     TOK_LOGO = 276,
     TOK_MARK = 277,
     TOK_MOVE = 278,
     TOK_MOVETYPE = 279,
     TOK_NOTATION = 280,
     TOK_ONREPEAT = 281,
     TOK_ORIGIN = 282,
     TOK_PIECE = 283,
     TOK_PIECE_NAME = 284,
     TOK_REPEAT = 285,
     TOK_SEQUENCE = 286,
     TOK_START = 287,
     TOK_SYMMETRY = 288,
     TOK_TARGET = 289,
     TOK_ZONE = 290,
     TOK_SEPCODE = 291,
     TOK_AHOGADO = 292,
     TOK_AQUI = 293,
     TOK_ASIGNA_ATT = 294,
     TOK_ATACADO_ENEMIGO = 295,
     TOK_CAMBIA_COLOR = 296,
     TOK_CAPTURA = 297,
     TOK_CAPTURA_SI = 298,
     TOK_CAPTURA_Y_JUEGA = 299,
     TOK_CAPTURA_Y_JUEGA_SI = 300,
     TOK_CAPTURADAS_ENEMIGO = 301,
     TOK_CAPTURADAS_PROPIO = 302,
     TOK_CASILLERO_INICIAL = 303,
     TOK_DESTINO_ANT = 304,
     TOK_EMPATA = 305,
     TOK_EMPATA_SI = 306,
     TOK_ENTABLERO = 307,
     TOK_ENZONA = 308,
     TOK_GANA = 309,
     TOK_GANA_SI = 310,
     TOK_JAQUEMATE = 311,
     TOK_JUEGA = 312,
     TOK_JUEGA_SI = 313,
     TOK_GOTO_MARCA = 314,
     TOK_MARCA = 315,
     TOK_MUEVE = 316,
     TOK_MUEVE_SI = 317,
     TOK_IF = 318,
     TOK_OCUPADO = 319,
     TOK_OCUPADOENEMIGO = 320,
     TOK_OCUPADOPROPIO = 321,
     TOK_ORIGEN_ANT = 322,
     TOK_PARA = 323,
     TOK_PARA_SI = 324,
     TOK_PIERDE = 325,
     TOK_PIERDE_SI = 326,
     TOK_PIEZAS_EN_CAS = 327,
     TOK_TRANSFORMA = 328,
     TOK_REPITEPOS = 329,
     TOK_AND = 330,
     TOK_OR = 331,
     TOK_NOT = 332,
     TOK_EQUAL = 333,
     TOK_DEQUAL = 334,
     TOK_WHILE = 335,
     TOK_DO = 336,
     TOK_END = 337,
     TOK_BREAK = 338,
     TOK_GRAPH_BOARD = 339,
     TOK_GRAPH_PIECE = 340,
     TOK_GRAPH_SQUARE = 341,
     TOK_GRID = 342,
     TOK_CHECKERBOARD = 343,
     TOK_INTERSECTIONS = 344,
     TOK_HIGHLIGHTED = 345,
     TOK_STANDARD_GEM = 346,
     TOK_STANDARD_BISHOP = 347,
     TOK_STANDARD_KING = 348,
     TOK_STANDARD_KNIGHT = 349,
     TOK_STANDARD_PAWN = 350,
     TOK_STANDARD_QUEEN = 351,
     TOK_STANDARD_RECT = 352,
     TOK_STANDARD_ROOK = 353
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
#define TOK_LOGO 276
#define TOK_MARK 277
#define TOK_MOVE 278
#define TOK_MOVETYPE 279
#define TOK_NOTATION 280
#define TOK_ONREPEAT 281
#define TOK_ORIGIN 282
#define TOK_PIECE 283
#define TOK_PIECE_NAME 284
#define TOK_REPEAT 285
#define TOK_SEQUENCE 286
#define TOK_START 287
#define TOK_SYMMETRY 288
#define TOK_TARGET 289
#define TOK_ZONE 290
#define TOK_SEPCODE 291
#define TOK_AHOGADO 292
#define TOK_AQUI 293
#define TOK_ASIGNA_ATT 294
#define TOK_ATACADO_ENEMIGO 295
#define TOK_CAMBIA_COLOR 296
#define TOK_CAPTURA 297
#define TOK_CAPTURA_SI 298
#define TOK_CAPTURA_Y_JUEGA 299
#define TOK_CAPTURA_Y_JUEGA_SI 300
#define TOK_CAPTURADAS_ENEMIGO 301
#define TOK_CAPTURADAS_PROPIO 302
#define TOK_CASILLERO_INICIAL 303
#define TOK_DESTINO_ANT 304
#define TOK_EMPATA 305
#define TOK_EMPATA_SI 306
#define TOK_ENTABLERO 307
#define TOK_ENZONA 308
#define TOK_GANA 309
#define TOK_GANA_SI 310
#define TOK_JAQUEMATE 311
#define TOK_JUEGA 312
#define TOK_JUEGA_SI 313
#define TOK_GOTO_MARCA 314
#define TOK_MARCA 315
#define TOK_MUEVE 316
#define TOK_MUEVE_SI 317
#define TOK_IF 318
#define TOK_OCUPADO 319
#define TOK_OCUPADOENEMIGO 320
#define TOK_OCUPADOPROPIO 321
#define TOK_ORIGEN_ANT 322
#define TOK_PARA 323
#define TOK_PARA_SI 324
#define TOK_PIERDE 325
#define TOK_PIERDE_SI 326
#define TOK_PIEZAS_EN_CAS 327
#define TOK_TRANSFORMA 328
#define TOK_REPITEPOS 329
#define TOK_AND 330
#define TOK_OR 331
#define TOK_NOT 332
#define TOK_EQUAL 333
#define TOK_DEQUAL 334
#define TOK_WHILE 335
#define TOK_DO 336
#define TOK_END 337
#define TOK_BREAK 338
#define TOK_GRAPH_BOARD 339
#define TOK_GRAPH_PIECE 340
#define TOK_GRAPH_SQUARE 341
#define TOK_GRID 342
#define TOK_CHECKERBOARD 343
#define TOK_INTERSECTIONS 344
#define TOK_HIGHLIGHTED 345
#define TOK_STANDARD_GEM 346
#define TOK_STANDARD_BISHOP 347
#define TOK_STANDARD_KING 348
#define TOK_STANDARD_KNIGHT 349
#define TOK_STANDARD_PAWN 350
#define TOK_STANDARD_QUEEN 351
#define TOK_STANDARD_RECT 352
#define TOK_STANDARD_ROOK 353




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
#line 418 "qgames_parser.c"

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
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   376

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  216
/* YYNRULES -- Number of states.  */
#define YYNSTATES  312

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   353

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     101,   102,     2,     2,    99,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   100,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     103,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      95,    96,    97,    98
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
     187,   191,   193,   195,   198,   201,   203,   205,   208,   212,
     216,   220,   223,   225,   227,   231,   234,   237,   239,   242,
     244,   245,   246,   253,   255,   256,   257,   265,   267,   269,
     271,   273,   275,   277,   279,   281,   283,   285,   287,   289,
     291,   293,   294,   296,   300,   304,   305,   309,   310,   314,
     315,   320,   322,   325,   326,   331,   333,   336,   337,   342,
     343,   348,   351,   355,   358,   362,   366,   369,   370,   375,
     379,   384,   388,   390,   392,   394,   396,   398,   400,   402,
     404,   405,   407,   409,   411,   416,   420,   425,   430,   436,
     440,   444,   448,   452,   453,   457,   460,   462,   464,   466,
     468,   470,   472,   475,   479,   481,   484,   488,   492,   497,
     501,   505,   509,   513,   516,   521,   522,   528,   530,   531,
     535,   537,   538,   543,   548,   549,   555,   557,   559,   561,
     563,   565,   567,   569,   571,   573,   575,   577,   579,   581,
     583,   585,   587,   589,   590,   592,   596
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     188,     0,    -1,     4,    -1,     5,    -1,   105,    -1,   106,
     105,    -1,   106,    99,   105,    -1,     3,    -1,   107,     3,
      -1,    37,    -1,    37,   105,    -1,    40,    -1,    11,    -1,
      12,    -1,    13,    -1,   110,   106,    -1,   110,     3,    -1,
      46,   100,     3,    -1,    46,     3,    -1,   110,    -1,    49,
      -1,    49,   105,    -1,    67,    -1,    67,   105,    -1,    52,
      -1,    53,   105,   105,    -1,    53,   105,    -1,    56,   105,
      -1,    64,    -1,    66,    -1,    65,    -1,    64,   105,    -1,
      74,     3,    -1,    78,    -1,    79,    -1,    77,   121,    -1,
      -1,   121,    75,   120,   121,    -1,   121,    76,   121,    -1,
     121,   118,     3,    -1,     3,   118,   121,    -1,   101,   121,
     102,    -1,   119,    -1,   108,    -1,   109,    -1,   111,    -1,
     112,    -1,   113,    -1,   114,    -1,   115,    -1,   116,    -1,
     117,    -1,     4,    -1,    50,    -1,    51,   121,    -1,    54,
      -1,    55,   121,    -1,    70,    -1,    71,   121,    -1,    48,
      -1,    -1,    73,   124,   106,    -1,    41,    38,    -1,    41,
     105,    38,    -1,    41,    -1,    41,   105,    -1,    39,   105,
       3,    -1,    39,   105,    99,     3,    -1,    15,   105,   105,
     105,    -1,    15,   105,   105,    38,    -1,    15,   105,    38,
      -1,    57,    -1,    44,    -1,    58,   121,    -1,    45,   121,
      -1,    42,    -1,    68,    -1,    69,   121,    -1,    61,    72,
       4,    -1,    61,    72,   132,    -1,    61,     4,     4,    -1,
      61,   132,    -1,    38,    -1,   105,    -1,    60,     3,   130,
      -1,    60,   130,    -1,    60,     3,    -1,    60,    -1,    59,
       3,    -1,    59,    -1,    -1,    -1,    63,   121,   135,   143,
     136,    82,    -1,    83,    -1,    -1,    -1,    80,   139,   121,
      81,   140,   143,    82,    -1,   125,    -1,   137,    -1,   126,
      -1,   127,    -1,   122,    -1,   134,    -1,   131,    -1,   133,
      -1,   123,    -1,   129,    -1,   128,    -1,   138,    -1,     4,
      -1,   141,    -1,    -1,   142,    -1,   143,    36,   142,    -1,
       8,   105,     3,    -1,    -1,     9,   146,   106,    -1,    -1,
      14,   148,   106,    -1,    -1,    17,   105,   150,   107,    -1,
      18,    -1,    18,   105,    -1,    -1,   151,     7,   153,   143,
      -1,    23,    -1,    23,   105,    -1,    -1,   154,     7,   156,
     143,    -1,    -1,    19,     7,   158,   143,    -1,    20,   105,
      -1,     6,    99,     6,    -1,     6,     6,    -1,     3,    99,
       3,    -1,     3,   103,     3,    -1,     3,     3,    -1,    -1,
     162,   160,    99,   161,    -1,   162,   160,   161,    -1,   162,
     161,    99,   160,    -1,   162,   161,   160,    -1,    91,    -1,
      92,    -1,    93,    -1,    94,    -1,    95,    -1,    96,    -1,
      98,    -1,     3,    -1,    -1,    88,    -1,    87,    -1,    89,
      -1,    84,   165,   166,   163,    -1,    84,   165,   105,    -1,
      85,   164,   105,   161,    -1,    85,   105,   164,   161,    -1,
      85,   105,    97,   161,     6,    -1,    85,   105,   105,    -1,
      86,   105,   105,    -1,    86,   105,     6,    -1,    86,   105,
      90,    -1,    -1,    21,   169,   106,    -1,    24,   105,    -1,
      29,    -1,    27,    -1,    34,    -1,    22,    -1,    10,    -1,
     171,    -1,   172,   171,    -1,   172,    99,   171,    -1,   171,
      -1,   173,   171,    -1,   173,    99,   171,    -1,    25,   105,
     105,    -1,    25,   105,   105,   105,    -1,    25,    22,   105,
      -1,    25,    10,   105,    -1,    25,    16,   173,    -1,    25,
      26,   172,    -1,    28,   105,    -1,    32,   105,   105,     3,
      -1,    -1,    32,   105,   105,   177,   106,    -1,   106,    -1,
      -1,    31,   180,   178,    -1,   179,    -1,    -1,   179,    30,
     182,   178,    -1,    33,   105,   105,   105,    -1,    -1,    35,
     105,   105,   185,   106,    -1,   144,    -1,   145,    -1,   147,
      -1,   149,    -1,   152,    -1,   157,    -1,   159,    -1,   167,
      -1,   168,    -1,   155,    -1,   170,    -1,   174,    -1,   175,
      -1,   181,    -1,   176,    -1,   183,    -1,   184,    -1,    -1,
     186,    -1,   187,     7,   186,    -1,   187,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   197,   197,   198,   202,   203,   204,   207,   208,   215,
     219,   226,   232,   237,   242,   251,   271,   276,   281,   286,
     293,   297,   308,   312,   328,   334,   360,   372,   385,   389,
     393,   397,   415,   423,   423,   426,   430,   430,   436,   438,
     442,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   499,   503,   509,   513,   519,   523,   533,
     537,   537,   557,   561,   566,   570,   579,   584,   591,   614,
     630,   644,   648,   652,   658,   664,   671,   675,   686,   697,
     701,   702,   709,   710,   723,   728,   736,   737,   741,   745,
     757,   760,   757,   765,   775,   780,   775,   792,   793,   794,
     795,   796,   797,   798,   799,   800,   801,   802,   803,   804,
     822,   822,   826,   827,   839,   850,   850,   862,   862,   872,
     872,   884,   885,   888,   888,   899,   900,   904,   904,   917,
     917,   926,   940,   941,   945,   946,   947,   950,   953,   954,
     955,   956,   959,   960,   961,   962,   963,   964,   965,   968,
     970,   973,   974,   975,   978,   982,   983,   992,  1001,  1010,
    1011,  1012,  1013,  1020,  1020,  1034,  1042,  1043,  1044,  1045,
    1046,  1049,  1050,  1051,  1054,  1055,  1056,  1060,  1074,  1100,
    1105,  1110,  1111,  1115,  1124,  1133,  1133,  1144,  1169,  1169,
    1172,  1173,  1173,  1180,  1189,  1189,  1209,  1210,  1211,  1212,
    1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,
    1223,  1224,  1225,  1225,  1232,  1233,  1237
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
  "TOK_ENDING", "TOK_GAMETYPE", "TOK_LOGO", "TOK_MARK", "TOK_MOVE",
  "TOK_MOVETYPE", "TOK_NOTATION", "TOK_ONREPEAT", "TOK_ORIGIN",
  "TOK_PIECE", "TOK_PIECE_NAME", "TOK_REPEAT", "TOK_SEQUENCE", "TOK_START",
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
  "TOK_STANDARD_QUEEN", "TOK_STANDARD_RECT", "TOK_STANDARD_ROOK", "','",
  "'='", "'('", "')'", "'x'", "$accept", "word_or_string",
  "word_or_string_list", "number_list", "instexpr_ahogado",
  "instexpr_atacado", "cantidad_piezas_preludio",
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
  "instruction_graph", "instruction_logo", "@13", "instruction_movetype",
  "instruction_notation_element", "instruction_notation_rep",
  "instruction_notation_def", "instruction_notation", "instruction_piece",
  "instruction_start", "@14", "instruction_sequence_list",
  "instruction_sequence_prelude", "@15", "instruction_sequence", "@16",
  "instruction_sym", "instruction_zone", "@17", "instruction",
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
     345,   346,   347,   348,   349,   350,   351,   352,   353,    44,
      61,    40,    41,   120
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   104,   105,   105,   106,   106,   106,   107,   107,   108,
     108,   109,   110,   110,   110,   111,   111,   111,   111,   111,
     112,   112,   112,   112,   113,   114,   114,   115,   116,   116,
     116,   116,   117,   118,   118,   119,   120,   119,   119,   119,
     119,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   122,   122,   122,   122,   122,   122,   123,
     124,   123,   123,   123,   123,   123,   125,   125,   126,   126,
     126,   127,   127,   127,   127,   127,   128,   128,   129,   129,
     129,   129,   130,   130,   131,   131,   132,   132,   133,   133,
     135,   136,   134,   137,   139,   140,   138,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     142,   142,   143,   143,   144,   146,   145,   148,   147,   150,
     149,   151,   151,   153,   152,   154,   154,   156,   155,   158,
     157,   159,   160,   160,   161,   161,   161,   162,   163,   163,
     163,   163,   164,   164,   164,   164,   164,   164,   164,   165,
     165,   166,   166,   166,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   169,   168,   170,   171,   171,   171,   171,
     171,   172,   172,   172,   173,   173,   173,   174,   174,   174,
     174,   174,   174,   175,   176,   177,   176,   178,   180,   179,
     181,   182,   181,   183,   185,   184,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   187,   187,   188
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
       3,     1,     1,     2,     2,     1,     1,     2,     3,     3,
       3,     2,     1,     1,     3,     2,     2,     1,     2,     1,
       0,     0,     6,     1,     0,     0,     7,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     3,     3,     0,     3,     0,     3,     0,
       4,     1,     2,     0,     4,     1,     2,     0,     4,     0,
       4,     2,     3,     2,     3,     3,     2,     0,     4,     3,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     4,     3,     4,     4,     5,     3,
       3,     3,     3,     0,     3,     2,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     2,     3,     3,     4,     3,
       3,     3,     3,     2,     4,     0,     5,     1,     0,     3,
       1,     0,     4,     4,     0,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     213,     0,   115,   117,     0,   121,     0,     0,   163,   125,
       0,     0,     0,   188,     0,     0,     0,   150,     0,     0,
     196,   197,   198,   199,     0,   200,     0,   205,   201,   202,
     203,   204,   206,   207,   208,   210,   190,   209,   211,   212,
     214,   216,     0,     2,     3,     0,     0,     0,   119,   122,
     129,   131,     0,   126,   165,     0,     0,     0,     0,     0,
     183,     0,     0,     0,     0,   149,     0,   142,   143,   144,
     145,   146,   147,   148,     0,     0,     0,   123,   127,   191,
     213,     1,   114,     4,   116,   118,     0,   111,   164,   180,
     170,   169,   167,   166,   168,   174,   181,   179,   171,   182,
     177,   187,   189,   185,     0,   194,   152,   151,   153,   155,
     137,     0,   159,     0,     0,   161,   162,   160,   111,   111,
       0,   215,     0,     5,     7,   120,   109,     0,     0,    64,
      75,    72,     0,    59,    53,     0,    55,     0,    71,     0,
      89,     0,     0,     0,    76,     0,    57,     0,    60,    94,
      93,   101,   105,    97,    99,   100,   107,   106,   103,   104,
     102,    98,   108,   110,   112,   130,     0,   175,     0,   172,
     178,   184,     0,   193,     0,     0,   154,     0,     0,   157,
     156,   124,   128,   192,     6,     8,     0,     0,    62,    65,
       0,    52,    12,    13,    14,     9,    11,     0,    20,    24,
       0,     0,    28,    30,    29,    22,     0,     0,     0,    43,
      44,    19,    45,    46,    47,    48,    49,    50,    51,    42,
      74,    54,    56,    73,    88,     0,    82,    83,    85,     0,
      87,     0,    81,    90,    77,    58,     0,     0,   111,   176,
     173,   186,   195,     0,     0,     0,   136,     0,     0,   158,
      70,     0,    66,     0,    63,    33,    34,     0,    10,    18,
       0,    21,    26,    27,    31,    23,    32,    35,     0,    16,
      15,    36,     0,     0,    84,    80,    86,    78,    79,   111,
      61,     0,   113,   133,     0,     0,   139,     0,   141,   134,
     135,    69,    68,    67,    40,    17,    25,    41,     0,    38,
      39,    91,    95,   132,   138,   140,    37,     0,   111,    92,
       0,    96
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    83,   101,   125,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   273,   219,   298,   220,   151,   152,
     236,   153,   154,   155,   156,   157,   228,   158,   232,   159,
     160,   279,   307,   161,   162,   237,   308,   163,   164,   165,
      20,    21,    46,    22,    47,    23,    86,    24,    25,   118,
      26,    27,   119,    28,    87,    29,   244,   178,   175,   176,
      75,    66,   110,    30,    31,    52,    32,    95,    99,    96,
      33,    34,    35,   172,   102,    36,    61,    37,   120,    38,
      39,   174,    40,    41,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -216
static const yytype_int16 yypact[] =
{
     290,    66,  -216,  -216,    66,    66,    27,    66,  -216,    66,
      66,   322,    66,  -216,    66,    66,    66,    33,    43,    66,
    -216,  -216,  -216,  -216,    37,  -216,    48,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,    52,  -216,  -216,  -216,
    -216,    53,    98,  -216,  -216,    50,    66,    66,  -216,  -216,
    -216,  -216,    66,  -216,  -216,    66,   186,    66,   186,    66,
    -216,    66,    66,    66,    66,  -216,    72,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,   160,    66,    62,  -216,  -216,  -216,
     290,  -216,  -216,  -216,    23,    23,    89,   223,    23,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,    30,  -216,  -216,    59,
      66,    23,  -216,   102,    66,  -216,  -216,  -216,  -216,  -216,
    -216,   104,  -216,   104,   104,  -216,  -216,  -216,   223,   223,
      66,  -216,    66,  -216,  -216,   111,  -216,    66,    66,    85,
    -216,  -216,   165,  -216,  -216,   165,  -216,   165,  -216,   165,
     113,    92,    34,   165,  -216,   165,  -216,   165,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,    84,   186,  -216,   186,  -216,
    -216,  -216,    66,  -216,    66,    39,  -216,     9,   118,  -216,
    -216,    84,    84,  -216,  -216,  -216,   106,    18,  -216,    87,
       1,  -216,  -216,  -216,  -216,    66,  -216,     4,    66,  -216,
      66,    66,    66,  -216,  -216,    66,   129,   165,   165,  -216,
    -216,    46,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
     158,   158,   158,   158,  -216,   144,  -216,  -216,  -216,   138,
     130,    31,  -216,   158,   158,   158,    66,   165,   223,  -216,
    -216,    23,    23,    10,    19,    20,  -216,   140,   143,  -216,
    -216,   151,  -216,   150,  -216,  -216,  -216,   165,  -216,  -216,
     154,  -216,    66,  -216,  -216,  -216,  -216,   158,    96,  -216,
      23,  -216,   165,   164,  -216,  -216,  -216,  -216,  -216,   223,
      23,   147,  -216,  -216,   157,   104,  -216,   167,  -216,  -216,
    -216,  -216,  -216,  -216,   158,  -216,  -216,  -216,   165,   158,
    -216,    84,  -216,  -216,  -216,  -216,   158,    68,   223,  -216,
      -4,  -216
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,    -1,   -27,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,   -20,  -216,  -216,  -106,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,   -46,  -216,   -51,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,   -57,  -117,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -215,   -90,  -216,  -216,
     109,  -216,  -216,  -216,  -216,  -216,  -216,   -53,  -216,  -216,
    -216,  -216,  -216,  -216,    67,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,   108,  -216,  -216
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      45,   181,   182,    48,    49,    98,    51,   259,    53,    54,
      59,    60,   246,    62,    63,    64,   283,    74,    76,    84,
      85,   252,   177,   179,   180,    88,   243,    43,    44,   221,
     288,   222,   238,   223,    50,   277,    65,   233,   229,   234,
      90,   235,   177,   167,    77,   243,   169,    43,    44,   269,
      43,    44,    91,    82,    89,    78,    97,    92,   100,    93,
      80,   103,   104,   105,    94,   109,    43,    44,   115,    90,
      43,    44,   305,   112,   114,   117,    43,    44,   311,   255,
     256,    91,    79,   123,   123,   245,    92,   123,    93,    43,
      44,   230,   124,    94,   230,   225,    43,    44,    81,   170,
     123,   267,   268,   173,   260,   171,   231,   177,   247,   284,
      43,    44,   248,   239,   185,   240,   224,   253,   285,   287,
     238,   184,   122,   188,   249,   254,   186,   187,   189,   166,
     226,   281,   266,   276,    67,    68,    69,    70,    71,    72,
     227,    73,   275,   289,   250,   241,   290,   242,    43,    44,
     309,   294,   116,   293,   286,    43,    44,   295,   168,   106,
     107,   108,   301,   303,    43,    44,   299,   300,   190,   191,
     257,   271,   272,   243,   255,   256,   192,   193,   194,   274,
     278,   282,   226,   113,   270,   251,     0,   183,   121,   291,
       0,   310,   306,     0,   258,   304,    90,   261,   297,   262,
     263,   264,   195,     0,   265,   196,     0,     0,    91,   280,
       0,   197,     0,    92,   198,    93,     0,   199,   200,     0,
      94,   201,   271,   272,   227,   255,   256,   126,   302,   202,
     203,   204,   205,   271,   272,     0,   255,   256,   127,   206,
     123,   123,   207,     0,     0,     0,     0,     0,     0,     0,
     292,    67,    68,    69,    70,    71,    72,   111,    73,     0,
       0,   296,   128,     0,   129,   130,   208,   131,   132,   123,
       0,   133,     0,   134,   135,     0,     0,   136,   137,   123,
     138,   139,   140,   141,   142,     0,   143,     0,     0,     0,
       0,   144,   145,   146,   147,     0,   148,     0,     1,     2,
       0,     0,     0,   149,     3,     0,   150,     4,     5,     6,
       7,     8,     0,     9,    10,    11,     0,     0,    12,     0,
       0,    13,    14,    15,     0,    16,    43,    44,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,    56,     0,
       0,     0,     0,     0,    57,     0,     0,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19
};

static const yytype_int16 yycheck[] =
{
       1,   118,   119,     4,     5,    58,     7,     3,     9,    10,
      11,    12,     3,    14,    15,    16,     6,    18,    19,    46,
      47,     3,     3,   113,   114,    52,     6,     4,     5,   135,
     245,   137,    36,   139,     7,     4,     3,   143,     4,   145,
      10,   147,     3,    96,     7,     6,    99,     4,     5,     3,
       4,     5,    22,     3,    55,     7,    57,    27,    59,    29,
       7,    62,    63,    64,    34,    66,     4,     5,     6,    10,
       4,     5,   287,    74,    75,    76,     4,     5,    82,    78,
      79,    22,    30,    84,    85,   175,    27,    88,    29,     4,
       5,    60,     3,    34,    60,     3,     4,     5,     0,   100,
     101,   207,   208,   104,   100,     3,    72,     3,    99,    99,
       4,     5,   103,   166,     3,   168,     3,    99,    99,    99,
      36,   122,    99,    38,     6,    38,   127,   128,   129,    99,
      38,   237,     3,     3,    91,    92,    93,    94,    95,    96,
     141,    98,     4,     3,    38,   172,     3,   174,     4,     5,
      82,   257,    90,     3,   244,     4,     5,     3,    99,    87,
      88,    89,   279,     6,     4,     5,   272,     3,     3,     4,
     190,    75,    76,     6,    78,    79,    11,    12,    13,   225,
     231,   238,    38,    74,   211,   186,    -1,   120,    80,    38,
      -1,   308,   298,    -1,   195,   285,    10,   198,   102,   200,
     201,   202,    37,    -1,   205,    40,    -1,    -1,    22,   236,
      -1,    46,    -1,    27,    49,    29,    -1,    52,    53,    -1,
      34,    56,    75,    76,   225,    78,    79,     4,    81,    64,
      65,    66,    67,    75,    76,    -1,    78,    79,    15,    74,
     241,   242,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
      -1,   262,    39,    -1,    41,    42,   101,    44,    45,   270,
      -1,    48,    -1,    50,    51,    -1,    -1,    54,    55,   280,
      57,    58,    59,    60,    61,    -1,    63,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    -1,    73,    -1,     8,     9,
      -1,    -1,    -1,    80,    14,    -1,    83,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    -1,    28,    -1,
      -1,    31,    32,    33,    -1,    35,     4,     5,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    14,    17,    18,    19,    20,    21,    23,
      24,    25,    28,    31,    32,    33,    35,    84,    85,    86,
     144,   145,   147,   149,   151,   152,   154,   155,   157,   159,
     167,   168,   170,   174,   175,   176,   179,   181,   183,   184,
     186,   187,   188,     4,     5,   105,   146,   148,   105,   105,
       7,   105,   169,   105,   105,    10,    16,    22,    26,   105,
     105,   180,   105,   105,   105,     3,   165,    91,    92,    93,
      94,    95,    96,    98,   105,   164,   105,     7,     7,    30,
       7,     0,     3,   105,   106,   106,   150,   158,   106,   105,
      10,    22,    27,    29,    34,   171,   173,   105,   171,   172,
     105,   106,   178,   105,   105,   105,    87,    88,    89,   105,
     166,    97,   105,   164,   105,     6,    90,   105,   153,   156,
     182,   186,    99,   105,     3,   107,     4,    15,    39,    41,
      42,    44,    45,    48,    50,    51,    54,    55,    57,    58,
      59,    60,    61,    63,    68,    69,    70,    71,    73,    80,
      83,   122,   123,   125,   126,   127,   128,   129,   131,   133,
     134,   137,   138,   141,   142,   143,    99,   171,    99,   171,
     105,     3,   177,   105,   185,   162,   163,     3,   161,   161,
     161,   143,   143,   178,   105,     3,   105,   105,    38,   105,
       3,     4,    11,    12,    13,    37,    40,    46,    49,    52,
      53,    56,    64,    65,    66,    67,    74,    77,   101,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   119,
     121,   121,   121,   121,     3,     3,    38,   105,   130,     4,
      60,    72,   132,   121,   121,   121,   124,   139,    36,   171,
     171,   106,   106,     6,   160,   161,     3,    99,   103,     6,
      38,   105,     3,    99,    38,    78,    79,   118,   105,     3,
     100,   105,   105,   105,   105,   105,     3,   121,   121,     3,
     106,    75,    76,   118,   130,     4,     3,     4,   132,   135,
     106,   121,   142,     6,    99,    99,   161,    99,   160,     3,
       3,    38,   105,     3,   121,     3,   105,   102,   120,   121,
       3,   143,    81,     6,   161,   160,   121,   136,   140,    82,
     143,    82
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
#line 197 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 3:
#line 198 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 4:
#line 202 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(1) - (1)]) ); }
    break;

  case 5:
#line 203 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(2) - (2)]) ); }
    break;

  case 6:
#line 204 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(3) - (3)]) ); }
    break;

  case 7:
#line 207 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(1) - (1)]) ); }
    break;

  case 8:
#line 208 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(2) - (2)]) ); }
    break;

  case 9:
#line 215 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_ahogado( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 10:
#line 219 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_ahogado( tipojuego, (char*)(yyvsp[(2) - (2)]) ) ) YYERROR;
            free(  (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 11:
#line 226 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_atacado( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 12:
#line 232 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = CUALQUIERA;
            init_parameters(); 
    }
    break;

  case 13:
#line 237 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = PROPIO;
            init_parameters(); 
    }
    break;

  case 14:
#line 242 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = ENEMIGO;
            init_parameters(); 
    }
    break;

  case 15:
#line 251 "qgames_parser.y"
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
#line 271 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (2)]), NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 17:
#line 276 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, ENEMIGO, NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, (yyvsp[(3) - (3)]) );
    }
    break;

  case 18:
#line 281 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, ENEMIGO, NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 19:
#line 286 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (1)]), NULL, NULL ) ) YYERROR;;
    }
    break;

  case 20:
#line 293 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_destino_ant( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 21:
#line 297 "qgames_parser.y"
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
#line 308 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_origen_ant( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 23:
#line 312 "qgames_parser.y"
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
#line 328 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_entablero( tipojuego ) ) YYERROR;
    }
    break;

  case 25:
#line 334 "qgames_parser.y"
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
#line 360 "qgames_parser.y"
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
#line 372 "qgames_parser.y"
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
#line 385 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( !tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL, NULL ) ) YYERROR;
    }
    break;

  case 29:
#line 389 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( !tipojuego_code_ocupado( tipojuego, NULL, PROPIO, NULL, NULL ) ) YYERROR;
    }
    break;

  case 30:
#line 393 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( !tipojuego_code_ocupado( tipojuego, NULL, ENEMIGO, NULL, NULL ) ) YYERROR;
    }
    break;

  case 31:
#line 397 "qgames_parser.y"
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
#line 415 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_op_false( tipojuego );
        NOT_IMPLEMENTED_WARN( "repite-posicion" );
    }
    break;

  case 35:
#line 426 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_not( tipojuego );
    }
    break;

  case 36:
#line 430 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 37:
#line 433 "qgames_parser.y"
    { 
                tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 38:
#line 436 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 39:
#line 438 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(3) - (3)]) );
    }
    break;

  case 40:
#line 442 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(1) - (3)]) );
    }
    break;

  case 52:
#line 460 "qgames_parser.y"
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
                }
                free( (char*)(yyvsp[(1) - (1)]) );
            }
    }
    break;

  case 53:
#line 499 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_final( tipojuego, NULL, EMPATA ) ) YYERROR;
    }
    break;

  case 54:
#line 503 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_final( tipojuego, NULL, EMPATA ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 55:
#line 509 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_final( tipojuego, NULL, GANA ) ) YYERROR;
    }
    break;

  case 56:
#line 513 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_final( tipojuego, NULL, GANA ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 57:
#line 519 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_final( tipojuego, NULL, PIERDE ) ) YYERROR;
    }
    break;

  case 58:
#line 523 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_final( tipojuego, NULL, PIERDE ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
     }
    break;

  case 59:
#line 533 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_casillero( tipojuego, NULL );
    }
    break;

  case 60:
#line 537 "qgames_parser.y"
    {  CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 61:
#line 537 "qgames_parser.y"
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
#line 557 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, CAMBIOCOLOR, NULL, NULL, FROM_AQUI ) ) YYERROR; 
    }
    break;

  case 63:
#line 561 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, NOCOLOR, (char*)(yyvsp[(2) - (3)]), NULL, FROM_AQUI ) ) YYERROR; 
            free( (char*)(yyvsp[(2) - (3)]) );
    }
    break;

  case 64:
#line 566 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, CAMBIOCOLOR, NULL, NULL, 0 ) ) YYERROR; 
    }
    break;

  case 65:
#line 570 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, NOCOLOR, (char*)(yyvsp[(2) - (2)]), NULL, 0 ) ) YYERROR; 
            free( (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 66:
#line 579 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          if( !tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) ) ) YYERROR;
          free( (char*)(yyvsp[(2) - (3)]) );
    }
    break;

  case 67:
#line 584 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          if( !tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]) ) ) YYERROR;
          free( (char*)(yyvsp[(2) - (4)]) );
    }
    break;

  case 68:
#line 591 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            int tp  = qg_tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (4)])) );
            if( tp == NOT_FOUND ){
                qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (4)])) );
                yyerror( "Debe ser un tipo de pieza" ); YYERROR;
            }
            int col = qg_tipojuego_get_color( tipojuego, ((char*)(yyvsp[(3) - (4)])) );
            if( col == NOT_FOUND ){
                qgzprintf( "%s debe ser un color", ((char*)(yyvsp[(3) - (4)])) );
                yyerror( "Debe ser un color" ); YYERROR;
            }
            int cas = qg_tipojuego_get_casillero( tipojuego, ((char*)(yyvsp[(4) - (4)])));
            if( cas == NOT_FOUND ){
                qgzprintf( "%s debe ser un casillero", ((char*)(yyvsp[(4) - (4)])) );
                yyerror( "Debe ser un casillero" ); YYERROR;
            }
            tipojuego_code_crea( tipojuego, ((char*)(yyvsp[(2) - (4)])), NOCOLOR, ((char*)(yyvsp[(3) - (4)])), ((char*)(yyvsp[(4) - (4)])) );
            free( (char*) (yyvsp[(2) - (4)]) );
            free( (char*) (yyvsp[(3) - (4)]) );
            free( (char*) (yyvsp[(4) - (4)]) );
            
    }
    break;

  case 69:
#line 614 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            int tp  = qg_tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (4)])) );
            if( tp == NOT_FOUND ){
                qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (4)])) );
                yyerror( "Debe ser un tipo de pieza" ); YYERROR;
            }
            int col = qg_tipojuego_get_color( tipojuego, ((char*)(yyvsp[(3) - (4)])) );
            if( col == NOT_FOUND ){
                qgzprintf( "%s debe ser un color", ((char*)(yyvsp[(3) - (4)])) );
                yyerror( "Debe ser un color" ); YYERROR;
            }
            tipojuego_code_crea( tipojuego, ((char*)(yyvsp[(2) - (4)])), NOCOLOR, ((char*)(yyvsp[(3) - (4)])), NULL );
            free( (char*) (yyvsp[(2) - (4)]) );
            free( (char*) (yyvsp[(3) - (4)]) );
    }
    break;

  case 70:
#line 630 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            CHECK_TIPOJUEGO;
            int tp  = qg_tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (3)])) );
            if( tp == NOT_FOUND ){
                qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (3)])) );
                yyerror( "Debe ser un tipo de pieza" ); YYERROR;
            }
            tipojuego_code_crea( tipojuego, ((char*)(yyvsp[(2) - (3)])), PROPIO, NULL, NULL );
            free( (char*) (yyvsp[(2) - (3)]) );
    }
    break;

  case 71:
#line 644 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_juega( tipojuego, NULL, 0 ) ) YYERROR;
    }
    break;

  case 72:
#line 648 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_juega( tipojuego, NULL, 1 ) ) YYERROR;
    }
    break;

  case 73:
#line 652 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_juega( tipojuego, NULL, 0 ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 74:
#line 658 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_juega( tipojuego, NULL, 1 ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 75:
#line 664 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_captura( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 76:
#line 671 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_para( tipojuego );
    }
    break;

  case 77:
#line 675 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_para( tipojuego );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 78:
#line 686 "qgames_parser.y"
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

  case 79:
#line 697 "qgames_parser.y"
    { 
                          CHECK_TIPOJUEGO;
                          if( !tipojuego_code_mueve( tipojuego, FROM_AQUI | TO_MARCA, 0, (void*)(yyvsp[(3) - (3)]) ) ) YYERROR;
     }
    break;

  case 80:
#line 701 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve cas  => casillero" ); }
    break;

  case 81:
#line 702 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve      => marca" ); }
    break;

  case 82:
#line 709 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 83:
#line 710 "qgames_parser.y"
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

  case 84:
#line 723 "qgames_parser.y"
    { 
                        CHECK_TIPOJUEGO; 
                        if( !tipojuego_code_setmarca( tipojuego, (yyvsp[(2) - (3)]), (char*)(yyvsp[(3) - (3)]) ) ) YYERROR;
                        if( (char*)(yyvsp[(3) - (3)]) ) free( (char*)(yyvsp[(3) - (3)]) );
    }
    break;

  case 85:
#line 728 "qgames_parser.y"
    { 
                        CHECK_TIPOJUEGO; 
                        if( !tipojuego_code_setmarca( tipojuego,  0, (char*)(yyvsp[(2) - (2)]) ) ) YYERROR;
                        if( (char*)(yyvsp[(2) - (2)]) ) free( (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 86:
#line 736 "qgames_parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 87:
#line 737 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 88:
#line 741 "qgames_parser.y"
    {
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_gotomarca( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 89:
#line 745 "qgames_parser.y"
    {
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_gotomarca( tipojuego, 0 );
    }
    break;

  case 90:
#line 757 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 91:
#line 760 "qgames_parser.y"
    {
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 93:
#line 765 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !last_block ){
                yyerror( "Break por fuera de bloque" );
                YYERROR;
            }
            tipojuego_code_break_block( tipojuego, last_block );
    }
    break;

  case 94:
#line 775 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            (yyval) = tipojuego_code_start_block( tipojuego );
            // FIXME: Debe usar un stack de bloques.
            last_block = (yyval);
    }
    break;

  case 95:
#line 780 "qgames_parser.y"
    {
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 96:
#line 782 "qgames_parser.y"
    {
            tipojuego_code_continue_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_else_condblock( tipojuego );
            tipojuego_code_break_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_end_condblock( tipojuego );
            tipojuego_code_end_block( tipojuego, (yyvsp[(2) - (7)]) );
    }
    break;

  case 109:
#line 804 "qgames_parser.y"
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

  case 114:
#line 840 "qgames_parser.y"
    {  CHECK_TIPOJUEGO ;
                      CHECK_LAST_PIEZA;
                      if( !tipojuego_add_tpieza_att( tipojuego, last_pieza, ((char*)(yyvsp[(2) - (3)])), (yyvsp[(3) - (3)]) ) ) YYERROR;
                      free( (char*)(yyvsp[(2) - (3)]));
                    }
    break;

  case 115:
#line 850 "qgames_parser.y"
    { CHECK_TIPOJUEGO; 
                     init_parameters(); }
    break;

  case 116:
#line 853 "qgames_parser.y"
    {
                     char*  dims[MAX_PARAMS]; int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                        dims[i] = ((char*)qgz_param_list[i].par);
                     }
                     qg_tipojuego_genera_dimensiones( tipojuego, qgz_param_count, dims );
                   }
    break;

  case 117:
#line 862 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 118:
#line 863 "qgames_parser.y"
    { int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                       char* col = ((char*)qgz_param_list[i].par);
                       qg_tipojuego_add_color( tipojuego, col );
                     }
                   }
    break;

  case 119:
#line 872 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 120:
#line 873 "qgames_parser.y"
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

  case 121:
#line 884 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 122:
#line 885 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 123:
#line 888 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, DROP, last_pieza, (char*)((yyvsp[(1) - (2)])) );
    }
    break;

  case 124:
#line 893 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 125:
#line 899 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 126:
#line 900 "qgames_parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 127:
#line 904 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, MOVE, last_pieza, ((char*)(yyvsp[(1) - (2)])) );
        if( (yyvsp[(1) - (2)]) ) free( ((char*)(yyvsp[(1) - (2)])) );
    }
    break;

  case 128:
#line 910 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 129:
#line 917 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO; 
            change_to_code_mode(); 
            tipojuego_start_codeend( tipojuego );
    }
    break;

  case 130:
#line 921 "qgames_parser.y"
    {
            tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 131:
#line 926 "qgames_parser.y"
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

  case 132:
#line 940 "qgames_parser.y"
    { html_color1 = (yyvsp[(1) - (3)]); html_color2 = (yyvsp[(3) - (3)]); }
    break;

  case 133:
#line 941 "qgames_parser.y"
    { html_color1 = (yyvsp[(1) - (2)]); html_color2 = (yyvsp[(2) - (2)]);
                                      qgzprintf( "Frente: %x Fondo: %x", html_color1, html_color2 ); }
    break;

  case 134:
#line 945 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (3)]); graph_dim2 = (yyvsp[(3) - (3)]); }
    break;

  case 135:
#line 946 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (3)]); graph_dim2 = (yyvsp[(3) - (3)]); }
    break;

  case 136:
#line 947 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (2)]); graph_dim2 = (yyvsp[(2) - (2)]); }
    break;

  case 137:
#line 950 "qgames_parser.y"
    { graph_dim1 = 0; graph_dim2 = 0; html_color1 = 0; html_color2 = 0; }
    break;

  case 142:
#line 959 "qgames_parser.y"
    { (yyval) = STANDARD_GEM; }
    break;

  case 143:
#line 960 "qgames_parser.y"
    { (yyval) = STANDARD_BISHOP; }
    break;

  case 144:
#line 961 "qgames_parser.y"
    { (yyval) = STANDARD_KING; }
    break;

  case 145:
#line 962 "qgames_parser.y"
    { (yyval) = STANDARD_KNIGHT; }
    break;

  case 146:
#line 963 "qgames_parser.y"
    { (yyval) = STANDARD_PAWN; }
    break;

  case 147:
#line 964 "qgames_parser.y"
    { (yyval) = STANDARD_QUEEN ; }
    break;

  case 148:
#line 965 "qgames_parser.y"
    { (yyval) = STANDARD_ROOK; }
    break;

  case 149:
#line 968 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); 
                  qgzprintf( "Tablero %d", (yyvsp[(1) - (1)]) ); }
    break;

  case 150:
#line 970 "qgames_parser.y"
    { (yyval) = BOARD_ACTUAL; qgzprintf( "Tablero actual" ); }
    break;

  case 151:
#line 973 "qgames_parser.y"
    { (yyval) = TYPE_CHECKERBOARD; }
    break;

  case 152:
#line 974 "qgames_parser.y"
    { (yyval) = TYPE_GRID; }
    break;

  case 153:
#line 975 "qgames_parser.y"
    { (yyval) = TYPE_INTERSECTIONS; }
    break;

  case 154:
#line 978 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        if( !tipojuego_graph_tablero_std( tipojuego, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), graph_dim1, graph_dim2, html_color1, html_color2 ) ) YYERROR;
     }
    break;

  case 155:
#line 982 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-board file" ) }
    break;

  case 156:
#line 983 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( qg_tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(3) - (4)])) ) == NOT_FOUND ){ 
            qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(3) - (4)])) );
            yyerror( "Debe ser un tipo de pieza" ); YYERROR;
        }
        if( !tipojuego_graph_tipopieza_std( tipojuego, ((char*)(yyvsp[(3) - (4)])), (yyvsp[(2) - (4)]), graph_dim1, graph_dim2, 0 ) ) YYERROR;
        free( (char*)(yyvsp[(3) - (4)]) );
    }
    break;

  case 157:
#line 992 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( qg_tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (4)])) ) == NOT_FOUND ){ 
            qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (4)])) );
            yyerror( "Debe ser un tipo de pieza" ); YYERROR;
        }
        if( !tipojuego_graph_tipopieza_std( tipojuego, ((char*)(yyvsp[(2) - (4)])), (yyvsp[(3) - (4)]), graph_dim1, graph_dim2, 0 ) ) YYERROR;
        free( (char*)(yyvsp[(2) - (4)]) );
    }
    break;

  case 158:
#line 1001 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( qg_tipojuego_get_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (5)])) ) == NOT_FOUND ){ 
            qgzprintf( "%s debe ser un tipo de pieza", ((char*)(yyvsp[(2) - (5)])) );
            yyerror( "Debe ser un tipo de pieza" ); YYERROR;
        }
        if( !tipojuego_graph_tipopieza_std( tipojuego, ((char*)(yyvsp[(2) - (5)])), STANDARD_RECT, graph_dim1, graph_dim2, (yyvsp[(5) - (5)]) ) ) YYERROR;
        free( (char*)(yyvsp[(2) - (5)]) );
    }
    break;

  case 159:
#line 1010 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-piece string" ); }
    break;

  case 160:
#line 1011 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square file" ); }
    break;

  case 161:
#line 1012 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square color" ); }
    break;

  case 162:
#line 1013 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square highlighted" ); }
    break;

  case 163:
#line 1020 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        init_parameters();
    }
    break;

  case 164:
#line 1023 "qgames_parser.y"
    { 
        NOT_IMPLEMENTED_WARN( "logo moves" ); 
    }
    break;

  case 165:
#line 1034 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        qgzprintf( "Definiendo %s", ((char*)(yyvsp[(2) - (2)])) );
        tipojuego_add_tipo_mov( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
        free((void*)(yyvsp[(2) - (2)]));
    }
    break;

  case 166:
#line 1042 "qgames_parser.y"
    { (yyval) =  NOTACION_PIEZA; }
    break;

  case 167:
#line 1043 "qgames_parser.y"
    { (yyval) =  NOTACION_ORIGEN; }
    break;

  case 168:
#line 1044 "qgames_parser.y"
    { (yyval) =  NOTACION_DESTINO; }
    break;

  case 169:
#line 1045 "qgames_parser.y"
    { (yyval) =  NOTACION_MARCA ; }
    break;

  case 170:
#line 1046 "qgames_parser.y"
    { (yyval) =  NOTACION_CAPTURA; }
    break;

  case 171:
#line 1049 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_rep( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 172:
#line 1050 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_rep( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 173:
#line 1051 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_rep( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 174:
#line 1054 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_def( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 175:
#line 1055 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_def( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 176:
#line 1056 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_def( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 177:
#line 1060 "qgames_parser.y"
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

  case 178:
#line 1074 "qgames_parser.y"
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

  case 179:
#line 1100 "qgames_parser.y"
    { 
                  CHECK_TIPOJUEGO;
                  tipojuego_set_notacion_marca( tipojuego, (char*)(yyvsp[(3) - (3)]), NULL );
                  free((void*)(yyvsp[(3) - (3)]));
             }
    break;

  case 180:
#line 1105 "qgames_parser.y"
    { 
                  CHECK_TIPOJUEGO;
                  tipojuego_set_notacion_marca( tipojuego, NULL, (char*)(yyvsp[(3) - (3)]) );
                  free((void*)(yyvsp[(3) - (3)]));
             }
    break;

  case 183:
#line 1115 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO; 
        tipojuego_add_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ); 
        if( last_pieza ) free( last_pieza );
        last_pieza = strdup( ((char*)(yyvsp[(2) - (2)])) );
        free( (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 184:
#line 1124 "qgames_parser.y"
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

  case 185:
#line 1133 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 186:
#line 1133 "qgames_parser.y"
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

  case 187:
#line 1144 "qgames_parser.y"
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
                    qgzprintf( "color secuencia %s - tipo mov %s",  val1, val2 );
                    if( !tipojuego_add_secuencia( tipojuego, val1, val2 ) ) YYERROR;
                    i ++;
                } else {
                    qgzprintf( "color secuencia %s",  val1 );
                    if( !tipojuego_add_secuencia( tipojuego, val1, NULL ) ) YYERROR;
                }
            } else {
                qgzprintf( "color secuencia %s",  val1 );
                if( !tipojuego_add_secuencia( tipojuego, val1, NULL ) ) YYERROR;
            }
        } 
    }
    break;

  case 188:
#line 1169 "qgames_parser.y"
    { init_parameters(); qgzprintf( "inicio secuencia %d", TOK_SEQUENCE ); }
    break;

  case 191:
#line 1173 "qgames_parser.y"
    {
        if( !tipojuego_add_secuencia_rep( tipojuego ) ) YYERROR;
    }
    break;

  case 193:
#line 1180 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        if( !tipojuego_add_simetria( tipojuego, ((char*)(yyvsp[(2) - (4)])), (char*)(yyvsp[(3) - (4)]), (char*)(yyvsp[(4) - (4)]) ) ) YYERROR;
        free( ((char*)(yyvsp[(2) - (4)])) );
        free( ((char*)(yyvsp[(3) - (4)])) );
        free( ((char*)(yyvsp[(4) - (4)])) );
    }
    break;

  case 194:
#line 1189 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 195:
#line 1189 "qgames_parser.y"
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
            free( ((char*)(yyvsp[(2) - (5)])) );
            free( ((char*)(yyvsp[(3) - (5)])) );
    }
    break;


/* Line 1267 of yacc.c.  */
#line 3396 "qgames_parser.c"
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


#line 1241 "qgames_parser.y"


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


