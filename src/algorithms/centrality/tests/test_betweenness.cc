#include "../../../generators/classic.hpp"
#include "../../../generators/small.hpp"
#include "../betweenness.hpp"
#include <gtest/gtest.h>

bool equal_to_6th_place(double a, double b)
{
    int x1 = (a * 1000000);
    int x2 = (b * 1000000);
    return x1 == x2;
}

class TestBetweennessCentrality : public ::testing::Test {
};

TEST_F(TestBetweennessCentrality, TestK5)
{
    Graph g = complete_graph(5);
    NodeDoubleDict b = betweenness_centrality(g, false);
    NodeDoubleDict expected {
        { 0, 0 },
        { 1, 0 },
        { 2, 0 },
        { 3, 0 },
        { 4, 0 },
    };
    ASSERT_EQ(b, expected);
}

TEST_F(TestBetweennessCentrality, TestP3Normalized)
{
    Graph g = path_graph(3);
    NodeDoubleDict b = betweenness_centrality(g, true);
    NodeDoubleDict expected {
        { 0, 0 },
        { 1, 1 },
        { 2, 0 },
    };
    ASSERT_EQ(b, expected);
}

TEST_F(TestBetweennessCentrality, TestP3)
{
    Graph g = path_graph(3);
    NodeDoubleDict b = betweenness_centrality(g, false);
    NodeDoubleDict expected {
        { 0, 0 },
        { 1, 1 },
        { 2, 0 },
    };
    ASSERT_EQ(b, expected);
}

TEST_F(TestBetweennessCentrality, TestKrackhardtKiteGraph)
{
    Graph g = krackhardt_kite_graph();
    NodeDoubleDict b = betweenness_centrality(g, false);
    NodeDoubleDict expected {
        { 0, (double)5 / 3 },
        { 1, (double)5 / 3 },
        { 2, 0 },
        { 3, (double)22 / 3 },
        { 4, 0 },
        { 5, (double)50 / 3 },
        { 6, (double)50 / 3 },
        { 7, 28 },
        { 8, 16 },
        { 9, 0 },
    };
    for (auto [n, bet] : b)
        expected[n] /= 2;
    for (auto [n, val] : b)
        ASSERT_TRUE(equal_to_6th_place(expected[n], val));
}

TEST_F(TestBetweennessCentrality, TestKrackhardtKiteGraphNormalized)
{
    Graph g = krackhardt_kite_graph();
    NodeDoubleDict b = betweenness_centrality(g, true);
    NodeDoubleDict expected {
        { 0, (double)5 / 216 },
        { 1, (double)5 / 216 },
        { 2, 0 },
        { 3, (double)22 / 216 },
        { 4, 0 },
        { 5, (double)50 / 216 },
        { 6, (double)50 / 216 },
        { 7, (double)28 / 72 },
        { 8, (double)16 / 72 },
        { 9, 0 },
    };
    for (auto [n, val] : b)
        ASSERT_TRUE(equal_to_6th_place(expected[n], val));
}