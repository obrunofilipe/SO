#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pids[10];
    pid_t tmp_pid, c_pid;
    int i = 0,r;
    // criar processos 10 filhos a partir do processo atual 
    // nao criar processos filhos a partir de processos filhos
    while( i < 10 && (c_pid = fork()) != 0 ){
        pids[i] = c_pid;
        i++;
    }
    if(c_pid == 0){
        printf("Processo filho nº: %d\nPID: %d\nPID(pai): %d",i,getpid(),getppid());
        _exit(i);
    }
    else{
        i = 0;
        while(i < 10){
            tmp_pid = waitpid(pids[i],&r,0);
            if(WIFEXITED(r)){
                r = WEXITSTATUS(r);
                printf("\n:::: Processo %d ::::\n PID: %d \n Saída: %d\n\n",i,pids[i],r);
            }
            i++;
        }
    }
    return 0;
}