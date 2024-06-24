#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Mahasiswa {
    string NBI;
    string nama;
    string tgl_lahir;
    string jurusan;
    char jenis_kelamin;
};

int main() {

    int jumlah;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    vector<Mahasiswa> mahasiswas;

    for(int i = 0; i < jumlah; i++) {
        Mahasiswa mhs;
        cout << "Masukkan data mahasiswa ke-" << i+1 << endl;

        cout << "NBI: ";
        cin >> mhs.NBI;
        cout << "Nama: ";
        cin >> mhs.nama;
        cout << "Tgl Lahir: ";
        cin >> mhs.tgl_lahir;
        cout << "Jurusan: ";
        cin >> mhs.jurusan;
        cout << "Jenis Kelamin (L/P): ";
        cin >> mhs.jenis_kelamin;
        cout << endl;
        mahasiswas.push_back(mhs);
    }

    int pil;
    char ulangi;
    do {
    cout << "Pilih kelas: " << endl;
    cout << "1. Reguler" << endl;
    cout << "2. Non-Reguler" << endl;
    cin >> pil;

    if(pil == 1) {
        sort(mahasiswas.begin(), mahasiswas.end(), [](Mahasiswa &a, Mahasiswa &b) {
            return a.NBI < b.NBI;
        });
    } else {
        sort(mahasiswas.begin(), mahasiswas.end(), [](Mahasiswa &a, Mahasiswa &b) {
            return a.NBI > b.NBI;
        });
    }

    cout << "\nData Mahasiswa" << endl;
    for(Mahasiswa &m : mahasiswas) {
        cout << "NBI: " << m.NBI << endl;
        cout << "Nama: " << m.nama << endl;
        cout << "Tgl Lahir: " << m.tgl_lahir << endl;
        cout << "Jurusan: " << m.jurusan << endl;
        cout << "Jenis Kelamin: " << m.jenis_kelamin << endl << endl;
    }
     cout << "Apakah ingin kembali[Y/T]";
     cin >> ulangi;
    }while(ulangi == 'Y' || ulangi == 'y');
}
