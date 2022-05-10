#pragma once
#include "betweenness.h"

NodeDoubleDict betweenness_centrality(Graph g, bool normalized = true, string weight = "")
{
    NodeDoubleDict betweenness;
    unordered_set<int> nodes = convert_map_to_set(g.nodes());
    for (auto n : nodes)
        betweenness[n] = 0;
    for (int source : nodes) {
        // single source shortest paths
        vector<int> s;
        unordered_map<int, vector<int>> p;
        unordered_map<int, double> sigma;
        if (weight == "") {
            SSSPBasic res = _single_source_shortest_path_basic(g, source);
            s = res.seen;
            p = res.predecessors;
            sigma = res.sigma;
        } else {
            throw NotImplementedException();
        }
        // accumulation
        auto res = _accumulate_basic(betweenness, s, p, sigma, source);
        betweenness = res.first;
    }
    betweenness = _rescale(betweenness, g.number_of_nodes(), normalized, g.is_directed());
    return betweenness;
}

SSSPBasic _single_source_shortest_path_basic(Graph g, int source)
{
    vector<int> s;
    unordered_map<int, vector<int>> p;
    for (auto [n, attr] : g.nodes())
        p[n] = vector<int>();
    unordered_map<int, double> sigma;
    for (auto [n, attr] : g.nodes())
        sigma[n] = 0;
    unordered_map<int, double> d;
    sigma[source] = 1;
    d[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        s.push_back(v);
        double dv = d[v];
        double sigmav = sigma[v];
        for (auto [w, attr] : g.neighbors(v)) {
            if (!in(d, w)) {
                q.push(w);
                d[w] = dv + 1;
            }
            if (d[w] == dv + 1) {
                sigma[w] += sigmav;
                p[w].push_back(v);
            }
        }
    }
    return SSSPBasic(s, p, sigma, d);
}

pair<NodeDoubleDict, NodeDoubleDict> _accumulate_basic(NodeDoubleDict& betweenness, vector<int>& s, unordered_map<int, vector<int>>& p, unordered_map<int, double>& sigma, int source)
{
    NodeDoubleDict delta;
    for (auto [n, val] : betweenness)
        delta[n] = 0;
    while (!s.empty()) {
        int w = s.back();
        s.pop_back();
        double coeff = (1 + delta[w]) / sigma[w];
        for (auto v : p[w])
            delta[v] += sigma[v] * coeff;
        if (w != source)
            betweenness[w] += delta[w];
    }
    return pair<NodeDoubleDict, NodeDoubleDict>(betweenness, delta);
}

NodeDoubleDict _rescale(NodeDoubleDict betweenness, int n, bool normalized, bool directed)
{
    double scale = 1;
    if (normalized) {
        if (n > 2) {
            scale = (double)1 / ((n - 1) * (n - 2));
        }
    } else {
        if (!directed) {
            scale = 0.5;
        }
    }
    for (auto [n, val] : betweenness) {
        betweenness[n] *= scale;
    }
    return betweenness;
}
