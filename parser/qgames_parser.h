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
     TOK_STANDARD_RECT = 351,
     TOK_STANDARD_ROOK = 352
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
#define TOK_STANDARD_RECT 351
#define TOK_STANDARD_ROOK 352




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE qgzlval;

