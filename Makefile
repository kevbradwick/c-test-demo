ROOT_DIR=$(PWD)
CC=gcc
CFLAGS=-Wall
INCLUDE_PATH  = -I $(ROOT_DIR)/include
SOURCES=test/main.c src/contacts.c

all: clean tests

tests:
	$(CC) $(CFLAGS) -lcmocka $(INCLUDE_PATH) $(SOURCES) -o all_tests
	./all_tests

clean:
	rm -rf *.o all_tests
