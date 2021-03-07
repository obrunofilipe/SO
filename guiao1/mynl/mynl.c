#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "readline.h"


int main(){
    int line_size, lc = 1;
    char line[MAX_BUFFER];
    char line_number[5];
    line_size = 0;
    while((line_size = readln2(STDIN_FILENO,line,MAX_BUFFER)) > 0){
        sprintf(line_number, " %d:",lc);
        if(line[0] != '\n'){
            write(STDOUT_FILENO, line_number,5);
            write(STDOUT_FILENO,line,line_size);
            lc++;
        }
    }
    return 0;
}