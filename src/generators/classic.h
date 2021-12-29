#pragma once
#include "../classes/digraph.hpp"
#include "../classes/graph.hpp"

inline Graph cycle_graph(int n);
inline DiGraph cycle_digraph(int n);
inline Graph empty_graph(int n);
inline DiGraph empty_digraph(int n);
inline Graph path_graph(int n);