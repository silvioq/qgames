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

#include  <stdlib.h>
#include  <assert.h>
#include  <qgames.h>


int  main( int argc, char** argv ){
    Tipojuego* tj ;

    // Este test simple controla la no duplicidad de los casilleros
    assert( tj = qg_tipojuego_new( "Generico" ) );
    qg_tipojuego_add_casillero( tj, "a1" );
    assert( qg_tipojuego_valido( tj ) );
    qg_tipojuego_add_casillero( tj, "a1" );
    assert( !qg_tipojuego_valido( tj ) );
    
    // Este test simple controla la no duplicidad de las direcciones
    assert( tj = qg_tipojuego_new( "Generico" ) );
    qg_tipojuego_add_direccion( tj, "norte" );
    assert( qg_tipojuego_valido( tj ) );
    qg_tipojuego_add_casillero( tj, "n" );
    assert( qg_tipojuego_valido( tj ) );
    qg_tipojuego_add_direccion( tj, "norte" );
    assert( !qg_tipojuego_valido( tj ) );

    exit( EXIT_SUCCESS );

}


