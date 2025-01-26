prog: moed_b_2024.o
	gcc -o prog moed_b_2024.o -lm
moed_b_2024.o: moed_b_2024.c
	gcc -c moed_b_2024.c
run: prog
	./prog
clean:
	rm -f *.o prog