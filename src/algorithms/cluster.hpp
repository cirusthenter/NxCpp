#pragma once
#include "cluster.h"

NodeInt triangles(Graph g)
{
    NodeInt ntriangles;
    for (auto [n, td] : _triangles_and_degree(g)) {
        ntriangles[n] = td.triangles / 2;
    }
    return ntriangles;
}

unordered_map<Node, NodeDegreeTrianglesGdegree> _triangles_and_degree(Graph g)
{
    unordered_map<Node, NodeDegreeTrianglesGdegree> td;
    auto nodes_nbrs = g.adjacency();
    for (auto [v, v_nbrs] : nodes_nbrs) {
        unordered_set<Node> v_nbrs_set = convert_map_to_set(v_nbrs);
        if (in(v_nbrs_set, v))
            v_nbrs_set.erase(v);
        unordered_map<int, int> gen_degree;
        for (auto w : v_nbrs_set) {
            auto vs = v_nbrs_set;
            unordered_set<Node> ws = convert_map_to_set(nodes_nbrs[w]);
            if (in(ws, w))
                ws.erase(w);
            unordered_set<int> itsct = intersection(vs, ws);
            int gd = itsct.size();
            if (in(gen_degree, gd))
                gen_degree[gd]++;
            else
                gen_degree[gd] = 1;
        }
        int ntriangles = 0;
        for (auto [k, val] : gen_degree)
            ntriangles += k * val;
        td[v] = NodeDegreeTrianglesGdegree(v_nbrs_set.size(), ntriangles, gen_degree);
    }
    return td;
}