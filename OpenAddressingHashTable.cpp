#include "OpenAddressingHashTable.h"

OpenAddressingHashTable::OpenAddressingHashTable(int size) {
    capacity = size;
    table.resize(size, std::make_pair(-1, -1));
    occupied.resize(size, false);
}

int OpenAddressingHashTable::hashFunction(int key) {
    return key % capacity;
}

int OpenAddressingHashTable::linearProbing(int key) {
    int index = hashFunction(key);
    int i = 0;

    // Znajdujemy pierwszy dostêpny kube³ek albo taki z tym samym kluczem
    while (occupied[(index + i) % capacity] && table[(index + i) % capacity].first != key) {
        i++;
        if (i == capacity) return -1; // Tablica pe³na
    }
    return (index + i) % capacity;
}

void OpenAddressingHashTable::insert(int key, int value) {
    int index = linearProbing(key);
    if (index != -1) {
        table[index] = std::make_pair(key, value);
        occupied[index] = true;
    }
}

int OpenAddressingHashTable::search(int key) {
    int index = linearProbing(key);
    if (index != -1 && occupied[index] && table[index].first == key) {
        return table[index].second;
    }
    return -1; // Klucz nie zosta³ znaleziony
}

void OpenAddressingHashTable::remove(int key) {
    int index = linearProbing(key);
    if (index != -1 && occupied[index] && table[index].first == key) {
        table[index] = std::make_pair(-1, -1);
        occupied[index] = false;
    }
}
