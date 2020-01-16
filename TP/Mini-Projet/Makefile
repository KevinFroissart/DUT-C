CC = gcc -Wall -Werror -Wextra

# Règle 1
iutsh : main.o ligne_commande.o
	$(CC) -lreadline -o iutsh main.o ligne_commande.o

# Règle 2
main.o : main.c ligne_commande.o ligne_commande.h
	$(CC) -c main.c

clean:
	rm -f *.o *~ *.gch

real-clean :
	make clean
	rm -f ./iutsh

