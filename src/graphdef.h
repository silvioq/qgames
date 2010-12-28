/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2010.
*/

#ifndef  GRAPHDEF_H
#ifdef  HAVE_GD_H
#include  "gd.h"   
#endif

#define   TIPOGRAPH_TABLERO    1
#define   TIPOGRAPH_TPIEZA     2
#define   TIPOGRAPH_CASILLERO  3
#define   TIPOGRAPH_LOGO       4

typedef struct  StrGraphdef {
    char    tipo;
    union{
        int     tablero;
        Tipopieza* tpieza;
        Casillero* cas;
    };
    char    std;    // Flag de imagen estandar
    int     w;      // Width ancho
    int     h;      // Height alto
    int     f;      // Color frente (Forecolor)
    int     b;      // Color fondo  (Backcolor)
    int     ox;     // Offset x
    int     oy;     // Offset y
    int     color;  // Color de la pieza
    char*   cus;    // Nombre del archivo "custom"
#if HAVE_GD_H
    gdImagePtr  gd;
    gdImagePtr  gd_r;   // Rotado
    gdImagePtr  gd_c;   // Capturada
#endif
} _Graphdef;


#endif
