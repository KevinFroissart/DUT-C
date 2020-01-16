#include <stdio.h>
#include "fonction.h"
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 10000

int length(const char *s){
	int i = 0;
	while(s[i] != '\0'){
		i++;
	}
	return i;
}

int lignes(const char *s){
	int j = 0;
	int cpt = 1;
	while(s[j] != '\0'){
		if(s[j] == '\n') cpt++;
		j++;
	}
	return cpt;
}

int wordCount(const char *s){
	int i = 0;
	int res = 0;
	char tmp = ' ';
	while(s[i] != '\0'){
		if(!isspace(s[i]) && isspace(tmp) && tmp != '\t') res++;
		else if(s[i] == '\t' && isspace(tmp) && tmp != '\t') res++;
		tmp = s[i];
		i++;
	}
	return res;
}


int traiter (int f, int *car, int *mot, int *lig){
	int charCount = 0;
	int motsCount = 0;
	int lineCount = 1;
	char buffer[BUFFER_SIZE];
	while ((read(f, buffer, BUFFER_SIZE)) > 0) {
		if((*car) == 1) charCount += length(buffer);
		if((*mot) == 1) motsCount += wordCount(buffer);
		if((*lig) == 1) lineCount += lignes(buffer);
	}
	if((*car) == 1) printf("caractères : %d ", charCount);
	if((*mot) == 1) printf("mots : %d ", motsCount);
	if((*lig) == 1) printf("lignes : %d ", lineCount);
	return 0;	
}
