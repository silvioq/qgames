
/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2010.
*/

#include <stdlib.h>
#include <assert.h>
#include "symtable.h"

char* def1 = "direccion_1; direccion_2";
char* params1[2] = { "direccion_1", "direccion_2" };

char* def2 = "while( direccion ) do algo";
char* params2[1] = { "direccion" };

int  main(int argc, char**argv){

    symtable* sym = symtable_init( );
    symtable_adddef( sym, "def1", 2, params1, def1 );
    symtable_adddef( sym, "def2", 1, params2, def2 );

    char* ret;
    char* pp1[2] = { "no", "ne" };

    assert( !symtable_resolve( sym, "xsxx", 0, NULL, NULL ) );
    assert( symtable_resolve( sym, "def1", 0, NULL, &ret ) );
    assert( strcmp( ret, "; " ) == 0 );
    free( ret );

    assert( symtable_argc( sym, "def1" ) == 2 );
    assert( symtable_resolve( sym, "def1", 1, pp1, &ret ) );
    // printf( "1. %s\n", ret );
    assert( strcmp( ret, "no; " ) == 0 );
    free( ret );

    assert( symtable_resolve( sym, "def1", 2, pp1, &ret ) );
    assert( strcmp( ret, "no; ne" ) == 0 );

    assert( symtable_argc( sym, "def2" ) == 1 );
    assert( symtable_resolve( sym, "def2", 0, pp1, &ret ) );
    assert( strcmp( ret, "while(  ) do algo" ) == 0 );
    free( ret );

    assert( symtable_resolve( sym, "def2", 1, pp1, &ret ) );
    assert( strcmp( ret, "while( no ) do algo" ) == 0 );
    free( ret );
    symtable_free( sym );

    return EXIT_SUCCESS;

}



