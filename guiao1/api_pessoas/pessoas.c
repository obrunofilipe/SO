#include "pessoas.h"

int load_register(int fd, PESSOA* p1){
    void *buffer = malloc(sizeof(struct pessoa));
    int bread = 0;
    bread = read(fd,buffer,sizeof(struct pessoa));
    if(bread > 0) (*p1) = buffer;
    //free(buffer);
    return bread;
}
void add_Pessoa(int fd ,char *pessoa, char* idade){
    int wb = 0;
    lseek(fd,0,SEEK_END);
    PESSOA p1 = malloc(sizeof(struct pessoa));
    p1->idade = atoi(idade);
    strcpy(p1->nome ,pessoa);
    wb = write(fd,p1,sizeof(struct pessoa));
}

void update_Age(int fd, char* pessoa, char* idade){
    int bread = 0;
    PESSOA p1 = malloc(sizeof(struct pessoa));
    bread = load_register(fd,&p1);
    while(bread > 0 && strcmp(p1->nome, pessoa) != 0){
        bread = load_register(fd,&p1);
    }
    if(strcmp(p1->nome,pessoa) == 0){
        p1->idade = atoi(idade);
        lseek(fd,-bread,SEEK_CUR);
        write(fd,p1,sizeof(struct pessoa));
    }
    //free(p1);
}