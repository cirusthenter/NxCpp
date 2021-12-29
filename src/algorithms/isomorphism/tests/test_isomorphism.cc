#include "../isomorph.hpp"
#include <gtest/gtest.h>

class TestIsomorph : public ::testing::Test {
protected:
    Graph g1, g2, g3, g4, g5, g6;
    void SetUp() override
    {
        g1.add_edge(1, 2);
        g1.add_edge(1, 3);
        g1.add_edge(1, 5);
        g1.add_edge(2, 3);
        g2.add_edge(10, 20);
        g2.add_edge(10, 30);
        g2.add_edge(10, 50);
        g2.add_edge(20, 30);
        g3.add_edge(1, 2);
        g3.add_edge(1, 3);
        g3.add_edge(1, 5);
        g3.add_edge(2, 5);
        g4.add_edge(1, 2);
        g4.add_edge(1, 3);
        g4.add_edge(1, 5);
        g4.add_edge(2, 4);
        g5.add_edge(1, 2);
        g5.add_edge(1, 3);
        g6.add_edge(10, 20);
        g6.add_edge(10, 30);
        g6.add_edge(10, 50);
        g6.add_edge(20, 30);
        g6.add_edge(20, 50);
    }
};

TEST_F(TestIsomorph, TestCouldBeIsomorphic)
{
    ASSERT_TRUE(could_be_isomorphic(g1, g2));
    ASSERT_TRUE(could_be_isomorphic(g1, g3));
    ASSERT_FALSE(could_be_isomorphic(g1, g4));
    ASSERT_TRUE(could_be_isomorphic(g3, g2));
    ASSERT_FALSE(could_be_isomorphic(g1, g6));
}