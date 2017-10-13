##Linkedlist
CC = gcc

#Complile
linkedlist.o: linkedlist.h linkedlist.c
	$(CC) linkedlist.c -c

tarball: linkedlist.c linkedlist.h MAKEFILE
	tar -cvf linkedlist_src.tar.gz linkedlist.h linkedlist.c MAKEFILE

