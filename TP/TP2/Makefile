tp2: main.o tab.o
	gcc -o tp2 main.o tab.o

main.o:	main.c
	gcc -Wall -Werror -Wextra -o main.o -c main.c

tab.o: tab.c tableau.h
	gcc -Wall -Werror -Wextra -o tab.o -c tab.c
