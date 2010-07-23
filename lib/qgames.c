
#include <stdio.h>
#include <qgames.h>

Partida* x(){
    qgz_parse_filename();
    pgnscan_string();
    tipojuego_get_tablero_png(NULL,NULL,NULL,NULL);
    return tipojuego_create_partida( NULL, NULL );
}

