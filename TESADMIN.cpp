#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Nasabah {
    int rekening;
    int pin;
    string nama;
    int saldo;
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
    admin.namaAdmin = "Edo";
    admin.rekeningAdmin = "131313";
    nasabah[0].nama = "Alif";
    nasabah[0].pin = 1234;
    nasabah[0].rekening = 1462301;
    nasabah[1].nama = "fuad";
    nasabah[1].pin = 2324;
    nasabah[1].rekening = 1462302;

    int maxTries = 3;
    bool pinFound = false;
    bool isAdmin = false;
    bool isNasabah = false;
    bool rekeningFound = false;
    int nasabahIndex = -1;


    for (int tries = 1; tries <= maxTries; tries++) {
        cout << "====== MASUK ======" << endl << endl;
        cout << "Masukkan Nomor Rekening: ";
        int nomorRekening;
        cin >> nomorRekening;
        cout << "Masukkan PIN : ";
        int pin;
        cin >> pin;

        if (pin == stoi(admin.pinAdmin)) {
            pinFound = true;
            isAdmin = true;
            cout << endl << endl;
            cout << "Selamat Datang " << admin.namaAdmin << " (Admin)" << endl << endl;

            while (true) {
                cout << "MENU ADMIN" << endl << endl;
                cout << "1. Daftarkan Nasabah" << endl;
                cout << "2. Edit Nasabah" << endl;
                cout << "3. Hapus Akun Nasabah" << endl;
                cout << "4. Keluar" << endl;
                cout << "5. Masuk Sebagai Nasabah" << endl << endl;
                cout << "Pilih opsi : ";
                int pilihan;
                cin >> pilihan;
                cout << endl << endl;

                switch (pilihan) {
                    case 1: {
                    	system("cls");
                        Nasabah akun;
                        cout << "-- REGISTRASI NASABAH --" << endl << endl;
                        cout << "Masukkan Nama Pendaftar : ";
                        cin >> akun.nama;
                        cout << "Masukkan PIN Pendaftar : ";
                        cin >> akun.pin;
                        cout << "Masukkan Nomor Rekening : ";
                        cin >> akun.rekening;
                        cout << "Masukkan Saldo Awal Nasabah : Rp.";
                        cin >> akun.saldo;
                        daftarAkunPendaftar.push_back(akun);
                        nasabah.push_back(akun);
                        cout << "Akun Berhasil Ditambahkan." << endl << endl;
                        break;
                    }

                    case 2: {
                        int rekeningDiedit;
                        system("cls");
                        cout << "===== EDIT NASABAH =====" << endl << endl;
                        cout << "Masukkan nomor rekening nasabah yang akan diedit: ";
                        cin >> rekeningDiedit;

                        bool nasabahDitemukan = false;
                        for (size_t i = 0; i < nasabah.size(); i++) {
                        if (nasabah[i].rekening == rekeningDiedit) {
                        cout << "Masukkan nama baru: ";
                        cin >> nasabah[i].nama;
                        cout << "Masukkan PIN baru: ";
                        cin >> nasabah[i].pin;
                        cout << "Masukkan saldo baru: Rp.";
                        cin >> nasabah[i].saldo;
                        cout << "Akun nasabah telah diubah." << endl << endl;
                        nasabahDitemukan = true;
                    break;
        }
    }

    if (!nasabahDitemukan) {
        cout << "Rekening nasabah tidak ditemukan." << endl;
    }
    break;
}


                case 3: {
                    int rekeningDihapus;
                    system("cls");
                    cout << "===== HAPUS NASABAH =====" << endl << endl;
                    cout << "Masukkan nomor rekening nasabah yang akan dihapus: ";
                    cin >> rekeningDihapus;

                    bool nasabahDitemukan = false;
                    for (size_t i = 0; i < nasabah.size(); i++) {
                    if (nasabah[i].rekening == rekeningDihapus) {
                    nasabah.erase(nasabah.begin() + i);
                    cout << "Akun nasabah telah dihapus." << endl << endl;
                    nasabahDitemukan = true;
                break;
        }
    }

                 if (!nasabahDitemukan) {
                 cout << "Rekening nasabah tidak ditemukan." << endl;
                 }
               break;
}


                    case 4:
                        system("cls");
                        cout << "Keluar dari akun admin." << endl;
                        isAdmin = false;
                        break;


                    case 5: {
                        system("cls");
                        cout << "Masuk Sebagai Nasabah" << endl << endl;
                        cout << "Masukkan nomor rekening: ";
                        int nomorRekening;
                        cin >> nomorRekening;

                        bool nasabahDitemukan = false;
                        for (size_t i = 0; i < nasabah.size(); i++) {
                              if (nasabah[i].rekening == nomorRekening) {
                              nasabahIndex = i;
                              nasabahDitemukan = true;
                              break;
                          }
                      }

                        if (nasabahDitemukan) {
                            cout << "Masukkan PIN : ";
                            int pinNasabah;
                            cin >> pinNasabah;

                       if (nasabah[nasabahIndex].pin == pinNasabah) {
                            isAdmin = false;
                            isNasabah = true;
                            break;
                          } else {
                            cout << "PIN salah." << endl;
                         }
                          } else {
                        cout << "Nomor rekening tidak ditemukan." << endl;
                       }

                       break;
                    }

                    default:
                        cout << "Pilihan tidak valid." << endl;
                        break;
                }

                if (!isAdmin) {
                    break;
                }
            }

            break;
        }

        for (int i = 0; i < jumlahNasabah; ++i) {
            if (pin == nasabah[i].pin) {
                pinFound = true;
                isNasabah = true;
                nasabahIndex = i;
                break;
            }
        }

        if (pinFound) {
            break;
        }

        if (tries < maxTries) {
            cout << "PIN salah. Silakan ulang." << endl;
        } else {
            cout << "Anda telah memasukkan PIN salah sebanyak 3 kali. Akun Anda telah diblokir." << endl;
        }
    }

    if (isAdmin) {
        return 0;
    }

    if (!pinFound) {
        cout << "PIN tidak ditemukan. Akun tidak terdaftar." << endl;
        return 0;
    }

    if (isNasabah) {
        system("cls");
        cout << endl;
        cout << "=========SELAMAT DATANG=========" << endl << endl;
        cout << (nasabah[nasabahIndex].nama) << endl;
        cout << endl;

        while (true) {
            cout << "==========MENU NASABAH==========" << endl << endl;
            cout << "1. Cek Saldo" << endl;
            cout << "2. Tarik Tunai" << endl;
            cout << "3. Setor Tunai" << endl;
            cout << "4. Transfer" << endl;
            cout << "5. Menu Admin" << endl;
            cout << "6. Keluar" << endl << endl;
            cout << "Pilih opsi : ";
            int pilihan;
            cin >> pilihan;
            cout << endl << endl;

            switch (pilihan) {
                case 1:
                	system("cls");
                    cout << "Nomor Rekening : " << nasabah[nasabahIndex].rekening << endl;
                    cout << "Nama : " << nasabah[nasabahIndex].nama << endl;
                    cout << "Saldo Anda adalah Rp." << nasabah[nasabahIndex].saldo << endl << endl;
                    break;

                case 2: {
                	system("cls");
                    double jumlahTarik;
                    cout << "===== TARIK TUNAI =====" << endl;
                    cout << "Masukkan jumlah yang akan ditarik: Rp.";
                    cin >> jumlahTarik;

                    if (jumlahTarik <= nasabah[nasabahIndex].saldo) {
                        nasabah[nasabahIndex].saldo -= jumlahTarik;
                        cout << "Penarikan berhasil. Saldo Anda sekarang adalah Rp." << nasabah[nasabahIndex].saldo << endl;
                    } else {
                        cout << "Saldo tidak mencukupi." << endl << endl;
                    }
                    break;
                }

                case 3: {
                	system("cls");
                    double jumlahSetor;
                    cout << "===== SETOR TUNAI =====" << endl;
                    cout << "Masukkan jumlah yang akan disetor: Rp.";
                    cin >> jumlahSetor;
                    nasabah[nasabahIndex].saldo += jumlahSetor;
                    cout << "Setor tunai berhasil. Saldo Anda sekarang adalah Rp." << nasabah[nasabahIndex].saldo << endl << endl;
                    break;
                }

                case 4: {
                	system("cls");
                    int rekeningTujuan;
                    bool rekeningValid = false;
                    double nominalTransfer;

                    cout << "===== TRANSFER =====" << endl;
                    cout << "Masukkan nomor rekening: ";
                    cin >> rekeningTujuan;


                    for (int j = 0; j < jumlahNasabah; j++) {
                        if (nasabah[j].rekening == rekeningTujuan) {
                            rekeningValid = true;
                            break;
                        }
                    }

                    if (!rekeningValid) {
                        cout << "Rekening Tujuan Tidak Ditemukan.." << endl << endl;
                        break;
                    }

                    int nasabahPengirimIndex = nasabahIndex;
                    int nasabahPenerimaIndex = -1;


                    for (int j = 0; j < jumlahNasabah; j++) {
                        if (nasabah[j].rekening == rekeningTujuan) {
                            nasabahPenerimaIndex = j;
                            break;
                        }
                    }

                    cout <<"Masukan jumlah nominal: Rp. ";
                    cin >> nominalTransfer;



                    if (nominalTransfer > 0 && nominalTransfer <= nasabah[nasabahPengirimIndex].saldo) {
                        nasabah[nasabahPengirimIndex].saldo -= nominalTransfer;
                        nasabah[nasabahPenerimaIndex].saldo += nominalTransfer;
                        cout << "Transfer Berhasil. Saldo Anda Kini: Rp." << nasabah[nasabahPengirimIndex].saldo << endl << endl;
                    } else {
                        cout << "Saldo Anda Tidak Cukup" << endl << endl;
                    }
                    break;
                }

                case 5: {
                system("cls");
                isNasabah = false;
                isAdmin = false;
                break;
                }

                case 6:
                    cout << "Terima Kasih Telah Menggunakan Layanan Kami." << endl;
                    isNasabah = false;
                    break;


                default:
                    cout << "Pilihan tidak valid." << endl;
                    break;
            }

            if (!isNasabah) {
                break;
            }
        }
    }

   return 0;
}
