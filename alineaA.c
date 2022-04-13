#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Feito por Pedro Meneses
int main(){

    int fd;
    char c;
    char *nome_ficheiro = "ficheiro.txt";

    fd = open(nome_ficheiro, O_RDONLY); // Designar o nosso fd    
    if (fd == -1) {  // Se o FD vier com -1 é porque o caminho ou o ficheiro está errado/não existe
        perror("erro, o ficheiro não existe ou o caminho é inválido");
        exit(1);
    }
    else{
        // Imprime todos os caracteres do ficheiro
        while (read(fd, &c, 1) > 0) {   // ssize_t read(int fildes, void *buf, size_t nbyte);
            printf("%c", c);
        }
        close(fd);
    }
    return 0;
}