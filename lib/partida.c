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
#include "../parser/pgn_scanner.h"

#include "log.h"

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
        if( color ) *color = seq->color;
        if( tmov  ) *tmov  = seq->tmov ;
    } else {
        if( color ) *color = par->secuencia + 1;
        if( tmov  ) *tmov  = 0;
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
    if( color || tmov ) secuencia_actual( par, color, tmov );
}


void    secuencia_anterior( Partida* par ){
    par->secuencia --;
    if( par->tjuego->secuencias ){
        if( par->secuencia < 0 ){
            par->secuencia = par->tjuego->secuencias->entradas - 1;
        }
    } else {
        if( par->secuencia < 0 ){
            par->secuencia = par->tjuego->colores - 1;
        }
    }
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
        char  aux2[16];
        static  int xxx = 100;
        int  mod = xxx % 8;
        char*  id = ALLOC( 256 );
        int  di;
        xxx += 7;
        md5_state_t  md5;
        md5_init( &md5 );

        sprintf( aux, "%d-%d-%d", (long)par->inicio, (long)clock(), xxx );
        md5_append( &md5, aux, strlen( aux ) );
        md5_append( &md5, (void*)(&xxx), sizeof( int ) );
        md5_finish( &md5, aux2 );
        for( di = mod; di < mod + 6; di ++ )
	        sprintf(aux + di * 2, "%02x", aux2[di]);
        LOGPRINT( 6, "mod es = %d %s", mod, aux );
        memcpy( id, aux, 8 );
        id[8] = '@';
        id[9] = 0;
        strcat( id, QGAMES_SERVERNAME );
        par->id = id ;
    }


    return  par;    
}

/*
 * Vamos a liberar todo lo que hay
 * */

void  partida_free( Partida* par ){
    if( par->pos ) posicion_free( par->pos );
    if( par->id ) free( par->id );
    if( par->movimientos ){
        int  i;
        for( i = 0; i < par->movimientos->entradas; i ++ ){
            Movida* mm = (Movida*) par->movimientos->data[i];
            movida_free( mm );
        }
        list_free( par->movimientos );
    }
    free( par );
}



/*
 * Este es el analizador de movidas.
 * Primero verifica que esté todo analizado, luego intentaremos 
 * llamar al calculo de posicion y finalmente, armaremos las
 * notaciones
 * */
int       partida_analizar_movidas( Partida* par ){
    if( PARTIDATERMINADA(par)){
        LOGPRINT(2,"Partida %s terminada", par->id );
        return 0;
    }
    if( PARTIDAMOVCALC(par) ) return  par->pos->movidas->entradas;
    clock_t  inicio;
    clock_t  final ;
    double   elapsed;
    inicio = clock();

    par->flags |= ANALIZANDO;

    posicion_analiza_movidas( par->pos, ANALISIS_MOVIDA, par->color, par->tmov, par->pieza_continua );
    par->flags &= (~ANALIZANDO);
    par->flags |= JUGANDO;

    if( PARTIDACONT( par ) ){
        assert( !"Hace falta agregar el pasar" );
    }

    if( PARTIDACONT( par ) ){
        Movida* mov = partida_ultimo_movimiento( par );
        if( par->pos->movidas ) notacion_resolver_movidas( par->tjuego, par->pos->movidas, mov->notacion );
    } else {
        if( par->pos->movidas ) notacion_resolver_movidas( par->tjuego, par->pos->movidas, NULL );
    }

    final   =  clock();
    elapsed = ((double) (final - inicio)) / CLOCKS_PER_SEC;
    LOGPRINT( 5, "Total: %.6f", elapsed );
    par->flags |= MOVCALC;
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
    if( PARTIDATERMINADA(par)){
        LOGPRINT(2,"Partida %s terminada", par->id );
        return 0;
    }
    if( !PARTIDAMOVCALC(par) ) partida_analizar_movidas( par );
    if( mov >= par->pos->movidas->entradas ) return 0;
    return partida_mover_mov( par, (Movida*)par->pos->movidas->data[mov] );
}


int       partida_mover_notacion( Partida* par, char* mov ){
    if( PARTIDATERMINADA(par)){
        LOGPRINT(2,"Partida %s terminada", par->id );
        return 0;
    }
    if( !PARTIDAMOVCALC(par) ) partida_analizar_movidas( par );
    int i;
    for( i = 0; i < par->pos->movidas->entradas; i ++ ){
        Movida* mmm = (Movida*)par->pos->movidas->data[i];
        if( strcmp( mov, mmm->notacion ) == 0 ) 
            return  partida_mover_mov( par, mmm );
    }
    LOGPRINT( 3, "No encuentro la movida %s", mov );
    return 0;
}


/* 
 * Esta funcion parsea la entrada como si fuera un archivo pgn
 * y ejecuta los movimientos establecidos
 * */
int         partida_mover_pgn     ( Partida* par, char* pgn ){
    if( PARTIDATERMINADA(par)){
        LOGPRINT(2,"Partida %s terminada", par->id );
        return 0;
    }
    int i = pgnscan_string( pgn );
    if( !i ){
        LOGPRINT( 2, "Error al analizar PGN: %s", pgnerror );
        return 0;
    }
    return  partida_mover_serie( par, pgnmoves );
}


int         partida_mover_serie ( Partida* par, char* serie ){
    char*  movepoint = serie;
    while( 1 ) {
        int  i  = 0;
        char   move[256];
        while( movepoint[i] && movepoint[i] != ' ' ){
            move[i] = movepoint[i];
            i ++;
        }
        move[i] = 0;
        if( !partida_mover_notacion( par, move ) ) return 0;
        if( PARTIDATERMINADA(par) ) return 1;
        if( movepoint[i] == 0 ) return 1;
        movepoint += i + 1;
    }
}

/*
 * Esta es la verdadera ejecucion de movimientos
 * */

int   partida_mover_mov( Partida* par, Movida* mov ){
    Posicion* parnew;
    int  ret;
    if( PARTIDACONT( par ) ){
        assert( !"Hace falta agregar las movidas continuadas a la lista de movimientos anterior" );
    }
    if( !par->movimientos ) par->movimientos = list_nueva( NULL );
    list_agrega( par->movimientos, movida_dup( mov ) );

    parnew = movida_ejecuta( mov );
    posicion_free_movidas( par->pos );
    par->pos = parnew;
    par->flags &= ~MOVCALC;

    int  color_actual = par->color;
    int  color_sig ;
    secuencia_siguiente( par, &color_sig, NULL );
    secuencia_anterior( par );
    char* resultado;
    ret = posicion_analiza_final( par->pos, color_actual, color_sig, &resultado );
    if( ret == FINAL_EMPATE ){
        par->resultado = resultado;
        par->flags    |= ESTABLAS;
        par->flags    &= (~ANALIZANDO );
        par->flags    |= TERMINADA;
    } else if ( ret > 0 ){
        par->resultado = resultado;
        par->color_ganador = ret;
        par->flags    &= (~ANALIZANDO );
        par->flags    |= TERMINADA;
    } else {
        secuencia_siguiente( par, &(par->color), &(par->tmov) );
    }
    return 1;
}

/*
 * Contador de cantidad de piezas, muy útil a la hora
 * de hacer pruebas
 * */
int         partida_count_piezas  ( Partida* par, char* casillero ){
    Casillero* cas;
    int count = 0;
    if( !casillero ){
        cas = NULL;
    } else if( casillero == CASILLERO_POZO ){
        cas = ENPOZO;
    } else if ( casillero == CASILLERO_CAPTURA ){
        cas = ENCAPTURA;
    } else {
        int ret = GETCASILLERO( par->tjuego, casillero );
        cas = (Casillero*) par->tjuego->casilleros->data[ret];
    }

    int i;
    for( i = 0; i < par->pos->piezas->entradas; i ++ ){
         Pieza* pie = (Pieza*) par->pos->piezas->data[i];
         if( pie ){
              if( !cas ){
                  count ++;
              } else if( cas == pie->casillero ){
                  count ++;
              }
         }
    }

    return  count;

}


void        partida_tablero_ascii ( Partida* par ){
    int i;
    printf( "Partida: %s (%s)\n", par->id, par->tjuego->nombre );
    for( i = 0; i < par->pos->piezas->entradas; i ++ ){
        Pieza* pie = (Pieza*) par->pos->piezas->data[i];
        if( CASILLERO_VALIDO( pie->casillero ) ){
            printf( "%s %s en %s\n", pie->tpieza->nombre,
                tipojuego_get_colorname( par->tjuego, pie->color ),
                pie->casillero->nombre );
        }
    }
}

/*
 * Devuelve la cantidad de entradas que tiene el tablero
 * */
int         partida_tablero_count ( Partida* par ){
    int ret, i;
    ret = 0;
    for( i = 0; i < par->pos->piezas->entradas; i ++ ){
        Pieza* pie = (Pieza*) par->pos->piezas->data[i];
        if( CASILLERO_VALIDO( pie->casillero ) ) ret ++;
    }
    return ret;
}


int         partida_tablero_data  ( Partida* par, int num, char** casillero, char** pieza, char** color ){
    int i; int cont = 0;
    for( i = 0; i < par->pos->piezas->entradas; i ++ ){
        Pieza* pie = (Pieza*) par->pos->piezas->data[i];
        if( CASILLERO_VALIDO( pie->casillero ) ){
            if( cont == num ){
                if( casillero ) *casillero = pie->casillero->nombre;
                if( pieza )     *pieza     = pie->tpieza->nombre;
                if( color )     *color     = tipojuego_get_colorname( par->tjuego, pie->color );
                return 1;
            } else cont ++;
        }
    }
    return 0;
}


void        partida_movidas_posibles_ascii( Partida* par ){
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
 * Devuelve el dato de notacion de la partida pasada como parametro
 * */
int         partida_movidas_data  ( Partida* par, int num, char** notacion ){
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

/*
 * Devuelve la cantidad de movidas que hay generadas
 * */
int         partida_movidas_count ( Partida* par ){
    if( PARTIDATERMINADA(par) ){ 
        return 0;
    }
    return partida_analizar_movidas( par );
}

/*
 * Devuelve el final de la partida ... en el caso
 * que haya terminado
 * */

int         partida_final         ( Partida* par, char** resultado ){
    if( resultado ){
      *resultado = par->resultado;
    }
    if( PARTIDAESTADO(par) == TERMINADA ){
        if( PARTIDATABLAS(par) ){
            return  FINAL_EMPATE;
        } else {
            return  par->color_ganador;
        }
    } else return  FINAL_ENJUEGO;
    

}

