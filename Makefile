CC = g++
FLAGS = -g -std=c++11

all:
	$(CC) $(FLAGS) actonization-test-1.cpp -o actonization-test-1

clean:
	rm -f actonization-test-1
