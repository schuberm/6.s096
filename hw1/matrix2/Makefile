CC := gcc
#CFLAGS := -O0 -g -std=c99 -Wall -Wextra -Wshadow -pedantic -Werror
#CXXFLAGS := -O0 -g -std=c++11 -Wall -Wextra -Wshadow -pedantic -Weffc++ -Werror
CFLAGS = -Wall

%.o: %.cc $(DEPS)
		$(CC) $(CFLAGS) -c -o $@ $<

matrix2: matrix2.o
		$(CC) $(CFLAGS) -o $@ $^

clean:
		rm -rf *o main
