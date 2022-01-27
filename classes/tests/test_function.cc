#include "../function.hpp"
#include <gtest/gtest.h>

class TestFunction : public ::testing::Test {
protected:
    Graph g;
    unordered_map<int, int> gdegree;

    void SetUp() override
    {
        g = Graph();
        g.add_edge(0, 1);
        g.add_edge(0, 2);
        g.add_edge(0, 3);
        g.add_edge(1, 1);
        g.add_edge(1, 2);
        g.add_node(4);
        gdegree = unordered_map<int, int>({
            { 0, 3 },
            { 1, 2 },
            { 2, 2 },
            { 3, 1 },
            { 4, 0 },
        });
    }
};

TEST_F(TestFunction, TestDegreeHistogram)
{
    NodeDict nodes = g.nodes();
    vector<int> expected({ 1, 1, 1, 1, 1 });
    ASSERT_EQ(degree_histogram(g), expected);
}