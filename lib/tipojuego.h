/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  TIPOJUEGO_H
#define  TIPOJUEGO_H  1

#include  <qcode.h>

typedef   struct   StrNotacion  Notacion;
typedef   struct   StrRegla     Regla;

#define   JAQUEMATE    0x1
#define   TJJAQUEMATE(tj)  (tj->flags & JAQUEMATE)


typedef   struct   StrTipojuego {
    _list*       simbolos;
    _list*       tableros;
    _list*       casilleros;
    _list*       direcciones;
    int          tablero_actual;
    Notacion*    notacion;
    _list*       secuencias;
    int          secuencia_repeat;
    int          colores;
    int          tipomovs;         // Cantidad de tipos de movimiento
    _list*       tipo_piezas;
    char*        nombre;
    _list*       simetrias;
    int          zonas;
    _list*       defzonas;
    Posicion*    inicial;
    char         flags;

    _list*       rules;           // Aca van los finales
    Regla*       regla_actual;
    QCode*       qcode;
} _Tipojuego;

typedef   struct   StrTablero {
    Tipojuego*   tipojuego;
    int          numero;

    // Cantidad de dimensiones que tiene el tablero
    int          dimc;          
    _list*       dimensiones;
} Tablero  ;

typedef   struct   StrCasillero {
    char*       nombre;
    int         tablero;
    int         posicion[MAXDIMS];
    _list*      vinculos;
} Casillero;

typedef   struct   StrDireccion {
    char*        nombre;
    int          mov_relativo[MAXDIMS];
}  Direccion;

typedef   struct   StrVinculo {
    Casillero* origen;
    Direccion* direccion;
    Casillero* destino;
} Vinculo;



typedef   struct   StrTipopieza {
    char*       nombre;
    Tipojuego*  tipojuego;
    int         att_count;
    _list*      att_nombres;
    _list*      att_default;
    _list*      rules;
    char        flags;
} Tipopieza;

//
#define  RULEFLAG_JAQUEMATE   JAQUEMATE
#define  RULEFLAG_PIEZAS      0x2
#define  RULEFLAG_DIRECCION   0x4

typedef   struct  StrRegla {
    Tipopieza*  tpieza;
    int         tmov;
    char        tregla;
    int         flags;    // Flags para las reglas de finales. 
    int         label;
    int         pc;
} _Regla;

typedef   struct  StrNotacion{
    Tipojuego*   tjuego;
    char*        notacion;
    char*        repeticion;
    _list*       notacion_tpiezas;
    _list*       notacion_tmovs;

    // Marca de movida (separacion)
    char*        marca;

    // Marca de capturado (cuando hay captura)
    char*        captura;
} _Notacion;

typedef struct StrNotacionData {
    long valor;
    int  color;
    char* notacion;
} NotacionData;

typedef  struct  StrSimetria{
    int          color;
    Direccion*   dir1;
    Direccion*   dir2;
}  Simetria;

typedef  struct  StrSecuencia{
    int         color;
    int         tmov;
}  Secuencia;

typedef  struct  StrZonadef{
    int         zona;
    int         color;
    Casillero*  cas;
} Zonadef;



#define  GETCASILLERO(tj,nom)  ({ \
    int ret = tipojuego_get_casillero(tj,nom); \
    assert( ret != NOT_FOUND ); \
    ret; \
  })

#define  GETDIRECCION(tj,nom)  ({ \
    int ret = tipojuego_get_direccion(tj,nom); \
    assert( ret != NOT_FOUND ); \
    ret; \
  })

#define  GETTIPOPIEZA(tj,nom)  ({ \
    int ret = tipojuego_get_tipopieza(tj,nom); \
    assert( ret != NOT_FOUND ); \
    ret; \
  })


#define  GETCOLOR(tj,nom)  ({ \
    int ret = tipojuego_get_color(tj,nom); \
    assert( ret != NOT_FOUND ); \
    ret; \
  })

#define  GETTIPOMOV(tj,nom)  ({ \
    int ret = tipojuego_get_tipomov(tj,nom); \
    assert( ret != NOT_FOUND ); \
    ret; \
  })

#define  GETZONA(tj,nom)  ({ \
    int ret = tipojuego_get_zona(tj,nom); \
    assert( ret != NOT_FOUND ); \
    ret; \
  })

/* Funciones de acceso a datos de tipojuego */
Casillero*  tipojuego_get_casillero_by_num( Tipojuego* tj, int nro );
Casillero*  tipojuego_get_casillero_by_relpos( Tipojuego* tj, int tablero, int dims[MAXDIMS] );
char*       tipojuego_get_colorname( Tipojuego* tj, int color );
int         tipojuego_get_coloroponente( Tipojuego* tj, int color );

int         tipojuego_casillero_en_zona( Tipojuego* tj, Casillero* cas, int zona, int color );
Direccion*  tipojuego_dir_by_sym( Tipojuego*, Direccion* dir, int color );

#define     TIPOJUEGO_CAPTURAIMPLICITA(tj) 1

/* Funciones de manejo de tablero */
Tablero*   tablero_new( Tipojuego* tj, int numero );
void       tablero_genera_dimensiones( Tablero* tab, int dimc, char** dimv );





/* Funciones de manejo de direcciones */
#define    ENPOZO     ((Casillero*)POZO)
#define    ENCAPTURA  ((Casillero*)CAPTURA)
#define    OUTOFBOARD ((Casillero*)0)

#define    CASILLERO_VALIDO(cas) ( cas != ENPOZO && cas != ENCAPTURA && cas != OUTOFBOARD )

Casillero* casillero_new( char* cas, int tablero );
void       casillero_free( Casillero* cas );
void       casillero_add_vinculo( Casillero* ori, Direccion* dir, Casillero* des );
void       casillero_kill_vinculo( Casillero* ori,Direccion* dir, Casillero* des );
Vinculo*   casillero_busca_vinculo_pororigen( Casillero* ori, Direccion* dir );
Vinculo*   casillero_busca_vinculo_pordestino( Casillero* des, Direccion* dir );
int        casillero_posicion_establecida( Casillero* cas );

int        casillero_check_dims( Casillero* cas, int max_dims, int pos[MAXDIMS] );

Casillero* casillero_aplica_direccion( Casillero* cas, Direccion* dir );


Direccion* direccion_new( char* dir );

/* Tema vinculos */
Vinculo*   vinculo_new( Casillero* ori, Direccion* dir, Casillero* des );
void       tipojuego_genera_vinculos( Tipojuego* tj, Direccion* dir );

/* Tipos de pieza */
Tipopieza*  tipopieza_new( Tipojuego* tj, char* nombre );
void        tipopieza_add_att(Tipopieza* tp, char* att, int default_value );
int         tipopieza_get_att( Tipopieza* tp, char* att );


/* Temas de codigo */
void  code_initialize( QCode** qcode );
int   code_execute_rule( void* z, int pc );
Regla*  code_regla_actual( Tipojuego* tj );


#endif
