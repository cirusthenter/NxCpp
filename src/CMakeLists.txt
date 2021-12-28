cmake_minimum_required(VERSION 3.14)
project(NxCpp)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include(GoogleTest)

# The following add_executable-target_link_libraries-gtest_discover_test loop should be changed
add_executable(test_graph classes/tests/test_graph.cc)
target_link_libraries(test_graph gtest_main)
gtest_discover_tests(test_graph)

add_executable(test_digraph classes/tests/test_digraph.cc)
target_link_libraries(test_digraph gtest_main)
gtest_discover_tests(test_digraph)

add_executable(test_function classes/tests/test_function.cc)
target_link_libraries(test_function gtest_main)
gtest_discover_tests(test_function)

add_executable(test_classic generators/tests/test_classic.cc)
target_link_libraries(test_classic gtest_main)
gtest_discover_tests(test_classic)

add_executable(test_lattice generators/tests/test_lattice.cc)
target_link_libraries(test_lattice gtest_main)
gtest_discover_tests(test_lattice)

add_executable(test_shortest_paths_unweighted algorithms/shortest_paths/tests/test_unweighted.cc)
target_link_libraries(test_shortest_paths_unweighted gtest_main)
gtest_discover_tests(test_shortest_paths_unweighted)
