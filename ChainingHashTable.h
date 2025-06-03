#pragma once
#include "HashTable.h"
#include <list>
#include <vector>

class ChainingHashTable : public HashTable {
private:
    std::vector<std::list<std::pair<int, int>>> buckets;
    int capacity;
    int size;
    const float loadFactorThreshold = 1.0f;  

    int hash(int key) const;
    void resize();

public:
    ChainingHashTable(int capacity);
    void insert(int key, int value) override;
    int search(int key) override;
    void remove(int key) override;
};
