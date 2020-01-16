#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "miroir.h"


int main(int argc, char **argv) {
  //Q1-------------------------------------------------
  //char tab[] = {"bonjour"};
  //char * s1 = &tab[0];
  //printf("Voici ma chaine normale : %s\n",s1);
  //printf("Et la chaine inversée : %s\n", miroir(s1));
  //---------------------------------------------------
  //Q2-------------------------------------------------
  //printf("Voici ma chaine saisie : %s\n", saisie());
  //---------------------------------------------------
  //Q3-------------------------------------------------
  
  int s_active = 0;
  int m_active = 0;
  char *res;
  int x = 1;
  int i = 0;
  if (argc > 4) {
    printf("mauvaise utilisation\n");
  }
    for (; x != argc; x++) {
      if (argv[x][0] == '-') {
        for (; argv[x][i] != '\0'; i++) {
          if (argv[x][i] == 's') s_active = 1;
          else if (argv[x][i] == 'm') m_active = 1;
        }
        i = 0;
      }
    }
    x = 0;
    if (s_active && m_active) {
      res = saisie();
      printf("%s\n%s\n", res, miroir(res));
    }
    else if (s_active && !m_active) printf("%s\n", saisie());
    else if (!s_active && m_active && argc == 3) printf("%s\n", miroir(argv[2]));
    else if (!s_active && m_active && argc == 2) printf("mauvaise utilisation\n");
  return 0;
}
