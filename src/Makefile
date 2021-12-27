CC = g++
CFLAGS = -std=c++17

.PHONY: test_graph test_digraph

run: main
	./main
	python3 test/test.py

main: main.o
	$(CC) $(CFLAGS) -o main main.o

# The main.o target can be written more simply

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

test_graph:
	$(CC) $(CFLAGS) -o test_graph -pthread -lgtest_main -lgtest classes/tests/test_graph.cpp
	./test_graph
	rm test_graph

test_digraph:
	$(CC) $(CFLAGS) -o test_digraph -pthread -lgtest_main -lgtest classes/tests/test_digraph.cpp
	./test_digraph
	rm test_digraph