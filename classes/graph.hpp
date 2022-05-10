#pragma once
#include "graph.h"

ostream& operator<<(ostream& os, const AttrDict& map)
{
    if (map.size() <= 0)
        return os << "{}";
    auto it = map.begin();
    os << "{";
    os << "\"" << it->first << "\": " << it->second;
    ++it;
    while (it != map.end()) {
        os << ", \"" << it->first << "\": " << it->second;
        ++it;
    }
    os << "}";
    return os;
}

ostream& operator<<(ostream& os, const NodeDict& map)
{
    if (map.size() <= 0)
        return os << "[]";
    auto it = map.begin();
    os << "[";
    os << (it++)->first;
    while (it != map.end()) {
        os << ", " << it->first;
        ++it;
    }
    os << "]";
    return os;
}

ostream& operator<<(ostream& os, const EdgeDict& map)
{
    if (map.size() <= 0)
        return os << "[]";
    auto it = map.begin();
    os << "[";
    auto v = (it++)->first;
    os << "(" << v.first << ", " << v.second << ")";
    while (it != map.end()) {
        v = (it)->first;
        os << ", (" << v.first << ", " << v.second << ")";
        ++it;
    }
    os << "]";
    return os;
}

ostream& operator<<(ostream& os, const OuterAdjDict& map)
{
    throw NotImplementedException();
}

class Graph {
public:
    typedef typename unordered_map<int, AttrDict>::iterator iterator;
    typedef typename unordered_map<int, AttrDict>::const_iterator const_iterator;

protected:
    NodeDict node;
    OuterAdjDict adj;

public:
    Graph()
    {
        node = node_dict_factory();
        adj = adjlist_outer_dict_factory();
    }

    // range-based for
    iterator begin() { return node.begin(); }
    const_iterator begin() const { return node.begin(); }
    iterator end() { return node.end(); }
    const_iterator end() const { return node.end(); }

    size_t size()
    {
        return node.size();
    }

    double edge_size(string weight = "")
    {
        double s = 0;
        for (auto [n, attr] : node) {
            s += degree(n, weight);
        }
        return s / 2;
    }

    AdjDict& operator[](int idx) { return adj[idx]; }
    const AdjDict& operator[](int idx) const { return adj.at(idx); }

    void add_node(int node_for_adding, AttrDict attr = AttrDict())
    {
        if (has_node(node_for_adding)) { // update attr even if node already exists
            update_map(node[node_for_adding], attr);
        } else {
            adj[node_for_adding] = adjlist_inner_dict_factory();
            update_map(node[node_for_adding], attr);
        }
    }

    void add_nodes_from()
    {
        throw NotImplementedException();
    }

    void remove_node(int n)
    {
        if (!has_node(n))
            throw NxCppError();
        node.erase(n);
        AdjDict nbrs = adj[n];
        adj.erase(n);
        for (auto [nbr, nbrs_of_nbr] : nbrs) {
            adj[nbr].erase(n);
        }
    }

    void remove_nodes_from()
    {
        throw NotImplementedException();
    }

    NodeDict nodes()
    {
        return node;
    }

    AttrDict get_node_data(int n, AttrDict def_dict = AttrDict())
    {
        if (has_node(n))
            return node[n];
        return def_dict;
    }

    size_t number_of_nodes()
    {
        return node.size();
    }

    size_t order()
    {
        return node.size();
    }

    bool has_node(int n)
    {
        return node.find(n) != node.end();
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
        if (has_edge(u, v))
            datadict = adj[u][v];
        update_map(datadict, addtr);
        adj[u][v] = datadict;
        adj[v][u] = datadict;
    }

    void add_edges_from()
    {
        throw NotImplementedException();
    }

    void remove_edge(int u, int v)
    {
        if (!has_edge(u, v))
            throw NxCppError();
        adj[u].erase(v);
        if (u != v)
            adj[v].erase(u);
    }

    void remove_edges_from()
    {
        throw NotImplementedException();
    }

    bool has_edge(int u, int v)
    {
        if (adj.find(u) != adj.end() && adj[u].find(v) != adj[u].end())
            return true;
        return false;
    }

    AdjDict neighbors(int n)
    {
        if (has_node(n))
            return adj[n];
        throw NxCppError();
    }

    EdgeDict edges()
    {
        // This method can be updated
        EdgeDict edges;
        for (auto [u, nbrs] : adj)
            for (auto [v, attr] : nbrs)
                if (u <= v)
                    edges[Edge(u, v)] = attr;
        return edges;
    }

    EdgeDict edges(int n)
    {
        // This method can be updated
        EdgeDict edges;
        for (auto [nbr, attr] : adj[n]) {
            if (n < nbr)
                edges[Edge(n, nbr)] = attr;
            else
                edges[Edge(nbr, n)] = attr;
        }
        return edges;
    }

    EdgeDict edges(unordered_set<int> nds)
    {
        // This method can be updated
        EdgeDict es;
        for (auto n : nds) {
            for (auto [nbr, attr] : adj[n]) {
                if (n < nbr)
                    es[Edge(n, nbr)] = attr;
                else
                    es[Edge(nbr, n)] = attr;
            }
        }
        return es;
    }

    AttrDict get_edge_data(int u, int v, AttrDict def_dict = AttrDict())
    {
        if (has_edge(u, v))
            return adj[u][v];
        return def_dict;
    }

    OuterAdjDict adjacency()
    {
        return adj;
    }

    double degree(int nd, string weight = "")
    {
        if (!has_node(nd))
            throw NxCppError();

        if (weight == "") {
            if (has_edge(nd, nd))
                return adj[nd].size() + 1;
            return adj[nd].size();
        }

        double sum_weight = 0;
        for (auto [n, attr] : neighbors(nd)) {
            double wt;
            if (attr.find(weight) == attr.end())
                wt = 1;
            else
                wt = attr[weight];
            if (nd == n)
                wt *= 2;
            sum_weight += wt;
        }
        return sum_weight;
    }

    NodeDoubleDict degree(string weight = "")
    {
        NodeDoubleDict d;
        for (auto [n, attr] : node)
            d[n] = degree(n, weight);

        return d;
    }

    void clear()
    {
        adj.clear();
        node.clear();
    }

    void clear_edges()
    {
        for (auto& [nbr, nbrs_of_nbr] : adj) {
            nbrs_of_nbr.clear();
        }
    }

    void update()
    {
        throw NotImplementedException();
    }

    bool is_multigraph()
    {
        return false;
    }

    bool is_directed()
    {
        return false;
    }

    Graph subgraph(vector<int> nodes)
    {
        throw NotImplementedException();
    }

    Graph edge_subgraph(vector<int> nodes)
    {
        throw NotImplementedException();
    }

    int number_of_edges()
    {
        return edge_size();
    }

    void nbunch_iter()
    {
        throw NotImplementedException();
    }

    NodeDict node_dict_factory()
    {
        return NodeDict();
    }

    AttrDict node_attr_dict_factory()
    {
        return AttrDict();
    }

    OuterAdjDict adjlist_outer_dict_factory()
    {
        return OuterAdjDict();
    }

    NodeDict adjlist_inner_dict_factory()
    {
        return NodeDict();
    }

    AttrDict edge_attr_dict_factory()
    {
        return AttrDict();
    }

    Graph subgraph(unordered_set<Node> nodes)
    {
        Graph newg;
        for (auto nd : nodes) {
            if (!has_node(nd))
                continue;
            newg.add_node(nd, get_node_data(nd));
            for (auto [nbr, attr] : neighbors(nd)) {
                if (in(nodes, nbr))
                    newg.add_edge(nd, nbr, attr);
            }
        }

        return newg;
    }
};