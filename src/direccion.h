/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  DIRECCIONES_H
#define  DIRECCIONES_H  1

typedef   struct   StrDireccion {
    char*        nombre;
    int          mov_relativo[MAXDIMS];
    int          dataptr;               // Puntero a la data de la maquina virtual
}  Direccion;

Direccion* direccion_new( char* cas );



#endif
