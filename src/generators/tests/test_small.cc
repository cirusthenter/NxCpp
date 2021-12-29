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
