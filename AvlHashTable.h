#pragma once
#include "HashTable.h"
#include "AvlTree.h"
class AvlHashTable : public HashTable
{
private:
    int size;
    AvlTree* buckets;
    int hash(int key) const;
public:
    AvlHashTable(int size);
    ~AvlHashTable();

    void insert(int key, int value) override;
    int search(int key) override;
    void remove(int key) override;
};

