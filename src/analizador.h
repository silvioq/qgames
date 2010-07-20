/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/


#ifndef  ANALIZADOR_H
#define  ANALIZADOR_H   1


#define    CON_TRANSFORMACION  0x1

#define    ZPOSICION(z) (&(z->pos))

typedef  struct  StrAnalizador {
    Posicion   pos;
    Pieza*     pieza;
    Casillero* cas;
    Casillero* cas_ori;           // Casillero original
    int        tmov;
    int        color;
    int        color_siguiente;
    Movida*    mov_actual;
    _list*     movidas;
    char       tipo_analisis;
    char       status;
    char       flags;

    Casillero** marcas;

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
#define   STATUS_ERROR      128



int    analizador_juega  ( Analizador* z, Casillero* cas, int con_captura );
int    analizador_mueve  ( Analizador* z, char fromto_flags, void* from, void* to );
int    analizador_captura( Analizador* z, Casillero* cas );
int    analizador_transforma( Analizador*z, int owner, Tipopieza* tp);
int    analizador_asigna_att( Analizador* z, int att, int val );
int    analizador_evalua_att( Analizador* z, int att );

/*
 * Devuelve uno o cero, si se encuentra ocupado el casillero pasado como parametro
 * Detalle:
 *  cas  : Casillero. Si es nulo, toma el casillero actual
 *  owner: Dueño. Puede ser ENEMIGO, PROPIO, CUALQUIERA o un color
 *
 *  */
int    analizador_ocupado( Analizador* z, Casillero* cas, int owner, Tipopieza* tpieza );


/*
 * Cambia el puntero al lugar indicado (casillero o direccion)
 */ 
int    analizador_casillero( Analizador* z, Casillero* cas );
int    analizador_direccion( Analizador* z, Direccion* dir );

int    analizador_atacado( Analizador* z, Casillero* cas );
int    analizador_cuenta_piezas( Analizador* z, Casillero* cas, int owner, Tipopieza* tpieza );
int    analizador_destino_ant( Analizador* z, Casillero* cas );
int    analizador_origen_ant( Analizador* z, Casillero* cas );
int    analizador_ahogado( Analizador* z );
int    analizador_entablero( Analizador* z );
int    analizador_enzona( Analizador* z, int zona, int color, Tipopieza* tpieza );
int    analizador_setmarca( Analizador* z, int marca, Casillero* cas);
int    analizador_jaquemate( Analizador* z, Tipopieza* tpieza );


int   analizador_final( Analizador* z, int color, int res );
#endif
