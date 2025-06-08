#include "ChainingHashTable.h"

ChainingHashTable::ChainingHashTable(int capacity)
    : capacity(capacity), size(0) {
    buckets = new ElementOfChain * [capacity];
    for (int i = 0; i < capacity; ++i) {
        buckets[i] = nullptr;
    }
}

ChainingHashTable::~ChainingHashTable() {
    deleteChains();
    delete[] buckets;
}

void ChainingHashTable::deleteChains() {
    for (int i = 0; i < capacity; ++i) {
        ElementOfChain* current = buckets[i];
        while (current != nullptr) {
            ElementOfChain* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
}

int ChainingHashTable::hash(int key) const {
    return key % capacity;
}
void ChainingHashTable::insert(int key, int value) {

    int index = hash(key);
    ElementOfChain* current = buckets[index];

    while (current != nullptr) {
        if (current->key == key) {
            current->value = value; // Aktualizacja, jeœli klucz istnieje
            return;
        }
        current = current->next;
    }

    ElementOfChain* newEntry = new ElementOfChain{ key, value, buckets[index] };
    buckets[index] = newEntry;
    size++;
}

int ChainingHashTable::search(int key) {
    int index = hash(key);
    ElementOfChain* current = buckets[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return -1;
}

void ChainingHashTable::remove(int key) {
    int index = hash(key);
    ElementOfChain* current = buckets[index];
    ElementOfChain* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                buckets[index] = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}
