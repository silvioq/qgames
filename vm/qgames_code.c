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

#include  "log.h"
#include  "list.h"
#include  "tipojuego.h"
#include  "simbolos.h"
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
        label_stack_data =  (long*)malloc( sizeof( long ) * 10 );
        label_stack_size = 10;
    }
    if( label_stack_point >= label_stack_size ){
        label_stack_size += 10;
        label_stack_data = (long*) realloc( label_stack_data, sizeof( long ) * label_stack_size );
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
    qcode_op( tj->qcode, QCSTO, 1, 0 ) ;   // r1 = r0 ; r0 hay que salvarlo, tras cada operacion, cambia
    qcode_op( tj->qcode, QCSTI, 2, val ); 
    qcode_op( tj->qcode, QCEQU, 1, 2 );    // EQU r1 , r2
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
    long  label_inicio = pop_label_stack( );   // Esta es la etiqueta de inicio
    qcode_label( tj->qcode, label_inicio );
    
}

struct codeBlock{
    long  label_start;
    long  label_end ;
};

/*
 * Esta funcion abre un bloque de codigo, del cual se 
 * puede salir en cualquier momento!
 * */
long        tipojuego_code_start_block( Tipojuego* tj ){
    struct  codeBlock* cb = malloc( sizeof( struct codeBlock ) );
    cb->label_start = qcode_crlab( tj->qcode, unnamed_label );
    cb->label_end   = qcode_crlab( tj->qcode, unnamed_label );
    qcode_label( tj->qcode, cb->label_start );
    return (long)(void*)cb;
}
/*
 * Este es el final del bloque
 * */
void        tipojuego_code_end_block( Tipojuego* tj, long block ){
    struct  codeBlock* cb = (struct codeBlock*)block;
    qcode_label( tj->qcode, cb->label_end );
    free(cb);
}

void        tipojuego_code_break_block( Tipojuego* tj, long block ){
    struct  codeBlock* cb = (struct codeBlock*)block;
    qcode_oplab( tj->qcode, QCJMP, cb->label_end );
}

void        tipojuego_code_continue_block( Tipojuego* tj, long block ){
    struct  codeBlock* cb = (struct codeBlock*)block;
    qcode_oplab( tj->qcode, QCJMP, cb->label_start );
}


void        tipojuego_code_cuenta_piezas( Tipojuego* tj, char* casillero, int owner, char* color, char* tpieza ){
    assert( tj );
    int   own = CUALQUIERA;
    long  cas;
    long  tp;

    cas = ( casillero ? GETCASILLERO(tj,casillero) : -1 );
    tp  = ( tpieza    ? GETTIPOPIEZA(tj,tpieza)    : -1 );
    if( owner == CUALQUIERA && color ){
        own = GETCOLOR(tj, color );
    } else if( owner != CUALQUIERA ){
        own = owner;
    }

    qcode_op( tj->qcode, QCSTI, 1, tp  );       // r1 = tp 
    qcode_op( tj->qcode, QCPSH, 1, 0   );       // PSH r1
    qcode_op( tj->qcode, QCSTI, 1, own );       // r1 = own
    qcode_op( tj->qcode, QCPSH, 1, 0   );       // PSH r1
    qcode_op( tj->qcode, QCSTI, 1, cas );       // r1 = cas
    qcode_op( tj->qcode, QCPSH, 1, 0   );       // PSH r1
    qcode_op( tj->qcode, QCPSH, 3, 0   );       // PSH r3 ; analizado
    qcode_opnlab( tj->qcode, QCCLX, "cuentapiezas" );
}

void        tipojuego_code_ocupado( Tipojuego* tj, char* casillero, int owner, char* color, char* tpieza ){
    int  own = CUALQUIERA;
    long cas, tp;

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

    tp = ( tpieza ? GETTIPOPIEZA( tj, tpieza ) : -1 );

    qcode_op( tj->qcode, QCSTI, 1, tp  );      // r1 = tp
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCSTI, 1, own );      // r1 = own
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCSTI, 1, cas );      // r1 = cas     
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCPSH, 3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "ocupado" );
}


void        tipojuego_code_destino_ant( Tipojuego* tj, char* casillero ){
    long cas = ( casillero ? GETCASILLERO( tj, casillero ) : -1 );
    qcode_op( tj->qcode, QCSTI, 1, cas );      // r1 = cas     
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCPSH, 3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "destino_ant" );
}

void        tipojuego_code_origen_ant( Tipojuego* tj, char* casillero ){
    long cas = ( casillero ? GETCASILLERO( tj, casillero ) : -1 );
    qcode_op( tj->qcode, QCSTI, 1, cas );      // r1 = cas     
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCPSH, 3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "origen_ant" );
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

void        tipojuego_code_jaquemate( Tipojuego* tj, char* tpieza  ){
    assert( tj );
    tj->flags |= JAQUEMATE;
    tj->regla_actual->flags |= JAQUEMATE;
    int tp = GETTIPOPIEZA(tj, tpieza );
    ((Tipopieza*)(tj->tipo_piezas->data[tp]))->flags |= JAQUEMATE;
    qcode_op( tj->qcode, QCSTI, 1, tp  );      // r1  = tp 
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCPSH, 3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "jaquemate" );
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

    qcode_op( tj->qcode, QCSTI, 1, captura );  // r1 = captura
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCSTI, 1, cas );      // r1 = cas     
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCPSH, 3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "juega" );
    RET_IF_STATUS;                              // Retorna si el valor es distinto de cero
}


void        tipojuego_code_mueve  ( Tipojuego* tj, char fromto_flags, void* from, void* to ){
    long from_var, to_var;
    if( (fromto_flags&FROM_MASK)==FROM_CASILLERO) {
        from_var = GETCASILLERO( tj, (char*)from ) ;
    } else {
        from_var = (long)from;
    }
    if( (fromto_flags&TO_MASK)==TO_CASILLERO) {
        to_var = GETCASILLERO( tj, (char*)to ) ;
    } else {
        to_var = (long)to;
    }
    qcode_op( tj->qcode, QCSTI, 1, to_var );   // r1 = to          
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCSTI, 1, from_var );   // r1 = from        
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCSTI, 1, fromto_flags );   // r1 = fromto_flags
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCPSH, 3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "mueve" );
    RET_IF_STATUS;                              // Retorna si el valor es distinto de cero
}



void        tipojuego_code_captura( Tipojuego* tj, char* casillero ){
    long cas = ( casillero ? GETCASILLERO(tj, casillero ) : -1 );

    qcode_op( tj->qcode, QCSTI, 1, cas );      // r1 = cas     
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCPSH, 3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "captura" );
    RET_IF_STATUS;                              // Retorna si el valor es distinto de cero
}


void        tipojuego_code_asigna_att( Tipojuego* tj, char* att, int val ){
    Regla* rule = tj->regla_actual;
    assert( rule->tpieza );
    long a = GETTIPOPIEZAATT(tj, rule->tpieza, att );
    qcode_op( tj->qcode, QCSTI,  1, val );      // r1 = val
    qcode_op( tj->qcode, QCPSH,  1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCSTI,  1, a );        // r1 = a
    qcode_op( tj->qcode, QCPSH,  1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCPSH,  3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "asigna_att" );
    RET_IF_STATUS;                              // Retorna si el valor es distinto de cero
}

void        tipojuego_code_evalua_att( Tipojuego* tj, char* att ){
    Regla* rule = tj->regla_actual;
    assert( rule->tpieza );
    long a = GETTIPOPIEZAATT(tj, rule->tpieza, att );
    qcode_op( tj->qcode, QCSTI,  1, a );         // r1 = a
    qcode_op( tj->qcode, QCPSH,  1, 0 );         // PSH r1
    qcode_op( tj->qcode, QCPSH,  3, 0 );         // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "evalua_att" );
}


void       tipojuego_code_setmarca( Tipojuego* tj, int marca, char* casillero ){
    long cas = ( casillero ? GETCASILLERO(tj, casillero ) : -1 );
    qcode_op( tj->qcode, QCSTI, 1, cas );      // r1 = cas     
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCSTI, 1, marca );    // r1 = marca
    qcode_op( tj->qcode, QCPSH, 1, 0 );        // PSH r1
    qcode_op( tj->qcode, QCPSH, 3, 0 );        // PSH r3
    qcode_opnlab( tj->qcode, QCCLX, "setmarca" );
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

/*
 * Esta funcion agrega una nueva entrada de codigo, y va armando la lista
 * de etiquetas
 * El retorno de la funcion es la etiqueta para el codificador
 * */
int         tipojuego_start_code(  Tipojuego* tj, char tiporegla, char* tipopieza, char* tipomov ){

  static int  label = 0;
  Simbolo* sp;
  Simbolo* sm;

  Tipopieza*  tpieza;
  int  tmov;
  Regla* cod ;

  if( !tj->qcode ){
    code_initialize( &tj->qcode );
  }

  assert( ( tiporegla == DROP ) || ( tiporegla == MOVE ) || ( tiporegla == END ) );
  assert( ( tiporegla == END  ) || tipopieza );
  assert( ( tiporegla != END  ) || ( !tipopieza ) );
  assert( ( tiporegla != END  ) || ( !tipomov ) );

  if( tipopieza ){
    sp = tipojuego_get_simbolo( tj, tipopieza );
    if( !sp ){
      printf( "Tipo pieza %s inexistente (File %s - linea %d)\n", tipopieza, __FILE__, __LINE__ );
      exit( EXIT_FAILURE );
    }
    if( sp->tipo != SIM_TIPOPIEZA ){
      printf( "%s no es tipo pieza (File %s - linea %d)\n", tipopieza, __FILE__, __LINE__ );
      exit( EXIT_FAILURE );
    }
    tpieza = (Tipopieza*)tj->tipo_piezas->data[sp->ref];
  } else tpieza = NULL;

  // A ver el tipo de juego
  if( tipomov ){
    sm   = tipojuego_get_simbolo( tj, tipomov );
    if( !sm ){
      printf( "Tipo movimiento %s inexistente (File %s - linea %d)\n", tipomov, __FILE__, __LINE__ );
      exit( EXIT_FAILURE );
    }
    if( sm->tipo != SIM_TIPOMOV ){
      printf( "%s no es tipo movimiento (File %s - linea %d)\n", tipomov, __FILE__, __LINE__ );
      exit( EXIT_FAILURE );
    }
    tmov = sm->ref;
  } else {
    tmov = 0;
  }
  
  cod = malloc( sizeof( Regla ) );
  memset( cod, 0, sizeof( Regla ) );
  cod->tpieza = tpieza;
  cod->tmov   = tmov;
  cod->tregla = tiporegla;
  label ++;
  cod->label  = qcode_crlab( tj->qcode, unnamed_label );
  qcode_label( tj->qcode, cod->label );
  cod->pc     = qcode_label_getpc( tj->qcode, cod->label );

  if( tpieza ){
    if( !tpieza->rules ) tpieza->rules = list_nueva( NULL );
    list_agrega( tpieza->rules, cod );
    tj->regla_actual = cod;
  } else { 
    if( !tj->rules ) tj->rules = list_nueva( NULL );
    list_agrega( tj->rules, cod );
    tj->regla_actual = cod;
  }
  qcode_opnlab( tj->qcode, QCCLX, "initz" );
  qcode_op( tj->qcode, QCSTO, 3, 0 );

  return cod->label;

}


void        tipojuego_end_code( Tipojuego* tj ){
    qcode_op( tj->qcode, QCRET, 0 , 0 );
}