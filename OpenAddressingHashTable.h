#pragma once

struct Entry {
    int key;
    int value;
};

class OpenAddressingHashTable {
public:
    Entry* table;
    bool* occupied;
    int capacity;
    int size;
    const float loadFactorThreshold = 0.7f;

    int hashFunction(int key) const;
    int linearProbing(int key) const;
    void resize();

public:
    OpenAddressingHashTable(int size);
    ~OpenAddressingHashTable();
    void insert(int key, int value);
    int search(int key);
    void remove(int key);
};
