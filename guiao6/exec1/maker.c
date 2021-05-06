#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd;
    fd = mkfifo("./fifo", 0666);
    if (fd != -1 ) printf("pipe criado com sucesso");
    return 0;
}
