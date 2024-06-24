#include <iostream>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <conio.h>


using namespace std;

struct Barang {
    int kode;
    int No;
    string nama;
    int stok;
    int Harga;

};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main() {
    vector<Barang> gudang;
    int nomorBarang = 1;


    while(true) {
    int pilihan;
    system("cls");
    cout << "=========== APLIKASI GUDANG ============" << endl;
    cout << "1. Tambah Barang" << endl;
    cout << "2. Tampilkan Gudang" << endl;
    cout << "3. Cari Barang" << endl;
    cout << "4. Hapus Barang" << endl;
    cout << "5. Edit Barang" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih menu : ";
    cin >> pilihan;

    switch(pilihan) {
        case 1: {
            Barang barang;
            barang.No = nomorBarang++;

            cout << "Masukkan Kode : ";
            cin >> barang.kode;

            cout << "Masukkan Nama Barang : ";
            cin >> barang.nama;

            cout << "Masukkan Stok : ";
            cin >> barang.stok;

            cout << "Harga Satuan : ";
            cin >> barang.Harga;
            
            gudang.push_back(barang);
            cout << "BARANG BERHASIL DITAMBAHKAN" << endl;

            continue;

        }
        case 2: {
            system("cls");
    gotoxy(0,0);cout << "=======================================================";
    gotoxy(0,1);cout << "| No | kode | Nama Barang | Stok Barang | Harga Satuan|";
    gotoxy(0,2);cout << "=======================================================";

    for (int i = 0; i < gudang.size(); i++) {
        gotoxy(0,3+i);
        cout << "| " << setw(3) << gudang[i].No << "| " << setw(4) << gudang[i].kode << " | " << setw(11) << gudang[i].nama << " | " << setw(12) << gudang[i].stok << " | " << setw(13) << fixed << setprecision(2) << gudang[i].Harga << " |";
    }

    for (int i = gudang.size() + 1; i <= 13; i++) {
        gotoxy(0,2+i);cout << "|      |             |             |             |";
    }
    gotoxy(0,15);cout << "==================================================";


    int i = 1;
    char tambahdata;

    cout << endl;
    do {
        gotoxy(57,3);cout << "Tambahkan Lagi [Y/T] : ";
        cin >> tambahdata;
        i++;

    } while (tambahdata == 'y' || tambahdata == 'Y');

    continue;
}

        case 3: {

        }
        case 4: {

        }
        case 5: {

        }
        case 6: {

        }
    }


    cin.get();
    return 0;
    }
}
