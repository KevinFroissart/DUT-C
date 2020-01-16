#include <stdio.h>
#include "tableau.h"

void afficher(int liste[], int taille)
{
  int i;
  for(i=0; i<taille; i++){
    printf("%d, ",liste[i]);
  }
}

int somme(int liste[], int taille)
{
  int i;
  int somme=0;
  for(i=0; i<taille; i++){
    somme += liste[i];
  }
  return somme;
}

void copie_dans(int dest[], int src[], int taille){
  int i;
  for(i=0; i<taille; i++){
    dest[i] = src[i];
    printf("%d, ",dest[i]);
  }
}

void ajoute_apres(int dest[], int taille_dest, int src[], int taille_src){
  int i;
  for(i=taille_src; i<taille_dest; i++){
    dest[i] = src[i-taille_src];
  }
  for(i=0; i<taille_dest; i++){
    printf("%d, ",dest[i]);
  }
}

struct rat rat_produit(struct rat n1, struct rat n2){

  struct rat res;
  res.num = n1.num * n2.num;
  res.den = n1.den * n2.den;
  return res;
}

struct rat rat_somme(struct rat n1, struct rat n2){

  struct rat res;
  res.num = n1.num * n2.den + n2.num * n1.den;
  res.den = n1.den * n2.den;
  return res;
}
struct rat rat_plus_petit(struct rat list[]){

  struct rat res;
  res.den = list[0].den;
  res.num = list[0].num;
  int i;
  
  for(i=0; i<10; i++){
    if(res.num/res.den > list[i].num/list[i].den){
      res.den = list[i].den;
      res.num = list[i].num;
    }
  }
  return res;
}
