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

#ifndef   QGAMES_CODE_H
#define   QGAMES_CODE_H  1



/*
 * Toda esta parte es para definir el codigo
 * */

// Tipos de reglas
#define   DROP  'D'
#define   MOVE  'M'
#define   END   'E'

int         tipojuego_start_code(  Tipojuego* tj, char tiporegla, char* tipopieza, char* tipomov );
#define     tipojuego_start_codeend(tj) tipojuego_start_code( tj, END, NULL, NULL )
void        tipojuego_end_code( Tipojuego* tj );
void*       tipojuego_get_code( Tipojuego* tj );

void        tipojuego_code_start_condblock( Tipojuego* tj );
void        tipojuego_code_else_condblock( Tipojuego* tj );
void        tipojuego_code_end_condblock( Tipojuego* tj );
long        tipojuego_code_start_block( Tipojuego* tj );
void        tipojuego_code_end_block( Tipojuego* tj, long block );
void        tipojuego_code_break_block( Tipojuego* tj, long block );
void        tipojuego_code_continue_block( Tipojuego* tj, long block );

void        tipojuego_code_op_not( Tipojuego* tj );
void        tipojuego_code_op_equal( Tipojuego* tj, long val );
void        tipojuego_code_op_false( Tipojuego* tj );

int         tipojuego_code_direccion( Tipojuego* tj, char* direccion );
int         tipojuego_code_casillero( Tipojuego* tj, char* casillero );
int         tipojuego_code_setmarca ( Tipojuego* tj, int marca, char* casillero );
int         tipojuego_code_gotomarca ( Tipojuego* tj, int marca );
int         tipojuego_code_asigna_att( Tipojuego* tj, char* att, int val );
int         tipojuego_code_evalua_att( Tipojuego* tj, char* att );
int         tipojuego_code_juega  ( Tipojuego* tj, char* casillero, int captura, int continua, char* tmov );
int         tipojuego_code_captura( Tipojuego* tj, char* casillero );
int         tipojuego_code_crea   ( Tipojuego* tj, char* tpieza, int owner, char* color, char* casillero );

/**
 * @owner   ENEMIGO , PROPIO , CAMBIACOLOR
 * @color   Color a transformar
 * @tpieza  Tipo de pieza a cambiar
 * @flags   FROM_CASILLERO: Indica que las piezas a transformar son las
 *                          que ocupan el casillero actual
 **/
int         tipojuego_code_transforma( Tipojuego* tj, int owner, char* color, char* tpieza, int flags );
void        tipojuego_code_para   ( Tipojuego* tj );

/*
 * fromto => Indica que tiene los parametros from y to
 * */
#define     FROM_AQUI                  0x10
#define     FROM_MARCA                 0x20
#define     FROM_CASILLERO             0x30
#define     FROM_MASK                  0xF0
#define     TO_AQUI                    0x01
#define     TO_MARCA                   0x02
#define     TO_CASILLERO               0x03 
#define     TO_MASK                    0x0F
int         tipojuego_code_mueve  ( Tipojuego* tj, char fromto_flags, void* from, void* to );

/* Definiciones para los dueños o colores */
#define   ENEMIGO       -1
#define   PROPIO        -2
#define   CAMBIOCOLOR   -3
#define   CUALQUIERA     0
#define   NOCOLOR        0
int         tipojuego_code_ahogado( Tipojuego* tj, char* color );
int         tipojuego_code_atacado( Tipojuego* tj, char* casillero );
int         tipojuego_code_destino_ant( Tipojuego* tj, char* casillero );
int         tipojuego_code_origen_ant( Tipojuego* tj, char* casillero );
int         tipojuego_code_cuenta_piezas( Tipojuego* tj, char* casillero, int owner, char* color, char* tpieza );
int         tipojuego_code_ocupado( Tipojuego* tj, char* casillero, int owner, char* color, char* tpieza );
int         tipojuego_code_entablero( Tipojuego* tj );
int         tipojuego_code_enzona ( Tipojuego* tj, char* zona, char* tpieza );
int         tipojuego_code_jaquemate( Tipojuego* tj, char* tpieza );

#define   ENJUEGO   0
#define   GANA      1
#define   PIERDE    2
#define   EMPATA    3
int         tipojuego_code_final  ( Tipojuego* tj, char* color, int resultado );




#endif
