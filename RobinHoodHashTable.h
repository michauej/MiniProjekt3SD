#pragma once
#include "HashTable.h"
#include <vector>
#include <utility>

class RobinHoodHashTable : public HashTable {
private:
    struct Entry {
        int key;
        int value;
        bool occupied;
        int probeDistance;

        Entry() : key(-1), value(-1), occupied(false), probeDistance(0) {}
    };

    std::vector<Entry> table;
    int capacity;
    int size;
    const float loadFactorThreshold = 0.7f;

    int hashFunction(int key) const;
    void resize();

public:
    RobinHoodHashTable(int size);
    void insert(int key, int value) override;
    int search(int key) override;
    void remove(int key) override;
};
