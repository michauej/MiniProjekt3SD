#include "AvlHashTable.h"
#include "AvlTree.h"

AvlHashTable::AvlHashTable(int size)
    : size(size), buckets(new AvlTree[size]) {}

AvlHashTable::~AvlHashTable() {
    delete[] buckets;
}
int AvlHashTable::hash(int key) const {
    return key % size;
}

void AvlHashTable::insert(int key, int value) {
    buckets[hash(key)].insert(key, value);
}

int AvlHashTable::search(int key) {
    buckets[hash(key)].inOrder();
    return 0;
}

void AvlHashTable::remove(int key) {
    buckets[hash(key)].remove(key);
}