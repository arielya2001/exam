prog: main.o shiny.o character.o armor.o
	gcc -I../Include -o prog main.o shiny.o character.o armor.o
main.o: main.c ../Include/character.h
	gcc -I../Include -c main.c
shiny.o: shiny.c ../Include/shiny.h
	gcc -I../Include -c shiny.c
character.o: character.c ../Include/character.h
	gcc -I../Include -c character.c
armor.o: armor.c ../Include/armor.h
	gcc -I../Include -c armor.c
run: prog
	./prog
clean:
	rm -f *.o prog
