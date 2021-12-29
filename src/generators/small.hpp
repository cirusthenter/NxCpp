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