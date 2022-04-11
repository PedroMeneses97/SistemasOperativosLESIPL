#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



// Feito por Pedro Meneses
int main(){

   /**
    * @brief Apagar um ficheiro com o nome passado como parametro na função open
    * caso o ficheiro nao exista, imprimir no ecrã o erro dado
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

