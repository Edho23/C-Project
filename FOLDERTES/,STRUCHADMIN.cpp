#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

struct Nasabah {
    int nomorRekening;
    int pin;
    string nama;
    float saldo;
};

struct Pendaftar {
    string daftarnama;
    int daftarpin;
    int Nasabah;
    int norekening;
    float saldo;
};

struct Admin {
    string username;
    string password;
};

struct Akunpendaftar {
    string nama;
    float saldo;

    Akunpendaftar(string _nama, float _saldo) : nama(_nama), saldo(_saldo) {}
        
        void ubahInfo(string _nama, float _saldo) {
            nama = _nama;
            saldo + _saldo;
        
    }
};


int main() {
    string namaPendaftar;
    int pinPendaftar;
    double saldo;

    const int jumlahNasabah = 20;
    Nasabah nasabah[jumlahNasabah];
    Pendaftar pendaftar[jumlahNasabah];
    vector<Pendaftar> daftarAkunPendaftar;
    Admin admin;

    for (int i = 0; i < 20; ++i) {
        daftarAkunPendaftar.push_back(Pendaftar());
        pendaftar[i].norekening = 14623001 + i;
    }

    // GAWE NGATUR PIN,USERS
    admin.username = "admin";
    admin.password = "1234";

    string daftarnama;
    string nama;
    int daftarpin;
    int pin;
    int maxTries = 3;
    bool pinFound = false;
    bool isAdmin = false;

    for (int tries = 1; tries <= maxTries; tries++) {
        cout << "======== MASUK ========" << endl << endl;
        cout << "Masukkan Username: ";
        cin >> admin.username;
        cout << "Masukkan Password: ";
        cin >> admin.password;

        if (admin.username == "admin" && admin.password == "1234") {
            isAdmin = true;
            cout << "Selamat Datang, Admin!" << endl << endl;
            break;
        } else {
            cout << "Username atau Password salah. Sisa percobaan: " << maxTries - tries << endl;
        }
    }

    if (!isAdmin) {
        cout << "Anda telah melebihi batas percobaan. Akses Admin ditolak." << endl;
        exit(0);
    }

    
    
     if (isAdmin) {
    vector<Pendaftar> daftarAkunpendaftar; 

    cout << "Admin Menu" << endl;
    cout << "1. Tambah Akun Nasabah" << endl;
    cout << "2. Hapus Akun Nasabah" << endl;
    cout << "3. Edit Akun Nasabah" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih opsi: ";
    int adminChoice;
    cin >> adminChoice;

    switch (adminChoice) {
        case 1: {
            string namaPendaftar;
            double saldo;
            cout << "Masukkan nama pendaftar: ";
            cin >> namaPendaftar;
            cout << "Masukkan saldo awal: Rp. ";
            cin >> saldo;
            Pendaftar akun;
            akun.daftarnama = namaPendaftar;
            akun.saldo = saldo;
            daftarAkunpendaftar.push_back(akun);
            cout << "Akun pendaftar telah ditambahkan" << endl;

        }
        break;

        case 2: {
            int nomorAkunDihapus;
            cout << "Masukkan nomor akun yang akan dihapus: ";
            cin >> nomorAkunDihapus;

            if (nomorAkunDihapus >= 0 && nomorAkunDihapus < daftarAkunpendaftar.size()) {
                daftarAkunpendaftar.erase(daftarAkunpendaftar.begin() + nomorAkunDihapus);
                cout << "Akun nasabah telah dihapus." << endl;
            } else {
                cout << "Nomor akun tidak valid." << endl;
            }
        }
        break;

        case 3: {
            int nomorAkunDiedit;
            cout << "Masukkan nomor akun yang akan diedit: ";
            cin >> nomorAkunDiedit;

            if (nomorAkunDiedit >= 0 && nomorAkunDiedit < daftarAkunpendaftar.size()) {
                string namaBaru;
                double saldoBaru;
                cout << "Masukkan nama baru: ";
                cin >> namaBaru;
                cout << "Masukkan saldo baru: ";
                cin >> saldoBaru;

                daftarAkunpendaftar[nomorAkunDiedit].daftarnama = namaBaru;
                daftarAkunpendaftar[nomorAkunDiedit].saldo = saldoBaru;
                cout << "Akun nasabah telah diubah." << endl;
            } else {
                cout << "Nomor akun tidak valid." << endl;
            }
        }
        break;

        case 4:
            cout << "Admin keluar." << endl;
            exit(0);
        break;

        default:
            cout << "Pilihan tidak valid." << endl;
    }
 }
 return 0;
}
