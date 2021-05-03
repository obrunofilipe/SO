#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc , char* argv[]){
    int status;
    for(int i = 1; i < argc ; i++){
        if(!fork())
            execlp(argv[i],argv[i],NULL);
    }
    for(int i = 1; i < argc ; i++)
        wait(&status);
    return 0;
}