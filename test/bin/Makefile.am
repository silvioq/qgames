
check_PROGRAMS = test-tateti test-gomoku test-ajedrezq test-dump test-graph
test_tateti_SOURCES = test-tateti.c
test_gomoku_SOURCES = test-gomoku.c
test_ajedrezq_SOURCES = test-ajedrezq.c
test_dump_SOURCES = test-dump.c
test_graph_SOURCES = test-graph.c

test_tateti_DEPENDENCIES = $(DEPENDENCIES)
test_tateti_LDADD        = $(DEPENDENCIES)

test_ajedrezq_DEPENDENCIES = $(DEPENDENCIES)
test_ajedrezq_LDADD        = $(DEPENDENCIES)

test_gomoku_DEPENDENCIES = $(DEPENDENCIES) $(top_builddir)/parser/libpgn-parser.a
test_gomoku_LDADD        = $(DEPENDENCIES) $(top_builddir)/parser/libpgn-parser.a

test_dump_DEPENDENCIES = $(DEPENDENCIES)
test_dump_LDADD        = $(DEPENDENCIES)

test_graph_DEPENDENCIES = $(DEPENDENCIES)
test_graph_LDADD        = $(DEPENDENCIES)


AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src -DTEST_IMGDIR=\"$(top_srcdir)/images\"
AM_LDFLAGS      = @GD_LIBS@ @PNG_LIBS@
TESTS = $(check_PROGRAMS)
