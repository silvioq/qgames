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

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <unistd.h>
#include  <time.h>
#include  <assert.h>
#include  <config.h>
#include  <qgames.h>
#include  <qgames_analyzer.h>
#include  "log.h"
#include  "../parser/pgn_scanner.h"

#include  <locale.h>
#include  <ncurses.h>
#include  <menu.h>

Tipojuego* tj = NULL;
static int  tablero_h = 0;
static int  tablero_w = 0;
int  tiene_colores = 0;

void usage(char* prg){

    puts( "Uso:" );
    printf( "  %s [-vp] [filename.qgame | filename.pgn]\n", prg );
    exit( EXIT_FAILURE );
   
}

int isnumeric(char *str)
{
  while(*str)
  {
    if(!isdigit(*str))
      return 0;
    str++;
  }

  return 1;
}



void  inicializar_pantalla(){
/*
 *----------------------------------
 * */
    setlocale( LC_ALL, "" );
    initscr();

    if( has_colors() ){
        start_color();
        assume_default_colors(COLOR_WHITE, COLOR_BLUE);
        tiene_colores = 1;
    } else tiene_colores = 0;

    cbreak();       /* take input chars one at a time, no wait for \n */
    noecho();
    keypad(stdscr, TRUE); 
    curs_set( 0 );


    refresh();
    
 
}


void  finalizar_pantalla( ){
    clear();
    refresh();
    endwin();
}


void borrar_win(WINDOW *local_win)
{
        // wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
        wclear( local_win );
        wrefresh(local_win);
        delwin(local_win);
}



int  imprimir_tablero( Partida* par, int linea ){
    static WINDOW*  tablerito = NULL;

    int dim[MAXDIMS];

    if( !tablero_h ){
        dim[0] = 0;
        dim[1] = 0;
        while( qg_tipojuego_get_casillero_bycell( tj, NULL, dim ) ){
            dim[1] = ++tablero_h;
        }
    }
    if( !tablero_w ){
        dim[0] = 0;
        dim[1] = 0;
        while( qg_tipojuego_get_casillero_bycell( tj, NULL, dim ) ){
            dim[0] = ++tablero_w;
        }
    }

    if( tablerito ) borrar_win( tablerito );
    assert( tablerito = newwin( tablero_h + 2, tablero_w + 2, linea, 0 ) );
    box( tablerito, 0, 0 );

    int  pie;
    char* pieza, * casillero, *color;
    pie = 0;

    while( qg_partida_tablero_data( par, LAST_MOVE, pie, &casillero, &pieza, &color ) ){
        int*  dim;
        assert( qg_tipojuego_get_cell_bycasillero( tj, casillero, &dim ) );
        if( color[0] == 'b' ){
            wattron( tablerito, A_BOLD );
        } else {
            wattroff( tablerito, A_BOLD );
        }
        mvwaddch( tablerito, tablero_h - dim[1], dim[0] + 1, pieza[0] );
        pie ++;
    }
    wrefresh( tablerito );
    return  tablero_w; 

}


char*  seleccionar_menu( Partida* par, int linea, int col ){

    ITEM ** items;
    MENU*   menu;
    WINDOW* menuwin;
    int cant = qg_partida_movidas_count( par );
    int i;
    char* ret;
    int  srow, scol;

    items = malloc( sizeof( ITEM ) * ( cant + 1 ) );
    for( i = 0; i < cant; i ++ ){
        Movdata  movd;
        assert( qg_partida_movidas_data( par, i, &movd ) );
        items[i] = new_item( strdup( movd.notacion ), NULL );
    }
    items[i] = NULL;
    menu = new_menu( items );
    set_menu_format( menu, 13, 3 );

    scale_menu( menu, &srow, &scol );

    menuwin = newwin( srow + 2, scol + 2, linea, col );
    set_menu_win( menu, menuwin );
    set_menu_sub( menu, derwin( menuwin, srow, scol, 1, 1 ) );
    menu_opts_off( menu, O_SHOWDESC );
    box( menuwin, 0, 0 );
    keypad(menuwin, TRUE);

    post_menu( menu );

    ITEM* selected = NULL;

    while(!selected){
        wrefresh( menuwin );
        switch( getch() ){
            case  27:
                selected = (ITEM*)-1;
                break;
            case KEY_DOWN:
                menu_driver(menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(menu, REQ_UP_ITEM);
                break;
            case KEY_LEFT:
                menu_driver(menu, REQ_LEFT_ITEM);
                break;
            case KEY_RIGHT:
                menu_driver(menu, REQ_RIGHT_ITEM);
                break;
            case KEY_NPAGE:
                menu_driver(menu, REQ_SCR_DPAGE);
                break;
            case KEY_PPAGE:
                menu_driver(menu, REQ_SCR_UPAGE);
                break;
            case 10:
                selected = current_item(menu);
                break;
        }
    }

    if( selected != (ITEM*)-1 ){
        ret = strdup( item_name(selected ) );
    } else {
        ret = NULL;
    }

    for( i = 0; i < cant; i ++ ){
        free( (void*)item_name(items[i]) );
        free( items[i] );
    }
    unpost_menu( menu );
    free_menu( menu );
    borrar_win( menuwin );

    return ret;
}



void  jugar_partida(Partida* par){

    inicializar_pantalla();
    int w = imprimir_tablero( par, 1 );
    int  ch;
    char* xx;
    char* res = NULL;

    while(xx = seleccionar_menu(par,1,w + 3)){
        qg_partida_mover_notacion( par, xx );
        
        free( xx );
        imprimir_tablero( par, 1 );
        if( qg_partida_final( par, &res ) != FINAL_ENJUEGO ) break;
    }

    if( res ){
        int len = strlen( res );
        WINDOW* w = newwin( 3 , len + 2, LINES / 2 - 1, ( COLS - len ) / 2 - 1 );
        box( w, 0, 0 );
        mvwprintw( w, 1, 1, res );
        wrefresh( w );
        while( getch() != 27 ){
        }
        borrar_win( w );
    }
    finalizar_pantalla();
    printf( "%s", qg_partida_pgn( par ) );
    printf( "\n" );
};


Partida*  procesar_partida( char* m, char* filename ){
    clock_t  inicio, final;
    int ret;
    inicio = clock();
    Partida* par = qg_tipojuego_create_partida( tj, NULL );
    if( !m ) return  par;
    ret = qg_partida_mover_serie( par, m );
    final = clock();
    LOGPRINT( 5, "Total %s: %.6f", filename, ((double) (final - inicio)) / CLOCKS_PER_SEC );
    if( !ret ){ qg_partida_free( par ); return NULL ; }
    return  par;
}



Partida*  check_game(char* pgnfile, int flags){
    Partida* par;
    int  ret;
    char filename[256];
    char* res;
    int  abandonado = 0;
    int  esperado = 0;
    int  result;

    if( !pgntag_variant ){
        printf( "No definida la variante\n" );
        return 0;
    }
    sprintf( filename, "../games/%s.qgame", pgntag_variant );
    tj = qgz_parse_filename( filename, flags );
    if( !tj ){
        LOGPRINT( 2, "Error al analizar %s", filename );
        return NULL;
    }
    LOGPRINT( 5, "Analisis de tipojuego completo %s", pgntag_variant );
    if( pgntag_result ){
        LOGPRINT( 5, "Resultado esperado : %s", pgntag_result );
    }

    if( pgntag_termination ){
        abandonado = 1;
    }  

    par =  procesar_partida( pgnmoves, pgnfile );

    if( !par ){
        LOGPRINT( 2, "Error al analizar partida %s", pgnmoves );
        return 0;
    }
    ret = 1;

    if( !pgntag_result ){
        esperado = FINAL_ENJUEGO;
    } else if( strcmp( pgntag_result, "1-0" ) == 0 ){
        esperado = 1;
    } else if ( strcmp( pgntag_result, "0-1" ) == 0 ){
        esperado = 2;
    } else if ( strcmp( pgntag_result, "1/2-1/2" ) == 0 ){
        esperado = FINAL_EMPATE;
    } else if ( strcmp( pgntag_result, "*" ) == 0 ){
        esperado = FINAL_ENJUEGO;
    } else {
        LOGPRINT( 2, "Resultado esperado incorrecto %s", pgntag_result );
        qg_partida_free( par );
        return 0;
    }

    result = qg_partida_final( par, &res );
    if( abandonado && ( result != FINAL_ENJUEGO )  ){
        LOGPRINT( 2, "Resultado con error => %d (term:%s res:%s)", result, pgntag_termination, pgntag_result );
        ret = 0;
    } else if( abandonado ){
        LOGPRINT( 5, "Partida abandonada: %s (term:%s)", (res ? res : "En juego" ), pgntag_termination );
        ret = 1;
    } else if( result != esperado ){
        LOGPRINT( 2, "Resultado con error => %d (%s) (espera:%d res:%s)", result, res, esperado, pgntag_result );
        ret = 0;
    } else {
        LOGPRINT( 5, "Resultado: %s", (res ? res : "En juego" ) );
        ret = 1;
    }
       
    if( ret ) return par;
    else { 
        qg_partida_free( par );
        return NULL;
    }
    
}


int  main(int argc, char** argv) {
    int  opt = 0, ret;
    int  forzar_pgn = 0;
    int  flags = 0;
    loglevel = 3;
    Partida*  par = NULL;

    while(( opt = getopt( argc, argv, "hpv" )) != -1 ){
        switch(opt){
            case 'v':
                flags |= QGZ_VERBOSE;
                loglevel = 5;
                break;
            case 'p':
                forzar_pgn = 1;
                break;
            default:
                usage(argv[0]);
        }
    }


    if( optind == argc ){
        if( forzar_pgn ){
            ret = pgnscan_file( stdin );
            if( !ret ){
                fprintf( stderr, "Error al procesar PGN: %s\n", pgnerror );
                exit( EXIT_FAILURE ) ;
            }
            par = check_game( "-", flags );
            if( par ) ret = 1; else ret = 0;
        } else {
            ret = (int)(long)qgz_parse_file( stdin, flags );
        }
    } else {
        char* filename = argv[optind];
        if( flags & QGZ_VERBOSE ) printf( "Abriendo %s\n", filename );
        ret = pgnscan_fname( filename );
        if( !ret ){
            tj = qgz_parse_filename( filename, flags );
            ret = tj ? 1 : 0;
        } else {
            par = check_game( filename, flags );
            if( par ) ret = 1; else ret = 0;
        }
    }

    if( ret && tj && !par ) par = qg_tipojuego_create_partida( tj, NULL );

    if( ret && par ){
        jugar_partida(par);
    }
    if( par )    qg_partida_free( par );

    if( ret ) return EXIT_SUCCESS; else return EXIT_FAILURE;
}
