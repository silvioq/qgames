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

#include  "log.h"

// -----------------------------------------------------------------

Movida*   movida_new( Posicion* pos, Pieza* pie ){
  Movida* m;
  m = ALLOC( sizeof( Movida ) );
  memset( m, 0, sizeof( Movida ) );
  m->pos = pos;
  if( pie ) m->piece_number = pie->number;
  return m;
}

static inline Accion*   accion_new(){
    Accion* acc;
    acc = ALLOC( sizeof( Accion ) );
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
void  movida_accion_asigna_att( Movida* mov, Pieza* p, char* att, int val ){
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
    Movida*  movnew = movida_new( mov->pos, NULL );
    if( mov->notacion ) movnew->notacion = strdup( mov->notacion );
    int i;
    movnew->piece_number = mov->piece_number;
    movnew->tmov     = mov->tmov;
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
    Movida** trans = ALLOC(sizeof(Movida*) * movs->entradas );
    
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
    int i;
    for( i = 0; i < mov->acciones->entradas; i ++ ){
        Accion* acc = (Accion*) mov->acciones->data[i];
        Pieza*  p = (Pieza*)pos->piezas->data[acc->pieza_number];
        switch( acc->tipo ){
            case ACCION_MUEVE:
                posicion_mueve_pieza( pos, p, acc->destino );
                break;
            case ACCION_CAPTURA:
                posicion_mueve_pieza( pos, p, ENCAPTURA );
                break;
            case ACCION_TRANSFORMA:
                if( acc->color  ) p->color = acc->color;
                if( acc->tpieza ) p->tpieza = acc->tpieza;
                break;
            default:
                LOGPRINT( 2, "Accion no implementada %d", acc->tipo );
                assert( !"Accion no implementada" );
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
    if( mov->destino ) return mov->destino;
    if( !mov->acciones ) return NULL;
    list_inicio( mov->acciones );
    while( acc = (Accion*)list_siguiente( mov->acciones ) ){
        if( acc->destino ){
            mov->destino = acc->destino;
            return acc->destino;
        }
    }
    return  NULL;
}

/*
 * Devuelve la pieza primaria de la movida, de acuerdo al analisis
 * las acciones que la conforman. De paso, se actualiza el elemento
 * pieza de la estructura, para posteriores usos
 * */
Pieza*       movida_pieza( Movida* mov ){
    return mov->pos->piezas->data[mov->piece_number];
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
