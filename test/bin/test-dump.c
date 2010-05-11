#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include <time.h>
#include "log.h"

#include <qgames.h>
#include <qgames_analyzer.h>

void  control_igual_partida( Partida* p1, Partida* p2 ){
    int i;
    assert( partida_movidas_count( p1 ) == partida_movidas_count( p2 ) );
    // printf( "Las movidas son %d == %d\n", partida_movidas_count( p1 ), partida_movidas_count( p2 ) );
    for( i = 0; i < partida_movidas_count( p2 ); i ++ ){
        char* n1, *n2;
        partida_movidas_data( p1, i, &n1 );
        partida_movidas_data( p2, i, &n2 );
        assert( strcmp( n1, n2 ) == 0 );
    }

    assert( partida_tablero_count( p1 ) == partida_tablero_count( p2 ) );
    // printf( "Las piezas son %d == %d\n", partida_tablero_count( p1 ), partida_tablero_count( p2 ) );
    for( i = 0; i < partida_tablero_count( p2 ); i ++ ){
        char* cas1, *pie1, *col1;
        char* cas2, *pie2, *col2;
        partida_tablero_data( p1, i, &cas1, &pie1, &col1 );
        partida_tablero_data( p2, i, &cas2, &pie2, &col2 );
        assert( strcmp( cas1, cas2 ) == 0 );
        assert( strcmp( col1, col2 ) == 0 );
        assert( strcmp( pie1, pie2 ) == 0 );
    }
}


int  main(int argc, char** argv) {
    Tipojuego* ajedrez, *gomoku;
    Partida*  p1, *p2;
    char* filename = "../../games/Ajedrez.qgame";
    char* file2    = "../../games/Gomoku.qgame";
    int i;

    loglevel = 2;

    char* pgn = 
          "1. b4 e5 2. Bb2 Bxb4 3. Bxe5 Nf6 4. c4 Nc6 "
          "5. Bb2 d6 6. Nf3 0-0 7. e3 Bg4 8. Be2 Re8 "
          "9. 0-0 h6 10. Nc3 Ne5 11. Nxe5 Bxe2 12. Nxe2 dxe5 "
          "13. Rb1 Qxd2 14. Qxd2 Bxd2 15. Rf1-d1 Ba5 "
          "16. f3 Bb6 17. Kf2 Ra8-d8 18. Rxd8 Rxd8 19. Bxe5 Rd2 "
          "20. Rb2 Rd3 21. Bd4 Bxd4 22. Nxd4 c5 23. Nb5 a6 "
          "24. Ke2 Rd7 25. Nc3 Ne8 26. Ne4 Rc7 27. g4 Kf8 "
          "28. h4 Ke7 29. Rb6 f6 30. h5 Kd7 31. f4 Kc8 "
          "32. a4 Kd7 33. Kd3 Ke7 34. Ke2 Kf7 35. f5 Ke7 "
          "36. Kf3 Kd7 37. Rb1 Kc6 38. a5 Kd7 39. Rd1 Kc6 "
          "40. Rd8 Re7 41. Rd5 b6 42. axb6 Kxb6 43. Nxc5 Nc7 "
          "44. Na4 Kc6 45. Ra5 Re8 46. Nc3 Rd8 47. Ra1 Rd3 "
          "48. Ne2 Kc5 49. Ra4 Rd1 50. Nd4 Rb1 51. Ke4 Rb8 "
          "52. Kd3 Rd8 53. Kc3 Rb8 54. Ra5 Kb6 55. Ra2 Rc8 "
          "56. Rb2 Kc5 57. Rb7 Kd6 58. Kb4 Re8 59. c5 Kd5 "
          "60. Rxc7 Rxe3 61. Rd7 Ke5 62. c6 ";



    void* data;
    int   size;
    assert( ajedrez = qgz_parse_filename( filename, 0 ) );
    assert( gomoku  = qgz_parse_filename( file2   , 0 ) );
    

    p1 = tipojuego_create_partida( ajedrez, "id" );
    assert( partida_dump( p1, &data, &size ));
    free( data );
    assert( size == 40 );

    assert( partida_mover_notacion( p1, "e4" ) );
    assert( partida_dump( p1, &data, &size ) );
    assert( size > 60 );
    free( data );
    partida_free( p1 ); 

   
    p1 = tipojuego_create_partida( ajedrez, NULL );
    assert( partida_dump( p1, &data, &size ));
    assert( size > 60  );
    free( data );
    assert( partida_mover_pgn( p1, pgn ) );
    assert( partida_dump( p1, &data, &size ));
    // printf( "El tamaño es %d\n", size );
    assert( size == 4089 );

    assert( p2 = partida_load( ajedrez, data, size ) );
    assert( !partida_load( gomoku, data, size ) );
    assert( partida_movidas_count( p2 ) == 15 );
    assert( partida_movidas_count( p1 ) == 15 );
    control_igual_partida( p1, p2 );

    free( data );
    assert( partida_dump( p1, &data, &size ));
    // printf( "El tamaño es %d\n", size );
    assert( size == 4592 );
/*
    FILE* f = fopen( "x", "w" );
    fwrite( data, 1, size, f );
    fclose( f ); 
*/
    free( data );
    partida_free( p1 ); 
    return 0;
}

