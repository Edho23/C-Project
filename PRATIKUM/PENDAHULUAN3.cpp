//AGUSTINO EDWARD HARTONO
//1462300061
#include <iostream>
using namespace std;

void faktorial(int n, int *hasil) {
    if(n == 0) {
        *hasil = 1;  
        return;
    }
    
    int faktorSementara;
    faktorial(n-1, &faktorSementara);
    *hasil = n * faktorSementara;
}

void permutasi(int n, int r, int *hasil) {
    int faktor1, faktor2;
    faktorial(n, &faktor1);
    faktorial(n-r, &faktor2);
    *hasil = faktor1/faktor2;
}

int main() {
    int angkaPermutasi;
    permutasi(5, 3, &angkaPermutasi);
    cout << "Nilai permutasi adalah: " << angkaPermutasi << endl;
    cin.get();
    return 0;
}