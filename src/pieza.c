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

void     pieza_init( Pieza* pieza, Tipopieza* tpieza, Casillero* cas, int color ){
    pieza->tpieza    = tpieza;
    pieza->casillero = cas;
    pieza->color     = color;
    pieza->flags     = 0;
}


/*
 * Devuelvo o calcula el hash de la pieza, lo que me sirve para
 * ver si es igual o distinta a las demas 
 * */
char*   pieza_hash( Pieza* p ){
    if( p->flags & PIEZA_HASH_CALCULADO ) return p->hash;
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

    if( p->flags & PIEZA_ATT_INIT ){
        md5_append( &md5, (void*)p->atts, sizeof( int ) * p->tpieza->att_count );
    }
    md5_finish( &md5, p->hash );
    p->flags |= PIEZA_HASH_CALCULADO;
    return  p->hash;
}


int     pieza_equal( Pieza* p1, Pieza* p2 ){
    return( strncmp( pieza_hash( p1 ), pieza_hash( p2 ), 16 ) == 0 );
}

/*
 * El duplicado de la pieza hace una pieza exactamente igual ... pero nueva!
 * */
/*
void   pieza_copy( Pieza* pieza_dest, Pieza* pieza_ori ){
    pieza_dest->tpieza    = pieza_ori->tpieza;
    pieza_dest->casillero = pieza_ori->casillero;
    pieza_dest->color     = pieza_ori->color;
    pieza_dest->number    = pieza_ori->number;
    pieza_dest->flags     = pieza_ori->flags;
    if( pieza_dest->flags & PIEZA_HASH_CALCULADO ) 
        memcpy( pieza_dest->hash,  pieza_ori->hash, 16 );
    if( pieza_dest->flags & PIEZA_ATT_INIT ) 
        memcpy( pieza_dest->atts, pieza_ori->atts, TIPOPIEZA_MAXATT ) ;
}*/

/*
    int x = tipopieza_get_att( p->tpieza, att );
    if( x == NOT_FOUND ){
        LOGPRINT( 1, "atributo %s incorrecto para %s", att, p->tpieza->nombre );
        exit( EXIT_FAILURE );
    }
*/
int      pieza_set_att( Pieza* p, int att, int val ){

    if( !(p->flags & PIEZA_ATT_INIT) ){
        int i ;
        for( i = 0; i < p->tpieza->att_default->entradas ; i ++ ){
            p->atts[i] = (int)(long)p->tpieza->att_default->data[i];
        }
    }
    if( att >= p->tpieza->att_count ){
        LOGPRINT( 1, "Error atributo incorrecto att: %d att_count %d", att, p->tpieza->att_count );
        return 0;
    };
    p->atts[att] = val;
    return 1;
}



int      pieza_get_att( Pieza* p, int att ){
    if( !(p->flags & PIEZA_ATT_INIT) ) return 0;
    if( att >= p->tpieza->att_count ) return 0;
    return p->atts[att];
}
