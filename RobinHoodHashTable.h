#ifndef ROBINHOODHASHTABLE_H
#define ROBINHOODHASHTABLE_H

#include <vector>
#include <utility>
#include "HashTable.h"

class RobinHoodHashTable : public HashTable {
private:
    std::vector<std::pair<int, int>> table;
    std::vector<int> distance;
    std::vector<bool> occupied;
    int capacity;

    int hashFunction(int key);

public:
    RobinHoodHashTable(int size);
    void insert(int key, int value) override;
    int search(int key) override;
    void remove(int key) override;
};

#endif 
