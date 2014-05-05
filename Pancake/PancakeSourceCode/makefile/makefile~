CC=gcc -g -Wall 
TARGET=p1

$(TARGET): main.o printadd.o add.o
	$(CC) main.o printadd.o add.o -o $(TARGET)
main.o: main.h
	$(CC) -c main.c
printadd.o: printadd.h
	$(CC) -c printadd.c
add.o: add.h
	$(CC) -c add.c
	
	
/*
project: some.o some1.o ..
 	cc some.o some1.o .. -o project
//for each some.o
some.o: some.h some.c ..
	cc -c some.c
some1.o: ...
	cc -c some1.c
*/
