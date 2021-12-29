CC = g++
CFLAGS = -std=c++17

.PHONY: test fast manual_test

test:
	bazel test --test_output=all //:all_tests

fast:
	cmake -S . -B build                                                 
	cmake --build build                                            
	cd build && ctest

manual_test:
	$(CC) $(CFLAGS) -o manual_test -pthread -lgtest_main -lgtest algorithms/shortest_paths/tests/test_unweighted.cc
	./manual_test
	rm manual_test
