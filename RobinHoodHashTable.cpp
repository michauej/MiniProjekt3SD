#include "RobinHoodHashTable.h"
#include <cmath>
#include <algorithm>

RobinHoodHashTable::RobinHoodHashTable(int size) {
    capacity = size;
    table.resize(size, std::make_pair(-1, -1));
    occupied.resize(size, false);
    distance.resize(size, 0);
}

int RobinHoodHashTable::hashFunction(int key) {
    return key % capacity;
}

void RobinHoodHashTable::insert(int key, int value) {
    int index = hashFunction(key);
    int probeDistance = 0;

    while (occupied[index]) {
        if (table[index].first == key) {
            table[index].second = value;
            return;
        }

        int existingDistance = distance[index];
        if (probeDistance > existingDistance) {
            std::swap(key, table[index].first);
            std::swap(value, table[index].second);
            std::swap(probeDistance, distance[index]);
        }

        index = (index + 1) % capacity;
        probeDistance++;
        if (probeDistance >= capacity) return;
    }

    table[index] = std::make_pair(key, value);
    distance[index] = probeDistance;
    occupied[index] = true;
}

int RobinHoodHashTable::search(int key) {
    int index = hashFunction(key);
    int probeDistance = 0;

    while (occupied[index]) {
        if (table[index].first == key) {
            return table[index].second;
        }

        if (probeDistance > distance[index]) {
            return -1;
        }

        index = (index + 1) % capacity;
        probeDistance++;
        if (probeDistance >= capacity) return -1;
    }

    return -1;
}

void RobinHoodHashTable::remove(int key) {
    int index = hashFunction(key);
    int probeDistance = 0;

    while (occupied[index]) {
        if (table[index].first == key) {
            table[index] = std::make_pair(-1, -1);
            occupied[index] = false;
            distance[index] = 0;
            return;
        }

        if (probeDistance > distance[index]) return;

        index = (index + 1) % capacity;
        probeDistance++;
        if (probeDistance >= capacity) return;
    }
}
