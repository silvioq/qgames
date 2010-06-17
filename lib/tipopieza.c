/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#include  <stdlib.h>
#include  <string.h>
#include  <stdio.h>

#include  "log.h"
#include  "qgames.h"
#include  "tipojuego.h"


/*
 * Crea un nuevo tipo de pieza. Nada más ni nada menos.
 * */
Tipopieza*  tipopieza_new( Tipojuego* tj, char* nombre, int number ){

    Tipopieza* t = malloc( sizeof( Tipopieza ) );
    memset( t, 0, sizeof( Tipopieza ) );
    t->nombre = strdup( nombre );
    t->tipojuego = tj;
    t->number = number;
    return t;

}

int         tipopieza_add_att(Tipopieza* tp, char* att, int default_value ){
    if( tipopieza_get_att( tp, att ) != NOT_FOUND ){
        return 0;
    }
    if( !tp->att_nombres ){
        tp->att_nombres = list_nueva( NULL );
        tp->att_default = list_nueva( NULL );
    }
    list_agrega( tp->att_nombres, strdup(att) );
    list_agrega( tp->att_default, (void*)(long)default_value );
    return 1;
}

int        tipopieza_get_att( Tipopieza* tp, char* att ){
    if( !tp->att_nombres ) return NOT_FOUND;
    list_inicio( tp->att_nombres );
    int  i;
    for( i = 0; i < tp->att_nombres->entradas; i ++ ){
        char* nom = tp->att_nombres->data[i];
        if( strcmp( nom, att ) == 0 ) return  i;
    }
    return NOT_FOUND;
}

