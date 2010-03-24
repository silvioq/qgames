/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2010.
*/

#ifndef  PARTIDA_H
#define  PARTIDA_H

#define   PORCOMENZAR           0x0
#define   JUGANDO               0x1
#define   TERMINADA             0x2
#define   ANALIZANDO            0x3


#define   PARTIDAESTADO(p)   (p->flags&0x3)
/*
 * La bandera de continuacion es para determinar si el proximo movimiento
 * que se realizara es una continuacion de un movimiento primario .
 * Es el tipico caso de la captura en las damas. 
 * Si es cero, se trata del movimiento primario.
 * */
#define   CONTINUACION        0x4
#define   PARTIDACONT(p)     (p->flags&CONTINUACION)

/*
 * La bandera de movidas calculadas determina si las movidas de la posicion
 * han sido calculadas o no 
 * */
#define   MOVCALC             0x8
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
    Posicion*   posicion;

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
    _list*      movidas;
    
} _Partida;


/*
 * La creacion de la partida (escrita totalmente en C) es algo por lo que
 * espere durante mucho tiempo ... aqui esta! 
 * */
Partida*  partida_new( Tipojuego* tjuego );


int       partida_calcular_movidas( Partida* par );
int       partida_mover         ( Partida* par, int mov );
int       partida_mover_notacion( Partida* par, char* mov );


#endif
