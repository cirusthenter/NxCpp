#pragma once
#include "small.h"

Graph cubical_graph()
{
    // This function should be updated
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 7);
    g.add_edge(2, 3);
    g.add_edge(2, 6);
    g.add_edge(3, 5);
    g.add_edge(4, 5);
    g.add_edge(4, 7);
    g.add_edge(5, 6);
    g.add_edge(6, 7);
    return g;
}

Graph krackhardt_kite_graph()
{
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(0, 5);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(1, 6);
    g.add_edge(2, 3);
    g.add_edge(2, 5);
    g.add_edge(3, 4);
    g.add_edge(3, 5);
    g.add_edge(3, 6);
    g.add_edge(4, 6);
    g.add_edge(5, 6);
    g.add_edge(5, 7);
    g.add_edge(6, 7);
    g.add_edge(7, 8);
    g.add_edge(8, 9);
    return g;
}