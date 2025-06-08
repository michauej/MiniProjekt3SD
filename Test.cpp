#include "Test.h"
using namespace std;

vector<pair<int, int>> generateDataset(int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 500 * size);
    vector<pair<int, int>> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = { i, dist(gen) };
    }
    return data;
}

const int DATASET_COUNT = 100;
const int repeat = 10;
int sizes[] = { 1000 };
float multiFactors[] = { 0.25, 0.5, 1, 2, 4, 8, 16, 32,50, 64,80,100,128,256, 512 };
void testInsert() {

    cout << "=== INSERT TEST elementow===" << endl;
    cout << "Size\tOpen(us)\tChaining(us)\tAvl(us)" << endl;
    for (int s = 0; s < 1; s++) {
        for (int m = 0; m < 15; m++) {
            int size = sizes[s];
            float multiFactor = multiFactors[m];
            long long OpenTotal = 0;
            long long AvlTotal = 0;
            long long ChainingTotal = 0;
            for (int i = 0; i < DATASET_COUNT; i++) {
                vector<pair<int, int>> data = generateDataset(size * multiFactor);
                for (int x = 0; x < repeat; x++) {
                    random_device rd;
                    mt19937 gen(rd());
                    uniform_int_distribution<int> dist(1, 500 * size);
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
            cout << (float)(size * multiFactor) <<"\t" << OpenTotal / DATASET_COUNT / repeat << "\t\t" << ChainingTotal / DATASET_COUNT / repeat << "\t\t" << AvlTotal / DATASET_COUNT / repeat << endl;

        }
    }
}
void testRemove() {

    cout << "=== Remove TEST elementow===" << endl;
    cout << "Size\tOpen(us)\tChaining(us)\tAvl(us)" << endl;
    for (int s = 0; s < 1; s++) {
        for (int m = 0; m < 15; m++) {
            int size = sizes[s];
            float multiFactor = multiFactors[m];
            long long OpenTotal = 0;
            long long AvlTotal = 0;
            long long ChainingTotal = 0;
            for (int i = 0; i < DATASET_COUNT; i++) {
                vector<pair<int, int>> data = generateDataset(size * multiFactor);
                for (int x = 0; x < repeat; x++) {
                    random_device rd;
                    mt19937 gen(rd());
                    uniform_int_distribution<int> dist(1, size * multiFactor-1);
                    int randomNumber = dist(gen);
                    OpenAddressingHashTable oaht(size);
                    for (size_t j = 0; j < data.size(); j++)
                        oaht.insert(data[j].first, data[j].second);
                    auto start = high_resolution_clock::now();
                    oaht.remove(data[randomNumber].first);
                    auto end = high_resolution_clock::now();
                    OpenTotal += duration_cast<nanoseconds>(end - start).count();

                    AvlHashTable aht(size);
                    for (size_t j = 0; j < data.size(); j++)
                        aht.insert(data[j].first, data[j].second);
                    start = high_resolution_clock::now();
                    aht.remove(data[randomNumber].first);
                    end = high_resolution_clock::now();
                    AvlTotal += duration_cast<nanoseconds>(end - start).count();

                    ChainingHashTable cht(size);
                    for (size_t j = 0; j < data.size(); j++)
                        cht.insert(data[j].first, data[j].second);
                    start = high_resolution_clock::now();
                    cht.remove(data[randomNumber].first);
                    end = high_resolution_clock::now();
                    ChainingTotal += duration_cast<nanoseconds>(end - start).count();
                }
            }
            cout << (float)(size * multiFactor) << "\t" << OpenTotal / DATASET_COUNT / repeat << "\t\t" << ChainingTotal / DATASET_COUNT / repeat << "\t\t" << AvlTotal / DATASET_COUNT / repeat << endl;

        }
    }
}