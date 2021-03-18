#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
 pid_t pid, p_pid, c_pid;
 int status;
 pid = fork();
 if(pid != 0){
     c_pid = getpid();
     p_pid = getppid();
     printf("\n\nEste é o processo pai: %d\nO seu processo pai é: %d\n",c_pid,p_pid);
     wait(&status);
 }
 else{
    c_pid = getpid();
     p_pid = getppid();
     printf("\n\nEste é o processo filho: %d\nO seu processo pai é: %d\n",c_pid,p_pid); 
 }
 return 0;
}