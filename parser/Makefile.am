# lib_LIBRARIES = libqgames-parser.a libpgn-parser.a
check_PROGRAMS = test-pgn test-symtable
noinst_LIBRARIES = libqgames-parser.a libpgn-parser.a

libqgames_parser_a_SOURCES = qgames_parser.y qgames_parser.h qgames_scanner.l symtable.c
libpgn_parser_a_SOURCES = pgn_scanner.l pgn_scanner.h

AM_YFLAGS = -d -v -p qgz
AM_LFLAGS = -Pqgz -olex.yy.c
AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/vm \
		-fPIC  \
  $(CFLAG_VISIBILITY) 
		

libpgn_parser_a_LFLAGS = -Ppgn -olex.yy.c


test_pgn_SOURCES = test-pgn.c
test_pgn_DEPENDENCIES = $(srcdir)/libpgn-parser.a
test_pgn_LDADD =        $(srcdir)/libpgn-parser.a

test_symtable_SOURCES = test-symtable.c symtable.c symtable.h ../common/list.c

TESTS = $(check_PROGRAMS)
