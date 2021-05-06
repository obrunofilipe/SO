mk3: mkfolders readline main exec3
mkfolders:
	$(shell mkdir obj)

readline: readline.h readln.c
	gcc -Wall -Werror -o obj/readline.o -c readln.c

main: exec3.c
	gcc -Wall -Werror -o obj/exec3.o -c exec3.c

exec3: obj/readline.o exec3.c
	gcc -Wall obj/exec3.o obj/readline.o -o exec3

exec5: exec5.c
	gcc -Wall -g -o obj/exec5.o -c exec5.c

final5: readline exec5 exec5.c
	gcc -Wall obj/exec5.o obj/readline.o -o final5
