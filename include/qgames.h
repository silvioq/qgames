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
#ifndef   QGAMES_H
#define   QGAMES_H  1


// Esta es la cantidad máxima de dimensiones
// que puede soportar el motor
#define   MAXDIMS   16


typedef   struct  StrTipojuego  Tipojuego;
typedef   struct  StrPosicion   Posicion;
typedef   struct  StrPartida    Partida;


Tipojuego*  qg_tipojuego_new( char* nombre );
Tipojuego*  qg_tipojuego_open( char* nombre );


const char* qg_path_games( ); 
void        qg_path_set( const char* );

int         qg_tipojuego_valido( Tipojuego* tj );
int         qg_tipojuego_add_tablero  ( Tipojuego* tj );
int         qg_tipojuego_genera_dimensiones( Tipojuego* tj, int dimc, char** dimv );
int         qg_tipojuego_add_casillero( Tipojuego* tj, char* casillero );
int         qg_tipojuego_add_direccion( Tipojuego* tj, char* direccion );
int         qg_tipojuego_add_direccion_rel( Tipojuego* tj, char* direccion, ... );
int         qg_tipojuego_add_direccion_arr( Tipojuego* tj, char* direccion, int* dirv );
int         qg_tipojuego_add_link  ( Tipojuego* tj, char* cas_ori, char* dir, char* cas_des );
int         qg_tipojuego_add_color ( Tipojuego* tj, char* color );
int         qg_tipojuego_set_control_repeticiones( Tipojuego* tj, int repeticiones );
int         qg_tipojuego_add_tipo_mov ( Tipojuego* tj, char* tipo_mov, int prioritario );
int         qg_tipojuego_add_tipopieza( Tipojuego* tj, char* tpieza    );
int         qg_tipojuego_add_tpieza_att( Tipojuego* tj, char* tpieza, char* att, int default_value );
int         qg_tipojuego_add_zona     ( Tipojuego* tj, char* zona      );
int         qg_tipojuego_add_cas_to_zona( Tipojuego* tj, char* cas, char* color, char* zona );
int         qg_tipojuego_add_simetria ( Tipojuego* tj, char* color, char* dir1, char* dir2 );
int         qg_tipojuego_add_secuencia( Tipojuego* tj, char* color, char* tipomov );
int         qg_tipojuego_add_secuencia_rep( Tipojuego* tj );

void        qg_tipojuego_kill_casillero( Tipojuego* tj, char* casillero );

#define     POZO     -1
#define     CAPTURA  -2
#define     SINCASILLERO   -3
#define     CASILLERO_POZO    ((char*)POZO)
#define     CASILLERO_CAPTURA ((char*)CAPTURA)
int         qg_tipojuego_add_pieza( Tipojuego* tj, char* tpieza, char* casillero, char* color );


#define   NOT_FOUND   -1
int         qg_tipojuego_get_casillero( Tipojuego* tj, char* cas );
int         qg_tipojuego_get_direccion( Tipojuego* tj, char* dir );
int         qg_tipojuego_get_tipopieza( Tipojuego* tj, char* tpieza );
int         qg_tipojuego_get_att      ( Tipojuego* tj, char* tpieza, char* att );
int         qg_tipojuego_get_zona     ( Tipojuego* tj, char* zona );
int         qg_tipojuego_get_color    ( Tipojuego* tj, char* color );
int         qg_tipojuego_get_tipomov  ( Tipojuego* tj, char* tipomov );


int         qg_tipojuego_get_casillero_bycell( Tipojuego* tj, char** casillero, int   pos[MAXDIMS] );
int         qg_tipojuego_get_cell_bycasillero( Tipojuego* tj, char* casillero,  int** pos );


/*
 * Informacion devuelta para el tipojuego
 * */
const char*  qg_tipojuego_get_nombre   ( Tipojuego* tj );
int          qg_tipojuego_get_dims( Tipojuego* tj );
const char*  qg_tipojuego_info_color( Tipojuego* tj, int color );
int          qg_tipojuego_info_color_rotado( Tipojuego* tj, int color );
const char*  qg_tipojuego_info_tpieza( Tipojuego* tj, int tpieza );
const char*  qg_tipojuego_info_casillero( Tipojuego* tj, int cas, int** pos );



/* 
 * Aca viene toda la parte de notacion
 * */
#define  NOTACION_ORIGEN            'o'
#define  NOTACION_MARCA             '-'
#define  NOTACION_CAPTURA           'x'
#define  NOTACION_DESTINO           'd'
#define  NOTACION_PIEZA             'p'
#define  NOTACION_MARCA_IFORIGEN    '?'
#define  NOTACION_SPACE             's'

void   qg_tipojuego_add_notacion_def( Tipojuego* tj, char elemento );
void   qg_tipojuego_add_notacion_rep( Tipojuego* tj, char elemento );
int    qg_tipojuego_add_notacion_tmov( Tipojuego* tj, char* tmov, char* notacion );
int    qg_tipojuego_add_notacion_tpieza( Tipojuego* tj, char* tpieza, char* color, char* abbr );
void   qg_tipojuego_set_notacion_marca( Tipojuego* tj, char* marca, char* captura );


/*
 * A partir de aqui, comenzamos con la definicion de la graficacion
 * del tipo de juego.
 * */
#define   BOARD_ACTUAL  -1
#define   STANDARD_GEM        1
#define   STANDARD_BISHOP     2
#define   STANDARD_KING       3
#define   STANDARD_KNIGHT     4
#define   STANDARD_PAWN       5
#define   STANDARD_QUEEN      6
#define   STANDARD_ROOK       7
#define   STANDARD_CHECKERS_PAWN  11
#define   STANDARD_CHECKERS_KING  12
#define   STANDARD_RECT       31
#define   STANDARD_FROM_PGN   1

#define   TYPE_CHECKERBOARD   1
#define   TYPE_INTERSECTIONS  2
#define   TYPE_GRID           3


int    qg_tipojuego_graph_tablero_std     ( Tipojuego* tj, int board_number, char graphtype, int width, int height, int forecolor, int backcolor );
int    qg_tipojuego_graph_tablero_cus     ( Tipojuego* tj, int board_number, char* file  );
int    qg_tipojuego_graph_tipopieza_std   ( Tipojuego* tj, char* tpieza, int stdimg, int width, int height, int forecolor );
int    qg_tipojuego_graph_tipopieza_cus   ( Tipojuego* tj, char* tpieza, char* color, char* file );
int    qg_tipojuego_graph_casillero_std   ( Tipojuego* tj, char* casillero, int resaltado, int color );
int    qg_tipojuego_graph_casillero_cus   ( Tipojuego* tj, char* casillero, char* file );
int    qg_tipojuego_graph_logofile     ( Tipojuego* tj, char* file );
int    qg_tipojuego_graph_logopgn      ( Tipojuego* tj, char* pgn  );

/*
 * Esta funcion establece el directorio por defecto donde estan las
 * imagenes de piezas por defecto
 * */
void   qgames_graph_image_dir( const char* imagedir );


/*
 * Estas funciones devuelven el PNG asociado a un elemento
 * En todos los casos, en caso de fallos, devolvera 0, sino, 
 * la cantidad de bytes.
 * Una vez utilizado, debe eliminarse los datos del elemento
 * png, mediante un free_pgn
 * Los flags, pueden tener GETPNG_ROTADO.
 *
 * */
int    qg_tipojuego_get_tablero_png( Tipojuego* tj, int board_number, int flags, 
                                          void** png, int* width, int* height );
int    qg_tipojuego_get_tpieza_png( Tipojuego* tj, const char* color, const char* tpieza, int flags, 
                                          void** png, int* width, int* height );
int    qg_tipojuego_get_logo( Tipojuego* tj, void** png, int* width, int* height );
void   qgames_free_png( void* );





/*
 * A partir de aca, comenzamos con la partida
 * */
Partida*    qg_tipojuego_create_partida( Tipojuego* tj, char* id );
void        qg_partida_free          ( Partida* par );

char*       qg_partida_id( Partida* par );
int         qg_partida_mover         ( Partida* par, int mov );
int         qg_partida_mover_notacion( Partida* par, char* mov );
int         qg_partida_mover_serie   ( Partida* par, char* serie );
int         qg_partida_mover_pgn     ( Partida* par, char* pgn );


#define   FINAL_EMPATE   0
#define   FINAL_ENJUEGO  -1
int         qg_partida_final         ( Partida* par, char** resultado );
const char* qg_partida_color         ( Partida* par );  // Color que mueve
int         qg_partida_es_continuacion( Partida* par );


/*
 * Estructura para acceso a los datos de la movida
 * */

typedef  struct {

    int     numero;
    char*   descripcion;
    char*   notacion;
    char*   pieza;
    char*   color;
    char*   origen;
    char*   destino;

    int     movida;
    char*   movida_pieza;
    char*   movida_origen;
    char*   movida_destino;
    char*   movida_color;
    int     movida_ref;

    int     captura;
    char*   captura_pieza;
    char*   captura_casillero;
    char*   captura_color;
    int     captura_ref;

    int     transforma;
    char*   transforma_pieza;
    char*   transforma_color;
    int     transforma_ref;

    int     crea;
    char*   crea_pieza;
    char*   crea_casillero;
    char*   crea_color;
    int     crea_ref;

    void*   movida_data;
}  Movdata;

/*
 * Esta serie de funciones permiten consultar las movidas posibles
 * */
int         qg_partida_movidas_analizadas( Partida* par );
int         qg_partida_movidas_count ( Partida* par );
void        qg_partida_movidas_posibles_ascii( Partida* par );
int         qg_partida_movida_valida ( Partida* par, char* notacion );

int         qg_partida_movdata_nextcap ( Partida* par, Movdata* movdata );
int         qg_partida_movdata_nextcrea( Partida* par, Movdata* movdata );
int         qg_partida_movdata_nextmov ( Partida* par, Movdata* movdata );
int         qg_partida_movdata_nexttran( Partida* par, Movdata* movdata );
int         qg_partida_movidas_data  ( Partida* par, int num, Movdata* data );

/*
 * Esta serie de funciones permiten consultar el estado actual
 * del tablero
 * */
void        qg_partida_tablero_ascii ( Partida* par );
int         qg_partida_tablero_count ( Partida* par, int movida );
int         qg_partida_tablero_countcap( Partida* par, int movida );
int         qg_partida_count_piezas    ( Partida* par, char* casillero, char* tipopieza );
int         qg_partida_tablero_data  ( Partida* par, int movida, int num, char** casillero, char** pieza, char** color );
int         qg_partida_tablero_datacap( Partida* par, int movida, int num, char** pieza, char** color );

/*
 * Acceso a los movimientos historicos
 * */
int         qg_partida_movhist_count( Partida* par );
int         qg_partida_movhist_data( Partida* par, int mov, Movdata* movdata );
int         qg_partida_movhist_data_movida    ( Partida* par, int nummov, Movdata* movdata );
int         qg_partida_movhist_data_captura   ( Partida* par, int numcap, Movdata* movdata );
int         qg_partida_movhist_data_transforma( Partida* par, int numtra, Movdata* movdata );
int         qg_partida_movhist_data_crea      ( Partida* par, int numcre, Movdata* movdata );

int         qg_partida_movhist_destino_count( Partida* par, int mov );
const char* qg_partida_movhist_destino      ( Partida* par, int mov, int dest );

char*       qg_partida_pgn( Partida* par ); // free luego!


int         qg_partida_dump( Partida* par, void** data, int* size );
Partida*    qg_partida_load( Tipojuego* tj, void* data, int size );
const char* qg_partida_load_tj( void* data, int size );

/*
 * Esta funcion devuelve la imagen de la partida
 * En caso de fallos, devolvera 0, sino, la cantidad de bytes.
 * Una vez utilizado, debe eliminarse los datos del elemento
 * png, mediante un free_pgn
 * El parametro flags indicara si la posicion debera dibujarse
 * en forma inversa (rotado para las negras), si hay highlight
 * de ultima movida y otras que iran aparenciendo
 * El parametro movida indica el numero de movida a controlar
 * En el caso que sea negativo, se contara desde atras hacia
 * adelante, siendo -1 la ultima
 * 
 * */
#define  LAST_MOVE  -1
#define  GETPNG_ROTADO                0x01
#define  GETPNG_HIGHLIGHT_GREEN       0x02
#define  GETPNG_HIGHLIGHT_BLUE        0x04
#define  GETPNG_HIGHLIGHT_RED         0x08
#define  GETPNG_HIGHLIGHTED(flag)   ( flag & ( GETPNG_HIGHLIGHT_GREEN | GETPNG_HIGHLIGHT_BLUE | GETPNG_HIGHLIGHT_RED ))
#define  GETPNG_HIGHLIGHT_YELLOW    ( GETPNG_HIGHLIGHT_GREEN | GETPNG_HIGHLIGHT_RED )
#define  GETPNG_PIEZA_CAPTURADA       0x10

int         qg_partida_get_png( Partida* par, int flags, int movida, void** png );



#endif
