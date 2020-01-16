#include <stdlib.h>
#include <stdio.h>
#include "fonction.h"
#include <fcntl.h>
#include <unistd.h>

#define MAXCHAR 1000

int main(int argc, char **argv) {
	
	char saisie[MAXCHAR] = {0};

	int c_active = 0;
	int l_active = 0;
	int w_active = 0;
	int x = 1;
	int i = 1;
	int nb_args = 0;
	for (; x != argc; x++) {
		if (argv[x][0] == '-') {
			int arg = 0;
   			for (; argv[x][i] != '\0'; i++) {
       			if (argv[x][i] == 'c' || argv[x][i] == 'C'){
					c_active = 1;
					arg = 1;
				}
       			else if (argv[x][i] == 'l' || argv[x][i] == 'L') {
					l_active = 1; 
					arg = 1;
				}
       			else if (argv[x][i] == 'w' || argv[x][i] == 'W') {
					w_active = 1; 
					arg = 1;
				}
				else {
					perror("Cet argument n'existe pas. -c -l -w seulement");
					exit(1);
				}
      		}
			nb_args += arg;
    	}
		i = 0;
	}
	x = 0;
		
	if(argc == 1){
		perror("arguments ou fichier manquants");
		exit(1);
	}

	if(nb_args + 1 == argc){
		scanf("%[^\n]",saisie);
		if(c_active) printf("caractères : %d ", length(saisie));
		if(w_active) printf("mots : %d ", wordCount(saisie));
		if(l_active) printf("lignes : %d",lignes(saisie));
		printf(" --> stdin\n");
		return 0;
	}

	if(nb_args == 0){
		c_active = 1;
		l_active = 1;
		w_active = 1;
	}

	int j = nb_args + 1;
	for (; j < argc; j++){
		char const *filename = argv[j];
        int fd = open(filename, O_RDONLY);
        if (fd == -1){
	    	perror(argv[j]);
		    return(1);
        } else {
		    traiter(fd,&c_active,&w_active,&l_active);
            close(fd);
			printf("--> %s\n", filename);
        }
	}
	return 0;
}
