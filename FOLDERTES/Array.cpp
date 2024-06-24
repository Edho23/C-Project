#include <iostream>
using namespace std;

int main() {

    int A[] = {23, 47, 65};
    int B[] = {14, 35, 57, 94};
    int merged[7];

    
    int index1 = 0, index2 = 0, mergedIndex = 0;
    while (index1 < 3 && index2 < 4) {
        if (A[index1] <= B[index2]) {
            merged[mergedIndex++] = A[index1++];
        } else {
            merged[mergedIndex++] = B[index2++];
        }
    }
    while (index1 < 3) {
        merged[mergedIndex++] = A[index1++];
    }
    while (index2 < 4) {
        merged[mergedIndex++] = B[index2++];
    }

    cout << "SEBELUM DI URUTKAN" << endl;
    cout << "A : 23, 47, 65 " << endl;
    cout << "B : 14, 35, 57, 94 " << endl << endl;
    cout << "Array gabungan setelah pengurutan: ";
    for (int i = 0; i < 7; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;
    cin.get();

    return 0;
}