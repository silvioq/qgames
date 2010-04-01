
check_PROGRAMS = test-tateti
test_tateti_SOURCES = test-tateti.c


test_tateti_DEPENDENCIES = $(top_builddir)/qcode/src/libqcode.la $(top_builddir)/lib/libqgames.a \
										$(top_builddir)/parser/libqgames-parser.a $(top_builddir)/parser/libpgn-parser.a
test_tateti_LDADD = \
										$(top_builddir)/parser/libqgames-parser.a \
                    $(top_builddir)/lib/libqgames.a \
									  $(top_builddir)/parser/libpgn-parser.a \
                    $(top_builddir)/qcode/src/libqcode.la

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/qcode/src
TESTS = $(check_PROGRAMS)
