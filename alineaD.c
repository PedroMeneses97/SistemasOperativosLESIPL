#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief conta ficheiro- Este comando deve apresentar no ecrã o
 * número de linhas no ficheiro indicado como parâmetro.
 * Caso o ficheiro não exista, o comando deve avisar que o ficheiro não existe.
 * Feito por Ricardo Fernandes
 */
int main(int argc, char *argv[])
{
    int fd;

    if (argc != 2)
    {
        perror("Erro: Argumentos inválidos ");
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Erro: Ficheiro não existe");
        exit(1);
    }
    else
    {
        char c;
        int count = 0;

        while (read(fd, &c, 1) > 0)
        {

            if (c == '\n' || c == EOF)
            {
                count++;
            }
        }

        printf("O ficheiro tem %d linhas", count);

        close(fd);
    }

    return 0;
}
