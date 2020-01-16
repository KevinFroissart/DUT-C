#include <stdio.h>

void afficher(int liste[], int taille);

int somme (int liste[], int taille);

void copie_dans(int dest[], int src[], int taille);

void ajoute_apres(int dest[], int taille_dest, int src[], int taille_src);

struct rat
{
  int den;
  int num;
};

struct rat rat_produit(struct rat n1, struct rat n2);

struct rat rat_somme(struct rat n1, struct rat n2);

struct rat rat_plus_petit(struct rat list[]);
