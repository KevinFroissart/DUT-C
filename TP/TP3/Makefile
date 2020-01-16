CC=gcc
CFLAGS=-Wall -Werror -Wextra
EXEC=tp3

all: $(EXEC)

tp3: main.o chaines.o 
	$(CC) -o tp3 main.o chaines.o

main.o: main.c 
	$(CC) $(CFLAGS) -o main.o -c main.c

chaines.o: chaines.c chaines.h
	$(CC) -$(CFLAGS) -o chaines.o -c chaines.c

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
