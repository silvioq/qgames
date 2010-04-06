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
    int        color_siguiente;
    _list*     movidas;
    char       tipo_analisis;
    char       status;

    char*      resultado;         // Para el analisis del final, este elemento contiene la descripcion del resultado
    int        color_ganador;     // Color que gano! 0 es tablas!
}  Analizador;


_list*   analizador_evalua_movidas( Regla* regla, Posicion* pos, Pieza* pieza, Casillero* cas, char tipoanalisis, int tipomovida, int color );

/* Los valores posibles que retorna, son los especificados en qgames.h ...
 * #define   FINAL_EMPATE   0
 * #define   FINAL_ENJUEGO  -1
 * */
int      analizador_evalua_final  ( Regla* regla, Posicion* pos, Pieza* pieza, Casillero* cas, int color, int color_siguiente, char** resultado );


#define   STATUS_NORMAL       0
#define   STATUS_OUTOFBOARD   1
#define   STATUS_STOP         2
#define   STATUS_EOG          4



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
 * Cambia el puntero al lugar indicado (casillero o direccion)
 */ 
int    analizador_casillero( Analizador* z, Casillero* cas );
int    analizador_direccion( Analizador* z, Direccion* dir );

int    analizador_ahogado( Analizador* z );
int    analizador_entablero( Analizador* z );


int   analizador_final( Analizador* z, int color, int res );
#endif
