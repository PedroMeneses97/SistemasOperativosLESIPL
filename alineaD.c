#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief conta ficheiro- Este comando deve apresentar no ecrã o
 * número de linhas no ficheiro indicado.
 * Caso o ficheiro nao exista, o comando deve avisar que o ficheiro não existe.
 * Feito por Ricardo Fernandes
 */
int main(int argc, char *argv[])
{
    int fd;
    char buffer[100];

    if (argc != 2)
    {
        // write(2,"Erro: Argumentos inválidos\n",29);
        perror("Erro: Argumentos inválidos ");
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        // write(2,"Erro: Ficheiro não existe\n",28);
        perror("Erro: Argumentos inválidos");
        exit(1);
    }
    else
    {
        char c;
        int count = 0;

        // Corre todos os caracters do ficheiro e por cada '\n' ou se
        // o caracter estive no final do ficheiro adiciona mais um ao valor do contador.
        while (read(fd, &c, 1) > 0)
        {

            if (c == '\n' || c == EOF)
            {
                count++;
            }
        }

        // Imprime o valor do contador
        printf("O ficheiro tem %d linhas", count);

        // Fecha o fd
        close(fd);
    }

    return 0;
}
// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>

// /**
//  * @brief conta ficheiro- Este comando deve apresentar no ecrã o
//  * número de linhas no ficheiro indicado.
//  * Caso o ficheiro nao exista, o comando deve avisar que o ficheiro não existe.
//  * Feito por Ricardo Fernandes
//  */
// int main(int argc, char *argv[])
// {

//     int fd = open("./ficheiro2.txt", O_RDONLY); // Designar o nosso fd

//     if (fd == -1)
//     { // Caso dê erro
//         perror("erro, o ficheiro não existe ou o caminho é inválido");
//         exit(1);
//     }
//     else
//     {
//         char c;
//         int count = 0;

//         // Corre todos os caracters do ficheiro e por cada '\n' ou se
//         // o caracter estive no final do ficheiro adiciona mais um ao valor do contador.
//         while (read(fd, &c, 1) > 0)
//         {

//             if (c == '\n' || c == EOF)
//             {
//                 count++;
//             }
//         }

//         // Imprime o valor do contador
//         printf("O ficheiro tem %d linhas", count);

//         // Fecha o fd
//         close(fd);
//     }

//     return 0;
// }
