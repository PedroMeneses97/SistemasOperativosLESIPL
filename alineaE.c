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

int main(int argc, char *argv[]){
    int fd;

    if(argc != 2){
        perror("Erro: Argumentos inválidos ");
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1){
        perror("Erro: Erro ao abrir o ficheiro ");
        exit(1);
    }
    else{
        close(fd);
        unlink(argv[1]);
    }

    return 0;
}
