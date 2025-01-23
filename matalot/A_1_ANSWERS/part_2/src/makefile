CC = gcc
CFLAGS = -Wall
INCLUDES = -I../Include

prog: main.o character.o shiny.o armor.o
	$(CC) $^ -o $@

armor.o: armor.c
character.o: character.c
main.o: main.c
shiny.o: shiny.c

clean:
	rm -f *.o prog
