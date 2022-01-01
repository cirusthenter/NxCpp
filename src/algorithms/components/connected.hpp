#pragma once
#include "connected.h"

bool is_connected(Graph g)
{
    if (g.size() == 0)
        throw NxCppPointlessConcept();
    Node n = arbitrary_element(g.nodes());
    return _plain_bfs(g, n).size() == g.size();
}

unordered_set<int> _plain_bfs(Graph g, int source)
{
    unordered_set<Node> seen;
    unordered_set<Node> nextlevel { source };
    while (!nextlevel.empty()) {
        unordered_set<Node> thislevel = nextlevel;
        nextlevel = unordered_set<Node>();
        for (auto v : thislevel) {
            if (in(seen, v))
                continue;
            seen.insert(v);
            for (auto [u, attr] : g.neighbors(v)) {
                nextlevel.insert(u);
            }
        }
    }
    return seen;
}