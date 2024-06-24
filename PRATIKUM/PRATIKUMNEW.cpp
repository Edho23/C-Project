// NAMA : Agustino Edward Hartono
// NBI  : 1462300061
#include <iostream>

using namespace std;

int main() {

    int a; 
    int b;

    cout << "Masukkan Angka Pertama : ";
    cin >> a;

    cout << "Masukkan Angka Kedua : ";
    cin >> b;

    int jumlah = a + b;
    int pengurangan = a - b;
    int kali = a * b;
    double bagi = static_cast<double>(a) / b;
    int hasilbagi = a % b;

    bool samadengan = a == b;
    bool tidaksamadengan = a != b;
    bool lebihdari = a > b;
    bool kurangdari = a < b;
    bool besardari = a >= b;
    bool kecildari = a <= b;

    cout << " HASIL BAGI ARITMATIKA " << endl;
    cout << " Jumlah : " << jumlah << endl;
    cout << " Pengurangan : " << pengurangan << endl;
    cout << " Perkalian : " << kali << endl;
    cout << " Pembagian : " << bagi << endl;
    cout << " Sisa bagi : " << hasilbagi << endl << endl;

    cout << " HASIL OPERASI RELASIONAL " << endl;
    cout << " Sama Dengan : " << samadengan << endl;
    cout << " Tidak Sama Dengan : " << tidaksamadengan<< endl;
    cout << " Lebih Dari : " << lebihdari << endl;
    cout << " Kurang Dari : " << kurangdari << endl;
    cout << " Besar Dari : " << besardari << endl;
    cout << " Kurang Dari : " << kurangdari << endl;

    cin.get();
    return 0;
}
