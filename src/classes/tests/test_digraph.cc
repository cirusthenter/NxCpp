#include "../digraph.h"
#include "test_graph.cc"
#include <gtest/gtest.h>

class TestDiGraph : public TestGraph {
protected:
    DiGraph k3;
    OuterAdjDict k3succ;
    OuterAdjDict k3pred;
    DiGraph p3;

    void SetUp() override
    {
        k3 = DiGraph();
        k3.add_edge(0, 1);
        k3.add_edge(1, 0);
        k3.add_edge(0, 2);
        k3.add_edge(2, 0);
        k3.add_edge(1, 2);
        k3.add_edge(2, 1);
        k3nodes = NodeDict({ { 0, AttrDict() }, { 1, AttrDict() }, { 2, AttrDict() } });
        k3edges = EdgeDict({
            { Edge(0, 1), AttrDict() },
            { Edge(1, 0), AttrDict() },
            { Edge(0, 2), AttrDict() },
            { Edge(2, 0), AttrDict() },
            { Edge(1, 2), AttrDict() },
            { Edge(2, 1), AttrDict() },
        });
        k3adj = OuterAdjDict({ { 0, AdjDict({ { 1, AttrDict() }, { 2, AttrDict() } }) },
            { 1, AdjDict({ { 0, AttrDict() }, { 2, AttrDict() } }) },
            { 2, AdjDict({ { 0, AttrDict() }, { 1, AttrDict() } }) } });
        k3pred = k3adj;
        k3succ = k3adj;

        p3 = DiGraph();
        p3.add_edge(0, 1);
        p3.add_edge(1, 2);
    }
};

TEST_F(TestDiGraph, TestHasEdge)
{
    DiGraph g = p3;
    ASSERT_TRUE(g.has_successor(0, 1));
    ASSERT_FALSE(g.has_successor(1, 0));
    ASSERT_FALSE(g.has_successor(0, -1));
}

TEST_F(TestDiGraph, TestHasSuccessor)
{
    DiGraph g = k3;
    ASSERT_TRUE(g.has_successor(0, 1));
    ASSERT_FALSE(g.has_successor(0, -1));
}

TEST_F(TestDiGraph, TestSuccessors)
{
    DiGraph g = k3;
    ASSERT_EQ(g.successors(0), AdjDict({ { 1, AttrDict() }, { 2, AttrDict() } }));
    ASSERT_THROW(g.successors(-1), NxCppError);
}

TEST_F(TestDiGraph, TestHasPredessor)
{
    DiGraph g = k3;
    ASSERT_TRUE(g.has_predecessor(0, 1));
    ASSERT_FALSE(g.has_predecessor(0, -1));
}

TEST_F(TestDiGraph, TestPredessors)
{
    DiGraph g = k3;
    ASSERT_EQ(g.predecessors(0), AdjDict({ { 1, AttrDict() }, { 2, AttrDict() } }));
    ASSERT_THROW(g.predecessors(-1), NxCppError);
}

TEST_F(TestDiGraph, TestEdges)
{
    DiGraph g = k3;
    EdgeDict edges {
        { Edge(0, 1), AttrDict() },
        { Edge(1, 0), AttrDict() },
        { Edge(0, 2), AttrDict() },
        { Edge(2, 0), AttrDict() },
        { Edge(1, 2), AttrDict() },
        { Edge(2, 1), AttrDict() },
    };
    ASSERT_EQ(g.edges(), edges);
    ASSERT_EQ(g.edges(0), EdgeDict({ { Edge(0, 1), AttrDict() }, { Edge(0, 2), AttrDict() } }));
    ASSERT_EQ(g.edges(vector<int> { 0, 1 }), EdgeDict({ { Edge(0, 1), AttrDict() }, { Edge(0, 2), AttrDict() }, { Edge(1, 0), AttrDict() }, { Edge(1, 2), AttrDict() } }));
    ASSERT_THROW(g.edges(-1), NxCppError);
    ASSERT_THROW(g.edges(vector<int> { 0, 1, 2, -1 }), NxCppError);
}

TEST_F(TestDiGraph, TestOutEdges)
{
    DiGraph g = k3;
    EdgeDict out_edges {
        { Edge(0, 1), AttrDict() },
        { Edge(1, 0), AttrDict() },
        { Edge(0, 2), AttrDict() },
        { Edge(2, 0), AttrDict() },
        { Edge(1, 2), AttrDict() },
        { Edge(2, 1), AttrDict() },
    };
    ASSERT_EQ(g.out_edges(), out_edges);
    ASSERT_EQ(g.out_edges(0), EdgeDict({ { Edge(0, 1), AttrDict() }, { Edge(0, 2), AttrDict() } }));
    ASSERT_EQ(g.out_edges(vector<int> { 0, 1 }), EdgeDict({ { Edge(0, 1), AttrDict() }, { Edge(0, 2), AttrDict() }, { Edge(1, 0), AttrDict() }, { Edge(1, 2), AttrDict() } }));
    ASSERT_THROW(g.out_edges(-1), NxCppError);
    ASSERT_THROW(g.out_edges(vector<int> { 0, 1, 2, -1 }), NxCppError);
}

TEST_F(TestDiGraph, TestOutEdgesDir)
{
    DiGraph g = p3;
    EdgeDict out_edges {
        { Edge(0, 1), AttrDict() },
        { Edge(1, 2), AttrDict() },
    };
    ASSERT_EQ(g.out_edges(), out_edges);
    ASSERT_EQ(g.out_edges(0), EdgeDict({ { Edge(0, 1), AttrDict() } }));
    ASSERT_EQ(g.out_edges(vector<int> { 0, 1 }), out_edges);
    ASSERT_THROW(g.out_edges(-1), NxCppError);
    ASSERT_THROW(g.out_edges(vector<int> { 0, 1, 2, -1 }), NxCppError);
}

TEST_F(TestDiGraph, TestInEdgesDir)
{
    DiGraph g = p3;
    EdgeDict in_edges {
        { Edge(0, 1), AttrDict() },
        { Edge(1, 2), AttrDict() },
    };
    ASSERT_EQ(g.in_edges(), in_edges);
    ASSERT_EQ(g.in_edges(0), EdgeDict());
    ASSERT_EQ(g.in_edges(1), EdgeDict({ { Edge(0, 1), AttrDict() } }));
    ASSERT_EQ(g.in_edges(vector<int> { 0, 1 }), EdgeDict({ { Edge(0, 1), AttrDict() } }));
    ASSERT_THROW(g.in_edges(-1), NxCppError);
    ASSERT_THROW(g.in_edges(vector<int> { 0, 1, 2, -1 }), NxCppError);
}

TEST_F(TestDiGraph, TestDegree)
{
    DiGraph g = k3;
    pair<double, double> in_out(2, 2);
    ASSERT_EQ(g.degree(0), in_out);
    g = p3;
    in_out = pair<double, double>(0, 1);
    ASSERT_EQ(g.degree(0), in_out);
    ASSERT_THROW(g.degree(-1), NodeNotFound);
}

TEST_F(TestDiGraph, TestInDegree)
{
    DiGraph g = k3;
    ASSERT_EQ(g.in_degree(0), 2);
    ASSERT_THROW(g.in_degree(-1), NodeNotFound);
}

TEST_F(TestDiGraph, TestOutDegree)
{
    DiGraph g = k3;
    ASSERT_EQ(g.out_degree(0), 2);
    ASSERT_THROW(g.out_degree(-1), NodeNotFound);
}

TEST_F(TestDiGraph, TestEdgeSize)
{
    DiGraph g = k3;
    ASSERT_EQ(g.edge_size(), 6);
}

TEST_F(TestDiGraph, TestInDegreeWeighted)
{
    DiGraph g = k3;
    g.add_edge(0, 1, AttrDict({ { "weight", 0.3 }, { "other", 1.2 } }));
    ASSERT_EQ(g.in_degree(0, "weight"), 2);
    ASSERT_EQ(g.in_degree(1, "weight"), 1.3);
    ASSERT_EQ(g.in_degree(0, "other"), 2);
    ASSERT_EQ(g.in_degree(1, "other"), 2.2);
}

TEST_F(TestDiGraph, TestOutDegreeWeighted)
{
    DiGraph g = k3;
    g.add_edge(0, 1, AttrDict({ { "weight", 0.3 }, { "other", 1.2 } }));
    ASSERT_EQ(g.out_degree(0, "weight"), 1.3);
    ASSERT_EQ(g.out_degree(1, "weight"), 2);
    ASSERT_EQ(g.out_degree(0, "other"), 2.2);
    ASSERT_EQ(g.out_degree(1, "other"), 2);
}

TEST_F(TestDiGraph, TestDataInput)
{
    DiGraph g = DiGraph();
    g.add_edge(1, 2);
    g.add_edge(2, 1);
    OuterAdjDict expected({ { 1, AdjDict({ { 2, AttrDict() } }) },
        { 2, AdjDict({ { 1, AttrDict() } }) } });
    ASSERT_EQ(g.adjacency(), expected);
    ASSERT_EQ(g.successor(), expected);
    ASSERT_EQ(g.predecessor(), expected);
}

TEST_F(TestDiGraph, TestAddEdge)
{
    DiGraph g = DiGraph();
    g.add_edge(0, 1);
    OuterAdjDict succ_expected({ { 0, AdjDict({ { 1, AttrDict() } }) }, { 1, AdjDict() } });
    OuterAdjDict pred_expected({ { 0, AdjDict() }, { 1, AdjDict({ { 0, AttrDict() } }) } });
    ASSERT_EQ(g.adjacency(), succ_expected);
    ASSERT_EQ(g.successor(), succ_expected);
    ASSERT_EQ(g.predecessor(), pred_expected);
}

TEST_F(TestDiGraph, TestRemoveEdge)
{
    DiGraph g = k3;
    g.remove_edge(0, 1);
    OuterAdjDict succ_expected = OuterAdjDict({ { 0, AdjDict({ { 2, AttrDict() } }) },
        { 1, AdjDict({ { 0, AttrDict() }, { 2, AttrDict() } }) },
        { 2, AdjDict({ { 0, AttrDict() }, { 1, AttrDict() } }) } });
    OuterAdjDict pred_expected = OuterAdjDict({ { 0, AdjDict({ { 1, AttrDict() }, { 2, AttrDict() } }) },
        { 1, AdjDict({ { 2, AttrDict() } }) },
        { 2, AdjDict({ { 0, AttrDict() }, { 1, AttrDict() } }) } });
    ASSERT_EQ(g.adjacency(), succ_expected);
    ASSERT_EQ(g.successor(), succ_expected);
    ASSERT_EQ(g.predecessor(), pred_expected);
}

TEST_F(TestDiGraph, TestClear)
{
    DiGraph g = k3;
    g.clear();
    ASSERT_EQ(g.nodes(), NodeDict());
    ASSERT_EQ(g.adjacency(), OuterAdjDict());
    ASSERT_EQ(g.successor(), OuterAdjDict());
    ASSERT_EQ(g.predecessor(), OuterAdjDict());
}

TEST_F(TestDiGraph, TestClearEdges)
{
    DiGraph g = k3;
    NodeDict nodes = g.nodes();
    g.clear_edges();
    ASSERT_EQ(nodes, g.nodes());
    ASSERT_EQ(g.adjacency(), OuterAdjDict({ { 0, AdjDict() }, { 1, AdjDict() }, { 2, AdjDict() } }));
    ASSERT_EQ(g.successor(), OuterAdjDict({ { 0, AdjDict() }, { 1, AdjDict() }, { 2, AdjDict() } }));
    ASSERT_EQ(g.predecessor(), OuterAdjDict({ { 0, AdjDict() }, { 1, AdjDict() }, { 2, AdjDict() } }));
}