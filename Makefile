all: 
	gcc -c *.c
	ar r lib.a *.o
	ranlib lib.a
	rm *.o
	gcc -L lib.a -o oui *.c -g