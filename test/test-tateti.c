/*
 *
 * QGames. Testeo del tateti!
 * Haga lo que quiera con el programa, pero no hay garantias
 * Silvio Quadri (c) 2009
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <qgames.h>
#include "<qgames_analyzer.h>"


int  main(int argc, char** argv) {
    int  ret;
    char *filename = "../games/TaTeTi.qgame";
    assert( ret = qgz_parse( NULL, filename, 0 ) );

    return  EXIT_SUCCESS;
}
