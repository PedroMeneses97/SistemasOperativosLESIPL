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
    int n;

    if (argc != 2)
    {
        perror("Erro: Argumentos inválidos ");
        exit(1);
    }

    struct stat info;
    n = stat(argv[1], &info);

    if (n < 0)
    {
        perror("Erro: o ficheiro não existe.");
        exit(1);
    }

    struct passwd *pw = getpwuid(info.st_uid);

    time_t t = info.st_mtime;
    struct tm *tm = localtime(&t);

    time_t at = info.st_atime;
    struct tm *atm = localtime(&at);

    time_t ct = info.st_ctime;
    struct tm *ctm = localtime(&ct);

    write(STDOUT_FILENO, "\tTipo: ", 6);
    if (S_ISREG(info.st_mode))
    {
        write(STDOUT_FILENO, "Ficheiro\n", 10);
    }
    else if (S_ISDIR(info.st_mode))
    {
        write(STDOUT_FILENO, "Diretório\n", 11);
    }
    else if (S_ISCHR(info.st_mode))
    {
        write(STDOUT_FILENO, "Char Device\n", 13);
    }
    else if (S_ISBLK(info.st_mode))
    {
        write(STDOUT_FILENO, "Block Device\n", 14);
    }
    else if (S_ISFIFO(info.st_mode))
    {
        write(STDOUT_FILENO, "FIFO\n", 6);
    }
    else if (S_ISLNK(info.st_mode))
    {
        write(STDOUT_FILENO, "Link\n", 13);
    }
    else if (S_ISSOCK(info.st_mode))
    {
        write(STDOUT_FILENO, "Socket\n", 8);
    }
    else
    {
        write(STDOUT_FILENO, "Tipo desconhecido\n", 19);
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
