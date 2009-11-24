/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  ZONA_H
#define  ZONA_H  1

typedef   struct   StrZona {
    char*   nombre;
    _list*  detalle;
} Zona;

typedef   struct  StrZonaDetalle{
    Casillero*  casillero;
    char*       color;
    int         color_def;
} Zonadet;


Zona*    zona_new( char* zona );
void     zona_agrega_casillero( Zona* z, Casillero* cas, char* color );

void     zona_free( Zona* z );



#endif
