AC_INIT([qgames], [2.9.8], [silvioq@gmail.com])
AC_DEFINE([QG_MAJOR_VERSION],[2], Major version)
AC_DEFINE([QG_MINOR_VERSION],[9], Minor version)
AC_DEFINE([QG_REV_VERSION],  [8], Revision version)

AM_INIT_AUTOMAKE
AC_PROG_CC
AC_PROG_YACC
AC_PROG_LEX
AC_CONFIG_MACRO_DIR([m4])

LT_INIT([dlopen win32-dll])
AC_PROG_LIBTOOL
AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_HEADERS([config.h])     # not even really needed
AC_PROG_CC                        # or AC_PROG_CXX

AC_CHECK_LIB(readline,readline)
AC_CHECK_LIB(ncurses,initscr,[CURSES_LIBS="-lncurses"])
AC_CHECK_LIB(ncursesw,initscr,[CURSES_LIBS="-lncursesw"])
AC_CHECK_HEADERS([ncurses.h])

AC_CHECK_HEADERS([gd.h])
AC_CHECK_LIB(gd,gdImageCreate,[GD_LIBS="-lgd"],[
    echo  "--------------------------------------------"
    echo  "      Cuidado! no esta instalado GD"
    echo  "--------------------------------------------" ]
    )
AC_CHECK_HEADERS([png.h])
AC_CHECK_LIB(png,png_read_info,[PNG_LIBS="-lpng"])

gl_VISIBILITY
AC_SUBST([CFLAG_VISIBILITY],[-fvisibility=hidden])


AC_SUBST([CURSES_LIBS])
AC_SUBST([GD_LIBS])
AC_SUBST([PNG_LIBS])

AC_SUBST([gamesdir], ["\$(pkgdatadir)/games"])
AC_SUBST([imagesdir], ["\$(pkgdatadir)/images"])

if test x"${ac_cv_lib_png_png_read_info}" = xyes; then
    if  test x"${ac_cv_lib_gd_gdImageCreate}" = xyes; then
        AC_DEFINE([GRAPH_ENABLED], [1], Graficos habilitados)
    fi
fi

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
# AC_SUBST(DEPENDENCIES,["\$(top_builddir)/parser/libqgames-parser.a \
                    # \$(top_builddir)/lib/libqgames.a \
									  # \$(top_builddir)/parser/libpgn-parser.a \
                    # \$(top_builddir)/vm/libqcode.a"])
AC_SUBST(DEPENDENCIES,["\$(top_builddir)/lib/libqgames.la"])

AC_CONFIG_FILES(
  [Makefile
   vm/Makefile
   parser/Makefile
   src/Makefile
   lib/Makefile
   bin/Makefile
   test/Makefile
   test/bin/Makefile
   test/qgtest/Makefile
   tools/Makefile
   ])


AC_OUTPUT

