#include <iostream>
#include <unordered_map>
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

template <typename K, typename V>
bool in(std::unordered_map<K, V> m, K k)
{
    return m.find(k) != m.end();
}

template <typename K, typename V>
ostream& operator<<(ostream& os, const unordered_map<K, V>& map)
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