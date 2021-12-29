#pragma once
#include "../exception.hpp"
#include "../utils/operator.hpp"
#include "../utils/pair_hash.hpp"
#include <functional>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef int Node;
typedef unordered_map<string, double> AttrDict;
typedef unordered_map<Node, AttrDict> NodeDict;
typedef unordered_map<Node, AttrDict> AdjDict;
typedef unordered_map<Node, AdjDict> OuterAdjDict;
typedef pair<Node, Node> Edge;
typedef unordered_map<Edge, AttrDict, pair_hash> EdgeDict;
typedef unordered_map<Node, double> NodeDoubleDict;
typedef unordered_map<Node, unordered_map<Node, double>> NodeNodeDoubleDict;
typedef unordered_map<Node, Node> NodeNode;
typedef unordered_map<int, vector<int>> Paths;
typedef unordered_map<Node, Paths> NodePaths;
typedef unordered_map<Node, int> NodeInt;

inline ostream& operator<<(ostream& os, const AttrDict& map);
inline ostream& operator<<(ostream& os, const NodeDict& map);
inline ostream& operator<<(ostream& os, const EdgeDict& map);
inline ostream& operator<<(ostream& os, const OuterAdjDict& map);