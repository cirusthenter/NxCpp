#include "../small.hpp"
#include <gtest/gtest.h>

class TestGeneratorsSmall : public ::testing::Test {
};

TEST_F(TestGeneratorsSmall, TestCubicGraph)
{
    Graph g = cubical_graph();
    ASSERT_EQ(g.number_of_nodes(), 8);
    ASSERT_EQ(g.number_of_edges(), 12);
}

TEST_F(TestGeneratorsSmall, TestKrackhardtKiteGraph)
{
    Graph g = krackhardt_kite_graph();
    ASSERT_EQ(g.number_of_nodes(), 10);
    ASSERT_EQ(g.number_of_edges(), 18);
    vector<double> degrees;
    for (auto [n, d] : g.degree())
        degrees.push_back(d);
    sort(degrees.begin(), degrees.end());
    ASSERT_EQ(degrees, vector<double>({ 1, 2, 3, 3, 3, 4, 4, 5, 5, 6 }));
}
