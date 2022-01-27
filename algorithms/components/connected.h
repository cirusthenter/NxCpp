#pragma once
#include "../../classes/digraph.hpp"
#include "../../classes/graph.hpp"
#include "../../utils/misc.hpp"

inline bool is_connected(Graph g);
inline unordered_set<Node> _plain_bfs(Graph g, Node source);