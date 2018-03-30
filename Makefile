LIB_NAME 	=	lib_global.a

all: 
	gcc -c *.c	
	find . -name $(LIB_NAME) -type f -delete
	ar r include/$(LIB_NAME) *.o
	ranlib include/$(LIB_NAME)
	rm *.o
	gcc -I ./include -L include/$(LIB_NAME) -include/$(LIB_NAME) test.c -g