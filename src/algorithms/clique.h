#pragma once
#include "../classes/digraph.hpp"
#include "../classes/graph.hpp"
#include "../utils/operator.hpp"
#include "cluster.hpp"
#include <random>
#include <stack>
#include <vector>

inline vector<vector<int>> find_cliques(Graph g);
inline int number_of_cliques(Graph g);
