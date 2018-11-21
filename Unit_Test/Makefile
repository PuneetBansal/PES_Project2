#-*-Makefile-*-

proj2: main.o circular_buffer.o
	gcc main.c circular_buffer.c -o -proj2 -lm
main.o: main.c circular_buffer.h
	gcc -c main.c
circular_buffer.o: circular_buffer.c circular_buffer.h
	gcc -c circular_buffer.c
test1: test.c circular_buffer.c circular_buffer.h
	gcc test.c circular_buffer.c -lm -lcunit -o test1 
clean:
	rm *.o


