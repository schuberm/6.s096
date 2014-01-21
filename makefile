CXX = g++
CC = gcc
CFLAGS = -Wall
LDFLAGS =
DEPS =
OBJ = 

%.o: %.cc $(DEPS)
		$(CC) $(CFLAGS) -c -o $@ $<

hello: hello.o
		$(CC) $(CFLAGS) -o $@ $^

floating: floating.o
		$(CC) $(CFLAGS) -o $@ $^

clean:
		rm -rf *o main