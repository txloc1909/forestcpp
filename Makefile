CC=g++

COMMON_FLAGS=-Wall -Wextra -Werror -pedantic -std=c++17

all: main run

main: main.cpp
	$(CC) main.cpp $(COMMON_FLAGS) -o main

run: main
	./main

clean:
	rm ./main
