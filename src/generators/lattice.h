#pragma once
#include "../classes/digraph.h"
#include "../classes/graph.h"
#include "classic.h"

Graph grid_2d_graph(int m, int n);
DiGraph grid_2d_digraph(int m, int n);

Graph grid_2d_graph(int m, int n)
{
    // returns m*n grid graph
    Graph g = empty_graph(0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            g.add_edge(n * i + j, n * i + (j + 1));
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m - 1; ++i) {
            g.add_edge(n * i + j, n * (i + 1) + j);
        }
    }
    return g;
}

DiGraph grid_2d_digraph(int m, int n)
{
    // returns m*n grid graph
    DiGraph g = empty_digraph(0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            g.add_edge(n * i + j, n * i + (j + 1));
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m - 1; ++i) {
            g.add_edge(n * i + j, n * (i + 1) + j);
        }
    }
    for (auto [edge, attr] : g.edges())
        g.add_edge(edge.second, edge.first);

    return g;
}