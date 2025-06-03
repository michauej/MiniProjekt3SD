#include "ChainingHashTable.h"
#include <algorithm>

ChainingHashTable::ChainingHashTable(int capacity)
    : capacity(capacity), size(0) {
    buckets.resize(capacity);
}

int ChainingHashTable::hash(int key) const {
    return key % capacity;
}

void ChainingHashTable::resize() {
    int newCapacity = capacity * 2;
    std::vector<std::list<std::pair<int, int>>> newBuckets(newCapacity);

    for (const auto& chain : buckets) {
        for (const auto& entry : chain) {
            int newIndex = entry.first % newCapacity;
            newBuckets[newIndex].push_back(entry);
        }
    }

    buckets = std::move(newBuckets);
    capacity = newCapacity;
}

void ChainingHashTable::insert(int key, int value) {
    if ((float)(size + 1) / capacity > loadFactorThreshold) {
        resize();
    }

    int index = hash(key);
    for (auto& entry : buckets[index]) {
        if (entry.first == key) {
            entry.second = value;  // Aktualizacja, jeœli klucz istnieje
            return;
        }
    }

    buckets[index].emplace_back(key, value);
    size++;
}

int ChainingHashTable::search(int key) {
    int index = hash(key);
    for (const auto& entry : buckets[index]) {
        if (entry.first == key) {
            return entry.second;
        }
    }
    return -1;  
}

void ChainingHashTable::remove(int key) {
    int index = hash(key);
    auto& chain = buckets[index];
    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->first == key) {
            chain.erase(it);
            size--;
            return;
        }
    }
}