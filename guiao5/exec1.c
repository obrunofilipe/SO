#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>



int main(){
  char buffer[20];
  int pd[2]; //descritor de ficheiros
  int n_lidos;
  //pd[0] lê
  //pd[1] escreve
  //pipe(pd[2])
  if(pipe(pd) == 0){
    switch(fork()){
      case 0: //filho
        //filho vai escrever
        close(pd[0]);
        strcpy(buffer,"filho escreveu");
        n_lidos = write(pd[1], &buffer, 20);
        close(pd[1]); //fechar o descritor de escrita para evitar um deadlock
        _exit(0);
      case -1: //erro
        perror("fork");
        return -1;
      default: //pai
        //pai vai ler
        close(pd[1]); //fechar o descritor de escrita para evitar um deadlock
        n_lidos = read(pd[0],&buffer,20);
        printf("[PAI]: %s\n",buffer);
        close(pd[0]);
        _exit(0);
    }
  }
  else{
    perror("pipes");
  }
  return 0;
}
