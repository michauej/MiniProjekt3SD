#include "OpenAddressingHashTable.h"
OpenAddressingHashTable::OpenAddressingHashTable(int size)
    : capacity(size), size(0) {
    table = new Entry[capacity];
    occupied = new bool[capacity];
    for (int i = 0; i < capacity; i++) {
        table[i].key = -1;
        table[i].value = -1;
        occupied[i] = false;
    }
}

OpenAddressingHashTable::~OpenAddressingHashTable() {
    delete[] table;
    delete[] occupied;
}

int OpenAddressingHashTable::hashFunction(int key) const {
    return key % capacity;
}

int OpenAddressingHashTable::linearProbing(int key) const {
    int index = hashFunction(key);
    int step = 1 + (key % (capacity - 1));
    int i = 0;
    while (occupied[(index + i * step) % capacity] && table[(index + i * step) % capacity].key != key) {
        i++;
    }

    return (index + i*step) % capacity;
}

void OpenAddressingHashTable::resize() {
    int oldCapacity = capacity;
    capacity *= 2;
    size = 0;

    Entry* oldTable = table;
    bool* oldOccupied = occupied;

    table = new Entry[capacity];
    occupied = new bool[capacity];
    for (int i = 0; i < capacity; i++) {
        table[i].key = -1;
        table[i].value = -1;
        occupied[i] = false;
    }

    for (int i = 0; i < oldCapacity; i++) {
        if (oldOccupied[i]) {
            insert(oldTable[i].key, oldTable[i].value);
        }
    }

    delete[] oldTable;
    delete[] oldOccupied;
}

void OpenAddressingHashTable::insert(int key, int value) {
    if ((float)(size + 1) / capacity >= loadFactorThreshold) {
        resize();
    }

    int index = linearProbing(key);
    if (!occupied[index]) size++;
    table[index].key = key;
    table[index].value = value;
    occupied[index] = true;
}

int OpenAddressingHashTable::search(int key) {
    int index = linearProbing(key);
    if (occupied[index] && table[index].key == key)
        return table[index].value;
    return -1;
}

void OpenAddressingHashTable::remove(int key) {
    int index = linearProbing(key);
    if (occupied[index] && table[index].key == key) {
        table[index].key = -1;
        table[index].value = -1;
        occupied[index] = false;
        size--;
    }
}
