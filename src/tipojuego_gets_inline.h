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


/*
 * Funcion que devuelve el numero de color a partir
 * de su nombre
 * */
static inline int   tipojuego_get_color( Tipojuego* tj, char* color ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, color );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_COLOR ) return NOT_FOUND;
    return  sym->ref;
}

/*
 * Devuelve el numero de casillero.
 * En el caso de no ser encontrado, devuelve NOT_FOUND
 * */

static inline int    tipojuego_get_casillero( Tipojuego* tj, char* cas ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, cas );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_CASILLERO ) return NOT_FOUND;
    return  sym->ref;
}


/*
 * Devuelve el numero de tipo de pieza.
 * En el caso de no ser encontrado, devuelve NOT_FOUND
 * */
static inline int         tipojuego_get_tipopieza( Tipojuego* tj, char* tpieza ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, tpieza );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_TIPOPIEZA ) return NOT_FOUND;
    return  sym->ref;
}

/*
 * Devuelve el numero de la direccion
 * */
static inline int         tipojuego_get_direccion( Tipojuego* tj, char* dir ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, dir );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_DIRECCION ) return NOT_FOUND;
    return  sym->ref;
}

static inline int         tipojuego_get_att( Tipojuego* tj, char* tpieza, char* att ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, tpieza );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_TIPOPIEZA ) return NOT_FOUND;
    Tipopieza* x = (Tipopieza*) tj->tipo_piezas->data[sym->ref];
    return tipopieza_get_att( x, att );
}

/*
 * Devuelve el numero de zona de la lista.
 * Si no la encuentra, retorna NOT_FOUND
 * */
static inline int         tipojuego_get_zona     ( Tipojuego* tj, char* zona ){
    Simbolo*  sym;
    sym = tipojuego_get_simbolo( tj, zona );
    if( !sym ) return NOT_FOUND;
    if( sym->tipo != SIM_ZONA ) return NOT_FOUND;
    return  sym->ref;
}
