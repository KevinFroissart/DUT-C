CC=gcc
CFLAGS=-Wall -Werror -Wextra
EXEC=tp5 tp5_2

all: $(EXEC)

tp5: main.o fonction.o 
	$(CC) -o tp5 main.o fonction.o

tp5_2: main2.o fonction.o
	$(CC) -o tp5_2 main2.o fonction.o

main.o: main.c 
	$(CC) $(CFLAGS) -o main.o -c main.c

main2.o: main2.c
	$(CC) $(CFLAGS) -o main2.o -c main2.c
	
fonction.o: fonction.c fonction.h
	$(CC) $(CFLAGS) -o fonction.o -c fonction.c

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
