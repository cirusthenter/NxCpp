#pragma once
#include "stochastic.h"

DiGraph stochastic_graph(DiGraph dg, string weight = "weight")
{
    DiGraph g = dg;
    auto degree = g.out_degree(weight);
    for (auto [e, d] : g.edges()) {
        auto [u, v] = e;
        if (degree[u] == 0) {
            g.add_edge(u, v, AttrDict({ { "weight", 0 } }));
        } else {
            double w;
            if (in(d, weight))
                w = d[weight];
            else
                w = 1;
            g.add_edge(u, v, AttrDict({ { "weight", w / degree[u] } }));
        }
    }
    return g;
}
