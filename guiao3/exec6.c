#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int mysystem(char* command){
    int status,i = 0;
    char* program;
    char *aux;
    char* args[100];
    aux = strtok(command," ");
    while(aux != NULL) {
        args[i] = aux;
        aux = strtok(NULL," ");
        i++;
    }
    args[i] = NULL;
    fork_ret = fork()
    if(!fork_ret){
        execvp(args[0],args);
        _exit(-1);
    }
    else{
        if(fork_ret == -1){
            return -1;
        }
        else{
            wait(&status);
            if(WIFEXITED(status)) return WEXITSTATUS(status);
        }

    }
    return -1;
}
int main(int argc , char* argv[]){
    int status;
    mysystem(strdup("wc -l -w  exec1.c"));
    return 0;
}