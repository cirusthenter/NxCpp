#pragma once
#include "../../classes/digraph.hpp"
#include "../../classes/graph.hpp"
#include "../../utils/operator.hpp"
#include <unordered_set>
#include <vector>

inline bool is_partition(Graph g, vector<unordered_set<int>> communities);