bin_PROGRAMS = qgames

# qgames_SOURCES = qgames.c qgames_parser.y  qgames_scanner.l ../common/list.c  
qgames_SOURCES = qgames.c ../common/list.c  

DEPENDENCIES = \
										$(top_builddir)/parser/libqgames-parser.a \
                    $(top_builddir)/lib/libqgames.a \
									  $(top_builddir)/parser/libpgn-parser.a \
                    $(top_builddir)/vm/libqcode.a

qgames_DEPENDENCIES = $(DEPENDENCIES)
qgames_LDADD = $(DEPENDENCIES)

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/vm


TESTS_ENVIRONMENT = $(srcdir)/qgames 
TESTS = $(srcdir)/../games/*.qgame $(srcdir)/../games/pgn/*.pgn
# XFAIL_TESTS =  $(srcdir)/../games/Ajedrez.qgame  
EXTRA_DIST = $(srcdir)/games/*.qgame
