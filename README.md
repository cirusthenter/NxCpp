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
- Google Test for testing the code.
- CMake for Google Test.

### NxCpp

```
git clone git@github.com:cirusthenter/NxCpp.git
cd NxCpp
```

### Cmake

#### Ubuntu

```
sudo apt install cmake
```

#### Mac

```
brew install cmake
```

### Google Test

This project is under C/C++ unit test using [Google Test](https://github.com/google/googletest) with continuous integration provided by [GitHub Actions](https://docs.github.com/actions). Install Google Test as follows (See also https://github.com/google/googletest/blob/main/googletest/README.md):

```
cd src
cmake -S . -B build
cmake --build build
cd build && ctest
cd ../../
```

## Copyright Information

(Original Python) [NetworkX](https://networkx.org) is released under the 3-Clause BSD license. 

```
Copyright (C) 2004-2021 NetworkX Developers
Aric Hagberg <hagberg@lanl.gov>
Dan Schult <dschult@colgate.edu>
Pieter Swart <swart@lanl.gov>
```