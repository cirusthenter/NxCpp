#pragma once
#include "louvain.h"

vector<unordered_set<int>> louvain_communities(Graph g, string weight = "weight", double resolution = 1, double threshold = 0.0000001)
{
    throw NotImplementedException();
}

vector<unordered_set<int>> louvain_partitions(Graph g, string weight = "weight", double resolution = 1, double threshold = 0.0000001)
{
    vector<unordered_set<int>> partition;
    for (auto [u, attr] : g.nodes())
        partition.push_back(unordered_set<int>({ { u } }));
    throw NotImplementedException();
}

vector<unordered_set<int>> _one_level(Graph g, double m, vector<unordered_set<int>> partition, double resolution, bool is_directed)
{
    throw NotImplementedException();
}