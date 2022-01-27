CC = g++
CFLAGS = -std=c++17

.PHONY: main test fast manual_test

main:
	g++ main.cpp -o ./main -std=c++17
	./main

test:
	bazel test --test_output=all //:all_tests

fast:
	cmake -S . -B build                                                 
	cmake --build build                                            
	cd build && ctest

manual_test:
	$(CC) $(CFLAGS) -o manual_test -pthread -lgtest_main -lgtest readwrite/tests/test_read_file.cc
	./manual_test
	rm manual_test
