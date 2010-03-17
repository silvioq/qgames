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
 * Estas tres variables me permitiran trabajar con un stack de etiquetas
 * y generar los bloques
 * */

long*   label_stack_data  = NULL;
int     label_stack_size  = 0;
int     label_stack_point = 0;

void     push_label_stack( long label ){
    if( !label_stack_data ){
        label_stack_data =  (long*)ALLOC( sizeof( long ) * 10 );
        label_stack_size = 10;
    }
    if( label_stack_point <= label_stack_size ){
        label_stack_size += 10;
        label_stack_data = (long*) REALLOC( label_stack_data, sizeof( long ) * label_stack_size );
    }
    label_stack_data[label_stack_point] = label;
    label_stack_point ++;
}

long    pop_label_stack( ){
    assert( label_stack_point > 0 );
    long label = label_stack_data[label_stack_point];
    label_stack_point --;
    return  label;
}

/*
 * Esta funcion abre un block condicional
 * */
void        tipojuego_code_start_condblock( Tipojuego* tj ){
    long  label = qcode_crlab( tj->qcode, unnamed_label );
    push_label_stack( label );
    qcode_oplab( tj->qcode, QCJPZ, label );
}

void        tipojuego_code_end_condblock( Tipojuego* tj ){
    long  label = pop_label_stack( );
    qcode_label( tj->qcode, label );
}

void        tipojuego_code_ocupado( Tipojuego* tj, char* casillero, int owner, char* color ){
    int  own = CUALQUIERA;
    long cas;

    if( owner == CUALQUIERA && color ){
        own = GETCOLOR(tj, color );
    } else if( owner != CUALQUIERA ){
        own = owner;
    }

    if( casillero ){
        cas = GETCASILLERO(tj, casillero );
    } else {
        cas = NULL;
    }
    qcode_op( tj->qcode, QCSTI, 16, own );      // t16 = own
    qcode_op( tj->qcode, QCPOP, 16, 0 );        // POP t16
    qcode_op( tj->qcode, QCPOP, 16, cas );      // t16 = cas     
    qcode_op( tj->qcode, QCPOP, 16, 0 );        // POP t16
    qcode_op( tj->qcode, QCPOP,  3, 0 );        // POP r3
    qcode_opnlab( tj->qcode, QCCLX, "ocupado" );
}

void        tipojuego_code_juega  ( Tipojuego* tj, char* casillero, int captura ){
    long cas;
    if( casillero ){
        cas = GETCASILLERO(tj, casillero );
    } else {
        cas = NULL;
    }

    qcode_op( tj->qcode, QCSTI, 16, captura );  // t16 = captura
    qcode_op( tj->qcode, QCPOP, 16, 0 );        // POP t16
    qcode_op( tj->qcode, QCSTI, 16, cas );      // t16 = cas     
    qcode_op( tj->qcode, QCPOP, 16, 0 );        // POP t16
    qcode_op( tj->qcode, QCPOP,  3, 0 );        // POP r3
    qcode_opnlab( tj->qcode, QCCLX, "juega" );
}

