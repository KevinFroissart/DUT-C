CC=gcc
CFLAGS=-Wall -Werror -Wextra
EXEC=tp4

all: $(EXEC)

tp4: main.o miroir.o 
	$(CC) -o tp4 main.o miroir.o

main.o: main.c 
	$(CC) $(CFLAGS) -o main.o -c main.c

miroir.o: miroir.c miroir.h
	$(CC) $(CFLAGS) -o miroir.o -c miroir.c

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
