#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pidp, pid;
    pid = getpid();
    pidp = getppid();   
    printf("PID processo pai: %d \nPID processo atual: %d\n",pidp,pid);
    return 0;
}