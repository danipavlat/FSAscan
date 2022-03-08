CC := gcc
CFLAGS := -g -Wall
OBJ := main.o scanner.o testScanner.o errors.o token.o
DEPS := errors.h token.h scanner.h

all: scanner clean

%.o: %.c main.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

scanner: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
.PHONY: clean

clean:
	rm -rf *.o