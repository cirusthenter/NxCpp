#pragma once
#include "digraph.h"

class DiGraph : public Graph {
    OuterAdjDict pred;
    OuterAdjDict succ;

public:
    DiGraph()
    {
        pred = adjlist_outer_dict_factory();
        succ = adjlist_outer_dict_factory();
    }

    OuterAdjDict successor()
    {
        return succ;
    }

    OuterAdjDict predecessor()
    {
        return pred;
    }

    void add_node(int node_for_adding, AttrDict attr = AttrDict())
    {
        if (has_node(node_for_adding)) { // update attr even if node already exists
            update_map(node[node_for_adding], attr);
        } else {
            succ[node_for_adding] = adjlist_inner_dict_factory();
            pred[node_for_adding] = adjlist_inner_dict_factory();
            update_map(node[node_for_adding], attr);
        }
    }

    void add_nodes_from()
    {
        throw NotImplementedException();
    }

    void remove_node(int n)
    {
        cout << has_node(n) << endl;
        if (!has_node(n))
            throw NxCppError();
        node.erase(n);
        for (auto [nbr, attr] : succ[n]) {
            pred[nbr].erase(n);
        }
        succ.erase(n);
        for (auto [nbr, attr] : pred[n]) {
            succ[nbr].erase(n);
        }
        pred.erase(n);
    }

    void add_edge(int u_of_edge, int v_of_edge, AttrDict addtr = AttrDict())
    {
        int u = u_of_edge;
        int v = v_of_edge;
        // add nodes
        if (!has_node(u)) {
            add_node(u);
        }
        if (!has_node(v)) {
            add_node(v);
        }
        // add the edge
        AttrDict datadict = edge_attr_dict_factory();
        if (has_successor(u, v))
            datadict = adj[u][v];
        update_map(datadict, addtr);
        succ[u][v] = datadict;
        pred[v][u] = datadict;
    }

    void add_edges_from()
    {
        throw NotImplementedException();
    }

    void remove_edge(int u, int v)
    {
        if (!has_successor(u, v))
            throw NxCppError();
        succ[u].erase(v);
        pred[v].erase(u);
    }

    bool has_edge(int u, int v)
    {
        if (succ.find(u) != succ.end() && succ[u].find(v) != succ[u].end())
            return true;
        return false;
    }

    void remove_edges_from()
    {
        throw NotImplementedException();
    }

    bool has_successor(int u, int v)
    {
        return has_node(u) && succ[u].find(v) != succ[u].end();
    }

    bool has_predecessor(int u, int v)
    {
        return has_node(u) && pred[u].find(v) != pred[u].end();
    }

    OuterAdjDict succs()
    {
        return succ;
    }

    AdjDict successors(int n)
    {
        if (has_node(n))
            return succ[n];
        throw NxCppError();
    }

    AdjDict neighbors(int n)
    {
        return successors(n);
    }

    OuterAdjDict preds()
    {
        return pred;
    }

    AdjDict predecessors(int n)
    {
        if (has_node(n))
            return pred[n];
        throw NxCppError();
    }

    EdgeDict edges()
    {
        // This method can be updated
        EdgeDict edges;
        for (auto [u, nbrs] : succ)
            for (auto [v, attr] : nbrs)
                edges[Edge(u, v)] = attr;
        return edges;
    }

    EdgeDict edges(int n)
    {
        if (!has_node(n))
            throw NxCppError();
        EdgeDict edges;
        for (auto [nbr, attr] : succ[n]) {
            edges[Edge(n, nbr)] = attr;
        }
        return edges;
    }

    EdgeDict edges(unordered_set<int> nodes)
    {
        // This method can be updated
        EdgeDict edges;
        for (auto n : nodes) {
            if (!has_node(n))
                throw NxCppError();
            for (auto [nbr, attr] : succ[n]) {
                edges[Edge(n, nbr)] = attr;
            }
        }
        return edges;
    }

    EdgeDict out_edges()
    {
        return edges();
    }

    EdgeDict out_edges(int n)
    {
        return edges(n);
    }

    EdgeDict out_edges(unordered_set<int> nodes)
    {
        return edges(nodes);
    }

    EdgeDict in_edges()
    {
        // This method can be updated
        EdgeDict edges;
        for (auto [u, nbrs] : pred)
            for (auto [v, attr] : nbrs)
                edges[Edge(v, u)] = attr;
        return edges;
    }

    EdgeDict in_edges(int n)
    {
        if (!has_node(n))
            throw NxCppError();
        EdgeDict edges;
        for (auto [nbr, attr] : pred[n]) {
            edges[Edge(nbr, n)] = attr;
        }
        return edges;
    }

    EdgeDict in_edges(unordered_set<int> nodes)
    {
        // This method can be updated
        EdgeDict edges;
        for (auto n : nodes) {
            if (!has_node(n))
                throw NxCppError();
            for (auto [nbr, attr] : pred[n]) {
                edges[Edge(nbr, n)] = attr;
            }
        }
        return edges;
    }

    double in_degree(int n, string weight = "")
    {
        if (!has_node(n))
            throw NodeNotFound();

        if (weight == "") {
            return pred[n].size();
        }

        double sum_weight = 0;
        for (auto [n, attr] : predecessors(n)) {
            if (attr.find(weight) == attr.end())
                sum_weight += 1;
            else
                sum_weight += attr[weight];
        }
        return sum_weight;
    }

    double out_degree(int n, string weight = "")
    {
        if (!has_node(n))
            throw NodeNotFound();

        if (weight == "") {
            return succ[n].size();
        }

        double sum_weight = 0;
        for (auto [n, attr] : successors(n)) {
            if (attr.find(weight) == attr.end())
                sum_weight += 1;
            else
                sum_weight += attr[weight];
        }
        return sum_weight;
    }

    pair<double, double> degree(int n, string weight = "")
    {
        // (in_degree, out_degree)
        return pair<double, double>(in_degree(n, weight), out_degree(n, weight));
    }

    double edge_size(string weight = "")
    {
        double s = 0;
        for (auto [n, attr] : node) {
            s += out_degree(n, weight);
        }
        return s;
    }

    void clear()
    {
        succ.clear();
        pred.clear();
        node.clear();
    }

    void clear_edges()
    {
        for (auto& [nbr, nbrs_of_nbr] : succ) {
            nbrs_of_nbr.clear();
        }
        for (auto& [nbr, nbrs_of_nbr] : pred) {
            nbrs_of_nbr.clear();
        }
    }

    OuterAdjDict adjacency()
    {
        return succ;
    }

    bool is_multigraph()
    {
        return false;
    }

    bool is_directed()
    {
        return true;
    }

    int number_of_edges()
    {
        return edge_size();
    }

    Graph to_undirected()
    {
        throw NotImplementedException();
    }

    DiGraph reverse()
    {
        throw NotImplementedException();
    }
};