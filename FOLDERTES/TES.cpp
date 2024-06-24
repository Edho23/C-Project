#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

// Deklarasi struktur Item
struct Item {
    string nama;
    int stok;
    float harga;
};

// Deklarasi struktur Pembeli
struct Pembeli {
    Item item[10];
    float totalHarga;
};

Pembeli pembeli;

Item itemList[5];
int menutambahan = 0;
int totalMenu = sizeof(itemList) / sizeof(Item);
int count = 0;

// Deklarasi fungsi-fungsi
void gotoxy(int x, int y);

// Fungsi untuk menampilkan panah
void panah(int rp, int ap) {
    if (rp == ap) {
        cout << "==>";
    } else {
        cout << "   ";
    }
}

// Gwen Theresia Grandis A (672022250)
void tampilBarang(Item* item) {
    cout << "==========Daftar Barang==========" << endl;

    for (int i = 0; i < (totalMenu + menutambahan); i++) {
        cout << "Nama  : " << (item + i)->nama << endl;
        cout << "Stok  : " << (item + i)->stok << endl;
        cout << "Harga : " << fixed << setprecision(3) << (item + i)->harga << endl << endl;
    }
    cout << "\nPress any key to go back" << endl;
    _getch();
}

// Florentino Lama Tokan (672022245)
void TambahBarang(Item* item) {
    muatUlang:
    cout << "=========Tambah Barang==========" << endl;

    for (int i = 0; i < (totalMenu + menutambahan); i++) {
        cout << "Nama  : " << (item + i)->nama << endl;
        cout << "Stok  : " << (item + i)->stok << endl;
        cout << "Harga : " << fixed << setprecision(3) << (item + i)->harga << endl << endl;
    }

    string inputNama;
    int stok;
    float harga;

    cout << "Masukkan Nama Barang : ";
    cin.ignore();
    getline(cin, inputNama);

    cout << "Masukkan Stok : ";
    cin >> stok;

    cout << "Masukkan Harga : ";
    cin >> harga;

    int it;
    for (it = 0; it < totalMenu; it++) {
        if (inputNama == item[it].nama) {
            item[it].stok += stok;
            item[it].harga = harga;
            break;
        }
    }

    if (it == totalMenu) {
        item[totalMenu + menutambahan].nama = inputNama;
        item[totalMenu + menutambahan].stok = stok;
        item[totalMenu + menutambahan].harga = harga;
        menutambahan++;
        cout << "Berhasil Menambahkan " << inputNama << " pada menu" << endl;
    }

    char pilihUlang;

    tanyaUlang:
    cout << "Apakah mau menambahkan lagi? [y/n] : ";
    cin >> pilihUlang;
    if (pilihUlang == 'Y' || pilihUlang == 'y') {
        system("cls");
        goto muatUlang;
    } else if (pilihUlang == 'N' || pilihUlang == 'n') {
        system("cls");
    } else {
        goto tanyaUlang;
    }

    cout << "\nPress any key to go back" << endl;
    _getch();
}

// Cheful Mandiri Djanning (672022256)
void Kalkulasi(Item* item) {
    string inputNama;
    muatUlang:

    for (int i = 0; i < (totalMenu + menutambahan); i++) {
        cout << "Nama  : " << (item + i)->nama << endl;
        cout << "Stok  : " << (item + i)->stok << endl;
        cout << "Harga : " << fixed << setprecision(3) << (item + i)->harga << endl << endl;
    }

    cout << "Masukkan Nama Barang : ";
    cin.ignore();
    getline(cin, inputNama);

    int it;
    for (it = 0; it < (totalMenu + menutambahan); it++) {
        if (inputNama == item[it].nama) {
            int stok;
            tanyaStok:
            cout << "Masukkan Stok : ";
            cin >> stok;
            if (item[it].stok >= stok) {
                item[it].stok -= stok;
                pembeli.item[count].nama = inputNama;
                pembeli.item[count].stok = stok;
                pembeli.item[count].harga = item[it].harga;
                count++;
                cout << "Sukses masukkan kedalam keranjang" << endl;

                tanyaUlang1:
                cout << "Mau menambahkan barang lagi? [y/n] : ";
                cin >> pilihUlang;
                if (pilihUlang == 'Y' || pilihUlang == 'y') {
                    system("cls");
                    goto muatUlang;
                } else if (pilihUlang == 'N' || pilihUlang == 'n') {
                    system("cls");
                    return;
                } else {
                    goto tanyaUlang1;
                }
            } else if (item[it].stok == 0) {
                cout << "Stok Habis" << endl;
                tanyaUlang:
                cout << "Mau pilih barang lain? [y/n] : ";
                cin >> pilihUlang;
                if (pilihUlang == 'Y' || pilihUlang == 'y') {
                    system("cls");
                    goto muatUlang;
                } else if (pilihUlang == 'N' || pilihUlang == 'n') {
                    system("cls");
                    return;
                } else {
                    goto tanyaUlang;
                }
            } else if (item[it].stok < stok) {
                cout << "Stok kurang!!!" << endl;
                cout << "Sisa stok dari item " << inputNama << " : " << item[it].stok << endl;
                system("pause");
                goto tanyaStok;
            }
            break;
        }
        if (it == (totalMenu + menutambahan) - 1 && (inputNama != item[it].nama)) {
            cout << "Barang tidak ditemukan" << endl;
            system("pause");
            system("cls");
            goto muatUlang;
        }
    }
}

// Angelina Sekar Ayu (672022240)
void menuTotal() {
    cout << "Total Keseluruhan" << endl;
    if (count < 1) {
        cout << "Keranjang Kosong!" << endl;
        cout << "\nPress any key to go back" << endl;
        _getch();
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << pembeli.item[i].nama << " , " << pembeli.item[i].stok << ", " << fixed << setprecision(3) << pembeli.item[i].harga << endl;
        cout << "Total Harga : " << fixed << setprecision(3) << (pembeli.item[i].stok * pembeli.item[i].harga) << endl;
        pembeli.totalHarga += pembeli.item[i].stok * pembeli.item[i].harga;
    }

    cout << "Grand Total: " << fixed << setprecision(3) << pembeli.totalHarga << endl << endl;
    cout << "\nPress any key to go back" << endl;
    _getch();
}

int main() {
    // Rest of your code remains the same
    // ...
    return 0;
}
