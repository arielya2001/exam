prog1: test.c
	@gcc -o prog1 test.c
run: prog1
	@./prog1
clean:
	@rm -f prog1