main: main.o list.o
	cc main.o list.o -o main
main.o: main.c
	cc -c -g main.c
list.o: list.c
	cc -c -g list.c
clean:
	rm *.o main
