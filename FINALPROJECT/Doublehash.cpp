#include <iostream>
#include <vector>

using namespace std;

class DoubleHash {
private:
    vector<long long> hashTable;
    int capacity;
    int prime;
    int size;

    int hash1(long long key) {
        return key % capacity;
    }

    int hash2(long long key) {
        return prime - (key % prime);
    }

public:
    DoubleHash(int cap) {
        capacity = cap;
        size = 0;
        prime = 7;
        hashTable.resize(capacity, -1);
    }

    void insert(long long key) {
        if (size == capacity) {
            cout << "Hash Table is full" << endl;
            return;
        }

        int index = hash1(key);
        if (hashTable[index] != -1) {
            int index2 = hash2(key);
            int i = 1;
            while (true) {
                int newIndex = (index + i * index2) % capacity;
                if (hashTable[newIndex] == -1) {
                    hashTable[newIndex] = key;
                    break;
                }
                i++;
            }
        } else {
            hashTable[index] = key;
        }
        size++;
    }

    bool search(long long key) {
        int index = hash1(key);
        int index2 = hash2(key);
        int i = 0;
        while (hashTable[(index + i * index2) % capacity] != key) {
            if (hashTable[(index + i * index2) % capacity] == -1) {
                return false;
            }
            i++;
        }
        return true;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";
            if (hashTable[i] != -1) {
                cout << hashTable[i];
            }
            cout << endl;
        }
    }
};

int main() {
    int capacity = 11;
    DoubleHash ht(capacity);

    ht.insert(1462300061LL);
    ht.insert(1462300062LL);
    ht.insert(1462300063LL);
    ht.insert(1462300064LL);

    cout << "Hash Table after insertion:" << endl;
    ht.display();

    if (ht.search(1462300061LL)) {
        cout << "Element 1462300063 Ditemukkan" << endl;
    } else {
        cout << "Element 1462300063 tidak ditemukan di tabel hash" << endl;
    }

    if (ht.search(9999999999LL)) {
        cout << "Element 9999999999 Ditemukkan" << endl;
    } else {
        cout << "Element 9999999999 tidak ditemukan di tabel hash" << endl;
    }
    cin.get();
    return 0;
}
