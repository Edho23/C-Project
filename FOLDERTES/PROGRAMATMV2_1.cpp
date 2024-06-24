#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Nasabah {
    int nasabah;
    int nomorRekening;
    int pin;
    string nama;
    double saldo;
};

struct Pendaftar {
    string daftarnama;
    int daftarpin;
    int pendaftar;
    int nomorRekening;
    double saldo;
};

void tampilkanInformasiPendaftar(const Pendaftar& pendaftar) { 
    cout << "Nomor Rekening: " << pendaftar.nomorRekening << endl;
    cout << "Nama: " << pendaftar.daftarnama << endl;
    cout << "Saldo: Rp." << pendaftar.saldo << endl;
}

int main() {
    string namaPendaftar;
    int pinPendaftar;

    const int jumlahNasabah = 20;
    Pendaftar pendaftar[jumlahNasabah];
    Nasabah nasabah[jumlahNasabah];
    for (int i = 0; i < 20; i++) {
        cout << "Daftarkan Nama Anda : ";
        cin >> pendaftar[i].daftarnama;
        cout << "Selamat Datang " << pendaftar[i].daftarnama << ". Nama Anda Berhasil Di-daftarkan " << endl;
        cout << "Daftarkan PIN Anda : ";
        cin >> pendaftar[i].daftarpin;
        cout << "PIN Berhasil Di-daftarkan. Harap diingat dengan baik PIN Anda." << endl;
        break;
    }

    string daftarnama;
    string nama;
    int daftarpin;
    int pin;
    int maxTries = 3;
    bool pinFound = false;

    for (int tries = 1; tries <= maxTries; tries++) {
        cout << "Masukkan PIN Anda: ";
        cin >> pin;

        for (int i = 0; i < 4; i++) {
            if (pendaftar[i].daftarpin == pin) {
                pinFound = true;
                cout << "PIN ditemukan!" << endl;
                cout << "Selamat Datang, " << pendaftar[i].daftarnama << endl;

                // Menu ATM
                while (true) {
                    cout << "Menu ATM:" << endl;
                    cout << "1. Cek Saldo" << endl;
                    cout << "2. Setor" << endl;
                    cout << "3. Tarik Dana" << endl;
                    cout << "4. Keluar" << endl;
                    int choice;
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            tampilkanInformasiPendaftar(pendaftar[i]);
                            break;
                        case 2:
                            double setoran;
                            cout << "Masukkan jumlah yang akan disetor: Rp. ";
                            cin >> setoran;
                            pendaftar[i].saldo += setoran;
                            cout << "Saldo berhasil disetor." << endl;
                            break;
                        case 3:
                            double penarikan;
                            cout << "Masukkan jumlah yang akan ditarik: Rp. ";
                            cin >> penarikan;
                            if (penarikan <= pendaftar[i].saldo) {
                                pendaftar[i].saldo -= penarikan;
                                cout << "Penarikan berhasil." << endl;
                            } else {
                                cout << "Saldo tidak mencukupi." << endl;
                            }
                            break;
                        case 4:
                            cout << "Terima kasih. Sampai jumpa!" << endl;
                            exit(0);
                        default:
                            cout << "Pilihan tidak valid." << endl;
                            break;
                    }
                }
            }
        }

        if (pinFound) {
            break;
        } else {
            cout << "PIN salah. Sisa percobaan: " << maxTries - tries << endl;
        }
    }

    if (!pinFound) {
        cout << "Anda telah melebihi batas percobaan. Kartu Anda Telah Di-Blokir." << endl;
    }

    return 0;
}
