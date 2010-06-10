lib_LIBRARIES = libqgames.a

libqgames_a_SOURCES = ../common/list.c ../common/list.h \
							  ../common/md5.c ../common/md5.h \
							  ../common/log.c ../common/log.h \
								tipojuego.c  tipojuego.h  simbolos.h \
                graph.c   graphdef.h  \
								tablero.c  casillero.c  vinculo.c  direccion.c   tipopieza.c   \
								notacion.c  notacion.h \
								pieza.c    pieza.h \
                movida.c   movida.h  \
                posicion.c  posicion.h  \
								analizador.c   analizador.h \
								partida.c    partida.h

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/vm -DDATADIR='"$(datadir)"' -DIMGDIR='"$(imagesdir)"'


