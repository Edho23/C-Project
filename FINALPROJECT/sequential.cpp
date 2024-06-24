#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Mengembalikan indeks jika elemen ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika elemen tidak ditemukan
}

int main() {
    int arr[] = {10, 7, 1, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5; // Angka yang ingin dicari
    cout << "Key : " << key << endl;
    int index = sequentialSearch(arr, n, key);
    if (index != -1) {
        cout << "Elemen ditemukan pada indeks: " << index << endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }
    cin.get();
    return 0;
}
