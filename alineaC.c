#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

 /**
   * @brief Acrescenta origem destino
   * Este comando deve acrescentar(append) de tudo que estiver presente no ficheiro.txt no ficheiroAppend.txt
   *  Caso algum dos ficheiros não exista, deve ser apresentado um aviso ao utilizador.
   * Autor: Pedro Meneses
   */

int main(){
    int fd, fd2;
    char c;

    fd = open("./ficheiro.txt", O_RDONLY); // Designar o nosso fd
    if (fd == -1) {  // Caso dê erro ao abrir ficheiro, devolver erro ao utilizador
        perror("erro, o ficheiro não existe ou o caminho é inválido");
        exit(1);
    }
    else{
        fd2 = open("./ficheiroAppend.txt", O_APPEND | O_WRONLY); // Abrir o ficheiro, caso exista fazemos append e escrevemos no ficheiro de destino

        if(fd2 == -1){
             perror("erro, o ficheiro que queremos fazer append não existe ou o caminho é inválido");
            exit(1); // Caso dê erro.
        }
        else{

            while (read(fd, &c, 1) > 0) {
                write(fd2, &c, 1); // Escreve no ficheiro
            }
        }
    }
    close(fd);
    close(fd2);

    return 0;
}

