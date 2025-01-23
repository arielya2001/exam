CC = gcc
CFLAGS = -Wall

LIB = libmath.a

# Objects
OBJS = mathlib.o
MAIN = main.o

all: program

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)

progStatic: $(MAIN) $(LIB)
	$(CC) -o $@ $(MAIN) -L. -lmath

clean:
	rm -f *.o *.a porgStatic

.PHONY: all clean