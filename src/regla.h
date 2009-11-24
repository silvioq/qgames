/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  REGLA_H
#define  REGLA_H  1

#include  "qcode.h"

#define   REGLA_MOVER    1
#define   REGLA_DEJAR    2

#define   REGLA_TODOS_TIP -1

typedef   struct   StrReglas {
    int        tipo;
    int        tipo_movimiento;
    int        function;
    _list*     parms;
   
}  Regla;

Regla*   regla_new( int tipo, int tipo_movimiento );
void    regla_free( Regla* r );

#include  "casillero.h"
#include  "direccion.h"
void     regla_add_parameter_casillero( Regla* r, Casillero* cas );
void     regla_add_parameter_direccion( Regla* r, Direccion* dir );
void     regla_add_parameter_color    ( Regla* r, int color );
void     regla_call_to_function       ( Regla* r, char* function );



#endif
