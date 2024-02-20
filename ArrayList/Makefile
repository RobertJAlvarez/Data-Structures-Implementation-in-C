CC   = cc
OBJS = ArrayList.o

CFLAGS = -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings

all: compile

compile: $(OBJS)

ArrayList.o: ArrayList.c ArrayList.h
	${CC} $(CFLAGS) -c -o $@ $<
	mv $@ ../o
	cp ArrayList.h ../h

clean:
	rm -f *.o

