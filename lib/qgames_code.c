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

long    get_label_stack( ){
    assert( label_stack_point > 0 );
    long label = label_stack_data[label_stack_point-1];
    return  label;
}

/*
 *
 * Operador False
 *
 * */
void        tipojuego_code_op_false( Tipojuego* tj ){
    qcode_op( tj->qcode, QCSTI, 0, 0 ); 
}

/*
 *
 * Operador EQual
 *
 * */
void        tipojuego_code_op_equal( Tipojuego* tj, long val ){
    assert( tj );
    qcode_op( tj->qcode, QCSTI, 2, val ); 
    // qcode_opnlab( tj->qcode, QCCLX, "dump" );
    qcode_op( tj->qcode, QCEQU, 0, 2 );    // EQU r0 , r2
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

void        tipojuego_code_else_condblock( Tipojuego* tj ){
    long  label = pop_label_stack( );                          // esta tiene el final de la condicion positiva
    long  label_end = qcode_crlab( tj->qcode, unnamed_label ); // Esta tiene el final del bloque
    push_label_stack( label_end );
    qcode_oplab( tj->qcode, QCJMP, label_end );                // Lo primero que hago es mandar el PC al final del bloque
    qcode_label( tj->qcode, label );                           // Aca va a caer el PC cuando la condicion de negativa.
}

void        tipojuego_code_end_condblock( Tipojuego* tj ){
    tipojuego_code_end_block(tj);
}

/*
 * Esta funcion abre un bloque de codigo, del cual se 
 * puede salir en cualquier momento!
 * */
void        tipojuego_code_start_block( Tipojuego* tj ){
    long  label = qcode_crlab( tj->qcode, unnamed_label );
    push_label_stack( label );
}
/*
 * Este es el final del bloque
 * */
void        tipojuego_code_end_block( Tipojuego* tj ){
    long  label = pop_label_stack( );
    qcode_label( tj->qcode, label );
}

void        tipojuego_code_break_block( Tipojuego* tj ){
    long  label = get_label_stack( );
    qcode_oplab( tj->qcode, QCJMP, label );
}

void        tipojuego_code_continue_block( Tipojuego* tj );

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

void        tipojuego_code_enzona ( Tipojuego* tj, char* zona, char* tpieza ){
    int  za, tp;
    za = GETZONA(tj, zona);
    tp = ( tpieza ? GETTIPOPIEZA( tj, tpieza ) : - 1 );
    qcode_op( tj->qcode, QCSTI, 16, tp );       // t16 = tp
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCSTI, 16, za );       // t16 = za
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCPSH,  3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "enzona" );
    
}

void        tipojuego_code_atacado( Tipojuego* tj, char* casillero ){
    int  cas;
    if( casillero ){
        cas = GETCASILLERO(tj,casillero);
    } else {
        cas = -1;
    }
    qcode_op( tj->qcode, QCSTI, 16, cas );      // t16 = cas
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCPSH,  3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "atacado" );
    
}


void        tipojuego_code_entablero( Tipojuego* tj ){
    qcode_op( tj->qcode, QCPSH,  3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "entablero" );
    // FIXME: Hay que controlar posibles estados erroneos
    // RET_IF_STATUS;                              // Retorna si el valor es distinto de cero
}


void        tipojuego_code_transforma( Tipojuego* tj, int owner, char* color, char* tpieza  ){
    int  own = NOCOLOR;
    int  tp ;

    assert( owner == PROPIO || owner == ENEMIGO || owner == NOCOLOR );

    if( owner == NOCOLOR && color ){
        own = GETCOLOR(tj, color );
    } else if( owner != NOCOLOR ){
        own = owner;
    }

    if( tpieza ){
        tp = GETTIPOPIEZA(tj, tpieza );
    } else {
        tp = -1;
    }
    qcode_op( tj->qcode, QCSTI, 16, own );      // t16 = own
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCSTI, 16, tp  );      // t16 = tp 
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCPSH,  3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "transforma" );
    RET_IF_STATUS;                              // Retorna si el valor es distinto de cero
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
    if( casillero ){
        cas = GETCASILLERO(tj, casillero );
    } else {
        cas = -1;
    }
    qcode_op( tj->qcode, QCSTI, 16, cas );      // t16 = cas     
    qcode_op( tj->qcode, QCPSH, 16, 0 );        // PSH t16
    qcode_op( tj->qcode, QCPSH,  3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "casillero" );
    RET_IF_STATUS;                              // Retorna si el valor es distinto de cero
}
    
void        tipojuego_code_direccion( Tipojuego* tj, char* direccion ){
    long dir;
    Regla* rule = tj->regla_actual;
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
