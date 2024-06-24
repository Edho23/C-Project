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
	system("COLOR F4");
    const int jumlahNasabah = 20;
    vector<Nasabah> nasabah(jumlahNasabah);
    vector<Nasabah> daftarAkunPendaftar;
    Admin admin;

    admin.pinAdmin = "1111";
    admin.namaAdmin = "Noval Ardiansyah";
    admin.rekeningAdmin = "131313";
    nasabah[0].nama = "Alif Ubaidillah";
    nasabah[0].pin = 1234;
    nasabah[0].rekening = 1462301;
    nasabah[1].nama = "Fuad Fatmawata";
    nasabah[1].pin = 2324;
    nasabah[1].rekening = 1462302;

    int maxTries = 3;
    bool isAdmin = false;
    bool isNasabah = false;
    bool nasabahDitemukan = false;
    int nasabahIndex = -1;
    int pilihan;

    while (true) {
        cout << "====== MASUK ======" << endl << endl;
        cout << "Masukkan Nomor Rekening: ";
        int nomorRekening;
        cin >> nomorRekening;
        cout << "Masukkan PIN : ";
        int pin;
        cin >> pin;

        isAdmin = (pin == stoi(admin.pinAdmin));

        if (isAdmin) {
        	system("cls");
            cout << "--------------" << endl;
            cout << "Selamat Datang " << admin.namaAdmin << " (Admin)" << endl;
            cout << "--------------" << endl << endl;

            while (isAdmin) {
                cout << "MENU ADMIN" << endl << endl;
                cout << "1. Daftarkan Nasabah" << endl;
                cout << "2. Edit Nasabah" << endl;
                cout << "3. Hapus Akun Nasabah" << endl;
                cout << "4. Keluar" << endl;
                cout << "5. Masuk Sebagai Nasabah" << endl << endl;
                cout << "Pilih opsi : ";
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
                        cout << "==== Validasi Nasabah ====" << endl << endl;
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
                            cout << endl;

                            if (nasabah[nasabahIndex].pin == pinNasabah) {
                                isAdmin = false;
                            } else {
                                system("cls");
                                cout << "PIN salah." << endl << endl;
                                isAdmin = false;
                            }
                        } else {
                            cout << "Nomor rekening tidak ditemukan." << endl;
                            isAdmin = false;
                        }
                        break;
                    }

                    default:
                        cout << "Pilihan tidak valid." << endl;
                        break;
                }
            }
        } else {
            for (int i = 0; i < jumlahNasabah; ++i) {
                if (pin == nasabah[i].pin) {
                    nasabahIndex = i;
                    break;
                }
            }

            if (nasabahIndex >= 0) {
                system("cls");
                cout << endl;
                cout << "-------- BANKBANK -------" << endl << endl;
                cout << "========= LOBBY =========" << endl << endl;
                cout << "Selamat Datang, " << nasabah[nasabahIndex].nama << endl;
                cout << endl;

                while (true) {
                    cout << "========== MENU NASABAH ==========" << endl << endl;
                    cout << "1. Cek Saldo" << endl;
                    cout << "2. Tarik Tunai" << endl;
                    cout << "3. Setor Tunai" << endl;
                    cout << "4. Transfer" << endl;
                    cout << "5. Keluar" << endl << endl;
                    cout << "Pilih opsi : ";
                    cin >> pilihan;
                    cout << endl << endl;

                    switch (pilihan) {
                        case 1:
                            system("cls");
                            cout << "===== INFO =====" << endl << endl;
                            cout << "Nomor Rekening : " << nasabah[nasabahIndex].rekening << endl;
                            cout << "Nama : " << nasabah[nasabahIndex].nama << endl;
                            cout << "Saldo : Rp." << nasabah[nasabahIndex].saldo << endl << endl;
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
                            cout << "Masukkan nomor rekening tujuan : ";
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

                            cout << "Masukan jumlah nominal: Rp. ";
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

                        case 5: 
                        cout << "Terima Kasih Telah Menggunakan Layanan Kami..." << endl;
                        system("pause");
                        system("cls");
                        cout << "==== Masuk Sebagai Nasabah ====" << endl << endl;
                        cout << "Masukkan nomor rekening: ";
                        int nomorRekening;
                        cin >> nomorRekening;

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
                                system("cls");
                                cout << "PIN salah." << endl << endl;
                                isNasabah = false;
                                return 0;
                            }
                        } else {
                            cout << "Nomor rekening tidak ditemukan." << endl;
                        }
                        break;
                    

                        default:
                            cout << "Pilihan tidak valid." << endl;
                            break;
                    }
                }
            } else {
                if (maxTries == 0) {
                    cout << "Anda telah memasukkan PIN salah sebanyak 3 kali. Akun Anda telah diblokir." << endl;
                    break;
                } else {
                    cout << "PIN salah. Silakan ulang." << endl;
                    maxTries--;
                }
            }
        }
    }

    return 0;
}
