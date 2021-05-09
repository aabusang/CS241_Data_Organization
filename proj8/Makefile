main: main.o list.o
	cc main.o list.o -o -g main
main.o: main.c
	cc -c main.c
list.o: list.c
	cc -c list.c
run:
	./main arrivals.log mylist.txt
clean:
	rm *.o main
