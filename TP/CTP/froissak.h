#ifndef __LECTURE__
#define __LECTURE__
int envoyer_job(int fd, const job_t *job);
int recevoir_job(int fd, job_t *job);
int afficher_details(const char *fichier);
void traitement_fils(int fd);
int creer_fils(int fd[2]);
int main(int argc, char **argv);
#endif
