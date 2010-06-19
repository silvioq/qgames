/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  PIEZA_H
#define  PIEZA_H  1

typedef  struct  StrPieza {
    Tipopieza*  tpieza;
    Casillero*  casillero;
    int         color;
    _list*      atributos;
    int         number;
    int         hash_calculado;
    char        hash[16];
} Pieza;


void     pieza_init( Pieza* pieza, Tipopieza* tpieza, Casillero* cas, int color );
void     pieza_copy( Pieza* pieza_dest, Pieza* pieza_ori );
int      pieza_equal( Pieza* p1, Pieza* p2 );
char*    pieza_hash( Pieza* p1 );
int      pieza_set_att( Pieza* p, int att, int val );
int      pieza_get_att( Pieza* p, int att );
int      pieza_free_att( Pieza* p );


#endif
