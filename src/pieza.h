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
} Pieza;


Pieza*   pieza_new( Tipopieza* tpieza, Casillero* cas, int color );
int      pieza_equal( Pieza* p1, Pieza* p2 );


#endif
