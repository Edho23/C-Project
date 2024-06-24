#include <iostream>
#include <vector>

using namespace std;

struct Nasabah {
    int rekening;
    int pin;
    string nama;
    double saldo;
};

struct Admin {
    string namaAdmin;
    string pinAdmin;
};

int main() {
    const int jumlahNasabah = 20;
    vector<Nasabah> nasabah(jumlahNasabah);
    vector<Nasabah> daftarAkunPendaftar;
    Admin admin;

    admin.pinAdmin = "1111";
    admin.namaAdmin = "Edo";
    nasabah[0].nama = "Alif";
    nasabah[0].pin = 1234;
    nasabah[1].nama = "fuad";
    nasabah[1].pin = 2324;

    int maxTries = 3;
    bool pinFound = false;
    bool isAdmin = false;
    bool isNasabah = false;
    int nasabahIndex = -1;

    for (int tries = 1; tries <= maxTries; tries++) {
        cout << "====== MASUK ======" << endl << endl;
        cout << "Masukkan PIN : ";
        int pin;
        cin >> pin;

        if (pin == stoi(admin.pinAdmin)) {
            pinFound = true;
            isAdmin = true;
            cout << "Selamat Datang " << admin.namaAdmin << " (Admin)" << endl;

            while (true) {
                cout << "MENU ADMIN" << endl << endl;
                cout << "1. Daftarkan Nasabah" << endl;
                cout << "2. Edit Nasabah" << endl;
                cout << "3. Hapus Akun Nasabah" << endl;
                cout << "4. Keluar" << endl;
                cout << "Pilih opsi : ";
                int pilihan;
                cin >> pilihan;

                switch (pilihan) {
                    case 1: {
                        Nasabah akun;
                        cout << "Masukkan Nama Pendaftar : ";
                        cin >> akun.nama;
                        cout << "Masukkan PIN Pendaftar : ";
                        cin >> akun.pin;
                        cout << "Masukkan Saldo Awal Nasabah : Rp.";
                        cin >> akun.saldo;
                        daftarAkunPendaftar.push_back(akun);
                        cout << "Akun Berhasil Ditambahkan." << endl;
                        break;
                    }

                    case 2: {
                        int nomorAkunDiedit;
                        cout << "Masukkan nomor akun yang akan diedit: ";
                        cin >> nomorAkunDiedit;

                        if (nomorAkunDiedit >= 0 && nomorAkunDiedit < daftarAkunPendaftar.size()) {
                            Nasabah& akun = daftarAkunPendaftar[nomorAkunDiedit];
                            cout << "Masukkan nama baru: ";
                            cin >> akun.nama;
                            cout << "Masukkan PIN baru: ";
                            cin >> akun.pin;
                            cout << "Masukkan saldo baru: Rp.";
                            cin >> akun.saldo;
                            cout << "Akun nasabah telah diubah." << endl;
                        } else {
                            cout << "Nomor akun tidak valid." << endl;
                        }

                        break;
                    }

                    case 3: {
                        int nomorAkunDihapus;
                        cout << "Masukkan nomor akun yang akan dihapus: ";
                        cin >> nomorAkunDihapus;

                        if (nomorAkunDihapus >= 0 && nomorAkunDihapus < daftarAkunPendaftar.size()) {
                            daftarAkunPendaftar.erase(daftarAkunPendaftar.begin() + nomorAkunDihapus);
                            cout << "Akun nasabah telah dihapus." << endl;
                        } else {
                            cout << "Nomor akun tidak valid." << endl;
                        }

                        break;
                    }

                    case 4:
                        cout << "Keluar dari akun admin." << endl;
                        isAdmin = false;
                        break;

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
            cout << "PIN salah. Silakanulang." << endl;
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
        cout << "Selamat Datang " << nasabah[nasabahIndex].nama << endl;

        while (true) {
            cout << "==========MENU NASABAH==========" << endl << endl;
            cout << "1. Cek Saldo" << endl;
            cout << "2. Tarik Tunai" << endl;
            cout << "3. Setor Tunai" << endl;
            cout << "4. Transfer" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilih opsi : ";
            int pilihan;
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    cout << "Saldo Anda adalah Rp." << nasabah[nasabahIndex].saldo << endl;
                    break;

                case 2: {
                    double jumlahTarik;
                    cout << "Masukkan jumlah yang akan ditarik: Rp.";
                    cin >> jumlahTarik;

                    if (jumlahTarik <= nasabah[nasabahIndex].saldo) {
                        nasabah[nasabahIndex].saldo -= jumlahTarik;
                        cout << "Penarikan berhasil. Saldo Anda sekarang adalah Rp." << nasabah[nasabahIndex].saldo << endl;
                    } else {
                        cout << "Saldo tidak mencukupi." << endl;
                    }

                    break;
                }

                case 3: {
                    double jumlahSetor;
                    cout << "Masukkan jumlah yang akan disetor: Rp.";
                    cin >> jumlahSetor;
                    nasabah[nasabahIndex].saldo += jumlahSetor;
                    cout << "Setor tunai berhasil. Saldo Anda sekarang adalah Rp." << nasabah[nasabahIndex].saldo << endl << endl ;
                    break;
                }

                case 4: {
                    int nomorAkunTujuan;
                    double jumlahTransfer;
                    cout << "Masukkan nomor akun tujuan: ";
                    cin >> nomorAkunTujuan;

                    if (nomorAkunTujuan >= 0 && nomorAkunTujuan < jumlahNasabah) {
                        cout << "Masukkan jumlah yang akan ditransfer: Rp.";
                        cin >> jumlahTransfer;

                        if (jumlahTransfer <= nasabah[nasabahIndex].saldo) {
                            nasabah[nasabahIndex].saldo -= jumlahTransfer;
                            nasabah[nomorAkunTujuan].saldo += jumlahTransfer;
                            cout << "Transfer berhasil. Saldo Anda sekarang adalah Rp." << nasabah[nasabahIndex].saldo << endl;
                        } else {
                            cout << "Saldo tidak mencukupi." << endl;
                        }
                    } else {
                        cout << "Nomor akun tujuan tidak valid." << endl;
                    }

                    break;
                }

                case 5:
                    cout << "Keluar dari akun nasabah." << endl;
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