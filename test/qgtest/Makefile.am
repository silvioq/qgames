
check_PROGRAMS = test-qgames
test_qgames_SOURCES = test-qgames.c test-qgames-scanner.l

test_qgames_DEPENDENCIES = @DEPENDENCIES@
test_qgames_LDADD        = @DEPENDENCIES@ @GD_LIBS@ @PNG_LIBS@

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src \
				-DTEST_GAMESDIR=\"$(top_srcdir)/games\"
TESTS = $(srcdir)/pass/*.qgtest
TESTS_ENVIRONMENT=$(srcdir)/test-qgames
EXTRA_DIST= $(srcdir)/pass/*.qgtest
