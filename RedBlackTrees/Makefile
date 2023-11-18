CC   = cc
OBJS = redblacktrees.o

CFLAGS = -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings \

all: test 

compile: redblacktrees.o
	mv $@ ../o

redblacktrees.o: redblacktrees.c redblacktrees.h
	${CC} $(CFLAGS) -c -o $@ $<

test: $(OBJS) test.o
	${CC} -o $@ $^

run: test
	./test

clean:
	rm -f *.o test

test.o: redblacktrees.h

