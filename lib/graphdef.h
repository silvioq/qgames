/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2010.
*/

#ifndef  GRAPHDEF_H

#define   TIPOGRAPH_TABLERO    1
#define   TIPOGRAPH_TPIEZA     2
#define   TIPOGRAPH_CASILLERO  3

typedef struct  StrGraphdef {
    int     tablero;
    char    tipo;
    char    std;
    int     w;
    int     h;
    int     f;
    int     b;
    char*   cus;
} Graphdef;


#endif
