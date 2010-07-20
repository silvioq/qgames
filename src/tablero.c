/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#include  "qgames.h"
#include  "tipojuego.h"
#include  "graphdef.h"
#include  "log.h"


/*  
 * Creacion de un tablero
 * */
Tablero*   tablero_new( Tipojuego* tj , int numero ){
    Tablero *  t = malloc( sizeof( Tablero ) );
    memset( t, 0, sizeof( Tablero ) );

    t->tipojuego = tj;
    t->numero    = numero;
    return t;

}

#define  SEPARADORES " /"
#define  ES_SEPARADOR(c) ((c) &&  strchr(SEPARADORES,(c)))


int        tablero_genera_dimensiones( Tablero* tab, int dimc, char** dimv ){

    int i;
    int dimint[MAXDIMS];
    char* dimp[MAXDIMS];
    if( tab->dimensiones ){
        LOGPRINT( 1, "Error al setear dimensiones ya cargadas", 0 );
        return 0;
    }

    tab->dimensiones = list_nueva( NULL );
    tab->dimc = dimc;
    for( i = 0; i < dimc; i ++ ){
        list_agrega( tab->dimensiones, strdup( dimv[i] ) );
        dimp[i] = dimv[i];
        dimint[i] = 0;
    }

    while( 1 ){
        // Arma el char con todo
        char  cas[24];
        char* act;
        Casillero* casillero;
        int j;

        memset( cas, 0, 24 );
        act = cas;
        for( i = 0; i < dimc; i ++ ){
            char*  dimpp;
            while( ES_SEPARADOR(*(dimp[i]) )  ) dimp[i] ++;
            dimpp = dimp[i];
            while( (!ES_SEPARADOR( *dimpp ) ) && *dimpp ){
                act[0] = *(dimpp);
                act++; dimpp ++;
            }
        }
        // Creo el casillero ...
        // printf( "Estoy creando casillero %s\n", cas );
        int sim = tipojuego_add_casillero( tab->tipojuego, cas );
        casillero = (Casillero*)tab->tipojuego->casilleros->data[sim];
        for( j = 0; j < dimc; j ++ ){
            casillero->posicion[j] = dimint[j];
            if( dimint[j] + 1 > tab->dimmax[j] ) tab->dimmax[j] =  dimint[j] + 1;
        }

        // Busco el proximo de cada uno
        for( i = dimc - 1; i >= 0; i -- ){
            // Avanzo hasta obtener el proximo o el cero
            while( (!ES_SEPARADOR( *(dimp[i]) ) ) && *(dimp[i]) ) dimp[i] ++;
            // Avanzo mientras tenga espacios
            while( ES_SEPARADOR( *(dimp[i]) ) ) dimp[i] ++;
            if( *(dimp[i]) ) {
              // Si encontre algo, entonces salgo del ciclo
              dimint[i] ++;
              break; 
            } else {
              // Si no encontre nada (o sea fin de cadena) vuelvo el
              // puntero al principio y avanzo el anterior (continuo con 
              // el for)
              dimint[i] = 0;
              dimp[i] = dimv[i];
            }
        }
        
        if( i < 0 ){
            // si llegue hasta aca, implica que la primera
            // dimension creada también fue reseteada.
            // Esto implica que termina todo mi análisis ...
            break;
        }
    }
    return 1;
    
}

Graphdef*  tablero_get_graphdef( Tablero* t ){
    if( t->graphdef ) return t->graphdef;
    Tipojuego* tj = t->tipojuego;
    if( !tj->graphdefs ) return NULL;
    int i;
    for( i = 0; i < tj->graphdefs->entradas; i++ ){
        Graphdef* g = tj->graphdefs->data[i];
        if( g->tipo == TIPOGRAPH_TABLERO && g->tablero == t->numero ){
            t->graphdef = g;
            return g;
        }
    }
    return NULL;
}

