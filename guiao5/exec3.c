#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "readline.h"



int main(){
    int fildes[2]; //descritores do pipe 0 -> le , 1 -> escreve
    pipe(fildes);
    char* buffer = malloc(sizeof(char) * 1024);
    int nb_read;
    switch (fork()) {
        case -1:
            perror("pipe");
            break;
        case 0: //filho:  vai ler do pipe
            close(fildes[1]);
            dup2(fildes[0],STDIN_FILENO);
            close(fildes[0]);
            execlp("wc","wc",NULL);
        default://pai .> vai escrever no pipe
            close(fildes[0]);
            while((nb_read = readln2(STDIN_FILENO,buffer,1024)) > 0){
                write(fildes[1],buffer,nb_read);
            }
            close(fildes[1]);
            break;
    }
}
