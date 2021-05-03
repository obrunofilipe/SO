#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    execlp("ls","ls","-l",NULL);
    return 0;
}