CC = g++
CFLAGS = -std=c++17

.PHONY: test test2 test3

test:
	$(CC) $(CFLAGS) -o test -pthread -lgtest_main -lgtest algorithms/shortest_paths/tests/test_unweighted.cc
	./test
	rm test

test2:
	$(CC) $(CFLAGS) -o test2 -pthread -lgtest_main -lgtest generators/tests/test_classic.cc
	./test2
	rm test2

test3:
	$(CC) $(CFLAGS) -o test3 -pthread -lgtest_main -lgtest classes/tests/test_function.cc
	./test3
	rm test3
