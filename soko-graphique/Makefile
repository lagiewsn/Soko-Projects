CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=
EXEC=sokoban
BIN=main2.o
SRC=main2.c
HEAD=
GTK_CFLAGS = $(shell pkg-config --cflags gtk+-2.0)
GTK_LDFLAGS = $(shell pkg-config --libs gtk+-2.0)
 
all: $(EXEC)
 
sokoban: $(BIN)
	$(CC) $(BIN) $(GTK_LDFLAGS) -o sokoban 
 
main2.o: main2.c $(HEAD)
	$(CC) $(GTK_CFLAGS) -c $(SRC)
 
clean:
	rm -f *.o *~ 2> /dev/null
 
clear: clean
	rm -f $(EXEC) $(USER)_sokoban.tgz 2> /dev/null
 
zip: clear
	mkdir -p $(USER)_sokoban
	cp Makefile *.c *.h *.sok $(USER)_sokoban
	tar czf $(USER)_sokoban.tgz $(USER)_sokoban
	rm -rf $(USER)_sokoban
