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
	# $(CC) $(CFLAGS) -o manual_test -pthread -lgtest_main -lgtest generators/tests/test_classic.cc
	# $(CC) $(CFLAGS) -o manual_test -pthread -lgtest_main -lgtest generators/tests/test_random_graphs.cc
	$(CC) $(CFLAGS) -o manual_test -pthread -lgtest_main -lgtest algorithms/community/tests/test_louvain.cc
	# $(CC) $(CFLAGS) -o manual_test -pthread -lgtest_main -lgtest algorithms/community/tests/test_quality.cc
	# $(CC) $(CFLAGS) -o manual_test -pthread -lgtest_main -lgtest classes/tests/test_graph.cc
	# $(CC) $(CFLAGS) -o manual_test -pthread -lgtest_main -lgtest -v algorithms/community/tests/test_utils.cc
	# $(CC) $(CFLAGS) -o manual_test -pthread -lgtest_main -lgtest algorithms/components/tests/test_connected.cc
	./manual_test
	rm manual_test
