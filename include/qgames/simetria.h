/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  SIMETRIA_H
#define  SIMETRIA_H  1

typedef   struct   StrSimetria {
    int   color;
    struct StrDireccion* dir1;
    struct StrDireccion* dir2;
} Simetria;

Simetria* simetria_new( int  color, struct StrDireccion* dir1, struct StrDireccion* dir2 );
void     simetria_free( Simetria* s );



#endif
