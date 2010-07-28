
bin_PROGRAMS = qgames-ncurses qgames-console

qgames_ncurses_SOURCES = qgames-ncurses.c  
qgames_ncurses_LDFLAGS = -lmenu @CURSES_LIBS@ @GD_LIBS@ @PNG_LIBS@
qgames_ncurses_DEPENDENCIES = $(DEPENDENCIES) $(top_builddir)/parser/libpgn-parser.a
qgames_ncurses_LDADD = $(DEPENDENCIES) $(top_builddir)/parser/libpgn-parser.a

qgames_console_SOURCES = qgames-console.c
qgames_console_LDFLAGS = @GD_LIBS@ @PNG_LIBS@
qgames_console_DEPENDENCIES = $(DEPENDENCIES) $(top_builddir)/parser/libpgn-parser.a
qgames_console_LDADD = $(DEPENDENCIES) $(top_builddir)/parser/libpgn-parser.a

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/vm


