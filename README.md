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

### Google Test

```
cd src
git clone https://github.com/google/googletest.git -b release-1.11.0
cd googletest        # Main directory of the cloned repository.
mkdir build          # Create a directory to hold the build output.
cd build
cmake ..             # Generate native build scripts for GoogleTest.
```

If you are useing Mac:

```
make
sudo make install    # Install in /usr/local/ by default
sudo cp -r ../googlemock/include/gmock /usr/local/include/.
sudo cp -r ../googletest/include/gtest /usr/local/include/.
sudo cp lib/*.a /usr/local/lib/
```

See also: https://github.com/google/googletest/blob/main/googletest/README.md

## Copyright Information

(Original Python) [NetworkX](https://networkx.org) is released under the 3-Clause BSD license. 

```
Copyright (C) 2004-2021 NetworkX Developers
Aric Hagberg <hagberg@lanl.gov>
Dan Schult <dschult@colgate.edu>
Pieter Swart <swart@lanl.gov>
```