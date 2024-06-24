// NAMA : Agustino Edward Hartono
// NBI  : 1462300061
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    int nilaiSiswa;
    bool nilaiRataRata;
    string namaSiswa;

    cout << "Masukkan Nama Siswa : ";
    cin >> namaSiswa;

    cout << "Masukkan Nilai Siswa : ";
    cin >> nilaiSiswa;

    cout << "Masukkan Nilai Rata-Rata : ";
    cin >> nilaiRataRata;

    system("cls");
    cout << "Nama Siswa : " << namaSiswa << endl;
    cout << "Nilai Siswa : " << nilaiSiswa << endl;
    cout << "Nilai Rata-Rata : " << nilaiRataRata << endl;

    cin.get();
    return 0;
}
