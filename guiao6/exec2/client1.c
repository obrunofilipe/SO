#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define LINE 1024

int main(){
    int fd = open("./fifo", O_WRONLY);
    int nb_read;
    char* buf = malloc(sizeof(char) * LINE );
    while((nb_read = read(STDIN_FILENO, buf, LINE)) > 0){
        write(fd,buf,nb_read);
    }
}
