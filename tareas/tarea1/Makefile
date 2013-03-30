all:
	gcc -c evento.c -o evento.o -I./include
	ar -rcs lib/libevento.a -o evento.o
	gcc main.c -o main -L./lib -levento 

clean:
	rm *.o lib/*.a
