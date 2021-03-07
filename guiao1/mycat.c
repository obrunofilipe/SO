#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#define MAX_BUFFER 1024

int main(){
    void *buffer = malloc(MAX_BUFFER);
    int bytes_read;
    //read "bloqueia" até ser introduzido o '\n' 
    while((bytes_read = read(STDIN_FILENO, buffer,MAX_BUFFER) )> 0)
        write(STDOUT_FILENO, buffer,bytes_read);
    return 0;
}