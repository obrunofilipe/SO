#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t ppid,pid;
    int i = 0,status;
    while(!fork() && i < 10)
        i++;
    wait(&status);
    pid = getpid();
    ppid = getppid();
    printf("PID: %d\nPID(pai): %d\n\n",pid,ppid);
    return 0;
}