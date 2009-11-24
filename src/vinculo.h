/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  VINCULO_H
#define  VINCULO_H  1

typedef   struct   StrVinculo {
    struct StrCasillero* origen;
    struct StrDireccion* direccion;
    struct StrCasillero* destino;
} Vinculo;

Vinculo* vinculo_new( struct StrCasillero* ori, struct StrDireccion* dir, struct StrCasillero* des );

void     vinculo_free( Vinculo* v );



#endif
