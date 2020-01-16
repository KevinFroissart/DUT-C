#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ligne_commande.h"

void affiche_prompt(){
  char * user = getenv("USER");
  printf("%s :",user);
}

void execute_ligne_commande(){
	int flag ;
  int nb;
  char *** ligne = ligne_commande(&flag, &nb);
  for(int i = 0; i < nb; i++){
    if(fork() == 0 && flag > -1){
    	if(execvp(ligne[i][0],ligne[i]) == -1) perror("execvp");
    } else {
      //wait();
    }
  }
  printf("\n");
}

int main(void){
  //while(1){
    affiche_prompt();
    execute_ligne_commande();
  //}
	return 1;
}

