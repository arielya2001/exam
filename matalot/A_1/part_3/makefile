prog: main.o lib.a
	gcc -o prog main.o lib.a
lib.a: mathlib.o 
	ar rcs -o lib.a mathlib.o
mathlib.o: mathlib.c mathlib.h
	gcc -c mathlib.c 
main.o: main.c mathlib.h
	gcc -c main.c
run: prog
	./prog
clean:
	rm -f *.o lib.a prog