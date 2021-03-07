pessoa: main.o pessoas.o
	gcc  -g -o pessoa main.o pessoas.o
main.o: main.c
	gcc  -c -g main.c

pessoas.o: pessoas.c
	gcc  -c -g pessoas.c
clean:
	rm main.o pessoas.o pessoa armazenamento
