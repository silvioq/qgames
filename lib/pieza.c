/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/


#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <stdarg.h>
#include  <qgames.h>

#include  "log.h"
#include  "list.h"
#include  "tipojuego.h"
#include  "pieza.h"

#include  <md5.h>

/*
 * Crea una pieza nueva
 * */

Pieza*   pieza_new( Tipopieza* tpieza, Casillero* cas, int color ){
    Pieza *p;
    p = (Pieza*)malloc( sizeof( Pieza ) );
    memset( p, 0, sizeof( Pieza ) );
    p->tpieza = tpieza;
    p->casillero = cas;
    p->color     = color;
    return p;
}

/*
 * Para borrar una pieza, hay que ser prolijos
 * */
void   pieza_free( Pieza* p ){
  if( p->atributos ){
      list_free( p->atributos );
  }
  free( p );
}

/*
 * Devuelvo o calcula el hash de la pieza, lo que me sirve para
 * ver si es igual o distinta a las demas 
 * */
char*   pieza_hash( Pieza* p ){
    if( p->hash_calculado ) return p->hash;
    md5_state_t md5;
    md5_init( &md5 );
    md5_append( &md5, p->tpieza->nombre, strlen( p->tpieza->nombre ) );
    if( p->casillero == ENPOZO ){
        md5_append( &md5, "CASILLERO-ENPOZO", 16 );
    } else if ( p->casillero == ENCAPTURA ){
        md5_append( &md5, "CASILLERO-ENCAPTURA", 19 );
    } else {
        md5_append( &md5, p->casillero->nombre, strlen( p->tpieza->nombre ) );
    }

    if( p->atributos ){
        int i;
        for( i = 0; i < p->atributos->entradas; i ++ ){
            md5_append( &md5, (void*)(& (p->atributos->data[i] )), sizeof( int ) );
        }
    }
    md5_finish( &md5, p->hash );
    return  p->hash;
}


int     pieza_equal( Pieza* p1, Pieza* p2 ){
    return( strncmp( pieza_hash( p1 ), pieza_hash( p2 ), 16 ) == 0 );
}

/*
 * El duplicado de la pieza hace una pieza exactamente igual ... pero nueva!
 * */

Pieza*   pieza_dup( Pieza* pieza ){
    Pieza *p;
    p = (Pieza*)malloc( sizeof( Pieza ) );
    memset( p, 0, sizeof( Pieza ) );
    p->tpieza    = pieza->tpieza;
    p->casillero = pieza->casillero;
    p->color     = pieza->color;
    p->number    = pieza->number;
    memcpy( p->hash,  pieza->hash, 16 );
    p->hash_calculado = p->hash_calculado;

    if( pieza->atributos ){
        p->atributos = list_nueva( NULL );
        int i;
        for( i = 0; i < pieza->atributos->entradas; i ++ ){
            list_agrega( p->atributos, pieza->atributos->data[i] );
        }
    }
    return p;
}

/*
    int x = tipopieza_get_att( p->tpieza, att );
    if( x == NOT_FOUND ){
        LOGPRINT( 1, "atributo %s incorrecto para %s", att, p->tpieza->nombre );
        exit( EXIT_FAILURE );
    }
*/
int      pieza_set_att( Pieza* p, int att, int val ){

    if( !p->atributos ){
        int i ;
        p->atributos = list_nueva( NULL );
        for( i = 0; i < p->tpieza->att_default->entradas ; i ++ ){
            list_agrega( p->atributos, p->tpieza->att_default->data[i] );
        }
    }
    if( att >= p->atributos->entradas ){
        LOGPRINT( 1, "Error atributo incorrecto", 0 );
        return 0;
    };
    p->atributos->data[att] = (void*)(long)val;
}



int      pieza_get_att( Pieza* p, int att ){
    if( !p->atributos ) return 0;
/*
    int x = tipopieza_get_att( p->tpieza, att );
    if( x == NOT_FOUND ) return 0;
    if( x >= p->atributos->entradas ) return 0; */
    if( att >= p->atributos->entradas ) return 0;
    return (int)(long)p->atributos->data[att];
}
