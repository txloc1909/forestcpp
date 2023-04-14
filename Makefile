CC=g++
FLAGS=-Wall -Wextra -Werror -pedantic -std=c++17

all: main run

*.o: *.cpp
	$(CC) $(FLAGS) -c *.cpp

main: *.o
	$(CC) $(FLAGS) *.o -o main

run: main
	./main

clean:
	rm *.o main
