#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include "lecture.h"
#define TAILLE_ENTETE_BMP 40
#define NB_PLANS_BMP 1
#define SIGNATURE_BMP 0x424D
#define FILTRE_PIXELS(f) ((f) <= NEGATIG)
#define FILTRE_MOITIE(f) ((f) > NEGATIF && (f) <= INFERIEUR
// typedef void (*filter_callback)(entete_bmp *, unsigned char *);

//void rouge(entete_bmp *entete, unsigned char *pixels);

//EXO1

int lire_deux_octets(int fd, uint16 *val) {
  return read(fd, val, 2);
}

int lire_quatre_octets(int fd, uint32 *val) {
  return read(fd, val, 4);
}

int lire_entete(int de, entete_bmp *entete) {
  if (lire_deux_octets(de, &entete->fichier.signature) == -1) {return -1;}
  if (lire_quatre_octets(de, &entete->fichier.taille_fichier) == -1) {return -1;}
  if (lire_quatre_octets(de, &entete->fichier.reserve) == -1) {return -1;}
  if (lire_quatre_octets(de, &entete->fichier.offset_donnees) == -1) {return -1;}
  if (lire_quatre_octets(de, &entete->bitmap.taille_entete) == -1) {return -1;}
  if (lire_quatre_octets(de, &entete->bitmap.largeur) == -1) {return -1;}
  if (lire_quatre_octets(de, &entete->bitmap.hauteur) == -1) {return -1;}
  if (lire_deux_octets(de, &entete->bitmap.nombre_plans) == -1) {return -1;}
  if (lire_deux_octets(de, &entete->bitmap.profondeur) == -1) {return -1;}
  if (lire_quatre_octets(de, &entete->bitmap.compression) == -1) {return -1;}
  if (lire_quatre_octets(de, &entete->bitmap.taille_donnees_image) == -1) {return -1;}
  if (lire_quatre_octets(de, &entete->bitmap.resolution_horizontale) == -1) {return -1;}
  if (lire_quatre_octets(de, &entete->bitmap.resolution_verticale) == -1) {return -1;}
  if (lire_quatre_octets(de, &entete->bitmap.taille_palette) == -1) {return -1;}
  if (lire_quatre_octets(de, &entete->bitmap.nombre_de_couleurs_importantes) == -1) {return -1;}
  return 1;
}

//EXO2

int ecrire_deux_octets(int fd, uint16 val) {
  return write(fd, &val, 2);
}

int ecrire_quatre_octets(int fd, uint32 val) {
  return write(fd, &val, 4);
}

int ecrire_entete(int vers, entete_bmp *entete) {
  if (ecrire_deux_octets(vers, entete->fichier.signature) == -1) {return -1;}
  if (ecrire_quatre_octets(vers, entete->fichier.taille_fichier) == -1) {return -1;}
  if (ecrire_quatre_octets(vers, entete->fichier.reserve) == -1) {return -1;}
  if (ecrire_quatre_octets(vers, entete->fichier.offset_donnees) == -1) {return -1;}
  if (ecrire_quatre_octets(vers, entete->bitmap.taille_entete) == -1) {return -1;}
  if (ecrire_quatre_octets(vers, entete->bitmap.largeur) == -1) {return -1;}
  if (ecrire_quatre_octets(vers, entete->bitmap.hauteur) == -1) {return -1;}
  if (ecrire_deux_octets(vers, entete->bitmap.nombre_plans) == -1) {return -1;}
  if (ecrire_deux_octets(vers, entete->bitmap.profondeur) == -1) {return -1;}
  if (ecrire_quatre_octets(vers, entete->bitmap.compression) == -1) {return -1;}
  if (ecrire_quatre_octets(vers, entete->bitmap.taille_donnees_image) == -1) {return -1;}
  if (ecrire_quatre_octets(vers, entete->bitmap.resolution_horizontale) == -1) {return -1;}
  if (ecrire_quatre_octets(vers, entete->bitmap.resolution_verticale) == -1) {return -1;}
  if (ecrire_quatre_octets(vers, entete->bitmap.taille_palette) == -1) {return -1;}
  if (ecrire_quatre_octets(vers, entete->bitmap.nombre_de_couleurs_importantes) == -1) {return -1;}
  return 1;
}

//EXO3

int verifier_entete(entete_bmp *entete) {
  if(entete->fichier.signature != SIGNATURE_BMP){
    fprintf(stderr, "signature invalide\n");
    return 0;
  }
  if(entete->bitmap.taille_entete != TAILLE_ENTETE_BMP){
    fprintf(stderr, "taille de l'entete invalide : %u lu, %d minimum anttendu\n", entete->bitmap.taille_entete, TAILLE_ENTETE_BMP); 
    return 0;
  }
  if(entete->bitmap.nombre_plans != NB_PLANS_BMP){
    fprintf(stderr, "nombre de plans invalide : %u lu, %d attendu\n", entete->bitmap.nombre_plans, NB_PLANS_BMP); 
    return 0;
  }
  if (entete->bitmap.profondeur != 24) {
    return 0;
  }
  return 1;
}
 

//EXO4

unsigned char* allouer_pixels(entete_bmp *entete) 
{
  return (unsigned char*) malloc(entete->bitmap.taille_donnees_image);
}

//EXO5

int lire_pixels(int de, entete_bmp *entete, unsigned char *pixels)
{
	if( lseek(de, entete->fichier.offset_donnees, SEEK_SET) ==-1 )perror ("lseek");
	return read(de ,pixels, entete->bitmap.taille_donnees_image);
}

//EXO6

int ecrire_pixels(int de, entete_bmp *entete, unsigned char *pixels)
{
	if(lseek(de, entete->fichier.offset_donnees, SEEK_SET)==-1)perror("lseek");
	return write(de, pixels, entete->bitmap.taille_donnees_image); 	
}

//EXO7

int copier_bmp (int de , int vers) {
  entete_bmp entete ;
  unsigned char * pixels ;

  lire_entete (de , &entete);
  pixels = allouer_pixels (&entete);
  lire_pixels (de ,&entete ,pixels);
  
  
  ecrire_entete (vers ,&entete);
  ecrire_pixels (vers ,&entete ,pixels);
  free( pixels );
  return 1;
}

//EXO8

void rouge (entete_bmp *entete, unsigned char *pixels)
{
	int i;
  int j;
  int tailleV = entete->bitmap.hauteur;
  int tailleH = entete->bitmap.largeur * 3;
  int ligne;

  if (tailleH % 4 != 0) {
    ligne = tailleH + (4 - tailleH % 4);
  } else {
    ligne = tailleH;
  }

  for (i = 0; i < tailleV; i++) {
    for (j = 0; j < tailleH; j++) {
      if (j % 3 != 2) {
        pixels[i * ligne + j] = 0;
      }
    }
  }
}


//EXO9
void negatif(entete_bmp *entete, unsigned char *pixels) {
  int i;
  int j;
  int tailleV = entete->bitmap.hauteur;
  int tailleH = entete->bitmap.largeur * 3;
  int ligne;

  if (tailleH % 4 != 0) {
    ligne = tailleH + (4 - tailleH % 4);
  } else {
    ligne = tailleH;
  }

  for (i = 0; i < tailleV; i++) {
    for (j = 0; j < tailleH; j++) {
      pixels[i * ligne + j] = 255 - pixels[i * ligne + j];
    }
  }
}

//EXO10
void noir_et_blanc(entete_bmp *entete, unsigned char *pixels) {
  int i, ligne, niveauGris;	
	int hauteur = entete->bitmap.hauteur;	
	int tl = taille_ligne(entete, 0);
	int tlp = taille_ligne(entete, 1);
	for(ligne = 0; ligne < hauteur; ligne++, pixels += tlp){
		for(i=0;i<tl;i+=3){	
			niveauGris = (pixels[i] + pixels[i+1] + pixels[i+2])/3;
			pixels[i]=niveauGris;
	 		pixels[i+1]=niveauGris;
			pixels[i+2]=niveauGris;
		}
  }
}


/*
void moitie(entete_bmp *entete, unsigned char *pixels,int sup) {
  int i;
  int j;
  int tailleV = entete->bitmap.hauteur;
  int tailleH = entete->bitmap.largeur * 3;
  int tailleVM = tailleV / 2;
  int ligne;
	if (sup == 1) {
    entete->bitmap.hauteur = entete->bitmap.hauteur / 2;
  } else {
  if (tailleH % 4 != 0) {
    ligne = tailleH + (4 - tailleH % 4);
  } else {
    ligne = tailleH;
  }

  for (i = tailleVM; i < tailleV; i++) {
    for (j = 0; j < tailleH; j ++) {
      pixels[(i - tailleVM) * ligne + j] = pixels[i * ligne + j];
    }
  }
  entete->bitmap.hauteur = entete->bitmap.hauteur / 2;
}}*/

int taille_ligne(entete_bmp *entete, int avec_padding)
{
  int taille = (entete->bitmap.profondeur >> 3) * entete->bitmap.largeur;
  int mod = 4 - (taille % 4);
  if(mod != 4 && avec_padding) 
  {
  taille += mod;
  }
  return taille;
}

int moitie(entete_bmp *entete, unsigned char *pixels,int sup) {
  int ancienne_hauteur = entete->bitmap.hauteur;
  int tlp = taille_ligne(entete, 1);
  entete->bitmap.hauteur /= 2;
  entete->bitmap.taille_donnees_image = tlp * entete->bitmap.hauteur;
  entete->fichier.taille_fichier = entete->bitmap.taille_donnees_image + entete->fichier.offset_donnees;
  if(sup) {
    return 1;
  }
  int offset = (ancienne_hauteur - entete->bitmap.hauteur) * tlp;
  memcpy(pixels, pixels + offset, entete->bitmap.hauteur * tlp);
  return 1;
}

//EXO11
int copier_options (int de ,int vers, int r, int n, int b, int s, int i) {
	entete_bmp entete ;
   unsigned char * pixels ;

   lire_entete (de , &entete);
   pixels = allouer_pixels (&entete);
   lire_pixels (de ,&entete ,pixels);
   
   if(r) rouge(&entete, pixels);
   if(n) negatif(&entete, pixels);
   if(b) noir_et_blanc(&entete, pixels);
   if(i) moitie(&entete, pixels, i);
   if(s) moitie(&entete, pixels, 0);

   ecrire_entete (vers ,&entete);
   ecrire_pixels (vers ,&entete ,pixels);
   free( pixels );
   return 1;
}



