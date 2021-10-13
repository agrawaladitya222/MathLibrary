CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic
LFLAGS = -lm


all: mathlib-test

mathlib-test: mathlib.o mathlib-test.o
	$(CC) -o mathlib-test mathlib-test.o mathlib.o $(LFLAGS)

mathlib.o: mathlib.c
	$(CC) $(CFLAGS) -c mathlib.c

mathlib-test.o: mathlib-test.c
	$(CC) $(CFLAGS) -c mathlib-test.c

clean:
	rm *.o mathlib-test
