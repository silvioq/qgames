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

/*
 * Una posicion nueva!
 * */

Posicion*   posicion_new( Tipojuego* tpieza ){
  Posicion* pos;
  pos = ALLOC( sizeof( Posicion ) );
  memset( pos, 0, sizeof( Posicion ) );
  return  pos;
}

/*
 * Esta funcion es muy simple, pero es fundamental.
 * Solo agrega una pieza a la posicion.
 * */

void        posicion_add_pieza( Posicion* pos, Pieza* pie ){
  if( !pos->piezas ) pos->piezas = list_nueva( NULL );
  list_agrega( pos->piezas, pie );
}

/*
 * Aca se viene el analisis de movidas. Esta funcion realiza el siguiente trabajo.
 * 1. Chequea los parametros, de tal forma que no entre basura
 * 2. Limpia las movidas que se encuentren en la posicion
 * 3. Verifica las piezas en el pozo e intenta una movida por cada tipo de pieza
 *    distinta que se halle en el pozo
 * 4. Verifica pieza por pieza en el tablero e intenta una movida por cada una
 *    de ellas
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

int        posicion_analiza_movidas( Posicion* pos, int tipoanalisis, int color, int tipomov, Pieza* pieza ){

  // 1. chequeo de parametros
  assert( color > 0 );
  assert( ( tipoanalisis == ANALISIS_MOVIDA ) || 
          ( tipoanalisis == ANALISIS_PRIMER_MOVIDA ) ||
          ( tipoanalisis == ANALISIS_ATAQUE ) );


  return 0;
}
