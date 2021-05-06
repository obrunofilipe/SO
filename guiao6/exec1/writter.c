#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd, nb_read;
    char* buf = malloc(sizeof(char) * 500);
    fd = open("./fifo", O_WRONLY);
    while (( nb_read = read(STDIN_FILENO, buf, 500) ) > 0 ) {
        write(fd,buf,nb_read);
    }
    return 0;
}
