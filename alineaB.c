#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

  /**
   * @brief Copy File
   * Este comando deve criar um novo ficheiro, cujo nome é “ficheiro.copia”,
   * cujo conteúdo é uma cópia de (todo) o conteúdo do ficheiro passado como parâmetro no comando,
   * com o nome ficheiro. Caso o ficheiro não exista, deve ser apresentado um aviso ao utilizador;
   * Autor: Pedro Meneses
   */

  int main(int argc, char *argv[]){
    int fd, fd2;
    char buffer[100];
    int n;

    if(argc != 3){
      // write(2,"Erro: Argumentos inválidos\n",29);
      perror("Erro: Argumentos inválidos ");
      exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1){
      // write(2,"Erro: Ficheiro não existe\n",28);
      perror("Erro: Erro ao abrir o ficheiro ");
      exit(1);
    }

    fd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if(fd2 == -1){
      // write(2,"Erro: Ficheiro não existe\n",28);
      perror("Erro: erro ao criar o ficheiro ");
      exit(1);
    }

    while((n = read(fd, buffer, 100)) > 0){
      write(fd2, buffer, n);
    }

    close(fd);
    close(fd2);
    return 0;
  }

  