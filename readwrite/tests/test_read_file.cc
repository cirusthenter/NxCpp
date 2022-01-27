#include "../../generators/social.hpp"
#include "../../algorithms/isomorphism/isomorph.hpp"
#include "../read_file.hpp"
#include <gtest/gtest.h>

class TestReadFile : public ::testing::Test {
};

TEST_F(TestReadFile, TestReadUndirected)
{
    string path = "graph/karate_club.gr";
    Graph g = read_undirected_file(path);
    Graph karate = karate_club_graph();

    ASSERT_EQ(g.nodes(), karate.nodes());
    ASSERT_EQ(g.edges(), karate.edges());
}
