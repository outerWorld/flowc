CC = gcc
INC = -I./
LIB =
BIN = flowc
LFLAGS = 
CFLAGS =
OBJS=main.o

flowc:${OBJS}
	${CC} -o $@ $^ ${LFLAGS}

%.o:src/%.c
	${CC} -c $< ${CFLAGS}

.PHONY:all clean

all:${BIN}

clean:
	rm -f *.o
	rm -f ${BIN}
