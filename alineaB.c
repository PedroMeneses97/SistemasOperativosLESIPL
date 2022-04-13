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

int main()
{
  // Instanciar os filedescriptors, um char para depois imprimirmos do ficheiro, e os dois ficheiros.
  int fd1, fd2;
  char c;
  char *nome_ficheiro = "ficheiro.txt";
  char *nome_ficheiro_copia = "ficheiro.copia.txt";

  fd1 = open(nome_ficheiro, O_RDONLY); // Abrir o ficheiro para leitura

  if (fd1 == -1)
  {
    perror("Ficheiro nao existe\n"); // Caso dê erro ao abrir ficheiro, devolver erro ao utilizador
    exit(1);
  }

  else
  {
    fd2 = open(nome_ficheiro_copia, O_WRONLY | O_CREAT, 0644); // Abrir o ficheiro para escrita , criar se não existir , com permissões de leitura e escrita
    
    if (fd2 == -1)
    {
      perror("Erro ao criar ficheiro\n"); // Caso dê erro ao abrir ficheiro, devolver erro ao utilizador
      return -1;
    }

    else
    {

      while (read(fd1, &c, 1) > 0) // le o fd1 e escreve no fd2
      {
        write(fd2, &c, 1);
      }

    }
  }
  close(fd1);
  close(fd2);

  return 0;
}