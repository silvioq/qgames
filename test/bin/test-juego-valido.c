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
#include <qgames.h>
#include <qgames_analyzer.h>
#include "../vm/qgames_code_impl.h"

#include "log.h"


int  main(int argc, char** argv) {
    char *filename = "../../games/TaTeTi.qgame";
    Tipojuego * tateti, *tateti2;

    assert( tateti = qgz_parse_filename( filename, 0 ) );
    qg_path_set( TEST_GAMESDIR );
    assert( tateti2 = qg_tipojuego_open( "TaTeTi" ) );

    assert( qg_tipojuego_valido( tateti2 ) );
    assert( tipojuego_code_casillero( tateti2, "a1" ) );
    assert( qg_tipojuego_valido( tateti2 ) );
    assert( !tipojuego_code_casillero( tateti2, "a4" ) );
    assert( !qg_tipojuego_valido( tateti2 ) );

    return  EXIT_SUCCESS;
}
