/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  POSICION_H
#define  POSICION_H  1

// Los defines que vienen son para el flag de posicion
#define  POSICION_FLAG_CHECKMATED  1
#define  POSICION_FLAG_HASHED      2
#define  POSICION_ISCHECKMATED(p)  ( p->flags & POSICION_FLAG_CHECKMATED )
#define  POSICION_ISHASHED(p)      ( p->flags & POSICION_FLAG_HASHED )

typedef   struct   StrPosicion {

    // Este es el puntero al tipo de juego
    struct StrTipojuego*   tipo_juego;

    // Banderas varias para el juego
    int    flags;   

    // La lista de piezas
    _list*  piezas;

    // Esta lista contiene aquellas piezas a las que se les
    // puede dar jaquemate
    _list*  piezas_jaquemate;

    // Hash de la posicion, que le da un numero unico a 
    // la cosa
    int    hash;

    // Esta tabla indica, por cada color, si es que
    // hay movidas disponibles
    st_table*  hay_movidas;

    // Contador interno, para darle un numero unico
    // a cada pieza, dentro de la posicion
    int    contador;

    // Esta lista contiene todas las posiciones anteriores
    // de la posicion actual. Es especialmente util a la
    // hora de controlar repeticiones.
    _list*  anteriores;

}  Posicion;


// Ahora vienen las funciones

Posicion*  posicion_new( struct StrTipojuego* tj );
void       posicion_free( Posicion* );

void       posicion_add_pieza( Posicion* pos, struct StrPieza*  p );

void       posicion_analiza( Posicion* pos );




#endif
