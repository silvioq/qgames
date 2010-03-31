lib_LIBRARIES = libqgames-parser.a libpgn-parser.a

libqgames_parser_a_SOURCES = qgames_parser.y qgames_parser.h qgames_scanner.h qgames_scanner.l
libpgn_parser_a_SOURCES = pgn_scanner.l

AM_YFLAGS = -d -v -p qgz
AM_LFLAGS = --prefix qgz -o lex.yy.c
AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src

libpgn_parser_a_LFLAGS = --prefix pgn -o lex.yy.c
