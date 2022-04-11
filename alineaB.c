#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Feito por Pedro Meneses
int main(){


 
 /**
  * @brief Copy File
  * Copiar um ficheiro original para um ficheiro destino
  */
    int fd = open("./ficheiro.txt", O_RDONLY); // Designar o nosso fd
    if (fd == -1) {  // Caso dê erro
        perror("erro, o ficheiro não existe ou o caminho é inválido");
        exit(1);
    }
    else{
        // Imprime todos os caracteres do ficheiro
        char c;
        int fd2 = open("./ficheiro.copia.txt", O_WRONLY | O_CREAT, 0644);

        if(fd2 == -1){
             perror("erro, o ficheiro.copia não existe ou o caminho é inválido");
            exit(1);
        }
        else{

            while (read(fd, &c, 1) > 0) {
                write(fd2, &c, 1);
            }

        }
    }
    
    return 0;
}