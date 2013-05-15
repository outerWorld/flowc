CC=gcc
CFLAGS=-g -I../include -I../lib/include
LFLAGS=-L../lib -lsos
TESTS=test_memcpy_perf


test_memcpy_perf:test_memcpy_perf.o
	${CC} -o $@ $^ ${LFLAGS}

%.o:%.c
	${CC} -c $< ${CFLAGS}

all:${TESTS}

.PHONY:clean all

clean:
	rm -f *.o
	rm -f ${TESTS}
