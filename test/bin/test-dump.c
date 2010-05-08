#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include <time.h>

#include <qgames.h>
#include <qgames_analyzer.h>


int  main(int argc, char** argv) {
    Tipojuego* ajedrez;
    Partida*  p1;
    char* filename = "../../games/Ajedrez.qgame";
    void* data;
    int   size;
    assert( ajedrez = qgz_parse_filename( filename, 0 ) );
    

    p1 = tipojuego_create_partida( ajedrez, "id" );
    assert( partida_dump( p1, &data, &size ));
    free( data );
    assert( size == 13 );

    assert( partida_mover_notacion( p1, "e4" ) );
    assert( partida_dump( p1, &data, &size ) );
    assert( size > 20 );
   

    free( data );
    partida_free( p1 ); 
    return 0;
}

