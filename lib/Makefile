CC=gcc
AR=ar
CFLAGS=-I./include
LFLAGS=
D_LIBS=libsos.a libsos.so
LIB_OBJS=

include src/Makefile.am
SRC_C=$(SRCS)
SRC_O=$(SRCS:.c=.o)

libsos.a:${SRC_O}
	${AR} -rs $@ $^

libsos.so:${SRC_O}
	${CC} -shared -o $@ $^ ${LFLAGS}

$(SRC_O):src/${SRC_C}
	${CC} -c $< ${CFLAGS}

libs:${D_LIBS}

all:libs

.PHONY:clean all

clean:
	rm -f *.o
	rm -f ${D_LIBS}
