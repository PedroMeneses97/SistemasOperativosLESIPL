#include <sys/types.h>
#include <pwd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

// Ricardo Fernandes e Pedro Meneses

/**
 * @brief informa ficheiro - Este comando deve apresentar no ecrã a informação do
 * sistema em relação a este ficheiro.
 * Apresentar o tipo de ficheiro, o tamanho, o numero de i-nodes, o utilizador dono
 * em formato de texto e as datas de criação, modificação e leitura
 */
int main(int argc, char *argv[])
{
    char buffer[100];
    int n;

    if (argc != 2)
    {
        // write(2,"Erro: Argumentos inválidos\n",29);
        perror("Erro: Argumentos inválidos ");
        exit(1);
    }

    // Função que irá fazer um stat do ficheiro e imprimir as informações
    struct stat info;
    n = stat(argv[1], &info);

    if (n < 0)
    {
        perror("Erro: o ficheiro não existe.");
        exit(1);
    }

    // Designar o nosso user dono
    struct passwd *pw = getpwuid(info.st_uid);
    // Data de Modicação
    time_t t = info.st_mtime;
    struct tm *tm = localtime(&t);
    // Data de leitura
    time_t at = info.st_atime;
    struct tm *atm = localtime(&at);
    // Data de criação
    time_t ct = info.st_ctime;
    struct tm *ctm = localtime(&ct);

    printf("%s\n", "ficheiro.txt");
    printf("\tTipo: ");
    if (S_ISREG(info.st_mode))
    {
        printf("Ficheiro\n");
    }
    else if (S_ISDIR(info.st_mode))
    {
        printf("Diretório\n");
    }
    else if (S_ISCHR(info.st_mode))
    {
        printf("Char Device\n");
    }
    else if (S_ISBLK(info.st_mode))
    {
        printf("Block Device\n");
    }
    else if (S_ISFIFO(info.st_mode))
    {
        printf("FIFO\n");
    }
    else if (S_ISLNK(info.st_mode))
    {
        printf("Link\n");
    }
    else if (S_ISSOCK(info.st_mode))
    {
        printf("Socket\n");
    }
    else
    {
        printf("Tipo desconhecido\n");
        perror("Não encontrado.");
        exit(1);
    }
    printf("\tTamanho: %lld bytes\n", info.st_size);
    printf("\tNúmero de inodes: %llu\n", info.st_ino);
    printf("\tUtilizador: %s\n", pw->pw_name);
    printf("\tData de modificação: %d/%d/%d %d:%d:%d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec);
    printf("\tData de criação: %d/%d/%d %d:%d:%d\n", ctm->tm_mday, ctm->tm_mon + 1, ctm->tm_year + 1900, ctm->tm_hour, ctm->tm_min, ctm->tm_sec);
    printf("\tData de leitura: %d/%d/%d %d:%d:%d\n", atm->tm_mday, atm->tm_mon + 1, atm->tm_year + 1900, atm->tm_hour, atm->tm_min, atm->tm_sec);
    return 0;
}

// int main()
// {

//     // Função que irá fazer um stat do ficheiro e imprimir as informações
//     struct stat info;
//     stat("ficheiro.txt", &info);

//     // Designar o nosso user dono
//     struct passwd *pw = getpwuid(info.st_uid);
//     // Data de Modicação
//     time_t t = info.st_mtime;
//     struct tm *tm = localtime(&t);
//     // Data de leitura
//     time_t at = info.st_atime;
//     struct tm *atm = localtime(&at);
//     // Data de criação
//     time_t ct = info.st_ctime;
//     struct tm *ctm = localtime(&ct);

//     printf("%s\n", "ficheiro.txt");
//     printf("\tTipo: ");
//     if (S_ISREG(info.st_mode))
//     {
//         printf("Ficheiro\n");
//     }
//     else if (S_ISDIR(info.st_mode))
//     {
//         printf("Diretório\n");
//     }
//     else if (S_ISCHR(info.st_mode))
//     {
//         printf("Char Device\n");
//     }
//     else if (S_ISBLK(info.st_mode))
//     {
//         printf("Block Device\n");
//     }
//     else if (S_ISFIFO(info.st_mode))
//     {
//         printf("FIFO\n");
//     }
//     else if (S_ISLNK(info.st_mode))
//     {
//         printf("Link\n");
//     }
//     else if (S_ISSOCK(info.st_mode))
//     {
//         printf("Socket\n");
//     }
//     else
//     {
//         printf("Tipo desconhecido\n");
//         perror("Não encontrado.");
//         exit(1);
//     }
//     printf("\tTamanho: %lld bytes\n", info.st_size);
//     printf("\tNúmero de inodes: %llu\n", info.st_ino);
//     printf("\tUtilizador: %s\n", pw->pw_name);
//     printf("\tData de modificação: %d/%d/%d %d:%d:%d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec);
//     printf("\tData de criação: %d/%d/%d %d:%d:%d\n", ctm->tm_mday, ctm->tm_mon + 1, ctm->tm_year + 1900, ctm->tm_hour, ctm->tm_min, ctm->tm_sec);
//     printf("\tData de leitura: %d/%d/%d %d:%d:%d\n", atm->tm_mday, atm->tm_mon + 1, atm->tm_year + 1900, atm->tm_hour, atm->tm_min, atm->tm_sec);
//     return 0;
// }