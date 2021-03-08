#include "pessoas.h"

int load_register(int fd, PESSOA* p1){
    void *buffer = malloc(sizeof(struct pessoa));
    int bread = 0;
    bread = read(fd,buffer,sizeof(struct pessoa));
    if(bread > 0) (*p1) = buffer;
    //free(buffer);
    return bread;
}
int add_Pessoa(int fd ,char *pessoa, char* idade){
    int offset = 0, size_pessoa, registo;
    offset = lseek(fd,0,SEEK_END);
    size_pessoa = sizeof(struct pessoa);
    registo = offset / size_pessoa;
    PESSOA p1 = malloc(size_pessoa);
    p1->idade = atoi(idade);
    strcpy(p1->nome ,pessoa);
    write(fd,p1,sizeof(struct pessoa));
    return registo;
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

void update_Age2(int fd, char* n_registo, char* idade){
    int registo_update, byte_offset, bread;
    PESSOA p = malloc(sizeof(struct pessoa));
    registo_update = atoi(n_registo);
    byte_offset = sizeof(struct pessoa) * registo_update;
    lseek(fd,byte_offset,SEEK_CUR);
    bread = read(fd,p,sizeof(struct pessoa));
    lseek(fd,-bread,SEEK_CUR);
    p->idade = atoi(idade);
    write(fd,p,sizeof(struct pessoa));
}