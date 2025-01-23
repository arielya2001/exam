prog: main.o advmath.so mathlib.a
	gcc -o prog main.c ./advmath.so mathlib.a -lm
main.o: main.c mathlib.h advmath.h
	gcc -fpic -c main.c
advmath.so: advmath.c advmath.h
	gcc -fpic -shared -o advmath.so advmath.c -lm
mathlib.a: mathlib.o
	ar rcs mathlib.a mathlib.o
mathlib.o: mathlib.c mathlib.h
	gcc -c mathlib.c
run: prog
	./prog
clean:
	rm -f *.o advmath.so mathlib.a prog

