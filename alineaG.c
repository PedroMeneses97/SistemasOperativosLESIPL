#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h> 
#include <stdio.h> 
#include <string.h>

/**
 * @brief lista [directoria] – Este comando deve apresentar uma lista de todas as
 * pastas e ficheiros existentes na directoria indicada ou na diretoria atual se
 * não especificada. Adicionalmente, deve distinguir ficheiros simples de 
 * diretorias através de uma indicação textual.
 * Autor: Pedro Meneses
 * https://stackoverflow.com/questions/4204666/how-to-list-files-in-a-directory-in-a-c-program
 */


int main(int argc, char *argv[]){
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(argv[1])) != NULL) {
        while ((ent = readdir (dir)) != NULL) {

            // Se o tipo de ficheiro for um ficheiro, imprime um c- antes do nome
            if (ent->d_type == DT_REG) {
                printf ("c-%s\n", ent->d_name);
                // write(1, ent->d_name, strlen(ent->d_name));
            }

            // Se o tipo de ficheiro for um diretório, imprime um d- antes do nome
            else if (ent->d_type == DT_DIR) {
                printf ("d-%s\n", ent->d_name);

                // write(1,ent->d_name, strlen(ent->d_name));
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