
bin_PROGRAMS = qgames-ncurses qgames-console

qgames_ncurses_SOURCES = qgames-ncurses.c ../common/list.c  
qgames_ncurses_LDFLAGS = -lmenu @CURSES_LIBS@ @GD_LIBS@ @PNG_LIBS@
qgames_ncurses_DEPENDENCIES = $(DEPENDENCIES)
qgames_ncurses_LDADD = $(DEPENDENCIES)

qgames_console_SOURCES = qgames-console.c ../common/list.c  
qgames_console_LDFLAGS = @GD_LIBS@ @PNG_LIBS@
qgames_console_DEPENDENCIES = $(DEPENDENCIES)
qgames_console_LDADD = $(DEPENDENCIES)

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/vm


