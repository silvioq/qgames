
check_PROGRAMS = test-qgames
test_qgames_SOURCES = test-qgames.c test-qgames-scanner.l

test_qgames_DEPENDENCIES = @DEPENDENCIES@
test_qgames_LDADD        = @DEPENDENCIES@

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src
TESTS = *.qgtest
TESTS_ENVIRONMENT=$(srcdir)/test-qgames
EXTRA_DIST=*.qgtest
