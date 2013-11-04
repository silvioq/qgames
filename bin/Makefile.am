
bin_PROGRAMS = qgames-ncurses qgames-console

qgames_ncurses_SOURCES = qgames-ncurses.c
qgames_ncurses_DEPENDENCIES = $(top_builddir)/parser/libpgn-parser.la $(DEPENDENCIES)
qgames_ncurses_LDADD = $(top_builddir)/parser/libpgn-parser.la $(DEPENDENCIES) -lmenu @GD_LIBS@ @PNG_LIBS@

qgames_console_SOURCES = qgames-console.c
qgames_console_DEPENDENCIES = $(DEPENDENCIES) $(top_builddir)/parser/libpgn-parser.la
qgames_console_LDADD = $(top_builddir)/parser/libpgn-parser.la $(DEPENDENCIES) @GD_LIBS@ @PNG_LIBS@

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/vm

