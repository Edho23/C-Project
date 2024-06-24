#include <iostream>
#include <string>

using namespace std;

struct nasabah {
    string nama;
    string nasabah;
    int pin;
    double saldo;
    int rekening;
    
   
} nasabah [4];

int main() {
    nasabah[4]; // Membuat array users dengan ukuran 4

    nasabah[0].nama = "Anton";
    nasabah[0].pin = 1234;
    nasabah[0].saldo = 100000.0;
    nasabah[0].rekening = 202301;

    nasabah[1].nama = "Alif";
    nasabah[1].pin = 4321;
    nasabah[1].saldo = 150000.0;
    nasabah[2].rekening = 202306;

    nasabah[2].nama = "Salim";
    nasabah[2].pin = 5678;
    nasabah[2].saldo = 200000.0;
    nasabah[2].rekening = 202303;

    nasabah[3].nama = "Abdi";
    nasabah[3].pin = 2345;
    nasabah[3].saldo = 300000.0;
    nasabah[3].rekening = 202304;

    int maxTries = 3;
    int inputPin;
    bool pinFound = false;

    for (int tries = 1; tries <= maxTries; tries++) {
        cout << "Masukkan PIN Anda: ";
        cin >> inputPin;

        for (int i = 0; i < 4; i++) {
            if (nasabah[i].pin == inputPin) {
                pinFound = true;
                cout << "PIN ditemukan!" << endl << endl;
                cout << "Selamat Datang, " << nasabah[i].nama << endl << endl;
                
                while (true) {
				
                int pilihan;
                cout << "Pilihan Menu" << endl << endl;
                cout << "1. Cek Saldo" << endl;
                cout << "2. Tarik Tunai" << endl;
                cout << "3. Transfer" << endl;
                cout << "4. Keluar" << endl<<endl;
                cout << "Masukkan Pilihan : ";
                cin >> pilihan;
                cout << endl << endl;

                bool penerimaDitemukan = true;
                int indexPenerima = -1;

                switch (pilihan) {
                    case 1:
                    	cout << "Nama : " << nasabah[i].nama << endl << endl;
                        cout << "Saldo Anda : Rp." << nasabah[i].saldo << endl<<endl;
                        continue;
                        
                        
                    

                    case 2:
                        double jumlahTarik;
                        cout << "Masukkan Nominal yang ingin Anda Tarik : Rp.";
                        cin >> jumlahTarik;
                        cout << endl;

                        if (jumlahTarik <= nasabah[i].saldo) {
                            nasabah[i].saldo -= jumlahTarik;
                            cout << "Penarikan Berhasil. Saldo Anda Kini : Rp." << nasabah[i].saldo << endl << endl;
                        } else {
                            cout << "Saldo Anda Tidak Mencukupi.." << endl<<endl;
                        }
                        continue;

                    case 3:
                        int rekeningTujuan;
                        double nominalTransfer;
                        
                            cout << "Masukkan Rekening Tujuan : ";
                            cin >> rekeningTujuan;
                        
                            for (int j = 0; j < 4; j++) {
                                if (nasabah[j].rekening == rekeningTujuan) {
                                    penerimaDitemukan = true;
                                    indexPenerima = j;
                                    break;
                                }
                            }

                            if (!penerimaDitemukan) {
                                cout << "Rekening Tujuan Tidak Ditemukan.." << endl << endl;
                            } else {
                                cout << "Masukkan Nominal : Rp.";
                                cin >> nominalTransfer;

                                if (nominalTransfer <= nasabah[i].saldo) {
                                    nasabah[i].saldo -= nominalTransfer;
                                    nasabah[indexPenerima].saldo += nominalTransfer;
                                    cout << "Transfer Berhasil. Saldo Anda Kini : Rp." << nasabah[i].saldo << endl << endl;
                                } else {
                                    cout << "Saldo Anda Tidak Cukup" << endl << endl;
                                }
                            }
                            continue;
					
                        	
                    case 4: 
                        cout << "Terima Kasih, Sampai jumpa "<<endl;
                        return 0;

                    default:
                        cout << "Pilihan Tidak Valid..." << endl<<endl;
                        continue;
                }

                break;
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
