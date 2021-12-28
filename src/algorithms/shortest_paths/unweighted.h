#include "../../classes/digraph.h"
#include <float.h>
#include <unordered_map>
#include <vector>

NodeDoubleDict _single_shortest_path_length(OuterAdjDict adj, unordered_map<int, int> firstlevel, double cutoff);
pair<pair<NodeNode, NodeNode>, int> _bidirectional_pred_succ(Graph g, int source, int target);
pair<pair<NodeNode, NodeNode>, int> _bidirectional_pred_succ_directed(DiGraph g, int source, int target);
Paths _single_shortest_path(OuterAdjDict adj, unordered_map<Node, int> firstlevel, Paths paths, double cutoff, bool is_target);

NodeDoubleDict single_source_shortest_path_length(Graph g, int source, double cutoff = DBL_MAX)
{
    if (!g.has_node(source))
        throw NodeNotFound();
    OuterAdjDict adj = g.adjacency();
    unordered_map<int, int> nextlevel {
        { source, 1 }
    };
    return _single_shortest_path_length(adj, nextlevel, cutoff);
}

NodeDoubleDict single_source_shortest_path_length_directed(DiGraph g, int source, double cutoff = DBL_MAX)
{
    if (!g.has_node(source))
        throw NodeNotFound();
    OuterAdjDict adj = g.succs();
    unordered_map<int, int> nextlevel {
        { source, 1 }
    };
    return _single_shortest_path_length(adj, nextlevel, cutoff);
}

NodeDoubleDict _single_shortest_path_length(OuterAdjDict adj, unordered_map<int, int> firstlevel, double cutoff)
{
    NodeDoubleDict d;
    unordered_map<Node, double> seen;
    int level = 0;
    unordered_set<int> nextlevel;
    for (auto [k, v] : firstlevel)
        nextlevel.insert(k);
    int n = adj.size();
    while (!nextlevel.empty() && cutoff > level) {
        unordered_set<int> thislevel = nextlevel;
        nextlevel = unordered_set<int>();
        vector<int> found;
        for (auto v : thislevel) {
            if (!in(seen, v)) {
                seen[v] = level;
                found.push_back(v);
            }
        }
        if (seen.size() == n)
            return seen;
        for (auto v : found)
            for (auto [n, nbr] : adj[v])
                nextlevel.insert(n);
        level += 1;
    }
    return seen;
}

NodeDoubleDict single_target_shortest_path_length(Graph g, int target, double cutoff = DBL_MAX)
{
    if (!g.has_node(target))
        throw NodeNotFound();
    OuterAdjDict adj = g.adjacency();
    unordered_map<int, int> nextlevel {
        { target, 1 }
    };
    return _single_shortest_path_length(adj, nextlevel, cutoff);
}

NodeDoubleDict single_target_shortest_path_length_directed(DiGraph g, int target, double cutoff = DBL_MAX)
{
    if (!g.has_node(target))
        throw NodeNotFound();
    OuterAdjDict adj = g.preds();
    unordered_map<int, int> nextlevel {
        { target, 1 }
    };
    return _single_shortest_path_length(adj, nextlevel, cutoff);
}

NodeNodeDoubleDict all_pairs_shortest_path_length(Graph g, double cutoff = DBL_MAX)
{
    NodeNodeDoubleDict all_pairs;
    for (auto [nd, attr] : g.nodes()) {
        all_pairs[nd] = single_source_shortest_path_length(g, nd, cutoff);
    }
    return all_pairs;
}

vector<int> bidirectional_shortest_path(Graph g, int source, int target)
{
    if (!g.has_node(source) or !g.has_node(target))
        throw NodeNotFound();
    auto result = _bidirectional_pred_succ(g, source, target);
    NodeNode pred = result.first.first;
    NodeNode succ = result.first.second;
    int w = result.second;

    vector<int> path;
    while (w != source) {
        path.push_back(w);
        w = pred[w];
    }
    path.push_back(source);
    w = succ[path[0]];
    reverse(path.begin(), path.end());
    while (w != target) {
        path.push_back(w);
        w = succ[w];
    }
    path.push_back(target);
    return path;
}

vector<int> bidirectional_shortest_path_directed(DiGraph g, int source, int target)
{
    if (!g.has_node(source) or !g.has_node(target))
        throw NodeNotFound();
    auto result = _bidirectional_pred_succ_directed(g, source, target);
    NodeNode pred = result.first.first;
    NodeNode succ = result.first.second;
    int w = result.second;

    vector<int> path;
    while (w != source) {
        path.push_back(w);
        w = pred[w];
    }
    path.push_back(source);
    w = succ[path[0]];
    reverse(path.begin(), path.end());
    if (w == target) // when w == target
        return path;
    while (w != target) {
        path.push_back(w);
        w = succ[w];
    }
    path.push_back(target);
    return path;
}

pair<pair<NodeNode, NodeNode>, int> _bidirectional_pred_succ(Graph g, int source, int target)
{
    if (target == source)
        return pair<pair<NodeNode, NodeNode>, int>(pair<NodeNode, NodeNode>(NodeNode({ { target, target } }), NodeNode({ { source, source } })), source);
    OuterAdjDict gpred = g.adjacency();
    OuterAdjDict gsucc = g.adjacency();
    NodeNode pred { { source, source } };
    NodeNode succ { { target, target } };
    vector<int> forward_fringe { source };
    vector<int> reverse_fringe { target };

    while (!forward_fringe.empty() && !reverse_fringe.empty()) {
        if (forward_fringe.size() <= reverse_fringe.size()) {
            vector<int> this_level = forward_fringe;
            forward_fringe = vector<int>();
            for (auto v : this_level) {
                for (auto [w, adj] : gsucc[v]) {
                    if (!in(pred, w)) {
                        forward_fringe.push_back(w);
                        pred[w] = v;
                    }
                    if (in(succ, w))
                        return pair<pair<NodeNode, NodeNode>, int>(pair<NodeNode, NodeNode>(pred, succ), w);
                }
            }
        } else {
            vector<int> this_level = reverse_fringe;
            reverse_fringe = vector<int>();
            for (auto v : this_level) {
                for (auto [w, adj] : gpred[v]) {
                    if (!in(succ, w)) {
                        reverse_fringe.push_back(w);
                        succ[w] = v;
                    }
                    if (in(pred, w))
                        return pair<pair<NodeNode, NodeNode>, int>(pair<NodeNode, NodeNode>(pred, succ), w);
                }
            }
        }
    }
    throw NxCppNoPath();
}

pair<pair<NodeNode, NodeNode>, int> _bidirectional_pred_succ_directed(DiGraph g, int source, int target)
{
    if (target == source)
        return pair<pair<NodeNode, NodeNode>, int>(pair<NodeNode, NodeNode>(NodeNode({ { target, target } }), NodeNode({ { source, source } })), source);
    OuterAdjDict gpred = g.preds();
    OuterAdjDict gsucc = g.succs();
    NodeNode pred { { source, source } };
    NodeNode succ { { target, target } };
    vector<int> forward_fringe { source };
    vector<int> reverse_fringe { target };

    while (!forward_fringe.empty() && !reverse_fringe.empty()) {
        if (forward_fringe.size() <= reverse_fringe.size()) {
            vector<int> this_level = forward_fringe;
            forward_fringe = vector<int>();
            for (auto v : this_level) {
                for (auto [w, adj] : gsucc[v]) {
                    if (!in(pred, w)) {
                        forward_fringe.push_back(w);
                        pred[w] = v;
                    }
                    if (in(succ, w))
                        return pair<pair<NodeNode, NodeNode>, int>(pair<NodeNode, NodeNode>(pred, succ), w);
                }
            }
        } else {
            vector<int> this_level = reverse_fringe;
            reverse_fringe = vector<int>();
            for (auto v : this_level) {
                for (auto [w, adj] : gpred[v]) {
                    if (!in(succ, w)) {
                        reverse_fringe.push_back(w);
                        succ[w] = v;
                    }
                    if (in(pred, w))
                        return pair<pair<NodeNode, NodeNode>, int>(pair<NodeNode, NodeNode>(pred, succ), w);
                }
            }
        }
    }
    throw NxCppNoPath();
}

Paths single_source_shortest_path(Graph g, int source, double cutoff = DBL_MAX)
{
    if (!g.has_node(source))
        throw NodeNotFound();
    NodeNode nextlevel({ { source, 1 } });
    Paths paths { { source, vector<int> { source } } };
    return _single_shortest_path(g.adjacency(), nextlevel, paths, cutoff, false);
}

Paths single_source_shortest_path_directed(DiGraph g, int source, double cutoff = DBL_MAX)
{
    if (!g.has_node(source))
        throw NodeNotFound();
    NodeNode nextlevel({ { source, 1 } });
    Paths paths { { source, vector<int> { source } } };
    return _single_shortest_path(g.succs(), nextlevel, paths, cutoff, false);
}

Paths _single_shortest_path(OuterAdjDict adj, unordered_map<Node, int> firstlevel, Paths paths, double cutoff = DBL_MAX, bool is_target = false)
{
    int level = 0;
    NodeNode nextlevel = firstlevel;
    while (!nextlevel.empty() && cutoff > level) {
        auto thislevel = nextlevel;
        nextlevel = NodeNode();
        for (auto [v, level] : thislevel) {
            for (auto [w, attr] : adj[v]) {
                if (!in(paths, w)) {
                    vector<int> pw;
                    if (is_target) {
                        pw.push_back(w);
                        pw.insert(pw.end(), paths[v].begin(), paths[v].end());
                    } else {
                        pw = paths[v];
                        pw.push_back(w);
                    }
                    paths[w] = pw;
                    nextlevel[w] = 1;
                }
            }
        }
        level++;
    }
    return paths;
}

Paths single_target_shortest_path(Graph g, int target, double cutoff = DBL_MAX)
{
    if (!g.has_node(target))
        throw NodeNotFound();
    NodeNode nextlevel({ { target, 1 } });
    Paths paths { { target, vector<int> { target } } };
    return _single_shortest_path(g.adjacency(), nextlevel, paths, cutoff, true);
}

Paths single_target_shortest_path_directed(DiGraph g, int target, double cutoff = DBL_MAX)
{
    if (!g.has_node(target))
        throw NodeNotFound();
    NodeNode nextlevel({ { target, 1 } });
    Paths paths { { target, vector<int> { target } } };
    return _single_shortest_path(g.preds(), nextlevel, paths, cutoff, true);
}

NodePaths all_pairs_shortest_path(Graph g, double cutoff = DBL_MAX)
{
    NodePaths all_pairs_paths;
    for (auto [n, attr] : g.nodes())
        all_pairs_paths[n] = single_source_shortest_path(g, n, cutoff);

    return all_pairs_paths;
}

Paths predecessor(Graph g, int source, double cutoff = DBL_MAX)
{
    if (!g.has_node(source))
        throw NodeNotFound();
    int level = 0;
    vector<int> nextlevel { source };
    NodeNode seen({ { source, level } });
    Paths pred({ { source, vector<int>() } });
    while (!nextlevel.empty()) {
        level++;
        auto thislevel = nextlevel;
        nextlevel = vector<int>();
        for (auto v : thislevel) {
            for (auto [w, attr] : g[v]) {
                if (!in(seen, w)) {
                    pred[w] = vector<int>({ v });
                    seen[w] = level;
                    nextlevel.push_back(w);
                } else if (seen[w] == level) {
                    pred[w].push_back(v);
                }
            }
        }
        if (cutoff <= level)
            break;
    }
    return pred;
}

vector<int> predecessor_with_target(Graph g, int source, int target, double cutoff = DBL_MAX)
{
    auto pred = predecessor(g, source, cutoff);
    if (!in(pred, target))
        return vector<int>();
    return pred[target];
}