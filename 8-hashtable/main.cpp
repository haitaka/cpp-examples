#include <iostream>
#include <cassert>
#include <vector>
#include <functional>

template<typename K>
int hash(K key) {
    return 1;
}

template<typename K, typename V>
class HashTable {
    static const int N = 42;
public:
    void add(K key, V val) {
        Pair p;
        p.k = key;
        p.v = val;

        std::vector<Pair> & v = data[hash(key) % N];
        v.push_back(p);
    }

    V find(K key) {
        std::vector<Pair> & v = data[hash(key) % N];
        for (auto & p : v) {
            if (p.k == key) {
                return p.v;
            }
        }
        exit(42);
    }

    class Pair {
    public:
        K k;
        V v;
    };

private:
    std::vector<HashTable::Pair> data[N];
    V data2[N];
};

int main() {
    HashTable<std::string, int> ht;

    ht.add("hello", 42);
    ht.add("world", 37);

    assert(ht.find("hello") == 42);
    assert(ht.find("world") == 37);

    return 0;
}
