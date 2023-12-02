CC   = cc
OBJS = searchtrees.o

CFLAGS = -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings -Wno-unused-parameter

all: test 

compile: searchtrees.o
	mv $^ ../o

searchtrees.o: searchtrees.c searchtrees.h
	${CC} $(CFLAGS) -c -o $@ $<

test: $(OBJS) test.o
	${CC} -o $@ $^

run: test
	./test

clean:
	rm -f *.o test

test.o: searchtrees.h

