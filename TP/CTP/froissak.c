/**
 * FROISSART Kévin H epicea05
 *
 * Indiquez ci-dessus vos nom, prénom, groupe et machine
 */
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
/** La taille maximale d'un nom de fichier */
#define FILENAME_SIZE 256

/** La structure qui décrit un travail */
typedef struct
{
   char fichier[FILENAME_SIZE];
} job_t;

/** Ecrit un job dans un tube
 * @param fd le descripteur de l'entrée du tube
 * @param job le pointeur vers le job à envoyer
 * @return -1 en cas d'erreur, 0 en cas de succès
 */
int envoyer_job(int fd, const job_t *job)
{
	if(write(fd, job, FILENAME_SIZE) == -1){
		perror("write");
		return -1;
	}
	
  return 0;
}

/** Lit un job depuis un tube
 * @param fd le descripteur de la sortie du tube
 * @param job un pointeur (valide) vers la structure à remplir
 * @return -1 en cas d'erreur, 0 en cas de succès
 */
int recevoir_job(int fd, job_t *job)
{
	 if(read(fd, job, FILENAME_SIZE) == -1){
     perror("write");
     return -1;
   }	 	
	
   return 0;
}

/** Affiche les informations concernant un fichier sur la sortie standard
 * @param fichier une chaîne de caractères contenant le chemin vers un fichier
 * @return -1 en cas d'erreur, 0 en cas de succès
 */
int afficher_details(const char *fichier)
{
	 
	 int taille;
	 char t;
	 
	 struct stat buf;
	 
	 if(stat(fichier, &buf) == -1){
	 		perror("stat");
	 		return -1;
	 }
	 taille = buf.st_size;
	 
	 switch (buf.st_mode & S_IFMT)
   {
      case S_IFCHR: t = 'c'; break;
      case S_IFDIR: t = 'd'; break;
      case S_IFBLK: t = 'b'; break;
      case S_IFREG: t = '-'; break;
      default:
         t = 'X';
         break;
   }
	 
	 printf("%c,%s,%d",t ,fichier, taille);
   return 0;
}

/** Effectue le traitement.
 * @param fd la sortie d'un tube duquel vont provenir les travaux
 * @return cette fonction ne retourne pas et quitte le processus courant
 */
void traitement_fils(int fd)
{
	job_t * job = NULL;

	while(sizeof(fd) > 0){
		if(recevoir_job(fd, job) == -1){
			perror("recevoir_job");
			exit(1);
		}
	  if(afficher_details(job->fichier) == -1){
	  	perror("afficher_details");
	  	exit(1);
	  }
	}
  printf("Travail terminé");
  exit(0);
}

/** Créer un processus fils et lui fait démarrer le traintement
 * @param fd les descripteurs du tube permettant la communication entre le père et le fils créé
 * @return -1 en cas d'erreur, le pid du fils créé sinon.
 */
 
int creer_fils(int fd[2])
{
   int pid = fork();
   
   if(pid == 0){
   	close(fd[1]);
   	traitement_fils(fd[0]);
   	close(fd[0]);
   	printf("Fils de pid %d: Fini", getpid());
   }
   else if(pid == -1){
   	perror("pid");
   	return -1;
   }
   else {
   	wait(&pid);
   	printf("Pere: Fils de pid %d terminé correctement\n", pid);
   	return pid;
   }
   return -1;
}

/** Le main */
int main(int argc, char **argv)
{

	job_t * job = NULL;

	// On vérifie le nombre d'arguments

	if(argc < 3){
		perror("argc");
		return -1;
	}
	
	//On créeer un tube
	
	int t[2];
	if (pipe(t) == -1) {
      perror("pipe");
      return 1;
  }
	
	//On récupère le nombre de fils à créer
	
	int nbFils = atoi(argv[1]);
	
	//On créer tous les fils
	
	for(int i = 0; i < nbFils; i++) {
		creer_fils(t);
	}
	
	//On envoie tous les jobs passé en paramètre
	
	for(int j = 2; j < argc; j++){
		int fd;
		if((fd = open(argv[j], O_RDONLY)) == -1)
		{
			perror(argv[j]);
			return -1;
		}
		envoyer_job(fd, job);
	}
	
	//On traite les fils
	
	traitement_fils(t[1]);
  
  printf("Tous les processus sont terminé");
   
  return 0;
}

