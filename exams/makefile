prog: moed_b_2023.o
	gcc -o prog moed_b_2023.o -lm
moed_b_2023.o: moed_b_2023.c
	gcc -c moed_b_2023.c
run: prog
	./prog
clean:
	rm -f *.o prog