CC=gcc
CFLAGS=-W -Wall -g -Wextra
EXEC=stackSorting


all: $(EXEC)

stackSorting: main.o log.o
	$(CC) -o stackSorting main.o log.o

main.o: main.c log.h
	$(CC) -o main.o -c main.c $(CFLAGS)

log.o: log.c
	$(CC) -o log.o -c log.c $(CFLAGS)

mrproper: clean
	rm -rf $(EXEC)

clean:
	rm -rf *.o *.h.gch
