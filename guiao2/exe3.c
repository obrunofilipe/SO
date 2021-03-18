#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t ppid, pid;
    int r;
    // criar processos 10 filhos a partir do processo atual 
    // nao criar processos filhos a partir de processos filhos
    for(int i = 0 ; i < 10 ; i++){
        if(fork() == 0){
            ppid = getppid();
            pid = getpid();
            printf(":::: Processo %d ::::\n PID: %d\n PID(pai): %d\n",i,pid,ppid);
            _exit(i);
        }
        wait(&r);
        if(WIFEXITED(r)){
            r  = WEXITSTATUS(r);
            printf(" Saída: %d\n",r);
        }
    }
    return 0;
}