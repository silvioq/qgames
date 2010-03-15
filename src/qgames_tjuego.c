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

int  simbolo_id = 0;

#define   SIM_ADD(tj,tipo,nom,data)  \
  list_agrega(tj->simbolos, simbolo_new( tipo, strdup(nom), data ) );


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
    SIM_ADD( tj, SIM_TIPOJUEGO, tj->nombre, tj );

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
    list_agrega( tj->casilleros, cas );
    SIM_ADD( tj, SIM_CASILLERO, casillero, cas );
    return tj->simbolos->entradas - 1;
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
    list_agrega( tj->direcciones, dir );
    SIM_ADD( tj, SIM_DIRECCION, dir->nombre, dir );
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
    dir = (Direccion*)sym->data;

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
    dir = (Direccion*)sym->data;

    for( i = 0; i < TABLERO_ACTUAL(tj)->dimc; i ++ ){
        dir->mov_relativo[i] = dirv[i];
    }
    tipojuego_genera_vinculos( tj, dir );
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
    list_agrega( tj->tipo_piezas, pie );
    SIM_ADD( tj, SIM_TIPOPIEZA, tpieza, pie );
    return tj->simbolos->entradas - 1;

}



/*
 * Esta funcion agrega una nueva entrada de codigo, y va armando la lista
 * de etiquetas
 * */

int         tipojuego_start_code(  Tipojuego* tj, char drop_mov, char* tipopieza, char* tipomov ){

  Simbolo* sp;
  Simbolo* sm;

  Tipopieza*  tpieza;
  int  tmov;
  EntradaCod* cod ;

  if( !tj->qcode ){
    tj->qcode = qcode_new();
  }

  sp = tipojuego_get_simbolo( tj, tipopieza );
  if( !tpieza ){
    printf( "Tipo pieza %s inexistente (File %s - linea %d\n", tipopieza, __FILE__, __LINE__ );
    exit( EXIT_FAILURE );
  }
  if( sp->tipo != SIM_TIPOPIEZA ){
    printf( "%s no es tipo pieza (File %s - linea %d\n", tipopieza, __FILE__, __LINE__ );
    exit( EXIT_FAILURE );
  }
  tpieza = (Tipopieza*) sp->data;

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
    tmov = (int) sm->data;
  } else {
    tmov = 0;
  }
  

  if( !tj->labels ) tj->labels = list_nueva( NULL );
  cod = ALLOC( sizeof( EntradaCod ) );
  memset( cod, sizeof( EntradaCod ), 0 );
  cod->tpieza = tpieza;
  cod->tmov   = tmov;
  cod->drop_mov = drop_mov;
  cod->label  = qcode_crlab( tj->qcode, unnamed_label );
  list_agrega( tj->labels, cod );

  return  tj->labels->entradas - 1;
}

