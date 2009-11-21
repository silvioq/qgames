#include   <stdio.h>
#include   <string.h>
#include  <stdlib.h>
#include   <assert.h>
#include   "list.h"

void  free_char(void* d){
    free( d );
}


int  main(int argc, char** argv){
    _list* l;
    int x, act;
    char* v;
  
    printf( "." ); 
    assert( l = list_nueva(free_char) );
    for( x = 0; x < 100; x ++ ){ 
        char*  linea;
        linea = (char*) malloc( 24 );
        sprintf( linea, "Nueva %d", x );
        list_agrega( l, (void*) linea ); 
    }

    printf( "." ); 
    assert( l->entradas == 100 );

    printf( "." ); 
    assert( strcmp( l->data[0], "Nueva 0" ) == 0 );
    assert( strcmp( l->data[1], "Nueva 1" ) == 0 );

    list_quita( l, 22 );
    printf( "." ); 
    assert( l->entradas == 99 );

    printf( "." ); 
    assert( strcmp( l->data[0], "Nueva 0" ) == 0 );
    assert( strcmp( l->data[1], "Nueva 1" ) == 0 );
    assert( strcmp( l->data[23], "Nueva 24" ) == 0 );
    assert( strcmp( l->data[97], "Nueva 98" ) == 0 );
    assert( strcmp( l->data[98], "Nueva 99" ) == 0 );

    // Compruebo el armado ...
    list_inicio( l );
    x = 0; act = 0;
    assert( l->actual == act );
    while( ( v = list_siguiente( l ) ) ){
        if( x == 22 ) x ++;
        assert( l->actual ==( ++act ) );
        char lll[24];
        printf( "." ); 
        sprintf( lll, "Nueva %d", x );
        // printf( "(%d) %s == %s\n", l->actual, lll, v );
        assert( strcmp( v, lll ) == 0 );
        x ++;
    }

    // Ahora al reves ...
    list_final( l );
    x = 99;
    while( ( v = list_anterior( l ) ) ){
        if( x == 22 ) x --;
        char lll[24];
        printf( "." ); 
        sprintf( lll, "Nueva %d", x );
        assert( strcmp( v, lll ) == 0 );
        x --;
    }

    // Pop
    v = list_pop( l );
    printf( "." ); 
    assert( strcmp( v, "Nueva 99" ) == 0 );
    assert( l->entradas == 98 );

    printf( "\n" );
    list_free( l );
    return 0;

}
