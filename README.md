# NxCpp: C++ Library for Graph Traversal

NxCpp is an **unofficial** C++ version of [NetworkX](https://github.com/networkx/networkx).

According to [NetworkX](https://github.com/networkx/networkx), NetworkX is a Python package for the creation, manipulation, and study of the structure, dynamics, and functions of complex networks.

- **Website (including documentation):** https://networkx.org
- **Mailing list:** https://groups.google.com/forum/#!forum/networkx-discuss
- **Source:** https://github.com/networkx/networkx
- **Bug reports:** https://github.com/networkx/networkx/issues
- **Tutorial:** https://networkx.org/documentation/latest/tutorial.html
- **GitHub Discussions:** https://github.com/networkx/networkx/discussions

## Install

NxCpp needs: 

- C++17 or later.
- Bazel for unit tests.
- CMake for Manual Test.
- Google Test for testing the code.
    - Don't care about installing by youselef since Bazel or CMakeList will handle this.

### NxCpp

```
git clone git@github.com:cirusthenter/NxCpp.git
cd NxCpp
```

### Bazel

See also: [Installing Bazel in the official document](https://docs.bazel.build/versions/4.2.2/install.html)

#### Ubuntu

```
sudo apt install apt-transport-https curl gnupg
curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > bazel.gpg
sudo mv bazel.gpg /etc/apt/trusted.gpg.d/
echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
sudo apt update && sudo apt install bazel
```

#### Mac

```
brew install bazel
```

### CMake

See also: [Installing CMake in the official document](https://cmake.org/install/)

#### Ubuntu

```
sudo apt install cmake
```

#### Mac

```
brew install cmake
```

## Google Test by Bazel with GitHub Actions

This project is under C/C++ unit tests using [Google Test](https://github.com/google/googletest) executed by [Bazel](https://bazel.build/) with continuous integration provided by [GitHub Actions](https://docs.github.com/actions). 

### Run the Test

Test the code as follows:

```
cd src
bazel test --test_output=all //:all_tests
cd ../
```

Bazel finds all the test files in this repository with its name "test_*.cc".

### Continuous Intergration

The CI file `.github/workflows/ci.yml` defines the workflow and blocks any pull request or merging to `main` branch that fails the above Bazel test. You can find all the workflows [here](https://github.com/cirusthenter/NxCpp/actions). Administrator review is required for pull requests from non-collaborators.

### Manual Test with CMake

This projects also has a light-weight testing function by CMake. First, create `src/CMakeLists.txt` file and open it with Vim (or any other editor you prefer) as follows: 

```
touch src/CMakeLists.txt
vim src/CMakeLists.txt
```

Paste this. 

```
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

########### FROM HERE ###########
add_executable(test1 classes/tests/test_graph.cc)
target_link_libraries(test1 gtest_main)
gtest_discover_tests(test1)

add_executable(test2 classes/tests/test_digraph.cc)
target_link_libraries(test2 gtest_main)
gtest_discover_tests(test2)
########### TO HERE ###########
```

You designate the test files like above if you want to test `classes/tests/test_graph.cc` and `classes/tests/test_digraph.cc` (It will run 2 test suites in this setting; you can change the number of suits by duplicating the three lines). Set it to whatever tests you want to try, and copy the three lines however many times you want.

Then, install and build Google Test with CMake as follows (See also: [README.md of Google Test](https://github.com/google/googletest/blob/main/googletest/README.md)):

```
cd src
cmake -S . -B build
cmake --build build
cd build && ctest
cd ../../
```

And you would get the result like this.

```
Test project /home/thenter/NxCpp/src/build
      Start  1: TestGraph.TestContains
 1/43 Test  #1: TestGraph.TestContains ..............   Passed    0.00 sec
      Start  2: TestGraph.TestOrder
 2/43 Test  #2: TestGraph.TestOrder .................   Passed    0.00 sec
      Start  3: TestGraph.TestNodes
 3/43 Test  #3: TestGraph.TestNodes .................   Passed    0.00 sec
      Start  4: TestGraph.TestHasNode
 4/43 Test  #4: TestGraph.TestHasNode ...............   Passed    0.00 sec
      Start  5: TestGraph.TestGetNodeData
 5/43 Test  #5: TestGraph.TestGetNodeData ...........   Passed    0.00 sec
      Start  6: TestGraph.TestHasEdge
 6/43 Test  #6: TestGraph.TestHasEdge ...............   Passed    0.00 sec
      Start  7: TestGraph.TestNeighbors
 7/43 Test  #7: TestGraph.TestNeighbors .............   Passed    0.00 sec
      Start  8: TestGraph.TestEdges
 8/43 Test  #8: TestGraph.TestEdges .................   Passed    0.00 sec
      Start  9: TestGraph.TestDegree
 9/43 Test  #9: TestGraph.TestDegree ................   Passed    0.00 sec
      Start 10: TestGraph.TestEdgeSize
10/43 Test #10: TestGraph.TestEdgeSize ..............   Passed    0.00 sec
      Start 11: TestGraph.TestWeightedDegree
11/43 Test #11: TestGraph.TestWeightedDegree ........   Passed    0.00 sec
      Start 12: TestGraph.TestNodeAttr
12/43 Test #12: TestGraph.TestNodeAttr ..............   Passed    0.00 sec
      Start 13: TestGraph.TestEdgeAttr
13/43 Test #13: TestGraph.TestEdgeAttr ..............   Passed    0.00 sec
      Start 14: TestGraph.TestDataInput
14/43 Test #14: TestGraph.TestDataInput .............   Passed    0.00 sec
      Start 15: TestGraph.TestAdjacency
15/43 Test #15: TestGraph.TestAdjacency .............   Passed    0.00 sec
      Start 16: TestGraph.TestAddNode
16/43 Test #16: TestGraph.TestAddNode ...............   Passed    0.00 sec
      Start 17: TestGraph.TestRemoveNode
17/43 Test #17: TestGraph.TestRemoveNode ............   Passed    0.00 sec
      Start 18: TestGraph.TestAddEdge
18/43 Test #18: TestGraph.TestAddEdge ...............   Passed    0.00 sec
      Start 19: TestGraph.TestRemoveEdge
19/43 Test #19: TestGraph.TestRemoveEdge ............   Passed    0.00 sec
      Start 20: TestGraph.TestClear
20/43 Test #20: TestGraph.TestClear .................   Passed    0.00 sec
      Start 21: TestGraph.TestClearEdges
21/43 Test #21: TestGraph.TestClearEdges ............   Passed    0.00 sec
      Start 22: TestGraph.TestGetEdgeData
22/43 Test #22: TestGraph.TestGetEdgeData ...........   Passed    0.00 sec
      Start 23: TestGraph.TestUpdate
23/43 Test #23: TestGraph.TestUpdate ................   Passed    0.00 sec
      Start 24: TestDiGraph.TestHasEdge
24/43 Test #24: TestDiGraph.TestHasEdge .............   Passed    0.00 sec
      Start 25: TestDiGraph.TestHasSuccessor
25/43 Test #25: TestDiGraph.TestHasSuccessor ........   Passed    0.00 sec
      Start 26: TestDiGraph.TestSuccessors
26/43 Test #26: TestDiGraph.TestSuccessors ..........   Passed    0.00 sec
      Start 27: TestDiGraph.TestHasPredessor
27/43 Test #27: TestDiGraph.TestHasPredessor ........   Passed    0.00 sec
      Start 28: TestDiGraph.TestPredessors
28/43 Test #28: TestDiGraph.TestPredessors ..........   Passed    0.00 sec
      Start 29: TestDiGraph.TestEdges
29/43 Test #29: TestDiGraph.TestEdges ...............   Passed    0.00 sec
      Start 30: TestDiGraph.TestOutEdges
30/43 Test #30: TestDiGraph.TestOutEdges ............   Passed    0.00 sec
      Start 31: TestDiGraph.TestOutEdgesDir
31/43 Test #31: TestDiGraph.TestOutEdgesDir .........   Passed    0.00 sec
      Start 32: TestDiGraph.TestInEdgesDir
32/43 Test #32: TestDiGraph.TestInEdgesDir ..........   Passed    0.00 sec
      Start 33: TestDiGraph.TestDegree
33/43 Test #33: TestDiGraph.TestDegree ..............   Passed    0.00 sec
      Start 34: TestDiGraph.TestInDegree
34/43 Test #34: TestDiGraph.TestInDegree ............   Passed    0.00 sec
      Start 35: TestDiGraph.TestOutDegree
35/43 Test #35: TestDiGraph.TestOutDegree ...........   Passed    0.00 sec
      Start 36: TestDiGraph.TestEdgeSize
36/43 Test #36: TestDiGraph.TestEdgeSize ............   Passed    0.00 sec
      Start 37: TestDiGraph.TestInDegreeWeighted
37/43 Test #37: TestDiGraph.TestInDegreeWeighted ....   Passed    0.00 sec
      Start 38: TestDiGraph.TestOutDegreeWeighted
38/43 Test #38: TestDiGraph.TestOutDegreeWeighted ...   Passed    0.00 sec
      Start 39: TestDiGraph.TestDataInput
39/43 Test #39: TestDiGraph.TestDataInput ...........   Passed    0.00 sec
      Start 40: TestDiGraph.TestAddEdge
40/43 Test #40: TestDiGraph.TestAddEdge .............   Passed    0.00 sec
      Start 41: TestDiGraph.TestRemoveEdge
41/43 Test #41: TestDiGraph.TestRemoveEdge ..........   Passed    0.00 sec
      Start 42: TestDiGraph.TestClear
42/43 Test #42: TestDiGraph.TestClear ...............   Passed    0.00 sec
      Start 43: TestDiGraph.TestClearEdges
43/43 Test #43: TestDiGraph.TestClearEdges ..........   Passed    0.00 sec

100% tests passed, 0 tests failed out of 43

Total Test time (real) =   0.16 sec
```

## Copyright Information

(Original Python) [NetworkX](https://networkx.org) is released under the 3-Clause BSD license. 

```
Copyright (C) 2004-2021 NetworkX Developers
Aric Hagberg <hagberg@lanl.gov>
Dan Schult <dschult@colgate.edu>
Pieter Swart <swart@lanl.gov>
```
