#pragma once
#include "louvain.h"

vector<unordered_set<int>> louvain_communities(
    Graph g,
    string weight = "weight",
    double resolution = 1,
    double threshold = 0.0000001,
    bool has_seed = false,
    int seed = 0)
{
    auto d = louvain_partitions(g, weight, resolution, threshold, has_seed, seed);
    return d.back();
}

vector<vector<unordered_set<int>>> louvain_partitions(
    Graph g,
    string weight = "weight",
    double resolution = 1,
    double threshold = 0.0000001,
    bool has_seed = false,
    int seed = 0)
{
    vector<unordered_set<int>> partition;
    for (auto [u, attr] : g.nodes())
        partition.push_back(unordered_set<int>({ u }));
    double mod = 0;
    Graph graph = g;

    double m = graph.edge_size(weight = weight);
    unordered_map<int, unordered_set<int>> com_nodes;
    for (auto [u, attr] : g.nodes())
        com_nodes[u] = unordered_set<int>({ u });

    OneLevel res = _one_level(graph, com_nodes, m, resolution, has_seed, seed);
    partition = res.partition;
    vector<unordered_set<int>> inner_partition = res.inner_partition;
    bool improvement = res.improvement;
    vector<vector<unordered_set<int>>> partitions;
    partitions.push_back(partition);

    while (improvement) {
        double new_mod = modularity(graph, inner_partition, weight = "weight", resolution);
        if (new_mod - mod <= threshold)
            break;
        mod = new_mod;
        auto graph_comnodes = _gen_graph(graph, inner_partition, com_nodes);
        graph = graph_comnodes.first;
        com_nodes = graph_comnodes.second;

        res = _one_level(graph, com_nodes, m, resolution, has_seed, seed);
        partition = res.partition;
        inner_partition = res.inner_partition;
        improvement = res.improvement;
        partitions.push_back(partition);
    }
    return partitions;
}

OneLevel _one_level(
    Graph g,
    unordered_map<int, unordered_set<int>> com_nodes,
    double m,
    double resolution,
    bool has_seed,
    int seed)
{
    unordered_map<int, int> node2com;
    unordered_map<int, unordered_set<int>> inner_partition;
    const string weight = "weight";
    auto degrees = g.degree(weight);
    NodeDoubleDict stot;
    {
        int com_id = 0;
        for (auto [u, attr] : g.nodes()) {
            node2com[u] = com_id;
            inner_partition[com_id] = unordered_set<int>({ u });
            stot[com_id] = degrees[u];
            ++com_id;
        }
    }

    unordered_map<int, unordered_map<int, double>> nbrs;
    for (auto [u, neighbors] : g.adjacency()) {
        nbrs[u] = unordered_map<int, double>();
        for (auto [v, attr] : neighbors) {
            if (u == v)
                continue;
            if (in(attr, weight))
                nbrs[u][v] = attr[weight];
            else
                nbrs[u][v] = 1;
        }
    }
    // random node sequence
    vector<int> rand_nodes;
    for (auto [u, attr] : g.nodes())
        rand_nodes.push_back(u);
    shuffle_vector(rand_nodes, has_seed, seed);
    int nb_moves = 1;
    bool improvement = false;

    while (nb_moves > 0) {
        nb_moves = 0;
        for (int u : rand_nodes) {
            double best_mod = 0;
            int best_com = node2com[u];
            NodeDoubleDict weights2com = _neighbor_weights(nbrs[u], node2com);
            auto degree = degrees[u];
            stot[best_com] -= degree;

            for (auto [nbr_com, wt] : weights2com) {
                double gain = 2 * wt - resolution * (stot[nbr_com] * degree) / m;
                if (gain > best_mod) {
                    best_mod = gain;
                    best_com = nbr_com;
                    continue;
                } else if (gain == best_mod && nbr_com < best_com) {
                    best_com = nbr_com;
                }
            }

            stot[best_com] += degree;
            if (best_com != node2com[u]) {
                auto com = com_nodes[u];
                inner_partition[node2com[u]].erase(u);
                inner_partition[best_com].insert(u);
                improvement = true;
                ++nb_moves;
                node2com[u] = best_com;
            }
        }
    }
    vector<unordered_set<int>> new_partition;
    for (auto [nd, atr] : com_nodes)
        new_partition.push_back(atr);
    vector<unordered_set<int>> new_inner_partition;
    for (auto [u, s] : inner_partition)
        if (s.size() > 0)
            new_inner_partition.push_back(s);
    return OneLevel(new_partition, new_inner_partition, improvement);
}

unordered_map<int, double> _neighbor_weights(unordered_map<int, double>& nbrs, unordered_map<int, int>& node2com)
{
    unordered_map<int, double> weights;
    for (auto [nbr, wt] : nbrs) {
        int com = node2com[nbr];
        if (in(weights, com))
            weights[com] += wt;
        else
            weights[com] = wt;
    }
    return weights;
}

pair<Graph, unordered_map<int, unordered_set<int>>> _gen_graph(Graph g, vector<unordered_set<int>> partition, unordered_map<int, unordered_set<int>> old_com_nodes)
{
    Graph h;
    unordered_map<int, int> node2com;
    unordered_map<int, unordered_set<int>> com_nodes;
    string weight = "weight";
    int com_id = 0;
    for (auto part : partition) {
        com_nodes[com_id] = unordered_set<int>();
        for (auto nd : part) {
            node2com[nd] = com_id;
            if (in(old_com_nodes, nd)) {
                for (auto u : old_com_nodes[nd])
                    com_nodes[com_id].insert(u);
            } else {
                com_nodes[com_id].insert(nd);
            }
        }
        h.add_node(com_id);
        com_id++;
    }

    for (auto [e, attr] : g.edges()) {
        int node1 = e.first;
        int node2 = e.second;

        double wt;
        if (in(attr, weight))
            wt = attr[weight];
        else
            wt = 1;
        int com1 = node2com[node1];
        int com2 = node2com[node2];
        double current = h.get_edge_data(com1, com2, AttrDict({ { weight, 0 } }))["weight"];
        h.add_edge(com1, com2, AttrDict({ { weight, current + wt } }));
    }
    return make_pair(h, com_nodes);
}
