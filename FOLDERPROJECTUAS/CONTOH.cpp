#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Barang {
    int kode;
    string nama;
    int stok;
    float harga;
};

class AplikasiGudang {
private:
    vector<Barang> gudang;

public:
    void tambahBarang() {
        Barang barang;
        cout << "Masukkan Kode Barang: ";
        cin >> barang.kode;

        cout << "Masukkan Nama Barang: ";
        cin.ignore();
        getline(cin, barang.nama);

        cout << "Masukkan Stok Barang: ";
        cin >> barang.stok;

        cout << "Masukkan Harga Barang: ";
        cin >> barang.harga;

        gudang.push_back(barang);
        cout << "Barang berhasil ditambahkan!" << endl;
    }

    void tampilkanGudang() {
        if (gudang.empty()) {
            cout << "Gudang kosong." << endl;
        } else {
            cout << "===================================" << endl;
            cout << "| Kode | Nama Barang | Stok | Harga |" << endl;
            cout << "===================================" << endl;

            for (const auto& barang : gudang) {
                cout << "| " << barang.kode << "    | " << barang.nama << "  | "
                     << barang.stok << "   | " << barang.harga << "    |" << endl;
            }

            cout << "===================================" << endl;
        }
    }

    void cariBarang() {
        int kodeCari;
        cout << "Masukkan Kode Barang yang dicari: ";
        cin >> kodeCari;

        auto iter = find_if(gudang.begin(), gudang.end(), [kodeCari](const Barang& b) {
            return b.kode == kodeCari;
        });

        if (iter != gudang.end()) {
            cout << "Barang ditemukan:" << endl;
            cout << "Kode: " << iter->kode << ", Nama: " << iter->nama
                 << ", Stok: " << iter->stok << ", Harga: " << iter->harga << endl;
        } else {
            cout << "Barang tidak ditemukan." << endl;
        }
    }

    void hapusBarang() {
        int kodeHapus;
        cout << "Masukkan Kode Barang yang akan dihapus: ";
        cin >> kodeHapus;

        auto iter = find_if(gudang.begin(), gudang.end(), [kodeHapus](const Barang& b) {
            return b.kode == kodeHapus;
        });

        if (iter != gudang.end()) {
            gudang.erase(iter);
            cout << "Barang berhasil dihapus!" << endl;
        } else {
            cout << "Barang tidak ditemukan." << endl;
        }
    }

    void editBarang() {
        int kodeEdit;
        cout << "Masukkan Kode Barang yang akan diedit: ";
        cin >> kodeEdit;

        auto iter = find_if(gudang.begin(), gudang.end(), [kodeEdit](const Barang& b) {
            return b.kode == kodeEdit;
        });

        if (iter != gudang.end()) {
            cout << "Masukkan data baru:" << endl;
            cout << "Nama Barang: ";
            cin.ignore();
            getline(cin, iter->nama);

            cout << "Stok Barang: ";
            cin >> iter->stok;

            cout << "Harga Barang: ";
            cin >> iter->harga;

            cout << "Barang berhasil diedit!" << endl;
        } else {
            cout << "Barang tidak ditemukan." << endl;
        }
    }
};

int main() {
    AplikasiGudang aplikasi;
    int pilihan;

    do {
        cout << "=========== APLIKASI GUDANG ============" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Tampilkan Gudang" << endl;
        cout << "3. Cari Barang" << endl;
        cout << "4. Hapus Barang" << endl;
        cout << "5. Edit Barang" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu (0-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                aplikasi.tambahBarang();
                break;
            case 2:
                aplikasi.tampilkanGudang();
                break;
            case 3:
                aplikasi.cariBarang();
                break;
            case 4:
                aplikasi.hapusBarang();
                break;
            case 5:
                aplikasi.editBarang();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);

    return 0;
}
