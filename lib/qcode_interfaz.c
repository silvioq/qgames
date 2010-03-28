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


#define  ZGETCASILLERO(z,c) ({ \
    Casillero* ret = NULL; \
    int val = c; \
    if( val != -1 ){         \
      ret = (Casillero*)  z->pos->tjuego->casilleros->data[val]; \
    } \
    ret; })

#define  ZGETDIRECCION(z,d) ({ \
    Direccion* ret = NULL; \
    int val = d; \
    if( val != -1 ){         \
      ret = (Direccion*)  z->pos->tjuego->direcciones->data[val]; \
    } \
    ret; })

/*
 * En esta parte del codigo, se definiran los "wrappers" entre el codigo máquina generado
 * y el tema del analizador
 * Para la implementacion a traves de esta linda máquina virtual que es la QCode, utilizaremos
 * la R3, donde dejaremos el puntero al analizador, el cual sera pasado como parametro
 * cada vez que se use
 * */
long  code_wrapper_ocupado( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    assert( z );
    Casillero*  c = ZGETCASILLERO( z, qcode_pop( vm ) );
    int  owner    = (int)qcode_pop(vm);
    return (long)analizador_ocupado( z, c, owner );
}


long  code_wrapper_juega( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Casillero*  c = ZGETCASILLERO( z, qcode_pop( vm ) );
    int  captura  = (int)qcode_pop(vm);
    return (long)analizador_juega( z, c, captura );
}

long  code_wrapper_casillero( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Casillero*  c = ZGETCASILLERO( z, qcode_pop( vm ) );
    return (long)analizador_casillero( z, c );
}
    
long  code_wrapper_direccion( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Direccion*  d = ZGETDIRECCION( z, qcode_pop( vm ) );
    return (long)analizador_direccion( z, d );
}

long  code_wrapper_ahogado( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    return 0;
}

Analizador* zgeneral;
long  code_wrapper_initz( QCodeVM* vm ){
    return  (long)zgeneral;
}
long  code_wrapper_dump( QCodeVM* vm ){
    printf( "Dump!\n" );
    return  vm->r[0];
}


void  code_initialize( QCode** qcode ){
    QCode*  q;
    q = qcode_new();
    qcode_xcrlab( q, "ocupado",   (qcode_extfunc)code_wrapper_ocupado );
    qcode_xcrlab( q, "juega",     (qcode_extfunc)code_wrapper_juega );
    qcode_xcrlab( q, "casillero", (qcode_extfunc)code_wrapper_casillero );
    qcode_xcrlab( q, "direccion", (qcode_extfunc)code_wrapper_direccion );
    qcode_xcrlab( q, "ahogado"  , (qcode_extfunc)code_wrapper_ahogado );
    qcode_xcrlab( q, "final"    , (qcode_extfunc)code_wrapper_ahogado );
    qcode_xcrlab( q, "dump"     , (qcode_extfunc)code_wrapper_dump );

    /* El primer codigo que meto es el tema del analizador */
    int label = qcode_xcrlab( q, "initz", (qcode_extfunc)code_wrapper_initz );
    qcode_oplab( q, QCCLX, label );
    qcode_op   ( q, QCSTO, 3, 0 ) ;   // STO R3, R0
    qcode_op   ( q, QCRET, 0, 0 );    // RET

    *qcode = q;
}


/* Sensacional! el más simple ejecutor de las reglas */
int    code_execute_rule( void* z, int pc ){
    zgeneral = (Analizador*)z;
    long  ret;
    QCode* q = ((Analizador*)z)->pos->tjuego->qcode;
    // q->flags |= QCODE_FLAG_DEBUG;
    int r = qcode_runargs( q, &ret, pc, 0, NULL );
    if( r == 0 ) return 0;
    printf( "-----------------------------------------\n" );
    printf( "Error de ejecucion %d\n", r );
    printf( "-----------------------------------------\n" );
    return 1;
    
}




