#include "pessoas.h"
#define ficheiro "armazenamento"

int main(int argc , char*argv[]){
    int fd;
    fd = open(ficheiro, O_CREAT | O_RDWR);
    printf("fd: %d\n",fd);
    if (!strcmp("-i",argv[1])){
        printf("add_Pessoa() %s %s",argv[2],argv[3]);
        add_Pessoa(fd,argv[2],argv[3]);


    }
    else if(!strcmp("-u",argv[1])){
        //printf("update_Age()");
        update_Age(fd,argv[2],argv[3]);
    }
    return 0;
}