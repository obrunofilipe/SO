#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc , char* argv[]){
    argv[0] = "fds";
    execv("exec3",argv);
    return 0;
}