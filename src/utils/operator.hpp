#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    if (v.size() <= 0)
        return os << "[]";
    auto it = v.begin();
    os << "[";
    os << *(it++);
    while (it != v.end()) {
        os << ", " << *it;
        ++it;
    }
    os << "]";
    return os;
}

template <typename K, typename V>
void update_map(std::unordered_map<K, V>& m,
    std::unordered_map<K, V> l)
{
    for (const auto& p : l)
        m[p.first] = p.second;
}

template <typename V>
std::vector<V> convert_set_to_vector(std::unordered_set<V> s)
{
    std::vector<V> vec;
    for (auto v : s)
        vec.push_back(v);
    return vec;
}

template <typename K, typename V>
std::unordered_set<K> convert_map_to_set(std::unordered_map<K, V> m)
{
    std::unordered_set<K> s;
    for (auto [k, v] : m)
        s.insert(k);
    return s;
}

template <typename K1, typename K2, typename V>
std::unordered_map<K1, unordered_set<K2>> convert_mapmap_to_mapset(std::unordered_map<K1, std::unordered_map<K2, V>> m)
{
    std::unordered_map<K1, unordered_set<K2>> s;
    for (auto [k1, k2_v] : m) {
        s[k1] = unordered_set<K2>();
        for (auto [k2, v] : k2_v) {
            s[k1].insert(k2);
        }
    }
    return s;
}

template <typename K>
std::unordered_set<K> intersection(std::unordered_set<K> s1, std::unordered_set<K> s2)
{
    std::unordered_set<K>&small = s1, &large = s2;
    if (s1.size() > s2.size()) {
        small = s2;
        large = s1;
    }
    std::unordered_set<K> s;
    for (K e : small)
        if (large.find(e) != large.end())
            s.insert(e);

    return s;
}

template <typename K>
std::unordered_set<K> difference(std::unordered_set<K> s1, std::unordered_set<K> s2)
{
    // return s1 - s2
    std::unordered_set<K> s;
    for (K e : s1)
        if (s2.find(e) == s2.end())
            s.insert(e);

    return s;
}

template <typename K, typename V>
bool in(std::unordered_map<K, V> m, K k)
{
    return m.find(k) != m.end();
}

template <typename K>
bool in(std::unordered_set<K> s, K k)
{
    return s.find(k) != s.end();
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<K, V>& map)
{
    if (map.size() <= 0)
        return os << "{}";
    auto it = map.begin();
    os << "{";
    os << it->first << ": " << it->second;
    ++it;
    while (it != map.end()) {
        os << ", " << it->first << ": " << it->second;
        ++it;
    }
    os << "}";
    return os;
}

template <typename K>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<K>& map)
{
    if (map.size() <= 0)
        return os << "{}";
    auto it = map.begin();
    os << "{";
    os << *it;
    ++it;
    while (it != map.end()) {
        os << ", " << *it;
        ++it;
    }
    os << "}";
    return os;
}

template <typename P, typename Q>
std::ostream& operator<<(std::ostream& os, const std::pair<P, Q>& p)
{
    os << "(";
    os << p.first;
    os << ", ";
    os << p.second;
    os << ")";
    return os;
}
