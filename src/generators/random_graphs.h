#pragma once
#include "../classes/digraph.hpp"
#include "../classes/graph.hpp"
#include "../utils/random.hpp"
#include "classic.hpp"
#include <unordered_set>

inline Graph erdos_renyi_graph(int n, double p, bool has_seed, int seed);
inline Graph gnp_random_graph(int n, double p, bool has_seed, int seed);