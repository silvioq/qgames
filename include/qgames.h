/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#include  "list.h"
#include  "defines.h"

#ifndef   QGAMES_H
#define   QGAMES_H  1


// Esta es la cantidad máxima de dimensiones
// que puede soportar el motor
#define   MAXDIMS   16


typedef   struct  StrTipojuego  Tipojuego;
typedef   struct  StrPosicion   Posicion;
typedef   struct  StrPartida    Partida;


Tipojuego*  tipojuego_new( char* nombre );
int         tipojuego_add_tablero  ( Tipojuego* tj );
int         tipojuego_genera_dimensiones( Tipojuego* tj, int dimc, char** dimv );
int         tipojuego_add_casillero( Tipojuego* tj, char* casillero );
int         tipojuego_add_direccion( Tipojuego* tj, char* direccion );
void        tipojuego_add_direccion_rel( Tipojuego* tj, char* direccion, ... );
void        tipojuego_add_direccion_arr( Tipojuego* tj, char* direccion, int* dirv );
int         tipojuego_add_link     ( Tipojuego* tj, char* cas_ori, char* dir, char* cas_des );
int         tipojuego_add_color    ( Tipojuego* tj, char* color );
int         tipojuego_add_tipo_mov ( Tipojuego* tj, char* tipo_mov );
int         tipojuego_add_tipopieza( Tipojuego* tj, char* tpieza    );
int         tipojuego_add_tpieza_att( Tipojuego* tj, char* tpieza, char* att, int default_value );
int         tipojuego_add_zona     ( Tipojuego* tj, char* zona      );
void        tipojuego_add_cas_to_zona( Tipojuego* tj, char* cas, char* color, char* zona );
void        tipojuego_add_simetria ( Tipojuego* tj, char* color, char* dir1, char* dir2 );

void        tipojuego_kill_casillero( Tipojuego* tj, char* casillero );

#define     POZO     -1
#define     CAPTURA  -2
#define     CASILLERO_POZO  (char*)POZO
void        tipojuego_add_pieza( Tipojuego* tj, char* tpieza, char* casillero, char* color );


#define   NOT_FOUND   -1
int         tipojuego_get_casillero( Tipojuego* tj, char* cas );
int         tipojuego_get_direccion( Tipojuego* tj, char* dir );
int         tipojuego_get_tipopieza( Tipojuego* tj, char* tpieza );
int         tipojuego_get_zona     ( Tipojuego* tj, char* zona );
int         tipojuego_get_color    ( Tipojuego* tj, char* color );
int         tipojuego_get_tipomov  ( Tipojuego* tj, char* tipomov );

/*
 * Toda esta parte es para definir el codigo
 * */

#define   DROP  'D'
#define   MOVE  'M'
#define   END   'E'

int         tipojuego_start_code(  Tipojuego* tj, char tiporegla, char* tipopieza, char* tipomov );
#define     tipojuego_start_codeend(tj) tipojuego_start_code( tj, END, NULL, NULL )
void*       tipojuego_get_code( Tipojuego* tj );

#define   ENEMIGO       -1
#define   PROPIO        -2
#define   CUALQUIERA     0
void        tipojuego_code_start_condblock( Tipojuego* tj );
void        tipojuego_code_end_condblock( Tipojuego* tj );
void        tipojuego_code_direccion( Tipojuego* tj, char* direccion );
void        tipojuego_code_casillero( Tipojuego* tj, char* casillero );
void        tipojuego_code_ocupado( Tipojuego* tj, char* casillero, int owner, char* color );
void        tipojuego_code_ahogado( Tipojuego* tj, char* color );
void        tipojuego_code_juega  ( Tipojuego* tj, char* casillero, int captura );
void        tipojuego_code_para   ( Tipojuego* tj );

#define   GANA      1
#define   PIERDE    2
#define   EMPATA    3
void        tipojuego_code_final  ( Tipojuego* tj, char* color, int resultado );


/*
 * A partir de aca, comenzamos con la partida
 * */
Partida*    tipojuego_create_partida( Tipojuego* tj );




#endif
