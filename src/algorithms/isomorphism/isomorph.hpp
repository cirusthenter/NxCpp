#pragma once
#include "isomorph.h"

bool graph_could_be_isomorphic(Graph g1, Graph g2)
{
    return could_be_isomorphic(g1, g2);
}

bool could_be_isomorphic(Graph g1, Graph g2)
{
    // check global properties
    if (g1.order() != g2.order())
        return false;

    // check local properties
    NodeDoubleDict d1 = g1.degree();
    NodeInt t1 = triangles(g1);
    // int c1 = number_of_cliques(g1);
    auto props1 = vector<pair<double, int>>();
    for (auto [n, deg] : d1) {
        props1.push_back(pair<double, int>(deg, t1[n]));
    }
    sort(props1.begin(), props1.end());

    NodeDoubleDict d2 = g2.degree();
    NodeInt t2 = triangles(g2);
    // int c2 = number_of_cliques(g2);
    auto props2 = vector<pair<double, int>>();
    for (auto [n, deg] : d2) {
        props2.push_back(pair<double, int>(deg, t2[n]));
    }
    sort(props2.begin(), props2.end());
    if (props1 != props2)
        return false;

    // ok...
    return true;
}