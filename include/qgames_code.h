/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef   QGAMES_CODE_H
#define   QGAMES_CODE_H  1



/*
 * Toda esta parte es para definir el codigo
 * */


#define   DROP  'D'
#define   MOVE  'M'
#define   END   'E'
int         tipojuego_start_code(  Tipojuego* tj, char tiporegla, char* tipopieza, char* tipomov );
#define     tipojuego_start_codeend(tj) tipojuego_start_code( tj, END, NULL, NULL )
void        tipojuego_end_code( Tipojuego* tj );
void*       tipojuego_get_code( Tipojuego* tj );

void        tipojuego_code_start_condblock( Tipojuego* tj );
void        tipojuego_code_else_condblock( Tipojuego* tj );
void        tipojuego_code_end_condblock( Tipojuego* tj );
long        tipojuego_code_start_block( Tipojuego* tj );
void        tipojuego_code_end_block( Tipojuego* tj, long block );
void        tipojuego_code_break_block( Tipojuego* tj, long block );
void        tipojuego_code_continue_block( Tipojuego* tj, long block );

void        tipojuego_code_op_not( Tipojuego* tj );
void        tipojuego_code_op_equal( Tipojuego* tj, long val );
void        tipojuego_code_op_false( Tipojuego* tj );

int         tipojuego_code_direccion( Tipojuego* tj, char* direccion );
int         tipojuego_code_casillero( Tipojuego* tj, char* casillero );
int         tipojuego_code_setmarca ( Tipojuego* tj, int marca, char* casillero );
int         tipojuego_code_asigna_att( Tipojuego* tj, char* att, int val );
int         tipojuego_code_evalua_att( Tipojuego* tj, char* att );
int         tipojuego_code_juega  ( Tipojuego* tj, char* casillero, int captura );
int         tipojuego_code_captura( Tipojuego* tj, char* casillero );
int         tipojuego_code_transforma( Tipojuego* tj, int owner, char* color, char* tpieza );
void        tipojuego_code_para   ( Tipojuego* tj );

/*
 * fromto => Indica que tiene los parametros from y to
 * */
#define     FROM_AQUI                  0x10
#define     FROM_MARCA                 0x20
#define     FROM_CASILLERO             0x30
#define     FROM_MASK                  0xF0
#define     TO_AQUI                    0x01
#define     TO_MARCA                   0x02
#define     TO_CASILLERO               0x03 
#define     TO_MASK                    0x0F
int         tipojuego_code_mueve  ( Tipojuego* tj, char fromto_flags, void* from, void* to );

/* Definiciones para los dueños o colores */
#define   ENEMIGO       -1
#define   PROPIO        -2
#define   CUALQUIERA     0
#define   NOCOLOR        0
int         tipojuego_code_ahogado( Tipojuego* tj, char* color );
int         tipojuego_code_atacado( Tipojuego* tj, char* casillero );
int         tipojuego_code_destino_ant( Tipojuego* tj, char* casillero );
int         tipojuego_code_origen_ant( Tipojuego* tj, char* casillero );
int         tipojuego_code_cuenta_piezas( Tipojuego* tj, char* casillero, int owner, char* color, char* tpieza );
int         tipojuego_code_ocupado( Tipojuego* tj, char* casillero, int owner, char* color, char* tpieza );
int         tipojuego_code_entablero( Tipojuego* tj );
int         tipojuego_code_enzona ( Tipojuego* tj, char* zona, char* tpieza );
int         tipojuego_code_jaquemate( Tipojuego* tj, char* tpieza );

#define   ENJUEGO   0
#define   GANA      1
#define   PIERDE    2
#define   EMPATA    3
int         tipojuego_code_final  ( Tipojuego* tj, char* color, int resultado );




#endif
