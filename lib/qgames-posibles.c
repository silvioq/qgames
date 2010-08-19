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

/*
 * En este archivo pondremos todas las funciones relativas a las
 * movidas posibles exportadas por el qgames
 * */

#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <stdarg.h>
#include  <qgames.h>
#include  <qgames_code.h>
#include  <qgames_analyzer.h>

#include  "config.h"
#include  "qgames_core.h"
#include  "list.h"
#include  "tipojuego.h"
#include  "graphdef.h"
#include  "simbolos.h"
#include  "pieza.h"
#include  "movida.h"
#include  "partida.h"
#include  "posicion.h"
#include  "log.h"
#include "../parser/pgn_scanner.h"



DLL_PUBLIC   int         qg_partida_movidas_count ( Partida* par ){
    if( PARTIDATERMINADA(par) ) return 0;
    return partida_analizar_movidas( par );
}
/* 
 * Devuelve el dato de notacion de la partida pasada como parametro
 * */
DLL_PUBLIC   int         qg_partida_movidas_data  ( Partida* par, int num, char** notacion ){
    if( PARTIDATERMINADA(par) ){ 
        return 0;
    }
    int cant = partida_analizar_movidas( par );
    if( num >= cant ) return 0;
    if( notacion ){
        Movida* mov = (Movida*) par->pos->movidas->data[num];
        *notacion = mov->notacion;
    }
    return 1;
}


DLL_PUBLIC   int         qg_partida_movida_valida ( Partida* par, char* notacion ){
    return     partida_movida_valida( par, notacion );
}

/*
 * Esta funcion especial imprime en la consola de texto
 * las posibles movidas que pueden realizarse en la 
 * posicion actual
 * */
DLL_PUBLIC    void        qg_partida_movidas_posibles_ascii( Partida* par ){
    int cant, i;
    if( PARTIDATERMINADA(par) ){
        printf( "Partida terminada %s\n", par->resultado );
        return;
    }
    cant = partida_analizar_movidas( par );
    for( i = 0; i < cant; i ++ ){
        Movida* mov = (Movida*) par->pos->movidas->data[i];
        if( ( i % 4 == 0 ) && i > 0 ){ printf( "\n" ); };
        printf( "%2d) %-16s", i, mov->notacion );
    }
    printf( "\n" );
}


/*
 * Esta funcion devuelve informacion acerca de la enesima pieza capturada
 * */
DLL_PUBLIC    int         qg_partida_movidas_capturas( Partida* par, int nummov, int numpie, 
        char** casillero, char** pieza, char ** color ){
    if( PARTIDATERMINADA(par) ){ 
        return 0;
    }
    int cant = partida_analizar_movidas( par );
    if( nummov >= cant ) return 0;
    Movida* mov = par->pos->movidas->data[nummov];
    int i, contador = 0 ;
    for( i = 0; i < mov->acciones->entradas; i ++ ){
        Accion* acc = mov->acciones->data[i];
        if( acc->tipo == ACCION_CAPTURA ){
            if( contador == numpie ){
                Pieza* p = &(par->pos->piezas[acc->pieza_number]);
                if( casillero ) *casillero = p->casillero->nombre;
                if( color ) *color         = tipojuego_get_colorname( par->tjuego, p->color );
                if( pieza ) *pieza         = p->tpieza->nombre;
                return 1;
            }
            contador ++;
        }
    }
    return 0;
}
