CC = g++
CFLAGS = -std=c++17

.PHONY: test test2 test3

run: main
	./main
	python3 test/test.py

main: main.o
	$(CC) $(CFLAGS) -o main main.o

# The main.o target can be written more simply

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

test:
	$(CC) $(CFLAGS) -o test -pthread -lgtest_main -lgtest algorithms/shortest_paths/tests/test_unweighted.cc
	./test
	rm test

test2:
	$(CC) $(CFLAGS) -o test2 -pthread -lgtest_main -lgtest generators/tests/test_lattice.cc
	./test2
	rm test2

test3:
	$(CC) $(CFLAGS) -o test3 -pthread -lgtest_main -lgtest classes/tests/test_function.cc
	./test3
	rm test3