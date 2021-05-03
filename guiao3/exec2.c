#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    pid_t pid ;
    if(!fork()){
        execlp("ls","ls","-l",NULL);
        _exit(0);
    }
    wait(0);
    printf("processo filho executado\n");
    perror("Errors");
    return 0;
}