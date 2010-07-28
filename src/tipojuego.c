/****************************************************************************
 * Copyright (c) 2009-2010 Silvio Quadri                                    *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, distribute with modifications, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is    *
 * furnished to do so, subject to the following conditions:                 *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 ****************************************************************************/


#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <stdarg.h>
#include  <qgames.h>
#include  <qgames_code.h>

#include  "config.h"
#include  "qgames_core.h"
#include  "list.h"
#include  "tipojuego.h"
#include  "graphdef.h"
#include  "simbolos.h"
#include  "pieza.h"
#include  "movida.h"
#include  "partida.h"
#include  "posicion.h"

#include  "log.h"

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
    Tipojuego *  tj = malloc( sizeof( Tipojuego ) );
    memset( tj, 0, sizeof( Tipojuego ) );

    tj->simbolos = list_nueva( (_list_freefunc)free_simbolo );

    tj->nombre  = strdup( nombre );
    tj->inicial = posicion_new( tj );
    tj->flags   = ENDEFINCION | VALIDO;
    SIM_ADD( tj, SIM_TIPOJUEGO, tj->nombre, 0 );  

    return tj;

}


/*
 * Genera un tablero y las dimensiones
 * */
int         tipojuego_genera_dimensiones( Tipojuego* tj, int dimc, char** dimv ){

    // genera el tablero
    if( !TJVALIDO(tj) ) return 0;
    if( !tj->tableros ){
      tj->tableros = list_nueva( NULL );
    }
    tj->tablero_actual =  tj->tableros->entradas + 1;
    Tablero* tab = tablero_new( tj, tj->tablero_actual );
    list_agrega( tj->tableros, tab );
    if( !tablero_genera_dimensiones( tab, dimc, dimv ) ){
        TJSETERROR( tj, "Generacion de dimensiones en tablero con error", 0 );
        return 0;
    };
    return  tj->tablero_actual;
}


/* 
 * Agrega un casillero a los casilleros existentes.
 * Manda un assertion si el casillero ya existe.
 * */
int         tipojuego_add_casillero( Tipojuego* tj, char* casillero ){
    if( tipojuego_get_simbolo( tj, casillero ) ){
        // FIXME: Esto debe dar un error
        printf( "Casillero %s existente (File %s - linea %d)\n", casillero, __FILE__, __LINE__ );
        exit( EXIT_FAILURE );
    }
    if( !tj->casilleros )  tj->casilleros = list_nueva( NULL );
    Casillero*  cas = casillero_new( casillero, tj->tablero_actual, tj->casilleros->entradas );
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
        // FIXME: Esto debe dar un error
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
int        tipojuego_add_direccion_rel( Tipojuego* tj, char* direccion, ... ){

    int  i;
    Direccion* dir;
    Simbolo*  sym;
    va_list args;

    if( !TJVALIDO(tj) ) return 0;
    sym = tipojuego_get_simbolo( tj, direccion ) ;
    if( !sym ){
        TJSETERROR( tj, "Error obteniendo simbolo direccion", direccion );
        return 0;
    }
    if( SIM_DIRECCION != sym->tipo ){
        TJSETERROR( tj, "Simbolo no es direccion", direccion );
        return 0;
    }
    dir = (Direccion*)tj->direcciones->data[sym->ref];

    va_start( args, direccion );
    for( i = 0; i < TABLERO_ACTUAL(tj)->dimc; i ++ ){
        dir->mov_relativo[i] = va_arg( args, int );
    }

    va_end( args );
    return 1;

}

/* 
 * Agrega las direcciones relativas a una dirección cualquiera
 * */
int        tipojuego_add_direccion_arr( Tipojuego* tj, char* direccion, int* dirv ){

    int  i;
    Direccion* dir;
    Simbolo*  sym;

    if( !TJVALIDO(tj) ) return 0;
    sym = tipojuego_get_simbolo( tj, direccion ) ;
    if( !sym ){
        TJSETERROR( tj, "Error obteniendo simbolo direccion", direccion );
        return 0;
    }
    if( SIM_DIRECCION != sym->tipo ){
        TJSETERROR( tj, "Simbolo no es direccion", direccion );
        return 0;
    }
    dir = (Direccion*)tj->direcciones->data[sym->ref];

    for( i = 0; i < TABLERO_ACTUAL(tj)->dimc; i ++ ){
        dir->mov_relativo[i] = dirv[i];
    }
    return tipojuego_genera_vinculos( tj, dir );
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

int         tipojuego_add_cas_to_zona( Tipojuego* tj, char* cas, char* color, char* zona ){
    if( !TJVALIDO(tj) ) return 0;
    int  zzz = GETZONA( tj, zona );
    if( !TJVALIDO(tj) ) return 0;
    int  ccc = GETCOLOR( tj, color );
    if( !TJVALIDO(tj) ) return 0;
    int  cass = GETCASILLERO( tj, cas );
    if( !TJVALIDO(tj) ) return 0;
    Zonadef* zdef = malloc( sizeof( Zonadef ) );
    zdef->color = ccc;
    zdef->zona  = zzz;
    zdef->cas   = tj->casilleros->data[cass];
    if( !tj->defzonas ) tj->defzonas = list_nueva( NULL );
    list_agrega( tj->defzonas, zdef );
    return 1;
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
    Tipopieza* pie = tipopieza_new( tj, tpieza, tj->tipo_piezas->entradas );
    int ref = list_agrega( tj->tipo_piezas, pie );
    SIM_ADD( tj, SIM_TIPOPIEZA, tpieza, ref );
    return tj->simbolos->entradas - 1;

}

/* 
 * Agrega un atributo para el tipo de pieza pasado como parametro.
 * */
int         tipojuego_add_tpieza_att( Tipojuego* tj, char* tpieza, char* att, int default_value ){

    Tipopieza* tp;
    if( !TJVALIDO(tj) ) return 0;
    int  tt = GETTIPOPIEZA( tj, tpieza );
    if( !TJVALIDO(tj) ) return 0;
    tp = (Tipopieza*) tj->tipo_piezas->data[tt];
    if( !tipopieza_add_att( tp, att, default_value ) ){
        TJSETERROR( tj, "Error agregando atributo", att );
        return 0;
    };
    return  1;
}

/*
 * Esta funcion crea una nuevo tipo de juego
 *
 * */
int         tipojuego_add_tipo_mov( Tipojuego* tj, char* tmov  ){
    if( !TJVALIDO(tj) ) return 0;
    if( tipojuego_get_simbolo( tj, tmov ) ){
        TJSETERROR( tj, "Tipo de movimiento ya existente", tmov );
        return 0;
    }
    tj->tipomovs ++;
    SIM_ADD( tj, SIM_TIPOMOV, tmov, tj->tipomovs );
    return 1;
}

int         tipojuego_add_color    ( Tipojuego* tj, char* color ){
    if( !TJVALIDO(tj) ) return 0;
    if( tipojuego_get_simbolo( tj, color ) ){
        TJSETERROR( tj, "Color ya existente", color );
        return 0;
    }
    tj->colores ++;
    SIM_ADD( tj, SIM_COLOR, color, tj->colores );
    return 1;

}

/*
 * El agregado de piezas. 
 * Esta funcion agrega una pieza a la posicion original.
 *
 * */
int         tipojuego_add_pieza( Tipojuego* tj, char* tpieza, char* casillero, char* color ){

    if( !TJVALIDO(tj) ) return 0;
    Tipopieza*  tp;
    Casillero*  cas;
    int         col;
    Pieza*      p;

    if( !TJVALIDO(tj) ) return 0;
    int  tt = GETTIPOPIEZA( tj, tpieza );
    if( !TJVALIDO(tj) ) return 0;
    tp = (Tipopieza*) tj->tipo_piezas->data[tt];

    if( casillero == CASILLERO_POZO ){
       cas = ENPOZO;
    } else {
       int  cc = GETCASILLERO( tj, casillero );
       if( !TJVALIDO(tj) ) return 0;
       cas = (Casillero*) tj->casilleros->data[cc];
    }
  
    col = GETCOLOR( tj, color );
    if( !TJVALIDO(tj) ) return 0;
  
    p = posicion_add_pieza( tj->inicial );
    pieza_init( p, tp, cas, col );
    return 1;
}

/*
 * Devuelve el nombre del tipo juego ...
 * */
const char* tipojuego_get_nombre   ( Tipojuego* tj ){
    return (const char*) tj->nombre;
}

/*
 * Devuelve el numero de casillero.
 * En el caso de no ser encontrado, devuelve NOT_FOUND
 * */

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

int         tipojuego_get_att( Tipojuego* tj, char* tpieza, char* att ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, tpieza );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_TIPOPIEZA ) return NOT_FOUND;
    Tipopieza* x = (Tipopieza*) tj->tipo_piezas->data[sym->ref];
    return tipopieza_get_att( x, att );
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
 * Devuelve la cantidad de dimensiones que tiene el tablero actual
 * */
int         tipojuego_get_dimensiones( Tipojuego* tj ){
    return  TABLERO_ACTUAL(tj)->dimc;
}

    
    

/*
 * La simetria
 * */
int         tipojuego_add_simetria( Tipojuego*  tj, char* color, char* d1, char* d2 ){
    if( !TJVALIDO( tj ) ) return 0;
    int  col = GETCOLOR( tj, color );
    if( !TJVALIDO(tj) ) return 0;
    int  dd1 = GETDIRECCION( tj, d1 );
    if( !TJVALIDO( tj ) ) return 0;
    int  dd2 = GETDIRECCION( tj, d2 );
    if( !TJVALIDO( tj ) ) return 0;

    Simetria*  sim = malloc( sizeof( Simetria ) );
    sim->color = col;
    sim->dir1  = tj->direcciones->data[dd1];
    sim->dir2  = tj->direcciones->data[dd2];
    
    if( !tj->simetrias ) tj->simetrias = list_nueva( NULL );
    list_agrega( tj->simetrias, sim );
    return 1;
}


/*
 * Vamos armando la secuencia de jugadas 
 * */
int         tipojuego_add_secuencia( Tipojuego* tj, char* color, char* tipomov ){
    if( !TJVALIDO( tj ) ) return 0;
    int  col = GETCOLOR( tj, color );
    if( !TJVALIDO( tj ) ) return 0;
    int  tmov = ( tipomov ? GETTIPOMOV( tj, tipomov ) : 0 );
    if( !TJVALIDO( tj ) ) return 0;

    Secuencia* seq = (Secuencia*) malloc( sizeof( Secuencia ) );
    seq->color = col;
    seq->tmov  = tmov;

    if( !tj->secuencias ) tj->secuencias = list_nueva( NULL );
    list_agrega( tj->secuencias, seq );
    return 1;
}

int         tipojuego_add_secuencia_rep( Tipojuego* tj ){
    if( !TJVALIDO( tj ) ) return 0;
    if( !tj->secuencias ){
        TJSETERROR( tj, "No hay secuencias", 0 );
        return 0;
    }
    tj->secuencia_repeat = tj->secuencias->entradas;
    return 1;
}

/*
 *
 * Esta es la parte de definicion de notaciones
 * 
 * */
#define  INIT_NOTACION( tj ) \
    if( !tj->notacion ) { \
        tj->notacion = malloc( sizeof( Notacion ) );\
        memset( tj->notacion, 0, sizeof( Notacion ) ); \
    }

/*
 * La primera definicion de la notacion es la abreviatura del tipo 
 * de pieza
 * */
int    tipojuego_add_notacion_tpieza( Tipojuego* tj, char* tpieza, char* color, char* abbr ){
    if( !TJVALIDO( tj ) ) return 0;
    int  tp = GETTIPOPIEZA( tj, tpieza );
    if( !TJVALIDO( tj ) ) return 0;

    int  col = ( color ? tipojuego_get_color( tj, color ) : 0 );
    NotacionData* not_data = malloc( sizeof( NotacionData ) );
    not_data->valor = (long)(tj->tipo_piezas->data[tp]);
    not_data->color = col;
    not_data->notacion = abbr;
    INIT_NOTACION(tj);
    if( !tj->notacion->notacion_tpiezas ) tj->notacion->notacion_tpiezas = list_nueva( NULL );
    list_agrega( tj->notacion->notacion_tpiezas , not_data );
    return 1;
}

int    tipojuego_add_notacion_tmov( Tipojuego* tj, char* tmov, char* notacion ){
    if( !TJVALIDO( tj ) ) return 0;
    int  tm = GETTIPOMOV( tj, tmov );
    if( !TJVALIDO( tj ) ) return 0;
    NotacionData* not_data = malloc( sizeof( NotacionData ) );
    not_data->valor = tm;
    not_data->notacion = notacion;
    INIT_NOTACION(tj);
    if( !tj->notacion->notacion_tmovs ) tj->notacion->notacion_tmovs = list_nueva( NULL );
    list_agrega( tj->notacion->notacion_tmovs , not_data );
    return 1;
}

void   tipojuego_add_notacion_def( Tipojuego* tj, char elemento ){
    INIT_NOTACION(tj);
    if( !tj->notacion->notacion ){  
        tj->notacion->notacion = malloc(128);
        tj->notacion->notacion[0] = elemento;
        tj->notacion->notacion[1] = 0;
    } else {
        int  len = strlen(tj->notacion->notacion );
        tj->notacion->notacion[len] = elemento;
        tj->notacion->notacion[len+1] = 0;
    }
}

void   tipojuego_add_notacion_rep( Tipojuego* tj, char elemento ){
    INIT_NOTACION(tj);
    if( !tj->notacion->repeticion ){  
        tj->notacion->repeticion = malloc(128);
        tj->notacion->repeticion[0] = elemento;
        tj->notacion->repeticion[1] = 0;
    } else {
        int  len = strlen(tj->notacion->repeticion );
        tj->notacion->repeticion[len] = elemento;
        tj->notacion->repeticion[len+1] = 0;
    }
}

/*
 *
 * A partir de aqui, comienzas las definiciones de graficos
 *
 * */

int    tipojuego_graph_tablero_std     ( Tipojuego* tj, int board_number, char graphtype, int width, int height, int forecolor, int backcolor ){
    if( !TJVALIDO(tj) ) return 0;
    int b = ( board_number == BOARD_ACTUAL ? tj->tablero_actual : board_number );
    if( b > tj->tableros->entradas ){
        TJSETERROR( tj, "Numero de tablero incorrecto", 0 );
        return 0;
    }
    if( !tj->graphdefs ) tj->graphdefs = list_nueva( NULL );
    Graphdef* g = malloc( sizeof( Graphdef ) );
    memset( g, 0, sizeof( Graphdef ) );
    g->tipo = TIPOGRAPH_TABLERO;
    g->tablero = b;
    g->std  = graphtype;
    g->w    = width;
    g->h    = height;
    g->f    = forecolor;
    g->b    = backcolor;

    list_agrega( tj->graphdefs, g );
    return 1;

}

int    tipojuego_graph_tipopieza_std   ( Tipojuego* tj, char* tpieza, int stdimg, int width, int height ){
    if( !TJVALIDO(tj) ) return 0;
    int tp = GETTIPOPIEZA( tj, tpieza );
    if( !TJVALIDO(tj) ) return 0;
    if( !tj->graphdefs ) tj->graphdefs = list_nueva( NULL );
    Graphdef* g = malloc( sizeof( Graphdef ) );
    memset( g, 0, sizeof( Graphdef ) );
    g->tipo = TIPOGRAPH_TPIEZA;
    g->tpieza = tj->tipo_piezas->data[tp];
    g->std  = stdimg;
    g->w    = width;
    g->h    = height;
    list_agrega( tj->graphdefs, g );
    return 1;
}


/*
 * Esta funcion setea la marca de notacion. La primera
 * es la separacion de movida y la segunda es la marca de
 * capturado
 * */
void   tipojuego_set_notacion_marca( Tipojuego* tj, char* marca, char* captura ){
    INIT_NOTACION(tj);
    if( marca )   tj->notacion->marca = strdup(marca);
    if( captura ) tj->notacion->captura = strdup(captura);
}




/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */

/*
 * Dado un arreglo de posiciones relativas en un tablero,
 * esta funcion devuelve el casillero correspondiente.
 * Si no encuentra ninguno, devuelve Nulo.
 * */

Casillero*  tipojuego_get_casillero_by_relpos( Tipojuego* tj, int tablero, int dims[MAXDIMS] ){
    Casillero* c;
    if( tablero > tj->tableros->entradas ) return NULL;
    int  dimensiones = ((Tablero*) tj->tableros->data[tablero - 1] )->dimc;
    list_inicio( tj->casilleros );
    while( ( c = list_siguiente( tj->casilleros ) ) ){
      if( ( c->tablero == tablero ) &&
          ( casillero_check_dims( c, dimensiones, dims ) ) ) return (Casillero*)c ;
    }
    return NULL;
    
}

/*
 * Esta función genera los vínculos entre casilleros a 
 * partir de las posiciones relativas de los casilleros
 * y de las direcciones 
 * */

int     tipojuego_genera_vinculos( Tipojuego* tj, Direccion* dir ){
    int i, j, k;
    Casillero* ori;
    Casillero* des;
    if( !TJVALIDO( tj )) return 0;
    int posicion[MAXDIMS];

    for( i = 0; i < tj->casilleros->entradas; i ++ ){
        ori = (Casillero*) tj->casilleros->data[i];
        if( !casillero_posicion_establecida( ori ) ) continue;
        Tablero* tab = (Tablero*) tj->tableros->data[ori->tablero-1];
        int hay_algo = 0;
        for( k =0 ; k < tab->dimc; k ++ ){
           posicion[k] = ori->posicion[k] + dir->mov_relativo[k] ;
           if( dir->mov_relativo[k] ) hay_algo = 1;
        }
        if( !hay_algo ){
            TJSETERROR( tj, "Error al generar vinculos", ori->nombre );
            return 0;
        };
        if( ( des = tipojuego_get_casillero_by_relpos( tj, ori->tablero, posicion ) ) ){
            LOGPRINT( 6, "Agrega origen:%s dir:%s des:%s",
                  ori->nombre, dir->nombre, des->nombre );
            if( !casillero_add_vinculo( ori, dir, des ) ){
                TJSETERROR( tj, "Error agregando vinculo", ori->nombre );
                return 0;
            }
        }
    }
    return 1;

}


int         tipojuego_casillero_en_zona( Tipojuego* tj, Casillero* cas, int zona, int color ){
    int i;
    if( !tj->defzonas ) return 0;
    for( i = 0; i < tj->defzonas->entradas; i ++ ){
        Zonadef*  zonadef = tj->defzonas->data[i];
        if( zonadef->zona == zona && zonadef->color == color && zonadef->cas == cas ) return 1;
    }
    return 0;
}

/*
 * Esta funcion devuelve la dirección correcta teniendo en cuenta el desdoble por 
 * simetria del color pasado como parámetro
 * */
Direccion*  tipojuego_dir_by_sym( Tipojuego* tj, Direccion* dir, int color ){
    if( !tj->simetrias ) return dir;
    Simetria* sss;
    list_inicio( tj->simetrias );
    while( sss = (Simetria*) list_siguiente(tj->simetrias) ){
        if( color == sss->color && dir == sss->dir1 ) return sss->dir2;
    }
    return dir;
}

/*
 *
 * Devuelve el nombre del color pasado como parametro,
 * accediendo a la tabla de simbolos 
 *
 * */

char*       tipojuego_get_colorname( Tipojuego* tj, int color ){
    int i;
    static char color_no_encontrado[15];
    if( !TJVALIDO( tj ) ) return NULL;
    if( !tj->simbolos ){
        TJSETERROR( tj, "No estan definido los simbolos aun", 0 );
        return NULL;
    }
    for( i = 0; i < tj->simbolos->entradas; i ++ ){
        volatile Simbolo* sym;
        sym = tj->simbolos->data[i];
        if( sym->tipo != SIM_COLOR ) continue;
        if( sym->ref  == color ) return sym->nombre;
    }
    sprintf( color_no_encontrado, "%d ???", color );
    return  color_no_encontrado;
}

int      tipojuego_get_coloroponente( Tipojuego* tj, int color ){
    int i;
    if( !TJVALIDO( tj ) ) return 0;
    for( i = 1; i <= tj->colores; i ++ ){
        if( i != color ) return i;
    }
    TJSETERROR( tj, "Color no encontrado", 0 );
    return 0;
}


