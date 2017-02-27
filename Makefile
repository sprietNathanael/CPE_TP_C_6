CC=gcc
CFLAGS=-W -Wall -g -Wextra
EXEC=stackSorting


all: $(EXEC)

stackSorting: main.o log.o stackSorting.o
	$(CC) -o stackSorting main.o log.o stackSorting.o

main.o: main.c log.h stackSorting.h
	$(CC) -o main.o -c main.c $(CFLAGS)

stackSorting.o: stackSorting.c log.h
	$(CC) -o stackSorting.o -c stackSorting.c

log.o: log.c
	$(CC) -o log.o -c log.c $(CFLAGS)

mrproper: clean
	rm -rf $(EXEC)

clean:
	rm -rf *.o *.h.gch
