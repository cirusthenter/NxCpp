#pragma once
#include "../classes/digraph.hpp"
#include "../classes/graph.hpp"
#include "../utils/operator.hpp"
#include <unordered_map>

inline NodeInt triangles(Graph g);

struct NodeDegreeTrianglesGdegree {
    int degree;
    int triangles;
    NodeInt generalized_degree;
    NodeDegreeTrianglesGdegree()
    {
        degree = 0;
        triangles = 0;
        generalized_degree = NodeInt();
    }
    NodeDegreeTrianglesGdegree(int d, int t, NodeInt gd)
    {
        degree = d;
        triangles = t;
        generalized_degree = gd;
    }
};
inline unordered_map<Node, NodeDegreeTrianglesGdegree> _triangles_and_degree(Graph g);