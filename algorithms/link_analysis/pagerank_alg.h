#pragma once
#include "../../classes/digraph.hpp"
#include "../../generators/stochastic.hpp"
#include "../../utils/operator.hpp"
#include <string>
#include <unordered_set>
#include <vector>

inline NodeDoubleDict pagerank(DiGraph g, double alpha, double tol, int max_iter, string weight, NodeDoubleDict personalization, NodeDoubleDict nstart, NodeDoubleDict dangling);