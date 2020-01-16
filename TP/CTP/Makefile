# FROISSART Kévin H epicea05

CC=gcc
CFLAGS=-Wall -Werror -Wextra
EXEC=iutsh


cpt: froissak.o 
	$(CC) -o ctp froissak.o 

froissak.o: froissak.c froissak.h
	$(CC) $(CFLAGS) -o froissak.o -c froissak.c

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
