#include "../../algorithms/components/connected.hpp"
#include "../../algorithms/isomorphism/isomorph.hpp"
#include "../classic.hpp"
#include <gtest/gtest.h>

auto is_isomorphic(Graph g1, Graph g2)
{
    return graph_could_be_isomorphic(g1, g2);
}

class TestClassic : public ::testing::Test {
};

TEST_F(TestClassic, TestBarbellGraph)
{

    // number of nodes = 2*m1 + m2 (2 m1-complete graphs + m2-path + 2 edges)
    // number of edges = 2*(nx.number_of_edges(m1-complete graph) + m2 + 1
    int m1, m2;
    Graph b;

    m1 = 3;
    m2 = 5;
    b = barbell_graph(m1, m2);
    ASSERT_EQ(b.number_of_nodes(), 2 * m1 + m2);
    ASSERT_EQ(b.number_of_edges(), m1 * (m1 - 1) + m2 + 1);

    m1 = 4;
    m2 = 10;
    b = barbell_graph(m1, m2);
    ASSERT_EQ(b.number_of_nodes(), 2 * m1 + m2);
    ASSERT_EQ(b.number_of_edges(), m1 * (m1 - 1) + m2 + 1);

    m1 = 3;
    m2 = 20;
    b = barbell_graph(m1, m2);
    ASSERT_EQ(b.number_of_nodes(), 2 * m1 + m2);
    ASSERT_EQ(b.number_of_edges(), m1 * (m1 - 1) + m2 + 1);

    // Raise NetworkXError if m1 < 2
    m1 = 1;
    m2 = 20;
    ASSERT_THROW(barbell_graph(m1, m2), NxCppError);

    // Raise NetworkXError if m2 < 0
    m1 = 5;
    m2 = -2;
    ASSERT_THROW(barbell_graph(m1, m2), NxCppError);

    // barbell_graph(2, m) = path_graph(m + 4)
    m1 = 2;
    m2 = 5;
    b = barbell_graph(m1, m2);
    ASSERT_TRUE(is_isomorphic(b, path_graph(m2 + 4)));

    m1 = 2;
    m2 = 10;
    b = barbell_graph(m1, m2);
    ASSERT_TRUE(is_isomorphic(b, path_graph(m2 + 4)));

    m1 = 2;
    m2 = 20;
    b = barbell_graph(m1, m2);
    ASSERT_TRUE(is_isomorphic(b, path_graph(m2 + 4)));
}

TEST_F(TestClassic, TestCompleteGraph)
{
    int cases[] = { 0, 1, 3, 5 };
    for (int m : cases) {
        Graph g = complete_graph(m);
        ASSERT_EQ(g.number_of_nodes(), m);
        ASSERT_EQ(g.number_of_edges(), m * (m - 1) / 2);
    }
}

TEST_F(TestClassic, TestCompleteDirectedGraph)
{
    int cases[] = { 0, 1, 3, 5 };
    for (int m : cases) {
        DiGraph g = complete_directed_graph(m);
        ASSERT_EQ(g.number_of_nodes(), m);
        ASSERT_EQ(g.number_of_edges(), m * (m - 1));
    }
}

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

TEST_F(TestClassic, TestNullGraph)
{
    Graph g = null_graph();
    ASSERT_EQ(g.number_of_nodes(), 0);
}

TEST_F(TestClassic, TestNullDiGraph)
{
    DiGraph g = null_digraph();
    ASSERT_EQ(g.number_of_nodes(), 0);
}

TEST_F(TestClassic, TestPathGraph)
{
    // This has to be updated
    Graph p;

    p = path_graph(0);
    ASSERT_TRUE(is_isomorphic(p, null_graph()));

    p = path_graph(1);
    ASSERT_TRUE(is_isomorphic(p, empty_graph(1)));

    p = path_graph(10);
    ASSERT_TRUE(is_connected(p));
    ASSERT_EQ(p.number_of_edges(), 9);
    NodeDoubleDict expected {
        { 0, 1 },
        { 1, 2 },
        { 2, 2 },
        { 3, 2 },
        { 4, 2 },
        { 5, 2 },
        { 6, 2 },
        { 7, 2 },
        { 8, 2 },
        { 9, 1 },
    };
    ASSERT_EQ(p.degree(), expected);
    ASSERT_EQ(p.order() - 1, p.edge_size());

    DiGraph dp = path_digraph(3);
    ASSERT_TRUE(dp.has_edge(0, 1));
    ASSERT_FALSE(dp.has_edge(1, 0));
}
