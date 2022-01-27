#pragma once
#include "small.h"

Graph karate_club_graph()
{
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(0, 4);
    g.add_edge(0, 5);
    g.add_edge(0, 6);
    g.add_edge(0, 7);
    g.add_edge(0, 8);
    g.add_edge(0, 10);
    g.add_edge(0, 11);
    g.add_edge(0, 12);
    g.add_edge(0, 13);
    g.add_edge(0, 17);
    g.add_edge(0, 19);
    g.add_edge(0, 21);
    g.add_edge(0, 31);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 7);
    g.add_edge(1, 13);
    g.add_edge(1, 17);
    g.add_edge(1, 19);
    g.add_edge(1, 21);
    g.add_edge(1, 30);
    g.add_edge(2, 3);
    g.add_edge(2, 7);
    g.add_edge(2, 8);
    g.add_edge(2, 9);
    g.add_edge(2, 13);
    g.add_edge(2, 27);
    g.add_edge(2, 28);
    g.add_edge(2, 32);
    g.add_edge(3, 7);
    g.add_edge(3, 12);
    g.add_edge(3, 13);
    g.add_edge(4, 6);
    g.add_edge(4, 10);
    g.add_edge(5, 6);
    g.add_edge(5, 10);
    g.add_edge(5, 16);
    g.add_edge(6, 16);
    g.add_edge(8, 30);
    g.add_edge(8, 32);
    g.add_edge(8, 33);
    g.add_edge(9, 33);
    g.add_edge(13, 33);
    g.add_edge(14, 32);
    g.add_edge(14, 33);
    g.add_edge(15, 32);
    g.add_edge(15, 33);
    g.add_edge(18, 32);
    g.add_edge(18, 33);
    g.add_edge(19, 33);
    g.add_edge(20, 32);
    g.add_edge(20, 33);
    g.add_edge(22, 32);
    g.add_edge(22, 33);
    g.add_edge(23, 25);
    g.add_edge(23, 27);
    g.add_edge(23, 29);
    g.add_edge(23, 32);
    g.add_edge(23, 33);
    g.add_edge(24, 25);
    g.add_edge(24, 27);
    g.add_edge(24, 31);
    g.add_edge(25, 31);
    g.add_edge(26, 29);
    g.add_edge(26, 33);
    g.add_edge(27, 33);
    g.add_edge(28, 31);
    g.add_edge(28, 33);
    g.add_edge(29, 32);
    g.add_edge(29, 33);
    g.add_edge(30, 32);
    g.add_edge(30, 33);
    g.add_edge(31, 32);
    g.add_edge(31, 33);
    g.add_edge(32, 33);
    return g;
}

Graph les_miserables_graph()
{
    Graph g;
    unordered_map<int, string> id_to_name {
        { 0, "Bamatabois" },
        { 1, "Cosette" },
        { 2, "Tholomyes" },
        { 3, "Magnon" },
        { 4, "LtGillenormand" },
        { 5, "Grantaire" },
        { 6, "Chenildieu" },
        { 7, "Child2" },
        { 8, "Joly" },
        { 9, "MmeBurgon" },
        { 10, "Prouvaire" },
        { 11, "Blacheville" },
        { 12, "Fauchelevent" },
        { 13, "Zephine" },
        { 14, "Fameuil" },
        { 15, "Mabeuf" },
        { 16, "Combeferre" },
        { 17, "Anzelma" },
        { 18, "Cravatte" },
        { 19, "Marius" },
        { 20, "Babet" },
        { 21, "MmePontmercy" },
        { 22, "Thenardier" },
        { 23, "Champmathieu" },
        { 24, "Cochepaille" },
        { 25, "Woman1" },
        { 26, "MmeHucheloup" },
        { 27, "Fantine" },
        { 28, "MmeDeR" },
        { 29, "Myriel" },
        { 30, "Champtercier" },
        { 31, "MotherInnocent" },
        { 32, "Woman2" },
        { 33, "Judge" },
        { 34, "Eponine" },
        { 35, "MmeThenardier" },
        { 36, "Gueulemer" },
        { 37, "Boulatruelle" },
        { 38, "Brevet" },
        { 39, "Jondrette" },
        { 40, "Simplice" },
        { 41, "Child1" },
        { 42, "Labarre" },
        { 43, "Isabeau" },
        { 44, "Marguerite" },
        { 45, "Enjolras" },
        { 46, "Javert" },
        { 47, "Bahorel" },
        { 48, "BaronessT" },
        { 49, "Napoleon" },
        { 50, "Dahlia" },
        { 51, "MotherPlutarch" },
        { 52, "Pontmercy" },
        { 53, "Count" },
        { 54, "Feuilly" },
        { 55, "Courfeyrac" },
        { 56, "MlleBaptistine" },
        { 57, "Geborand" },
        { 58, "OldMan" },
        { 59, "Favourite" },
        { 60, "MlleGillenormand" },
        { 61, "Toussaint" },
        { 62, "Perpetue" },
        { 63, "Valjean" },
        { 64, "Scaufflaire" },
        { 65, "MlleVaubois" },
        { 66, "Listolier" },
        { 67, "Gavroche" },
        { 68, "Gervais" },
        { 69, "Gribier" },
        { 70, "Claquesous" },
        { 71, "CountessDeLo" },
        { 72, "Gillenormand" },
        { 73, "Bossuet" },
        { 74, "Brujon" },
        { 75, "Montparnasse" },
        { 76, "MmeMagloire" },
    };
    unordered_map<string, int> name_to_id;
    for (auto [n, name] : id_to_name) {
        name_to_id[name] = n;
        g.add_node(n, AttrDict({ { name, 0 } }));
    }
    g.add_edge(name_to_id["Napoleon"], name_to_id["Myriel"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MlleBaptistine"], name_to_id["Myriel"], AttrDict({ { "weight", 8 } }));
    g.add_edge(name_to_id["MmeMagloire"], name_to_id["Myriel"], AttrDict({ { "weight", 10 } }));
    g.add_edge(name_to_id["MmeMagloire"], name_to_id["MlleBaptistine"], AttrDict({ { "weight", 6 } }));
    g.add_edge(name_to_id["CountessDeLo"], name_to_id["Myriel"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Geborand"], name_to_id["Myriel"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Champtercier"], name_to_id["Myriel"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Cravatte"], name_to_id["Myriel"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Count"], name_to_id["Myriel"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["OldMan"], name_to_id["Myriel"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Valjean"], name_to_id["Labarre"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Valjean"], name_to_id["MmeMagloire"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Valjean"], name_to_id["MlleBaptistine"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Valjean"], name_to_id["Myriel"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Marguerite"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MmeDeR"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Isabeau"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Gervais"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Listolier"], name_to_id["Tholomyes"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Fameuil"], name_to_id["Tholomyes"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Fameuil"], name_to_id["Listolier"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Blacheville"], name_to_id["Tholomyes"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Blacheville"], name_to_id["Listolier"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Blacheville"], name_to_id["Fameuil"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Favourite"], name_to_id["Tholomyes"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Favourite"], name_to_id["Listolier"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Favourite"], name_to_id["Fameuil"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Favourite"], name_to_id["Blacheville"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Dahlia"], name_to_id["Tholomyes"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Dahlia"], name_to_id["Listolier"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Dahlia"], name_to_id["Fameuil"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Dahlia"], name_to_id["Blacheville"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Dahlia"], name_to_id["Favourite"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Zephine"], name_to_id["Tholomyes"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Zephine"], name_to_id["Listolier"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Zephine"], name_to_id["Fameuil"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Zephine"], name_to_id["Blacheville"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Zephine"], name_to_id["Favourite"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Zephine"], name_to_id["Dahlia"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Fantine"], name_to_id["Tholomyes"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Fantine"], name_to_id["Listolier"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Fantine"], name_to_id["Fameuil"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Fantine"], name_to_id["Blacheville"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Fantine"], name_to_id["Favourite"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Fantine"], name_to_id["Dahlia"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Fantine"], name_to_id["Zephine"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Fantine"], name_to_id["Marguerite"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Fantine"], name_to_id["Valjean"], AttrDict({ { "weight", 9 } }));
    g.add_edge(name_to_id["MmeThenardier"], name_to_id["Fantine"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["MmeThenardier"], name_to_id["Valjean"], AttrDict({ { "weight", 7 } }));
    g.add_edge(name_to_id["Thenardier"], name_to_id["MmeThenardier"], AttrDict({ { "weight", 13 } }));
    g.add_edge(name_to_id["Thenardier"], name_to_id["Fantine"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Thenardier"], name_to_id["Valjean"], AttrDict({ { "weight", 12 } }));
    g.add_edge(name_to_id["Cosette"], name_to_id["MmeThenardier"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Cosette"], name_to_id["Valjean"], AttrDict({ { "weight", 31 } }));
    g.add_edge(name_to_id["Cosette"], name_to_id["Tholomyes"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Cosette"], name_to_id["Thenardier"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Javert"], name_to_id["Valjean"], AttrDict({ { "weight", 17 } }));
    g.add_edge(name_to_id["Javert"], name_to_id["Fantine"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Javert"], name_to_id["Thenardier"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Javert"], name_to_id["MmeThenardier"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Javert"], name_to_id["Cosette"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Fauchelevent"], name_to_id["Valjean"], AttrDict({ { "weight", 8 } }));
    g.add_edge(name_to_id["Fauchelevent"], name_to_id["Javert"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Bamatabois"], name_to_id["Fantine"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Bamatabois"], name_to_id["Javert"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Bamatabois"], name_to_id["Valjean"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Perpetue"], name_to_id["Fantine"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Simplice"], name_to_id["Perpetue"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Simplice"], name_to_id["Valjean"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Simplice"], name_to_id["Fantine"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Simplice"], name_to_id["Javert"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Scaufflaire"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Woman1"], name_to_id["Valjean"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Woman1"], name_to_id["Javert"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Judge"], name_to_id["Valjean"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Judge"], name_to_id["Bamatabois"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Champmathieu"], name_to_id["Valjean"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Champmathieu"], name_to_id["Judge"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Champmathieu"], name_to_id["Bamatabois"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Brevet"], name_to_id["Judge"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Brevet"], name_to_id["Champmathieu"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Brevet"], name_to_id["Valjean"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Brevet"], name_to_id["Bamatabois"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Chenildieu"], name_to_id["Judge"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Chenildieu"], name_to_id["Champmathieu"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Chenildieu"], name_to_id["Brevet"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Chenildieu"], name_to_id["Valjean"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Chenildieu"], name_to_id["Bamatabois"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Cochepaille"], name_to_id["Judge"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Cochepaille"], name_to_id["Champmathieu"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Cochepaille"], name_to_id["Brevet"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Cochepaille"], name_to_id["Chenildieu"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Cochepaille"], name_to_id["Valjean"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Cochepaille"], name_to_id["Bamatabois"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Pontmercy"], name_to_id["Thenardier"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Boulatruelle"], name_to_id["Thenardier"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Eponine"], name_to_id["MmeThenardier"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Eponine"], name_to_id["Thenardier"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Anzelma"], name_to_id["Eponine"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Anzelma"], name_to_id["Thenardier"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Anzelma"], name_to_id["MmeThenardier"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Woman2"], name_to_id["Valjean"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Woman2"], name_to_id["Cosette"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Woman2"], name_to_id["Javert"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MotherInnocent"], name_to_id["Fauchelevent"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["MotherInnocent"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Gribier"], name_to_id["Fauchelevent"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["MmeBurgon"], name_to_id["Jondrette"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Gavroche"], name_to_id["MmeBurgon"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Gavroche"], name_to_id["Thenardier"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Gavroche"], name_to_id["Javert"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Gavroche"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Gillenormand"], name_to_id["Cosette"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Gillenormand"], name_to_id["Valjean"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Magnon"], name_to_id["Gillenormand"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Magnon"], name_to_id["MmeThenardier"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MlleGillenormand"], name_to_id["Gillenormand"], AttrDict({ { "weight", 9 } }));
    g.add_edge(name_to_id["MlleGillenormand"], name_to_id["Cosette"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["MlleGillenormand"], name_to_id["Valjean"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["MmePontmercy"], name_to_id["MlleGillenormand"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MmePontmercy"], name_to_id["Pontmercy"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MlleVaubois"], name_to_id["MlleGillenormand"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["LtGillenormand"], name_to_id["MlleGillenormand"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["LtGillenormand"], name_to_id["Gillenormand"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["LtGillenormand"], name_to_id["Cosette"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Marius"], name_to_id["MlleGillenormand"], AttrDict({ { "weight", 6 } }));
    g.add_edge(name_to_id["Marius"], name_to_id["Gillenormand"], AttrDict({ { "weight", 12 } }));
    g.add_edge(name_to_id["Marius"], name_to_id["Pontmercy"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Marius"], name_to_id["LtGillenormand"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Marius"], name_to_id["Cosette"], AttrDict({ { "weight", 21 } }));
    g.add_edge(name_to_id["Marius"], name_to_id["Valjean"], AttrDict({ { "weight", 19 } }));
    g.add_edge(name_to_id["Marius"], name_to_id["Tholomyes"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Marius"], name_to_id["Thenardier"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Marius"], name_to_id["Eponine"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Marius"], name_to_id["Gavroche"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["BaronessT"], name_to_id["Gillenormand"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["BaronessT"], name_to_id["Marius"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Mabeuf"], name_to_id["Marius"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Mabeuf"], name_to_id["Eponine"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Mabeuf"], name_to_id["Gavroche"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Enjolras"], name_to_id["Marius"], AttrDict({ { "weight", 7 } }));
    g.add_edge(name_to_id["Enjolras"], name_to_id["Gavroche"], AttrDict({ { "weight", 7 } }));
    g.add_edge(name_to_id["Enjolras"], name_to_id["Javert"], AttrDict({ { "weight", 6 } }));
    g.add_edge(name_to_id["Enjolras"], name_to_id["Mabeuf"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Enjolras"], name_to_id["Valjean"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Combeferre"], name_to_id["Enjolras"], AttrDict({ { "weight", 15 } }));
    g.add_edge(name_to_id["Combeferre"], name_to_id["Marius"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Combeferre"], name_to_id["Gavroche"], AttrDict({ { "weight", 6 } }));
    g.add_edge(name_to_id["Combeferre"], name_to_id["Mabeuf"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Prouvaire"], name_to_id["Gavroche"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Prouvaire"], name_to_id["Enjolras"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Prouvaire"], name_to_id["Combeferre"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Feuilly"], name_to_id["Gavroche"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Feuilly"], name_to_id["Enjolras"], AttrDict({ { "weight", 6 } }));
    g.add_edge(name_to_id["Feuilly"], name_to_id["Prouvaire"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Feuilly"], name_to_id["Combeferre"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Feuilly"], name_to_id["Mabeuf"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Feuilly"], name_to_id["Marius"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Courfeyrac"], name_to_id["Marius"], AttrDict({ { "weight", 9 } }));
    g.add_edge(name_to_id["Courfeyrac"], name_to_id["Enjolras"], AttrDict({ { "weight", 17 } }));
    g.add_edge(name_to_id["Courfeyrac"], name_to_id["Combeferre"], AttrDict({ { "weight", 13 } }));
    g.add_edge(name_to_id["Courfeyrac"], name_to_id["Gavroche"], AttrDict({ { "weight", 7 } }));
    g.add_edge(name_to_id["Courfeyrac"], name_to_id["Mabeuf"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Courfeyrac"], name_to_id["Eponine"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Courfeyrac"], name_to_id["Feuilly"], AttrDict({ { "weight", 6 } }));
    g.add_edge(name_to_id["Courfeyrac"], name_to_id["Prouvaire"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Bahorel"], name_to_id["Combeferre"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Bahorel"], name_to_id["Gavroche"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Bahorel"], name_to_id["Courfeyrac"], AttrDict({ { "weight", 6 } }));
    g.add_edge(name_to_id["Bahorel"], name_to_id["Mabeuf"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Bahorel"], name_to_id["Enjolras"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Bahorel"], name_to_id["Feuilly"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Bahorel"], name_to_id["Prouvaire"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Bahorel"], name_to_id["Marius"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Bossuet"], name_to_id["Marius"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Bossuet"], name_to_id["Courfeyrac"], AttrDict({ { "weight", 12 } }));
    g.add_edge(name_to_id["Bossuet"], name_to_id["Gavroche"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Bossuet"], name_to_id["Bahorel"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Bossuet"], name_to_id["Enjolras"], AttrDict({ { "weight", 10 } }));
    g.add_edge(name_to_id["Bossuet"], name_to_id["Feuilly"], AttrDict({ { "weight", 6 } }));
    g.add_edge(name_to_id["Bossuet"], name_to_id["Prouvaire"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Bossuet"], name_to_id["Combeferre"], AttrDict({ { "weight", 9 } }));
    g.add_edge(name_to_id["Bossuet"], name_to_id["Mabeuf"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Bossuet"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Joly"], name_to_id["Bahorel"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Joly"], name_to_id["Bossuet"], AttrDict({ { "weight", 7 } }));
    g.add_edge(name_to_id["Joly"], name_to_id["Gavroche"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Joly"], name_to_id["Courfeyrac"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Joly"], name_to_id["Enjolras"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Joly"], name_to_id["Feuilly"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Joly"], name_to_id["Prouvaire"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Joly"], name_to_id["Combeferre"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Joly"], name_to_id["Mabeuf"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Joly"], name_to_id["Marius"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Grantaire"], name_to_id["Bossuet"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Grantaire"], name_to_id["Enjolras"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Grantaire"], name_to_id["Combeferre"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Grantaire"], name_to_id["Courfeyrac"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Grantaire"], name_to_id["Joly"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Grantaire"], name_to_id["Gavroche"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Grantaire"], name_to_id["Bahorel"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Grantaire"], name_to_id["Feuilly"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Grantaire"], name_to_id["Prouvaire"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MotherPlutarch"], name_to_id["Mabeuf"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Gueulemer"], name_to_id["Thenardier"], AttrDict({ { "weight", 5 } }));
    g.add_edge(name_to_id["Gueulemer"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Gueulemer"], name_to_id["MmeThenardier"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Gueulemer"], name_to_id["Javert"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Gueulemer"], name_to_id["Gavroche"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Gueulemer"], name_to_id["Eponine"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Babet"], name_to_id["Thenardier"], AttrDict({ { "weight", 6 } }));
    g.add_edge(name_to_id["Babet"], name_to_id["Gueulemer"], AttrDict({ { "weight", 6 } }));
    g.add_edge(name_to_id["Babet"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Babet"], name_to_id["MmeThenardier"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Babet"], name_to_id["Javert"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Babet"], name_to_id["Gavroche"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Babet"], name_to_id["Eponine"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Claquesous"], name_to_id["Thenardier"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Claquesous"], name_to_id["Babet"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Claquesous"], name_to_id["Gueulemer"], AttrDict({ { "weight", 4 } }));
    g.add_edge(name_to_id["Claquesous"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Claquesous"], name_to_id["MmeThenardier"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Claquesous"], name_to_id["Javert"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Claquesous"], name_to_id["Eponine"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Claquesous"], name_to_id["Enjolras"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Montparnasse"], name_to_id["Javert"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Montparnasse"], name_to_id["Babet"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Montparnasse"], name_to_id["Gueulemer"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Montparnasse"], name_to_id["Claquesous"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Montparnasse"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Montparnasse"], name_to_id["Gavroche"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Montparnasse"], name_to_id["Eponine"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Montparnasse"], name_to_id["Thenardier"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Toussaint"], name_to_id["Cosette"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Toussaint"], name_to_id["Javert"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Toussaint"], name_to_id["Valjean"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Child1"], name_to_id["Gavroche"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Child2"], name_to_id["Gavroche"], AttrDict({ { "weight", 2 } }));
    g.add_edge(name_to_id["Child2"], name_to_id["Child1"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Brujon"], name_to_id["Babet"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Brujon"], name_to_id["Gueulemer"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Brujon"], name_to_id["Thenardier"], AttrDict({ { "weight", 3 } }));
    g.add_edge(name_to_id["Brujon"], name_to_id["Gavroche"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Brujon"], name_to_id["Eponine"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Brujon"], name_to_id["Claquesous"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["Brujon"], name_to_id["Montparnasse"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MmeHucheloup"], name_to_id["Bossuet"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MmeHucheloup"], name_to_id["Joly"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MmeHucheloup"], name_to_id["Grantaire"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MmeHucheloup"], name_to_id["Bahorel"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MmeHucheloup"], name_to_id["Courfeyrac"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MmeHucheloup"], name_to_id["Gavroche"], AttrDict({ { "weight", 1 } }));
    g.add_edge(name_to_id["MmeHucheloup"], name_to_id["Enjolras"], AttrDict({ { "weight", 1 } }));
    return g;
}
