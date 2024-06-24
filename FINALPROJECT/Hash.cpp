#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> hashTable[10]; // Hash table dengan ukuran 10

    // Array angka yang akan dimasukkan ke hash table
    int arr[] = {10, 7, 1, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Memasukkan angka ke dalam hash table
    for (int i = 0; i < n; i++) {
        int index = arr[i] % 10; // Menggunakan modulus 10
        hashTable[index].push_back(arr[i]);
    }

    // Menampilkan hash table
    for (int i = 0; i < 10; i++) {
        cout << "Index " << i << ": ";
        for (int j = 0; j < hashTable[i].size(); j++) {
            cout << hashTable[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
