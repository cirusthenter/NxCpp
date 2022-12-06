#pragma once
#include "../classes/digraph.hpp"
#include "../classes/graph.hpp"
#include <fstream>

inline Graph read_undirected_file(string path);
inline DiGraph read_directed_file(string path);
