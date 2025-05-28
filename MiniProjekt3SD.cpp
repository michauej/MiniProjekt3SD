#include <iostream>
#include "OpenAddressingHashTable.h"

void printMenu() {
    std::cout << "\n--- MENU ---\n";
    std::cout << "1. Dodaj (insert)\n";
    std::cout << "2. Wyszukaj (search)\n";
    std::cout << "3. Usun (remove)\n";
    std::cout << "4. Wyjscie\n";
    std::cout << "Wybierz opcje: ";
}

int main() {
    int size;
    std::cout << "Podaj rozmiar tablicy mieszajacej: ";
    std::cin >> size;

    OpenAddressingHashTable hashTable(size);

    int choice, key, value;

    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Podaj klucz i wartosc: ";
            std::cin >> key >> value;
            hashTable.insert(key, value);
            std::cout << "Dodano.\n";
            break;
        case 2:
            std::cout << "Podaj klucz do wyszukania: ";
            std::cin >> key;
            value = hashTable.search(key);
            if (value != -1)
                std::cout << "Znaleziono: " << value << "\n";
            else
                std::cout << "Nie znaleziono klucza.\n";
            break;
        case 3:
            std::cout << "Podaj klucz do usuniecia: ";
            std::cin >> key;
            hashTable.remove(key);
            std::cout << "Usunieto, jesli istnial.\n";
            break;
        case 4:
            std::cout << "Zamykam program.\n";
            break;
        default:
            std::cout << "Niepoprawna opcja.\n";
        }
    } while (choice != 4);

    return 0;
}
