#include "../random_graphs.hpp"
#include <gtest/gtest.h>

class TestRandomGraphs : public ::testing::Test {
};

TEST_F(TestRandomGraphs, TestGnpGeneratorsNegativeEdgeProbability)
{
    Graph g = gnp_random_graph(10, -1.1);
    ASSERT_EQ(g.size(), 10);
    ASSERT_EQ(g.number_of_edges(), 0);
}

TEST_F(TestRandomGraphs, TestGnpGeneratorsGreaterThan1EdgeProbability)
{
    Graph g = gnp_random_graph(10, 1.1);
    ASSERT_EQ(g.size(), 10);
    ASSERT_EQ(g.number_of_edges(), 45);
}

TEST_F(TestRandomGraphs, TestGnpGeneratorsForPCloseTo1)
{
    int runs = 100;
    int sum_edges = 0;
    for (int i = 0; i < runs; ++i) {
        sum_edges += gnp_random_graph(10, 0.99999).number_of_edges();
    }
    ASSERT_LE(abs(sum_edges / (double)runs - 45), runs * 2.0 / 100);
}

TEST_F(TestRandomGraphs, TestGnpGeneratorsEdgeProbability)
{
    float ps[] { 0.2, 0.8 };
    for (auto p : ps) {
        int runs = 5000;
        int n = 5;
        vector<vector<int>> edge_counts(n, vector<int>(n, 0));
        for (int i = 0; i < runs; ++i) {
            Graph g = gnp_random_graph(n, p);
            for (auto [e, attr] : g.edges()) {
                int u = e.first, v = e.second;
                edge_counts[u][v]++;
                edge_counts[v][u]++;
            }
        }
        for (int v = 0; v < n; ++v) {
            for (int w = 0; w < n; ++w) {
                if (v == w)
                    ASSERT_EQ(edge_counts[v][w], 0);
                else
                    ASSERT_LE(abs(edge_counts[v][w] / double(runs) - p), 0.03);
            }
        }
    }
}