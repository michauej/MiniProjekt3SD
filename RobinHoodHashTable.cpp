#include "RobinHoodHashTable.h"
#include <algorithm>

RobinHoodHashTable::RobinHoodHashTable(int size)
    : capacity(size), size(0) {
    table.resize(capacity);
}

int RobinHoodHashTable::hashFunction(int key) const {
    return key % capacity;
}

void RobinHoodHashTable::resize() {
    int oldCapacity = capacity;
    capacity *= 2;
    size = 0;

    std::vector<Entry> oldTable = table;
    table.clear();
    table.resize(capacity);

    for (const auto& entry : oldTable) {
        if (entry.occupied) {
            insert(entry.key, entry.value);
        }
    }
}

void RobinHoodHashTable::insert(int key, int value) {
    if ((float)(size + 1) / capacity >= loadFactorThreshold) {
        resize();
    }

    Entry newEntry;
    newEntry.key = key;
    newEntry.value = value;
    newEntry.occupied = true;
    newEntry.probeDistance = 0;

    int index = hashFunction(key);

    while (true) {
        if (!table[index].occupied) {
            table[index] = newEntry;
            size++;
            return;
        }

        if (table[index].key == key) {
            table[index].value = value;
            return;
        }

        if (table[index].probeDistance < newEntry.probeDistance) {
            std::swap(table[index], newEntry);
        }

        index = (index + 1) % capacity;
        newEntry.probeDistance++;
    }
}

int RobinHoodHashTable::search(int key) {
    int index = hashFunction(key);
    int probeDistance = 0;

    while (table[index].occupied) {
        if (table[index].key == key) {
            return table[index].value;
        }
        if (probeDistance > table[index].probeDistance) {
            return -1;
        }
        index = (index + 1) % capacity;
        probeDistance++;
    }

    return -1;
}

void RobinHoodHashTable::remove(int key) {
    int index = hashFunction(key);
    int probeDistance = 0;

    while (table[index].occupied) {
        if (table[index].key == key) {
            table[index] = Entry();
            size--;
            return;
        }
        if (probeDistance > table[index].probeDistance) {
            return;
        }
        index = (index + 1) % capacity;
        probeDistance++;
    }
}
