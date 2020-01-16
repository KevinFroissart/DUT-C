#tp1_1.c
#tp1_1.o: tp1_1.c
#	gcc -c -o -Wall -Werror -Wextra tp1_1.c

#tp1_2.c
#tp1_2.o: tp1_2.c
#	gcc -c -o -Wall -Werror -Wextra tp1_2.c

#tp1_3.c
#tp1_3.o: tp1_3.c
#	gcc -c -o -Wall -Werror -Wextra tp1_3.c
tp1: tp1_1.o tp1_2.o tp1_3.o
	gcc -o tp1_1.c tp1_2.c tp1_3.c
tp1_1.o: tp1_1.c tp1_2.h
	gcc -Wall -Werror -Wextra -c tp1_1.c
tp1_2.o: tp1_2.c
	gcc -Wall -Werror -Wextra -c tp1_2.c
tp1_3.o: tp1_3.c tp1_2.h
	gcc -Wall -Werror -Wextra -c tp1_3.c
