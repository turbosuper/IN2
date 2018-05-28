CC = gcc
CFLAGS = -c -g -Wall -W -Werror -o 

main: main.o menu.o lib.o ships.o
	$(CC) -o main main.o menu.o lib.o ships.o -lm

main.o : main.c 
	$(CC) $(CFLAGS) main.o main.c

menu.o : menu.c menu.h
	$(CC) $(CFLAGS) menu.o menu.c

lib.o : lib.c lib.h
	$(CC) $(CFLAGS) lib.o lib.c

ships.o: ships.c ships.h datastructure.h
	$(CC) $(CFLAGS) ships.o ships.c 
	
run:
	./main

clean: 
	$(RM) *.o *.out main
