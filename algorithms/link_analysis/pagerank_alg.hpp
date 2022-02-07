#pragma once
#include "pagerank_alg.h"

NodeDoubleDict pagerank(
    DiGraph g,
    double alpha = 0.85,
    double tol = 0.000001,
    int max_iter = 100,
    string weight = "weight",
    NodeDoubleDict personalization = NodeDoubleDict(),
    NodeDoubleDict nstart = NodeDoubleDict(),
    NodeDoubleDict dangling = NodeDoubleDict())
{
    if (g.size() == 0)
        return NodeDoubleDict();

    DiGraph w = stochastic_graph(g, weight);
    int n = w.number_of_nodes();

    // Choose fixed starting vector if not given
    NodeDoubleDict x;
    if (nstart.size() == 0) {
        x = fromkeys(w.nodes(), (double)1 / n);
    } else {
        // normalized nstart vector
        double s = 0;
        for (auto [k, v] : nstart)
            s += v;
        if (s == 0)
            throw ZeroDivisionError();
        for (auto [k, v] : nstart)
            x[k] = v / s;
    }

    NodeDoubleDict p;
    if (personalization.size() == 0) {
        p = fromkeys(w.nodes(), (double)1 / n);
    } else {
        double s = 0;
        for (auto [k, v] : personalization)
            s += v;
        if (s == 0)
            throw ZeroDivisionError();
        for (auto [k, v] : personalization)
            p[k] = v / s;
    }

    NodeDoubleDict dangling_weights;
    if (dangling.size() == 0) {
        dangling_weights = p;
    } else {
        double s = 0;
        for (auto [k, v] : dangling)
            s += v;
        if (s == 0)
            throw ZeroDivisionError();
        for (auto [k, v] : dangling)
            dangling_weights[k] = v / s;
    }
    unordered_set<Node> dangling_nodes;
    for (auto [nd, attr] : w.nodes())
        if (w.out_degree(nd, weight) == 0)
            dangling_nodes.insert(nd);

    for (int iter_cnt = 0; iter_cnt < max_iter; ++iter_cnt) {
        NodeDoubleDict xlast = x;
        x = fromkeys(xlast, (double)0);

        double danglesum = 0;
        for (auto n : dangling_nodes)
            danglesum += alpha * xlast[n];
        for (auto [n, v] : x) {
            for (auto [e, attr] : w.edges(n)) {
                Node nbr = e.second;
                double wt = attr[weight];
                x[nbr] += alpha * xlast[n] * wt;
            }
            x[n] += danglesum * dict_get(dangling_weights, n, (double)0) + (1 - alpha) * dict_get(p, n, (double)0);
        }
        double err = 0;
        for (auto [n, v] : x)
            err += abs(x[n] - xlast[n]);
        if (err < n * tol)
            return x;
    }
    throw PowerIterationFailedConvergence();
}