
check_PROGRAMS = test-tateti test-gomoku
test_tateti_SOURCES = test-tateti.c
test_gomoku_SOURCES = test-gomoku.c

DEPENDENCIES = \
										$(top_builddir)/parser/libqgames-parser.a \
                    $(top_builddir)/lib/libqgames.a \
									  $(top_builddir)/parser/libpgn-parser.a \
                    $(top_builddir)/qcode/src/libqcode.la

test_tateti_DEPENDENCIES = $(DEPENDENCIES)
test_tateti_LDADD        = $(DEPENDENCIES)

test_gomoku_DEPENDENCIES = $(DEPENDENCIES)
test_gomoku_LDADD        = $(DEPENDENCIES)

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src
TESTS = $(check_PROGRAMS)
