CC   = cc
OBJS = linkedlists.o

CFLAGS = -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings \

all: compile

compile: $(OBJS)

linkedlists.o: linkedlists.c linkedlists.h
	${CC} $(CFLAGS) -c -o $@ $<
	mv $@ ../o
	cp linkedlists.h ../h

clean:
	rm -f *.o

