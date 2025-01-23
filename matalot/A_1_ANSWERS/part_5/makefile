CC = gcc
CFLAGS = -Wall -fPIC

# Libraries
STATIC_LIB = libmath.a
DYNAMIC_LIB = libadvmath.so

# Objects
MATH_OBJ = mathlib.o
ADV_MATH_OBJ = advmath.o
MAIN_OBJ = main.o

all: program

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(STATIC_LIB): $(MATH_OBJ)
	ar rcs $@ $^

$(DYNAMIC_LIB): $(ADV_MATH_OBJ)
	$(CC) -shared -o $@ $^

progComb: $(MAIN_OBJ) $(STATIC_LIB) $(DYNAMIC_LIB)
	$(CC) -o $@ $(MAIN_OBJ) -L. -lmath -ladvmath -Wl,-rpath,.

clean:
	rm -f *.o *.a *.so progComb	

.PHONY: all clean