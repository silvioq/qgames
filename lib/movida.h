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
} Movida;

typedef struct StrAccion{
  int         tipo;
  Pieza*      pieza;
  Casillero*  destino;
  int         color;
  Tipopieza*  tipo_pieza;
  char*       att_key;
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
#define   ACCION_NOTACION        8
#define   ACCION_CONT_MOVIENDO   9
#define   ACCION_PASAR          10


Movida*   movida_new( Posicion* pos );

void  movida_accion_mueve  ( Movida* mov, Pieza* p, Casillero* destino );
void  movida_accion_captura( Movida* mov, Pieza* p );

#endif
