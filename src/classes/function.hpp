#pragma once
#include "function.h"

vector<int> degree_histogram(Graph g)
{
    vector<int> counts;
    for (auto [n, attr] : g.nodes()) {
        unsigned int d = g.degree(n);
        if (d + 1 > counts.size()) {
            counts.resize(d + 1, 0);
        }
        ++counts[d];
    }
    return counts;
}
