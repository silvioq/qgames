/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  TABLERO_H
#define  TABLERO_H  1

typedef   struct   StrTablero {
    struct StrTipojuego*   tipo_juego;
    _list*       casilleros;
    _list*       direcciones;
    _list*       zonas;
    _list*       simetrias;

    // Cantidad de dimensiones que tiene el tablero
    int          dimc;          
    _list*       dimensiones;
}  Tablero;

Tablero*   tablero_new( struct StrTipojuego* tj );
void       tablero_genera_dimensiones( Tablero* tab, int dimc, char** dimv );



#endif
