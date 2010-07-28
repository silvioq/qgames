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

#ifndef  PARTIDA_H
#define  PARTIDA_H

#define   PORCOMENZAR           0x0
#define   JUGANDO               0x1
#define   TERMINADA             0x2
#define   ANALIZANDO            0x3


#define   PARTIDAESTADO(p)   (p->flags&0x3)
#define   PARTIDATERMINADA(p) (PARTIDAESTADO(p)==TERMINADA)


/* 
 * Esta bandera indica si hay un ganador o es tablas
 * */
#define   ESTABLAS            0x4
#define   PARTIDATABLAS(p)   (p->flags&ESTABLAS)


/*
 * La bandera de continuacion es para determinar si el proximo movimiento
 * que se realizara es una continuacion de un movimiento primario .
 * Es el tipico caso de la captura en las damas. 
 * Si es cero, se trata del movimiento primario.
 * */
#define   CONTINUACION        0x8
#define   PARTIDACONT(p)     (p->flags&CONTINUACION)

/*
 * La bandera de movidas calculadas determina si las movidas de la posicion
 * han sido calculadas o no 
 * */
#define   MOVCALC             0x10
#define   PARTIDAMOVCALC(p)   (p->flags&MOVCALC)





/*
 * Por las dudas, si no se incluyo en alguna otra parte
 * */
#include  <time.h>


typedef  struct  StrPartida {
    Tipojuego*  tjuego;

    /* tmov tiene el tipo de movimiento a realizar ... si esta en blanco
       cualquier tipo de movimiento es posible */
    int         tmov;

    /* 
     * El color es quien realizara la proxima movida
     * */
    int         color;

    /*
     * Para los movimientos continuados, esta variable indica que pieza
     * es la que continua
     * */
    Pieza*      pieza_continua;

    /* La posicion actual. */
    Posicion*   pos;

    /*
     * Secuencia ... contiene el numero en el arreglo de secuencias que
     * corresponde al proximo movimiento (indicara color y tipo movimiento)
     * */
    int         secuencia;

    /*
     * Este flag indica el estado de la partida y si la misma es una
     * continuacion 
     * */
    int         flags;

    /* el id es el identificador unico universal de la partida */
    char*       id;

    /* El inicio y final de la partida, en lo que habitualmente se llama epoch */
    time_t      inicio;
    time_t      final;

    /* Esta es la lista de movidas de la partida */
    _list*      movimientos;

    /* Este es el color ganador! */
    int         color_ganador;
    char*       resultado;
    
} _Partida;


/*
 * La creacion de la partida (escrita totalmente en C) es algo por lo que
 * espere durante mucho tiempo ... aqui esta! 
 * */
Partida*  partida_new( Tipojuego* tjuego, char* id_par );

int       partida_mover_serie ( Partida* par, char* serie );
int       partida_analizar_movidas( Partida* par );
int       partida_analizar_finales( Partida* par );
int       partida_count_piezas    ( Partida* par, char* casillero, char* tipopieza );

Movida*   partida_ultimo_movimiento( Partida* par );


#endif
