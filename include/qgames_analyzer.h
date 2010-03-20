/*
 *
 * QGames. Procesador de archivos qgames.
 * Haga lo que quiera con el programa, pero no hay garantias
 * Silvio Quadri (c) 2009
 *
 * */

#ifndef  QGAMES_ANALYZER_H
#define  QGAMES_ANALYZER_H

#define  QGZ_DEBUG    1
#define  QGZ_VERBOSE  2


// 
//
/*
*/

Tipojuego*  qgz_parse_filename( char* filename, int flags );
Tipojuego*  qgz_parse_file    ( FILE* file, int flags );
Tipojuego*  qgz_parse_string  ( char* string, int flags );

#endif
