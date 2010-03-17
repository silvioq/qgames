/*
 *
 * Libreria para listas de proposito general
 * Haga lo que quiera con ella, pero no hay garantias
 * Silvio Quadri (c) 2009
 *
 * */

#ifndef  LIST_INCLUDED
#define  LIST_INCLUDED

typedef  void(*_list_freefunc)(void*);

#ifndef  NULL  
#define  NULL  (void*)0
#endif

typedef  struct  _str_list{
    void**  data;
    unsigned int    entradas;
    unsigned int    tamanio;
    unsigned int    actual;
    _list_freefunc   free_func;
}  _list;


_list*  list_nueva( _list_freefunc free_func );
int     list_agrega( _list* lista, void* data );
void    list_quita( _list* lista, int entrada );
void*   list_pop( _list*  lista );
void    list_free( _list* );

static inline void    list_inicio( _list* lista ) { lista->actual = 0; } 
static inline void    list_final( _list* lista )  { lista->actual = lista->entradas - 1; } 

static inline void*   list_siguiente( _list* lista ) {
    if( lista->actual >= lista->entradas ){ return NULL; }
    return( lista->data[ lista->actual++ ] );
}

static inline void*   list_anterior( _list* lista ){
    if( lista->actual == 0 ) return NULL;
    return lista->data[ lista->actual-- ];
}

static inline void*   list_top( _list* lista ){
    if( !lista->entradas ) return NULL;
    return lista->data[lista->entradas-1];
}

#define   list_push    list_agrega


#endif
