#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(){

    /**
     * @brief a) mostra ficheiro de texto
     * Se der erro, imprimir no ecrã o erro dado
     */
   
    int fd = open("./ficheiro.txt", O_RDONLY); // Designar o nosso FD 
    if (fd == -1) {  // Caso dê erro
        perror("erro, o ficheiro não existe ou o caminho é inválido");
        exit(1);
    }
    else{
        // Imprime todos os caracteres do ficheiro
        char c;
        while (read(fd, &c, 1) > 0) {
            printf("%c", c);
        }
        
    }




    return 0;
}