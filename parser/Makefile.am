lib_LIBRARIES = libqgames-parser.a

libqgames_parser_a_SOURCES = qgames_parser.y qgames_parser.h qgames_scanner.h qgames_scanner.l

AM_YFLAGS = -d -v -p qgz
AM_LFLAGS = --prefix qgz -o lex.yy.c
AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src


