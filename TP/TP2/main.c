#include <stdio.h>
#include "tableau.h"

int main(void)
{
  /*  int tabDest[20];
      int tab[10];
  int i;
  for(i=0; i<10; i++){
      tab[i] = i;
  }
  afficher(tab,10);
  int j = somme(tab,10);
  printf("\nsomme : %d\n",j);
  copie_dans(tabDest,tab,10);
  printf("\n");
  ajoute_apres(tabDest,20,tab,10);
  printf("\n");
  */
  struct rat f1 = {10,5};
  struct rat f2 = {10,3};
  struct rat f3 = {120,4};
  struct rat f4 = {5,8};
  struct rat f5 = {4,130};
  struct rat f6 = {9,42};
  struct rat f7 = {24,26};
  struct rat f8 = {15,369};
  struct rat f9 = {5,16};
  struct rat f10 = {9,52};
  
  struct rat res = rat_produit(f1,f2);
  printf("%d / %d",res.num, res.den);

  struct rat resTab[10];
  resTab[0] = f1;
  resTab[1] = f2;
  resTab[2] = f3;
  resTab[3] = f4;
  resTab[4] = f5;
  resTab[5] = f6;
  resTab[6] = f7;
  resTab[7] = f8;
  resTab[8] = f9;
  resTab[9] = f10;

  struct rat resTa = rat_plus_petit(resTab);
  printf("\n%d / %d",resTa.num, resTa.den);
  return 0;
  
}
