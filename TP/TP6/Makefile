CC=gcc
CFLAGS=-Wall -Werror -Wextra
EXEC=tp6


tp6: main.o lecture.o 
	$(CC) -o tp6 main.o lecture.o 

main.o: main.c
	$(CC) $(CFLAGS) -o main.o -c main.c

lecture.o: lecture.c lecture.h
	$(CC) $(CFLAGS) -o lecture.o -c lecture.c

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
