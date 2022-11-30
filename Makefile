AR=ar
CC=gcc
FLAGS= -Wall -g

all:	main

#lib.a:	my_mat.o
#	$(CC) -rcs lib.a my_mat.o
#
#lib.so:	my_mat.o
#	$(CC) -shared -o lib.so my_mat.o

main:	main.o
	$(CC) $(FLAGS) -o main main.o -lm

main.o:	main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

#my_mat.o:	my_mat.c my_mat.h
#	$(CC) $(FLAGS) -c my_mat.c

.PHONY: clean all

clean:
	rm -f *.o main
