myprogram: source1.o source2.o source3.o
	gcc -o myprogram source1.o source2.o source3.o
source3.o: source3.c soruce3.h
	gcc -c source3.c
source2.o: source2.c source2.h
	gcc -c source2.c
source1.o: source1.c source1.h source2.h soruce3.h
	gcc -c source1.c
clean:
	rm -f *.o myprogram