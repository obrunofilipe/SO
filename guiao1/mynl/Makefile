
mynl: mynl.o readln.o
	gcc -O -g -o  mynl mynl.o readln.o
readln.o: readln.c
	gcc  -O -c -g readln.c
mynl.o: mynl.c
	gcc -O -c -g  mynl.c
clean:
	rm mynl mynl.o readln.o 
