CC = gcc
CFLAGS = -Wall -Wextra

all: bank_queue

bank_queue: main.o queue.o
	$(CC) $(CFLAGS) -o bank_queue main.o queue.o

main.o: main.c queue.h
	$(CC) $(CFLAGS) -c -o main.o main.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c -o queue.o queue.c

clean:
	rm -f bank_queue main.o queue.o
