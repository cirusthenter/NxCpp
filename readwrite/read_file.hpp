#pragma once
#include "read_file.h"

Graph read_undirected_file(string path)
{
    ifstream file(path);
    if (!file.good())
        throw NxCppError();

    Graph g;
    int u, v;
    while (file >> u >> v)
        g.add_edge(u, v);

    return g;
}
