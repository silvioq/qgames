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
    qg_tipojuego_add_color( tj, "blanco" );
    assert( qg_tipojuego_valido( tj ) );
    qg_tipojuego_add_casillero( tj, "n" );
    assert( qg_tipojuego_valido( tj ) );
    qg_tipojuego_add_tipo_mov ( tj, "Tipo mov", 0 );
    qg_tipojuego_add_tipopieza( tj, "Gemagenerica" );
    assert( qg_tipojuego_valido( tj ) );
    assert( qg_tipojuego_add_tpieza_att( tj, "Gemagenerica", "att", 1 ) );
    assert( qg_tipojuego_valido( tj ) );

    assert( qg_tipojuego_add_pieza( tj, "Gemagenerica", "n", "blanco" ) );
    assert( qg_tipojuego_valido( tj ) );

    // error direccion
    qg_tipojuego_add_direccion( tj, "norte" );
    assert( !qg_tipojuego_valido( tj ) );

    // test de error de pieza
    assert( tj = qg_tipojuego_new( "Generico" ) );
    qg_tipojuego_add_color( tj, "blanco" );
    qg_tipojuego_add_casillero( tj, "x" );
    qg_tipojuego_add_tipopieza( tj, "Gemagenerica" );
    assert( qg_tipojuego_valido( tj ) );
    assert( qg_tipojuego_add_pieza( tj, "Gemagenerica", "x", "blanco" ) );
    assert( qg_tipojuego_valido( tj ) );
    assert( !qg_tipojuego_add_pieza( tj, "Gemagenerica", "xx", "blanco" ) );
    assert( !qg_tipojuego_valido( tj ) );

    // controlo posible error de atributo
    assert( tj = qg_tipojuego_new( "Generico" ) );
    qg_tipojuego_add_tipopieza( tj, "Gemagenerica" );
    assert( qg_tipojuego_valido( tj ) );
    assert( !qg_tipojuego_add_tpieza_att( tj, "Gemaquenoexiste", "att", 1 ) );
    assert( !qg_tipojuego_valido( tj ) );

    // controlo zonas
    assert( tj = qg_tipojuego_new( "Generico" ) );
    assert( qg_tipojuego_add_zona( tj, "zona" ) );
    qg_tipojuego_add_casillero( tj, "a1" );
    qg_tipojuego_add_casillero( tj, "a2" );
    qg_tipojuego_add_color( tj, "verde" );
    qg_tipojuego_add_color( tj, "negro" );
    assert( qg_tipojuego_valido( tj ) );
    assert( qg_tipojuego_add_cas_to_zona( tj, "a1", "verde", "zona" ) );
    assert( qg_tipojuego_valido( tj ) );

    assert( !qg_tipojuego_add_cas_to_zona( tj, "a1", "azul", "zona" ) );  // Falla por color
    assert( !qg_tipojuego_valido( tj ) );
 
    assert( tj = qg_tipojuego_new( "Generico" ) );
    assert( qg_tipojuego_add_zona( tj, "zona" ) );
    qg_tipojuego_add_casillero( tj, "a1" );
    qg_tipojuego_add_casillero( tj, "a2" );
    qg_tipojuego_add_color( tj, "verde" );
    qg_tipojuego_add_color( tj, "negro" );
    assert( qg_tipojuego_valido( tj ) );
    assert( qg_tipojuego_add_cas_to_zona( tj, "a1", "verde", "zona" ) );
    assert( qg_tipojuego_valido( tj ) );

    assert( !qg_tipojuego_add_cas_to_zona( tj, "a3", "negro", "zona" ) ); // Falla por casillero
    assert( !qg_tipojuego_valido( tj ) );

    // controlo secuencias
    assert( tj = qg_tipojuego_new( "Generico" ) );
    qg_tipojuego_add_casillero( tj, "a1" );
    qg_tipojuego_add_casillero( tj, "a2" );
    qg_tipojuego_add_color( tj, "verde" );
    qg_tipojuego_add_color( tj, "negro" );
    assert( qg_tipojuego_add_tipo_mov( tj, "tmov", 1 ) );
    assert( qg_tipojuego_add_secuencia( tj, "verde", NULL ) );
    assert( qg_tipojuego_add_secuencia( tj, "verde", "tmov" ) );
    assert( qg_tipojuego_add_secuencia( tj, "negro", NULL ) );
    assert( qg_tipojuego_add_secuencia( tj, "verde", "tmov" ) );
    assert( qg_tipojuego_add_secuencia_rep( tj ) );
    assert( qg_tipojuego_valido( tj ) );
    assert( !qg_tipojuego_add_secuencia( tj, "azul", NULL ) );
    assert( !qg_tipojuego_valido( tj ) );

    exit( EXIT_SUCCESS );

}


