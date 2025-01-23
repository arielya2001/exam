prog: main.o advmath.so
	gcc -o prog main.o ./advmath.so -lm
main.o: main.c advmath.h
	gcc -fpic -c main.c
advmath.so: advmath.c
	gcc -fpic -shared -o advmath.so advmath.c -lm
run: prog
	./prog
clean:
	rm -f *.o prog advmath.so