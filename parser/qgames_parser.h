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
     TOK_SEPARATOR = 261,
     TOK_ATTR = 262,
     TOK_BOARD = 263,
     TOK_CAPTURED_MARK = 264,
     TOK_CANTIDAD_PIEZAS = 265,
     TOK_COLOR = 266,
     TOK_DEFAULT = 267,
     TOK_DIRECTION = 268,
     TOK_DROP = 269,
     TOK_ENDING = 270,
     TOK_GAMETYPE = 271,
     TOK_MARK = 272,
     TOK_MOVE = 273,
     TOK_MOVETYPE = 274,
     TOK_NOTATION = 275,
     TOK_ONREPEAT = 276,
     TOK_ORIGIN = 277,
     TOK_PIECE = 278,
     TOK_PIECE_NAME = 279,
     TOK_REPEAT = 280,
     TOK_SEQUENCE = 281,
     TOK_START = 282,
     TOK_SYMMETRY = 283,
     TOK_TARGET = 284,
     TOK_ZONE = 285,
     TOK_SEPCODE = 286,
     TOK_AHOGADO = 287,
     TOK_ATACADO_ENEMIGO = 288,
     TOK_CASILLERO_INICIAL = 289,
     TOK_EMPATA = 290,
     TOK_EMPATA_SI = 291,
     TOK_ENTABLERO = 292,
     TOK_ENZONA = 293,
     TOK_GANA = 294,
     TOK_GANA_SI = 295,
     TOK_JAQUEMATE = 296,
     TOK_JUEGA = 297,
     TOK_JUEGA_SI = 298,
     TOK_IF = 299,
     TOK_OCUPADO = 300,
     TOK_OCUPADOENEMIGO = 301,
     TOK_OCUPADOPROPIO = 302,
     TOK_PARA = 303,
     TOK_PARA_SI = 304,
     TOK_PIERDE = 305,
     TOK_PIERDE_SI = 306,
     TOK_TRANSFORMA = 307,
     TOK_AND = 308,
     TOK_OR = 309,
     TOK_NOT = 310,
     TOK_EQUAL = 311,
     TOK_DEQUAL = 312,
     TOK_WHILE = 313,
     TOK_DO = 314,
     TOK_END = 315
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
#define TOK_COLOR 266
#define TOK_DEFAULT 267
#define TOK_DIRECTION 268
#define TOK_DROP 269
#define TOK_ENDING 270
#define TOK_GAMETYPE 271
#define TOK_MARK 272
#define TOK_MOVE 273
#define TOK_MOVETYPE 274
#define TOK_NOTATION 275
#define TOK_ONREPEAT 276
#define TOK_ORIGIN 277
#define TOK_PIECE 278
#define TOK_PIECE_NAME 279
#define TOK_REPEAT 280
#define TOK_SEQUENCE 281
#define TOK_START 282
#define TOK_SYMMETRY 283
#define TOK_TARGET 284
#define TOK_ZONE 285
#define TOK_SEPCODE 286
#define TOK_AHOGADO 287
#define TOK_ATACADO_ENEMIGO 288
#define TOK_CASILLERO_INICIAL 289
#define TOK_EMPATA 290
#define TOK_EMPATA_SI 291
#define TOK_ENTABLERO 292
#define TOK_ENZONA 293
#define TOK_GANA 294
#define TOK_GANA_SI 295
#define TOK_JAQUEMATE 296
#define TOK_JUEGA 297
#define TOK_JUEGA_SI 298
#define TOK_IF 299
#define TOK_OCUPADO 300
#define TOK_OCUPADOENEMIGO 301
#define TOK_OCUPADOPROPIO 302
#define TOK_PARA 303
#define TOK_PARA_SI 304
#define TOK_PIERDE 305
#define TOK_PIERDE_SI 306
#define TOK_TRANSFORMA 307
#define TOK_AND 308
#define TOK_OR 309
#define TOK_NOT 310
#define TOK_EQUAL 311
#define TOK_DEQUAL 312
#define TOK_WHILE 313
#define TOK_DO 314
#define TOK_END 315




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE qgzlval;

