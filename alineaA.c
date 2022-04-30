#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/**
 * @brief mostra ficheiro – Este comando deve apresentar no ecrã (todo) o
 * conteúdo do ficheiro indicado como parâmetro. Caso o ficheiro não exista, o comando 
 * deve avisar o utilizador que o ficheiro não existe;
 * Autor: Pedro Meneses
*/


int main(int argc, char *argv[]){
  int fd;
  char buffer[100];
  int n;

  if(argc != 2){
    perror("Erro: Argumentos inválidos ");
    exit(1);
  }
  else{

    fd = open(argv[1], O_RDONLY);

    if(fd == -1){
      perror("Erro: Ficheiro não encontrado");
      exit(1);
    }

    else{

      while((n = read(fd, buffer, 100)) > 0){
        write(1, buffer, n);
      }

    }
  }
  
  
  close(fd);
  return 0;
}

