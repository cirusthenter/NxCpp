#include "../../../generators/random_graphs.hpp"
#include "../../../generators/social.hpp"
#include "../../../readwrite/read_file.hpp"
#include "../community_utils.hpp"
#include "../louvain.hpp"
#include <gtest/gtest.h>

class TestLouvain : public ::testing::Test {
};

// TEST_F(TestLouvain, TestModularityIncrease)
// {
//     Graph g = erdos_renyi_graph(1000, 0.09);
//     vector<unordered_set<int>> partition;
//     for (auto [nd, attr] : g.nodes()) {
//         partition.push_back(unordered_set<int>({ nd }));
//     }
//     double mod = modularity(g, partition);
//     partition = louvain_communities(g);

//     ASSERT_GT(modularity(g, partition), mod);
// }

// TEST_F(TestLouvain, TestValidPartition)
// {
//     Graph g = erdos_renyi_graph(1000, 0.09);
//     vector<unordered_set<int>> partition = louvain_communities(g);

//     ASSERT_TRUE(is_partition(g, partition));
// }

TEST_F(TestLouvain, TestPartition)
{
    vector<double> mods;
    Graph g = karate_club_graph();
    vector<unordered_set<int>> partition = louvain_communities(g, "weight", 1, .00000001, true, 0);

    ASSERT_TRUE(is_partition(g, partition));
}

TEST_F(TestLouvain, TestReadFile)
{
    Graph g = read_file("graph/com-amazon-connected.gr");
    vector<unordered_set<int>> partition = louvain_communities(g);
    cout << "modularity: " << modularity(g, partition) << endl;
}
