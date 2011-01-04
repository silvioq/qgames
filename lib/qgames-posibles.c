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
    movdata->origen      = ( ori ? ( ori == (Casillero*)POZO ? CASILLERO_POZO : ori->nombre ) : NULL );
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
                    movdata->movida_origen = ( piecap->casillero ?
                         ( piecap->casillero == (Casillero*)POZO ? CASILLERO_POZO :
                         piecap->casillero->nombre ) : NULL)  ;
                    movdata->movida_destino = ( mmm->destino ? mmm->destino->nombre : NULL );
                    movdata->movida_ref     = i;
                }
                break;
            case  ACCION_CREA:
                movdata->crea ++;
                if( movdata->crea == 1 ){
                    movdata->crea_pieza = acc->tpieza->nombre;
                    movdata->crea_color = (char*) tipojuego_get_colorname( par->tjuego, acc->color );
                    movdata->crea_casillero = ( mmm->destino ? mmm->destino->nombre : NULL );
                    movdata->crea_ref     = i;
                }
                break;
            case  ACCION_CAPTURA:
                movdata->captura ++;
                if( movdata->captura == 1 ){
                    Pieza* piecap = &(mmm->pos->piezas[acc->pieza_number]);
                    movdata->captura_pieza = piecap->tpieza->nombre;
                    movdata->captura_color = (char*) tipojuego_get_colorname( par->tjuego, piecap->color );
                    movdata->captura_casillero = ( piecap->casillero ? piecap->casillero->nombre : NULL );
                    movdata->captura_ref       = i;
                }
                break;
            case  ACCION_TRANSFORMA:
                movdata->transforma ++;
                if( movdata->transforma == 1 ){
                    Pieza* piecap = &(mmm->pos->piezas[acc->pieza_number]);
                    movdata->transforma_pieza = ( acc->tpieza ? acc->tpieza : piecap->tpieza )->nombre;
                    movdata->transforma_color = (char*) tipojuego_get_colorname( par->tjuego, acc->color );
                    movdata->transforma_ref     = i;
                }
                break;
        }
    }
}

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
DLL_PUBLIC   int         qg_partida_movidas_data  ( Partida* par, int num, Movdata* data ){
    if( PARTIDATERMINADA(par) ) return 0;
    int cant = partida_analizar_movidas( par );
    if( num >= cant ) return 0;
    if( data ){
        Movida* mov = (Movida*) par->pos->movidas->data[num];
        memset( data, 0, sizeof( Movdata ));
        data->numero = num;
        set_movdata( par, mov, data );
    }
    return 1;
}

/*
 * Busca la proxima captura dentro de la estructura de la movida.
 * */
DLL_PUBLIC   int         qg_partida_movdata_nextcap( Partida* par, Movdata* movdata ){
    Movida* mmm = (Movida*)movdata->movida_data;
    int i;
    for( i = movdata->captura_ref + 1; i < mmm->acciones->entradas; i ++ ){
        Accion* acc = mmm->acciones->data[i];
        Pieza* piecap;
        switch( acc->tipo ){
            case  ACCION_CAPTURA:
               piecap = &(mmm->pos->piezas[acc->pieza_number]);
               movdata->captura_pieza = piecap->tpieza->nombre;
               movdata->captura_color = (char*) tipojuego_get_colorname( par->tjuego, piecap->color );
               movdata->captura_casillero = ( piecap->casillero ? piecap->casillero->nombre : NULL );
               movdata->captura_ref       = i;
               return 1;
        }
    }
    movdata->captura_ref       = i; // Para que proximas lecturas directamente salgan sin entrar al for
    return 0;
}

/*
 * Busca la proxima creacion dentro de la estructura de la movida.
 * */
DLL_PUBLIC   int         qg_partida_movdata_nextcrea( Partida* par, Movdata* movdata ){
    Movida* mmm = (Movida*)movdata->movida_data;
    int i;
    for( i = movdata->crea_ref + 1; i < mmm->acciones->entradas; i ++ ){
        Accion* acc = mmm->acciones->data[i];
        switch( acc->tipo ){
            case  ACCION_CREA:
               movdata->crea_pieza = acc->tpieza->nombre;
               movdata->crea_color = (char*) tipojuego_get_colorname( par->tjuego, acc->color );
               movdata->crea_casillero = ( mmm->destino ? mmm->destino->nombre : NULL );
               movdata->crea_ref     = i;
               return 1;
        }
    }
    movdata->crea_ref       = i; // Para que proximas lecturas directamente salgan sin entrar al for
    return 0;
}

/*
 * Busca la proxima movida dentro de la estructura de la movida.
 * */
DLL_PUBLIC   int         qg_partida_movdata_nextmov( Partida* par, Movdata* movdata ){
    Movida* mmm = (Movida*)movdata->movida_data;
    int i;
    for( i = movdata->crea_ref + 1; i < mmm->acciones->entradas; i ++ ){
        Accion* acc = mmm->acciones->data[i];
        Pieza* piecap;
        switch( acc->tipo ){
            case  ACCION_MUEVE:
               movdata->movida_pieza = piecap->tpieza->nombre;
               movdata->movida_color = (char*) tipojuego_get_colorname( par->tjuego, piecap->color );
               movdata->movida_origen = ( piecap->casillero ?
                    ( piecap->casillero == (Casillero*)POZO ? CASILLERO_POZO :
                    piecap->casillero->nombre ) : NULL)  ;
               movdata->movida_destino = ( mmm->destino ? mmm->destino->nombre : NULL );
               movdata->movida_ref     = i;
               return 1;
        }
    }
    movdata->movida_ref       = i; // Para que proximas lecturas directamente salgan sin entrar al for
    return 0;
}

/*
 * Busca la proxima transformacion dentro de la estructura de la movida.
 * */
DLL_PUBLIC    int         qg_partida_movdata_nexttran( Partida* par, Movdata* movdata ){
    Movida* mmm = (Movida*)movdata->movida_data;
    int i;
    for( i = movdata->crea_ref + 1; i < mmm->acciones->entradas; i ++ ){
        Accion* acc = mmm->acciones->data[i];
        Pieza* piecap;
        switch( acc->tipo ){
            case  ACCION_TRANSFORMA:
               piecap = &(mmm->pos->piezas[acc->pieza_number]);
               movdata->transforma_pieza = ( acc->tpieza ? acc->tpieza : piecap->tpieza )->nombre;
               movdata->transforma_color = (char*) tipojuego_get_colorname( par->tjuego, acc->color );
               movdata->transforma_ref     = i;
               return 1;
        }
    }
    movdata->transforma_ref       = i; // Para que proximas lecturas directamente salgan sin entrar al for
    return 0;
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




DLL_PUBLIC   int         qg_partida_movhist_data( Partida* par, int mov, Movdata* movdata ){
    Movida* mmm = partida_get_movimiento( par, mov );
    if( !mmm ) return 0;

    memset( movdata, 0, sizeof( Movdata ) );
    movdata->numero      = mov;
    set_movdata( par, mmm, movdata );
    return 1;
}
