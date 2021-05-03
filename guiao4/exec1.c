#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//exec4 ->
// dup2(ifd , 0) -> redirecionar o stdout para o  descritor de ficheiro ifd
// dup -> duplica o descritor de ficheiro
// bzero -> inicializar bytes a zero



int main(){
    int ifd = open("bash",O_RDONLY );
    int ofd = open("saida.txt", O_CREAT | O_TRUNC | O_WRONLY , 0666);
    int efd = open("erros.txt", O_CREAT | O_TRUNC | O_WRONLY , 0666);


}
