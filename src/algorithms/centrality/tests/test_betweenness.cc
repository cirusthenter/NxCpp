#include "../../../generators/classic.hpp"
#include "../../../generators/small.hpp"
#include "../../../generators/social.hpp"
#include "../betweenness.hpp"
#include <gtest/gtest.h>

bool equal_to_6th_place(double a, double b)
{
    // This has to be updated
    int x1 = (a * 1048576); // 1048576 = 2^20
    int x2 = (b * 1048576); // 1048576 = 2^20
    return x1 == x2;
}

class TestBetweennessCentrality : public ::testing::Test {
};

TEST_F(TestBetweennessCentrality, TestK5)
{
    Graph g = complete_graph(5);
    NodeDoubleDict b = betweenness_centrality(g, false);
    NodeDoubleDict expected {
        { 0, 0 },
        { 1, 0 },
        { 2, 0 },
        { 3, 0 },
        { 4, 0 },
    };
    ASSERT_EQ(b, expected);
}

TEST_F(TestBetweennessCentrality, TestP3Normalized)
{
    Graph g = path_graph(3);
    NodeDoubleDict b = betweenness_centrality(g, true);
    NodeDoubleDict expected {
        { 0, 0 },
        { 1, 1 },
        { 2, 0 },
    };
    ASSERT_EQ(b, expected);
}

TEST_F(TestBetweennessCentrality, TestP3)
{
    Graph g = path_graph(3);
    NodeDoubleDict b = betweenness_centrality(g, false);
    NodeDoubleDict expected {
        { 0, 0 },
        { 1, 1 },
        { 2, 0 },
    };
    ASSERT_EQ(b, expected);
}

TEST_F(TestBetweennessCentrality, TestKrackhardtKiteGraph)
{
    Graph g = krackhardt_kite_graph();
    NodeDoubleDict b = betweenness_centrality(g, false);
    NodeDoubleDict expected {
        { 0, (double)5 / 3 },
        { 1, (double)5 / 3 },
        { 2, 0 },
        { 3, (double)22 / 3 },
        { 4, 0 },
        { 5, (double)50 / 3 },
        { 6, (double)50 / 3 },
        { 7, 28 },
        { 8, 16 },
        { 9, 0 },
    };
    for (auto [n, bet] : b)
        expected[n] /= 2;
    for (auto [n, val] : b)
        ASSERT_TRUE(equal_to_4th_place(expected[n], val));
}

TEST_F(TestBetweennessCentrality, TestKrackhardtKiteGraphNormalized)
{
    Graph g = krackhardt_kite_graph();
    NodeDoubleDict b = betweenness_centrality(g, true);
    NodeDoubleDict expected {
        { 0, (double)5 / 216 },
        { 1, (double)5 / 216 },
        { 2, 0 },
        { 3, (double)22 / 216 },
        { 4, 0 },
        { 5, (double)50 / 216 },
        { 6, (double)50 / 216 },
        { 7, (double)28 / 72 },
        { 8, (double)16 / 72 },
        { 9, 0 },
    };
    for (auto [n, val] : b)
        ASSERT_TRUE(equal_to_4th_place(expected[n], val));
}

TEST_F(TestBetweennessCentrality, TestLesMiserablesGraphNormalized)
{
    Graph g = les_miserables_graph();
    NodeDoubleDict b = betweenness_centrality(g, true);
    unordered_map<string, double> b_answer = {
        { "Napoleon", 0.0 },
        { "Myriel", 0.17684210526315788 },
        { "MlleBaptistine", 0.0 },
        { "MmeMagloire", 0.0 },
        { "CountessDeLo", 0.0 },
        { "Geborand", 0.0 },
        { "Champtercier", 0.0 },
        { "Cravatte", 0.0 },
        { "Count", 0.0 },
        { "OldMan", 0.0 },
        { "Valjean", 0.5699890527836184 },
        { "Labarre", 0.0 },
        { "Marguerite", 0.0 },
        { "MmeDeR", 0.0 },
        { "Isabeau", 0.0 },
        { "Gervais", 0.0 },
        { "Listolier", 0.0 },
        { "Tholomyes", 0.04062934817733579 },
        { "Fameuil", 0.0 },
        { "Blacheville", 0.0 },
        { "Favourite", 0.0 },
        { "Dahlia", 0.0 },
        { "Zephine", 0.0 },
        { "Fantine", 0.12964454098819422 },
        { "MmeThenardier", 0.02900241873046176 },
        { "Thenardier", 0.07490122123424225 },
        { "Cosette", 0.023796253454148188 },
        { "Javert", 0.05433155966478436 },
        { "Fauchelevent", 0.026491228070175437 },
        { "Bamatabois", 0.008040935672514621 },
        { "Perpetue", 0.0 },
        { "Simplice", 0.008640295033483888 },
        { "Scaufflaire", 0.0 },
        { "Woman1", 0.0 },
        { "Judge", 0.0 },
        { "Champmathieu", 0.0 },
        { "Brevet", 0.0 },
        { "Chenildieu", 0.0 },
        { "Cochepaille", 0.0 },
        { "Pontmercy", 0.006925438596491228 },
        { "Boulatruelle", 0.0 },
        { "Eponine", 0.011487550654163002 },
        { "Anzelma", 0.0 },
        { "Woman2", 0.0 },
        { "MotherInnocent", 0.0 },
        { "Gribier", 0.0 },
        { "MmeBurgon", 0.02631578947368421 },
        { "Jondrette", 0.0 },
        { "Gavroche", 0.16511250242584766 },
        { "Gillenormand", 0.02021062158319776 },
        { "Magnon", 0.00021720969089390142 },
        { "MlleGillenormand", 0.047598927875243675 },
        { "MmePontmercy", 0.0003508771929824561 },
        { "MlleVaubois", 0.0 },
        { "LtGillenormand", 0.0 },
        { "Marius", 0.132032488621946 },
        { "BaronessT", 0.0 },
        { "Mabeuf", 0.027661236424394314 },
        { "Enjolras", 0.0425533568221771 },
        { "Combeferre", 0.0012501455659350393 },
        { "Prouvaire", 0.0 },
        { "Feuilly", 0.0012501455659350393 },
        { "Courfeyrac", 0.00526702988198833 },
        { "Bahorel", 0.0021854883087570067 },
        { "Bossuet", 0.03075365017995782 },
        { "Joly", 0.0021854883087570067 },
        { "Grantaire", 0.00015037593984962405 },
        { "MotherPlutarch", 0.0 },
        { "Gueulemer", 0.004960383978389518 },
        { "Babet", 0.004960383978389518 },
        { "Claquesous", 0.00486180419559921 },
        { "Montparnasse", 0.0038738298738298727 },
        { "Toussaint", 0.0 },
        { "Child1", 0.0 },
        { "Child2", 0.0 },
        { "Brujon", 0.00043859649122807013 },
        { "MmeHucheloup", 0.0 },
    };
    auto nodes = g.nodes();
    for (auto [n, val] : b) {
        string name = nodes[n].begin()->first;
        ASSERT_TRUE(equal_to_4th_place(b_answer[name], val));
    }
}

TEST_F(TestBetweennessCentrality, TestLesMiserablesGraph)
{
    Graph g = les_miserables_graph();
    NodeDoubleDict b = betweenness_centrality(g, false);
    unordered_map<string, double> b_answer = {
        { "Napoleon", 0.0 },
        { "Myriel", 504.0 },
        { "MlleBaptistine", 0.0 },
        { "MmeMagloire", 0.0 },
        { "CountessDeLo", 0.0 },
        { "Geborand", 0.0 },
        { "Champtercier", 0.0 },
        { "Cravatte", 0.0 },
        { "Count", 0.0 },
        { "OldMan", 0.0 },
        { "Valjean", 1624.4688004333127 },
        { "Labarre", 0.0 },
        { "Marguerite", 0.0 },
        { "MmeDeR", 0.0 },
        { "Isabeau", 0.0 },
        { "Gervais", 0.0 },
        { "Listolier", 0.0 },
        { "Tholomyes", 115.793642305407 },
        { "Fameuil", 0.0 },
        { "Blacheville", 0.0 },
        { "Favourite", 0.0 },
        { "Dahlia", 0.0 },
        { "Zephine", 0.0 },
        { "Fantine", 369.4869418163536 },
        { "MmeThenardier", 82.65689338181602 },
        { "Thenardier", 213.46848051759042 },
        { "Cosette", 67.81932234432234 },
        { "Javert", 154.84494504463544 },
        { "Fauchelevent", 75.5 },
        { "Bamatabois", 22.91666666666667 },
        { "Perpetue", 0.0 },
        { "Simplice", 24.624840845429084 },
        { "Scaufflaire", 0.0 },
        { "Woman1", 0.0 },
        { "Judge", 0.0 },
        { "Champmathieu", 0.0 },
        { "Brevet", 0.0 },
        { "Chenildieu", 0.0 },
        { "Cochepaille", 0.0 },
        { "Pontmercy", 19.7375 },
        { "Boulatruelle", 0.0 },
        { "Eponine", 32.73951936436456 },
        { "Anzelma", 0.0 },
        { "Woman2", 0.0 },
        { "MotherInnocent", 0.0 },
        { "Gribier", 0.0 },
        { "MmeBurgon", 75.0 },
        { "Jondrette", 0.0 },
        { "Gavroche", 470.57063191366586 },
        { "Gillenormand", 57.600271512113615 },
        { "Magnon", 0.6190476190476191 },
        { "MlleGillenormand", 135.6569444444445 },
        { "MmePontmercy", 1.0 },
        { "MlleVaubois", 0.0 },
        { "LtGillenormand", 0.0 },
        { "Marius", 376.2925925725461 },
        { "BaronessT", 0.0 },
        { "Mabeuf", 78.8345238095238 },
        { "Enjolras", 121.27706694320474 },
        { "Combeferre", 3.5629148629148624 },
        { "Prouvaire", 0.0 },
        { "Feuilly", 3.5629148629148624 },
        { "Courfeyrac", 15.011035163666742 },
        { "Bahorel", 6.2286416799574695 },
        { "Bossuet", 87.6479030128798 },
        { "Joly", 6.2286416799574695 },
        { "Grantaire", 0.42857142857142855 },
        { "MotherPlutarch", 0.0 },
        { "Gueulemer", 14.137094338410128 },
        { "Babet", 14.137094338410128 },
        { "Claquesous", 13.85614195745775 },
        { "Montparnasse", 11.040415140415138 },
        { "Toussaint", 0.0 },
        { "Child1", 0.0 },
        { "Child2", 0.0 },
        { "Brujon", 1.25 },
        { "MmeHucheloup", 0.0 },
    };
    auto nodes = g.nodes();
    for (auto [n, val] : b) {
        string name = nodes[n].begin()->first;
        ASSERT_TRUE(equal_to_4th_place(b_answer[name], val));
    }
}