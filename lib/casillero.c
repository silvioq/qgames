/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "qgames.h"
#include "tipojuego.h"





Casillero* casillero_new( char* cas, int tablero, int number ){
    Casillero* c = malloc( sizeof( Casillero ) );
    int i;

    memset( c, 0, sizeof( Casillero ) );
    c->nombre = strdup( cas );
    c->tablero = tablero;
    c->number  = number;
    // printf( "El nombre es %s\n", c->nombre );
    for( i = 0; i < MAXDIMS; i ++ ) c->posicion[i] = -1;
    return c;

}

void    casillero_free( Casillero* cas ){


    if( cas->vinculos ) {
        while( cas->vinculos->entradas > 0 ){
            Vinculo* v;
            v = (Vinculo*) cas->vinculos->data[0];
            casillero_kill_vinculo( v->origen, v->direccion, v->destino );
        }
        list_free( cas->vinculos );
    }
    free( cas->nombre );
    free( cas );
}


/*
 * Esta funcion borra el vinculo de la lista, tanto para el origen
 * como para el destino
 * */
void    casillero_kill_vinculo( Casillero* ori, Direccion* dir, Casillero* des ){

    Vinculo* v;
    Vinculo* vv = NULL;
    if( !ori->vinculos ) return;

    // Primero en la lista de origen
    list_inicio( ori->vinculos );
    while( ( v = list_siguiente( ori->vinculos ) ) ){
        if( v->origen == ori && v->direccion == dir && v->destino == des ){
            vv = v;
            list_quita( ori->vinculos, ori->vinculos->actual - 1 );
            break;
        }
    }

    // Y ahora en la lista de destino
    list_inicio( des->vinculos );
    while( ( v = list_siguiente( des->vinculos ) ) ){
        if( v->origen == ori && v->direccion == dir && v->destino == des ){
            list_quita( des->vinculos, des->vinculos->actual - 1 );
            break;
        }
    }

    free( vv );

}


/*
 * Controla que las posiciones pasadas como parametro correspondan
 * con la del casillero 
 * */
int        casillero_check_dims( Casillero* cas, int max_dims, int pos[MAXDIMS] ){
    int i;
    for( i = 0; i < max_dims; i ++ ){
        if( cas->posicion[i] != pos[i] ){
            return 0;
        }
    }
    return 1;
}


/* 
 * Esta función agrega el vínculo en la lista de origen y de destino
 * */

void   casillero_add_vinculo( Casillero* ori, Direccion* dir, Casillero* des ){

    Vinculo* v;
    Vinculo* search;

    // Lo busco en la lista
    search = casillero_busca_vinculo_pororigen( ori, dir );
    assert( !search );

    search = casillero_busca_vinculo_pordestino( des, dir );
    assert( !search );

    // Listo, lo puedo agregar en ambas listas 
    v = vinculo_new( ori, dir, des );

    if( !ori->vinculos ) ori->vinculos = list_nueva( NULL );
    list_agrega( ori->vinculos, v );

    if( !des->vinculos ) des->vinculos = list_nueva( NULL );
    list_agrega( des->vinculos, v );
}


Vinculo*   casillero_busca_vinculo( Casillero* cas, Direccion* dir, char orides ){

    Vinculo* v;

    assert( ( orides == 'O' ) || ( orides == 'D' ) );

    if( !cas->vinculos ) return NULL;
    list_inicio( cas->vinculos );
    while( ( v = list_siguiente( cas->vinculos ) ) ){
        if( orides == 'O' && dir == v->direccion && cas == v->origen ) return v;
        if( orides == 'D' && dir == v->direccion && cas == v->destino ) return v;
    }

    return NULL;


}


/*
 *
 * La busqueda de un vinculo existente es algo que no puede faltar
 *
 * */
Vinculo*   casillero_busca_vinculo_pororigen( Casillero* ori, Direccion* dir ){
    return  casillero_busca_vinculo( ori, dir, 'O' );
}
Vinculo*   casillero_busca_vinculo_pordestino( Casillero* des, Direccion* dir ){
    return  casillero_busca_vinculo( des, dir, 'D' );
}


/*
 * Devuelve verdadero o falso, dependiendo si la posicion
 * relativa del casillero ha sido establecida o no
 * */
int        casillero_posicion_establecida( Casillero* cas ){
    return( cas->posicion[0] != -1 );
}

/*
 * Dado un casillero, devuelve el casillero destino tras moverse
 * en la dirección indicada por parámetro
 * */
Casillero* casillero_aplica_direccion( Casillero* cas, Direccion* dir ){
    int i;
    for( i = 0; i < cas->vinculos->entradas; i ++ ){
        Vinculo* v = cas->vinculos->data[i];
        if( v->origen == cas && v->direccion == dir ) return v->destino;
    }
    return NULL;

}
