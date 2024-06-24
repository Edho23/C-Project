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

int main() {
    system("COLOR 1F");
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
    bool isAdmin = false;
    bool isNasabah = false;
    int nasabahIndex = -1;

    while (true) {
        cout << endl;
        cout << "    ======== MASUKKAN PIN ANDA ========" << endl << endl;
        cout << "\n   Masukkan Nomor Rekening: ";
        int nomorRekening;
        cin >> nomorRekening;
        cout << "\n   Masukkan PIN : ";
        int pin;
        cin >> pin;
        system("cls");

        isAdmin = (pin == stoi(admin.pinAdmin));

        if (isAdmin) {
            menuAdmin(nasabah, daftarAkunPendaftar, admin);
        } else {
            for (int i = 0; i < jumlahNasabah; ++i) {
                if (pin == nasabah[i].pin) {
                    nasabahIndex = i;
                    break;
                }
            }

            if (nasabahIndex >= 0) {
                menuNasabah(nasabah, nasabahIndex);
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


void menuAdmin(vector<Nasabah> &nasabah, vector<Nasabah> &daftarAkunPendaftar, Admin &admin) {
    int pilihan;
    int nasabahIndex = -1;
    while (true) {
        cout << " SELAMAT DATANG " << admin.namaAdmin << " (Admin)" << endl << endl;
        cout << " MENU ADMIN" << endl << endl;
        cout << " 1. Daftarkan Nasabah" << endl;
        cout << " 2. Edit Nasabah" << endl;
        cout << " 3. Hapus Akun Nasabah" << endl;
        cout << " 4. Keluar" << endl;
        cout << " 5. Masuk Sebagai Nasabah" << endl;
        cout << " Pilih opsi : ";
        cin >> pilihan;
        cout << endl << endl;

        switch (pilihan) {
            case 1:
                daftarkanNasabah(nasabah, daftarAkunPendaftar);
                break;
            case 2:
                editNasabah(nasabah);
                break;
            case 3:
                hapusNasabah(nasabah);
                break;
            case 4:
                cout << "Keluar dari akun admin." << endl;
                exit(0);
                break;
            case 5:
                masukSebagaiNasabah(nasabah, nasabahIndex);
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }
}

void daftarkanNasabah(vector<Nasabah> &nasabah, vector<Nasabah> &daftarAkunPendaftar) {
    system("cls");
   Nasabah akun;
   cout << "   ===== REGISTRASI NASABAH =====" << endl << endl;
   cout << " Masukkan Nama Pendaftar : ";
   cin >> akun.nama;
   cout << " Masukkan PIN Pendaftar : ";
   cin >> akun.pin;
   cout << " Masukkan Nomor Rekening : ";
   cin >> akun.rekening;
   cout << " Masukkan Saldo Awal Nasabah : Rp.";
   cin >> akun.saldo;
   daftarAkunPendaftar.push_back(akun);
   nasabah.push_back(akun);
   cout << " Akun Berhasil Ditambahkan." << endl << endl;


}

void editNasabah(vector<Nasabah> &nasabah) {
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

        }
      }

       if (!nasabahDitemukan) {
        cout << "Rekening nasabah tidak ditemukan." << endl;
      }

     }


void hapusNasabah(vector<Nasabah> &nasabah) {
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

}


void menuNasabah(vector<Nasabah> &nasabah, int &nasabahIndex) {
    int pilihan;
    Admin admin;

    cout << endl;
    cout << "=========SELAMAT DATANG=========" << endl << endl;
    cout << nasabah[nasabahIndex].nama << endl;
    cout << endl;
      
    while (true){  
    cout << "==========MENU NASABAH==========" << endl << endl;
    cout << "1. Cek Saldo" << endl;
    cout << "2. Tarik Tunai" << endl;
    cout << "3. Setor Tunai" << endl;
    cout << "4. Transfer" << endl;
    cout << "5. Logout" << endl << endl;
    cout << "Pilih opsi : ";
    cin >> pilihan;
    cout << endl << endl;

        switch (pilihan) {
            case 1:
            cekSaldo(nasabah, nasabahIndex);
            break;

            case 2:
            tarikTunai(nasabah, nasabahIndex);
            break;

            case 3:
            setorTunai(nasabah, nasabahIndex);
            break;

            case 4:
            tarikTunai(nasabah, nasabahIndex);
            break;

            case 5:
            masukkanRekeningDanPin(nasabah, nasabahIndex, admin);
            break;
        }
    }
}

void cekSaldo(vector<Nasabah> &nasabah, int nasabahIndex) {
    system("cls");
    cout << "===== INFO =====" << endl;
    cout << "Nomor Rekening : " << nasabah[nasabahIndex].rekening << endl;
    cout << "Nama : " << nasabah[nasabahIndex].nama << endl;
    cout << "Saldo Anda adalah Rp." << nasabah[nasabahIndex].saldo << endl << endl;


}

void tarikTunai(vector<Nasabah> &nasabah, int nasabahIndex) {
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

}

void setorTunai(vector<Nasabah> &nasabah, int nasabahIndex) {
    system("cls");
     double jumlahSetor;
     cout << "===== SETOR TUNAI =====" << endl;
     cout << "Masukkan jumlah yang akan disetor: Rp.";
     cin >> jumlahSetor;
     nasabah[nasabahIndex].saldo += jumlahSetor;
     cout << "Setor tunai berhasil. Saldo Anda sekarang adalah Rp." << nasabah[nasabahIndex].saldo << endl << endl;

}

void transfer(vector<Nasabah> &nasabah, int nasabahIndex) {
    system("cls");
    int rekeningTujuan;
    bool rekeningValid = false;
    double nominalTransfer;

    cout << "===== TRANSFER =====" << endl;
    cout << "Masukkan nomor rekening: ";
    cin >> rekeningTujuan;

    for (int j = 0; j <20; j++) {
     if (nasabah[j].rekening == rekeningTujuan) {
        rekeningValid = true;

     }
 }

    if (!rekeningValid) {
    cout << "Rekening Tujuan Tidak Ditemukan.." << endl << endl;

    }

    int nasabahPengirimIndex = nasabahIndex;
    int nasabahPenerimaIndex = -1;

    for (int j = 0; j <20; j++) {
     if (nasabah[j].rekening == rekeningTujuan) {
     nasabahPenerimaIndex = j;

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

}

void masukSebagaiNasabah(vector<Nasabah> &nasabah, int &nasabahIndex) {
    system("cls");
    cout << "Masuk Sebagai Nasabah" << endl << endl;
    cout << "Masukkan nomor rekening: ";
    int nomorRekening;
    cin >> nomorRekening;

    bool isAdmin = false;
    bool isNasabah = false;
    bool nasabahDitemukan = false;

    for (size_t i = 0; i < nasabah.size(); i++) {
        if (nasabah[i].rekening == nomorRekening) {
            nasabahIndex = i;
            nasabahDitemukan = true;
            break;
        }
    }

    if (nasabahDitemukan) {
        cout << "Masukkan PIN: ";
        int pinNasabah;
        cin >> pinNasabah;

        if (nasabah[nasabahIndex].pin == pinNasabah) {
            isAdmin = false;
            isNasabah = true;
        } else {
            system("cls");
            cout << "PIN salah." << endl << endl;
            isAdmin = false;
        }
    } else {
        cout << "Nomor rekening tidak ditemukan." << endl;
        isAdmin = false;
    }

    if (isNasabah) {
        system("cls");
        menuNasabah(nasabah, nasabahIndex);
    }
}

void masukkanRekeningDanPin(vector<Nasabah> &nasabah, int &nasabahIndex, Admin &admin) {
    int maxTries = 3;
    bool isAdmin = false;
    vector<Nasabah> daftarAkunPendaftar;

    while (maxTries > 0) {
        system("cls");
        cout << "    ======== MASUKKAN PIN ANDA ========" << endl << endl;
        cout << "\n   Masukkan Nomor Rekening: ";
        int nomorRekening;
        cin >> nomorRekening;
        cout << "\n   Masukkan PIN : ";
        string pinStr;
        cin >> pinStr;

        try {
            int pin = stoi(pinStr); 
            isAdmin = (pin == stoi(admin.pinAdmin));

            if (isAdmin) {
                menuAdmin(nasabah, daftarAkunPendaftar, admin);
                break;
            } else {
                nasabahIndex = -1;
                for (int i = 0; i < 20; ++i) {
                    if (pin == nasabah[i].pin && nomorRekening == nasabah[i].rekening) {
                        nasabahIndex = i;
                        break;
                    }
                }

                if (nasabahIndex >= 0) {
                    menuNasabah(nasabah, nasabahIndex);
                    break;
                }

                if (maxTries == 1) {
                    cout << "Anda telah memasukkan PIN salah sebanyak 3 kali. Akun Anda telah diblokir." << endl;
                    exit(0);
                } else {
                    cout << "PIN atau Nomor Rekening salah. Silakan ulang." << endl;
                    maxTries--;
                }
            }
        } catch (const std::invalid_argument& e) {
            cout << "PIN tidak valid, Silahkan ulang." << endl;
            maxTries--;
        }
    }
}













