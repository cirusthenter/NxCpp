#pragma once
#include "../classes/digraph.cc"
#include "../classes/graph.cc"

inline Graph cycle_graph(int n);
inline DiGraph cycle_digraph(int n);
inline Graph empty_graph(int n);
inline DiGraph empty_digraph(int n);
inline Graph path_graph(int n);