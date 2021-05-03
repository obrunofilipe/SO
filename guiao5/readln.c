#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "readline.h"

char * buffer ;
int buffer_index = 0;
int buffer_end = 0;

ssize_t readln1(int fd , char *line , size_t size){
    char c;
    int line_size = 0;
    read(fd,&c,1);
    while(c != '\n' && line_size < size){
        line[line_size++] = c;
        read(fd,&c,1);
    }
    line[line_size++] = c;
    return line_size;
}
//refazer a readline
ssize_t readln2(int fd, char *line, size_t size){
    int line_size = 0;
    char c;
    buffer = malloc(MAX_BUFFER * sizeof(char));
    readc(fd,&c);
    while(c != '\n' && buffer_end > 0){
        line[line_size]  = c;
        line_size++;
        readc(fd,&c);
    }
    if(buffer_end > 0){
        line[line_size] = c;
        line_size++;
    }
    return line_size;
}

void readc(int fd, char *c){
    //se o buffer já foi totalmente percorrido
    if(buffer_index == buffer_end){
        //é necessario carregar mais informação da memoria
        buffer_end = read(fd,buffer,MAX_BUFFER);
        buffer_index = 0;
        if(buffer_end > 0 ){
            (*c) = buffer[buffer_index];
            buffer_index++;
        }
    }
    else{
        (*c) = buffer[buffer_index];
        buffer_index++; 
    }
} 

