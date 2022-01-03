#pragma once
#include "../../classes/digraph.hpp"
#include "../../classes/graph.hpp"
#include <unordered_set>
#include <vector>

inline vector<unordered_set<int>> louvain_communities(Graph g, string weight, double resolution, double threshold);
inline vector<unordered_set<int>> louvain_partitions(Graph g, string weight, double resolution, double threshold);
inline vector<unordered_set<int>> _one_level(Graph g, double m, vector<unordered_set<int>> partition, double resolution, bool is_directed);
