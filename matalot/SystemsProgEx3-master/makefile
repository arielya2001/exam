CC = gcc
AR = ar
CFL = -Wall -g
LFL = rcs
.PHONY: all clean

all: StrList

StrList: main.o libStrList.a
	$(CC) $(CFL) $^ -o $@

main.o:main.c strList.h
	$(CC) $(CFL) -c $<

libStrList.a: strList.o
	$(AR) $(LFL) $@ $<

strList.o: strList.c strList.h
	$(CC) $(CFL) -c $<

clean:
	rm -f *.o *.a StrList