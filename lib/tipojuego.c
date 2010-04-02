/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/


#include  <assert.h>
#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <qgames.h>

#include  "simbolos.h"
#include  "list.h"
#include  "tipojuego.h"


/*
 * Dado un arreglo de posiciones relativas en un tablero,
 * esta funcion devuelve el casillero correspondiente.
 * Si no encuentra ninguno, devuelve Nulo.
 * */

Casillero*  tipojuego_get_casillero_by_relpos( Tipojuego* tj, int tablero, int dims[MAXDIMS] ){
    Casillero* c;
    assert( tablero <= tj->tableros->entradas );
    int  dimensiones = ((Tablero*) tj->tableros->data[tablero - 1] )->dimc;
    list_inicio( tj->casilleros );
    while( ( c = list_siguiente( tj->casilleros ) ) ){
      if( ( c->tablero == tablero ) &&
          ( casillero_check_dims( c, dimensiones, dims ) ) ) return (Casillero*)c ;
    }
    return NULL;
    
}

/*
 * Esta función genera los vínculos entre casilleros a 
 * partir de las posiciones relativas de los casilleros
 * y de las direcciones 
 * */

void    tipojuego_genera_vinculos( Tipojuego* tj, Direccion* dir ){
    int i, j, k;
    Casillero* ori;
    Casillero* des;
    int posicion[MAXDIMS];

    for( i = 0; i < tj->casilleros->entradas; i ++ ){
        ori = (Casillero*) tj->casilleros->data[i];
        if( !casillero_posicion_establecida( ori ) ) continue;
        Tablero* tab = (Tablero*) tj->tableros->data[ori->tablero-1];
        int hay_algo = 0;
        for( k =0 ; k < tab->dimc; k ++ ){
           posicion[k] = ori->posicion[k] + dir->mov_relativo[k] ;
           if( dir->mov_relativo[k] ) hay_algo = 1;
        }
        assert( hay_algo );
        if( ( des = tipojuego_get_casillero_by_relpos( tj, ori->tablero, posicion ) ) ){
            casillero_add_vinculo( ori, dir, des );
        }
    }

}


/*
 *
 * Devuelve el nombre del color pasado como parametro,
 * accediendo a la tabla de simbolos 
 *
 * */

char*       tipojuego_get_colorname( Tipojuego* tj, int color ){
    int i;
    char color_no_encontrado[15];
    assert( tj->simbolos );
    for( i = 0; i < tj->simbolos->entradas; i ++ ){
        volatile Simbolo* sym;
        sym = tj->simbolos->data[i];
        if( sym->tipo != SIM_COLOR ) continue;
        if( sym->ref  == color ) return sym->nombre;
    }
    sprintf( color_no_encontrado, "%d ???", color );
    return  color_no_encontrado;
}

int      tipojuego_get_coloroponente( Tipojuego* tj, int color ){
    int i;
    for( i = 1; i <= tj->colores; i ++ ){
        if( i != color ) return i;
    }
    assert( !"Color no encontrado" );
    return 0;
}


