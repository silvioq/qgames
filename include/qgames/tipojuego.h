/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  TIPOJUEGO_H
#define  TIPOJUEGO_H  1

typedef   struct   StrTipojuego {
    st_table*    simbolos;
    struct StrTablero*     tablero;
    _list*       tipos_movimiento;
    _list*       notacion;
    _list*       secuencias;
    int          secuencia_repeat;
    _list*       colores;
    _list*       piezas;
    char*        nombre;
    st_table*    descripciones;
    struct StrPosicion*    inicial;

    // Todo lo que continua tiene que ver con el codigo y su
    // generación.
    QCode*       code;
    int          lblgen;
    int          lblpos;
    int          lblfin;
}  Tipojuego;


Tipojuego*  tipojuego_new( char* nombre );

void        tipojuego_add_casillero( Tipojuego* tj, char* casillero );
void        tipojuego_add_direccion( Tipojuego* tj, char* direccion );
void        tipojuego_add_direccion_rel( Tipojuego* tj, char* direccion, ... );
void        tipojuego_add_direccion_arr( Tipojuego* tj, char* direccion, int* dirv );
void        tipojuego_add_link     ( Tipojuego* tj, char* cas_ori, char* dir, char* cas_des );
void        tipojuego_add_color    ( Tipojuego* tj, char* color );
void        tipojuego_add_tipo_mov ( Tipojuego* tj, char* tipo_mov );
void        tipojuego_add_tipopieza( Tipojuego* tj, char* tpieza    );
void        tipojuego_add_zona     ( Tipojuego* tj, char* zona      );
void        tipojuego_add_cas_to_zona( Tipojuego* tj, char* cas, char* color, char* zona );
void        tipojuego_add_simetria ( Tipojuego* tj, char* color, char* dir1, char* dir2 );

Regla*      tipojuego_add_regla      ( Tipojuego* tj, char* tpieza, int tregla, char* tmov );

void        tipojuego_kill_casillero( Tipojuego* tj, char* casillero );

void        tipojuego_create_piece( Tipojuego* tj, char* tpieza, char* cas, char* color, int cantidad );
void        tipojuego_create_piece_enpozo( Tipojuego* tj, char* tpieza, char* color, int cantidad );


Simbolo*    tipojuego_get_simbolo( Tipojuego* tj, char* sim );


static inline int  tipojuego_get_tipo_simbolo(Tipojuego* tj, char* sim){ 
    Simbolo *s;
    s = tipojuego_get_simbolo( tj, sim );
    return ( s ? ( s->tipo ) : -1 ) ;
}

static inline int tipojuego_es_casillero(Tipojuego* tj, char* cas){
    int t = tipojuego_get_tipo_simbolo(tj,cas);
    return ( t == SIM_CASILLERO ) ;
}

/*
 * Distintas formas de obtener algun dato
 * */

#define   NOT_FOUND   -1
struct StrCasillero*    tipojuego_get_casillero( Tipojuego* tj, char* cas );
struct StrDireccion*    tipojuego_get_direccion( Tipojuego* tj, char* dir );
struct StrTipopieza*    tipojuego_get_tipopieza( Tipojuego* tj, char* tpieza );
struct StrZona*         tipojuego_get_zona     ( Tipojuego* tj, char* zona );
int           tipojuego_get_color    ( Tipojuego* tj, char* color );
int           tipojuego_get_tipomov  ( Tipojuego* tj, char* tipomov );

/* Esta es la definicion auxiliar de secuencia
 * El color tiene el puntero a color ...
 * El color_def tiene el entero dentro del array de colores,
 * el cual, inicialmente, se pone en -1
 * El tipomov tiene el puntero al tipo de movimiento, 
 * el cual puede estar en nulo.
 * El tipomov_def tiene el entero dentro del array de tipos
 * de movimiento, el cual, inicialmente, se pone en -1
 * */

typedef  struct   StrSecuencia {
    char*       color;
    int         color_def;
    char*       tipomov;
    int         tipomov_def;
}  Secuencia;

void        tipojuego_add_secuencia( Tipojuego* tj, char* color, char* tipomov );
void        tipojuego_add_secrepeat( Tipojuego* tj );
#endif
