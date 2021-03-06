#pragma once
#include "community_utils.h"

bool is_partition(Graph g, vector<unordered_set<int>> communities)
{
    unordered_set<int> nodes = convert_map_to_set(g.nodes());
    unordered_set<int> nodes_in_communities;
    for (auto c : communities)
        for (auto n : c)
            if (in(nodes, n))
                nodes_in_communities.insert(n);
            else
                return false;
    if (nodes.size() != nodes_in_communities.size())
        return false;
    size_t number_of_nodes_in_all_communities = 0;
    for (auto c : communities)
        number_of_nodes_in_all_communities += c.size();
    if (nodes.size() != number_of_nodes_in_all_communities)
        return false;

    return true;
}
