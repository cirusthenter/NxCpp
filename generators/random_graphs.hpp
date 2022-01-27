#pragma once
#include "random_graphs.h"

Graph erdos_renyi_graph(int n, double p, bool has_seed = false, int seed = 0)
{
    return gnp_random_graph(n, p, has_seed, seed);
}

Graph gnp_random_graph(int n, double p, bool has_seed = false, int seed = 0)
{
    if (p <= 0)
        return empty_graph(n);
    if (p >= 1)
        return complete_graph(n);

    Graph g;
    for (int i = 0; i < n; ++i)
        g.add_node(i);

    // random doubles
    vector<double> rds = random_doubles(n * (n - 1) / 2, 0, 1, has_seed, seed);

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (rds[cnt] < p)
                g.add_edge(i, j);
            cnt++;
        }
    }

    return g;
}
