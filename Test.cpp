#include "Test.h"

vector<pair<int, int>> generateDataset(int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 50 * size);
    vector<pair<int, int>> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = { i, dist(gen) };
    }
    return data;
}

void test() {
    const int DATASET_COUNT = 8;
    const int repeat = 10;
    int sizes[] = { 5000, 15000, 25000, 35000, 45000, 55000, 65000, 75000, 85000, 95000 };
    cout << "=== INSERT TEST size/4 elementow===" << endl;
    cout << "Size\tOpen(us)\tChaining(us)\tAvl(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long OpenTotal = 0;
        long long AvlTotal = 0;
        long long ChainingTotal = 0;
        for (int i = 0; i < DATASET_COUNT; i++) {
            vector<pair<int, int>> data = generateDataset(size/4);
            for (int x = 0; x < repeat; x++) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(1, 50 * size);
                int randomNumber = dist(gen);
                int randomNumber2 = dist(gen);

                OpenAddressingHashTable oaht(size);
                for (size_t j = 0; j < data.size(); j++)
                    oaht.insert(data[j].first, data[j].second);
                auto start = high_resolution_clock::now();
                oaht.insert(randomNumber, randomNumber2);
                auto end = high_resolution_clock::now();

                OpenTotal += duration_cast<nanoseconds>(end - start).count();

                AvlHashTable aht(size);
                for (size_t j = 0; j < data.size(); j++)
                    aht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                aht.insert(randomNumber, randomNumber2);
                end = high_resolution_clock::now();
                AvlTotal += duration_cast<nanoseconds>(end - start).count();

                ChainingHashTable cht(size);
                for (size_t j = 0; j < data.size(); j++)
                    cht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                cht.insert(randomNumber, randomNumber2);
                end = high_resolution_clock::now();
                ChainingTotal += duration_cast<nanoseconds>(end - start).count();
            }
        }
        cout << size << "\t" << OpenTotal / DATASET_COUNT / repeat<<"\t\t" << ChainingTotal / DATASET_COUNT / repeat << "\t\t" << AvlTotal / DATASET_COUNT / repeat << endl;

    }

    cout << "INSERT TEST size/2 elementow" << endl;
    cout << "Size\tOpen(us)\tChaining(us)\tAvl(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long OpenTotal = 0;
        long long AvlTotal = 0;
        long long ChainingTotal = 0;
        for (int i = 0; i < DATASET_COUNT; i++) {
            vector<pair<int, int>> data = generateDataset(size/2);
            for (int x = 0; x < repeat; x++) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(1, 50 * size);
                int randomNumber = dist(gen);
                int randomNumber2 = dist(gen);

                OpenAddressingHashTable oaht(size);
                for (size_t j = 0; j < data.size(); j++)
                    oaht.insert(data[j].first, data[j].second);
                auto start = high_resolution_clock::now();
                oaht.insert(randomNumber, randomNumber2);
                auto end = high_resolution_clock::now();

                OpenTotal += duration_cast<nanoseconds>(end - start).count();

                AvlHashTable aht(size);
                for (size_t j = 0; j < data.size(); j++)
                    aht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                aht.insert(randomNumber, randomNumber2);
                end = high_resolution_clock::now();
                AvlTotal += duration_cast<nanoseconds>(end - start).count();

                ChainingHashTable cht(size);
                for (size_t j = 0; j < data.size(); j++)
                    cht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                cht.insert(randomNumber, randomNumber2);
                end = high_resolution_clock::now();
                ChainingTotal += duration_cast<nanoseconds>(end - start).count();
            }
        }
        cout << size << "\t" << OpenTotal / DATASET_COUNT / repeat << "\t\t" << ChainingTotal / DATASET_COUNT / repeat << "\t\t" << AvlTotal / DATASET_COUNT / repeat << endl;
    }

    cout << "INSERT TEST size elementow" << endl;
    cout << "Size\tOpen(us)\tChaining(us)\tAvl(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long OpenTotal = 0;
        long long AvlTotal = 0;
        long long ChainingTotal = 0;
        for (int i = 0; i < DATASET_COUNT; i++) {
            vector<pair<int, int>> data = generateDataset(size);
            for (int x = 0; x < repeat; x++) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(1, 50 * size);
                int randomNumber = dist(gen);
                int randomNumber2 = dist(gen);

                OpenAddressingHashTable oaht(size);
                for (size_t j = 0; j < data.size(); j++)
                    oaht.insert(data[j].first, data[j].second);
                auto start = high_resolution_clock::now();
                oaht.insert(randomNumber, randomNumber2);
                auto end = high_resolution_clock::now();

                OpenTotal += duration_cast<nanoseconds>(end - start).count();

                AvlHashTable aht(size);
                for (size_t j = 0; j < data.size(); j++)
                    aht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                aht.insert(randomNumber, randomNumber2);
                end = high_resolution_clock::now();
                AvlTotal += duration_cast<nanoseconds>(end - start).count();

                ChainingHashTable cht(size);
                for (size_t j = 0; j < data.size(); j++)
                    cht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                cht.insert(randomNumber, randomNumber2);
                end = high_resolution_clock::now();
                ChainingTotal += duration_cast<nanoseconds>(end - start).count();
            }
        }
        cout << size << "\t" << OpenTotal / DATASET_COUNT / repeat << "\t\t" << ChainingTotal / DATASET_COUNT / repeat << "\t\t" << AvlTotal / DATASET_COUNT / repeat << endl;
    }

    cout << "INSERT TEST size*2 elementow" << endl;
    cout << "Size\tOpen(us)\tChaining(us)\tAvl(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long OpenTotal = 0;
        long long AvlTotal = 0;
        long long ChainingTotal = 0;
        for (int i = 0; i < DATASET_COUNT; i++) {
            vector<pair<int, int>> data = generateDataset(size*2);
            for (int x = 0; x < repeat; x++) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(1, 50 * size);
                int randomNumber = dist(gen);
                int randomNumber2 = dist(gen);

                OpenAddressingHashTable oaht(size);
                for (size_t j = 0; j < data.size(); j++)
                    oaht.insert(data[j].first, data[j].second);
                auto start = high_resolution_clock::now();
                oaht.insert(randomNumber, randomNumber2);
                auto end = high_resolution_clock::now();

                OpenTotal += duration_cast<nanoseconds>(end - start).count();

                AvlHashTable aht(size);
                for (size_t j = 0; j < data.size(); j++)
                    aht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                aht.insert(randomNumber, randomNumber2);
                end = high_resolution_clock::now();
                AvlTotal += duration_cast<nanoseconds>(end - start).count();
                
                ChainingHashTable cht(size);
                for (size_t j = 0; j < data.size(); j++)
                    cht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                cht.insert(randomNumber, randomNumber2);
                end = high_resolution_clock::now();
                ChainingTotal += duration_cast<nanoseconds>(end - start).count();
            }
        }
        cout << size << "\t" << OpenTotal / DATASET_COUNT / repeat << "\t\t" << ChainingTotal / DATASET_COUNT / repeat << "\t\t" << AvlTotal / DATASET_COUNT / repeat << endl;
    }
    
    cout << "=== Remove TEST size/4 elementow===" << endl;
    cout << "Size\tOpen(us)\tChaining(us)\tAvl(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long OpenTotal = 0;
        long long AvlTotal = 0;
        long long ChainingTotal = 0;
        for (int i = 0; i < DATASET_COUNT; i++) {
            vector<pair<int, int>> data = generateDataset(size / 4);
            for (int x = 0; x < repeat; x++) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(1, 50 * size);
                int randomNumber = dist(gen);

                OpenAddressingHashTable oaht(size);
                for (size_t j = 0; j < data.size(); j++)
                    oaht.insert(data[j].first, data[j].second);
                auto start = high_resolution_clock::now();
                oaht.remove(randomNumber);
                auto end = high_resolution_clock::now();

                OpenTotal += duration_cast<nanoseconds>(end - start).count();

                AvlHashTable aht(size);
                for (size_t j = 0; j < data.size(); j++)
                    aht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                aht.remove(randomNumber);
                end = high_resolution_clock::now();
                AvlTotal += duration_cast<nanoseconds>(end - start).count();

                ChainingHashTable cht(size);
                for (size_t j = 0; j < data.size(); j++)
                    cht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                cht.remove(randomNumber);
                end = high_resolution_clock::now();
                ChainingTotal += duration_cast<nanoseconds>(end - start).count();
            }
        }
        cout << size << "\t" << OpenTotal / DATASET_COUNT / repeat << "\t\t" << ChainingTotal / DATASET_COUNT / repeat << "\t\t" << AvlTotal / DATASET_COUNT / repeat << endl;
    }
    
    cout << "=== Remove TEST size/2 elementow===" << endl;
    cout << "Size\tOpen(us)\tChaining(us)\tAvl(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long OpenTotal = 0;
        long long AvlTotal = 0;
        long long ChainingTotal = 0;
        for (int i = 0; i < DATASET_COUNT; i++) {
            vector<pair<int, int>> data = generateDataset(size / 2);
            for (int x = 0; x < repeat; x++) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(1, 50 * size);
                int randomNumber = dist(gen);

                OpenAddressingHashTable oaht(size);
                for (size_t j = 0; j < data.size(); j++)
                    oaht.insert(data[j].first, data[j].second);
                auto start = high_resolution_clock::now();
                oaht.remove(randomNumber);
                auto end = high_resolution_clock::now();

                OpenTotal += duration_cast<nanoseconds>(end - start).count();

                AvlHashTable aht(size);
                for (size_t j = 0; j < data.size(); j++)
                    aht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                aht.remove(randomNumber);
                end = high_resolution_clock::now();
                AvlTotal += duration_cast<nanoseconds>(end - start).count();

                ChainingHashTable cht(size);
                for (size_t j = 0; j < data.size(); j++)
                    cht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                cht.remove(randomNumber);
                end = high_resolution_clock::now();
                ChainingTotal += duration_cast<nanoseconds>(end - start).count();
            }
        }
        cout << size << "\t" << OpenTotal / DATASET_COUNT / repeat << "\t\t" << ChainingTotal / DATASET_COUNT / repeat << "\t\t" << AvlTotal / DATASET_COUNT / repeat << endl;
    }

    cout << "=== Remove TEST size elementow===" << endl;
    cout << "Size\tOpen(us)\tChaining(us)\tAvl(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long OpenTotal = 0;
        long long AvlTotal = 0;
        long long ChainingTotal = 0;
        for (int i = 0; i < DATASET_COUNT; i++) {
            vector<pair<int, int>> data = generateDataset(size);
            for (int x = 0; x < repeat; x++) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(1, 50 * size);
                int randomNumber = dist(gen);

                OpenAddressingHashTable oaht(size);
                for (size_t j = 0; j < data.size(); j++)
                    oaht.insert(data[j].first, data[j].second);
                auto start = high_resolution_clock::now();
                oaht.remove(randomNumber);
                auto end = high_resolution_clock::now();

                OpenTotal += duration_cast<nanoseconds>(end - start).count();

                AvlHashTable aht(size);
                for (size_t j = 0; j < data.size(); j++)
                    aht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                aht.remove(randomNumber);
                end = high_resolution_clock::now();
                AvlTotal += duration_cast<nanoseconds>(end - start).count();

                ChainingHashTable cht(size);
                for (size_t j = 0; j < data.size(); j++)
                    cht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                cht.remove(randomNumber);
                end = high_resolution_clock::now();
                ChainingTotal += duration_cast<nanoseconds>(end - start).count();
            }
        }
        cout << size << "\t" << OpenTotal / DATASET_COUNT / repeat << "\t\t" << ChainingTotal / DATASET_COUNT / repeat << "\t\t" << AvlTotal / DATASET_COUNT / repeat << endl;
    }
    cout << "=== Remove TEST size*2 elementow===" << endl;
    cout << "Size\tOpen(us)\tChaining(us)\tAvl(us)" << endl;

    for (int s = 0; s < 10; s++) {
        int size = sizes[s];
        long long OpenTotal = 0;
        long long AvlTotal = 0;
        long long ChainingTotal = 0;
        for (int i = 0; i < DATASET_COUNT; i++) {
            vector<pair<int, int>> data = generateDataset(size *2);
            for (int x = 0; x < repeat; x++) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(1, 50 * size);
                int randomNumber = dist(gen);

                OpenAddressingHashTable oaht(size);
                for (size_t j = 0; j < data.size(); j++)
                    oaht.insert(data[j].first, data[j].second);
                auto start = high_resolution_clock::now();
                oaht.remove(randomNumber);
                auto end = high_resolution_clock::now();

                OpenTotal += duration_cast<nanoseconds>(end - start).count();

                AvlHashTable aht(size);
                for (size_t j = 0; j < data.size(); j++)
                    aht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                aht.remove(randomNumber);
                end = high_resolution_clock::now();
                AvlTotal += duration_cast<nanoseconds>(end - start).count();

                ChainingHashTable cht(size);
                for (size_t j = 0; j < data.size(); j++)
                    cht.insert(data[j].first, data[j].second);
                start = high_resolution_clock::now();
                cht.remove(randomNumber);
                end = high_resolution_clock::now();
                ChainingTotal += duration_cast<nanoseconds>(end - start).count();
            }
        }
        cout << size << "\t" << OpenTotal / DATASET_COUNT / repeat << "\t\t" << ChainingTotal / DATASET_COUNT / repeat << "\t\t" << AvlTotal / DATASET_COUNT / repeat << endl;

    }
}