#include "../../../generators/classic.hpp"
#include "../../../generators/lattice.hpp"
#include "../unweighted.hpp"
#include <gtest/gtest.h>
#include <vector>

void validate_grid_path(int r, int c, int s, int t, vector<int> p)
{
    ASSERT_EQ(p[0], s);
    ASSERT_EQ(p[p.size() - 1], t);
    int s0 = s / c;
    int s1 = s % c;
    int t0 = t / c;
    int t1 = t % c;
    ASSERT_EQ(p.size(), abs(t0 - s0) + abs(t1 - s1) + 1);
    vector<pair<int, int>> new_p;
    for (auto u : p)
        new_p.push_back(pair<int, int>(u / c, u % c));
    for (auto u : new_p) {
        ASSERT_LE(0, u.first);
        ASSERT_LT(u.first, r);
        ASSERT_LE(0, u.second);
        ASSERT_LT(u.second, c);
    }
    for (int i = 0; i < (int) p.size() - 1; ++i) {
        int v0 = abs(new_p[i].first - new_p[i + 1].first);
        int v1 = abs(new_p[i].second - new_p[i + 1].second);
        bool eval = (v0 == 0 && v1 == 1) || (v0 == 1 && v1 == 0);
        ASSERT_TRUE(eval);
    }
}

class TestUnweighted : public ::testing::Test {
protected:
    Graph grid;
    Graph cycle;
    DiGraph directed_cycle;

    void SetUp() override
    {
        grid = grid_2d_graph(4, 4);
        cycle = cycle_graph(7);
        directed_cycle = cycle_digraph(7);
    }
};

TEST_F(TestUnweighted, TestBidirectionalShortestPath)
{
    ASSERT_EQ(bidirectional_shortest_path(cycle, 0, 3), vector<int>({ 0, 1, 2, 3 }));
    ASSERT_EQ(bidirectional_shortest_path(cycle, 0, 4), vector<int>({ 0, 6, 5, 4 }));
    validate_grid_path(4, 4, 0, 11, bidirectional_shortest_path(grid, 0, 11));
    ASSERT_EQ(bidirectional_shortest_path_directed(directed_cycle, 0, 3), vector<int>({ 0, 1, 2, 3 }));
}

TEST_F(TestUnweighted, TestSingleSourceShortestPathLength)
{
    NodeDoubleDict expected({
        { 0, 0 },
        { 1, 1 },
        { 2, 2 },
        { 3, 3 },
        { 4, 3 },
        { 5, 2 },
        { 6, 1 },
    });
    NodeDoubleDict lengths = single_source_shortest_path_length(cycle, 0);
    ASSERT_EQ(expected, lengths);
    expected = NodeDoubleDict({
        { 0, 0 },
        { 1, 1 },
        { 2, 2 },
        { 3, 3 },
        { 4, 4 },
        { 5, 5 },
        { 6, 6 },
    });
    lengths = single_source_shortest_path_length_directed(directed_cycle, 0);
    ASSERT_EQ(expected, lengths);
}

TEST_F(TestUnweighted, TestSingleTargetShortestPathLength)
{
    NodeDoubleDict expected({
        { 0, 0 },
        { 1, 1 },
        { 2, 2 },
        { 3, 3 },
        { 4, 3 },
        { 5, 2 },
        { 6, 1 },
    });
    NodeDoubleDict lengths = single_target_shortest_path_length(cycle, 0);
    ASSERT_EQ(expected, lengths);
    expected = NodeDoubleDict({
        { 0, 0 },
        { 1, 6 },
        { 2, 5 },
        { 3, 4 },
        { 4, 3 },
        { 5, 2 },
        { 6, 1 },
    });
    lengths = single_target_shortest_path_length_directed(directed_cycle, 0);
    ASSERT_EQ(expected, lengths);
}

TEST_F(TestUnweighted, TestAllPairsShortestPathLength)
{
    NodeNodeDoubleDict all_pairs;
    NodeDoubleDict expected;
    all_pairs = all_pairs_shortest_path_length(cycle);
    expected = NodeDoubleDict({
        { 0, 0 },
        { 1, 1 },
        { 2, 2 },
        { 3, 3 },
        { 4, 3 },
        { 5, 2 },
        { 6, 1 },
    });
    ASSERT_EQ(all_pairs[0], expected);
    all_pairs = all_pairs_shortest_path_length(grid);
    ASSERT_EQ(all_pairs[0][15], 6);
}

TEST_F(TestUnweighted, TestSingleSourceShortestPath)
{
    Paths p;
    p = single_source_shortest_path_directed(directed_cycle, 3);
    ASSERT_EQ(p[0], vector<int>({ 3, 4, 5, 6, 0 }));
    p = single_source_shortest_path(cycle, 0);
    ASSERT_EQ(p[3], vector<int>({ 0, 1, 2, 3 }));
    p = single_source_shortest_path(cycle, 0, 0);
    ASSERT_EQ(p, Paths({ { 0, vector<int>({ 0 }) } }));
}

TEST_F(TestUnweighted, TestSingleTargetShortestPath)
{
    Paths p;
    p = single_target_shortest_path_directed(directed_cycle, 0);
    ASSERT_EQ(p[3], vector<int>({ 3, 4, 5, 6, 0 }));
    p = single_target_shortest_path(cycle, 0);
    ASSERT_EQ(p[3], vector<int>({ 3, 2, 1, 0 }));
    p = single_target_shortest_path(cycle, 0, 0);
    ASSERT_EQ(p, Paths({ { 0, vector<int>({ 0 }) } }));
}

TEST_F(TestUnweighted, TestAllPairsShortestPath)
{
    NodePaths p;
    p = all_pairs_shortest_path(cycle);
    ASSERT_EQ(p[0][3], vector<int>({ 0, 1, 2, 3 }));
    p = all_pairs_shortest_path(grid);
    validate_grid_path(4, 4, 0, 11, p[0][11]);
}

TEST_F(TestUnweighted, TestPredecessorPath)
{
    Graph g = path_graph(4);
    Paths p {
        { 0, vector<int>() },
        { 1, vector<int>({ 0 }) },
        { 2, vector<int>({ 1 }) },
        { 3, vector<int>({ 2 }) },
    };
    ASSERT_EQ(predecessor(g, 0), p);
    ASSERT_EQ(predecessor_with_target(g, 0, 3), vector<int>({ 2 }));
}

TEST_F(TestUnweighted, TestPredecessorCycle)
{
    Graph g = cycle_graph(4);
    auto pred = predecessor(g, 0);
    ASSERT_EQ(pred[0], vector<int>());
    ASSERT_EQ(pred[1], vector<int>({ 0 }));
    bool eval = (pred[2] == vector<int>({ 1, 3 }) || pred[2] == vector<int>({ 3, 1 }));
    ASSERT_TRUE(eval);
    ASSERT_EQ(pred[3], vector<int>({ 0 }));
}

TEST_F(TestUnweighted, TestPredecessorCutoff)
{
    Graph g = path_graph(4);
    bool eval = true;
    for (auto v : predecessor_with_target(g, 0, 3)) {
        if (v == 4)
            eval = false;
    }
    ASSERT_TRUE(eval);
}

TEST_F(TestUnweighted, TestPredecessorTarget)
{
    Graph g = path_graph(4);
    auto p = predecessor_with_target(g, 0, 3);
    ASSERT_EQ(p, vector<int>({ 2 }));
    p = predecessor_with_target(g, 0, 3, 2);
    ASSERT_EQ(p, vector<int>());
}
