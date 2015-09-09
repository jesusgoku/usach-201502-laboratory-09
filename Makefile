CC=gcc
CFLAGS=-I./libs -std=c99
DEPS = libs/program.h libs/utilities.h libs/matrix.h
OBJ = main.o libs/program.o libs/utilities.o libs/matrix.o

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
		$(CC) -o main.out $(OBJ) $(CFLAGS)

.PHONY: clean start

start:
		./main.out

clean:
		rm -f main.o libs/*.o
