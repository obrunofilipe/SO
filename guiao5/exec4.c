#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ls /etc/passwd | wc -l
//fazer um pipe para ligar os dois comandos
// ls -> precisa de associar o descritor do Stdout ao descritor de escrita no pipe
// wc -> precisa de associar o descritor de stdin ao descritor de leitura do pipe
int main(){
    int fildes[2];
    pipe(fildes); //criação do pipe para ligar os comandos

    switch (fork()) {
        case -1:
            perror("pipe"); //prints de erros ao criar o pipe
            break;

        case 0://filho -> vai ler do pipe e executar wc
            close(fildes[1]); //fechar o descritor de escrita do pipe
            dup2(fildes[0],STDIN_FILENO); // associar o stdin ao descritor de leitura do pipe
            close(fildes[0]); //fechar o descritor de leitura do pipe
            execlp("wc","wc","-l",NULL); // executar o comando wc

        default:
            close(fildes[0]); // fechar o descritor de leitura do pipe
            dup2(fildes[1],STDOUT_FILENO); //associar o descritor de escrita do piep ao Stdout
            close(fildes[1]); //fechar o descritor de escrita no pipe , uma vez que foi duplicado e associado ao stdout
            execlp("ls","ls","/etc/passwd",NULL); // executar o comando
    }

}
