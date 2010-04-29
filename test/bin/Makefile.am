
check_PROGRAMS = test-tateti test-gomoku test-ajedrezq
test_tateti_SOURCES = test-tateti.c
test_gomoku_SOURCES = test-gomoku.c
test_ajedrezq_SOURCES = test-ajedrezq.c

DEPENDENCIES = \
										$(top_builddir)/parser/libqgames-parser.a \
                    $(top_builddir)/lib/libqgames.a \
									  $(top_builddir)/parser/libpgn-parser.a \
                    $(top_builddir)/vm/libqcode.a

test_tateti_DEPENDENCIES = $(DEPENDENCIES)
test_tateti_LDADD        = $(DEPENDENCIES)

test_ajedrezq_DEPENDENCIES = $(DEPENDENCIES)
test_ajedrezq_LDADD      = $(DEPENDENCIES)

test_gomoku_DEPENDENCIES = $(DEPENDENCIES)
test_gomoku_LDADD        = $(DEPENDENCIES)

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src
TESTS = $(check_PROGRAMS)
