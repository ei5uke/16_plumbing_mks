all: display encrypt

display: display.c
	gcc -o display display.c

encrypt: encrypt.c
	gcc -o encrypt encrypt.c

clean:
	rm display encrypt transfer
	echo Clean done