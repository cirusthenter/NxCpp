#pragma once
#include "classic.h"

Graph barbell_graph(int m1, int m2)
{
    if (m1 < 2)
        throw NxCppError();
    if (m2 < 0)
        throw NxCppError();

    // left barbell
    Graph g = complete_graph(m1);

    // connecting path
    for (int i = m1; i < m1 + m2 - 1; ++i)
        g.add_node(i);
    if (m2 > 1)
        for (int i = m1; i < m1 + m2; ++i)
            g.add_edge(i - 1, i);

    // right barbell
    for (int i = m1 + m2; i < 2 * m1 + m2; ++i) {
        for (int j = m1 + m2; j < 2 * m1 + m2; ++j) {
            if (i == j)
                continue;
            g.add_edge(i, j);
        }
    }

    // connecting it up
    g.add_edge(m1 - 1, m1);
    if (m2 > 0)
        g.add_edge(m1 + m2 - 1, m1 + m2);

    return g;
}

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

Graph null_graph()
{
    Graph g = empty_graph(0);
    return g;
}

DiGraph null_digraph()
{
    DiGraph g = empty_digraph(0);
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

DiGraph path_digraph(int n)
{
    DiGraph g = empty_digraph(n);
    for (int i = 0; i < n - 1; ++i) {
        g.add_edge(i, i + 1);
    }
    return g;
}
