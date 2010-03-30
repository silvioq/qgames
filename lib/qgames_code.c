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

#if 1
#define   RET_IF_STATUS  \
      {    \
          int  labcont = qcode_crlab( tj->qcode, unnamed_label );\
          qcode_oplab( tj->qcode, QCJPZ, labcont );\
          qcode_op( tj->qcode, QCRET, 0, 0 );\
          qcode_label( tj->qcode, labcont );\
      }
#else
#define  RET_IF_STATUS
#endif
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
    label_stack_point --;
    long label = label_stack_data[label_stack_point];
    return  label;
}


/*
 * Devuelve la regla actual, que en realidad, no es ni más ni
 * menos que la última de la lista
 * */
Regla*  code_regla_actual( Tipojuego* tj ){ 
    if( !tj->rules ) return NULL;
    if( tj->rules->entradas == 0 ) return NULL;
    return (Regla*)(tj->rules->data[tj->rules->entradas - 1]);
}

/*
 *
 * Operador NOT
 *
 * */
void        tipojuego_code_op_not( Tipojuego* tj ){
    assert( tj );
    qcode_op( tj->qcode, QCSTO, 1, 0 ); 
    qcode_op( tj->qcode, QCSTI, 2, 0 ); 
    // qcode_opnlab( tj->qcode, QCCLX, "dump" );
    qcode_op( tj->qcode, QCEQU, 1, 2 );    // EQU r1 , r2
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
        cas = -1;
    }
    qcode_op( tj->qcode, QCSTI, 16, own );      // t16 = own
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCSTI, 16, cas );      // t16 = cas     
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCPSH,  3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "ocupado" );
    // FIXME: Hay que controlar posibles estados erroneos
    // RET_IF_STATUS;                              // Retorna si el valor es distinto de cero
}

void        tipojuego_code_ahogado( Tipojuego* tj, char* color ){
    int  col;
    if( color ){
        col = GETCOLOR( tj, color );
    } else
       col = -1;
    qcode_op( tj->qcode, QCSTI, 16, col );      // t16 = col
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCPSH,  3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "ahogado" );
    // FIXME: Hay que controlar posibles estados erroneos
    // RET_IF_STATUS;                              // Retorna si el valor es distinto de cero
}

void        tipojuego_code_juega  ( Tipojuego* tj, char* casillero, int captura ){
    long cas;
    if( casillero ){
        cas = GETCASILLERO(tj, casillero );
    } else {
        cas = -1;
    }

    qcode_op( tj->qcode, QCSTI, 16, captura );  // t16 = captura
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCSTI, 16, cas );      // t16 = cas     
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCPSH,  3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "juega" );
    RET_IF_STATUS;                              // Retorna si el valor es distinto de cero
}

void        tipojuego_code_para  ( Tipojuego* tj ){
    qcode_op( tj->qcode, QCRET,  0, 0 );        // RET
}

void        tipojuego_code_casillero( Tipojuego* tj, char* casillero ){
    long cas;
    assert( casillero );
    cas = GETCASILLERO(tj, casillero );
    qcode_op( tj->qcode, QCSTI, 16, cas );      // t16 = cas     
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCPSH,  3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "casillero" );
    RET_IF_STATUS;                              // Retorna si el valor es distinto de cero
}
    
void        tipojuego_code_direccion( Tipojuego* tj, char* direccion ){
    long dir;
    Regla*  rule = code_regla_actual( tj );
    assert( rule );
    assert( direccion );
    dir = GETDIRECCION(tj, direccion );
    rule->flags |= RULEFLAG_DIRECCION;

    qcode_op( tj->qcode, QCSTI, 16, dir );      // t16 = dir     
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCPSH,  3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "direccion" );
    RET_IF_STATUS;                              // Retorna si el valor es distinto de cero
}

void        tipojuego_code_final  ( Tipojuego* tj, char* color, int resultado ){
    int  col;
    if( color ){
        col = GETCOLOR( tj, color );
    } else
       col = -1;

    qcode_op( tj->qcode, QCSTI, 16, resultado );// t16 = resultado
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCSTI, 16, col );      // t16 = col
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCPSH,  3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "final" );
    RET_IF_STATUS;                              // Retorna si el valor es distinto de cero


}
