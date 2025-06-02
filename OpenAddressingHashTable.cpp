#include "OpenAddressingHashTable.h"

OpenAddressingHashTable::OpenAddressingHashTable(int size)
    : capacity(size), size(0) {
    table.resize(capacity, std::make_pair(-1, -1));
    occupied.resize(capacity, false);
}

int OpenAddressingHashTable::hashFunction(int key) const {
    return key % capacity;
}

int OpenAddressingHashTable::linearProbing(int key) const {
    int index = hashFunction(key);
    int i = 0;
    while (occupied[(index + i) % capacity] && table[(index + i) % capacity].first != key) {
        i++;
    }
    return (index + i) % capacity;
}

void OpenAddressingHashTable::resize() {
    int oldCapacity = capacity;
    capacity *= 2;
    size = 0;

    std::vector<std::pair<int, int>> oldTable = table;
    std::vector<bool> oldOccupied = occupied;

    table.clear();
    occupied.clear();
    table.resize(capacity, std::make_pair(-1, -1));
    occupied.resize(capacity, false);

    for (int i = 0; i < oldCapacity; ++i) {
        if (oldOccupied[i]) {
            insert(oldTable[i].first, oldTable[i].second);
        }
    }
}

void OpenAddressingHashTable::insert(int key, int value) {
    if ((float)(size + 1) / capacity >= loadFactorThreshold) {
        resize();
    }

    int index = linearProbing(key);
    if (!occupied[index]) size++;
    table[index] = std::make_pair(key, value);
    occupied[index] = true;
}

int OpenAddressingHashTable::search(int key) {
    int index = linearProbing(key);
    if (occupied[index] && table[index].first == key)
        return table[index].second;
    return -1;
}

void OpenAddressingHashTable::remove(int key) {
    int index = linearProbing(key);
    if (occupied[index] && table[index].first == key) {
        table[index] = std::make_pair(-1, -1);
        occupied[index] = false;
        size--;
    }
}
