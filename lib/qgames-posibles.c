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
 * Devuelve verdadero en el caso que las movidas posibles de una partida
 * hayan sido analizadas previmante. Esto permite efectuar el control
 * del estado de la partida para sucesivos dump.
 * Ejemplo:
 *   analizada = qg_partida_movidas_analizadas( partida );
 *   printf( "La cantidad de movidas posibles es %d\n", qg_partida_movidas_count( partida ) ); 
 *   if( !analizada ) save_dump_partida( partida );
 *
 * En este ejemplo, se controla la marca de analizada de la partida. Si no estaba
 * analizada previamente, se salva el dump, ya que el mismo cambio
 * */
DLL_PUBLIC   int         qg_partida_movidas_analizadas( Partida* par ){
    return  PARTIDAMOVCALC( par );
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
                if( color ) *color         = (char*)tipojuego_get_colorname( par->tjuego, p->color );
                if( pieza ) *pieza         = p->tpieza->nombre;
                return 1;
            }
            contador ++;
        }
    }
    return 0;
}

/*
 * Esta funcion devuelve la informacion acerca de la "enesima" pieza a crear
 * tras la jugada 
 * */

DLL_PUBLIC    int         qg_partida_movidas_crea  ( Partida* par, int nummov, int numcr, 
      char** casillero,  char** tpieza, char** color ){

    if( PARTIDATERMINADA(par) ){ 
        return 0;
    }
    int cant = partida_analizar_movidas( par );
    if( nummov >= cant ) return 0;
    Movida* mov = par->pos->movidas->data[nummov];
    int i, contador = 0 ;
    for( i = 0; i < mov->acciones->entradas; i ++ ){
        Accion* acc = mov->acciones->data[i];
        if( acc->tipo == ACCION_CREA ){
            if( contador == numcr ){
                if( casillero ) *casillero = acc->destino->nombre;
                if( color )  *color        = (char*) tipojuego_get_colorname( par->tjuego, acc->color );
                if( tpieza ) *tpieza       = acc->tpieza->nombre;
                return 1;
            }
            contador ++;
        }
    }
    return 0;


}

/*
 * Devuelve informacion acerca de la pieza que vamos a mover
 * origen:  Casillero origen donde se encuentra actualmente la pieza
 * tpieza:  Tipo de pieza
 * color :  Color de la pieza
 * destino: Casillero destino donde se dirigira la pieza
 * ttpieza: Tipo de pieza en la que se transformara (null si no se transforma)
 * tcolor:  Color en el que se transformar (null si no se transforma)
 * */

DLL_PUBLIC    int         qg_partida_movidas_pieza ( Partida* par, int nummov, 
                                            char** origen, char** tpieza, char** color, 
                                            char** destino, char** ttpieza, char** tcolor ){
    if( PARTIDATERMINADA(par) ){ 
        return 0;
    }
    int cant = partida_analizar_movidas( par );
    if( nummov >= cant ) return 0;
    Movida* mov = par->pos->movidas->data[nummov];
    Pieza* p = movida_pieza( mov );
    if( p ){
        Casillero* o = movida_casillero_origen( mov );
        Casillero* d = movida_casillero_destino( mov );
        if( tpieza  ) *tpieza  = p->tpieza->nombre;
        if( color   ) *color   = (char*)tipojuego_get_colorname( par->tjuego, p->color );
        if( origen  ) *origen  = ( o == ENPOZO ? CASILLERO_POZO : o->nombre );
        if( destino ) *destino = ( CASILLERO_VALIDO( d ) ? d->nombre : NULL );
        if( ttpieza || tcolor ){  // Esta recorrida la hago en el caso que me lo hayan pedido
            int i, transf = 0;
            for( i = 0; i < mov->acciones->entradas; i ++ ){
                Accion* acc = mov->acciones->data[i];
                if( acc->tipo == ACCION_TRANSFORMA && acc->pieza_number == p->number ){
                    if( ttpieza ) *ttpieza = acc->tpieza->nombre;
                    if( tcolor  ) *tcolor  = (char*)tipojuego_get_colorname( par->tjuego, acc->color );
                    transf = 1;
                    break;
                }
            }
            // Si no hay transformacion, nulifico.
            if( !transf ){
                if( ttpieza ) *ttpieza = NULL;
                if( tcolor )  *tcolor  = NULL;
            }
        }
        return 1;
    } else return 0;
}


/*
 * Devuelve la cantidad de movidas historicas de la partida
 * */

DLL_PUBLIC    int         qg_partida_movhist_count( Partida* par ){
    if( !par->movimientos ) return 0;
    return   par->movimientos->entradas;
}

/*
 * Dado una movida historica (comenzando con la movida cero), y un numero
 * de destino (que tambien comienza con el cero), devuelve el casillero
 * correspondiente
 * */
DLL_PUBLIC    const char* qg_partida_movhist_destino      ( Partida* par, int mov, int dest ){
    Movida* mmm = partida_get_movimiento( par, mov );
    if( !mmm ) return NULL;
    int i, contador = 0;
    for( i = 0; i < mmm->acciones->entradas; i ++ ){
        Accion* acc = mmm->acciones->data[i];
        if( acc->destino ){
            if( dest == contador ) return acc->destino->nombre;
            contador ++;
        }
    }
    return  NULL;
}

/*
 * Esta funcion llena la estructura a partir de la movida pasada como parametro
 * */
static   set_movdata( Partida* par, Movida* mmm, Movdata* movdata ){
    Pieza*  pie = movida_pieza( mmm );
    Casillero* ori = movida_casillero_origen( mmm );
    Casillero* des = movida_casillero_destino( mmm );
    int i;

    movdata->movida_data = (void*) mmm;
    movdata->notacion    = mmm->notacion;
    movdata->descripcion = "Descripcion de la partida";
    movdata->pieza       = pie->tpieza->nombre;
    movdata->color       = (char*) tipojuego_get_colorname( par->tjuego, pie->color );
    movdata->origen      = ( ori ? ori->nombre : NULL );
    movdata->destino     = ( des ? des->nombre : NULL );
    for( i = 0; i < mmm->acciones->entradas; i ++ ){
        Accion* acc = mmm->acciones->data[i];
        switch( acc->tipo ){
            case  ACCION_MUEVE:
                movdata->movida ++;
                if( movdata->movida == 1 ){
                    Pieza* piecap = &(mmm->pos->piezas[acc->pieza_number]);
                    movdata->movida_pieza = piecap->tpieza->nombre;
                    movdata->movida_color = (char*) tipojuego_get_colorname( par->tjuego, piecap->color );
                    movdata->movida_origen = ( piecap->casillero ? piecap->casillero->nombre : NULL );
                    movdata->movida_destino = ( mmm->destino ? mmm->destino->nombre : NULL );
                }
                break;
            case  ACCION_CREA:
                movdata->crea ++;
                if( movdata->crea == 1 ){
                    Pieza* piecap = &(mmm->pos->piezas[acc->pieza_number]);
                    movdata->crea_pieza = piecap->tpieza->nombre;
                    movdata->crea_color = (char*) tipojuego_get_colorname( par->tjuego, piecap->color );
                    movdata->crea_casillero = ( piecap->casillero ? piecap->casillero->nombre : NULL );
                }
                break;
            case  ACCION_CAPTURA:
                movdata->captura ++;
                if( movdata->captura == 1 ){
                    Pieza* piecap = &(mmm->pos->piezas[acc->pieza_number]);
                    movdata->captura_pieza = piecap->tpieza->nombre;
                    movdata->captura_color = (char*) tipojuego_get_colorname( par->tjuego, piecap->color );
                    movdata->captura_casillero = ( piecap->casillero ? piecap->casillero->nombre : NULL );
                }
                break;
            case  ACCION_TRANSFORMA:
                movdata->transforma ++;
                if( movdata->transforma == 1 ){
                    movdata->transforma_tipo = acc->tpieza->nombre;
                    movdata->transforma_color = (char*) tipojuego_get_colorname( par->tjuego, acc->color );
                }
                break;
        }
    }
}



DLL_PUBLIC   int         qg_partida_movhist_data( Partida* par, int mov, Movdata* movdata ){
    Movida* mmm = partida_get_movimiento( par, mov );
    if( !mmm ) return 0;

    memset( movdata, 0, sizeof( Movdata ) );
    movdata->numero      = mov;
    set_movdata( par, mmm, movdata );
    return 1;
}
