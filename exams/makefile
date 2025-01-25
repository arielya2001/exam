prog: moed_b_2020.o
	gcc -o prog moed_b_2020.o
moed_b_2020.o: moed_b_2020.c
	gcc -c moed_b_2020.c
run: prog
	./prog
clean:
	rm -f *.o prog