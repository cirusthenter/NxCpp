#include "../../../generators/classic.hpp"
#include "../../../generators/random_graphs.hpp"
#include "../../../utils/approx.hpp"
#include "../quality.hpp"
#include <gtest/gtest.h>

class TestQuality : public ::testing::Test {
};

TEST_F(TestQuality, TestModularity)
{
    Graph g;
    vector<unordered_set<int>> c;

    g = barbell_graph(3, 0);
    c = vector<unordered_set<int>>({ unordered_set<int>({ 0, 1, 4 }), unordered_set<int>({ 2, 3, 5 }) });
    ASSERT_TRUE(equal_to_6th_place(modularity(g, c), (double)-16 / (14 * 14)));

    c = vector<unordered_set<int>>({ unordered_set<int>({ 0, 1, 2 }), unordered_set<int>({ 3, 4, 5 }) });
    ASSERT_TRUE(equal_to_6th_place(modularity(g, c), (double)35 * 2 / (14 * 14)));

    int n = 1000;
    g = erdos_renyi_graph(n, 0.09, true, 1);
    unordered_set<int> left, right;
    for (int i = 0; i < n / 2; ++i)
        left.insert(i);
    for (int i = n / 2; i < n; ++i)
        right.insert(i);
    c = vector<unordered_set<int>>({ left, right });
    ASSERT_DOUBLE_EQ(modularity(g, c), 0.0017752096344457458);
}
