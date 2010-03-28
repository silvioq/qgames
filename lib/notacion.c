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
#include  "analizador.h"
#include  "posicion.h"
#include  "notacion.h"

char     notacion_default[] =  { NOTACION_ORIGEN, NOTACION_MARCA_IFORIGEN, NOTACION_DESTINO, 0 };
char     notacion_repetida[] = { NOTACION_ORIGEN, NOTACION_MARCA_IFORIGEN, NOTACION_DESTINO, 0 };

char*   notacion_resolver_tmov( Notacion* nott, int tmov );
char*   notacion_resolver_tpieza( Notacion* nott, Tipopieza* tpieza );
char*   notacion_resolver_mov( Notacion* nott, Movida* mov, char* def );

/*
 * Notacion:
 * La notacion implica nombrar cada movida posible para identificarla y
 * diferenciarla de las demas. 
 * La notacion por defecto es la siguiente
 * casillero origen - casillero destino
 * Para el caso puntual de las movidas que implican sacar una pieza del pozo
 * solo se mostrara el casillero destino.
 * Muy probablemente, la notacion implicara la posibilidad de repetir el 
 * nombre ... para ello se determina una opcion de repeticion
 * */

typedef struct StrNotacionData {
    long valor;
    char* notacion;
} NotacionData;


void    notacion_resolver_movidas( Tipojuego* tjuego, _list* movs, char* prefix ){
    char* def = ( tjuego->notacion && tjuego->notacion->notacion ? 
                    tjuego->notacion->notacion : notacion_default );
    char* rep = ( tjuego->notacion && tjuego->notacion->repeticion ? 
                    tjuego->notacion->repeticion : notacion_repetida );
    Movida* mmm;

    list_inicio( movs );
    while( mmm = list_siguiente( movs ) ){
        if( mmm->notacion ) continue;
        char*  nom = notacion_resolver_mov( tjuego->notacion, mmm, def );
        if( prefix ){
            char* data = ALLOC( strlen( nom ) + strlen( prefix ) + 3 );
            sprintf( data, "%s-%s", prefix, nom );
            free( nom );
            nom = data;
        }
        mmm->notacion = nom;
    }


}



char*   notacion_resolver_tmov( Notacion* nott, int tmov ){
    if( nott->notacion_tmovs && tmov ){
        int i;
        for( i = 0; i < nott->notacion_tmovs->entradas; i ++ ){
            NotacionData* dat = (NotacionData*) nott->notacion_tmovs->data[i];
            if( dat->valor == tmov ) return nott->notacion ;
        }
    }
    return NULL;
}

char*   notacion_resolver_tpieza( Notacion* nott, Tipopieza* tpieza){
    if( nott && nott->notacion_tpiezas && tpieza ){
        int i;
        for( i = 0; i < nott->notacion_tpiezas->entradas; i ++ ){
            NotacionData* dat = (NotacionData*) nott->notacion_tpiezas->data[i];
            if( dat->valor == (long)tpieza) return nott->notacion;
        }
    }
    return NULL;
}


/*
 * Estos son los defines que estan en qgames
#define  NOTACION_ORIGEN            'o'
#define  NOTACION_MARCA             '-'
#define  NOTACION_CAPTURA           'x'
#define  NOTACION_DESTINO           'd'
#define  NOTACION_PIEZA             'p'
#define  NOTACION_MARCA_IFORIGEN    '?'
#define  NOTACION_SPACE             's'
*/

char*   notacion_resolver_mov( Notacion* nott, Movida* mov, char* def ){
    assert( def );
    char*  ret = ALLOC( 1024 );
    *ret = 0;
    char*  defchar = def;
    while( *defchar ){
        Casillero* origen;
        Casillero* destino;
        Pieza*  pieza;
        switch( *defchar ){
            case  NOTACION_ORIGEN:
                origen = movida_casillero_origen( mov );
                if( CASILLERO_VALIDO( origen ) ) strcat( ret, origen->nombre );
                break;
            case  NOTACION_MARCA_IFORIGEN:
                origen = movida_casillero_origen( mov );
                if( !CASILLERO_VALIDO( origen ) ) break;
            case  NOTACION_MARCA:
                strcat( ret, "-" );
                break;
            case  NOTACION_CAPTURA:
                if( movida_es_captura( mov ) ) strcat( ret, "x" );
                break;  
            case  NOTACION_DESTINO:
                destino = movida_casillero_destino( mov );
                if( destino ) strcat( ret, destino->nombre );
                break;
            case  NOTACION_PIEZA:
                pieza = movida_pieza( mov );
                if( pieza ){
                    char* p = notacion_resolver_tpieza( nott, pieza->tpieza );
                    if( !p ) p = pieza->tpieza->nombre;
                    strcat( ret, p );
                }
                break;
            case  NOTACION_SPACE:
                strcat( ret, " " );
                break;
            default:
                assert( 0 );
        }
        defchar ++;
    }
    return  ret;


}
