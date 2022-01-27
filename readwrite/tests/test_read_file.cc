#include "../../generators/social.hpp"
#include "../read_file.hpp"
#include <gtest/gtest.h>

class TestReadFile : public ::testing::Test {
};

// Testing with a text file in Bazel is difficult
// Try later
// TEST_F(TestReadFile, TestReadUndirected)
// {
//     string path = "graphs/karate_club.gr";
//     Graph g = read_undirected_file(path);
//     Graph karate = karate_club_graph();

//     ASSERT_EQ(g.nodes(), karate.nodes());
//     ASSERT_EQ(g.edges(), karate.edges());
// }
