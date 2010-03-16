/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/


#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <assert.h>
#include  <stdarg.h>
#include  <qgames.h>

#include  "list.h"
#include  "simbolos.h"
#include  "tipojuego.h"
#include  "pieza.h"
#include  "movida.h"
#include  "posicion.h"
#include  "analizador.h"

/*
 * En esta parte del codigo, se definiran los "wrappers" entre el codigo máquina generado
 * y el tema del analizador
 * Para la implementacion a traves de esta linda máquina virtual que es la QCode, utilizaremos
 * la R3, donde dejaremos el puntero al analizador, el cual sera pasado como parametro
 * cada vez 
 * */
long  code_wrapper_ocupado( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Casillero*  c = (Casillero*)qcode_pop( vm );
    int  owner    = (int)qcode_pop(vm);
    return (long)analizador_ocupado( z, c, owner );
}


long  code_wrapper_juega( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Casillero*  c = (Casillero*)qcode_pop( vm );
    int  captura  = (int)qcode_pop(vm);
    analizador_juega( z, c, captura );
    return 0;
}


void  code_initialize( QCode** qcode ){
    QCode*  q;
    q = qcode_new();
    qcode_xcrlab( q, "ocupado", (qcode_extfunc)code_wrapper_ocupado );
    qcode_xcrlab( q, "juega",   (qcode_extfunc)code_wrapper_juega );
    *qcode = q;
}

/* Sensacional! el más simple ejecutor de las reglas */
int    code_execute_rule( Posicion* pos, Rule* regla, Pieza* pie, Casillero* cas, int  tmov, int color, int tanalisis ){


}


