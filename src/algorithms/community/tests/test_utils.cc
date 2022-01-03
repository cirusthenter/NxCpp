#include "../../../generators/classic.hpp"
#include "../community_utils.hpp"
#include <gtest/gtest.h>

class TestUtils : public ::testing::Test {
};

TEST_F(TestUtils, TestIsPartition)
{
    Graph g = empty_graph(3);
    ASSERT_TRUE(is_partition(g, vector<unordered_set<int>>({ unordered_set<int>({ 0, 1 }), unordered_set<int>({ 2 }) })));
    ASSERT_FALSE(is_partition(g, vector<unordered_set<int>>({ unordered_set<int>({ 0, 1 }), unordered_set<int>({ 4 }) })));
    ASSERT_FALSE(is_partition(g, vector<unordered_set<int>>({ unordered_set<int>({ 0, 1 }), unordered_set<int>({ 1, 2 }) })));
    ASSERT_FALSE(is_partition(g, vector<unordered_set<int>>({ unordered_set<int>({ 1 }), unordered_set<int>({ 2 }) })));
}