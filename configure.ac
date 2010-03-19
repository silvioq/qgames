AC_INIT([qgames], [2.4.0])
AM_INIT_AUTOMAKE
AC_PROG_CC
AC_PROG_YACC
AC_PROG_LEX
AC_PROG_LIBTOOL
AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_HEADERS([config.h])     # not even really needed
AC_PROG_CC                        # or AC_PROG_CXX

AC_CONFIG_SUBDIRS([qcode])

AM_CONDITIONAL([QASM], [0])

AC_CONFIG_FILES(
  [Makefile
   qcode/Makefile
   qcode/src/Makefile
   lib/Makefile
   src/Makefile
   ])


AC_OUTPUT

