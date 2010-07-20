/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  MOVIDA_H
#define  MOVIDA_H  1

typedef  struct  StrMovida {
    _list*      acciones;
    Posicion*   pos;
    char*       notacion;
    int         tmov;
    int         piece_number;
    char        continua;
    Casillero*  destino;      // Solo como auxiliar, no usar directamente, para eso esta movida_destino
} Movida;

typedef struct StrAccion{
    char        tipo;
    int         pieza_number;
    Casillero*  destino;
    int         color;
    Tipopieza*  tpieza;
    int         att_key;
    int         att_val;
}  Accion;



/* Acciones de una movida */
#define   ACCION_MUEVE           1
#define   ACCION_CAPTURA         2
#define   ACCION_CREA            3
#define   ACCION_TRANSFORMA      4
#define   ACCION_DESTRUYE        5
#define   ACCION_ASIGNA_ATT      6
#define   ACCION_INFORMACION     7
#define   ACCION_PASAR          10


Movida*   movida_new( Posicion* pos, Pieza* pieza, int tmov );
Movida*   movida_dup( Movida* mov );

void  movida_accion_mueve  ( Movida* mov, Pieza* p, Casillero* destino );
void  movida_accion_captura( Movida* mov, Pieza* p );
void  movida_accion_transforma( Movida* mov, Pieza* p, int color, Tipopieza* tpieza );
void  movida_accion_asigna_att( Movida* mov, Pieza* p, int att, int val );
void  movida_free( Movida* mov );

void  movida_split_transformaciones( _list* movs );

Posicion*    movida_ejecuta( Movida* mov );



Casillero*   movida_casillero_origen( Movida* mov );
Casillero*   movida_casillero_destino( Movida* mov );
Pieza*       movida_pieza( Movida* mov );
int          movida_es_captura( Movida* mov );
int          movida_es_transformacion( Movida* mov, int* color, Tipopieza** tp );

int          movida_dump( Movida* mov, void** data, int* size );
Movida*      movida_load( Posicion* pos, void* data, int size );

#endif
