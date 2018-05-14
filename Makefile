CC = gcc
CFLAGS = -c -g -Wall -W -Werror -o

main: main.o menu.o lib.o tools.o
	$(CC) -o main main.o menu.o lib.o tools.o

main.o : main.c 
	$(CC) $(CFLAGS) main.o main.c

menu.o : menu.c tools.h menu.h
	$(CC) $(CFLAGS) menu.o menu.c

tools.o : tools.c tools.h 
	$(CC) $(CFLAGS) tools.o tools.c

lib.o : lib.c lib.h
	$(CC) $(CFLAGS) lib.o lib.c

run:
	./main

clean: 
	$(RM) *.o *.out main
