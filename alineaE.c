#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

 /**
   * @brief apaga ficheiro – Este comando deve apagar o ficheiro com o nome indicado.
   * No caso de o ficheiro indicado não existir, e apenas, deve ser apresentado
   * um aviso ao utilizador;
   * Autor: Pedro Meneses
   * https://linux.die.net/man/2/unlink
   */

int main(){

    int fd;

    fd = open("./ficheiroToDelete.txt", O_RDONLY); // Caso o nosso fd seja diferente de -1, significa que o ficheiro existe
    if (fd == -1) {  // Caso dê erro ao abrir ficheiro, devolver erro ao utilizador
        perror("erro, o ficheiro não existe ou o caminho é inválido");
        exit(1);
    }
    else{
        close(fd);
        unlink("./ficheiroToDelete.txt"); // Apaga o ficheiro
    }

    return 0;
}

