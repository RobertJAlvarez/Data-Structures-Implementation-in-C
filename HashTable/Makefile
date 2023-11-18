CC   = cc
OBJS = ../o/linkedlists.o hash.o hashtable.o

CFLAGS = -I../h -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings \

%.o: %.c
	${CC} $(CFLAGS) -c -o $@ $<

all: dictionary

compile: $(OBJS)
	mv *.o ../o
	cp *.h ../h

dictionary: $(OBJS) dictionary.o
	${CC} -o $@ $^

run1:
	./dictionary sp-en-dictionary.txt

run2:
	./dictionary sp-en-mini.txt

clean:
	rm -f *.o dictionary

hash.o: hash.c hash.h
hashtable.o: hashtable.c hashtable.h ../h/linkedlists.h

