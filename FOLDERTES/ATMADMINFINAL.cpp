#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
private:
    int table[SIZE];
public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = -1; 
        }
    }

    void insert(int value) {
        int index = value % SIZE; 

        while (table[index] != -1) {
            index = (index + 1) % SIZE;
        }

        table[index] = value;
    }

    int search(int value) {
        int index = value % SIZE; 

        while (table[index] != value && table[index] != -1) {
            index = (index + 1) % SIZE;
        }

        if (table[index] == value) {
            return index; 
        } else {
            return -1;
        }
    }
};

int main() {
    HashTable hashTable;


    hashTable.insert(12);
    hashTable.insert(25);
    hashTable.insert(35);
    hashTable.insert(20);


    int key = 20;
    int index = hashTable.search(key);

    if (index != -1) {
        cout << "Data ditemukan pada indeks " << index << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
    cin.get();
    return 0;
}
