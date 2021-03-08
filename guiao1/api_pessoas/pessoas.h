#ifndef PESSOAS_H_
#define PESSOAS_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#define Max_Nome 100
#define REGISTOS 3

typedef struct pessoa{
    int idade;
    char nome[Max_Nome];
}*PESSOA;

int add_Pessoa(int fd ,char *pessoa, char* idade);
void update_Age(int fd ,char* pessoa, char* idade);
void update_Age2(int fd, char* n_registo, char* idade);
int load_register(int fd, PESSOA* p1);

#endif