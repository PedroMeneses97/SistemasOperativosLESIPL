
#include <dirent.h> 
#include <stdio.h> 

int main(void) {

    // Pedro Meneses
    // https://stackoverflow.com/questions/4204666/how-to-list-files-in-a-directory-in-a-c-program


    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(".")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {

            // Se o tipo de ficheiro for um ficheiro, imprime um c- antes do nome
            if (ent->d_type == DT_REG) {
                printf ("c-%s/\n", ent->d_name);
            }

            // Se o tipo de ficheiro for um diretório, imprime um d- antes do nome
            else if (ent->d_type == DT_DIR) {
                printf ("d-%s\n", ent->d_name);
            }

            else{
                perror("Erro ao ler o tipo de ficheiro");
            }

        }

        closedir (dir);
    } else {
        perror ("Erro ao abrir a diretoria");
    }

  return(0);
}