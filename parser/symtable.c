/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#include  <string.h>
#include  <defines.h>
#include  "symtable.h"
#include  "list.h"

/*
 * Para la implementacion de tablas de simbolos y 
 * definiciones, uso el list, que es lo más sencillo
 * que se me ha ocurrido en los ultimos años
 * */

typedef  struct  StrSymDef {
    char*   nombre;
    int     argc;
    char**  argv;
    char*   def;
} symdef;

#define  L(sym)   ((_list*)sym)

symdef*   symtable_search( symtable* sym, char* name ){
    list_inicio( L(sym) );
    symdef* ret;
    while( ret = (symdef*)list_siguiente( L(sym ) ) ){
        if( strcmp( name, ret->nombre ) == 0 ) return ret;
    }
    return NULL;
}

void   symtable_freedef( symdef* def ){
    if( def->argc ){
        int  i;
        for( i = 0; i < def->argc; i ++ ){
            free( def->argv[i] );
        }
    }
    if( def->argv ) free( def->argv );
    if( def->def  ) free( def->def );
    free( def->nombre );
    free( def );
}



symtable*  symtable_init( ){
    return  (symtable*) list_nueva((_list_freefunc) symtable_freedef );
}


void       symtable_free( symtable* sym ){
    list_free( L(sym) );
}

int        symtable_addsym( symtable* sym, char* name ){
    /* Verifico la existencia de la entrada */
    if( symtable_search( sym, name ) ) return 0;
    symdef* sd = ALLOC( sizeof( symdef ) );
    memset( sd, 0, sizeof( symdef ) );
    sd->nombre = strdup( name );
    list_agrega( L(sym), sd );
    return 1;
}


int        symtable_adddef( symtable* sym, char* name, int argc, char** argv, char* def ){
    if( symtable_search( sym, name ) ) return 0;
    symdef* sd = ALLOC( sizeof( symdef ) );
    memset( sd, 0, sizeof( symdef ) );
    sd->nombre = strdup( name );
    sd->argv   = ALLOC( sizeof( char* ) * argc );
    sd->argc   = argc;
    int  i;
    for( i = 0; i < argc; i ++ ){
        sd->argv[i] = strdup( argv[i] );
    }
    sd->def    = strdup( def );
    list_agrega( L(sym), sd );
    return 1;
}


int        symtable_resolve( symtable* sym, char* name, int argc, char** argv, char** result ){

    symdef* def = symtable_search( sym, name );
    if( !def ) return 0;
    int  len = strlen( def->def );
    int  aloc = len;
    int  i;
    char* ret = ALLOC( aloc );

    strcpy( ret, def->def );

    for( i = 0; i < argc && i < def->argc; i ++ ){
        // Por cada elemento pasado como parametro, hay que reemplazar.
        // OPTIMIZE: Tabla de reemplazos seria algo que lo haría más rapido
        char * str, *strpoint;
        int  len_from = strlen( def->argv[i] );
        int  len_to   = strlen( argv[i] );
        strpoint = ret;
        while( str = strstr( strpoint, def->argv[i] ) ){
            // En str tengo el puntero de lo que quiero reemplazar
            // En len_from, tengo la longitud de lo que quiero reemplazar
            // En len_to    tengo la longitud del nuevo string;
            // Si len - len_from + len_to > alloc, realoco y comienzo nuevamente
            if( len - len_from + len_to > aloc ){
                aloc += - len_from + len_to + 10 ;
                ret = REALLOC( ret, aloc );
                strpoint = ret;
                continue;
            } else {
                if( len_from != len_to ){
                    // Estoy moviendo todo lo que hay despues de la definicion
                    // hasta el final del string. Le agrego un caracter mas
                    // para mover el cero.
                    int total = strlen( str + len_from ) + 1;
                    // printf( "str: %s len_from %d len_to %d long: %d\n", str, len_from, len_to, total );
                    memmove( str + len_to, str + len_from, total );
                    // printf( "str: %s len_from %d len_to %d\n", str, len_from, len_to );
                }
                strncpy( str, argv[i], len_to );
                strpoint = str + len_to;
            }
        }
    }
    *result = ret;
    return 1;
}
