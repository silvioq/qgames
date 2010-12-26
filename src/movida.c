/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <stdarg.h>
#include  <stdint.h>
#include  <qgames.h>

#include  "list.h"
#include  "tipojuego.h"
#include  "pieza.h"
#include  "movida.h"
#include  "posicion.h"

#include  "log.h"

// -----------------------------------------------------------------

Movida*   movida_new( Posicion* pos, Pieza* pie, int tmov ){
  Movida* m;
  m = malloc( sizeof( Movida ) );
  memset( m, 0, sizeof( Movida ) );
  m->pos = pos;
  if( pie ) m->piece_number = pie->number;
  m->tmov = tmov;
  return m;
}

static inline Accion*   accion_new(){
    Accion* acc;
    acc = malloc( sizeof( Accion ) );
    memset( acc, 0, sizeof( Accion ) );
    return  acc;
}

/*
 *
 * Esta es la generacion de la movida de movimiento
 *
 * */
void  movida_accion_mueve  ( Movida* mov, Pieza* p, Casillero* destino ){
    Accion* acc       = accion_new();
    acc->tipo         = ACCION_MUEVE;
    acc->pieza_number = p->number;
    acc->destino      = destino;
    if( !mov->acciones ) mov->acciones = list_nueva( NULL );
    list_agrega( mov->acciones, acc );
}

void  movida_accion_crea   ( Movida* mov, Tipopieza* tpieza, int color, Casillero* cas ){
    Accion* acc       = accion_new();
    acc->tipo         = ACCION_CREA;
    acc->destino      = cas;
    acc->tpieza       = tpieza;
    acc->color        = color;
    if( !mov->acciones ) mov->acciones = list_nueva( NULL );
    list_agrega( mov->acciones, acc );
}


/*
 * Esta es la generacion de accion de captura para una movida
 * */
void  movida_accion_captura( Movida* mov, Pieza* p ) {
    Accion* acc = accion_new();
    acc->tipo = ACCION_CAPTURA;
    acc->pieza_number = p->number;
    if( !mov->acciones ) mov->acciones = list_nueva( NULL );
    list_agrega( mov->acciones, acc );
}

/*
 * La accion de transformacion
 * */
void   movida_accion_transforma( Movida* mov, Pieza* p, int color, Tipopieza* tpieza ){
    Accion* acc = accion_new();
    acc->tipo = ACCION_TRANSFORMA;
    acc->pieza_number = p->number;
    acc->tpieza       = tpieza;
    acc->color        = color;
    if( !mov->acciones ) mov->acciones = list_nueva( NULL );
    list_agrega( mov->acciones, acc );
}

/*
 * Esta accion asigna un atributo a una pieza
 * */
void  movida_accion_asigna_att( Movida* mov, Pieza* p, int att, int val ){
    Accion* acc = accion_new();
    acc->tipo = ACCION_ASIGNA_ATT;
    acc->pieza_number = p->number;
    acc->att_key      = att;
    acc->att_val      = val;
    if( !mov->acciones ) mov->acciones = list_nueva( NULL );
    list_agrega( mov->acciones, acc );
}


/*
 * Limpia todo lo que tiene la movida, que no es mucho, por 
 * cierto
 * */
void  movida_free( Movida* mov ){
    if( mov->acciones ){
        int i;
        for( i = 0; i < mov->acciones->entradas; i ++ ){
            // La accion se puede borrar tranquilamente
            free( mov->acciones->data[i] );
        }
        list_free( mov->acciones );
    }
    if( mov->notacion ) free( mov->notacion );
    free( mov );
}

/*
 * Esta funcion duplica la movida, con todas sus acciones 
 * */

Movida*   movida_dup( Movida* mov ){
    Movida*  movnew = movida_new( mov->pos, NULL, mov->tmov );
    if( mov->notacion ) movnew->notacion = strdup( mov->notacion );
    int i;
    movnew->piece_number = mov->piece_number;
    movnew->continua = mov->continua;
    movnew->acciones = list_nueva( NULL );

    for( i = 0; i < mov->acciones->entradas; i ++ ){
        Accion* accnew = accion_new();
        memcpy( accnew, mov->acciones->data[i], sizeof( Accion ) );
        list_agrega( movnew->acciones, accnew );
    }

    return movnew;
    
}

void  movida_split_transformaciones( _list* movs ){
    int  cant = 0, i;
    Movida** trans = malloc(sizeof(Movida*) * movs->entradas );
    
    // Primero seleciono aquellas movidas que tienen mas de una transformacion 
    // posible
    for( i = 0; i < movs->entradas; i ++ ){
        int j; int cc = 0;
        Movida* mov = (Movida*)movs->data[i];
        for( j = 0; j < mov->acciones->entradas; j ++ ){
            Accion* acc = ((Accion*)mov->acciones->data[j]);
            if( acc->tipo == ACCION_TRANSFORMA && acc->tpieza ) cc ++;
            if( cc > 1 ) break;
        }
        if( cc > 1 ){  // Lo saco de la lista.
            LOGPRINT( 6, "detecte movida con transformaciones %d", mov->acciones->entradas );
            trans[cant++] = mov;
            list_quita( movs, i );
            i --;
        }
    }

    for( i = 0; i < cant ; i ++ ){
        Movida* mov = trans[i]; 
        int  j, k;
        // por cada transformacion, creo una movida igual, sin 
        // las demas transformaciones.
        for( j = 0; j < mov->acciones->entradas; j ++ ){
            Accion* acc = (Accion*)mov->acciones->data[j];
            if( acc->tipo == ACCION_TRANSFORMA ){
                Movida* nueva = movida_dup( mov );
                for( k = 0; k < nueva->acciones->entradas; k ++ ){
                    Accion* acc2 = (Accion*)nueva->acciones->data[k];
                    if( acc2->tpieza != acc->tpieza && acc2->tipo == ACCION_TRANSFORMA ){
                        LOGPRINT( 6, "Sacando %s de %p", acc2->tpieza->nombre, mov );
                        list_quita( nueva->acciones, k-- );
                        free( acc2 );
                    }
                }
                list_agrega( movs, nueva );
            }
        } 
        movida_free( trans[i] );
    }
    
    free( trans );

}

/*
 * Esta es la ejecucion de la movida, o sea, la apliacion
 * de las acciones de la movida sobre la posicion que
 * esta asociada.
 * La posicion devuelta por la funcion es una nueva
 * posicion
 * */

Posicion*  movida_ejecuta( Movida* mov ){
    //
    Posicion*  pos = posicion_dup( mov->pos );
    pos->pos_anterior = mov->pos;
    pos->mov_anterior = mov;
    int i;
    for( i = 0; i < mov->acciones->entradas; i ++ ){
        Accion* acc = (Accion*) mov->acciones->data[i];
        Pieza*  p = & pos->piezas[acc->pieza_number];
        switch( acc->tipo ){
            case ACCION_MUEVE:
                posicion_mueve_pieza( pos, p, acc->destino );
                break;
            case ACCION_CAPTURA:
                posicion_mueve_pieza( pos, p, ENCAPTURA );
                break;
            case ACCION_CREA:
                p = posicion_add_pieza( pos );
                pieza_init( p, acc->tpieza, acc->destino, acc->color );
                break;
            case ACCION_TRANSFORMA:
                if( acc->color  ) p->color = acc->color;
                if( acc->tpieza ) p->tpieza = acc->tpieza;
                break;
            case ACCION_ASIGNA_ATT:
                if( !pieza_set_att( p, acc->att_key, acc->att_val ) ) return NULL;
                break;
            default:
                LOGPRINT( 1, "Accion no implementada %d", acc->tipo );
                exit( EXIT_FAILURE );
        }
    }
    return pos;
}



/*
 * Devuelve el casillero de origen de la movida, de acuerdo al analisis
 * las acciones que la conforman. 
 * */
Casillero*   movida_casillero_origen( Movida* mov ){
    Pieza*  pieza = movida_pieza( mov );
    return( pieza ? pieza->casillero : NULL );
}


/*
 * Devuelve el casillero de destino de la movida, de acuerdo al analisis
 * las acciones que la conforman. De paso, se actualiza el elemento
 * destino de la estructura, para posteriores usos
 * */
Casillero*   movida_casillero_destino( Movida* mov ){
    Accion* acc;
    Casillero*  probable = NULL;
    if( mov->destino ) return mov->destino;
    if( !mov->acciones ) return NULL;
    int  i;
    list_inicio( mov->acciones );
    while( acc = (Accion*)list_siguiente( mov->acciones ) ){
        if( acc->destino ){
            if( acc->pieza_number == mov->piece_number ){
                mov->destino = acc->destino;
                return acc->destino;
            }
            if( !probable ) probable = acc->destino;
        }
    }
    return  probable;
}

/*
 * Devuelve la pieza primaria de la movida, de acuerdo al analisis
 * las acciones que la conforman. De paso, se actualiza el elemento
 * pieza de la estructura, para posteriores usos
 * */
Pieza*       movida_pieza( Movida* mov ){
    return &(mov->pos->piezas[mov->piece_number]);
}



int          movida_es_captura( Movida* mov ){
    Accion* acc;
    if( !mov->acciones ) return 0;
    list_inicio( mov->acciones );
    while( acc = (Accion*)list_siguiente( mov->acciones ) ){
        if( acc->tipo == ACCION_CAPTURA ) return 1;
    }
    return  0;
}

/*
 * En el caso que la captura sea una transformacion, devuelve
 * valor verdadero y setea las variables pasadas como parametro
 * */
int          movida_es_transformacion( Movida* mov, int* color, Tipopieza** tp ){
   
    Accion* acc;
    if( !mov->acciones ) return 0;
    list_inicio( mov->acciones );
    while( acc = (Accion*)list_siguiente( mov->acciones ) ){
        if( acc->tipo == ACCION_TRANSFORMA ){
            if( color ) *color = acc->color;
            if( tp    ) *tp    = acc->tpieza;
            return 1;
        }
    }
    return  0;

}


#define  STREXPAND(str,alloc,count)  \
    if( count > alloc ){ \
        alloc = count + 32;\
        str = realloc( ret, alloc );\
    }

#define  ADDDATA( data, len, dato, alloc ){ \
    if( len + sizeof( dato ) > alloc ){ \
        alloc = len + sizeof( dato ) + 256; \
        data = realloc( data, alloc ); \
    } \
    typeof(dato)* point = (typeof(dato)*)( ((char*)data) + len );\
    *point = dato ;\
    len += sizeof( dato ); \
  }

/*
 * Esta funcion transpasa a binario los datos de una movida
 * Recibe como parametro un puntero a puntero y un 
 * puntero a entero. En el primer caso devolvera la data
 * y en el segundo el tamaño de la memoria alocada
 * */

int          movida_dump( Movida* mov, void** data, int* size ){

    int   aloc = 256;
    int   len  = 0, i;
    void* ret = malloc( aloc );
    uint8_t len8;
    uint16_t len16;
    /* La estructura a devolver es la siguiente:
       1. un char con el tamaño de la notacion. Si no esta "notada",
          sera un cero
       2. la notacion
       3. Entero tmov (tipo de movimiento)
       4. Entero numero de pieza
       5. Char, continua
       6. Dos bytes indicando la cantidad de acciones
          . Todas las acciones */

    if( mov->notacion ){
        len8 = strlen( mov->notacion );
    } else {
        len8 = 0;
    }
    ADDDATA( ret, len, len8, aloc );
    if( len8 > 0 ){
        STREXPAND( ret, aloc, len + len8 );
        memcpy( ((char*)ret) + len , mov->notacion, len8 );
        len += len8;
    }

    len8 = mov->tmov;
    ADDDATA( ret, len, len8, aloc );
    len16 = mov->piece_number;
    ADDDATA( ret, len, len16, aloc );
    ADDDATA( ret, len, mov->continua, aloc );

    len16 = mov->acciones->entradas;
    ADDDATA( ret, len, len16, aloc );

    /* Listo! las acciones .... estas son mas faciles ...
        char        tipo;         (char)
        int         pieza_number; (short)
        Casillero*  destino;      (short)
        int         color;        (short)
        Tipopieza*  tpieza;       (char)
        int         att_key;      (char)
        int         att_val;      (int)
    */
    for( i = 0; i < mov->acciones->entradas; i ++ ){
        Accion* acc = mov->acciones->data[i];
        ADDDATA( ret, len, acc->tipo, aloc );

        len16 = acc->pieza_number;
        ADDDATA( ret, len, len16, aloc );

        len16 = acc->destino ? acc->destino->number : -1 ;
        ADDDATA( ret, len, len16, aloc );

        len8 = acc->color;
        ADDDATA( ret, len, len8, aloc );

        len8 = acc->tpieza ? acc->tpieza->number : -1 ;
        ADDDATA( ret, len, len8, aloc );

        len8 = acc->att_key;
        ADDDATA( ret, len, len8, aloc );

        ADDDATA( ret, len, acc->att_val, aloc );
    }

    *data = ret;
    *size = len;

    return 1;
}

/*
 * Esta funcion toma lo que hay en la memoria, con 
 * el tamaño correspondiente y devuelve la movida
 * armada como corresponde 
 * */
Movida*      movida_load( Posicion* pos, void* data, int size ){
    Movida* mov = movida_new( pos, NULL, 0 );
    char* point = data;
    uint8_t len8;
    uint16_t len16;
    int  max, i;

    // Lo primero que viene es la notacion
    len8 = point[0];
    mov->notacion = malloc( len8 + 1 );
    point ++;
    memcpy( mov->notacion, point, len8 );
    mov->notacion[len8] = 0;
    point += len8;

    len8 = point[0];
    mov->tmov = len8;
    point ++;

    len16 = ((uint16_t*)point)[0];
    mov->piece_number = len16;
    point += 2;

    len8 = point[0];
    mov->continua = len8;
    point ++;

    // Ahora las acciones
    max = ((uint16_t*)point)[0];
    point += 2;
    mov->acciones = list_nueva( NULL );
    for( i = 0; i < max ; i ++ ){
        Accion* acc = malloc( sizeof( Accion ) );
        memset( acc, 0, sizeof( Accion ) );
        acc->tipo = point[0];
        point ++;
        if( ((char*)data) + size <= point ){
            LOGPRINT( 1, "Error tamaño puntero %p + %d <= %p", data, size, point );
            movida_free( mov );
            return NULL;
        }

        len16 = ((uint16_t*)point)[0];
        acc->pieza_number = len16;
        point += 2;
        if( ((char*)data) + size <= point ){
            LOGPRINT( 1, "Error tamaño puntero %p + %d <= %p", data, size, point );
            movida_free( mov );
            return NULL;
        }

        len16 = ((uint16_t*)point)[0];
        if( len16 != (uint16_t)-1 ){
            acc->destino = (Casillero*)(pos->tjuego->casilleros->data[len16]);
        }
        point += 2;
        if( ((char*)data) + size <= point ){
            LOGPRINT( 1, "Error tamaño puntero %p + %d <= %p", data, size, point );
            movida_free( mov );
            return NULL;
        }

        acc->color = point[0];
        point ++;
        if( ((char*)data) + size <= point ){
            LOGPRINT( 1, "Error tamaño puntero %p + %d <= %p", data, size, point );
            movida_free( mov );
            return NULL;
        }

        len8 = point[0];
        if( len8 != (uint8_t)-1 ){
            acc->tpieza = (Tipopieza*)(pos->tjuego->tipo_piezas->data[len8]);
        }
        point ++;
        if( ((char*)data) + size <= point ){
            LOGPRINT( 1, "Error tamaño puntero %p + %d <= %p", data, size, point );
            movida_free( mov );
            return NULL;
        }

        acc->att_key = point[0];
        point ++;
        if( ((char*)data) + size <= point ){
            LOGPRINT( 1, "Error tamaño puntero %p + %d <= %p", data, size, point );
            movida_free( mov );
            return NULL;
        }
        
        acc->att_val = ((int*)point)[0];
        point += sizeof( int );
        if( ((char*)data) + size < point ){
            LOGPRINT( 1, "Error tamaño puntero %p + %d <= %p", data, size, point );
            movida_free( mov );
            return NULL;
        }

        list_agrega( mov->acciones, acc );
    }
    return  mov;
}


