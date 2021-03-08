#include "pessoas.h"
#define ficheiro "armazenamento"
#define OUTPUT_SIZE 13

int main(int argc , char*argv[]){
    int fd, registo;
    char output[20];
    fd = open(ficheiro, O_CREAT | O_RDWR);
    if (!strcmp("-i",argv[1])){
        registo = add_Pessoa(fd,argv[2],argv[3]);
        sprintf(output,"\nregister: %d",registo);
        write(STDOUT_FILENO,output,OUTPUT_SIZE);
    }
    else if(!strcmp("-u",argv[1])){
        update_Age(fd,argv[2],argv[3]);
    }
    else if(!strcmp("-r",argv[1])){
        update_Age2(fd,argv[2],argv[3]);
    }
    return 0;
}