
check_PROGRAMS = test-tateti test-gomoku test-ajedrezq test-dump
test_tateti_SOURCES = test-tateti.c
test_gomoku_SOURCES = test-gomoku.c
test_ajedrezq_SOURCES = test-ajedrezq.c
test_dump_SOURCES = test-dump.c

test_tateti_DEPENDENCIES = $(DEPENDENCIES)
test_tateti_LDADD        = $(DEPENDENCIES)

test_ajedrezq_DEPENDENCIES = $(DEPENDENCIES)
test_ajedrezq_LDADD        = $(DEPENDENCIES)
test_ajedrezq_LDFLAGS      = @GD_LIBS@ @PNG_LIBS@

test_gomoku_DEPENDENCIES = $(DEPENDENCIES)
test_gomoku_LDADD        = $(DEPENDENCIES)
test_gomoku_LDFLAGS      = @GD_LIBS@ @PNG_LIBS@

test_dump_DEPENDENCIES = $(DEPENDENCIES)
test_dump_LDADD        = $(DEPENDENCIES)

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src
TESTS = $(check_PROGRAMS)
