
bin_PROGRAMS = qgames-ncurses

qgames_ncurses_SOURCES = qgames-ncurses.c ../common/list.c  

qgames_ncurses_LDFLAGS = -lmenu @CURSES_LIBS@

DEPENDENCIES = \
										$(top_builddir)/parser/libqgames-parser.a \
                    $(top_builddir)/lib/libqgames.a \
									  $(top_builddir)/parser/libpgn-parser.a \
                    $(top_builddir)/vm/libqcode.a

qgames_ncurses_DEPENDENCIES = $(DEPENDENCIES)
qgames_ncurses_LDADD = $(DEPENDENCIES)


AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/vm


