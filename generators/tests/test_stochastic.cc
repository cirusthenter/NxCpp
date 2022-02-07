#include "../stochastic.hpp"
#include <gtest/gtest.h>

class TestStochasticGraph : public ::testing::Test {
};

TEST_F(TestStochasticGraph, TestDefaultWeights)
{
    DiGraph g = DiGraph();
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    DiGraph s = stochastic_graph(g);
    ASSERT_EQ(s.edges(), EdgeDict({
                             { Edge(0, 1), AttrDict({ { "weight", 0.5 } }) },
                             { Edge(0, 2), AttrDict({ { "weight", 0.5 } }) },
                         }));
    ASSERT_EQ(g.edges(), EdgeDict({
                             { Edge(0, 1), AttrDict() },
                             { Edge(0, 2), AttrDict() },
                         }));
}

TEST_F(TestStochasticGraph, TestArbitraryWeights)
{
    DiGraph g = DiGraph();
    g.add_edge(0, 1, AttrDict({ { "weight", 1 } }));
    g.add_edge(0, 2, AttrDict({ { "weight", 1 } }));
    DiGraph s = stochastic_graph(g);
    ASSERT_EQ(s.edges(), EdgeDict({
                             { Edge(0, 1), AttrDict({ { "weight", 0.5 } }) },
                             { Edge(0, 2), AttrDict({ { "weight", 0.5 } }) },
                         }));
}
