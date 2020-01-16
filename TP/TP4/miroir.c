#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * miroir(const char *s) {
  char *mir = malloc(sizeof(s));
  if(strlen(s) == 0){
    perror("Error");
	exit(1);
  }
  int i,n = strlen(s)-1;
  for(i = 0; i <= n; i++)
    *(mir+i) = *(s+(n-i));
  if (sizeof(mir) >= sizeof(s)) {
    return mir;
  }
  else{
	free(mir);
    return NULL;
   }
}

char *saisie()
{
  int taille=10;
  int i=0 ;
  char *s;
  char car;
  char *tmp;
  s=(char*)malloc(sizeof(char)*taille);
  car = getchar();
  if(isspace(car)) {
    free(s);
	perror("Chaine vide");
	exit(1);
  }
  while(!isspace(car)) {
    if(i==taille) {
      taille+=10;
      tmp=(char*)realloc(s,sizeof(char)*taille);
      s = tmp;
    }
    s[i]=car;
    i++;
    car=getchar();
  }
  taille=i+1;
  tmp=(char*)realloc(s,sizeof(char)*taille);
  s = tmp;
  s[i] = '\0';
  return s;
}
