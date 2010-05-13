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

typedef struct  StrGraphdef {
    char    tipo;
    union{
        int     tablero;
        Tipopieza* tpieza;
        Casillero* cas;
    };
    char    std;
    int     w;
    int     h;
    int     f;
    int     b;
    int     color;
    char*   cus;
#ifdef  HAVE_GD_H
    gdImagePtr  gd;
#endif
} _Graphdef;


#endif
