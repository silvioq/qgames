/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  PIEZA_H
#define  PIEZA_H  1


#define  PIEZA_ENPOZO     1
#define  PIEZA_CAPTURADA  2
#define  PIEZA_DESTRUIDA  3


typedef   struct   StrPieza {
    // Lo primero que tengo que saber, es quien soy ...
    struct StrTipopieza* tipopieza;

    // El puntero al casillero donde se ubica la pieza
    struct StrCasillero* casillero;

    // El numero de color (apunta a la lista del tipojuego)
    int                  color;

    // Los atributos de la pieza
    st_table*            atributos;

    // El identificador de pieza, unico dentro de la posicion
    // y que se mantiene a traves de sus copias
    int                  id;

       
} Pieza;

Pieza*   pieza_new( struct StrTipopieza* tp, struct StrCasillero* ori, int color );

void     pieza_setatributo( Pieza* p, char* att, int val );

void     pieza_free( Pieza* p );



#endif
