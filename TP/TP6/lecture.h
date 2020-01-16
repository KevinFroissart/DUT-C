#ifndef __LECTURE__
#define __LECTURE__
typedef unsigned short uint16 ;
	typedef unsigned int uint32 ;
	typedef struct
	{
		uint16 signature ;
		uint32 taille_fichier ;
		uint32 reserve ;
		uint32 offset_donnees ;
	} entete_fichier ;

	typedef struct
	{
		uint32 taille_entete ;
		uint32 largeur ;
		uint32 hauteur ;
		uint16 nombre_plans ;
		uint16 profondeur ;
		uint32 compression ;
		uint32 taille_donnees_image ;
		uint32 resolution_horizontale ;
		uint32 resolution_verticale ;
		uint32 taille_palette ;
		uint32 nombre_de_couleurs_importantes ;
	} entete_bitmap ;

	typedef struct
	{
		entete_fichier fichier ;
		entete_bitmap bitmap ;
	} entete_bmp ;

int lire_deux_octets(int fd, uint16 *val);
int lire_quatre_octets(int fd, uint32 *val);
int lire_entete(int de, entete_bmp *entete);
int ecrire_deux_octets(int fd, uint16 val);
int ecrire_quatre_octets(int fd, uint32 val);
int ecrire_entete(int vers, entete_bmp *entete);
int verifier_entete(entete_bmp *entete);
int lire_profondeur(int de, entete_bmp *entete);
unsigned char* allouer_pixels(entete_bmp *entete);
int lire_pixels(int de, entete_bmp *entete, unsigned char *pixels);
int ecrire_pixels(int vers, entete_bmp *entete, unsigned char *pixels);
int copier_bmp ( int de , int vers);
void rouge(entete_bmp *entete, unsigned char *pixels);
void negatif(entete_bmp *entete, unsigned char *pixels);
void noir_et_blanc(entete_bmp *entete, unsigned char *pixels);
int moitie(entete_bmp *entete, unsigned char *pixels,int sup);
int taille_ligne(entete_bmp *entete, int avec_padding);
int copier_options (int de ,int vers, int r, int n, int b, int s, int i);
#endif
