#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char*argv[]){
    int f,cp;
    // argv[1] -> ficheiro para copiar
    // argv[2] -> localizaçao para o ficheiro de escrita
    int nb_read = 1024;
    void *buffer = malloc(BUFFER_SIZE);
    f = open(argv[1],O_RDONLY);
    cp = open(argv[2], O_RDWR | O_CREAT | O_TRUNC,0600);

    while(nb_read == BUFFER_SIZE){
        // quando o read nao conseguir preencher  a totalidade do buffer é sinal que foi atingido o final do ficheiro 
        nb_read = read(f,buffer,BUFFER_SIZE);
        write(cp,buffer,nb_read); // escrever apenas os bytes que foram lidos
    }
    //um buffer implica:
        // mais pequeno implica mais iterações do ciclo
        //mais system calls
    // assim idealmente pretende-se diminuir o numero de chamadas do systema e iteraçoes
    close(f);
    close(cp);
}