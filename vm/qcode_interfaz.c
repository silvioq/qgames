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
#include  <qgames_code.h>

#include  "list.h"
#include  "tipojuego.h"
#include  "simbolos.h"
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

#define  ZGETTIPOPIEZA(z,d) ({ \
    Tipopieza* ret = NULL; \
    int val = d; \
    if( val != -1 ){         \
      ret = (Tipopieza*)  z->pos->tjuego->tipo_piezas->data[val]; \
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
    if( (long)c == -1 ) c = NULL;
    int  owner    = (int)qcode_pop(vm);
    Tipopieza*  t = ZGETTIPOPIEZA( z, qcode_pop( vm ) );
    if( (long)t == -1 ) t = NULL;
    return (long)analizador_ocupado( z, c, owner, t );
}

long  code_wrapper_transforma( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Tipopieza*  t = ZGETTIPOPIEZA( z, qcode_pop( vm ) );
    if( (long)t == -1 ) t = NULL;
    int  owner    = (int)qcode_pop(vm);
    return (long)analizador_transforma(z,owner,t );
}


long  code_wrapper_cuentapiezas( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Casillero*  c = ZGETCASILLERO( z, qcode_pop( vm ) );
    if( (long)c == -1 ) c = NULL;
    int  color    = (int)qcode_pop(vm);
    Tipopieza*  t = ZGETTIPOPIEZA( z, qcode_pop( vm ) );
    if( (long)t == -1 ) t = NULL;
    return (long)analizador_cuenta_piezas( z, c, color, t );
}

long  code_wrapper_destino_ant( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Casillero*  c = ZGETCASILLERO( z, qcode_pop( vm ) );
    if( (long)c == -1 ) c = NULL;
    return (long)analizador_destino_ant( z, c );
}

long  code_wrapper_origen_ant( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Casillero*  c = ZGETCASILLERO( z, qcode_pop( vm ) );
    if( (long)c == -1 ) c = NULL;
    return (long)analizador_origen_ant( z, c );
}


long  code_wrapper_asigna_att( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    int   att  = (int)qcode_pop(vm);
    int   val  = (int)qcode_pop(vm);
    return (long)analizador_asigna_att( z, att, val );
}

long  code_wrapper_evalua_att( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    int   att  = (int)qcode_pop(vm);
    return (long)analizador_evalua_att( z, att );
}

long  code_wrapper_setmarca( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    int  marca    = qcode_pop( vm );
    Casillero*  c = ZGETCASILLERO( z, qcode_pop( vm ) );
    if( (long)c == -1 ) c = NULL;
    return (long)analizador_setmarca( z, marca, c );
}

long  code_wrapper_captura( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Casillero*  c = ZGETCASILLERO( z, qcode_pop( vm ) );
    if( (long)c == -1 ) c = NULL;
    return (long)analizador_captura( z, c );
}

long  code_wrapper_juega( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Casillero*  c = ZGETCASILLERO( z, qcode_pop( vm ) );
    if( (long)c == -1 ) c = NULL;
    int  captura  = (int)qcode_pop(vm);
    return (long)analizador_juega( z, c, captura );
}

long  code_wrapper_mueve( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    long  fromto = qcode_pop( vm );
    long  from   = qcode_pop( vm );
    long  to     = qcode_pop( vm );
    if( (fromto&FROM_MASK)==FROM_CASILLERO) from = (long)ZGETCASILLERO(z, from );
    if( (fromto&TO_MASK)==TO_CASILLERO)     to   = (long)ZGETCASILLERO(z, to );
    return (long)analizador_mueve( z, fromto, (void*)from, (void*)to );
}

long  code_wrapper_casillero( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Casillero*  c = ZGETCASILLERO( z, qcode_pop( vm ) );
    if( (long)c == -1 ) c = NULL;
    return (long)analizador_casillero( z, c );
}
    
long  code_wrapper_direccion( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Direccion*  d = ZGETDIRECCION( z, qcode_pop( vm ) );
    return (long)analizador_direccion( z, d );
}

long  code_wrapper_atacado( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Casillero*  c = ZGETCASILLERO( z, qcode_pop( vm ) );
    return (long)analizador_atacado( z, c );
}

long  code_wrapper_ahogado( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    int  color    = (int)qcode_pop(vm);
    return (long)analizador_ahogado( z );
}

long  code_wrapper_entablero( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    return (long)analizador_entablero( z );
}

long  code_wrapper_jaquemate( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    Tipopieza* p = ZGETTIPOPIEZA( z, qcode_pop( vm ) );
    return (long)analizador_jaquemate( z, p );
}
long  code_wrapper_enzona( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    int    zon = qcode_pop( vm );
    Tipopieza* p = ZGETTIPOPIEZA( z, qcode_pop( vm ) );
    return (long)analizador_enzona( z, zon, PROPIO, p );
}

long  code_wrapper_final( QCodeVM* vm ){
    Analizador* z = (Analizador*)qcode_pop( vm );
    int  color    = qcode_pop( vm );
    if( color == -1 ) color = 0;
    int  res      = qcode_pop( vm );
    return (long)analizador_final( z, color, res );
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
    qcode_xcrlab( q, "ahogado"  ,    (qcode_extfunc)code_wrapper_ahogado );
    qcode_xcrlab( q, "asigna_att",   (qcode_extfunc)code_wrapper_asigna_att );
    qcode_xcrlab( q, "atacado",      (qcode_extfunc)code_wrapper_atacado );
    qcode_xcrlab( q, "casillero",    (qcode_extfunc)code_wrapper_casillero );
    qcode_xcrlab( q, "captura",      (qcode_extfunc)code_wrapper_captura );
    qcode_xcrlab( q, "cuentapiezas", (qcode_extfunc)code_wrapper_cuentapiezas );
    qcode_xcrlab( q, "destino_ant",  (qcode_extfunc)code_wrapper_destino_ant );
    qcode_xcrlab( q, "direccion", (qcode_extfunc)code_wrapper_direccion );
    qcode_xcrlab( q, "entablero", (qcode_extfunc)code_wrapper_entablero );
    qcode_xcrlab( q, "enzona",    (qcode_extfunc)code_wrapper_enzona );
    qcode_xcrlab( q, "evalua_att",   (qcode_extfunc)code_wrapper_evalua_att );
    qcode_xcrlab( q, "final"    , (qcode_extfunc)code_wrapper_final );
    qcode_xcrlab( q, "jaquemate", (qcode_extfunc)code_wrapper_jaquemate );
    qcode_xcrlab( q, "juega",     (qcode_extfunc)code_wrapper_juega );
    qcode_xcrlab( q, "mueve",     (qcode_extfunc)code_wrapper_mueve );
    qcode_xcrlab( q, "ocupado",   (qcode_extfunc)code_wrapper_ocupado );
    qcode_xcrlab( q, "origen_ant",(qcode_extfunc)code_wrapper_origen_ant );
    qcode_xcrlab( q, "setmarca"  ,(qcode_extfunc)code_wrapper_setmarca );
    qcode_xcrlab( q, "transforma",(qcode_extfunc)code_wrapper_transforma );

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




