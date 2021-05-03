#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


int main(int argc ,char** argv){
    int ret, status;
    pid_t pid;
        for(int i = 1 ; i < argc ; i++){
            if((pid = fork()) == 0){
                printf("\nPrograma%d em execução: %s",i,argv[i]);
                ret = execl(argv[i],argv[i],NULL);
                printf("\n :: %d :: \n",ret);
                _exit(-1);
            }
            else{
                printf("Processo [PAI]");
                wait(&status);
            }
        }
}