#include "../../../generators/classic.hpp"
#include "../../../utils/random.hpp"
#include "../pagerank_alg.hpp"
#include <gtest/gtest.h>
#define EPSILON 0.0001

class TestPageRank : public ::testing::Test {
protected:
    DiGraph g;
    NodeDoubleDict pr;
    Node dangling_node_index;
    NodeDoubleDict dangling_edges;
    NodeDoubleDict dangling_pr;

    void SetUp() override
    {
        g.add_edge(1, 2);
        g.add_edge(1, 3);
        // 2 is a dangling node
        g.add_edge(3, 1);
        g.add_edge(3, 2);
        g.add_edge(3, 5);
        g.add_edge(4, 5);
        g.add_edge(4, 6);
        g.add_edge(5, 4);
        g.add_edge(5, 6);
        g.add_edge(6, 4);
        pr = NodeDoubleDict({
            { 1, 0.03721197 },
            { 2, 0.05395735 },
            { 3, 0.04150565 },
            { 4, 0.37508082 },
            { 5, 0.20599833 },
            { 6, 0.28624589 },
        });
        dangling_node_index = 1;
        dangling_edges = NodeDoubleDict({
            { 1, 2 },
            { 2, 3 },
            { 3, 0 },
            { 4, 0 },
            { 5, 0 },
            { 6, 0 },
        });
        dangling_pr = NodeDoubleDict({
            { 1, 0.10844518 },
            { 2, 0.18618601 },
            { 3, 0.0710892 },
            { 4, 0.2683668 },
            { 5, 0.15919783 },
            { 6, 0.20671497 },
        });
    }
};

TEST_F(TestPageRank, TestPageRank)
{
    NodeDoubleDict p = pagerank(g, 0.9, 0.00000001);
    for (auto [nd, attr] : g.nodes())
        ASSERT_NEAR(p[nd], pr[nd], EPSILON);

    NodeDoubleDict nstart;
    for (auto [n, attr] : g.nodes())
        nstart[n] = random_double(0, 1);
    p = pagerank(g, 0.9, 0.00000001, 100, "weight", NodeDoubleDict(), nstart, NodeDoubleDict());
    for (auto [nd, attr] : g.nodes())
        ASSERT_NEAR(p[nd], pr[nd], EPSILON);
}

TEST_F(TestPageRank, TestPageRankMaxIter)
{
    ASSERT_THROW(pagerank(g, 0.85, 0.00000001, 0), PowerIterationFailedConvergence);
}

TEST_F(TestPageRank, TestPersonalization)
{
    DiGraph g = complete_directed_graph(4);
    NodeDoubleDict personalize = NodeDoubleDict({
        { 0, 1 },
        { 1, 1 },
        { 2, 4 },
        { 3, 4 },
    });
    NodeDoubleDict answer = NodeDoubleDict({
        { 0, 0.23246732615667579 },
        { 1, 0.23246732615667579 },
        { 2, 0.267532673843324 },
        { 3, 0.2675326738433241 },
    });
    NodeDoubleDict p = pagerank(g, 0.85, 0.00000001, 100, "weight", personalize, NodeDoubleDict(), NodeDoubleDict());
    for (auto [nd, attr] : g.nodes())
        ASSERT_NEAR(p[nd], answer[nd], EPSILON);
}

TEST_F(TestPageRank, TestZeroPersonalizationVector)
{
    DiGraph g = complete_directed_graph(4);
    NodeDoubleDict personalize = NodeDoubleDict({
        { 0, 0 },
        { 1, 0 },
        { 2, 0 },
        { 3, 0 },
    });
    ASSERT_THROW(pagerank(g, 0.85, 0.00000001, 100, "weight", personalize, NodeDoubleDict(), NodeDoubleDict()), ZeroDivisionError);
}

TEST_F(TestPageRank, TestNonZeroPersonalization)
{
    DiGraph g = complete_directed_graph(4);
    NodeDoubleDict personalize = NodeDoubleDict({
        { 0, 0 },
        { 1, 0 },
        { 2, 0 },
        { 3, 1 },
    });
    NodeDoubleDict answer = NodeDoubleDict({
        { 0, 0.22077931820379187 },
        { 1, 0.22077931820379187 },
        { 2, 0.22077931820379187 },
        { 3, 0.3376620453886241 },
    });
    NodeDoubleDict p = pagerank(g, 0.85, 0.00000001, 100, "weight", personalize, NodeDoubleDict(), NodeDoubleDict());
    for (auto [nd, attr] : g.nodes())
        ASSERT_NEAR(p[nd], answer[nd], EPSILON);
}

TEST_F(TestPageRank, TestIncompletePersonalization)
{
    DiGraph g = complete_directed_graph(4);
    NodeDoubleDict personalize = NodeDoubleDict({
        { 3, 1 },
    });
    NodeDoubleDict answer = NodeDoubleDict({
        { 0, 0.22077931820379187 },
        { 1, 0.22077931820379187 },
        { 2, 0.22077931820379187 },
        { 3, 0.3376620453886241 },
    });
    NodeDoubleDict p = pagerank(g, 0.85, 0.00000001, 100, "weight", personalize, NodeDoubleDict(), NodeDoubleDict());
    for (auto [nd, attr] : g.nodes())
        ASSERT_NEAR(p[nd], answer[nd], EPSILON);
}

TEST_F(TestPageRank, TestDanglingPageRank)
{
    NodeDoubleDict p = pagerank(g, 0.85, 0.00000001, 100, "weight", NodeDoubleDict(), NodeDoubleDict(), dangling_edges);
    for (auto [nd, attr] : g.nodes())
        ASSERT_NEAR(p[nd], dangling_pr[nd], EPSILON);
}

TEST_F(TestPageRank, TestEmpty)
{
    DiGraph g = DiGraph();
    ASSERT_EQ(pagerank(g), NodeDoubleDict());
}
