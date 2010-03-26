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
#include  "posicion.h"

int  simbolo_id = 0;

#define   SIM_ADD(tj,tipo,nom,ref)  \
  list_agrega(tj->simbolos, simbolo_new( tipo, strdup(nom), ref ) );


#define  TABLERO_ACTUAL(tjuego) ((Tablero*)(tjuego->tableros->data[tjuego->tablero_actual - 1]))

void   free_simbolo( Simbolo* s ){
    free( s->nombre );
    free( s );
}

/* 
 * Devuelve el simbolo de acuerdo a su nombre
 * */
Simbolo*    tipojuego_get_simbolo( Tipojuego* tj, char* sim ){
    int i;
    for( i = 0; i < tj->simbolos->entradas; i ++ ){
        Simbolo* sss = (Simbolo*)  tj->simbolos->data[i];
        if( sss->nombre && ( strcmp( sim, sss->nombre ) == 0 ) ) return sss;
    }
    return NULL;
}


/*  
 * El inicio de todo tipo juego es su creación ... algo muy sencillo
 * por cierto.
 * Hay que crear la tabla de simbolos, agregar el nombre y no mucho más
 * por el momento
 * */
Tipojuego*   tipojuego_new( char* nombre ){
    Tipojuego *  tj = ALLOC( sizeof( Tipojuego ) );
    memset( tj, 0, sizeof( Tipojuego ) );

    tj->simbolos = list_nueva( (_list_freefunc)free_simbolo );

    tj->nombre  = strdup( nombre );
    tj->inicial = posicion_new( tj );
    SIM_ADD( tj, SIM_TIPOJUEGO, tj->nombre, 0 );  

    return tj;

}

/*
 * Genera un tablero y las dimensiones
 * */
int         tipojuego_genera_dimensiones( Tipojuego* tj, int dimc, char** dimv ){

    // genera el tablero
    if( !tj->tableros ){
      tj->tableros = list_nueva( NULL );
    }
    tj->tablero_actual =  tj->tableros->entradas + 1;
    Tablero* tab = tablero_new( tj, tj->tablero_actual );
    list_agrega( tj->tableros, tab );
    tablero_genera_dimensiones( tab, dimc, dimv );
    return  tj->tablero_actual;
}


/* 
 * Agrega un casillero a los casilleros existentes.
 * Manda un assertion si el casillero ya existe.
 * */
int         tipojuego_add_casillero( Tipojuego* tj, char* casillero ){
    if( tipojuego_get_simbolo( tj, casillero ) ){
        printf( "Casillero %s existente (File %s - linea %d)\n", casillero, __FILE__, __LINE__ );
        exit( EXIT_FAILURE );
    }
    if( !tj->casilleros )  tj->casilleros = list_nueva( NULL );
    Casillero*  cas = casillero_new( casillero, tj->tablero_actual );
    int ref = list_agrega( tj->casilleros, cas );
    SIM_ADD( tj, SIM_CASILLERO, casillero, ref );
    return ref;
}

/*
 * Agrega una dirección a las direcciones existente
 * Sale con error si ya existe
 * */
int         tipojuego_add_direccion( Tipojuego* tj, char* direccion ){
    if( tipojuego_get_simbolo( tj, direccion ) ){
        printf( "Direccion %s existente (File %s - linea %d)\n", direccion, __FILE__, __LINE__ );
        exit( EXIT_FAILURE );
    }
    if( !tj->direcciones )  tj->direcciones = list_nueva( NULL );
    Direccion* dir = direccion_new( direccion );
    int ref = list_agrega( tj->direcciones, dir );
    SIM_ADD( tj, SIM_DIRECCION, dir->nombre, ref );
    return tj->simbolos->entradas - 1;
}


/* 
 * Agrega las direcciones relativas a una dirección cualquiera
 * */
void       tipojuego_add_direccion_rel( Tipojuego* tj, char* direccion, ... ){

    int  i;
    Direccion* dir;
    Simbolo*  sym;
    va_list args;

    assert( sym = tipojuego_get_simbolo( tj, direccion ) );
    assert( SIM_DIRECCION == sym->tipo );
    dir = (Direccion*)tj->direcciones->data[sym->ref];

    va_start( args, direccion );
    for( i = 0; i < TABLERO_ACTUAL(tj)->dimc; i ++ ){
        dir->mov_relativo[i] = va_arg( args, int );
    }

    va_end( args );

}

/* 
 * Agrega las direcciones relativas a una dirección cualquiera
 * */
void       tipojuego_add_direccion_arr( Tipojuego* tj, char* direccion, int* dirv ){

    int  i;
    Direccion* dir;
    Simbolo*  sym;

    assert( sym = tipojuego_get_simbolo( tj, direccion ) );
    assert( SIM_DIRECCION == sym->tipo );
    dir = (Direccion*)tj->direcciones->data[sym->ref];

    for( i = 0; i < TABLERO_ACTUAL(tj)->dimc; i ++ ){
        dir->mov_relativo[i] = dirv[i];
    }
    tipojuego_genera_vinculos( tj, dir );
}

/*
 * Agrega una zona a las zonas existentes
 * Sale con error si ya existe
 * */
int         tipojuego_add_zona( Tipojuego* tj, char* zona ){
    if( tipojuego_get_simbolo( tj, zona ) ){
        printf( "Zona %s existente (File %s - linea %d)\n", zona, __FILE__, __LINE__ );
        exit( EXIT_FAILURE );
    }
    tj->zonas ++;
    SIM_ADD( tj, SIM_ZONA, zona, tj->zonas );
    return tj->zonas;
}

/*
 * Esta funcion tiene que agregar un casillero a la zona.
 * */

void        tipojuego_add_cas_to_zona( Tipojuego* tj, char* cas, char* color, char* zona ){
    int  zzz = GETZONA( tj, zona );
    int  ccc = GETCOLOR( tj, color );
    int  cass = GETCASILLERO( tj, cas );
    Zonadef* zdef = ALLOC( sizeof( Zonadef ) );
    zdef->color = ccc;
    zdef->zona  = zzz;
    zdef->cas   = tj->casilleros->data[cass];
    if( !tj->defzonas ) tj->defzonas = list_nueva( NULL );
    list_agrega( tj->defzonas, zdef );
}

/*
 * Esta funcion crea una nueva pieza
 * */
int         tipojuego_add_tipopieza( Tipojuego* tj, char* tpieza    ){

    if( tipojuego_get_simbolo( tj, tpieza ) ){
        printf( "Tipo pieza %s existente (File %s - linea %d)\n", tpieza, __FILE__, __LINE__ );
        exit( EXIT_FAILURE );
    }
    if( !tj->tipo_piezas )  tj->tipo_piezas = list_nueva( NULL );
    Tipopieza* pie = tipopieza_new( tj, tpieza );
    int ref = list_agrega( tj->tipo_piezas, pie );
    SIM_ADD( tj, SIM_TIPOPIEZA, tpieza, ref );
    return tj->simbolos->entradas - 1;

}

/* 
 * Agrega un atributo para el tipo de pieza pasado como parametro.
 * */
int         tipojuego_add_tpieza_att( Tipojuego* tj, char* tpieza, char* att, int default_value ){

    Tipopieza* tp;
    Simbolo*  sp;
    sp = tipojuego_get_simbolo( tj, tpieza );
    if( !sp ){
        printf( "Tipo pieza %s inexistente (File %s - linea %d)\n", tpieza, __FILE__, __LINE__ );
        exit( EXIT_FAILURE );
    }

    assert( sp->tipo == SIM_TIPOPIEZA );

    tp = (Tipopieza*) tj->tipo_piezas->data[sp->ref];
    if( !tp->att_nombres ){
        tp->att_nombres = list_nueva( NULL );
        tp->att_default = list_nueva( NULL );
    }
    list_agrega( tp->att_nombres, strdup(att) );
    list_agrega( tp->att_default, (void*)(long)default_value );
    return  default_value;
}

/*
 * Esta funcion crea una nuevo tipo de juego
 *
 * */
int         tipojuego_add_tipo_mov( Tipojuego* tj, char* tmov  ){
    if( tipojuego_get_simbolo( tj, tmov ) ){
        printf( "Tipo movimiento %s existente (File %s - linea %d)\n", tmov, __FILE__, __LINE__ );
        exit( EXIT_FAILURE );
    }
    tj->tipomovs ++;
    SIM_ADD( tj, SIM_TIPOMOV, tmov, tj->tipomovs );
    return tj->tipomovs;
}

int         tipojuego_add_color    ( Tipojuego* tj, char* color ){
    if( tipojuego_get_simbolo( tj, color ) ){
        printf( "Color %s existente (File %s - linea %d)\n", color, __FILE__, __LINE__ );
        exit( EXIT_FAILURE );
    }
    tj->colores ++;
    SIM_ADD( tj, SIM_COLOR, color, tj->colores );
    return tj->colores;

}

/*
 * El agregado de piezas. 
 * Esta funcion agrega una pieza a la posicion original.
 *
 * */
void        tipojuego_add_pieza( Tipojuego* tj, char* tpieza, char* casillero, char* color ){


  Simbolo* s;
  Tipopieza*  tp;
  Casillero*  cas;
  int         col;
  Pieza*      p;

  assert( s = tipojuego_get_simbolo( tj, tpieza ) );
  assert( s->tipo == SIM_TIPOPIEZA );
  tp = (Tipopieza*) tj->tipo_piezas->data[s->ref];

  if( casillero == CASILLERO_POZO ){
    cas = ENPOZO;
  } else {
    assert( s = tipojuego_get_simbolo( tj, casillero ) );
    assert( s->tipo == SIM_CASILLERO );
    cas = (Casillero*) tj->casilleros->data[s->ref];
  }
  
  assert( s = tipojuego_get_simbolo( tj, color ) );
  assert( s->tipo == SIM_COLOR );
  col = s->ref;
  
  p = pieza_new( tp, cas, col );
  posicion_add_pieza( tj->inicial, p );
}


int         tipojuego_get_casillero( Tipojuego* tj, char* cas ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, cas );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_CASILLERO ) return NOT_FOUND;
    return  sym->ref;
}

int         tipojuego_get_direccion( Tipojuego* tj, char* dir ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, dir );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_DIRECCION ) return NOT_FOUND;
    return  sym->ref;
}

int         tipojuego_get_tipopieza( Tipojuego* tj, char* tpieza ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, tpieza );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_TIPOPIEZA ) return NOT_FOUND;
    return  sym->ref;
}

int         tipojuego_get_zona     ( Tipojuego* tj, char* zona ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, zona );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_ZONA ) return NOT_FOUND;
    return  sym->ref;
}

int         tipojuego_get_color    ( Tipojuego* tj, char* color ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, color );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_COLOR ) return NOT_FOUND;
    return  sym->ref;
}
int         tipojuego_get_tipomov  ( Tipojuego* tj, char* tipomov ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, tipomov );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_TIPOMOV ) return NOT_FOUND;
    return  sym->ref;
}


/*
 * La simetria
 * */
void        tipojuego_add_simetria( Tipojuego*  tj, char* color, char* d1, char* d2 ){
    int  col = GETCOLOR( tj, color );
    int  dd1 = GETDIRECCION( tj, d1 );
    int  dd2 = GETDIRECCION( tj, d2 );

    Simetria*  sim = ALLOC( sizeof( Simetria ) );
    sim->color = col;
    sim->dir1  = tj->direcciones->data[dd1];
    sim->dir2  = tj->direcciones->data[dd2];
    
    if( !tj->simetrias ) tj->simetrias = list_nueva( NULL );
    list_agrega( tj->simetrias, sim );
}


/*
 * Vamos armando la secuencia de jugadas 
 * */
void        tipojuego_add_secuencia( Tipojuego* tj, char* color, char* tipomov ){
    int  col = GETCOLOR( tj, color );
    int  tmov = ( tipomov ? GETTIPOMOV( tj, tipomov ) : 0 );

    Secuencia* seq = ALLOC( sizeof( Secuencia ) );
    seq->color = color;
    seq->tmov  = tmov;

    if( !tj->secuencias ) tj->secuencias = list_nueva( NULL );
    list_agrega( tj->secuencias, seq );
}

void        tipojuego_add_secuencia_rep( Tipojuego* tj ){
    assert( tj->secuencias );
    tj->secuencia_repeat = tj->secuencias->entradas;
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
      printf( "Tipo pieza %s inexistente (File %s - linea %d\n", tipopieza, __FILE__, __LINE__ );
      exit( EXIT_FAILURE );
    }
    if( sp->tipo != SIM_TIPOPIEZA ){
      printf( "%s no es tipo pieza (File %s - linea %d\n", tipopieza, __FILE__, __LINE__ );
      exit( EXIT_FAILURE );
    }
    tpieza = (Tipopieza*)tj->tipo_piezas->data[sp->ref];
  } else tpieza = NULL;

  // A ver el tipo de juego
  if( tipomov ){
    sm   = tipojuego_get_simbolo( tj, tipomov );
    if( !sm ){
      printf( "Tipo movimiento %s inexistente (File %s - linea %d\n", tipomov, __FILE__, __LINE__ );
      exit( EXIT_FAILURE );
    }
    if( sp->tipo != SIM_TIPOMOV ){
      printf( "%s no es tipo movimiento (File %s - linea %d\n", tipomov, __FILE__, __LINE__ );
      exit( EXIT_FAILURE );
    }
    tmov = sm->ref;
  } else {
    tmov = 0;
  }
  
  cod = ALLOC( sizeof( Regla ) );
  memset( cod, sizeof( Regla ), 0 );
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
  } else {
    if( !tj->rules ) tj->rules = list_nueva( NULL );
    list_agrega( tj->rules, cod );
  }
  return cod->label;

}



/*
void*       tipojuego_get_code( Tipojuego* tj ){
    return (void*)tj->qcode;
}*/
