#include "../../../generators/lattice.hpp"
#include "../connected.hpp"
#include <gtest/gtest.h>

class TestIsomorph : public ::testing::Test {
protected:
    Graph grid;
    void SetUp() override
    {
        grid = grid_2d_graph(4, 4);
    }
};

TEST_F(TestIsomorph, TestCouldBeIsomorphic)
{
    ASSERT_TRUE(is_connected(grid));
    Graph g;
    g.add_node(1);
    g.add_node(2);
    ASSERT_FALSE(is_connected(g));
}