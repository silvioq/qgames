/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  CASILLERO_H
#define  CASILLERO_H  1

typedef   struct   StrCasillero {
    char*       nombre;
    int         posicion[MAXDIMS];
    _list*      vinculos;
    int          dataptr;               // Puntero a la data de la maquina virtual
}  Casillero;

Casillero* casillero_new( char* cas );

#include  "direccion.h"
#include  "vinculo.h"

void       casillero_free( Casillero* cas );
void       casillero_add_vinculo( Casillero* ori, Direccion* dir, Casillero* des );
void       casillero_kill_vinculo( Casillero* ori,Direccion* dir, Casillero* des );
Vinculo*   casillero_busca_vinculo_origen( Casillero* ori, Direccion* dir );
Vinculo*   casillero_busca_vinculo_destino( Casillero* des, Direccion* dir );
int        casillero_posicion_establecida( Casillero* cas );


Casillero* casillero_aplica_direccion( Casillero* cas, Direccion* dir );



#endif
