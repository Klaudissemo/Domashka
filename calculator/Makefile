cal: main.c func.h func.c
		gcc main.c -c
		gcc func.c -c 
		ar rc libfunc.a func.o
		gcc main.o -o cal -L. -lfunc