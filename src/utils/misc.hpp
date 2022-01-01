#include <unordered_map>
#include <unordered_set>

template <class K, class V>
K arbitrary_element(std::unordered_map<K, V> m)
{
    return m.begin()->first;
}

template <class V>
V arbitrary_element(std::unordered_set<V> m)
{
    return *m.begin();
}