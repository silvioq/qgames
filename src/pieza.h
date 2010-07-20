/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  PIEZA_H
#define  PIEZA_H  1

#define  PIEZA_HASH_CALCULADO  0x01
#define  PIEZA_ATT_INIT        0x02

typedef  struct  StrPieza {
    Tipopieza*  tpieza;
    Casillero*  casillero;
    int         color;
    int         number;
    int         flags;
    char        hash[16];
    int         atts[TIPOPIEZA_MAXATT];
} Pieza;


void     pieza_init( Pieza* pieza, Tipopieza* tpieza, Casillero* cas, int color );
// void     pieza_copy( Pieza* pieza_dest, Pieza* pieza_ori );
#define  pieza_copy(pd,po)  memcpy(pd,po,sizeof(Pieza))
int      pieza_equal( Pieza* p1, Pieza* p2 );
char*    pieza_hash( Pieza* p1 );
int      pieza_set_att( Pieza* p, int att, int val );
int      pieza_get_att( Pieza* p, int att );
int      pieza_free_att( Pieza* p );


#endif
