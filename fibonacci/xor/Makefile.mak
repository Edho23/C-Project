all:	prime

prime:	MainP.o	fungction,o
	gcc	MainP.o	fungction.o	-o	Prime.exe

MainP.o:	MainP.o
	gcc	-c	MainP.o

fungction.o:	fungction.c
	gcc	-c	fungction.c
