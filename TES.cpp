#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Nasabah {
    int rekening;
    int saldo;
    int pin;
    string nama;
};

struct Admin {
    string namaAdmin;
    string pinAdmin;
    string rekeningAdmin;
};

int main() {
    const int jumlahNasabah = 20;
    vector<Nasabah> nasabah(jumlahNasabah);
    vector<Nasabah> daftarAkunPendaftar;
    Admin admin;

    admin.pinAdmin = "1111";
    admin.namaAdmin = "Agustino Edward Hartono";
    admin.rekeningAdmin = "121212";
    nasabah[0].nama = "Alif";
    nasabah[0].rekening = 1462301;
    nasabah[0].pin = 1234;
    nasabah[1].nama = "Fuad";
    nasabah[1].rekening = 1462302;
    nasabah[1].pin = 2324;

    int maxTries = 3;
    bool isAdmin = false;
    bool isNasabah = false;
    bool nasabahDitemukan = false;
    int nasabahIndex =-1;
    int pilihan;

    while(true) {
        system("cls");
        cout << endl;
        cout << " Masukkan Pin Anda " << endl << endl;
        cout << "Masukkan Rekening :";
        int nomorRekening;
        cin >> nomorRekening;
        cout << "Masukkan Pin : ";
        int pin;
        cin >> pin;

        isAdmin = (pin == stoi(admin.pinAdmin));

        if(isAdmin) {
            system("cls");
            cout << endl;
            cout << " SELAMAT DATANG " << endl;
            cout << admin.namaAdmin << " (Admin) " << endl << endl;

            while(isAdmin) {
                cout << " MENU ADMIN " << endl << endl;
                cout << " 1. DAFTAR NASABAH " << endl; 
                cout << " 2. EDIT NASABAH " << endl;
                cout << " 3. HAPUS AKUN NASABAH " << endl;
                cout << " 4. KELUAR " << endl;
                cout << " 5. MASUK SEBAGAI NASABAH " << endl << endl;
                cout << " Pilih Opsi : ";
                cin >> pilihan;
                cout << endl << endl;

            }

        }
    }
}