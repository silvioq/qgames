
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

void DLL_LOCAL x(){
    qgz_parse_filename();
    pgnscan_string();
    tipojuego_get_tablero_png(NULL,NULL,NULL,NULL);
}

/*  
 * El inicio de todo tipo juego es su creación ... algo muy sencillo
 * por cierto.
 * Hay que crear la tabla de simbolos, agregar el nombre y no mucho más
 * por el momento
 * */
DLL_PUBLIC Tipojuego*   qg_tipojuego_new( char* nombre ){
    return tipojuego_new( nombre );
}

DLL_PUBLIC Partida*     qg_tipojuego_create_partida( Tipojuego* tj, char* id ){
   return  partida_new( tj, id );
}

DLL_PUBLIC int          qg_partida_mover_serie   ( Partida* par, char* serie ){
   return  partida_mover_serie ( par, serie );
}
