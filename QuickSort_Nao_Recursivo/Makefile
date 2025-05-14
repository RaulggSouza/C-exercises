CC = gcc
CFLAGS = -Wall -Wextra

all: stack_quick_sort

stack_quick_sort: main.o funcoes.o
	$(CC) $(CFLAGS) -o stack_quick_sort main.o funcoes.o

main.o: main.c funcoes.h
	$(CC) $(CFLAGS) -c -o main.o main.c

funcoes.o: funcoes.c funcoes.h
	$(CC) $(CFLAGS) -c -o funcoes.o funcoes.c

clean:
	rm -f stack_quick_sort main.o funcoes.o
