/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  POSICION_H
#define  POSICION_H  1

#define  POSICION_HASH_CALCULADO  0x01

typedef  struct  StrPosicion {
    Tipojuego*  tjuego;
    _list*      movidas;
    int         flags;
    Posicion*   pos_anterior;
    Movida*     mov_anterior;
    char        hash[16];

    Pieza*      piezas;
    int         piezas_count;
    int         piezas_alloc;

} _Posicion;


Posicion*   posicion_new( Tipojuego* tjuego );
void        posicion_init( Posicion* pos, Tipojuego* tjuego );
static inline Pieza*  posicion_add_pieza( Posicion* pos );
Posicion*   posicion_dup( Posicion* pos );
int         posicion_equal( Posicion* pos1, Posicion* pos2 );
void        posicion_free( Posicion* pos );
char*       posicion_hash( Posicion* pos );

#define    SIN_ANALISIS              0
#define    ANALISIS_MOVIDA           1
#define    ANALISIS_FINAL            2
#define    ANALISIS_PRIMER_MOVIDA    3
#define    ANALISIS_ATAQUE           4

int        posicion_analiza_movidas( Posicion* pos, char tipoanalisis, int color, int tipomov, Pieza* pieza );
int        posicion_analiza_final( Posicion* pos,  int  color_actual, int color_sig, char** resultado );
int        posicion_movidas_posibles( Posicion* pos );

/*
 * Funcion para detectar si alguna pieza esta en jaque
 * Si el tipopieza no se especifica, se toman todas las piezas
 * a las cuales se le puede hacer jaquemate
 * */
int        posicion_en_jaque( Posicion* pos, Tipopieza* tpieza, int color );
void       posicion_mueve_pieza( Posicion* pos, Pieza* pieza, Casillero* destino );
Pieza*     posicion_get_pieza( Posicion* pos, Pieza* pieza );

/* ---------------------------------------------------------------------------------------- */
void       posicion_add_movida( Posicion* pos, Movida* mov );
void       posicion_free_movidas( Posicion* pos );


/* ---------------------------------------------------------------------------------------- */
/*
 * Esta funcion es muy simple, pero es fundamental.
 * Solo agrega una pieza a la posicion.
 * Definimos la funcion como static inline para mejorar la performance
 * */
#define  PIEZAS_ALLOC 50
static inline Pieza*      posicion_add_pieza( Posicion* pos ){
  Pieza* pie;
  if( !pos->piezas ){
      pos->piezas = malloc( sizeof( Pieza ) * PIEZAS_ALLOC );
      pos->piezas_count = 0;
      pos->piezas_alloc = PIEZAS_ALLOC;
  } else if ( pos->piezas_count >= pos->piezas_alloc ){
      pos->piezas_alloc += PIEZAS_ALLOC;
      pos->piezas = realloc( pos->piezas, sizeof( Pieza ) * pos->piezas_alloc );
  }  
  pie = & pos->piezas[pos->piezas_count];
  pie->number = pos->piezas_count;
  pos->piezas_count ++;
  return pie;
}

/*
 * Copia de una posicion. Se copian los campos realmente necesarios
 * */
static inline void     posicion_copy( Posicion* pos_dest, Posicion* pos_ori ){
    pos_dest->tjuego       = pos_ori->tjuego;
    pos_dest->flags        = pos_ori->flags;
    pos_dest->pos_anterior = pos_ori->pos_anterior;
    pos_dest->mov_anterior = pos_ori->mov_anterior;
    pos_dest->piezas_count = pos_ori->piezas_count;
    pos_dest->piezas_alloc = pos_ori->piezas_alloc;
    pos_dest->piezas = malloc( sizeof( Pieza ) * pos_ori->piezas_alloc );
    memcpy( pos_dest->piezas, pos_ori->piezas, sizeof( Pieza ) * pos_ori->piezas_count );
    if( pos_ori->flags & POSICION_HASH_CALCULADO ) memcpy( pos_dest->hash, pos_ori->hash, 16 );

}

static  inline  void  posicion_free_data(Posicion* pos){
    if( pos->movidas ){
        posicion_free_movidas( pos );
        list_free( pos->movidas );
    }
    if( pos->piezas ) free( pos->piezas );
}

#endif
