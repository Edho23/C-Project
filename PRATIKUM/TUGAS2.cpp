// AGUSTINO EDWARD HARTONO
// 1462300061
#include <iostream>

using namespace std;

int main() {

    int banyaknilai;

    cout << "Masukkan Nilai Awal : ";
    cin >> banyaknilai;

    int nilai[12];

    for (int i = 0; i < banyaknilai; ++i) {
        cout << "Masukkan Nilai  " << i + 1 << " : " ;
        cin >> nilai[i];
    }
      
      cout << endl;

    for (int i = 0; i < banyaknilai; ++i) {   
        cout << "Nilai " << i + 1 <<  " : " << nilai[i] << endl;
    }

    cin.get();
    return 0;
}
