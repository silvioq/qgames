/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/


#include  <assert.h>
#include  <stdlib.h>
#include  <qgames.h>
#include  "simbolos.h"
#include  "list.h"
#include  "tipojuego.h"

Casillero* tipojuego_get_casillero_by_num( Tipojuego* tj, int nro ){
    Simbolo* sym;
    assert( tj->simbolos->entradas > nro );
    sym = tj->simbolos->data[nro];
    assert( sym->tipo == SIM_CASILLERO );
    return  (Casillero*)sym->data;
}

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
