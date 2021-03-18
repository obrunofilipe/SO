#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int status, i;
    for(i = 0 ; i < 10 ; i++){
        if(!fork()){
            _exit(i);
        }
    }
    while(wait(&status) != -1 ){
        if(WEXITSTATUS(status)) printf("\nProcesso filho: %d",WEXITSTATUS(status));
    }
    return 0;  
}

