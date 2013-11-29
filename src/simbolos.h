/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  SIMBOLOS_H
#define  SIMBOLOS_H   1

typedef   struct  StrSimbolo{
    int     tipo;
    int     id;
    char*   nombre;
    int     ref;
}  _Simbolo;


#define   SIM_TIPOJUEGO  1
#define   SIM_CASILLERO  2
#define   SIM_TIPOPIEZA  3
#define   SIM_ZONA       4
#define   SIM_DIRECCION  5
#define   SIM_TIPOMOV    6
#define   SIM_TIPOMOVP   7
#define   SIM_COLOR      8

extern   int simbolo_id;

static inline Simbolo* simbolo_new( int tipo, char* nombre, int ref ){
    Simbolo* s = (Simbolo*) malloc( sizeof( Simbolo ) );
    s->tipo = tipo; 
    s->nombre = nombre;
    s->id   = ++simbolo_id;
    s->ref  = ref;
    return  s;
}


#endif

