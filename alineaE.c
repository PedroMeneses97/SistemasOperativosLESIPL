#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>




int main(){

   /**
    * @brief Delete file with the given name, if the file doesn't exist print an error message
    */

    int fd = open("./filetodelete.txt", O_RDONLY); // Designar o nosso fd

    if(remove("./filetodelete.txt") == 0){
        printf("Ficheiro apagado com sucesso");
    }
    else{
        perror("erro, o ficheiro não existe ou o caminho é inválido");
        exit(1);
    }
 

    return 0;
}

