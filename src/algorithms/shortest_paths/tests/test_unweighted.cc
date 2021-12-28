#include "../../../generators/classic.h"
#include "../../../generators/lattice.h"
#include "../unweighted.h"
#include <gtest/gtest.h>

class TestGraph : public ::testing::Test {
protected:
    Graph grid;
    Graph cycle;
    Graph directed_cycle;

    void SetUp() override
    {
        grid = grid_2d_graph(4, 4);
        cycle = cycle_graph(7);
        directed_cycle = cycle_digraph(7);
    }
};

TEST_F(TestGraph, TestSingleSourceShortestPathLength)
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
}