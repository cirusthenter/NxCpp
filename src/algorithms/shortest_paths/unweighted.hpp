#include "../../classes/digraph.hpp"
#include <float.h>
#include <unordered_map>
#include <vector>

NodeDoubleDict _single_shortest_path_length(OuterAdjDict adj, unordered_map<int, int> firstlevel, double cutoff);

NodeDoubleDict single_source_shortest_path_length(Graph g, int source, double cutoff = DBL_MAX)
{
    if (!g.has_node(source))
        throw NodeNotFound();
    OuterAdjDict adj = g.adjacency();
    unordered_map<int, int> nextlevel {
        { source, 1 }
    };
    return _single_shortest_path_length(adj, nextlevel, cutoff);
}

NodeDoubleDict single_source_shortest_path_length(DiGraph g, int source, double cutoff = DBL_MAX)
{
    if (!g.has_node(source))
        throw NodeNotFound();
    OuterAdjDict adj = g.succs();
    unordered_map<int, int> nextlevel {
        { source, 1 }
    };
    return _single_shortest_path_length(adj, nextlevel, cutoff);
}

NodeDoubleDict _single_shortest_path_length(OuterAdjDict adj, unordered_map<int, int> firstlevel, double cutoff)
{
    NodeDoubleDict d;
    unordered_map<Node, double> seen;
    int level = 0;
    unordered_set<int> nextlevel;
    for (auto [k, v] : firstlevel)
        nextlevel.insert(k);
    int n = adj.size();
    while (!nextlevel.empty() && cutoff > level) {
        unordered_set<int> thislevel = nextlevel;
        nextlevel = unordered_set<int>();
        vector<int> found;
        for (auto v : thislevel) {
            if (!in(seen, v)) {
                seen[v] = level;
                found.push_back(v);
            }
        }
        if (seen.size() == n)
            return seen;
        for (auto v : found)
            for (auto [n, nbr] : adj[v])
                nextlevel.insert(n);
        level += 1;
    }
    return seen;
}

NodeDoubleDict single_target_shortest_path_length(Graph g, int target, double cutoff = DBL_MAX)
{
    if (!g.has_node(target))
        throw NodeNotFound();
    OuterAdjDict adj = g.adjacency();
    unordered_map<int, int> nextlevel {
        { target, 1 }
    };
    return _single_shortest_path_length(adj, nextlevel, cutoff);
}

NodeDoubleDict single_target_shortest_path_length(DiGraph g, int target, double cutoff = DBL_MAX)
{
    if (!g.has_node(target))
        throw NodeNotFound();
    OuterAdjDict adj = g.preds();
    unordered_map<int, int> nextlevel {
        { target, 1 }
    };
    return _single_shortest_path_length(adj, nextlevel, cutoff);
}