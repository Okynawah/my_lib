all: 
	gcc -c *.c
	ar r lib.a *.o
	ranlib lib.a
	rm *.o

tes:
	gcc -I include -L lib.a -o oui a/test.c