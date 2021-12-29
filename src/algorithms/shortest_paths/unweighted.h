#pragma once
#include "../../classes/digraph.cc"
#include <float.h>
#include <unordered_map>
#include <vector>


NodeDoubleDict single_source_shortest_path_length(Graph g, int source, double cutoff);
NodeDoubleDict single_source_shortest_path_length_directed(DiGraph g, int source, double cutoff);
inline NodeDoubleDict _single_shortest_path_length(OuterAdjDict adj, unordered_map<int, int> firstlevel, double cutoff);
NodeDoubleDict single_target_shortest_path_length(Graph g, int target, double cutoff);
NodeDoubleDict single_target_shortest_path_length_directed(DiGraph g, int target, double cutoff);
NodeNodeDoubleDict all_pairs_shortest_path_length(Graph g, double cutoff);
vector<int> bidirectional_shortest_path(Graph g, int source, int target);
vector<int> bidirectional_shortest_path_directed(DiGraph g, int source, int target);
inline pair<pair<NodeNode, NodeNode>, int> _bidirectional_pred_succ(Graph g, int source, int target);
inline pair<pair<NodeNode, NodeNode>, int> _bidirectional_pred_succ_directed(DiGraph g, int source, int target);
Paths single_source_shortest_path(Graph g, int source, double cutoff);
Paths single_source_shortest_path_directed(DiGraph g, int source, double cutoff);
inline Paths _single_shortest_path(OuterAdjDict adj, unordered_map<Node, int> firstlevel, Paths paths, double cutoff, bool is_target);
Paths single_target_shortest_path(Graph g, int target, double cutoff);
Paths single_target_shortest_path_directed(DiGraph g, int target, double cutoff);
NodePaths all_pairs_shortest_path(Graph g, double cutoff);
Paths predecessor(Graph g, int source, double cutoff);
vector<int> predecessor_with_target(Graph g, int source, int target, double cutoff);