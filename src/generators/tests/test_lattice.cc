#include "../../classes/function.hpp"
#include "../lattice.hpp"
#include <gtest/gtest.h>

class TestLattice : public ::testing::Test {
};

TEST_F(TestLattice, TestNumberOfVertices)
{
    int m = 5, n = 6;
    Graph g = grid_2d_graph(m, n);
    ASSERT_EQ(g.size(), m * n);
}

TEST_F(TestLattice, TestDegreeDistribution)
{
    int m = 5, n = 6;
    Graph g = grid_2d_graph(m, n);
    vector<int> expected_histogram({ 0, 0, 4, 2 * (m + n) - 8, (m - 2) * (n - 2) });
    ASSERT_EQ(degree_histogram(g), expected_histogram);
}

TEST_F(TestLattice, TestDirected)
{
    int m = 5, n = 6;
    Graph g = grid_2d_graph(m, n);
    DiGraph h = grid_2d_digraph(m, n);
    ASSERT_EQ(h.succs(), g.adjacency());
    ASSERT_EQ(h.preds(), g.adjacency());
}