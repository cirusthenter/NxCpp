#include "../classic.hpp"
#include <gtest/gtest.h>

class TestClassic : public ::testing::Test {
};

TEST_F(TestClassic, TestCycleGraph)
{
    Graph g = cycle_graph(4);
    EdgeDict expected({
        { pair<int, int>(0, 1), AttrDict() },
        { pair<int, int>(0, 3), AttrDict() },
        { pair<int, int>(1, 2), AttrDict() },
        { pair<int, int>(2, 3), AttrDict() },
    });
    ASSERT_EQ(g.edges(), expected);
}

TEST_F(TestClassic, TestCycleDiGraph)
{
    DiGraph g = cycle_digraph(4);
    EdgeDict expected({
        { pair<int, int>(0, 1), AttrDict() },
        { pair<int, int>(1, 2), AttrDict() },
        { pair<int, int>(2, 3), AttrDict() },
        { pair<int, int>(3, 0), AttrDict() },
    });
    ASSERT_EQ(g.edges(), expected);
    ASSERT_FALSE(g.has_edge(2, 1));
    ASSERT_TRUE(g.has_edge(1, 2));
    ASSERT_TRUE(g.is_directed());
}

TEST_F(TestClassic, TestEmptyGraph)
{
    Graph g = empty_graph();
    ASSERT_EQ(g.number_of_nodes(), 0);
    g = empty_graph(42);
    ASSERT_EQ(g.number_of_nodes(), 42);
    ASSERT_EQ(g.number_of_edges(), 0);
}

TEST_F(TestClassic, TestEmptyDiGraph)
{
    DiGraph g = empty_digraph();
    ASSERT_EQ(g.number_of_nodes(), 0);
    g = empty_digraph(42);
    ASSERT_EQ(g.number_of_nodes(), 42);
    ASSERT_EQ(g.number_of_edges(), 0);
}

TEST_F(TestClassic, TestPathGraph)
{
    // This has to be updated
    Graph p;

    p = path_graph(0);
    ASSERT_EQ(p.number_of_nodes(), 0);
    ASSERT_EQ(p.number_of_edges(), 0);

    p = path_graph(1);
    ASSERT_EQ(p.number_of_nodes(), 1);
    ASSERT_EQ(p.number_of_edges(), 0);

    p = path_graph(10);
    // ASSERT_EQ(is_connected(p));
    ASSERT_EQ(p.number_of_edges(), 9);
}
