#pragma once
#include "../../classes/digraph.hpp"
#include "../../classes/graph.hpp"
#include "../../utils/random.hpp"
#include "quality.hpp"
#include <unordered_set>
#include <vector>

inline vector<unordered_set<int>> louvain_communities(Graph g, string weight, double resolution, double threshold, bool has_seed, int seed);
inline vector<vector<unordered_set<int>>> louvain_partitions(Graph g, string weight, double resolution, double threshold, bool has_seed, int seed);
struct OneLevel {
    vector<unordered_set<int>> partition;
    vector<unordered_set<int>> inner_partition;
    bool improvement;
    OneLevel(
        vector<unordered_set<int>> p,
        vector<unordered_set<int>> i_p,
        bool imp)
    {
        partition = p;
        inner_partition = i_p;
        improvement = imp;
    }
};
inline OneLevel _one_level(Graph g, unordered_map<int, unordered_set<int>> com_nodes, double m, double resolution, bool has_seed, int seed);
inline unordered_map<int, double> _neighbor_weights(unordered_map<int, double>& nbrs, unordered_map<int, int>& node2com);
inline pair<Graph, unordered_map<int, unordered_set<int>>> _gen_graph(Graph g, vector<unordered_set<int>> partition, unordered_map<int, unordered_set<int>> old_com_nodes);
