noinst_LIBRARIES = libqgames-core.a

libqgames_core_a_SOURCES =  \
								tipojuego.c  tipojuego.h  simbolos.h tipojuego_gets_inline.h \
                graph.c   graphdef.h  \
								tablero.c  casillero.c  vinculo.c  direccion.c   tipopieza.c   \
								notacion.c  notacion.h \
								pieza.c    pieza.h \
                movida.c   movida.h  \
                posicion.c  posicion.h  \
								analizador.c   analizador.h \
								partida.c    

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common -I$(top_srcdir)/vm \
	-DDATADIR='"$(datadir)"' -DIMGDIR='"$(imagesdir)"' -DGAMESDIR='"$(gamesdir)"'\
	-fPIC \
	$(CFLAG_VISIBILITY) 

