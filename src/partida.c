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

#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <stdint.h>
#include <md5.h>
#include <time.h>
#include <sys/time.h>
#include <qgames.h>


#include "config.h"
#include "tipojuego.h"
#include "pieza.h"
#include "movida.h"
#include "posicion.h"
#include "partida.h"

#include "log.h"

int   partida_mover_mov( Partida* par, Movida* mov );

/* 
 * Esta funcion devuelve la proxima secuencia, a partir
 * del estado de la partida y de la definicion misma de secuencia
 * */
void    secuencia_actual   ( Partida* par, int* color, int* tmov ){
    Secuencia* seq;
    if( par->tjuego->secuencias ){
        if( par->secuencia > par->tjuego->secuencias->entradas ){
            LOGPRINT( 1, "Me paso de secuencia (%d > %d)", par->secuencia, par->tjuego->secuencias->entradas )
            return;
        }
        seq = (Secuencia*)par->tjuego->secuencias->data[par->secuencia];
        if( color ) *color = seq->color;
        if( tmov  ) *tmov  = seq->tmov ;
    } else {
        if( color ) *color = par->secuencia + 1;
        if( tmov  ) *tmov  = 0;
    }
}


void    secuencia_siguiente( Partida* par, int* color, int* tmov ){
    par->secuencia ++;
    if( par->tjuego->secuencias ){
        if( par->secuencia >=  par->tjuego->secuencias->entradas ){
            par->secuencia = par->tjuego->secuencia_repeat;
        }
    } else {
        if( par->secuencia >= par->tjuego->colores ){
            par->secuencia = 0;
        }
    }
    if( color || tmov ) secuencia_actual( par, color, tmov );
}


void    secuencia_anterior( Partida* par ){
    par->secuencia --;
    if( par->tjuego->secuencias ){
        if( par->secuencia < 0 ){
            par->secuencia = par->tjuego->secuencias->entradas - 1;
        }
    } else {
        if( par->secuencia < 0 ){
            par->secuencia = par->tjuego->colores - 1;
        }
    }
}


Partida*  partida_new( Tipojuego* tjuego, char* id_par ){
    Partida*  par = malloc( sizeof( Partida ) );
    memset( par, 0, sizeof( Partida ) );
    par->tjuego = tjuego;
    par->pos    = posicion_dup( tjuego->inicial );
    secuencia_actual( par, &(par->color), &(par->tmov) );
    par->flags |= PORCOMENZAR;
    par->inicio = time( NULL );

    // Calculo el id
    if( id_par ){
        par->id = strdup( id_par );
    } else {
        char  aux[256];
        unsigned char  aux2[16];
        static  int xxx = 100; int seeded = 0;
        int  mod = xxx % 8;
        char*  id = malloc( 256 );
        int  di;
        xxx += 7;
        md5_state_t  md5;
        md5_init( &md5 );

        if( !seeded ){
            struct timeval tv;
            gettimeofday (&tv, NULL);
            srandom( tv.tv_sec * tv.tv_usec );
            seeded = 1;
        }
        sprintf( aux, "%d-%d-%d", (int)random(), (int)clock(), xxx );
        md5_append( &md5, aux, strlen( aux ) );
        md5_append( &md5, (void*)(&xxx), sizeof( int ) );
        md5_finish( &md5, aux2 );
        // LOGPRINT( 2, "md5 = %s", aux2 );
        for( di = mod; di < mod + 6; di ++ ){
	        sprintf(aux + ( di - mod ) * 2, "%02x", aux2[di]);
        }
        memcpy( id, aux, 12 );
        id[12] = '@';
        id[13] = 0;
        strcat( id, QGAMES_SERVERNAME );
        par->id = id ;
    }


    return  par;    
}


/*
 * Vamos a liberar todo lo que hay
 * */

void  partida_free( Partida* par ){
    if( par->pos ){
        Posicion * pos,* pos_act;
        pos_act = par->pos;
        while( pos_act->pos_anterior ){ 
            pos = pos_act->pos_anterior;
            posicion_free( pos_act );
            pos_act = pos;
        }
        posicion_free( pos_act );
    }
    if( par->id ) free( par->id );
    if( par->movimientos ){
        int  i;
        for( i = 0; i < par->movimientos->entradas; i ++ ){
            Movida* mm = (Movida*) par->movimientos->data[i];
            movida_free( mm );
        }
        list_free( par->movimientos );
    }
    if( par->resultado ) free( par->resultado );
    free( par );
}



/*
 * Este es el analizador de movidas.
 * Primero verifica que esté todo analizado, luego intentaremos 
 * llamar al calculo de posicion y finalmente, armaremos las
 * notaciones
 * */
int       partida_analizar_movidas( Partida* par ){
    if( PARTIDATERMINADA(par)){
        LOGPRINT(2,"Partida %s terminada", par->id );
        return 0;
    }
    if( PARTIDAMOVCALC(par) ) return  par->pos->movidas->entradas;
    clock_t  inicio;
    clock_t  final ;
    double   elapsed;
    inicio = clock();

    par->flags |= ANALIZANDO;

    int ret = posicion_analiza_movidas( par->pos, ANALISIS_MOVIDA, par->color, par->tmov, par->pieza_continua );
    par->flags &= (~ANALIZANDO);
    par->flags |= JUGANDO;

    if( PARTIDACONT( par ) ){
        LOGPRINT( 1, "Hace falta agregar el pasar, aun no implementado", 0 );
        return  0;
    }

    if( PARTIDACONT( par ) ){
        Movida* mov = partida_ultimo_movimiento( par );
        if( par->pos->movidas ) notacion_resolver_movidas( par->tjuego, par->pos->movidas, mov->notacion );
    } else {
        if( par->pos->movidas ) notacion_resolver_movidas( par->tjuego, par->pos->movidas, NULL );
    }

    final   =  clock();
    elapsed = ((double) (final - inicio)) / CLOCKS_PER_SEC;
    LOGPRINT( 5, "Total: %.6f", elapsed );
    par->flags |= MOVCALC;
    return  ret;
}


/*
 *
 * Ultimo movimiento realizado.
 *
 * */
Movida*     partida_ultimo_movimiento( Partida* par ){
    if( !par->movimientos ){
        LOGPRINT( 1, "No hay movimientos definidos", 0 );
        return NULL;
    }
    if( par->movimientos->entradas  ){
        LOGPRINT( 1, "No hay movimientos hechos", 0 );
        return NULL;
    }
    return (Movida*)(par->movimientos->data[par->movimientos->entradas - 1]);
}

/*
 *
 * Devuelvo el enesimo movimiento, teniendo en cuenta que el primero
 * es el 0
 *
 * */
Movida*  partida_get_movimiento( Partida* par, int movhist ){
    if( !par->movimientos ) return NULL;
    if( movhist >= par->movimientos->entradas ) return NULL;
    return (Movida*)(par->movimientos->data[movhist]);
}

/*
 * Devuelve un PGN con lo que haya en la partida
 * */

#define  STREXPAND(str,alloc,count)  \
    if( count > alloc ){ \
        alloc = count + 32;\
        str = realloc( ret, alloc );\
    }



char*       partida_pgn( Partida* par ){
    int  alloc = ( par->movimientos ? par->movimientos->entradas : 0 ) * 10 + 32 ;
    int  count = 0;
    char* ret = malloc( alloc ); int point;
    // Primero, variante
    char* var = "[Variant \"%s\"]\n";
    char* res = "[Result \"%s\"]\n";
    char* event = "[Event \"Casual Game\"]\n[Annotator \"%s\"]\n";
    char* res_enj = "*", * res_10 = "1-0", *res_01 = "0-1", *res_emp = "1/2-1/2" ;
    char* rr;

    count = strlen( event ) -2 + strlen( par->id ) ;
    STREXPAND(ret,alloc,count);
    sprintf( ret, event, par->id );
    point = count;
    
    count += strlen( par->tjuego->nombre ) + strlen( var ) - 2;
    STREXPAND(ret,alloc,count);
    sprintf( ret + point, var, par->tjuego->nombre );

    if( PARTIDATERMINADA(par) ){
        if( PARTIDATABLAS(par) ){
            rr = res_emp;
        } else if( par->color_ganador == 1 ){
            rr = res_10;
        } else rr = res_01;
    }  else 
      rr = res_enj;

    point = count;
    count += strlen( res ) + strlen( rr ) - 2;
    STREXPAND(ret,alloc,count);
   
    sprintf(ret + point, res, rr );

    count += 1;
    strcat( ret + point, "\n" );

    // Ahora las jugadas
    if( par->movimientos ){
        int  move = 0; int blancas = 1;
        int  line = 0;
        list_inicio( par->movimientos );
        Movida* mov;
        while( mov = (Movida*)list_siguiente(par->movimientos) ){
            point = count;
            if( blancas ){
                move ++;
                char mm[10];
                if( move == 1 ){
                    sprintf( mm, "%d.", move );
                } else sprintf( mm, " %d.", move );
                count += strlen( mm );
                line += strlen( mm );
                STREXPAND(ret,alloc,count);
                strcat( ret + point, mm );
                point = count;
                blancas = 0;
            } else blancas = 1;

            count += strlen( mov->notacion ) + ( line == 0 ? 0 : 1 );
            STREXPAND(ret,alloc,count);
            sprintf( ret + point, ( line == 0 ? "%s" : " %s" ), mov->notacion );
            line  += strlen( mov->notacion ) + 1;
            if( line > 72 ){
                count += 1;
                line  = 0;
                strcat( ret + point, "\n" );
            }
        }
    }
    
    point = count;
    count += strlen( rr ) + 1 ;
    STREXPAND(ret,alloc,count);
    strcat( ret + point, " " );
    strcat( ret + point, rr );

    return  ret;


}



/*
 * Hace un movimiento, de acuerdo a la lista de movidas posibles.
 * */
int       partida_mover         ( Partida* par, int mov ){
    if( PARTIDATERMINADA(par)){
        LOGPRINT(2,"Partida %s terminada", par->id );
        return 0;
    }
    if( !PARTIDAMOVCALC(par) ) partida_analizar_movidas( par );
    if( mov >= par->pos->movidas->entradas ) return 0;
    return partida_mover_mov( par, (Movida*)par->pos->movidas->data[mov] );
}


int       partida_mover_notacion( Partida* par, char* mov ){
    if( PARTIDATERMINADA(par)){
        LOGPRINT(2,"Partida %s terminada", par->id );
        return 0;
    }
    if( !PARTIDAMOVCALC(par) ) partida_analizar_movidas( par );
    int i;
    if( par->pos->movidas ){
        for( i = 0; i < par->pos->movidas->entradas; i ++ ){
            Movida* mmm = (Movida*)par->pos->movidas->data[i];
            if( strcmp( mov, mmm->notacion ) == 0 ) 
                return  partida_mover_mov( par, mmm );
        }
    }
    LOGPRINT( 3, "No encuentro la movida %s", mov );
    return 0;
}




int         partida_mover_serie ( Partida* par, char* serie ){
    if( PARTIDATERMINADA(par)){
        LOGPRINT(2,"Partida %s terminada", par->id );
        return 0;
    }
    char*  movepoint = serie;

    while( 1 ) {
        int  i  = 0;
        char   move[256];
        while( movepoint[i] && movepoint[i] != ' ' ){
            move[i] = movepoint[i];
            i ++;
        }
        move[i] = 0;
        if( i > 0 && move[i-1] == '+' ) move[i-1] = 0;
        if( i > 0 && move[i-1] == '#' ) move[i-1] = 0;
        if( !partida_mover_notacion( par, move ) ) return 0;
        if( PARTIDATERMINADA(par) ) return 1;
        if( movepoint[i] == 0 ) return 1;
        movepoint += i + 1;
    }
}

/*
 * Esta es la verdadera ejecucion de movimientos
 * */

int   partida_mover_mov( Partida* par, Movida* mov ){
    Posicion* posnew;
    Movida* movant;
    int  ret;
    if( PARTIDACONT( par ) ){
        LOGPRINT( 1, "Hace falta agregar las movidas continuadas a la lista de movimientos anterior (no implementado)", 0 );
        return 0;
    }
    if( !par->movimientos ) par->movimientos = list_nueva( NULL );
    movant = movida_dup( mov );
    list_agrega( par->movimientos, movant );

    posnew = movida_ejecuta( mov );
    posnew->pos_anterior = par->pos;
    posnew->mov_anterior = movant;
    posicion_free_movidas( par->pos );
    
    par->pos = posnew;
    par->flags &= ~MOVCALC;

    int  color_actual = par->color;
    int  color_sig ;
    secuencia_siguiente( par, &color_sig, NULL );
    secuencia_anterior( par );
    char* resultado;
    ret = posicion_analiza_final( par->pos, color_actual, color_sig, &resultado );
    if( ret == FINAL_EMPATE ){
        par->resultado = resultado;
        par->flags    |= ESTABLAS;
        par->flags    &= ~ANALIZANDO;
        par->flags    |= TERMINADA;
    } else if ( ret > 0 ){
        par->resultado = resultado;
        par->color_ganador = ret;
        par->flags    &= ~ANALIZANDO;
        par->flags    |= TERMINADA;
    } else {
        secuencia_siguiente( par, &(par->color), &(par->tmov) );
    }
    return 1;
}

/*
 * Contador de cantidad de piezas, muy útil a la hora
 * de hacer pruebas
 * */
int         partida_count_piezas  ( Partida* par, char* casillero, char* tpieza ){
    Casillero* cas;
    Tipopieza* tp;
    int count = 0;
    if( !casillero ){
        cas = NULL;
    } else if( casillero == CASILLERO_POZO ){
        cas = ENPOZO;
    } else if ( casillero == CASILLERO_CAPTURA ){
        cas = ENCAPTURA;
    } else {
        int ret = GETCASILLERO( par->tjuego, casillero );
        cas = (Casillero*) par->tjuego->casilleros->data[ret];
    }
    
    tp = ( tpieza ? (Tipopieza*) par->tjuego->tipo_piezas->data[GETTIPOPIEZA( par->tjuego, tpieza )] : NULL );


    int i;
    for( i = 0; i < par->pos->piezas_count; i ++ ){
         Pieza* pie = &(par->pos->piezas[i]);
         if( pie ){
              if( tpieza && tp != pie->tpieza ) continue;
              if( !cas ){
                  if(CASILLERO_VALIDO(pie->casillero)) count ++;
              } else if( cas == pie->casillero ){
                  count ++;
              }
         }
    }

    return  count;

}


/*
 * Dada una movida determinada, encuentra la posicion
 * */

Posicion*  partida_get_posicion_from_movida( Partida* par, int movida ){
    if( movida == 0 ){
        return par->tjuego->inicial ;
    } else if ( movida = LAST_MOVE ){
        return par->pos;
    } else if ( !par->movimientos ){
        LOGPRINT( 2, "Movida pedida %d. No hay movimientos. Partida %s",
                        movida,  par->id );
        return NULL;
    } else if ( movida > par->movimientos->entradas ){
        LOGPRINT( 2, "Movida pedida %d. Cantidad movimientos %d. Partida %s",
                        movida, par->movimientos->entradas, par->id );
        return NULL;
    } else if ( movida == par->movimientos->entradas ) {
        return par->pos;
    } else {
        Movida* mov = (Movida*) par->movimientos->data[movida];
        return mov->pos;
    }
}







int         partida_movida_valida ( Partida* par, char* notacion ){
    if( PARTIDATERMINADA(par) ) return 0;
    int i, cant;
    cant = partida_analizar_movidas( par );
    for( i = 0; i < cant; i ++ ){
        Movida* mov = (Movida*) par->pos->movidas->data[i];
        if( mov->notacion && ( strcmp( mov->notacion, notacion ) == 0 ) ) return 1;
    }
    return 0;
}



    



/*
 * Esta funcion genera un binario con la definicion de la partida,
 * para ser levantado próximamente.
 * Parametros:
 *  
 * Retorna
 *   0 si hubo error
 * */
#define  ADDDATA( data, len, dato, alloc ){ \
    if( len + sizeof( dato ) > alloc ){ \
        alloc = len + sizeof( dato ) + 256; \
        data = realloc( data, alloc ); \
    } \
    typeof(dato)* point = (typeof(dato)*)( ((char*)data) + len );\
    *point = dato ;\
    len += sizeof( dato ); \
  }

int         partida_dump( Partida* par, void** data, int* size ){

    int   aloc = 256;
    int   len  = 0, i;
    void* ret = malloc( aloc );
    uint8_t len8;
    uint16_t len16;

    /* La estructura es la siguiente:
        2 bytes con la version del qgames, siendo igual a MAJOR_VERSION * 256 + MINOR_VERSION
        1 byte con el largo del nombre del tipo de juego (int)
        n byte con el nombre del tipo de juego
        1 byte con el largo del id
        n bytes con el id
        1 byte con tmov
        1 byte con color
        2 bytes con el numero de pieza q continua
        1 byte con la secuencia
        4 bytes con el flag
        1 byte con el color ganador
        1 byte con el tamaño del resultado
        n bytes con el resultado de la partida
        (8 bytes con el time_t inicio)
        (8 bytes con el time_t final)
        2 bytes con la cantidad de movidas
        lista de movidas: 
           donde cada movida tiene
           2 bytes con el largo de la movida
           movida
        2 bytes con la cantidad de movidas calculadas
    */

    len16 = QG_MAJOR_VERSION * 256 + QG_MINOR_VERSION;
    ADDDATA( ret, len, len16, aloc );

    len8 = strlen(par->tjuego->nombre);
    ADDDATA( ret, len, len8, aloc );
    STREXPAND( ret, aloc, len + len8 );
    memcpy( ((char*)ret) + len, par->tjuego->nombre, len8 );
    len += len8;

    len8 = strlen(par->id);
    ADDDATA( ret, len, len8, aloc );
    STREXPAND( ret, aloc, len + len8 );
    memcpy( ((char*)ret) + len, par->id, len8 );
    len += len8;

    // tipo de movimiento
    len8 = par->tmov;
    ADDDATA( ret, len, len8, aloc );

    // Color
    len8 = par->color;
    ADDDATA( ret, len, len8, aloc );
    
    // Pieza
    len16 = par->pieza_continua ? par->pieza_continua->number : (uint16_t)-1 ;
    ADDDATA( ret, len, len16, aloc );

    // Secuencia
    len8 = par->secuencia;
    ADDDATA( ret, len, len8, aloc );

    // flag
    ADDDATA( ret, len, ((uint32_t)par->flags), aloc );

    // Color ganador
    len8 = par->color_ganador;
    ADDDATA( ret, len, len8, aloc );

    // resultado
    len8 = ( par->resultado ? strlen( par->resultado ) : 0 );
    ADDDATA( ret, len, len8, aloc );
    if( par->resultado ){
        STREXPAND( ret, aloc, len + len8 );
        memcpy( ((char*)ret) + len, par->resultado, len8 );
        len += len8;
    }

    // times!
    ADDDATA( ret, len, ((uint64_t)par->inicio), aloc );
    ADDDATA( ret, len, ((uint64_t)par->final), aloc );


    len16 = ( par->movimientos ? par->movimientos->entradas : 0 );
    ADDDATA( ret, len, len16, aloc );

    if( par->movimientos ){
        for( i = 0; i < par->movimientos->entradas; i ++ ){
            Movida* mov = par->movimientos->data[i];
            void * mmm;
            int    size;
            if( !movida_dump( mov, &mmm, &size ) ){
                LOGPRINT( 1, "No puede realizarse el dump de movida %p", mov );
                return 0;
            };
            len16 = size;
            ADDDATA( ret, len, len16, aloc );
            STREXPAND( ret, aloc, len + size );
            memcpy( ((char*)ret) + len, mmm, size );
            free( mmm );
            len += size;
        }
    }

    // 
    if( PARTIDAMOVCALC(par) && !PARTIDATERMINADA( par) ){
        len16 = par->pos->movidas->entradas;
        ADDDATA( ret, len, len16, aloc );
        for( i = 0; i < par->pos->movidas->entradas; i ++ ){
            Movida* mov = par->pos->movidas->data[i];
            void * mmm;
            int    size;
            if( !movida_dump( mov, &mmm, &size ) ){
                LOGPRINT( 1, "No puede realizarse el dump de movida %p", mov );
                return 0;
            };
            len16 = size;
            ADDDATA( ret, len, len16, aloc );
            STREXPAND( ret, aloc, len + size );
            memcpy( ((char*)ret) + len, mmm, size );
            free( mmm );
            len += size;
        }
    }

  
    *data = ret;
    *size = len;

    return 1;


}
/*
 * Esta funcion toma un espacio de memoria y recrea
 * la partida
 * */
Partida*    partida_load( Tipojuego* tjuego, void* data, int size ){

    char* point = data;
    uint8_t len8;
    uint16_t len16, piece_num;
    int  max, i;
    char aux[256];
    Partida* par;

    len16 = ((uint16_t*)point)[0];
    if( len16 < 2 * 256 + 9 ){
        LOGPRINT( 2, "Error: de version de archivo: %d.%d => ", len16 / 256, len16 % 256, 2, 9 , aux );
        return 0;
    }
    point += sizeof( uint16_t );

    /* El primer paso es controlar que el tipo de juego corresponda
       con lo que tiene la data */
    len8 = point[0]; 
    point ++;
    memcpy( aux, point, len8 );
    aux[len8] = 0;
    point += len8;

    if( strcmp( aux, tjuego->nombre ) != 0 ){
        LOGPRINT( 2, "Error: tipojuego esperado %s != %s", tjuego->nombre, aux );
        return NULL;
    }

    len8 = point[0]; 
    point ++;
    memcpy( aux, point, len8 );
    aux[len8] = 0;
    point += len8;
    par = partida_new( tjuego, aux );

    // ahora vienen 25 bytes ... controlo primero de no pasarme.
    if( point + 25 > ((char*)data) + size ){
        LOGPRINT( 1, "No puede levantarse la cantidad de bytes necesaria (%d)", size );
        partida_free( par );
        return NULL;
    }

    len8 = point[0];
    par->tmov = len8;
    point ++;

    len8 = point[0];
    par->color = len8;
    point ++;

    piece_num = ((uint16_t*)point)[0];
    point += sizeof(uint16_t);

    len8 = point[0];
    par->secuencia = len8;
    point ++;

    par->flags = (int)(((uint32_t*)point)[0]);
    point += sizeof(uint32_t);

    len8 = point[0];
    par->color_ganador = len8;
    point ++;

    len8 = point[0];
    point ++;
    if( len8 ){
        par->resultado = malloc( len8 + 1 );
        memcpy( par->resultado, point, len8 );
        par->resultado[len8] = 0;
        point += len8;
    }

    par->inicio = (time_t)(((uint64_t*)point)[0]);
    point += sizeof( uint64_t );
    par->final = (time_t)(((uint64_t*)point)[0]);
    point += sizeof( uint64_t );

    par->movimientos = list_nueva( NULL );
    max = ((uint16_t*)point)[0];
    point += sizeof( uint16_t);
    for( i = 0; i < max; i ++ ){
        len16 = ((uint16_t*)point)[0];
        point += sizeof(uint16_t);
        Movida* mov = movida_load( par->pos, point, len16 );
        if( point + len16 > ((char*)data) + size ) {
            LOGPRINT( 1, "No puede levantarse la cantidad de bytes necesaria (%d)", size );
            partida_free( par );
            return NULL;
        }
        point += len16;
        list_agrega( par->movimientos, mov );
        Posicion* pos = movida_ejecuta( mov );
        pos->pos_anterior = par->pos;
        par->pos = pos;
    }

    par->pieza_continua = ( piece_num == (uint16_t)-1 ? NULL : &( par->pos->piezas[piece_num] ) );

    // Finalmente, analizamos si hay movidas calculadas
    if( PARTIDAMOVCALC(par) && !PARTIDATERMINADA( par) ){
        max = ((uint16_t*)point)[0];
        point += sizeof( uint16_t);
        for( i = 0; i < max; i ++ ){
            len16 = ((uint16_t*)point)[0];
            point += sizeof(uint16_t);
            Movida* mov = movida_load( par->pos, point, len16 );
            if( point + len16 > ((char*)data) + size ){
                LOGPRINT( 1, "No puede levantarse la cantidad de bytes necesaria (%d)", size );
                partida_free( par );
                return NULL;
            }
            point += len16;
            posicion_add_movida( par->pos, mov );
        }
    }

    return par;



}


/*
 * Esta funcion toma un espacio de memoria y recrea
 * la partida
 * */
const char* partida_load_tj( void* data, int size ){
    static  char aux[256];
    char* point = data;
    uint8_t len8;
    point += sizeof( uint16_t );
    len8 = point[0]; 
    point ++;
    memcpy( aux, point, len8 );
    aux[len8] = 0;
    // FIXME: Esto de devolver un valor estatico, solo puede traer problemas
    return aux;
}
