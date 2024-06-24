all: encrypt

encrypt:	decrypt.o	encrypt.o
	gcc	decrypt.o	encrypt.o	-o	encrypt.exe

decrypt.o:	decrypt.c
	gcc	-c	decrypt.c

encrypt.o:	encrypt.c
	gcc	-c	encrypt.c
