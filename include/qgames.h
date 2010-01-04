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


typedef   struct  Tipojuego  Tipojuego;


Tipojuego*  tipojuego_new( char* nombre );
int         tipojuego_add_tablero  ( Tipojuego* tj );
int         tipojuego_genera_dimensiones( Tipojuego* tj, int tablero, int dimc, char** dimv );
int         tipojuego_add_casillero( Tipojuego* tj, char* casillero );
int         tipojuego_add_direccion( Tipojuego* tj, char* direccion );
void        tipojuego_add_direccion_rel( Tipojuego* tj, char* direccion, ... );
void        tipojuego_add_direccion_arr( Tipojuego* tj, char* direccion, int* dirv );
int         tipojuego_add_link     ( Tipojuego* tj, char* cas_ori, char* dir, char* cas_des );
int         tipojuego_add_color    ( Tipojuego* tj, char* color );
int         tipojuego_add_tipo_mov ( Tipojuego* tj, char* tipo_mov );
int         tipojuego_add_tipopieza( Tipojuego* tj, char* tpieza    );
int         tipojuego_add_zona     ( Tipojuego* tj, char* zona      );
void        tipojuego_add_cas_to_zona( Tipojuego* tj, char* cas, char* color, char* zona );
void        tipojuego_add_simetria ( Tipojuego* tj, char* color, char* dir1, char* dir2 );

void        tipojuego_kill_casillero( Tipojuego* tj, char* casillero );


#define   NOT_FOUND   -1

int         tipojuego_get_casillero( Tipojuego* tj, char* cas );
int         tipojuego_get_direccion( Tipojuego* tj, char* dir );
int         tipojuego_get_tipopieza( Tipojuego* tj, char* tpieza );
int         tipojuego_get_zona     ( Tipojuego* tj, char* zona );
int         tipojuego_get_color    ( Tipojuego* tj, char* color );
int         tipojuego_get_tipomov  ( Tipojuego* tj, char* tipomov );

#define   CASILLERO_POZO   ((Casillero*)PIEZA_ENPOZO)
#endif