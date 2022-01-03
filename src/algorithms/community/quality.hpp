#pragma once
#include "quality.h"

class NotAPartition : public NxCppError {
    /*
    Exception for the set of given communities is not a partition of g
    */
};

double modularity(Graph g, vector<unordered_set<int>> communities, string weight = "", double resolution = 1)
{
    if (!is_partition(g, communities))
        throw NotAPartition();
    if (g.is_directed())
        throw NotImplementedException();

    NodeDoubleDict degree;
    double deg_sum = 0, m, norm;
    degree = g.degree(weight);
    for (auto [n, deg] : degree)
        deg_sum += deg;
    m = deg_sum / 2;
    norm = 1 / (deg_sum * deg_sum);

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
        for (auto u : community)
            degree_sum += g.degree(u, weight);

        return l_c / m - resolution * degree_sum * degree_sum * norm;
    };

    double q = 0;
    for (auto community : communities) {
        q += community_contribution(community);
    }

    return q;
}
