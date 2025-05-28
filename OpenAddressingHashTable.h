#ifndef OPENADDRESSINGHASHTABLE_H
#define OPENADDRESSINGHASHTABLE_H

#include <vector>
#include <utility>
#include "HashTable.h"

// Implementacja tablicy mieszaj¹cej z adresowaniem otwartym (sondowanie liniowe)
class OpenAddressingHashTable : public HashTable {
private:
    std::vector<std::pair<int, int>> table;
    std::vector<bool> occupied;
    int capacity;

    int hashFunction(int key);
    int linearProbing(int key);

public:
    explicit OpenAddressingHashTable(int size);
    void insert(int key, int value) override;
    int search(int key) override;
    void remove(int key) override;
};

#endif 
