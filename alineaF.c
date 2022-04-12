#include <sys/types.h>
#include <pwd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

// Ricardo Fernandes e Pedro Meneses

int main(){

    // Função que irá fazer um stat do ficheiro e imprimir as informações
        struct stat info;
        stat("ficheiro.txt", &info);
        struct passwd *pw = getpwuid(info.st_uid);
        time_t t = info.st_mtime;
        struct tm *tm = localtime(&t);

        printf("%s\n", "ficheiro.txt");
        printf("\tTipo: ");
        if(S_ISREG(info.st_mode)){
            printf("Ficheiro\n");
        }
        else if(S_ISDIR(info.st_mode)){
            printf("Diretório\n");
        }
        else if(S_ISCHR(info.st_mode)){
            printf("Char Device\n");
        }
        else if(S_ISBLK(info.st_mode)){
            printf("Block Device\n");
        }
        else if(S_ISFIFO(info.st_mode)){
            printf("FIFO\n");
        }
        else if(S_ISLNK(info.st_mode)){
            printf("Link\n");
        }
        else if(S_ISSOCK(info.st_mode)){
            printf("Socket\n");
        }
        else{
            printf("Tipo desconhecido\n");
            perror("Não encontrado.");
            exit(1);
        }
        printf("\tTamanho: %lld bytes\n", info.st_size);
        printf("\tNúmero de inodes: %llu\n", info.st_ino);
        printf("\tUtilizador: %s\n", pw->pw_name);
        printf("\tData de modificação: %d/%d/%d %d:%d:%d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec);
        printf("\tData de criação: %d/%d/%d %d:%d:%d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec);
        printf("\tData de leitura: %d/%d/%d %d:%d:%d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec);
    return 0;
}