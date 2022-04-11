#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Feito por Ricardo Fernandes
 */
int main(){

    int fd = open("./ficheiro2.txt", O_RDONLY); // Designar o nosso fd
  
    if (fd == -1)
    { // Caso dê erro
        perror("erro, o ficheiro não existe ou o caminho é inválido");
        exit(1);
    }
    else
    {
        // Imprime todos os caracteres do ficheiro
        char c;
        int count = 0;

        while (read(fd, &c, 1) > 0 )
        {

            if (c == '\n' || c == EOF){
                count++;
            }

        }

        printf("O ficheiro tem %d linhas", count);
    }

    return 0 ;
}
