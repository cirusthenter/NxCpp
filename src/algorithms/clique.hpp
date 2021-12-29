#pragma once
#include "clique.h"

// I'll be back!

/*
vector<vector<int>> find_cliques(Graph g)
{
    vector<vector<int>> cliques;
    if (g.size() == 0)
        return vector<vector<int>>();
    unordered_map<int, unordered_set<int>> adj = convert_mapmap_to_mapset(g.adjacency());

    // avoid self loop
    for (auto [n, nbrs] : adj)
        if (in(nbrs, n))
            adj[n].erase(n);
    unordered_set<Node> subg = convert_map_to_set(g.nodes());
    unordered_set<Node> cand = subg;
    Node u = *subg.begin();
    int max_deg = intersection(cand, adj[u]).size();
    for (Node v : subg) {
        int intersection_size = intersection(cand, adj[v]).size();
        if (intersection_size > max_deg) {
            u = v;
            max_deg = intersection_size;
        }
    }
    unordered_set<int> ext_u = difference(cand, adj[u]);
    vector<int> c { -1 };

    typedef pair<pair<unordered_set<Node>, unordered_set<Node>>, unordered_set<Node>> SubgCandExtu;
    stack<SubgCandExtu> st;

    try {
        while (true) {
            if (!ext_u.empty()) {
                auto ext_u_vec = convert_set_to_vector(ext_u);
                std::shuffle(
                    ext_u_vec.begin(),
                    ext_u_vec.end(),
                    std::default_random_engine { std::random_device {}() });
                int q = ext_u_vec[0];
                ext_u.erase(q);
                cand.erase(q);
                c[c.size() - 1] = q;
                unordered_set<int> adj_q = adj[q];
                auto subg_q = intersection(subg, adj_q);
                if (subg_q.empty()) {
                    vector<int> clique = c;
                    cliques.push_back(clique);
                } else {
                    auto cand_q = intersection(cand, adj_q);
                    if (!cand_q.empty()) {
                        st.push(SubgCandExtu(pair<unordered_set<Node>, unordered_set<Node>>(subg, cand_q), ext_u));
                        c.push_back(-1);
                        subg = subg_q;
                        cand = cand_q;
                        Node u = *subg.begin();
                        int max_deg = intersection(cand, adj[u]).size();
                        for (Node v : subg) {
                            int intersection_size = intersection(cand, adj[v]).size();
                            if (intersection_size > max_deg) {
                                u = v;
                                max_deg = intersection_size;
                            }
                        }
                        unordered_set<int> ext_u = difference(cand, adj[u]);
                    }
                }
            } else {
                c.pop_back();
                if (st.empty())
                    throw IndexOutOfRangeException();
                SubgCandExtu res = st.top();
                subg = res.first.first;
                cand = res.first.second;
                ext_u = res.second;
                st.pop();
            }
        }
    } catch (IndexOutOfRangeException& e) {
        return cliques;
    }

    return cliques;
}

int number_of_cliques(Graph g)
{
}

*/