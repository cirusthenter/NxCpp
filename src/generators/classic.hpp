#pragma once
#include "classic.h"

Graph complete_graph(int n)
{
    Graph g = empty_graph(n);
    if (n < 2)
        return g;
    for (auto [u, attr] : g.nodes()) {
        for (auto [v, attr] : g.nodes()) {
            if (u == v)
                continue;
            g.add_edge(u, v);
        }
    }

    return g;
}

DiGraph complete_directed_graph(int n)
{
    DiGraph g = empty_digraph(n);
    if (n < 2)
        return g;
    for (auto [u, attr] : g.nodes()) {
        for (auto [v, attr] : g.nodes()) {
            if (u == v)
                continue;
            g.add_edge(u, v);
        }
    }

    return g;
}

Graph cycle_graph(int n)
{
    // This funciton assumes empty_graph(n) returns graph with node 0..n-1
    Graph g = empty_graph(n);
    for (int i = 0; i < n - 1; ++i)
        g.add_edge(i, i + 1);
    g.add_edge(n - 1, 0);
    return g;
}

DiGraph cycle_digraph(int n)
{
    // This funciton assumes empty_graph(n) returns graph with node 0..n-1
    DiGraph g = empty_digraph(n);
    for (int i = 0; i < n - 1; ++i)
        g.add_edge(i, i + 1);
    g.add_edge(n - 1, 0);
    return g;
}

Graph empty_graph(int n = 0)
{
    Graph g = Graph();
    for (int i = 0; i < n; ++i)
        g.add_node(i);
    return g;
}

DiGraph empty_digraph(int n = 0)
{
    DiGraph g = DiGraph();
    for (int i = 0; i < n; ++i)
        g.add_node(i);
    return g;
}

Graph path_graph(int n)
{
    Graph g = empty_graph(n);
    for (int i = 0; i < n - 1; ++i) {
        g.add_edge(i, i + 1);
    }
    return g;
}
