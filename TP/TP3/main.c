#include <stdio.h>
#include "chaines.h"


int main(void)
{
  char tab[] = {"bonjour"};
  printf("Nombre de caractères dans la chaine : %d\n",mon_strlen(tab));
  char tab2[] = {"jour"};
  char * s = &tab2[0];
  printf("Nombre de caractères dans la chaine : %d\n", mon_strlen2(s));
  char * p = &tab[0];
  printf("Comparaison1 : %d\n", mon_strcmp(s, p));
  printf("Comparaison2 : %d\n", mon_strncmp(s, p, 2));
  printf("Nouvelle chaine : %s\n", mon_strcat(s,p));
  printf("Première occurence : %c\n", *mon_strchr(s, 'j'));
  printf("Sous-chaine : %s\n", mon_strstr(p, s));
  return 0;
}
