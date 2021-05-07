#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define LINE 1024

int main(){
    int fd,nb_read,wf;
    char* buf = malloc(sizeof(char) * LINE);
    char* cmp;
    mkfifo("./fifo", 0666);
    fd = open("./fifo", O_RDONLY);
    wf = open("./log", O_CREAT | O_RDWR , 0666);
    while (1) {
        nb_read = read(fd,buf,LINE);
        cmp = strdup(buf);
        if(strcmp(cmp,"quit\n") == 0) return 0;
        free(cmp);
        write(wf,buf,nb_read);
    }
}
