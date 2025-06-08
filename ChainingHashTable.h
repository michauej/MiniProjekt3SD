#pragma once
#include "HashTable.h"

struct ElementOfChain {
    int key;
    int value;
    ElementOfChain* next;
};

class ChainingHashTable : public HashTable {
private:
    ElementOfChain** buckets;
    int capacity;
    int size;

    int hash(int key) const;
    void deleteChains();

public:
    ChainingHashTable(int capacity);
    ~ChainingHashTable();

    void insert(int key, int value) override;
    int search(int key) override;
    void remove(int key) override;
};
