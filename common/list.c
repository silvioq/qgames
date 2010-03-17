/*
 *
 * Libreria para listas de proposito general
 * Haga lo que quiera con ella, pero no hay garantias
 * Silvio Quadri (c) 2009
 *
 * */

#include  "list.h"
#include  <stdlib.h>
#include  <string.h>
#include  <assert.h>


#define  LIST_ALLOC(n)      malloc(n)
#define  LIST_REALLOC(p,n)  realloc(p,n)
#define  LIST_FREE(p)       free(p)

#define  DEFAULT_ALLOC      10

/*
 * Definicion de nueva lista
 */
_list*  list_nueva( _list_freefunc free_func ){
    _list*  l = LIST_ALLOC(sizeof(_list));
    l->entradas = 0;
    l->tamanio  = DEFAULT_ALLOC;
    l->data     = LIST_ALLOC( sizeof(void*) * DEFAULT_ALLOC );
    l->actual   = 0;
    l->free_func = free_func;
    return l;
}

/*
 * Agrega un nuevo elemento
 * */
int    list_agrega( _list* lista, void* data ){
    int  ret;
    if( lista->entradas == lista->tamanio ){
        lista->tamanio += DEFAULT_ALLOC;
        assert( lista->data = LIST_REALLOC( lista->data, lista->tamanio * sizeof(void*) ) );
    }
    ret = lista->entradas;
    lista->data[lista->entradas++] = data;
    return  ret;
}

/*
 * Quita algo de la lista y mueve todo el aparato
 * */
void    list_quita( _list* lista, int entrada ){

    // Una comprobacion importante y de bajo costo!
    assert( entrada < lista->entradas );

    if( lista->free_func ) lista->free_func( lista->data[entrada] );
    if( lista->actual >= entrada ) lista->actual --;

    if( lista->entradas - entrada - 1 > 0 ){
        memmove( lista->data + entrada, lista->data + entrada + 1, 
                 ( lista->entradas - entrada - 1 ) * sizeof( void* ) );
    }

    lista->entradas --;

}

/*
 * Toma el último valor y lo quita de la lista
 *
 * */
void*   list_pop( _list*  lista ){

    void* v;
    if( lista->entradas == 0 ){
        return NULL;
    }

    lista->entradas --;
    v = lista->data[lista->entradas];
    return v;
}

/*
 * Limpia los datos de la lista
 * y la lista también ...
 * */
void    list_free( _list* lista ){

    int i;
    if( lista->free_func ){
        for( i = 0; i < lista->entradas; i ++ ){
            if( lista->free_func ) lista->free_func( lista->data[i] );
        }
    }

    LIST_FREE( lista );

}

