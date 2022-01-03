#pragma once
#include "../../classes/digraph.hpp"
#include "../../classes/graph.hpp"
#include "../../exception.hpp"
#include "community_utils.hpp"
#include <unordered_set>
#include <vector>

inline double modularity(Graph g, vector<unordered_set<int>> communities, string weight, double resolution);
