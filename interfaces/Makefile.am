
bin_PROGRAMS = qgames-ncurses

qgames_ncurses_SOURCES = qgames-ncurses.c ../common/list.c  

qgames_ncurses_LDFLAGS = -lmenu @CURSES_LIBS@
qgames_ncurses_DEPENDENCIES = $(top_builddir)/qcode/src/libqcode.la $(top_builddir)/lib/libqgames.a \
										$(top_builddir)/parser/libqgames-parser.a $(top_builddir)/parser/libpgn-parser.a
qgames_ncurses_LDADD = \
										$(top_builddir)/parser/libqgames-parser.a \
                    $(top_builddir)/lib/libqgames.a \
									  $(top_builddir)/parser/libpgn-parser.a \
                    $(top_builddir)/qcode/src/libqcode.la

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src


