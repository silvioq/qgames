bin_PROGRAMS = qgames

qgames_SOURCES = qgames.c qgames_parser.y  qgames_scanner.l ../common/list.c  \
								qgames_tjuego.c  \
								tipojuego.c  tipojuego.h  \
								tablero.c  casillero.c  vinculo.c  direccion.c   \
								tipopieza.c

qgames_DEPENDENCIES = $(top_builddir)/qcode/src/libqcode.la
qgames_LDADD = $(top_builddir)/qcode/src/libqcode.la

qgames_scanner.l: qgames_parser.c qgames_parser.h
qgames.c: qgames_parser.c qgames_parser.h qgames_scanner.c qgames_analyzer.h


AM_YFLAGS = -d -v -p qgz
AM_LFLAGS = --prefix qgz -o lex.yy.c
AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src


TESTS_ENVIRONMENT = $(srcdir)/qgames 
TESTS = $(top_builddir)/games/*.qgame
# 
# EXTRA_DIST = test/*.qasm
# 
