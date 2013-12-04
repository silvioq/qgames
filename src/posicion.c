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
#include  <qgames.h>

#include  "config.h"
#include  "list.h"
#include  "tipojuego.h"
#include  "pieza.h"
#include  "movida.h"
#include  "posicion.h"
#include  "analizador.h"

#include  "log.h"


#include  <md5.h>

static  int        posicion_analiza_movidas_int( Posicion* pos, char tipoanalisis, int color, int tipomov, Pieza* pieza );


/* ---------------------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------------------- */
void  posicion_free_movidas( Posicion* pos ){
    if( pos->movidas ){
        int  i;
        for( i = 0; i < pos->movidas->entradas; i ++ ){
            Movida* mov = (Movida*)pos->movidas->data[i];
            movida_free( mov );
        }/*
        list_free( pos->movidas );
        pos->movidas = NULL;*/
        pos->movidas->entradas = 0;
    }
}

void  posicion_add_movida( Posicion* pos, Movida* mov ){
    if( !pos->movidas ) pos->movidas = list_nueva( NULL );
    list_agrega( pos->movidas, mov );
}

static void  posicion_add_movidas( Posicion* pos, _list* movs ){
    int i;
    for( i = 0; i < movs->entradas; i ++ ){
        Movida* m = (Movida*) movs->data[i];
        m->pos = pos;
        posicion_add_movida( pos, m );
    }
}

/*
 * 
 * Devuelve el hash que identifica univocamente a una posición
 *
 * */
char*  posicion_hash( Posicion* pos ){ 
    int i;
    if( pos->flags & POSICION_HASH_CALCULADO ) return pos->hash;
    md5_state_t md5;
    md5_init( &md5 );
    md5_append( &md5, (char*)  &(pos->tmov_continua), sizeof( int ) );
    for( i = 0; i < pos->piezas_count ; i ++ ){
        Pieza* p = &(pos->piezas[i]);
        char* hash_p = pieza_hash( p );
        md5_append( &md5, hash_p, 16 );
        LOGPRINT( 6, "Pieza %s en %s - color %d - flags %d", pos->piezas[i].tpieza->nombre, 
            CASILLERO_VALIDO( pos->piezas[i].casillero ) ? pos->piezas[i].casillero->nombre : "x",
            pos->piezas[i].color, pos->piezas[i].flags );
        LOGPRINT( 6, "hash de pieza %02x%02x%02x%02x-" "%02x%02x%02x%02x-" "%02x%02x%02x%02x-" "%02x%02x%02x%02x"
            ,(unsigned char)(pos->piezas[i].hash[0])
            ,(unsigned char)(pos->piezas[i].hash[1])
            ,(unsigned char)(pos->piezas[i].hash[2])
            ,(unsigned char)(pos->piezas[i].hash[3])
            ,(unsigned char)(pos->piezas[i].hash[4])
            ,(unsigned char)(pos->piezas[i].hash[5])
            ,(unsigned char)(pos->piezas[i].hash[6])
            ,(unsigned char)(pos->piezas[i].hash[7])
            ,(unsigned char)(pos->piezas[i].hash[8])
            ,(unsigned char)(pos->piezas[i].hash[9])
            ,(unsigned char)(pos->piezas[i].hash[10])
            ,(unsigned char)(pos->piezas[i].hash[11])
            ,(unsigned char)(pos->piezas[i].hash[12])
            ,(unsigned char)(pos->piezas[i].hash[13])
            ,(unsigned char)(pos->piezas[i].hash[14])
            ,(unsigned char)(pos->piezas[i].hash[15])
        );
    }
    md5_finish( &md5, pos->hash );
    pos->flags |= POSICION_HASH_CALCULADO;
    LOGPRINT( 6, "hash de posicion %02x%02x%02x%02x-" "%02x%02x%02x%02x-" "%02x%02x%02x%02x-" "%02x%02x%02x%02x"
        ,(unsigned char)(pos->hash[0])
        ,(unsigned char)(pos->hash[1])
        ,(unsigned char)(pos->hash[2])
        ,(unsigned char)(pos->hash[3])
        ,(unsigned char)(pos->hash[4])
        ,(unsigned char)(pos->hash[5])
        ,(unsigned char)(pos->hash[6])
        ,(unsigned char)(pos->hash[7])
        ,(unsigned char)(pos->hash[8])
        ,(unsigned char)(pos->hash[9])
        ,(unsigned char)(pos->hash[10])
        ,(unsigned char)(pos->hash[11])
        ,(unsigned char)(pos->hash[12])
        ,(unsigned char)(pos->hash[13])
        ,(unsigned char)(pos->hash[14])
        ,(unsigned char)(pos->hash[15])
    );
    return  pos->hash;
}



/*
 * Una posicion nueva!
 * */

Posicion*   posicion_new( Tipojuego* tj ){
  Posicion* pos;
  pos = malloc( sizeof( Posicion ) );
  posicion_init( pos, tj );
  return  pos;
}

void        posicion_init( Posicion* pos, Tipojuego* tj ){
  memset( pos, 0, sizeof( Posicion ) );
  pos->tjuego = tj;
}

void      posicion_free( Posicion* pos ){
    posicion_free_data( pos );
    free(pos);
}


Pieza*     posicion_get_pieza( Posicion* pos, Pieza* pieza ){
    if( !pos->piezas ) return  NULL;
    return &pos->piezas[pieza->number];
}

/*
 * Recorro las movidas que tengo e intento descartarlas por
 * posibles jaques a las piezas que se le puede hacer 
 * jaquemate
 * */
void        posicion_descartar_por_jaques( Posicion* pos, _list* movs, int color ){
    if( !TJJAQUEMATE(pos->tjuego) ) return;
    if( !movs ) return ;
    LOGPRINT( 6, "Descartar por jaques controlando para color %d", color );
    int i;
    for( i = 0; i < movs->entradas; i ++ ){
        Movida* mov = (Movida*) movs->data[i];
        mov->pos = pos;
        Posicion* pos2 = movida_ejecuta( mov );
        if( posicion_en_jaque( pos2, NULL, color ) ){
            LOGPRINT( 6, "Movida descartada %s => %s %p", 
                    movida_pieza( mov, NULL )->tpieza->nombre, 
                    movida_casillero_destino( mov )->nombre , mov->pos = pos) ;
            list_quita( movs, i );
            movida_free( mov );
            i --;
        }
        posicion_free( pos2 );
    }
}



/*
 * Esta funcion devuelve 1, si, una vez ejecutada la movida, 
 * alguna de las piezas afectadas queda en jaque.
 * */
int         posicion_en_jaque( Posicion* pos, Tipopieza* tpieza, int color ){
    int i, j;
    if( !TJJAQUEMATE(pos->tjuego) ) return 0; 
    Pieza* pieza;

    for( i = 0 ; i < pos->piezas_count; i ++ ){
        pieza = &(pos->piezas[i] );
        if( !TJJAQUEMATE(pieza->tpieza) ) continue;
        if( tpieza && pieza->tpieza != tpieza ) continue;
        if( pieza->color != color ) continue;
        if( !CASILLERO_VALIDO(pieza->casillero)) continue;

        // Ahora ejecuto las posibles movidas del enemigo
        for( j = 1; j <= pos->tjuego->colores; j ++ ){
            if( color == j ) continue;
            Movida* mov2;
            LOGPRINT( 6, "Inico de analisis para color %d en %s", j, pieza->casillero->nombre );
            posicion_analiza_movidas( pos, ANALISIS_ATAQUE, j, 0, NULL );
            if( !pos->movidas || pos->movidas->entradas == 0 ) continue;
            list_inicio( pos->movidas );
            while( mov2 = (Movida*) list_siguiente( pos->movidas ) ){
                if( movida_casillero_destino( mov2 ) == pieza->casillero ){
                    return 1;
                }
            }
        }
    }

    return 0;
}


/*
 * Aca se viene el analisis de movidas. Esta funcion realiza el siguiente trabajo.
 * Funcion principal:
 * 1. Chequea los parametros, de tal forma que no entre basura
 * 2. Limpia las movidas que se encuentren en la posicion
 * 3. Llamada a funcion interna reentrante
 *
 * Funcion estatica reentrante
 * 0. Controla la existencia de movidas prioritarias
 * 1. Verifica las piezas en el pozo e intenta una movida por cada tipo de pieza
 *    distinta que se halle en el pozo
 * 2. Verifica pieza por pieza en el tablero e intenta una movida por cada una
 *    de ellas
 * 3. Si se paso una pieza como parametro, ejecuta eso.
 *
 * Parametros:
 *   - tipo de analisis
 *   - color
 *   - tipo de movimiento: No obligatorio, solo se analizaran las reglas asociadas a ese tipo
 *   - pieza: No obligatorio, solo se analizaran las reglas asociadas a esa piea
 *
 * Retorna:
 *   cantidad de movidas encontradas
 **/

int        posicion_analiza_movidas( Posicion* pos, char tipoanalisis, int color, int tipomov, Pieza* pieza ){

    LOGPRINT( 6, "Ingreso a analisis movidas tipoanalisis = %d, color = %d, tipomov = %d", 
        tipoanalisis, color, tipomov );


    // 1. chequeo de parametros
    if( !color ){
        LOGPRINT( 1, "Color debe estar definido (%d)", color );
        return 0;
    };
    if(! ( ( tipoanalisis == ANALISIS_MOVIDA ) || 
           ( tipoanalisis == ANALISIS_PRIMER_MOVIDA ) ||
           ( tipoanalisis == ANALISIS_ATAQUE ) ) ){
        LOGPRINT( 1, "Tipo analisis incorrecto (%d)", tipoanalisis );
        return 0;
    }

    // 2. Limpiamos las movidas
    posicion_free_movidas( pos );

    // 3. Ingreso a funcion real.
    return  posicion_analiza_movidas_int( pos, tipoanalisis, color, tipomov, pieza );

}

static  int        posicion_analiza_movidas_int( Posicion* pos, char tipoanalisis, int color, int tipomov, Pieza* pieza ){

    // 0. Antes de nada, controlo la lista de tipos de movimientos prioritarios.
    //    de haberlos, ejecuto esos primero
    if( tipomov == 0 && TJCONTMOVP( pos->tjuego ) ){
        int i;
        for( i = 0; i < pos->tjuego->simbolos->entradas; i ++ ){
            Simbolo* s = (Simbolo*) pos->tjuego->simbolos->data[i];
            if( s->tipo != SIM_TIPOMOVP ) continue;
            int movs = posicion_analiza_movidas_int( pos, tipoanalisis, color, s->ref, pieza );
            if( movs > 0 ) return movs;
        }
    }

    // 1. Vamos por las piezas en pozo.
    if( !pieza ){
        int  i;
        Pieza* piezas_arr[1024];
        int    piezas_cnt = 0;
        for( i = 0; i < pos->piezas_count; i ++ ){
            Pieza* pp = &pos->piezas[i];
            if( pp->casillero != ENPOZO ) continue;
            if( pp->color != color ) continue;
            int j; int existe = 0;
            for( j = 0; j < piezas_cnt; j ++ ){
                if( pieza_equal( pp, piezas_arr[j] ) ){
                    existe = 1;
                    break;
                }
            }
            if( existe ) continue;
            LOGPRINT( 6, "Analizando reglas para pieza %s (%d) en POZO (%s)", 
                  pp->tpieza->nombre, pp->number, 
                  tipojuego_get_colorname( pos->tjuego, color ) );
            piezas_arr[piezas_cnt] = pp; piezas_cnt ++;
            int  c;
            for( c = 0; c < pos->tjuego->casilleros->entradas; c ++ ){
                Casillero* cas = (Casillero*) pos->tjuego->casilleros->data[c];
                
                int  r;
                for( r = 0; r < pp->tpieza->rules->entradas; r ++ ){
                    Regla*  regla = (Regla*) pp->tpieza->rules->data[r];
                    if( regla->tregla != DROP ) continue;
                    if( tipomov && tipomov != regla->tmov ) continue;
                    _list*  movs;
                    movs =  analizador_evalua_movidas( regla, pos, pp, cas, tipoanalisis, 
                                    regla->tmov, color );
                    if( movs ){
                        if( tipoanalisis != ANALISIS_ATAQUE ) posicion_descartar_por_jaques( pos, movs, color ) ;
                        posicion_add_movidas( pos, movs );
                        list_free( movs );
                        if( pos->movidas && pos->movidas->entradas > 0 && tipoanalisis == ANALISIS_PRIMER_MOVIDA ) return 1;
                    }
                }
            }
        }
    }

    // 2. Vamos por las piezas en el tablero
    if( !pieza ){
        int i;
        for( i = 0; i < pos->piezas_count; i ++ ){
            Pieza* pp = & pos->piezas[i];
            int  r;
            if( pp->casillero == ENPOZO ) continue;
            if( pp->casillero == ENCAPTURA ) continue;
            if( pp->color != color ) continue;
            LOGPRINT( 6, "Analizando reglas para pieza %s en %s (%s)", 
                  pp->tpieza->nombre, pp->casillero->nombre, 
                  tipojuego_get_colorname( pos->tjuego, color ) );
            for( r = 0; r < pp->tpieza->rules->entradas; r ++ ){
                Regla*  regla = (Regla*) pp->tpieza->rules->data[r];
                if( regla->tregla != MOVE ) continue;
                if( tipomov && tipomov != regla->tmov ) continue;
                _list*  movs;
                LOGPRINT( 7, "Regla %d", r );
                movs =  analizador_evalua_movidas( regla, pos, pp, pp->casillero, tipoanalisis, 
                                regla->tmov, color );
                if( movs ){
                    if( tipoanalisis != ANALISIS_ATAQUE ) posicion_descartar_por_jaques( pos, movs, color ) ;
                    posicion_add_movidas( pos, movs );
                    list_free( movs );
                    if( pos->movidas && pos->movidas->entradas > 0 && tipoanalisis == ANALISIS_PRIMER_MOVIDA ) return 1;
                    LOGPRINT( 7, "Regla %d %d entradas", r, movs->entradas );
                }
            }
        }
    }

    // 3. Esta es con la pieza pasada como parametro
    if( pieza  ){
        Pieza* pp = pieza;
        int  r;
        if( pp->casillero != ENPOZO && pp->casillero != ENCAPTURA ){
            for( r = 0; r < pp->tpieza->rules->entradas; r ++ ){
                Regla*  regla = (Regla*) pp->tpieza->rules->data[r];
                if( regla->tregla != MOVE ) continue;
                if( tipomov && tipomov != regla->tmov ) continue;
                _list*  movs;
                movs =  analizador_evalua_movidas( regla, pos, pp, pp->casillero, tipoanalisis, 
                                regla->tmov, color );
                if( movs ){
                    if( tipoanalisis != ANALISIS_ATAQUE ) posicion_descartar_por_jaques( pos, movs, color ) ;
                    posicion_add_movidas( pos, movs );
                    list_free( movs );
                    if( pos->movidas && pos->movidas->entradas > 0 && tipoanalisis == ANALISIS_PRIMER_MOVIDA ) return 1;
                }
            }
        }
    }


    if( pos->movidas ) return pos->movidas->entradas; else return 0;
}


/*
 * Funcion de analisis de finales.
 * De acuerdo a las condiciones establecidas en el final,
 * se analizará pieza por pieza o casillero por casillero
 * Para tateti, es necesario analizar pieza por pieza y verificar
 * que se cumpla la secuencia como corresponda
 * */

int        posicion_analiza_final( Posicion* pos, int  color_actual, int color_sig, char** resultado ){
    
    int  i;
    for( i = 0; i < pos->tjuego->rules->entradas; i ++ ){
        Regla*  rule = pos->tjuego->rules->data[i];
        int analizado = 0;
        if( rule->tregla != END ) continue;
        // analizamos casillero por casillero!
        if( rule->flags & RULEFLAG_DIRECCION ){
            analizado = 1;
            int  c;
            for( c = 0; c < pos->tjuego->casilleros->entradas ; c ++ ){
                Casillero* cas = (Casillero*)pos->tjuego->casilleros->data[c];
                int res = analizador_evalua_final( rule, pos, NULL, cas, color_actual, color_sig, resultado );
                if( res == STATUS_ERROR ) return FINAL_ENJUEGO;
                if( res == FINAL_EMPATE || res > 0 ) return res;
            }
        }
        if( rule->flags & RULEFLAG_PIEZAS ){
            analizado = 1;
            int p;
            for( p = 0; p < pos->piezas_count; p ++ ){
                Pieza* pieza = & pos->piezas[i];
                if( pieza->color != color_actual ) continue;
                int res = analizador_evalua_final( rule, pos, pieza, pieza->casillero, color_actual, color_sig, resultado );
                if( res == STATUS_ERROR ) return FINAL_ENJUEGO;
                if( res == FINAL_EMPATE || res > 0 ) return res;
            }
        }
        if( !analizado ){
            int res = analizador_evalua_final( rule, pos, NULL, NULL, color_actual, color_sig, resultado );
            if( res == STATUS_ERROR ) return FINAL_ENJUEGO;
            if( res == FINAL_EMPATE || res > 0 ) return res;
        }
    }
    return  FINAL_ENJUEGO;

}


/*
 * La duplicacion de la posicion es algo que hacemos todo el tiempo
 * la idea es generar una nueva posicion con todo listo como para
 * hacer otro analisis o lo que sea.
 * */

Posicion*   posicion_dup( Posicion* pos ){
    Posicion* pnew = posicion_new( pos->tjuego );
    posicion_copy( pnew, pos );
    return  pnew;
}


/*
 * Las posiciones son iguales si sus hash lo son
 *
 * */ 
int         posicion_equal( Posicion* pos1, Posicion* pos2 ){
    char* h1 = posicion_hash( pos1 );
    char* h2 = posicion_hash( pos2 );
    LOGPRINT( 6, "hash de posicion 1 %02x%02x%02x%02x-" "%02x%02x%02x%02x-" "%02x%02x%02x%02x-" "%02x%02x%02x%02x"
        ,(unsigned char)(pos1->hash[0])
        ,(unsigned char)(pos1->hash[1])
        ,(unsigned char)(pos1->hash[2])
        ,(unsigned char)(pos1->hash[3])
        ,(unsigned char)(pos1->hash[4])
        ,(unsigned char)(pos1->hash[5])
        ,(unsigned char)(pos1->hash[6])
        ,(unsigned char)(pos1->hash[7])
        ,(unsigned char)(pos1->hash[8])
        ,(unsigned char)(pos1->hash[9])
        ,(unsigned char)(pos1->hash[10])
        ,(unsigned char)(pos1->hash[11])
        ,(unsigned char)(pos1->hash[12])
        ,(unsigned char)(pos1->hash[13])
        ,(unsigned char)(pos1->hash[14])
        ,(unsigned char)(pos1->hash[15])
    );
    LOGPRINT( 6, "hash de posicion 2 %02x%02x%02x%02x-" "%02x%02x%02x%02x-" "%02x%02x%02x%02x-" "%02x%02x%02x%02x"
        ,(unsigned char)(pos2->hash[0])
        ,(unsigned char)(pos2->hash[1])
        ,(unsigned char)(pos2->hash[2])
        ,(unsigned char)(pos2->hash[3])
        ,(unsigned char)(pos2->hash[4])
        ,(unsigned char)(pos2->hash[5])
        ,(unsigned char)(pos2->hash[6])
        ,(unsigned char)(pos2->hash[7])
        ,(unsigned char)(pos2->hash[8])
        ,(unsigned char)(pos2->hash[9])
        ,(unsigned char)(pos2->hash[10])
        ,(unsigned char)(pos2->hash[11])
        ,(unsigned char)(pos2->hash[12])
        ,(unsigned char)(pos2->hash[13])
        ,(unsigned char)(pos2->hash[14])
        ,(unsigned char)(pos2->hash[15])
    );
    return memcmp( h1, h2, 16 ) == 0;
}

#if  CACHE_OCUPADO
static  void  posicion_generar_array_casilleros( Posicion* pos ){
    if( pos->casilleros_ocupados ) return;
    LOGPRINT( 6, "Generando arreglo de casilleros ocupados"  );
    pos->casilleros_ocupados = malloc( sizeof( int ) * pos->tjuego->casilleros->entradas );
    memset(  pos->casilleros_ocupados, 0, sizeof( int ) * pos->tjuego->casilleros->entradas );
    int i;
    for( i = 0; i < pos->piezas_count; i ++ ){
       Pieza* pieza = & pos->piezas[i];
       if( CASILLERO_VALIDO( pieza->casillero ) ){
           LOGPRINT( 7, "%s ==> %d ++", pieza->casillero->nombre, pieza->casillero->number  );
           pos->casilleros_ocupados[pieza->casillero->number] ++;
       }
    }
}
#endif


/*
 * Vamos a cambiar de lugar una pieza
 * */
void       posicion_mueve_pieza( Posicion* pos, Pieza* pieza, Casillero* destino ){
#if  CACHE_OCUPADO
    posicion_generar_array_casilleros( pos );
    if( CASILLERO_VALIDO( pieza->casillero ) ){
        pos->casilleros_ocupados[pieza->casillero->number] --;
        LOGPRINT( 7, "%s ==> %d --", pieza->casillero->nombre, pieza->casillero->number  );
    }
    if( CASILLERO_VALIDO( destino) ){
        pos->casilleros_ocupados[destino->number] ++;
        LOGPRINT( 7, "%s ==> %d ++ %s", destino->nombre, destino->number, pieza->tpieza->nombre  );
    }
#endif

    pos->flags &= (~POSICION_HASH_CALCULADO);
    pieza->casillero = destino;
    pieza->flags &= (~PIEZA_HASH_CALCULADO);
}
