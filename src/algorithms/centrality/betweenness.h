#pragma once
#include "../../classes/digraph.hpp"
#include "../../classes/graph.hpp"
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

inline NodeDoubleDict betweenness_centrality(Graph g, bool normalized, string weight);
struct SSSPBasic {
    vector<int> seen;
    unordered_map<int, vector<int>> predecessors;
    unordered_map<int, double> sigma;
    unordered_map<int, double> dist;
    SSSPBasic(
        vector<int> s,
        unordered_map<int, vector<int>> p,
        NodeDoubleDict _sigma,
        NodeDoubleDict d)
    {
        seen = s;
        predecessors = p;
        sigma = _sigma;
        dist = d;
    }
};
inline SSSPBasic _single_source_shortest_path_basic(Graph g, int source);
inline pair<NodeDoubleDict, NodeDoubleDict> _accumulate_basic(NodeDoubleDict& betweenness, vector<int>& s, unordered_map<int, vector<int>>& p, unordered_map<int, double>& sigma, int source);
inline NodeDoubleDict _rescale(NodeDoubleDict betweenness, int n, bool normalized, bool directed);