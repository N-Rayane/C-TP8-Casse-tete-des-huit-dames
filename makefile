CFLAGS=-std=c17 -pedantic -Wall -Wextra -D_DEFAULT_SOURCE -I./include -g -Wno-missing-field-initializers -g
LDLIBS=-lncurses -lm
CC=clang

all: Dame

Test: Test.o Moteur.o Graphique.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

Dame: Main.o Moteur.o Graphique.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

Main.o: src/Main.c
	$(CC) $(CFLAGS) -c -o $@ $<

Test.o: src/Test.c
	$(CC) $(CFLAGS) -c -o $@ $<

Moteur.o: src/Moteur.c
	$(CC) $(CFLAGS) -c -o $@ $<

Graphique.o : src/Graphique.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o

mrproper: clean
	rm -f Dame
	rm -f Test
