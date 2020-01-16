#include <stdio.h>
#include "tp1_2.h"

void fonction_b(int param)
{
  if(param == 0)
    printf("le paramètre est nul\n");
  else
    printf("le retour de la fonction_a est %d\n", fonction_a(param));
}
