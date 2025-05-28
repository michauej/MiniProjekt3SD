#ifndef HASHTABLE_H
#define HASHTABLE_H

// Abstrakcyjna klasa bazowa - interfejs dla tablic mieszaj¹cych
class HashTable {
public:
    virtual void insert(int key, int value) = 0;
    virtual int search(int key) = 0;
    virtual void remove(int key) = 0;
    virtual ~HashTable() = default;
};

#endif 