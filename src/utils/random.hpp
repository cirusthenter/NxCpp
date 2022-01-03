#pragma once
#include "random.h"

double random_double(double d_min, double d_max, bool has_seed = false, int seed = 0)
{
    std::random_device rd;
    std::default_random_engine random_eng(rd());
    std::default_random_engine seed_eng(seed);
    std::uniform_real_distribution<double> distr(d_min, d_max);

    if (has_seed)
        return distr(seed_eng);
    return distr(random_eng);
}

std::vector<double> random_doubles(int n, double d_min = 0, double d_max = 1, bool has_seed = false, int seed = 0)
{
    // n: number of random doubles
    // differs on different machines
    std::random_device rd;
    std::default_random_engine random_eng(rd());
    std::default_random_engine seed_eng(seed);
    std::uniform_real_distribution<double> distr(d_min, d_max);
    std::vector<double> v;
    for (int i = 0; i < n; ++i)
        if (has_seed)
            v.push_back(distr(seed_eng));
        else
            v.push_back(distr(random_eng));
    return v;
}
