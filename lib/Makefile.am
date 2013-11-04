lib_LTLIBRARIES = libqgames.la

libqgames_la_SOURCES = ../common/list.c ../common/list.h \
								../common/md5.c ../common/md5.h \
								../common/log.c ../common/log.h \
								qgames.c qgames-posibles.c  qgames_analyzer.c

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/src -I$(top_srcdir)/vm 
	-fPIC \
  $(CFLAG_VISIBILITY) 

AM_LDFLAGS = @GD_LIBS@ @PNG_LIBS@

libqgames_la_LIBADD = \
      $(top_builddir)/parser/libpgn-parser.la \
      $(top_builddir)/parser/libqgames-parser.la \
      $(top_builddir)/src/libqgames-core.la \
      $(top_builddir)/vm/libqcode.la \
  @GD_LIBS@ @PNG_LIBS@
# 
#
libqgames_la_LDFLAGS = -version-info 2:9:0 -no-undefined
