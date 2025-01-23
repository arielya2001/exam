CC = gcc 
CFLAGS = -Wall -g # -g flag is used to enable debugging information


all: program

program : debug_main.o
	$(CC) $^ -o $@ -lm


clean:
	rm -f *.o program