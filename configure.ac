AC_INIT([qgames], [2.9.0])
AM_INIT_AUTOMAKE
AC_PROG_CC
AC_PROG_YACC
AC_PROG_LEX
AC_PROG_LIBTOOL
AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_HEADERS([config.h])     # not even really needed
AC_PROG_CC                        # or AC_PROG_CXX

AC_CHECK_LIB(readline,readline)
AC_CHECK_LIB(ncurses,initscr,[CURSES_LIBS="-lncurses"])
AC_CHECK_LIB(ncursesw,initscr,[CURSES_LIBS="-lncursesw"])
AC_CHECK_HEADERS([ncurses.h])
AC_SUBST([CURSES_LIBS])

AM_CONDITIONAL([QASM], [0])

# 
# if test x"${ac_cv_lib_ncursesw_ncursesw}" = xyes; then
#    CURSES_LIBS="-lncursesw"
# else
#    if test x"${ac_cv_lib_ncurses_ncurses}" = xyes; then
#       CURSES_LIBS="-lncurses"
#    fi
# fi

# if test x"${ac_cv_lib_readline_readline}" = xno; then
  # AC_MSG_ERROR(libreadline not found)
# fi


AC_DEFINE([QGAMES_SERVERNAME],["qgames.com.ar"], ["Nombre del servidor a usar"])

AC_CONFIG_FILES(
  [Makefile
   lib/Makefile
   vm/Makefile
   parser/Makefile
   ifaces/Makefile
   test/Makefile
   test/bin/Makefile
   test/qgtest/Makefile
   ])


AC_OUTPUT

