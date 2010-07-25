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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include <time.h>
#include "log.h"

#include <qgames.h>
#include "config.h"
#include <qgames_analyzer.h>



int  main(int argc, char** argv) {
    Tipojuego* ajedrez;
    Partida*  p1, *p2;
    char* filename = "../../games/Ajedrez.qgame";
    int i;

    qgames_graph_image_dir( TEST_IMGDIR );

#if GRAPH_ENABLED

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



    int   size;
    void* datapng;

    assert( ajedrez = qgz_parse_filename( filename, 0 ) );
    

   
    p1 = tipojuego_create_partida( ajedrez, NULL );
    assert( partida_mover_pgn( p1, pgn ) );

    i = 0;
    while( size = partida_get_png( p1, GETPNG_HIGHLIGHT_RED, i, &datapng ) ){
        printf( "." );
        static char  filename[256];
        FILE* fpng;
        sprintf( filename, "../../tmp/ajedrez-sec-%04d.png", i );
        fpng = fopen( filename, "w" );
        assert( fwrite( datapng, size, 1, fpng ) );
        fclose( fpng ); 
        qgames_free_png( datapng );  
        i++;
    }
    assert( i == 62 * 2 );

    partida_free( p1 ); 
    puts( "" );
    return 0;

#else
    printf( "Graficos no habilitados\n" );
    return 0;
#endif

}

