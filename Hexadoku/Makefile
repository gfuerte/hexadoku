all: hexadoku

second: hexadoku.c
	gcc -g -Wall -Werror -fsanitize=address -std=c11 hexadoku.c -o hexadoku

clean: 
	rm -f hexadoku
