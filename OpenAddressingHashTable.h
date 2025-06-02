#pragma once
#include "HashTable.h"
#include <vector>
#include <utility>

class OpenAddressingHashTable : public HashTable {
private:
    std::vector<std::pair<int, int>> table;
    std::vector<bool> occupied;
    int capacity;
    int size;
    const float loadFactorThreshold = 0.7f;

    int hashFunction(int key) const;
    int linearProbing(int key) const;
    void resize();

public:
    OpenAddressingHashTable(int size);
    void insert(int key, int value) override;
    int search(int key) override;
    void remove(int key) override;
};
