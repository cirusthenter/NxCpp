#pragma once
#include <iomanip>
#include <random>
#include <vector>

double random_double(double f_min, double f_max)
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(f_min, f_max);

    return distr(eng);
}

std::vector<double> random_doubles(int n, double f_min = 0, double f_max = 1, bool has_seed = false, int seed = 0)
{
    // n: number of random doubles
    std::random_device rd;
    std::default_random_engine random_eng(rd());
    std::default_random_engine seed_eng(seed);
    std::uniform_real_distribution<double> distr(f_min, f_max);
    std::vector<double> v;
    for (int i = 0; i < n; ++i)
        if (has_seed)
            v.push_back(distr(seed_eng));
        else
            v.push_back(distr(random_eng));
    return v;
}