#include "../../generators/classic.hpp"
#include "../../generators/small.hpp"
#include "../cluster.hpp"
#include <gtest/gtest.h>

class TestTriangles : public ::testing::Test {
};

TEST_F(TestTriangles, TestEmpty)
{
    Graph g = Graph();
    ASSERT_EQ(triangles(g), NodeInt());
}

TEST_F(TestTriangles, TestPath)
{
    Graph g = path_graph(10);
    ASSERT_EQ(triangles(g), NodeInt({ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 } }));
}

TEST_F(TestTriangles, TestCubical)
{
    Graph g = cubical_graph();
    ASSERT_EQ(triangles(g), NodeInt({ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 } }));
}

TEST_F(TestTriangles, TestK5)
{
    Graph g = complete_graph(5);
    ASSERT_EQ(triangles(g), NodeInt({ { 0, 6 }, { 1, 6 }, { 2, 6 }, { 3, 6 }, { 4, 6 } }));
}
