#include "../graph.hpp"
#include "gtest/gtest.h"

class TestGraph : public ::testing::Test {
protected:
    Graph k3;
    NodeDict k3nodes;
    EdgeDict k3edges;
    OuterAdjDict k3adj;

    void SetUp() override
    {
        k3 = Graph();
        k3.add_edge(0, 1);
        k3.add_edge(0, 2);
        k3.add_edge(1, 2);
        k3nodes = NodeDict({ { 0, AttrDict() }, { 1, AttrDict() }, { 2, AttrDict() } });
        k3edges = EdgeDict({
            { Edge(0, 1), AttrDict() },
            { Edge(0, 2), AttrDict() },
            { Edge(1, 2), AttrDict() },
        });
        k3adj = OuterAdjDict({ { 0, AdjDict({ { 1, AttrDict() }, { 2, AttrDict() } }) },
            { 1, AdjDict({ { 0, AttrDict() }, { 2, AttrDict() } }) },
            { 2, AdjDict({ { 0, AttrDict() }, { 1, AttrDict() } }) } });
    }
};

TEST_F(TestGraph, TestContains)
{
    Graph g = k3;
    NodeDict nodes = g.nodes();
    ASSERT_NE(nodes.find(0), nodes.end());
    ASSERT_EQ(nodes.find(4), nodes.end());
}

TEST_F(TestGraph, TestOrder)
{
    Graph g = k3;
    ASSERT_EQ(g.size(), 3);
    ASSERT_EQ(g.order(), 3);
    ASSERT_EQ(g.number_of_nodes(), 3);
}

TEST_F(TestGraph, TestNodes)
{
    Graph g = k3;
    ASSERT_EQ(g.size(), 3);
    ASSERT_EQ(g.order(), 3);
    ASSERT_EQ(g.number_of_nodes(), 3);
}

TEST_F(TestGraph, TestHasNode)
{
    Graph g = k3;
    ASSERT_TRUE(g.has_node(1));
    ASSERT_FALSE(g.has_node(4));
}

TEST_F(TestGraph, TestGetNodeData)
{
    Graph g = k3;
    ASSERT_EQ(g.get_node_data(0), AttrDict());
    g.add_node(0, AttrDict({ { "foo", 1 } }));
    ASSERT_EQ(g.get_node_data(0), AttrDict({ { "foo", 1 } }));
    g.add_node(0, AttrDict({ { "bar", 2 } }));
    ASSERT_EQ(g.get_node_data(0), AttrDict({ { "foo", 1 }, { "bar", 2 } }));
    ASSERT_EQ(g.get_node_data(-1), AttrDict());
    AttrDict def_dict { { "foo", 1 }, { "bar", 2 } };
    ASSERT_EQ(g.get_node_data(-1, def_dict), def_dict);
}

TEST_F(TestGraph, TestHasEdge)
{
    Graph g = k3;
    ASSERT_TRUE(g.has_edge(0, 1));
    ASSERT_FALSE(g.has_edge(0, -1));
}

TEST_F(TestGraph, TestNeighbors)
{
    Graph g = k3;
    AdjDict adj0 {
        { 1, AttrDict() },
        { 2, AttrDict() }
    };
    ASSERT_EQ(g.neighbors(0), adj0);
    ASSERT_THROW(g.neighbors(-1), NxCppError);
}

TEST_F(TestGraph, TestEdges)
{
    Graph g = k3;
    ASSERT_EQ(g.edges(), k3edges);
    ASSERT_EQ(g.edges(0), EdgeDict({ { Edge(0, 1), AttrDict() }, { Edge(0, 2), AttrDict() } }));
    ASSERT_EQ(g.edges(vector<int> { 0, 1 }), EdgeDict({ { Edge(0, 1), AttrDict() }, { Edge(0, 2), AttrDict() }, { Edge(1, 2), AttrDict() } }));
}

TEST_F(TestGraph, TestDegree)
{
    Graph g = k3;
    ASSERT_EQ(g.degree(0), 2);
    ASSERT_THROW(g.degree(-1), NxCppError);
}

TEST_F(TestGraph, TestEdgeSize)
{
    Graph g = k3;
    ASSERT_EQ(g.edge_size(), 3);
    ASSERT_EQ(g.number_of_edges(), 3);
}

TEST_F(TestGraph, TestWeightedDegree)
{
    Graph g = k3;
    g.add_edge(1, 2, AttrDict({ { "weight", 2 }, { "other", 3 } }));
    g.add_edge(2, 3, AttrDict({ { "weight", 3 }, { "other", 4 } }));
    ASSERT_EQ(g.degree(0, "weight"), 2);
    ASSERT_EQ(g.degree(1, "weight"), 3);
    ASSERT_EQ(g.degree(2, "weight"), 6);
    ASSERT_EQ(g.degree(0, "other"), 2);
    ASSERT_EQ(g.degree(1, "other"), 4);
    ASSERT_EQ(g.degree(2, "other"), 8);
}

TEST_F(TestGraph, TestNodeAttr)
{
    Graph g = k3;
    g.add_node(1, AttrDict({ { "foo", 1 } }));
    ASSERT_EQ(g.nodes(), NodeDict({ { 0, AttrDict() }, { 1, AttrDict({ { "foo", 1 } }) }, { 2, AttrDict() } }));
}

TEST_F(TestGraph, TestEdgeAttr)
{
    Graph g = k3;
    g.add_edge(1, 2, AttrDict({ { "foo", 1 } }));
    ASSERT_EQ(g.edges(), EdgeDict({
                             { Edge(0, 1), AttrDict() },
                             { Edge(0, 2), AttrDict() },
                             { Edge(1, 2), AttrDict({ { "foo", 1 } }) },
                         }));
}

TEST_F(TestGraph, TestDataInput)
{
    Graph g = Graph();
    g.add_edge(1, 2);
    OuterAdjDict adj = g.adjacency();
    OuterAdjDict expected({ { 1, AdjDict({ { 2, AttrDict() } }) },
        { 2, AdjDict({ { 1, AttrDict() } }) } });
    ASSERT_EQ(adj, expected);
}

TEST_F(TestGraph, TestAdjacency)
{
    Graph g = k3;
    OuterAdjDict adj = g.adjacency();
    OuterAdjDict expected({ { 0, AdjDict({ { 1, AttrDict() }, { 2, AttrDict() } }) },
        { 1, AdjDict({ { 0, AttrDict() }, { 2, AttrDict() } }) },
        { 2, AdjDict({ { 0, AttrDict() }, { 1, AttrDict() } }) } });
    ASSERT_EQ(adj, expected);
}

TEST_F(TestGraph, TestAddNode)
{
    Graph g = Graph();
    g.add_node(0);
    ASSERT_EQ(g.adjacency(), OuterAdjDict({ { 0, AdjDict() } }));
    // test add attributes
    g.add_node(1, AttrDict({ { "weight", 0.1 } }));
    g.add_node(2, AttrDict({ { "weight", 0.2 } }));
    g.add_node(3, AttrDict({ { "weight", 0.3 } }));
    ASSERT_EQ(g.get_node_data(1), AttrDict({ { "weight", 0.1 } }));
    ASSERT_EQ(g.get_node_data(2), AttrDict({ { "weight", 0.2 } }));
    ASSERT_EQ(g.get_node_data(3), AttrDict({ { "weight", 0.3 } }));
    // test updating attributes
    g.add_node(1, AttrDict({ { "weight", 1 } }));
    g.add_node(2, AttrDict({ { "weight", 2 } }));
    g.add_node(3, AttrDict({ { "weight", 3 } }));
    ASSERT_EQ(g.get_node_data(1), AttrDict({ { "weight", 1 } }));
    ASSERT_EQ(g.get_node_data(2), AttrDict({ { "weight", 2 } }));
    ASSERT_EQ(g.get_node_data(3), AttrDict({ { "weight", 3 } }));
}

TEST_F(TestGraph, TestRemoveNode)
{
    Graph g = k3;
    g.remove_node(0);
    OuterAdjDict adj = g.adjacency();
    OuterAdjDict expected({ { 1, AdjDict({ { 2, AttrDict() } }) },
        { 2, AdjDict({ { 1, AttrDict() } }) } });
    ASSERT_EQ(adj, expected);
    EXPECT_THROW(g.remove_node(-1), NxCppError);
}

TEST_F(TestGraph, TestAddEdge)
{
    Graph g = Graph();
    g.add_edge(0, 1);
    OuterAdjDict adj = g.adjacency();
    OuterAdjDict expected({ { 0, AdjDict({ { 1, AttrDict() } }) },
        { 1, AdjDict({ { 0, AttrDict() } }) } });
    ASSERT_EQ(adj, expected);
}

TEST_F(TestGraph, TestRemoveEdge)
{
    Graph g = k3;
    g.remove_edge(0, 1);
    OuterAdjDict adj = g.adjacency();
    OuterAdjDict expected({ { 0, AdjDict({ { 2, AttrDict() } }) },
        { 1, AdjDict({ { 2, AttrDict() } }) },
        { 2, AdjDict({ { 0, AttrDict() }, { 1, AttrDict() } }) } });
    ASSERT_EQ(adj, expected);
    EXPECT_THROW(g.remove_edge(-1, 0), NxCppError);
}

TEST_F(TestGraph, TestClear)
{
    Graph g = k3;
    g.clear();
    ASSERT_EQ(g.nodes(), NodeDict());
    ASSERT_EQ(g.adjacency(), OuterAdjDict());
}

TEST_F(TestGraph, TestClearEdges)
{
    Graph g = k3;
    NodeDict nodes = g.nodes();
    g.clear_edges();
    ASSERT_EQ(nodes, g.nodes());
    ASSERT_EQ(g.adjacency(), OuterAdjDict({ { 0, AdjDict() }, { 1, AdjDict() }, { 2, AdjDict() } }));
}

TEST_F(TestGraph, TestGetEdgeData)
{
    Graph g = k3;
    ASSERT_EQ(g.get_edge_data(0, 1), AttrDict());
    AttrDict def_dict {
        { "foo", 1 },
        { "bar", 2 }
    };
    g.add_edge(0, 1, def_dict);
    ASSERT_EQ(g.get_edge_data(0, 1), def_dict);
    g.add_edge(0, 1, AttrDict({ { "baz", 3 } }));
    ASSERT_EQ(g.get_edge_data(0, 1), AttrDict({ { "foo", 1 }, { "bar", 2 }, { "baz", 3 } }));
    ASSERT_EQ(g.get_edge_data(10, 20), AttrDict());
    ASSERT_EQ(g.get_edge_data(-1, 0), AttrDict());
    ASSERT_EQ(g.get_edge_data(-1, 0, def_dict), def_dict);
}

TEST_F(TestGraph, TestUpdate)
{
    Graph g = Graph();
    ASSERT_THROW(g.update(), NotImplementedException);
}
