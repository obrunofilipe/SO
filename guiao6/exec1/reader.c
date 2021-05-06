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
    fd = open("./fifo", O_RDONLY);
    while (( nb_read = read(fd, buf, 500) )> 0 ) {
        write(STDOUT_FILENO,buf,nb_read);
    }
    return 0;
}
