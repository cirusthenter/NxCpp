#pragma once
#include "quality.h"
#include <chrono>
using namespace std::chrono;

class NotAPartition : public NxCppError {
    /*
    Exception for the set of given communities is not a partition of g
    */
};

double modularity(Graph g, vector<unordered_set<int>> communities, string weight = "weight", double resolution = 1)
{
    auto start1 = high_resolution_clock::now();
    if (!is_partition(g, communities))
        throw NotAPartition();
    if (g.is_directed())
        throw NotImplementedException();

    double deg_sum = 0, m, norm;
    NodeDoubleDict degree = g.degree(weight);
    for (auto [n, deg] : degree)
        deg_sum += deg;
    m = deg_sum / 2;
    norm = 1 / (deg_sum * deg_sum);

    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    auto start2 = high_resolution_clock::now();
    double q = 0;

    auto community_contribution = [&](unordered_set<int> community) {
        double l_c = 0;

        // complute l_c
        for (auto [e, attr] : g.edges(community)) {
            int u = e.first; // u is in community
            int v = e.second;
            double wt;
            if (in(attr, weight))
                wt = attr[weight];
            else
                wt = 1;
            if (in(community, u) && in(community, v))
                l_c += wt;
        }

        double degree_sum = 0;
        for (auto u : community) {
            degree_sum += degree[u];
        }

        return l_c / m - resolution * degree_sum * degree_sum * norm;
    };

    for (auto community : communities) {
        q += community_contribution(community);
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);

    return q;
}
