prog: targilim.o
	gcc -o prog targilim.o
targilim.o: targilim.c
	gcc -c targilim.c
run: prog
	./prog
clean:
	rm -f *.o prog