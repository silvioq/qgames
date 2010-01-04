bin_PROGRAMS = qgames

qasm_SOURCES = qgames.c qgames_parser.y  qgames_scanner.l
# qasm_LDADD = $(top_builddir)/src/libqcode.la
# qasm_DEPENDENCIES = $(top_builddir)/src/libqcode.la

qgames_scanner.l: qgames_parser.c qgames_parser.h
qgames.c: qgames_parser.c qgames_parser.h qgames_scanner.c

AM_YFLAGS = -d -p qgz
AM_LFLAGS = --prefix qgz -o lex.yy.c
# AM_CFLAGS = -I$(top_srcdir)/src


# TESTS_ENVIRONMENT = $(builddir)/qasm -vr
# TESTS = test/*.qasm
# 
# EXTRA_DIST = test/*.qasm
# 
