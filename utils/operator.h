#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <class T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);
template <typename K, typename V>
inline void update_map(std::unordered_map<K, V>& m, std::unordered_map<K, V> l);
template <typename K, typename V>
inline std::vector<K> convert_mapkey_to_vector(std::unordered_map<K, V> m);
template <typename V>
inline std::vector<V> convert_set_to_vector(std::unordered_set<V> s);
template <typename K, typename V>
inline std::unordered_set<K> convert_map_to_set(std::unordered_map<K, V> m);
template <typename K1, typename K2, typename V>
inline std::unordered_map<K1, std::unordered_set<K2>> convert_mapmap_to_mapset(std::unordered_map<K1, std::unordered_map<K2, V>> m);
template <typename K, typename V1, typename V2>
inline std::unordered_map<K, V2> fromkeys(std::unordered_map<K, V1> m, V2 v);
template <typename K, typename V>
inline V dict_get(std::unordered_map<K, V>& m, K k, V v);
template <typename K>
inline std::unordered_set<K> intersection(std::unordered_set<K>& s1, std::unordered_set<K>& s2);
template <typename K>
inline std::unordered_set<K> difference(std::unordered_set<K>& s1, std::unordered_set<K>& s2);
template <typename K>
inline void difference_update(std::unordered_set<K>& s1, std::unordered_set<K>& s2);
template <typename K, typename V>
inline bool in(std::unordered_map<K, V>& m, K k);
template <typename K>
inline bool in(std::unordered_set<K>& s, K k);
template <typename K, typename V>
inline std::ostream& operator<<(std::ostream& os, const std::unordered_map<K, V>& map);
template <typename K>
inline std::ostream& operator<<(std::ostream& os, const std::unordered_set<K>& map);
template <typename P, typename Q>
inline std::ostream& operator<<(std::ostream& os, const std::pair<P, Q>& p);
