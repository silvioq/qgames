/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  TIPOPIEZA_H
#define  TIPOPIEZA_H  1

typedef   struct   StrTipopieza {
    char*      nombre;
    _list*     reglas;
    st_table*  atributos;
    struct     StrTipojuego*  tipo_juego;
} Tipopieza;





Tipopieza* tipopieza_new( struct  StrTipojuego*  tj, char* tipopieza );
Regla*     tipopieza_add_regla   ( Tipopieza* tp, int tipo, char* tipo_movimiento );
void     tipopieza_add_atributo( Tipopieza* tp, char* att, int default_value );
int      tipopieza_es_atributo ( Tipopieza* tp, char* att );

void     tipopieza_free( Tipopieza* tipo );


#endif
