#pragma once
#include "operator.h"

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

template <typename K, typename V>
std::vector<K> convert_mapkey_to_vector(std::unordered_map<K, V> m)
{
    std::vector<K> vec;
    for (auto [k, v] : m)
        vec.push_back(k);
    return vec;
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
std::unordered_map<K1, std::unordered_set<K2>> convert_mapmap_to_mapset(std::unordered_map<K1, std::unordered_map<K2, V>> m)
{
    std::unordered_map<K1, std::unordered_set<K2>> s;
    for (auto [k1, k2_v] : m) {
        s[k1] = std::unordered_set<K2>();
        for (auto [k2, v] : k2_v) {
            s[k1].insert(k2);
        }
    }
    return s;
}

template <typename K, typename V1, typename V2>
std::unordered_map<K, V2> fromkeys(std::unordered_map<K, V1> m, V2 v)
{
    std::unordered_map<K, V2> n;
    for (auto [k, v_old] : m) {
        n[k] = v;
    }
    return n;
}

template <typename K, typename V>
V dict_get(std::unordered_map<K, V>& m, K k, V v)
{
    if (in(m, k))
        return m[k];
    return v;
}

template <typename K>
std::unordered_set<K> intersection(std::unordered_set<K>& s1, std::unordered_set<K>& s2)
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
std::unordered_set<K> difference(std::unordered_set<K>& s1, std::unordered_set<K>& s2)
{
    // return s1 - s2
    std::unordered_set<K> s;
    for (K e : s1)
        if (s2.find(e) == s2.end())
            s.insert(e);

    return s;
}

template <typename K>
void difference_update(std::unordered_set<K>& s1, std::unordered_set<K>& s2)
{
    // return element unique in s1
    std::unordered_set<K> cp = s1;
    for (K e : cp)
        if (s2.find(e) != s2.end()) //
            s1.erase(e); // remove the element in s1 if it exists in both of sets

    return;
}

template <typename K, typename V>
bool in(std::unordered_map<K, V>& m, K k)
{
    return m.find(k) != m.end();
}

template <typename K>
bool in(std::unordered_set<K>& s, K k)
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
