#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Struktur untuk menyimpan informasi nasabah
struct Nasabah {
    int nomorRekening;
    string nama;
    double saldo;
};

// Fungsi untuk menampilkan informasi nasabah
void tampilkanInformasiNasabah(const Nasabah& nasabah) {
    cout << "Nomor Rekening: " << nasabah.nomorRekening << endl;
    cout << "Nama: " << nasabah.nama << endl;
    cout << "Saldo: Rp." << nasabah.saldo << endl;
}

int main() {
    const int jumlahNasabah = 20;
    Nasabah daftarNasabah[jumlahNasabah];

    // Inisialisasi data nasabah secara acak
    srand(time(0));
    for (int i = 0; i < jumlahNasabah; ++i) {
        daftarNasabah[i].nomorRekening = 1000 + i;
        daftarNasabah[i].nama = "Nasabah " + to_string(i);
        daftarNasabah[i].saldo = (rand() % 1000000) + 100000; // Saldo awal antara 1000 dan 10999
    }

    int nomorRekening;
    cout << "Masukkan nomor rekening Anda: ";
    cin >> nomorRekening;

    // Cari nasabah berdasarkan nomor rekening
    int indeksNasabah = -1;
    for (int i = 0; i < jumlahNasabah; ++i) {
        if (daftarNasabah[i].nomorRekening == nomorRekening) {
            indeksNasabah = i;
            break;
        }
    }

    if (indeksNasabah != -1) {
        cout << "Selamat datang, " << daftarNasabah[indeksNasabah].nama << "!" << endl;
        while (true) {
            cout << "\nPilih operasi:\n1. Tampilkan Saldo\n2. Penarikan\n3. Setoran\n4. Keluar\n";
            int pilihan;
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    tampilkanInformasiNasabah(daftarNasabah[indeksNasabah]);
                    break;
                case 2:
                    double penarikan;
                    cout << "Masukkan jumlah yang akan ditarik: $";
                    cin >> penarikan;
                    if (penarikan <= daftarNasabah[indeksNasabah].saldo) {
                        daftarNasabah[indeksNasabah].saldo -= penarikan;
                        cout << "Penarikan berhasil." << endl;
                    } else {
                        cout << "Saldo tidak mencukupi untuk penarikan ini." << endl;
                    }
                    break;
                case 3:
                    double setoran;
                    cout << "Masukkan jumlah yang akan disetor: Rp.";
                    cin >> setoran;
                    if (setoran > 0) {
                        daftarNasabah[indeksNasabah].saldo += setoran;
                        cout << "Setoran berhasil." << endl;
                    } else {
                        cout << "Masukkan jumlah setoran yang valid." << endl;
                    }
                    break;
                case 4:
                    cout << "Terima kasih, " << daftarNasabah[indeksNasabah].nama << "!" << endl;
                    return 0;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
    } else {
        cout << "Nomor rekening tidak valid. Silakan coba lagi." << endl;
    }

    return 0;
}
