#pragma once
#include <iomanip>
#include <random>
#include <vector>

inline double random_double(double d_min, double d_max, bool has_seed, int seed);
inline std::vector<double> random_doubles(int n, double d_min, double d_max, bool has_seed, int seed);
template <typename T>
inline void shuffle_vector(std::vector<T>& v, bool has_seed, int seed);
