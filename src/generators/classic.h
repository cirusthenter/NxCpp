#pragma once
#include "../classes/digraph.hpp"
#include "../classes/graph.hpp"

inline Graph complete_graph(int n);
inline DiGraph complete_directed_graph(int n);
inline Graph cycle_graph(int n);
inline DiGraph cycle_digraph(int n);
inline Graph empty_graph(int n);
inline DiGraph empty_digraph(int n);
inline Graph path_graph(int n);