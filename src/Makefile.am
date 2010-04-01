bin_PROGRAMS = qgames

# qgames_SOURCES = qgames.c qgames_parser.y  qgames_scanner.l ../common/list.c  
qgames_SOURCES = qgames.c ../common/list.c  

qgames_DEPENDENCIES = $(top_builddir)/qcode/src/libqcode.la $(top_builddir)/lib/libqgames.a \
										$(top_builddir)/parser/libqgames-parser.a $(top_builddir)/parser/libpgn-parser.a
qgames_LDADD = \
										$(top_builddir)/parser/libqgames-parser.a \
                    $(top_builddir)/lib/libqgames.a \
									  $(top_builddir)/parser/libpgn-parser.a \
                    $(top_builddir)/qcode/src/libqcode.la

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src


TESTS_ENVIRONMENT = $(srcdir)/qgames 
TESTS = $(top_builddir)/games/*.qgame
XFAIL_TESTS =  $(top_builddir)/games/Ajedrez.qgame
