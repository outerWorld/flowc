CC = gcc
INC = -I./include -Ilib/include
LIB =
BIN = flowc
LFLAGS = -Llib -lsos
CFLAGS = -g ${INC}

include src/Makefile.am
SRCS=$(__SRC_C)
OBJS = $(__SRC_C:.c=.o)

flowc:${OBJS}
	${CC} -o $@ $^ ${LFLAGS}

$(OBJS):src/$(SRCS)
	${CC} -c $< ${CFLAGS}

gen_lib:
	cd ./lib && make -f Makefile clean all || cd ..

test:
	cd ./test && make -f Makefile clean all || cd ..

.PHONY:gen_lib all test clean

all:gen_lib ${BIN}

clean:
	rm -f *.o
	rm -f ${BIN}
