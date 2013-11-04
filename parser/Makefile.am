# lib_LTLIBRARIES = libqgames-parser.la libpgn-parser.la
check_PROGRAMS = test-pgn test-symtable
noinst_LTLIBRARIES = libqgames-parser.la libpgn-parser.la

libqgames_parser_la_SOURCES = qgames_parser.y qgames_parser.h qgames_scanner.l symtable.c
libpgn_parser_la_SOURCES = pgn_scanner.l pgn_scanner.h

AM_YFLAGS = -d -v -p qgz
AM_LFLAGS = -Pqgz -olex.yy.c
AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/vm \
		-fPIC  \
  $(CFLAG_VISIBILITY) 
		

libpgn_parser_la_LFLAGS = -Ppgn -olex.yy.c


test_pgn_SOURCES = test-pgn.c
test_pgn_DEPENDENCIES = $(srcdir)/libpgn-parser.la
test_pgn_LDADD =        $(srcdir)/libpgn-parser.la

test_symtable_SOURCES = test-symtable.c symtable.h ../common/list.c
test_symtable_LDADD =   $(srcdir)/libpgn-parser.la $(srcdir)/symtable.o

TESTS = $(check_PROGRAMS)
