
check_PROGRAMS = test-generic \
		test-tateti test-gomoku \
		test-ajedrezq test-dump \
		test-graph test-historial \
		test-logo \
		test-movidas-posibles-data \
		test-juego-valido

test_tateti_SOURCES = test-tateti.c
test_gomoku_SOURCES = test-gomoku.c
test_ajedrezq_SOURCES = test-ajedrezq.c
test_dump_SOURCES = test-dump.c
test_graph_SOURCES = test-graph.c
test_logo_SOURCES = test-logo.c
test_historial_SOURCES = test-historial.c
test_movidas_posibles_data_SOURCES = test-movidas-posibles-data.c
test_juego_valido_SOURCES = test-juego-valido.c

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

test_logo_DEPENDENCIES = $(DEPENDENCIES)
test_logo_LDADD        = $(DEPENDENCIES)

test_generic_DEPENDENCIES = $(DEPENDENCIES)
test_generic_LDADD        = $(DEPENDENCIES)

test_historial_DEPENDENCIES = $(DEPENDENCIES)
test_historial_LDADD        = $(DEPENDENCIES)

test_movidas_posibles_data_DEPENDENCIES = $(DEPENDENCIES)
test_movidas_posibles_data_LDADD        = $(DEPENDENCIES)

test_juego_valido_DEPENDENCIES = $(DEPENDENCIES)
test_juego_valido_LDADD        = $(DEPENDENCIES) $(top_builddir)/vm/libqcode.a $(top_builddir)/src/libqgames-core.a


AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src \
				-DTEST_IMGDIR=\"$(top_srcdir)/images\"  \
				-DTEST_GAMESDIR=\"$(top_srcdir)/games\"
AM_LDFLAGS      = @GD_LIBS@ @PNG_LIBS@
TESTS = $(check_PROGRAMS)
