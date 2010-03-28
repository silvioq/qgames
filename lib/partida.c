/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2010.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <md5.h>
#include <time.h>
#include <qgames.h>
#include "config.h"
#include "tipojuego.h"
#include "pieza.h"
#include "posicion.h"
#include "movida.h"
#include "partida.h"

int   partida_mover_mov( Partida* par, Movida* mov );

/* 
 * Esta funcion devuelve la proxima secuencia, a partir
 * del estado de la partida y de la definicion misma de secuencia
 * */
void    secuencia_actual   ( Partida* par, int* color, int* tmov ){
    Secuencia* seq;
    if( par->tjuego->secuencias ){
        assert( par->secuencia < par->tjuego->secuencias->entradas );
        seq = (Secuencia*)par->tjuego->secuencias->data[par->secuencia];
        *color = seq->color;
        *tmov  = seq->tmov ;
    } else {
        *color = par->secuencia + 1;
        *tmov  = 0;
    }
}

void    secuencia_siguiente( Partida* par, int* color, int* tmov ){
    par->secuencia ++;
    if( par->tjuego->secuencias ){
        if( par->secuencia >=  par->tjuego->secuencias->entradas ){
            par->secuencia = par->tjuego->secuencia_repeat;
        }
    } else {
        if( par->secuencia >= par->tjuego->colores ){
            par->secuencia = 0;
        }
    }
    secuencia_actual( par, color, tmov );
}



Partida*  partida_new( Tipojuego* tjuego ){
    Partida*  par = ALLOC( sizeof( Partida ) );
    memset( par, 0, sizeof( Partida ) );
    par->tjuego = tjuego;
    par->pos    = posicion_dup( tjuego->inicial );
    secuencia_actual( par, &(par->color), &(par->tmov) );
    par->flags |= PORCOMENZAR;
    par->inicio = time( NULL );

    // Calculo el id
    {
        char  aux[256];
        static  int xxx = 100;
        int  mod = xxx % 8;
        char*  id = ALLOC( 256 );
        xxx += 7;
        md5_state_t  md5;
        md5_init( &md5 );
        sprintf( aux, "%d-%d-%d", (long)par->inicio, (long)clock(), xxx );
        md5_append( &md5, aux, strlen( aux ) );
        md5_append( &md5, (void*)(&xxx), sizeof( int ) );
        md5_finish( &md5, aux );
        memcpy( id, aux + mod, 8 );
        id[8] = '@';
        id[9] = 0;
        strcat( id, QGAMES_SERVERNAME );
        par->id = id ;
    }


    return  par;    
}



/*
 * Este es el analizador de movidas.
 * Primero verifica que esté todo analizado, luego intentaremos 
 * llamar al calculo de posicion y finalmente, armaremos las
 * notaciones
 * */
int       partida_analizar_movidas( Partida* par ){
    if( PARTIDAMOVCALC(par) ) return  par->pos->movidas->entradas;
    clock_t  inicio = clock();
    clock_t  final ;
    double   elapsed;

    par->flags |= ANALIZANDO;

    posicion_analiza_movidas( par->pos, ANALISIS_MOVIDA, par->color, par->tmov, par->pieza_continua );
    par->flags &= (~ANALIZANDO);
    par->flags |= JUGANDO;

    if( PARTIDACONT( par ) ){
        assert( !"Hace falta agregar el pasar" );
    }

    if( PARTIDACONT( par ) ){
        Movida* mov = partida_ultimo_movimiento( par );
        notacion_resolver_movidas( par->tjuego, par->pos->movidas, mov->notacion );
    } else {
        notacion_resolver_movidas( par->tjuego, par->pos->movidas, NULL );
    }

    final   =  clock();
    elapsed = ((double) (final - inicio)) / CLOCKS_PER_SEC;
    printf( "Total: %.6f\n", elapsed );

    return  par->pos->movidas->entradas;
}


/*
 *
 * Ultimo movimiento realizado.
 *
 * */
Movida*     partida_ultimo_movimiento( Partida* par ){
    assert( par->movimientos );
    assert( par->movimientos->entradas > 0 );
    return (Movida*)(par->movimientos->data[par->movimientos->entradas - 1]);
}

/*
 * Hace un movimiento, de acuerdo a la lista de movidas posibles.
 * */
int       partida_mover         ( Partida* par, int mov ){
    if( !PARTIDAMOVCALC(par) ) partida_analizar_movidas( par );
    if( mov >= par->pos->movidas->entradas ) return 0;
    return partida_mover_mov( par, (Movida*)par->pos->movidas->data[mov] );
}


int       partida_mover_notacion( Partida* par, char* mov ){
    if( !PARTIDAMOVCALC(par) ) partida_analizar_movidas( par );
    int i;
    for( i = 0; i < par->pos->movidas->entradas; i ++ ){
        Movida* mmm = (Movida*)par->pos->movidas->data[i];
        if( strcmp( mov, mmm->notacion ) == 0 ) 
            return  partida_mover_mov( par, mmm );
    }
    printf( "(cuidado) %s:%d No encuentro la movida %s\n", __FILE__, __LINE__, mov );
    return 0;
}

/*
 * Esta es la verdadera ejecucion de movimientos
 * */

int   partida_mover_mov( Partida* par, Movida* mov ){
    if( PARTIDACONT( par ) ){
        assert( !"Hace falta agregar las movidas continuadas a la lista de movimientos anterior" );
    }
    if( !par->movimientos ) par->movimientos = list_nueva( NULL );
    list_agrega( par->movimientos, movida_dup( mov ) );

    posicion_free_movidas( par->pos );
    par->pos = movida_ejecuta( mov );
    

    return 1;
}

