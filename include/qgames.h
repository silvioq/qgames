/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef   QGAMES_H
#define   QGAMES_H  1


// Esta es la cantidad máxima de dimensiones
// que puede soportar el motor
#define   MAXDIMS   16


typedef   struct  StrTipojuego  Tipojuego;
typedef   struct  StrPosicion   Posicion;
typedef   struct  StrPartida    Partida;


Tipojuego*  tipojuego_new( char* nombre );
int         tipojuego_valido( Tipojuego* tj );
int         tipojuego_add_tablero  ( Tipojuego* tj );
int         tipojuego_genera_dimensiones( Tipojuego* tj, int dimc, char** dimv );
int         tipojuego_add_casillero( Tipojuego* tj, char* casillero );
int         tipojuego_add_direccion( Tipojuego* tj, char* direccion );
void        tipojuego_add_direccion_rel( Tipojuego* tj, char* direccion, ... );
void        tipojuego_add_direccion_arr( Tipojuego* tj, char* direccion, int* dirv );
int         tipojuego_add_link     ( Tipojuego* tj, char* cas_ori, char* dir, char* cas_des );
int         tipojuego_add_color    ( Tipojuego* tj, char* color );
int         tipojuego_add_tipo_mov ( Tipojuego* tj, char* tipo_mov );
int         tipojuego_add_tipopieza( Tipojuego* tj, char* tpieza    );
int         tipojuego_add_tpieza_att( Tipojuego* tj, char* tpieza, char* att, int default_value );
int         tipojuego_add_zona     ( Tipojuego* tj, char* zona      );
int         tipojuego_add_cas_to_zona( Tipojuego* tj, char* cas, char* color, char* zona );
int         tipojuego_add_simetria ( Tipojuego* tj, char* color, char* dir1, char* dir2 );
void        tipojuego_add_secuencia( Tipojuego* tj, char* color, char* tipomov );
void        tipojuego_add_secuencia_rep( Tipojuego* tj );

void        tipojuego_kill_casillero( Tipojuego* tj, char* casillero );

#define     POZO     -1
#define     CAPTURA  -2
#define     SINCASILLERO   -3
#define     CASILLERO_POZO    ((char*)POZO)
#define     CASILLERO_CAPTURA ((char*)CAPTURA)
void        tipojuego_add_pieza( Tipojuego* tj, char* tpieza, char* casillero, char* color );


#define   NOT_FOUND   -1
const char* tipojuego_get_nombre   ( Tipojuego* tj );
int         tipojuego_get_casillero( Tipojuego* tj, char* cas );
int         tipojuego_get_direccion( Tipojuego* tj, char* dir );
int         tipojuego_get_tipopieza( Tipojuego* tj, char* tpieza );
int         tipojuego_get_att      ( Tipojuego* tj, char* tpieza, char* att );
int         tipojuego_get_zona     ( Tipojuego* tj, char* zona );
int         tipojuego_get_color    ( Tipojuego* tj, char* color );
int         tipojuego_get_tipomov  ( Tipojuego* tj, char* tipomov );


int         tipojuego_get_dimensiones( Tipojuego* tj );
int         tipojuego_get_dimlen( Tipojuego* tj, int dim );
int         tipojuego_get_casillero_bycell( Tipojuego* tj, char** casillero, int   pos[MAXDIMS] );
int         tipojuego_get_cell_bycasillero( Tipojuego* tj, char* casillero,  int** pos );


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

void   tipojuego_add_notacion_def( Tipojuego* tj, char elemento );
void   tipojuego_add_notacion_rep( Tipojuego* tj, char elemento );
void   tipojuego_add_notacion_tmov( Tipojuego* tj, char* tmov, char* notacion );
void   tipojuego_add_notacion_tpieza( Tipojuego* tj, char* tpieza, char* color, char* abbr );
void   tipojuego_set_notacion_marca( Tipojuego* tj, char* marca, char* captura );


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

#define   TYPE_CHECKERBOARD   1
#define   TYPE_INTERSECTIONS  2
#define   TYPE_GRID           3


void   tipojuego_graph_tablero_std     ( Tipojuego* tj, int board_number, char graphtype, int width, int height, int forecolor, int backcolor );
void   tipojuego_graph_tablero_cus     ( Tipojuego* tj, int board_number, char* file  );
void   tipojuego_graph_tipopieza_std   ( Tipojuego* tj, char* tpieza, int stdimg, int width, int height );
void   tipojuego_graph_tipopieza_cus   ( Tipojuego* tj, char* tpieza, char* color, char* file );
void   tipojuego_graph_casillero_std   ( Tipojuego* tj, char* casillero, int resaltado, int color );
void   tipojuego_graph_casillero_cus   ( Tipojuego* tj, char* casillero, char* file );


/*
 * Estas funciones devuelven el PNG asociado a un elemento
 * En todos los casos, en caso de fallos, devolvera 0, sino, 
 * la cantidad de bytes.
 * Una vez utilizado, debe eliminarse los datos del elemento
 * png, mediante un free_pgn
 * Los flags, pueden tener GETPNG_ROTADO.
 *
 * */
int    tipojuego_get_tablero_png( Tipojuego* tj, int board_number, int flags, void** png );
int    tipojuego_get_tpieza_png( Tipojuego* tj, char* color, char* tpieza, void** png );
void   qgames_free_pgn( void* );





/*
 * A partir de aca, comenzamos con la partida
 * */
Partida*    tipojuego_create_partida( Tipojuego* tj, char* id );
char*       partida_id( Partida* par );

int         partida_mover         ( Partida* par, int mov );
int         partida_mover_notacion( Partida* par, char* mov );
int         partida_mover_serie   ( Partida* par, char* serie );
int         partida_mover_pgn     ( Partida* par, char* pgn );


#define   FINAL_EMPATE   0
#define   FINAL_ENJUEGO  -1
int         partida_final         ( Partida* par, char** resultado );
void        partida_free( Partida* par );

void        partida_movidas_posibles_ascii( Partida* par );
int         partida_movidas_count ( Partida* par );
int         partida_movidas_data  ( Partida* par, int num, char** notacion );
int         partida_movida_valida ( Partida* par, char* notacion );

void        partida_tablero_ascii ( Partida* par );
int         partida_tablero_count ( Partida* par );
int         partida_tablero_data  ( Partida* par, int num, char** casillero, char** pieza, char** color );

char*       partida_pgn( Partida* par ); // free luego!


int         partida_dump( Partida* par, void** data, int* size );
Partida*    partida_load( Tipojuego* tj, void* data, int size );

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

int         partida_get_png( Partida* par, int flags, int movida, void** png );



#endif
