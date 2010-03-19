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
    int        tipo_movida;
    int        color;
    _list*     movidas;
    char       tipo_analisis;
    char       status;
}  Analizador;


_list*   analizador_evalua_movidas( Regla* regla, Posicion* pos, Pieza* pieza, Casillero* cas, char tipoanalisis, int tipomovida, int color );
_list*   analizador_evalua_final  ( Regla* regla, Posicion* pos, int color );


#define   STATUS_NORMAL       0
#define   STATUS_OUTOFBOARD   1
#define   STATUS_STOP         2



int    analizador_juega  ( Analizador* z, Casillero* cas, int con_captura );

/*
 * Devuelve uno o cero, si se encuentra ocupado el casillero pasado como parametro
 * Detalle:
 *  cas  : Casillero. Si es nulo, toma el casillero actual
 *  owner: Dueño. Puede ser ENEMIGO, PROPIO, CUALQUIERA o un color
 *
 *  */
int    analizador_ocupado( Analizador* z, Casillero* cas, int owner );


/*
 * Cambia el puntero al lugar indicado
 */ 
int    analizador_casillero( Analizador* z, Casillero* cas );
int    analizador_direccion( Analizador* z, Direccion* dir );


#endif
