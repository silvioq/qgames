/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/


#ifndef  ANALIZADOR_H
#define  ANALIZADOR_H   1



typedef  struct  StrAnalizador {
    Posicion*  pos;
    Pieza*     pieza;
    Casillero* cas;
    int        tipo_analisis;
    int        tipo_movida;
    int        color;
    _list*     movidas;
}  Analizador;


#define   ENEMIGO       -1
#define   PROPIO        -2
#define   CUALQUIERA    0

int    analizador_juega  ( Analizador* z, Casillero* cas, int con_captura );

/*
 * Devuelve uno o cero, si se encuentra ocupado el casillero pasado como parametro
 * Detalle:
 *  cas  : Casillero. Si es nulo, toma el casillero actual
 *  owner: Dueño. Puede ser ENEMIGO, PROPIO, CUALQUIERA o un color
 *
 *  */
int    analizador_ocupado( Analizador* z, Casillero* cas, int owner );


#endif
