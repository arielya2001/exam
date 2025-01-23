# Final executable
prog: main.o other.o
	gcc -o prog main.o other.o

# Object files and their dependencies
main.o: main.c other.h
	gcc -c main.c

other.o: other.c other.h
	gcc -c other.c

run: prog
	./prog

# Clean target
clean:
	rm -f *.o prog
