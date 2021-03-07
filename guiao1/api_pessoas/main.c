#include "pessoas.h"
#define ficheiro "armazenamento"

int main(int argc , char*argv[]){
    int fd;
    fd = open(ficheiro, O_CREAT | O_RDWR);
    if (!strcmp("-i",argv[1])){
        add_Pessoa(fd,argv[2],argv[3]);


    }
    else if(!strcmp("-u",argv[1])){
        update_Age(fd,argv[2],argv[3]);
    }
    return 0;
}