#include <iostream>
#include <vector>

using namespace std;

struct Nasabah
{
    int rekening;
    string nama;
    int saldo;
    int pin;
};

struct Admin
{
    string pinAdmin;
    string namaAdmin;
    string rekeningAdmin;
};

void menuAdmin(vector<Nasabah> &nasabah, vector<Nasabah> &daftarAkunPendaftar, Admin &admin);
void daftarkanNasabah(vector<Nasabah> &nasabah, vector<Nasabah> &daftarAkunPendaftar);
void editNasabah(vector<Nasabah> &nasabah);
void hapusNasabah(vector<Nasabah> &nasabah);
void menuNasabah(vector<Nasabah> &nasabah, int &nasabahIndex);
void cekSaldo(vector<Nasabah> &nasabah, int nasabahIndex);
void tarikTunai(vector<Nasabah> &nasabah, int nasabahIndex);
void setorTunai(vector<Nasabah> &nasabah, int nasabahIndex);
void transfer(vector<Nasabah> &nasabah, int nasabahIndex);
void masukSebagaiNasabah(vector<Nasabah> &nasabah, int &nasabahIndex);
void masukkanRekeningDanPin(vector<Nasabah> &nasabah, int &nasabahIndex, Admin &admin);

int main()
{
    Admin admin;
    Nasabah nasabah;
    const int jumlahNasabah = 20;
    vector<Nasabah> nasabah(jumlahNasabah);
    vector<Nasabah> daftarAkunPendaftar;
    Admin admin;

    int maxTries = 3;
    bool isAdmin = false;
    bool isNasabah = false;
    int nasabahIndex = -1;

    admin.pinAdmin = 1212;
    admin.namaAdmin = "Edho";
    admin.rekeningAdmin = "121212";
    nasabah.nama = "edho";
    nasabah.rekening = "131313";
    nasabah.pin = 1111;

    return 0;
}

void menuAdmin(vector<Nasabah> &nasabah, vector<Nasabah> &daftarAkunPendaftar, Admin &admin)
{
    int pilihan;
    int nasabahIndex = -1;
    cout << "SELAMAT DATANG " << endl;
    cout << "1.PENDAFTARAN NASABAH" << endl;
    cout << "2.EDIT NASABAH" << endl;
    cout << "3.HAPUS NASABAH" << endl;
    cout << "4.MASUK SEBAGAI NASABAH" << endl;
    cout << "PILIH OPSI : ";
    cin >> pilihan;
}

void daftarkanNasabah(vector<Nasabah> &nasabah, vector<Nasabah> &daftarAkunPendaftar) {
    Nasabah akun;
    cout << " =====SILAHKAN REGISTRASI===== " << endl;
    cout << "MASUKKAN NAMA ANDA : ";
    cin >> akun.nama;
    cout << "MASUKKAN NO REKENING : ";
    cin >> akun.rekening;
    cout << "MASUKKAN PIN ANDA : ";
    cin >> akun.pin;
    cout << "MASUKKAN SALDO AWAL : ";
    cin >> akun.saldo;
    daftarAkunPendaftar.push_back(akun);
    nasabah.push_back(akun);
    cout << "AKUN BERHASIL TERDAFTAR " << endl << endl;
}

void editNasabah(vector<Nasabah> &nasabah){
    int rekeningDiedit;
    cout << " ===EIDT NASABAH=== " << endl << endl;
    cout << "MASUKKAN NOMOR REKENING YANG INGIN DI GANTI : ";
    cin >> rekeningDiedit;

    for()
}