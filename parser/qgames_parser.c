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
     TOK_CAMBIA_COLOR = 294,
     TOK_CAPTURA = 295,
     TOK_CAPTURA_SI = 296,
     TOK_CAPTURA_Y_JUEGA = 297,
     TOK_CAPTURA_Y_JUEGA_SI = 298,
     TOK_CAPTURADAS_ENEMIGO = 299,
     TOK_CAPTURADAS_PROPIO = 300,
     TOK_CASILLERO_INICIAL = 301,
     TOK_DESTINO_ANT = 302,
     TOK_EMPATA = 303,
     TOK_EMPATA_SI = 304,
     TOK_ENTABLERO = 305,
     TOK_ENZONA = 306,
     TOK_GANA = 307,
     TOK_GANA_SI = 308,
     TOK_JAQUEMATE = 309,
     TOK_JUEGA = 310,
     TOK_JUEGA_SI = 311,
     TOK_GOTO_MARCA = 312,
     TOK_MARCA = 313,
     TOK_MUEVE = 314,
     TOK_MUEVE_SI = 315,
     TOK_IF = 316,
     TOK_OCUPADO = 317,
     TOK_OCUPADOENEMIGO = 318,
     TOK_OCUPADOPROPIO = 319,
     TOK_ORIGEN_ANT = 320,
     TOK_PARA = 321,
     TOK_PARA_SI = 322,
     TOK_PIERDE = 323,
     TOK_PIERDE_SI = 324,
     TOK_PIEZAS_EN_CAS = 325,
     TOK_TRANSFORMA = 326,
     TOK_REPITEPOS = 327,
     TOK_AND = 328,
     TOK_OR = 329,
     TOK_NOT = 330,
     TOK_EQUAL = 331,
     TOK_DEQUAL = 332,
     TOK_WHILE = 333,
     TOK_DO = 334,
     TOK_END = 335,
     TOK_BREAK = 336,
     TOK_GRAPH_BOARD = 337,
     TOK_GRAPH_PIECE = 338,
     TOK_GRAPH_SQUARE = 339,
     TOK_GRID = 340,
     TOK_CHECKERBOARD = 341,
     TOK_INTERSECTIONS = 342,
     TOK_HIGHLIGHTED = 343,
     TOK_STANDARD_GEM = 344,
     TOK_STANDARD_BISHOP = 345,
     TOK_STANDARD_KING = 346,
     TOK_STANDARD_KNIGHT = 347,
     TOK_STANDARD_PAWN = 348,
     TOK_STANDARD_QUEEN = 349,
     TOK_STANDARD_ROOK = 350
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
#define TOK_CAMBIA_COLOR 294
#define TOK_CAPTURA 295
#define TOK_CAPTURA_SI 296
#define TOK_CAPTURA_Y_JUEGA 297
#define TOK_CAPTURA_Y_JUEGA_SI 298
#define TOK_CAPTURADAS_ENEMIGO 299
#define TOK_CAPTURADAS_PROPIO 300
#define TOK_CASILLERO_INICIAL 301
#define TOK_DESTINO_ANT 302
#define TOK_EMPATA 303
#define TOK_EMPATA_SI 304
#define TOK_ENTABLERO 305
#define TOK_ENZONA 306
#define TOK_GANA 307
#define TOK_GANA_SI 308
#define TOK_JAQUEMATE 309
#define TOK_JUEGA 310
#define TOK_JUEGA_SI 311
#define TOK_GOTO_MARCA 312
#define TOK_MARCA 313
#define TOK_MUEVE 314
#define TOK_MUEVE_SI 315
#define TOK_IF 316
#define TOK_OCUPADO 317
#define TOK_OCUPADOENEMIGO 318
#define TOK_OCUPADOPROPIO 319
#define TOK_ORIGEN_ANT 320
#define TOK_PARA 321
#define TOK_PARA_SI 322
#define TOK_PIERDE 323
#define TOK_PIERDE_SI 324
#define TOK_PIEZAS_EN_CAS 325
#define TOK_TRANSFORMA 326
#define TOK_REPITEPOS 327
#define TOK_AND 328
#define TOK_OR 329
#define TOK_NOT 330
#define TOK_EQUAL 331
#define TOK_DEQUAL 332
#define TOK_WHILE 333
#define TOK_DO 334
#define TOK_END 335
#define TOK_BREAK 336
#define TOK_GRAPH_BOARD 337
#define TOK_GRAPH_PIECE 338
#define TOK_GRAPH_SQUARE 339
#define TOK_GRID 340
#define TOK_CHECKERBOARD 341
#define TOK_INTERSECTIONS 342
#define TOK_HIGHLIGHTED 343
#define TOK_STANDARD_GEM 344
#define TOK_STANDARD_BISHOP 345
#define TOK_STANDARD_KING 346
#define TOK_STANDARD_KNIGHT 347
#define TOK_STANDARD_PAWN 348
#define TOK_STANDARD_QUEEN 349
#define TOK_STANDARD_ROOK 350




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
#include  <qgames_code.h>



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
#line 412 "qgames_parser.c"

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
#define YYLAST   363

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  208
/* YYNRULES -- Number of states.  */
#define YYNSTATES  298

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   350

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      98,    99,     2,     2,    96,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    97,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     100,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      95
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
     151,   152,   156,   159,   163,   165,   168,   172,   177,   179,
     181,   184,   187,   189,   191,   194,   198,   202,   206,   209,
     211,   213,   217,   220,   223,   225,   228,   230,   231,   232,
     239,   241,   242,   243,   251,   253,   255,   257,   259,   261,
     263,   265,   267,   269,   271,   273,   275,   277,   278,   280,
     284,   288,   289,   293,   294,   298,   299,   304,   306,   309,
     310,   315,   317,   320,   321,   326,   327,   332,   335,   339,
     342,   346,   350,   353,   354,   359,   363,   368,   372,   374,
     376,   378,   380,   382,   384,   386,   388,   389,   391,   393,
     395,   400,   404,   409,   414,   418,   422,   426,   430,   433,
     435,   437,   439,   441,   443,   445,   448,   452,   454,   457,
     461,   465,   470,   474,   478,   482,   486,   489,   494,   495,
     501,   503,   504,   508,   510,   511,   516,   521,   522,   528,
     530,   532,   534,   536,   538,   540,   542,   544,   546,   548,
     550,   552,   554,   556,   558,   560,   561,   563,   567
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     182,     0,    -1,     4,    -1,     5,    -1,   102,    -1,   103,
     102,    -1,   103,    96,   102,    -1,     3,    -1,   104,     3,
      -1,    35,    -1,    35,   102,    -1,    38,    -1,    11,    -1,
      12,    -1,    13,    -1,   107,   103,    -1,   107,     3,    -1,
      44,    97,     3,    -1,    44,     3,    -1,   107,    -1,    47,
      -1,    47,   102,    -1,    65,    -1,    65,   102,    -1,    50,
      -1,    51,   102,   102,    -1,    51,   102,    -1,    54,   102,
      -1,    62,    -1,    64,    -1,    63,    -1,    62,   102,    -1,
      72,     3,    -1,    76,    -1,    77,    -1,    75,   118,    -1,
      -1,   118,    73,   117,   118,    -1,   118,    74,   118,    -1,
     118,   115,     3,    -1,     3,   115,   118,    -1,    98,   118,
      99,    -1,   116,    -1,   105,    -1,   106,    -1,   108,    -1,
     109,    -1,   110,    -1,   111,    -1,   112,    -1,   113,    -1,
     114,    -1,     4,    -1,    48,    -1,    49,   118,    -1,    52,
      -1,    53,   118,    -1,    68,    -1,    69,   118,    -1,    46,
      -1,    -1,    71,   121,   103,    -1,    39,    36,    -1,    39,
     102,    36,    -1,    39,    -1,    39,   102,    -1,    37,   102,
       3,    -1,    37,   102,    96,     3,    -1,    55,    -1,    42,
      -1,    56,   118,    -1,    43,   118,    -1,    40,    -1,    66,
      -1,    67,   118,    -1,    59,    70,     4,    -1,    59,    70,
     128,    -1,    59,     4,     4,    -1,    59,   128,    -1,    36,
      -1,   102,    -1,    58,     3,   126,    -1,    58,   126,    -1,
      58,     3,    -1,    58,    -1,    57,     3,    -1,    57,    -1,
      -1,    -1,    61,   118,   131,   139,   132,    80,    -1,    81,
      -1,    -1,    -1,    78,   135,   118,    79,   136,   139,    80,
      -1,   122,    -1,   133,    -1,   123,    -1,   119,    -1,   130,
      -1,   127,    -1,   129,    -1,   120,    -1,   125,    -1,   124,
      -1,   134,    -1,     4,    -1,   137,    -1,    -1,   138,    -1,
     139,    34,   138,    -1,     8,   102,     3,    -1,    -1,     9,
     142,   103,    -1,    -1,    14,   144,   103,    -1,    -1,    16,
     102,   146,   104,    -1,    17,    -1,    17,   102,    -1,    -1,
     147,     7,   149,   139,    -1,    21,    -1,    21,   102,    -1,
      -1,   150,     7,   152,   139,    -1,    -1,    18,     7,   154,
     139,    -1,    19,   102,    -1,     6,    96,     6,    -1,     6,
       6,    -1,     3,    96,     3,    -1,     3,   100,     3,    -1,
       3,     3,    -1,    -1,   158,   156,    96,   157,    -1,   158,
     156,   157,    -1,   158,   157,    96,   156,    -1,   158,   157,
     156,    -1,    89,    -1,    90,    -1,    91,    -1,    92,    -1,
      93,    -1,    94,    -1,    95,    -1,     3,    -1,    -1,    86,
      -1,    85,    -1,    87,    -1,    82,   161,   162,   159,    -1,
      82,   161,   102,    -1,    83,   160,   102,   157,    -1,    83,
     102,   160,   157,    -1,    83,   102,   102,    -1,    84,   102,
     102,    -1,    84,   102,     6,    -1,    84,   102,    88,    -1,
      22,   102,    -1,    27,    -1,    25,    -1,    32,    -1,    20,
      -1,    10,    -1,   165,    -1,   166,   165,    -1,   166,    96,
     165,    -1,   165,    -1,   167,   165,    -1,   167,    96,   165,
      -1,    23,   102,   102,    -1,    23,   102,   102,   102,    -1,
      23,    20,   102,    -1,    23,    10,   102,    -1,    23,    15,
     167,    -1,    23,    24,   166,    -1,    26,   102,    -1,    30,
     102,   102,     3,    -1,    -1,    30,   102,   102,   171,   103,
      -1,   103,    -1,    -1,    29,   174,   172,    -1,   173,    -1,
      -1,   173,    28,   176,   172,    -1,    31,   102,   102,   102,
      -1,    -1,    33,   102,   102,   179,   103,    -1,   140,    -1,
     141,    -1,   143,    -1,   145,    -1,   148,    -1,   153,    -1,
     155,    -1,   163,    -1,   151,    -1,   164,    -1,   168,    -1,
     169,    -1,   175,    -1,   170,    -1,   177,    -1,   178,    -1,
      -1,   180,    -1,   181,     7,   180,    -1,   181,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   194,   194,   195,   199,   200,   201,   204,   205,   212,
     216,   223,   229,   234,   239,   248,   268,   273,   278,   283,
     290,   294,   305,   309,   325,   331,   357,   369,   382,   386,
     390,   394,   412,   420,   420,   423,   427,   427,   433,   435,
     439,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   496,   500,   506,   510,   516,   520,   530,
     534,   534,   554,   558,   563,   567,   576,   581,   590,   594,
     598,   604,   610,   617,   621,   632,   643,   647,   648,   655,
     656,   669,   674,   682,   683,   687,   691,   703,   706,   703,
     711,   721,   726,   721,   738,   739,   740,   741,   742,   743,
     744,   745,   746,   747,   748,   749,   767,   767,   771,   772,
     784,   795,   795,   807,   807,   817,   817,   829,   830,   833,
     833,   844,   845,   849,   849,   862,   862,   871,   885,   886,
     890,   891,   892,   895,   898,   899,   900,   901,   904,   905,
     906,   907,   908,   909,   910,   913,   915,   918,   919,   920,
     923,   927,   928,   937,   946,   947,   948,   949,   958,   966,
     967,   968,   969,   970,   973,   974,   975,   978,   979,   980,
     984,   998,  1024,  1029,  1034,  1035,  1039,  1048,  1057,  1057,
    1068,  1088,  1088,  1091,  1092,  1092,  1099,  1105,  1105,  1123,
    1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,
    1134,  1135,  1136,  1137,  1138,  1138,  1145,  1146,  1150
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
  "TOK_ATACADO_ENEMIGO", "TOK_CAMBIA_COLOR", "TOK_CAPTURA",
  "TOK_CAPTURA_SI", "TOK_CAPTURA_Y_JUEGA", "TOK_CAPTURA_Y_JUEGA_SI",
  "TOK_CAPTURADAS_ENEMIGO", "TOK_CAPTURADAS_PROPIO",
  "TOK_CASILLERO_INICIAL", "TOK_DESTINO_ANT", "TOK_EMPATA",
  "TOK_EMPATA_SI", "TOK_ENTABLERO", "TOK_ENZONA", "TOK_GANA",
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
  "instaction_movs", "@2", "instaction_asigna_att", "instaction_juega",
  "instaction_para", "instaction_mueve", "instaction_marca_casillero",
  "instaction_set_marca", "instaction_get_marca", "instaction_goto_marca",
  "instaction_if", "@3", "@4", "instaction_break", "instaction_while",
  "@5", "@6", "instaction", "instcode", "code_list", "instruction_attr",
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
     345,   346,   347,   348,   349,   350,    44,    61,    40,    41,
     120
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   102,   103,   103,   103,   104,   104,   105,
     105,   106,   107,   107,   107,   108,   108,   108,   108,   108,
     109,   109,   109,   109,   110,   111,   111,   112,   113,   113,
     113,   113,   114,   115,   115,   116,   117,   116,   116,   116,
     116,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   119,   119,   119,   119,   120,
     121,   120,   120,   120,   120,   120,   122,   122,   123,   123,
     123,   123,   123,   124,   124,   125,   125,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   131,   132,   130,
     133,   135,   136,   134,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   138,   138,   139,   139,
     140,   142,   141,   144,   143,   146,   145,   147,   147,   149,
     148,   150,   150,   152,   151,   154,   153,   155,   156,   156,
     157,   157,   157,   158,   159,   159,   159,   159,   160,   160,
     160,   160,   160,   160,   160,   161,   161,   162,   162,   162,
     163,   163,   163,   163,   163,   163,   163,   163,   164,   165,
     165,   165,   165,   165,   166,   166,   166,   167,   167,   167,
     168,   168,   168,   168,   168,   168,   169,   170,   171,   170,
     172,   174,   173,   175,   176,   175,   177,   179,   178,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   181,   181,   182
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
       0,     3,     2,     3,     1,     2,     3,     4,     1,     1,
       2,     2,     1,     1,     2,     3,     3,     3,     2,     1,
       1,     3,     2,     2,     1,     2,     1,     0,     0,     6,
       1,     0,     0,     7,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     3,
       3,     0,     3,     0,     3,     0,     4,     1,     2,     0,
       4,     1,     2,     0,     4,     0,     4,     2,     3,     2,
       3,     3,     2,     0,     4,     3,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       4,     3,     4,     4,     3,     3,     3,     3,     2,     1,
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
     205,     0,   111,   113,     0,   117,     0,     0,   121,     0,
       0,     0,   181,     0,     0,     0,   146,     0,     0,   189,
     190,   191,   192,     0,   193,     0,   197,   194,   195,   196,
     198,   199,   200,   202,   183,   201,   203,   204,   206,   208,
       0,     2,     3,     0,     0,     0,   115,   118,   125,   127,
     122,   158,     0,     0,     0,     0,     0,   176,     0,     0,
       0,     0,   145,     0,   138,   139,   140,   141,   142,   143,
     144,     0,     0,     0,   119,   123,   184,   205,     1,   110,
       4,   112,   114,     0,   107,   173,   163,   162,   160,   159,
     161,   167,   174,   172,   164,   175,   170,   180,   182,   178,
       0,   187,   148,   147,   149,   151,   133,   154,     0,     0,
     156,   157,   155,   107,   107,     0,   207,     0,     5,     7,
     116,   105,     0,    64,    72,    69,     0,    59,    53,     0,
      55,     0,    68,     0,    86,     0,     0,     0,    73,     0,
      57,     0,    60,    91,    90,    97,   101,    94,    96,   103,
     102,    99,   100,    98,    95,   104,   106,   108,   126,     0,
     168,     0,   165,   171,   177,     0,   186,     0,     0,   150,
       0,   153,   152,   120,   124,   185,     6,     8,     0,    62,
      65,     0,    52,    12,    13,    14,     9,    11,     0,    20,
      24,     0,     0,    28,    30,    29,    22,     0,     0,     0,
      43,    44,    19,    45,    46,    47,    48,    49,    50,    51,
      42,    71,    54,    56,    70,    85,     0,    79,    80,    82,
       0,    84,     0,    78,    87,    74,    58,     0,     0,   107,
     169,   166,   179,   188,     0,     0,     0,   132,     0,     0,
      66,     0,    63,    33,    34,     0,    10,    18,     0,    21,
      26,    27,    31,    23,    32,    35,     0,    16,    15,    36,
       0,     0,    81,    77,    83,    75,    76,   107,    61,     0,
     109,   129,     0,     0,   135,     0,   137,   130,   131,    67,
      40,    17,    25,    41,     0,    38,    39,    88,    92,   128,
     134,   136,    37,     0,   107,    89,     0,    93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    80,    97,   120,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   261,   210,   284,   211,   145,   146,
     227,   147,   148,   149,   150,   219,   151,   223,   152,   153,
     267,   293,   154,   155,   228,   294,   156,   157,   158,    19,
      20,    44,    21,    45,    22,    83,    23,    24,   113,    25,
      26,   114,    27,    84,    28,   235,   171,   168,   169,    72,
      63,   106,    29,    30,    91,    95,    92,    31,    32,    33,
     165,    98,    34,    58,    35,   115,    36,    37,   167,    38,
      39,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -202
static const yytype_int16 yypact[] =
{
     279,    63,  -202,  -202,    63,    63,    47,    63,    63,    63,
     174,    63,  -202,    63,    63,    63,    58,   119,    63,  -202,
    -202,  -202,  -202,    68,  -202,    75,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,    18,  -202,  -202,  -202,  -202,    77,
      50,  -202,  -202,    62,    63,    63,  -202,  -202,  -202,  -202,
    -202,  -202,    63,   209,    63,   209,    63,  -202,    63,    63,
      63,    63,  -202,    73,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,   119,    63,    39,  -202,  -202,  -202,   279,  -202,  -202,
    -202,    29,    29,    84,   213,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,    66,  -202,  -202,   196,    63,    29,  -202,    89,
      63,  -202,  -202,  -202,  -202,  -202,  -202,  -202,    91,    91,
    -202,  -202,  -202,   213,   213,    63,  -202,    63,  -202,  -202,
      97,  -202,    63,    43,  -202,  -202,   102,  -202,  -202,   102,
    -202,   102,  -202,   102,    98,    37,    27,   102,  -202,   102,
    -202,   102,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,    76,   209,
    -202,   209,  -202,  -202,  -202,    63,  -202,    63,    46,  -202,
       8,  -202,  -202,    76,    76,  -202,  -202,  -202,    22,  -202,
      81,    26,  -202,  -202,  -202,  -202,    63,  -202,    12,    63,
    -202,    63,    63,    63,  -202,  -202,    63,   104,   102,   102,
    -202,  -202,    34,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,   230,   230,   230,   230,  -202,    52,  -202,  -202,  -202,
     108,   125,    25,  -202,   230,   230,   230,    63,   102,   213,
    -202,  -202,    29,    29,    15,    24,    30,  -202,   126,   130,
    -202,   132,  -202,  -202,  -202,   102,  -202,  -202,   135,  -202,
      63,  -202,  -202,  -202,  -202,   230,    71,  -202,    29,  -202,
     102,   139,  -202,  -202,  -202,  -202,  -202,   213,    29,   166,
    -202,  -202,   137,    91,  -202,   144,  -202,  -202,  -202,  -202,
     230,  -202,  -202,  -202,   102,   230,  -202,    76,  -202,  -202,
    -202,  -202,   230,    74,   213,  -202,   -11,  -202
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,    -1,   -26,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,   -24,  -202,  -202,  -109,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,   -55,  -202,   -59,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,   -61,  -112,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -201,  -104,  -202,  -202,   100,
    -202,  -202,  -202,  -202,   -29,  -202,  -202,  -202,  -202,  -202,
    -202,    57,  -202,  -202,  -202,  -202,  -202,  -202,  -202,    96,
    -202,  -202
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      43,   173,   174,    46,    47,   172,    49,    50,    51,    56,
      57,   237,    59,    60,    61,   247,    71,    73,    81,    82,
     212,   271,   213,   229,   214,   240,    94,   170,   224,   265,
     225,   220,   226,    41,    42,   276,   234,   257,    41,    42,
     216,    41,    42,    41,    42,   110,    76,    41,    42,   170,
      78,    85,   234,    93,    48,    96,    41,    42,    99,   100,
     101,    62,   105,   160,   236,    79,   162,    41,    42,   297,
     107,   109,   112,   217,   291,    74,    86,    41,    42,   179,
     118,   118,    75,   221,    77,   221,    87,   119,   217,   255,
     256,    88,   164,    89,   170,   163,   118,   222,    90,   166,
     177,   215,   243,   244,   238,   181,   182,   254,   239,   248,
     229,   272,   263,   183,   184,   185,   176,   242,   241,   269,
     273,   178,   180,    41,    42,   117,   275,   111,   264,   277,
     230,   274,   231,   278,   218,   279,   280,   186,   281,   232,
     187,   233,   286,   289,   259,   260,   188,   243,   244,   189,
     234,   285,   190,   191,   295,   287,   192,   245,   102,   103,
     104,   262,   159,   266,   193,   194,   195,   196,   270,   290,
     283,   108,   175,   116,   197,   292,   258,   198,    41,    42,
       0,     0,   296,     0,    52,   246,     0,     0,   249,    53,
     250,   251,   252,     0,    54,   253,     0,     0,    55,     0,
     199,   268,     0,     0,     0,     0,    86,     0,    64,    65,
      66,    67,    68,    69,    70,   218,    87,   121,     0,    86,
       0,    88,     0,    89,     0,     0,     0,     0,    90,    87,
       0,   118,   118,     0,    88,     0,    89,     0,     0,   259,
     260,    90,   243,   244,     0,   288,     0,     0,     0,   282,
     122,     0,   123,   124,     0,   125,   126,   118,     0,   127,
       0,   128,   129,     0,     0,   130,   131,   118,   132,   133,
     134,   135,   136,     0,   137,     0,     0,     0,     0,   138,
     139,   140,   141,     0,   142,     0,     0,     1,     2,     0,
       0,   143,   161,     3,   144,     4,     5,     6,     7,     0,
       8,     9,    10,   259,   260,    11,   243,   244,    12,    13,
      14,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    18
};

static const yytype_int16 yycheck[] =
{
       1,   113,   114,     4,     5,   109,     7,     8,     9,    10,
      11,     3,    13,    14,    15,     3,    17,    18,    44,    45,
     129,     6,   131,    34,   133,     3,    55,     3,   137,     4,
     139,     4,   141,     4,     5,   236,     6,     3,     4,     5,
       3,     4,     5,     4,     5,     6,    28,     4,     5,     3,
       0,    52,     6,    54,     7,    56,     4,     5,    59,    60,
      61,     3,    63,    92,   168,     3,    95,     4,     5,    80,
      71,    72,    73,    36,   275,     7,    10,     4,     5,    36,
      81,    82,     7,    58,     7,    58,    20,     3,    36,   198,
     199,    25,     3,    27,     3,    96,    97,    70,    32,   100,
       3,     3,    76,    77,    96,     3,     4,     3,   100,    97,
      34,    96,     4,    11,    12,    13,   117,    36,    96,   228,
      96,   122,   123,     4,     5,    96,    96,    88,     3,     3,
     159,   235,   161,     3,   135,     3,   245,    35,     3,   165,
      38,   167,     3,     6,    73,    74,    44,    76,    77,    47,
       6,   260,    50,    51,    80,   267,    54,   181,    85,    86,
      87,   216,    96,   222,    62,    63,    64,    65,   229,   273,
      99,    71,   115,    77,    72,   284,   202,    75,     4,     5,
      -1,    -1,   294,    -1,    10,   186,    -1,    -1,   189,    15,
     191,   192,   193,    -1,    20,   196,    -1,    -1,    24,    -1,
      98,   227,    -1,    -1,    -1,    -1,    10,    -1,    89,    90,
      91,    92,    93,    94,    95,   216,    20,     4,    -1,    10,
      -1,    25,    -1,    27,    -1,    -1,    -1,    -1,    32,    20,
      -1,   232,   233,    -1,    25,    -1,    27,    -1,    -1,    73,
      74,    32,    76,    77,    -1,    79,    -1,    -1,    -1,   250,
      37,    -1,    39,    40,    -1,    42,    43,   258,    -1,    46,
      -1,    48,    49,    -1,    -1,    52,    53,   268,    55,    56,
      57,    58,    59,    -1,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    -1,    71,    -1,    -1,     8,     9,    -1,
      -1,    78,    96,    14,    81,    16,    17,    18,    19,    -1,
      21,    22,    23,    73,    74,    26,    76,    77,    29,    30,
      31,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    14,    16,    17,    18,    19,    21,    22,
      23,    26,    29,    30,    31,    33,    82,    83,    84,   140,
     141,   143,   145,   147,   148,   150,   151,   153,   155,   163,
     164,   168,   169,   170,   173,   175,   177,   178,   180,   181,
     182,     4,     5,   102,   142,   144,   102,   102,     7,   102,
     102,   102,    10,    15,    20,    24,   102,   102,   174,   102,
     102,   102,     3,   161,    89,    90,    91,    92,    93,    94,
      95,   102,   160,   102,     7,     7,    28,     7,     0,     3,
     102,   103,   103,   146,   154,   102,    10,    20,    25,    27,
      32,   165,   167,   102,   165,   166,   102,   103,   172,   102,
     102,   102,    85,    86,    87,   102,   162,   102,   160,   102,
       6,    88,   102,   149,   152,   176,   180,    96,   102,     3,
     104,     4,    37,    39,    40,    42,    43,    46,    48,    49,
      52,    53,    55,    56,    57,    58,    59,    61,    66,    67,
      68,    69,    71,    78,    81,   119,   120,   122,   123,   124,
     125,   127,   129,   130,   133,   134,   137,   138,   139,    96,
     165,    96,   165,   102,     3,   171,   102,   179,   158,   159,
       3,   157,   157,   139,   139,   172,   102,     3,   102,    36,
     102,     3,     4,    11,    12,    13,    35,    38,    44,    47,
      50,    51,    54,    62,    63,    64,    65,    72,    75,    98,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     116,   118,   118,   118,   118,     3,     3,    36,   102,   126,
       4,    58,    70,   128,   118,   118,   118,   121,   135,    34,
     165,   165,   103,   103,     6,   156,   157,     3,    96,   100,
       3,    96,    36,    76,    77,   115,   102,     3,    97,   102,
     102,   102,   102,   102,     3,   118,   118,     3,   103,    73,
      74,   115,   126,     4,     3,     4,   128,   131,   103,   118,
     138,     6,    96,    96,   157,    96,   156,     3,     3,     3,
     118,     3,   102,    99,   117,   118,     3,   139,    79,     6,
     157,   156,   118,   132,   136,    80,   139,    80
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
#line 194 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 3:
#line 195 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 4:
#line 199 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(1) - (1)]) ); }
    break;

  case 5:
#line 200 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(2) - (2)]) ); }
    break;

  case 6:
#line 201 "qgames_parser.y"
    { add_parameter( TOK_STRING, (yyvsp[(3) - (3)]) ); }
    break;

  case 7:
#line 204 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(1) - (1)]) ); }
    break;

  case 8:
#line 205 "qgames_parser.y"
    { add_parameter( TOK_NUMBER, (yyvsp[(2) - (2)]) ); }
    break;

  case 9:
#line 212 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_ahogado( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 10:
#line 216 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_ahogado( tipojuego, (char*)(yyvsp[(2) - (2)]) ) ) YYERROR;
            free(  (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 11:
#line 223 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_atacado( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 12:
#line 229 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = CUALQUIERA;
            init_parameters(); 
    }
    break;

  case 13:
#line 234 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = PROPIO;
            init_parameters(); 
    }
    break;

  case 14:
#line 239 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            (yyval) = ENEMIGO;
            init_parameters(); 
    }
    break;

  case 15:
#line 248 "qgames_parser.y"
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
#line 268 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (2)]), NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 17:
#line 273 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, ENEMIGO, NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, (yyvsp[(3) - (3)]) );
    }
    break;

  case 18:
#line 278 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, CASILLERO_CAPTURA, ENEMIGO, NULL, NULL ) ) YYERROR;;
            tipojuego_code_op_equal( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 19:
#line 283 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_cuenta_piezas( tipojuego, NULL, (yyvsp[(1) - (1)]), NULL, NULL ) ) YYERROR;;
    }
    break;

  case 20:
#line 290 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_destino_ant( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 21:
#line 294 "qgames_parser.y"
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
#line 305 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_origen_ant( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 23:
#line 309 "qgames_parser.y"
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
#line 325 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_entablero( tipojuego ) ) YYERROR;
    }
    break;

  case 25:
#line 331 "qgames_parser.y"
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
#line 357 "qgames_parser.y"
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
#line 369 "qgames_parser.y"
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
#line 382 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( !tipojuego_code_ocupado( tipojuego, NULL, CUALQUIERA, NULL, NULL ) ) YYERROR;
    }
    break;

  case 29:
#line 386 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( !tipojuego_code_ocupado( tipojuego, NULL, PROPIO, NULL, NULL ) ) YYERROR;
    }
    break;

  case 30:
#line 390 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        if( !tipojuego_code_ocupado( tipojuego, NULL, ENEMIGO, NULL, NULL ) ) YYERROR;
    }
    break;

  case 31:
#line 394 "qgames_parser.y"
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
#line 412 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        tipojuego_code_op_false( tipojuego );
        NOT_IMPLEMENTED_WARN( "repite-posicion" );
    }
    break;

  case 35:
#line 423 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_not( tipojuego );
    }
    break;

  case 36:
#line 427 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 37:
#line 430 "qgames_parser.y"
    { 
                tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 38:
#line 433 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 39:
#line 435 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(3) - (3)]) );
    }
    break;

  case 40:
#line 439 "qgames_parser.y"
    {
                CHECK_TIPOJUEGO;
                tipojuego_code_op_equal( tipojuego, (yyvsp[(1) - (3)]) );
    }
    break;

  case 52:
#line 457 "qgames_parser.y"
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
#line 496 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_final( tipojuego, NULL, EMPATA ) ) YYERROR;
    }
    break;

  case 54:
#line 500 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_final( tipojuego, NULL, EMPATA ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 55:
#line 506 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_final( tipojuego, NULL, GANA ) ) YYERROR;
    }
    break;

  case 56:
#line 510 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_final( tipojuego, NULL, GANA ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 57:
#line 516 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_final( tipojuego, NULL, PIERDE ) ) YYERROR;
    }
    break;

  case 58:
#line 520 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_final( tipojuego, NULL, PIERDE ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
     }
    break;

  case 59:
#line 530 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_casillero( tipojuego, NULL );
    }
    break;

  case 60:
#line 534 "qgames_parser.y"
    {  CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 61:
#line 534 "qgames_parser.y"
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
#line 554 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, CAMBIOCOLOR, NULL, NULL, FROM_AQUI ) ) YYERROR; 
    }
    break;

  case 63:
#line 558 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, NOCOLOR, (char*)(yyvsp[(2) - (3)]), NULL, FROM_AQUI ) ) YYERROR; 
            free( (char*)(yyvsp[(2) - (3)]) );
    }
    break;

  case 64:
#line 563 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, CAMBIOCOLOR, NULL, NULL, 0 ) ) YYERROR; 
    }
    break;

  case 65:
#line 567 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO ;
            if( !tipojuego_code_transforma( tipojuego, NOCOLOR, (char*)(yyvsp[(2) - (2)]), NULL, 0 ) ) YYERROR; 
            free( (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 66:
#line 576 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          if( !tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) ) ) YYERROR;
          free( (char*)(yyvsp[(2) - (3)]) );
    }
    break;

  case 67:
#line 581 "qgames_parser.y"
    {
          CHECK_TIPOJUEGO;
          if( !tipojuego_code_asigna_att( tipojuego, (char*)(yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]) ) ) YYERROR;
          free( (char*)(yyvsp[(2) - (4)]) );
    }
    break;

  case 68:
#line 590 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_juega( tipojuego, NULL, 0 ) ) YYERROR;
    }
    break;

  case 69:
#line 594 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_juega( tipojuego, NULL, 1 ) ) YYERROR;
    }
    break;

  case 70:
#line 598 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_juega( tipojuego, NULL, 0 ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 71:
#line 604 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            if( !tipojuego_code_juega( tipojuego, NULL, 1 ) ) YYERROR;
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 72:
#line 610 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            if( !tipojuego_code_captura( tipojuego, NULL ) ) YYERROR;
    }
    break;

  case 73:
#line 617 "qgames_parser.y"
    {  
            CHECK_TIPOJUEGO;
            tipojuego_code_para( tipojuego );
    }
    break;

  case 74:
#line 621 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
            tipojuego_code_para( tipojuego );
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 75:
#line 632 "qgames_parser.y"
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

  case 76:
#line 643 "qgames_parser.y"
    { 
                          CHECK_TIPOJUEGO;
                          if( !tipojuego_code_mueve( tipojuego, FROM_AQUI | TO_MARCA, 0, (void*)(yyvsp[(3) - (3)]) ) ) YYERROR;
     }
    break;

  case 77:
#line 647 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve cas  => casillero" ); }
    break;

  case 78:
#line 648 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "mueve      => marca" ); }
    break;

  case 79:
#line 655 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 80:
#line 656 "qgames_parser.y"
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

  case 81:
#line 669 "qgames_parser.y"
    { 
                        CHECK_TIPOJUEGO; 
                        if( !tipojuego_code_setmarca( tipojuego, (yyvsp[(2) - (3)]), (char*)(yyvsp[(3) - (3)]) ) ) YYERROR;
                        if( (char*)(yyvsp[(3) - (3)]) ) free( (char*)(yyvsp[(3) - (3)]) );
    }
    break;

  case 82:
#line 674 "qgames_parser.y"
    { 
                        CHECK_TIPOJUEGO; 
                        if( !tipojuego_code_setmarca( tipojuego,  0, (char*)(yyvsp[(2) - (2)]) ) ) YYERROR;
                        if( (char*)(yyvsp[(2) - (2)]) ) free( (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 83:
#line 682 "qgames_parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 84:
#line 683 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 85:
#line 687 "qgames_parser.y"
    {
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_gotomarca( tipojuego, (yyvsp[(2) - (2)]) );
    }
    break;

  case 86:
#line 691 "qgames_parser.y"
    {
                        CHECK_TIPOJUEGO; 
                        tipojuego_code_gotomarca( tipojuego, 0 );
    }
    break;

  case 87:
#line 703 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 88:
#line 706 "qgames_parser.y"
    {
            tipojuego_code_end_condblock( tipojuego );
    }
    break;

  case 90:
#line 711 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            if( !last_block ){
                yyerror( "Break por fuera de bloque" );
                YYERROR;
            }
            tipojuego_code_break_block( tipojuego, last_block );
    }
    break;

  case 91:
#line 721 "qgames_parser.y"
    {
            CHECK_TIPOJUEGO;
            (yyval) = tipojuego_code_start_block( tipojuego );
            // FIXME: Debe usar un stack de bloques.
            last_block = (yyval);
    }
    break;

  case 92:
#line 726 "qgames_parser.y"
    {
            tipojuego_code_start_condblock( tipojuego );
    }
    break;

  case 93:
#line 728 "qgames_parser.y"
    {
            tipojuego_code_continue_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_else_condblock( tipojuego );
            tipojuego_code_break_block( tipojuego, (yyvsp[(2) - (7)]) );
            tipojuego_code_end_condblock( tipojuego );
            tipojuego_code_end_block( tipojuego, (yyvsp[(2) - (7)]) );
    }
    break;

  case 105:
#line 749 "qgames_parser.y"
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

  case 110:
#line 785 "qgames_parser.y"
    {  CHECK_TIPOJUEGO ;
                      CHECK_LAST_PIEZA;
                      if( !tipojuego_add_tpieza_att( tipojuego, last_pieza, ((char*)(yyvsp[(2) - (3)])), (yyvsp[(3) - (3)]) ) ) YYERROR;
                      free( (char*)(yyvsp[(2) - (3)]));
                    }
    break;

  case 111:
#line 795 "qgames_parser.y"
    { CHECK_TIPOJUEGO; 
                     init_parameters(); }
    break;

  case 112:
#line 798 "qgames_parser.y"
    {
                     char*  dims[MAX_PARAMS]; int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                        dims[i] = ((char*)qgz_param_list[i].par);
                     }
                     qg_tipojuego_genera_dimensiones( tipojuego, qgz_param_count, dims );
                   }
    break;

  case 113:
#line 807 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 114:
#line 808 "qgames_parser.y"
    { int i;
                     for( i = 0; i < qgz_param_count; i ++ ){
                       char* col = ((char*)qgz_param_list[i].par);
                       qg_tipojuego_add_color( tipojuego, col );
                     }
                   }
    break;

  case 115:
#line 817 "qgames_parser.y"
    { CHECK_TIPOJUEGO; init_parameters(); }
    break;

  case 116:
#line 818 "qgames_parser.y"
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

  case 117:
#line 829 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 118:
#line 830 "qgames_parser.y"
    { NOT_IMPLEMENTED; }
    break;

  case 119:
#line 833 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, DROP, last_pieza, (char*)((yyvsp[(1) - (2)])) );
    }
    break;

  case 120:
#line 838 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 121:
#line 844 "qgames_parser.y"
    { (yyval) = 0; }
    break;

  case 122:
#line 845 "qgames_parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 123:
#line 849 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO; 
        CHECK_LAST_PIEZA;
        change_to_code_mode(); 
        tipojuego_start_code( tipojuego, MOVE, last_pieza, (char*)((yyvsp[(1) - (2)])) );
        free( (char*)((yyvsp[(1) - (2)])) );
    }
    break;

  case 124:
#line 855 "qgames_parser.y"
    {
        tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 125:
#line 862 "qgames_parser.y"
    { 
            CHECK_TIPOJUEGO; 
            change_to_code_mode(); 
            tipojuego_start_codeend( tipojuego );
    }
    break;

  case 126:
#line 866 "qgames_parser.y"
    {
            tipojuego_end_code( tipojuego ) ;
    }
    break;

  case 127:
#line 871 "qgames_parser.y"
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

  case 128:
#line 885 "qgames_parser.y"
    { html_color1 = (yyvsp[(1) - (3)]); html_color2 = (yyvsp[(3) - (3)]); }
    break;

  case 129:
#line 886 "qgames_parser.y"
    { html_color1 = (yyvsp[(1) - (2)]); html_color2 = (yyvsp[(2) - (2)]);
                                      qgzprintf( "Frente: %x Fondo: %x", html_color1, html_color2 ); }
    break;

  case 130:
#line 890 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (3)]); graph_dim2 = (yyvsp[(3) - (3)]); }
    break;

  case 131:
#line 891 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (3)]); graph_dim2 = (yyvsp[(3) - (3)]); }
    break;

  case 132:
#line 892 "qgames_parser.y"
    { graph_dim1 = (yyvsp[(1) - (2)]); graph_dim2 = (yyvsp[(2) - (2)]); qgzprintf( "%dx%d", (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]) ); }
    break;

  case 133:
#line 895 "qgames_parser.y"
    { graph_dim1 = 0; graph_dim2 = 0; html_color1 = 0; html_color2 = 0; }
    break;

  case 138:
#line 904 "qgames_parser.y"
    { (yyval) = STANDARD_GEM; }
    break;

  case 139:
#line 905 "qgames_parser.y"
    { (yyval) = STANDARD_BISHOP; }
    break;

  case 140:
#line 906 "qgames_parser.y"
    { (yyval) = STANDARD_KING; }
    break;

  case 141:
#line 907 "qgames_parser.y"
    { (yyval) = STANDARD_KNIGHT; }
    break;

  case 142:
#line 908 "qgames_parser.y"
    { (yyval) = STANDARD_PAWN; }
    break;

  case 143:
#line 909 "qgames_parser.y"
    { (yyval) = STANDARD_QUEEN ; }
    break;

  case 144:
#line 910 "qgames_parser.y"
    { (yyval) = STANDARD_ROOK; }
    break;

  case 145:
#line 913 "qgames_parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); 
                  qgzprintf( "Tablero %d", (yyvsp[(1) - (1)]) ); }
    break;

  case 146:
#line 915 "qgames_parser.y"
    { (yyval) = BOARD_ACTUAL; qgzprintf( "Tablero actual" ); }
    break;

  case 147:
#line 918 "qgames_parser.y"
    { (yyval) = TYPE_CHECKERBOARD; }
    break;

  case 148:
#line 919 "qgames_parser.y"
    { (yyval) = TYPE_GRID; }
    break;

  case 149:
#line 920 "qgames_parser.y"
    { (yyval) = TYPE_INTERSECTIONS; }
    break;

  case 150:
#line 923 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        if( !tipojuego_graph_tablero_std( tipojuego, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), graph_dim1, graph_dim2, html_color1, html_color2 ) ) YYERROR;
     }
    break;

  case 151:
#line 927 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-board file" ) }
    break;

  case 152:
#line 928 "qgames_parser.y"
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

  case 153:
#line 937 "qgames_parser.y"
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

  case 154:
#line 946 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-piece string" ); }
    break;

  case 155:
#line 947 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square file" ); }
    break;

  case 156:
#line 948 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square color" ); }
    break;

  case 157:
#line 949 "qgames_parser.y"
    { NOT_IMPLEMENTED_WARN( "graph-square highlighted" ); }
    break;

  case 158:
#line 958 "qgames_parser.y"
    {
        CHECK_TIPOJUEGO;
        qgzprintf( "Definiendo %s", ((char*)(yyvsp[(2) - (2)])) );
        tipojuego_add_tipo_mov( tipojuego, ((char*)(yyvsp[(2) - (2)])) );
        free((void*)(yyvsp[(2) - (2)]));
    }
    break;

  case 159:
#line 966 "qgames_parser.y"
    { (yyval) =  NOTACION_PIEZA; }
    break;

  case 160:
#line 967 "qgames_parser.y"
    { (yyval) =  NOTACION_ORIGEN; }
    break;

  case 161:
#line 968 "qgames_parser.y"
    { (yyval) =  NOTACION_DESTINO; }
    break;

  case 162:
#line 969 "qgames_parser.y"
    { (yyval) =  NOTACION_MARCA ; }
    break;

  case 163:
#line 970 "qgames_parser.y"
    { (yyval) =  NOTACION_CAPTURA; }
    break;

  case 164:
#line 973 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_rep( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 165:
#line 974 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_rep( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 166:
#line 975 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_rep( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 167:
#line 978 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_def( tipojuego, (yyvsp[(1) - (1)]) ); }
    break;

  case 168:
#line 979 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_def( tipojuego, (yyvsp[(2) - (2)]) ); }
    break;

  case 169:
#line 980 "qgames_parser.y"
    { CHECK_TIPOJUEGO; tipojuego_add_notacion_def( tipojuego, (yyvsp[(3) - (3)]) ); }
    break;

  case 170:
#line 984 "qgames_parser.y"
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

  case 171:
#line 998 "qgames_parser.y"
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

  case 172:
#line 1024 "qgames_parser.y"
    { 
                  CHECK_TIPOJUEGO;
                  tipojuego_set_notacion_marca( tipojuego, (char*)(yyvsp[(3) - (3)]), NULL );
                  free((void*)(yyvsp[(3) - (3)]));
             }
    break;

  case 173:
#line 1029 "qgames_parser.y"
    { 
                  CHECK_TIPOJUEGO;
                  tipojuego_set_notacion_marca( tipojuego, NULL, (char*)(yyvsp[(3) - (3)]) );
                  free((void*)(yyvsp[(3) - (3)]));
             }
    break;

  case 176:
#line 1039 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO; 
        tipojuego_add_tipopieza( tipojuego, ((char*)(yyvsp[(2) - (2)])) ); 
        if( last_pieza ) free( last_pieza );
        last_pieza = strdup( ((char*)(yyvsp[(2) - (2)])) );
        free( (char*)(yyvsp[(2) - (2)]) );
    }
    break;

  case 177:
#line 1048 "qgames_parser.y"
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

  case 178:
#line 1057 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 179:
#line 1057 "qgames_parser.y"
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

  case 180:
#line 1068 "qgames_parser.y"
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

  case 181:
#line 1088 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 184:
#line 1092 "qgames_parser.y"
    {
        if( !tipojuego_add_secuencia_rep( tipojuego ) ) YYERROR;
    }
    break;

  case 186:
#line 1099 "qgames_parser.y"
    { 
        CHECK_TIPOJUEGO;
        if( !tipojuego_add_simetria( tipojuego, ((char*)(yyvsp[(2) - (4)])), (char*)(yyvsp[(3) - (4)]), (char*)(yyvsp[(4) - (4)]) ) ) YYERROR;
    }
    break;

  case 187:
#line 1105 "qgames_parser.y"
    { init_parameters(); }
    break;

  case 188:
#line 1105 "qgames_parser.y"
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
#line 3273 "qgames_parser.c"
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


#line 1154 "qgames_parser.y"


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


