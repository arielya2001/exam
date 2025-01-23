

#simple makefile to compile the program

all: prog

prog: main.o other.o
	gcc -o main main.o

# implicit rules
main.o: main.c other.h
	gcc -c $< -o $@

other.o: other.c other.h
	gcc -c $< -o $@