/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE qgzlval;

