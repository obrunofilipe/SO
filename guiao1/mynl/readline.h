#ifndef READLINE_H_
#define READLINE_H_


#define MAX_BUFFER 1024

ssize_t readln1(int fd , char *line , size_t size);
ssize_t readln2(int fd, char *line, size_t size);
void readc(int fd, char *c ); //lê um caracter do buffer
#endif