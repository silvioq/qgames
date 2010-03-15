/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  POSICION_H
#define  POSICION_H  1

typedef  struct  StrPosicion {
    Tipojuego*  tjuego;
    _list*      piezas;
    _list*      movidas;
    Posicion*   pos_anterior;
} _Posicion;


Posicion*   posicion_new( Tipojuego* tpieza );
void        posicion_add_pieza( Posicion* pos, Pieza* pie );
Posicion*   posicion_dup( Posicion* pos );



#endif
