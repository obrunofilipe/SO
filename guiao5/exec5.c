#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define NUM_CMDS 4
#define LINE 1024

void parse_args(char* f_call , char ** final_args){
    int i;
    for( i = 0;f_call != NULL ; i++){
        if(i == 0){
            final_args[i] = strdup(strsep(&f_call, " "));
        }
        else final_args[i] = strdup(strsep(&f_call," "));
    }
    final_args[i] = NULL;
}

int main(){
    char** cmds;
    cmds = malloc(sizeof(char*) * 4 );
    cmds[0] = strdup("grep -v ^# /etc/passwd");
    cmds[1] = strdup("cut -f7 -d:");
    cmds[2] = strdup("uniq");
    cmds[3] = strdup("wc -l");
    char* exec_command, **cmd_args;
    int p_fildes[4][2], cmd_count, cmd_total, nb_read;
    cmd_total = NUM_CMDS;
    cmd_count = 0;
    char* buf = malloc(sizeof(char)*LINE);
    cmd_args = malloc(sizeof(char*) * 10);
    while(cmd_count < cmd_total){

        if(cmd_count == 0){
            pipe(p_fildes[cmd_count]); //criar o pipe para os processos filhos comunicarem
            switch (fork()) {
                case -1:
                    perror("pipe");
                    break;
                case 0: //filho
                    close(p_fildes[cmd_count][0]);// fechar o descritor de leitura
                    parse_args(cmds[cmd_count],cmd_args);
                    dup2(p_fildes[cmd_count][1], STDOUT_FILENO);
                    close(p_fildes[cmd_count][1]);
                    if(execvp(cmd_args[0], cmd_args) == -1) printf("nao executou\n");
                    break;
                default:
                    //close(p_fildes[cmd_count][0]);
                    //close(p_fildes[cmd_count][1]); //fechar os desc. associados ao pipe no processo pai
                    break;
            }
        }

        else if(cmd_count == cmd_total - 1 ){
            close(p_fildes[cmd_count - 1][1]);//fechar os desc. de escrita associado ao pipe anterior
            switch (fork()) {
                case 0:
                    dup2(p_fildes[cmd_count - 1 ][0], STDIN_FILENO);
                    close(p_fildes[cmd_count -1 ][0]);
                    parse_args(cmds[cmd_count],cmd_args);
                    if(execvp(cmd_args[0],cmd_args) == -1)printf("nao executou\n");
                    break;
            }

        }
        else{
            pipe(p_fildes[cmd_count]);
            close(p_fildes[cmd_count - 1][1]);//fechar o descritor de escrita do pipe anterior
            switch (fork()) {
                case 0://filho
                    dup2(p_fildes[cmd_count - 1][0],STDIN_FILENO); //redirecionar o desc. de leitura do pipe do comando anterior par o stdin
                    dup2(p_fildes[cmd_count][1],STDOUT_FILENO); //redirecionar o desc. de escrita do novo pipe associado à execução deste comando para o stdout
                    close(p_fildes[cmd_count - 1][0]); //fechar o descritor de leitura
                    close(p_fildes[cmd_count][1]);//fechar o descritor de escrita
                    parse_args(cmds[cmd_count],cmd_args);//fragmentar o comando nos seus argumentos
                    if(execvp(cmd_args[0],cmd_args) == -1) printf("\n nao executou \n");//executar os comandos
                    break;
                default:
                    //close(p_fildes[cmd_count][0]);
                    //close(p_fildes[cmd_count][1]); //fechar os desc. associados ao pipe no processo pai
                    break;

            }
        }
        cmd_count++;
    }
}
