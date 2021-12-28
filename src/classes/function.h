#pragma once
#include "digraph.h"
#include "graph.h"
#include <unordered_map>
#include <vector>

vector<int> degree_histogram(Graph g);

vector<int> degree_histogram(Graph g)
{
    vector<int> counts;
    for (auto [n, attr] : g.nodes()) {
        int d = g.degree(n);
        if (d + 1 > counts.size()) {
            counts.resize(d + 1, 0);
        }
        ++counts[d];
    }
    return counts;
}
