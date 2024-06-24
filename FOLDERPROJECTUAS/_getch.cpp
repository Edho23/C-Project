#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa
{
    string nbi;
    string nama;
    string alamat;
    string jkelamin;
    string tgl_lahir;
    string umur;
};

int main()
{

    int pilihanMenu;
    int jumlahMahasiswa = 0;

    Mahasiswa dataMhs[10];

    do
    { 
        cout << "+-----------------------------------------------------+" << endl;
        cout << "| Menu:                                              |" << endl;
        cout << "| 1. Tambahkan mahasiswa                             |" << endl;
        cout << "| 2. Ubah data mahasiswa                             |" << endl;
        cout << "| 3. Tampilkan data mahasiswa                        |" << endl;
        cout << "| 4. Hapus data mahasiswa                            |" << endl;
        cout << "| 0. Keluar                                          |" << endl;
        cout << "+-----------------------------------------------------+" << endl;
        cout << "| Pilih menu: ";
        cin >> pilihanMenu;

        switch (pilihanMenu)
        {
        case 1:
        {
            cout << "Masukkan NBI: ";
            cin >> dataMhs[jumlahMahasiswa].nbi;
            cout << "Masukkan Nama: ";
            cin >> dataMhs[jumlahMahasiswa].nama;
            cout << "Masukkan Alamat: ";
            cin >> dataMhs[jumlahMahasiswa].alamat;
            cout << "Masukkan Jenis Kelamin: ";
            cin >> dataMhs[jumlahMahasiswa].jkelamin;
            cout << "Masukkan Tanggal Lahir: ";
            cin >> dataMhs[jumlahMahasiswa].tgl_lahir;
            cout << "Masukkan Umur: ";
            cin >> dataMhs[jumlahMahasiswa].umur;
            jumlahMahasiswa++;
            cout << "Mahasiswa berhasil ditambahkan.\n";
            break;
        }
        case 2:
        {
            string nbiInput;
            cout << "Masukkan NBI mahasiswa yang ingin diubah: ";
            cin >> nbiInput;
            bool ditemukan = false;
            for (int i = 0; i < jumlahMahasiswa; ++i)
            {
                if (dataMhs[i].nbi == nbiInput)
                {
                    cout << "Masukkan NBI baru: ";
                    cin >> dataMhs[i].nbi;
                    cout << "Masukkan Nama baru: ";
                    cin >> dataMhs[i].nama;
                    cout << "Masukkan Alamat baru: ";
                    cin >> dataMhs[i].alamat;
                    cout << "Masukkan Jenis Kelamin baru: ";
                    cin >> dataMhs[i].jkelamin;
                    cout << "Masukkan Tanggal Lahir baru: ";
                    cin >> dataMhs[i].tgl_lahir;
                    cout << "Masukkan Umur baru: ";
                    cin >> dataMhs[i].umur;
                    ditemukan = true;
                    cout << "Data mahasiswa berhasil diubah.\n";
                    break;
                }
            }
            if (!ditemukan)
            {
                cout << "NBI tidak ditemukan.\n";
            }
            break;
        }
        case 3:
        {
            for (int i = 0; i < jumlahMahasiswa; ++i)
            {
                cout << "NBI: " << dataMhs[i].nbi << endl;
                cout << "Nama: " << dataMhs[i].nama << endl;
                cout << "Alamat: " << dataMhs[i].alamat << endl;
                cout << "Jenis Kelamin: " << dataMhs[i].jkelamin << endl;
                cout << "Tanggal Lahir: " << dataMhs[i].tgl_lahir << endl;
                cout << "Umur       : " << dataMhs[i].umur << endl;
                cout << "------------------------\n";
            }
            cout << "Tidak ada data Mahasiswa" << endl << endl;
            break;
        }
        case 4:
        {
            string nbiInput;
            cout << "Masukkan NBI mahasiswa yang ingin dihapus: ";
            cin >> nbiInput;
            bool ditemukan = false;
            for (int i = 0; i < jumlahMahasiswa; ++i)
            {
                if (dataMhs[i].nbi == nbiInput)
                {
                    for (int j = i; j < jumlahMahasiswa - 1; ++j)
                    {
                        dataMhs[j] = dataMhs[j + 1];
                    }
                    jumlahMahasiswa--;
                    cout << "Data mahasiswa berhasil dihapus.\n";
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan)
            {
                cout << "NBI tidak ditemukan.\n";
            }
            break;
        }
        case 0:
        {
            cout << "Keluar dari program...\n";
            break;
        }
        default:
        {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            break;
        }
        }
    } while (pilihanMenu != 0);

    return 0;
}
