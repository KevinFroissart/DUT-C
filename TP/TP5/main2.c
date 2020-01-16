#include <stdlib.h>
#include <stdio.h>
#include "fonction.h"

#define MAXCHAR 1000

int main(int argc, char **argv) {
	
	char saisie[MAXCHAR] = {0};

	if(argc == 1){
		scanf("%[^\n]",saisie);
		printf("caractères : %d mots : %d --> stdin\n",length(saisie), wordCount(saisie));
		return 0;
	}
	int c_active = 0;
	int l_active = 0;
	int w_active = 0;
	int x = 1;
	int i = 0;
	int nb_args = 0;
	for (; x != argc; x++) {
		if (argv[x][0] == '-') {
			int arg = 0;
   			for (; argv[x][i] != '\0'; i++) {
       			if (argv[x][i] == 'c' || argv[x][i] == 'C'){
					c_active = 1;
					arg = 1;
				}
       			if (argv[x][i] == 'l' || argv[x][i] == 'L') {
					l_active = 1; 
					arg = 1;
				}
       			if (argv[x][i] == 'w' || argv[x][i] == 'W') {
					w_active = 1; 
					arg = 1;
				}
      		}
			nb_args += arg;
    	}
		i = 0;
	}
	x = 0;
		
	if(nb_args + 1 == argc){
		perror("Fichier manquant");
		exit(1);
	}

	if(nb_args == 0){
		c_active = 1;
		l_active = 1;
		w_active = 1;
	}

	FILE *fp;
	char str[MAXCHAR];

	int totalCharCount = 0;
	int totalWordCount = 0;
	int totalLineCount = 0;
		
	int j = nb_args + 1;
	for (; j < argc; j++){
		char const *filename = argv[j];
		fp = fopen(filename, "r");
		if (fp == NULL){
			perror(argv[j]);
			exit(1);
		} else {
			int charCount = 0;
			int motsCount = 0;
			int lineCount = 1;
			while (fgets(str, MAXCHAR, fp) != NULL){
				if(c_active == 1 || nb_args == 0) charCount += length(str);
				if(w_active == 1 || nb_args == 0) motsCount += wordCount(str);
				if(l_active == 1 || nb_args == 0) lineCount ++;
			}
			fclose(fp);
			if(c_active == 1) printf("caractères : %d ", charCount);
			if(w_active == 1) printf("mots : %d ", motsCount);
			if(l_active == 1) printf("lignes : %d ", lineCount);
			printf("--> %s\n", filename);
			if(argc - nb_args > 1){	
				totalLineCount += lineCount;
				totalWordCount += motsCount;
				totalCharCount += charCount;
			}
		}
	}
	if(argc - nb_args - 1 > 1){
		if(c_active == 1) printf("caractères : %d ", totalCharCount);
		if(w_active == 1) printf("mots : %d ", totalWordCount);
		if(l_active == 1) printf("lignes : %d ", totalLineCount);
		printf("--> total\n");
	}
	return 0;
}	