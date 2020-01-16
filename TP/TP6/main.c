#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
	//entete_bmp entete;

	int r = 0;
 	int n = 0;
  	int b = 0;
  	int s = 0;
  	int i = 0;
  	
  	int j;
  	
  	for(j = 1; j < argc; j++) {
   	if(argv[j][0] == '-') {
     		if (argv[j][1] == 'r') r = 1;
     		if (argv[j][1] == 'n') n = 1;
     		if (argv[j][1] == 'b') b = 1;
     		if (argv[j][1] == 's') s = 1;
     		if (argv[j][1] == 'i') i = 1;
    	}
  	}
  	
  	int nbOptions = r+n+b+s+i;
	
	if(argc - nbOptions != 3){
		perror("Fichier(s) manquant(s)");
		return 1;
	}
	
	int fd;
	if((fd = open(argv[nbOptions+1], O_RDONLY)) == -1)
	{
		perror(argv[nbOptions+1]);
		return 1;
	}

	int fd2;
	if((fd2 = open(argv[nbOptions+2], O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
	{
		perror("Impossible de créer le fichier\n");
		return 1;
	}
	
	if (fd == -1)
	  perror("open");
	if (fd2 == -1)
	  perror("open");
	  
	if(nbOptions == 0) copier_bmp(fd, fd2);
	else copier_options(fd, fd2, r, n, b, s, i);
	
	
	//EXO 1 ------------------------------------------
	//lire_entete(fd, &entete);
	//printf("signature : %x \n", entete.fichier.signature);
	//printf("taille : %u \n", entete.fichier.taille_fichier);
	//printf("reserve : %u \n", entete.fichier.reserve);
	//printf("offset : %u \n", entete.fichier.offset_donnees);

	//Exo 2 --------------------------------------------
	//printf("%d \n", ecrire_deux_octets(fd, val));
	//idem pour quatre octets
	//printf("%d \n", ecrire_entete(fd2, &entete));

	//Exo 3 --------------------------------------------
	// il faut lire ici la profondeur de entete !
	//printf("%d \n", verifier_entete(fd, &entete));

	//Exo 4 --------------------------------------------
	//unsigned char * tab = allouer_pixels(&entete);
	//if(!tab)
		//perror("malloc");

	//Exo 5 --------------------------------------------
	//lire_pixels(fd, &entete, tab);
	//Exo 6 --------------------------------------------
	//ecrire_pixels(fd2, &entete, tab);
	//Exo 7 --------------------------------------------
 	//copier_bmp(fd, fd2);
	//Exo 8 --------------------------------------------
	//utilisation du rouge dans le copier_bmp
	//Exo 9 --------------------------------------------
	
	
	
	
	close(fd);
	return 0;
}
