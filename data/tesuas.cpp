#define SQLITE_HAS_CODEC
#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include "sqlite3.h"

using namespace std;

struct Barang
{
    string kode;
    string nama;
    string tanggalTransaksi;
    string namaPetugas;
    int No;
    int stok;
    int Harga;
    int jumlahPembelian;
};

struct Pegawai
{
    string nama;
    string pin;
    string username;
};

struct Admin
{
    string usernameAdmin;
    string namaAdmin;
    string pinAdmin;
};

Admin admin;
Pegawai pegawai1;
vector<Pegawai> pegawais;
vector<Barang> gudang;

sqlite3 *db;

void executeSQL(const char *sql)
{
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL Error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

void openDatabase()
{
    int rc = sqlite3_open("gudang.db", &db);

    if (rc)
    {
        cerr << "Tidak dapat membuka database: " << sqlite3_errmsg(db) << endl;
        exit(0);
    }

    const char *sqlCreateTable =
        "CREATE TABLE IF NOT EXISTS barang ("
        "kode TEXT PRIMARY KEY,"
        "nama TEXT NOT NULL,"
        "stok INTEGER NOT NULL,"
        "harga INTEGER NOT NULL,"
        "jumlah_pembelian INTEGER NOT NULL,"
        "tanggal_transaksi TEXT,"
        "nama_petugas TEXT);";

    executeSQL(sqlCreateTable);
}

void closeDatabase()
{
    sqlite3_close(db);
}

// Fungsi untuk menambahkan barang ke database SQLite
void tambahBarangSQLite(Barang &barang)
{
    char sql[300];
    sprintf(sql, "INSERT INTO barang VALUES ('%s', '%s', %d, %d, %d, '%s', '%s');",
            barang.kode.c_str(), barang.nama.c_str(), barang.stok, barang.Harga, barang.jumlahPembelian,
            barang.tanggalTransaksi.c_str(), barang.namaPetugas.c_str());

    executeSQL(sql);
}

// Fungsi untuk membaca data barang dari database SQLite
void bacaDataBarangSQLite()
{
    const char *sql = "SELECT * FROM barang;";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL Error: " << sqlite3_errmsg(db) << endl;
        exit(0);
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        Barang barang;
        barang.kode = (char *)sqlite3_column_text(stmt, 0);
        barang.nama = (char *)sqlite3_column_text(stmt, 1);
        barang.stok = sqlite3_column_int(stmt, 2);
        barang.Harga = sqlite3_column_int(stmt, 3);
        barang.jumlahPembelian = sqlite3_column_int(stmt, 4);
        barang.tanggalTransaksi = (char *)sqlite3_column_text(stmt, 5);
        barang.namaPetugas = (char *)sqlite3_column_text(stmt, 6);

        gudang.push_back(barang);
    }

    sqlite3_finalize(stmt);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void panah(int pilihan, int posisi)
{
    if (pilihan == posisi)
    {
        cout << "==>";
    }
    else
    {
        cout << "   ";
    }
}

int nomorBarang;
void TambahBarang(vector<Barang> &gudang, int &nomorBarang)
{
    Barang barang;
    if (gudang.empty())
    {
        barang.No = 1;
    }
    else
    {
        barang.No = gudang.back().No + 1;
    }

    cout << "Masukkan Kode : ";
    cin >> barang.kode;

    for (Barang &b : gudang)
    {
        if (b.kode == barang.kode)
        {
            cout << "Barang denga kode" << barang.kode << "Sudah ada digudang" << endl;
            char tambahstok;
            cout << "Apakah ingin menambahkan Barang? [Y/T] : ";
            cin >> tambahstok;
            if (tambahstok == 'Y' || tambahstok == 'y')
            {
                int tambahJumlah;
                cout << "Masukkan jumlah stok : ";
                cin >> tambahJumlah;
                b.stok += tambahJumlah;
                cout << "Stok Berhasil Ditambahkan. " << endl;
            }
            return;
        }
    }

    cout << "Masukkan Nama Barang : ";
    cin >> barang.nama;

    cout << "Masukkan Stok : ";
    cin >> barang.stok;

    cout << "Harga Satuan : ";
    cin >> barang.Harga;

    barang.jumlahPembelian = 0;

    tambahBarangSQLite(barang);

    gudang.push_back(barang);
    cout << "BARANG BERHASIL DITAMBAHKAN" << endl;
}

void TampilkanGudang(const vector<Barang> &gudang)
{
    system("cls");
    gotoxy(0, 0);
    cout << "===========================================================================";
    gotoxy(0, 1);
    cout << "| No | kode | Nama Barang | Stok Barang | Harga Satuan | Jumlah Pembelian |";
    gotoxy(0, 2);
    cout << "===========================================================================";

    for (int i = 0; i < gudang.size(); i++)
    {
        gotoxy(0, 3 + i);
        cout << "| " << setw(3) << left << gudang[i].No << "| "
             << setw(4) << left << gudang[i].kode << " | "
             << setw(11) << left << gudang[i].nama << " | "
             << setw(11) << left << gudang[i].stok << " | "
             << setw(11) << left << gudang[i].Harga << "  |"
             << setw(17) << left << fixed << setprecision(2) << gudang[i].jumlahPembelian << " |";
    }

    for (int i = gudang.size() + 1; i <= 13; i++)
    {
        gotoxy(0, 2 + i);
        cout << "|    |      |             |             |              |                  |";
    }
    gotoxy(0, 15);
    cout << "===========================================================================";

    int i = 1;
    char tambahdata;

    cout << endl;

    do
    {
        gotoxy(57, 18);
        cout << "KELUAR [T] : ";
        cin >> tambahdata;
        i++;

    } while (tambahdata == 'y' || tambahdata == 'Y');
}

bool PrintStruk(vector<Barang> &gudang)
{
    Barang barang;

    system("cls");
    gotoxy(0, 0);
    cout << "GUDANG";
    gotoxy(0, 1);
    cout << "Jl.Semolowaru Utara No 34";
    gotoxy(0, 2);
    cout << "Surabaya";
    gotoxy(0, 4);
    cout << "Nama Petugas : " << pegawai1.nama;
    gotoxy(0, 5);
    cout << "=========================================================================================";
    gotoxy(0, 6);
    cout << "| No |   Kode   |   Nama Barang   |   Harga Satuan   |   Jumlah Beli   |   Total Harga  |";
    gotoxy(0, 7);
    cout << "=========================================================================================";
    for (int i = 1; i <= 12; i++)
    {
        gotoxy(0, 7 + i);
        cout << "|    |          |                 |                  |                 |                | ";
    }
    gotoxy(0, 20);
    cout << "=========================================================================================";
    gotoxy(0, 21);
    cout << "|                                                         TOTAL BAYAR|                  |";
    gotoxy(0, 22);
    cout << "|                                                               BAYAR|                  |";
    gotoxy(0, 23);
    cout << "|                                                           KEMBALIAN|                  |";
    gotoxy(0, 24);
    cout << "=========================================================================================";
    int i = 1;
    char jw;
    int totHg, totByr = 0;
    float bayar, kembali;
    do
    {
        gotoxy(2, 7 + i);
        cout << i;
        gotoxy(8, 7 + i);
        cin >> barang.kode;
        auto it = find_if(gudang.begin(), gudang.end(), [&barang](const Barang &b) {
             return b.kode == barang.kode; });

        if (it != gudang.end())
        {
            barang.nama = it->nama;
            barang.Harga = it->Harga;

            gotoxy(19, 7 + i);
            cout << barang.nama;
            gotoxy(38, 7 + i);
            cout << barang.Harga;
        }
        else
        {
            gotoxy(40, 3);
            cout << "BARANG TIDAK DITEMUKKAN";
            getch();
            break;
        }

        gotoxy(55, 7 + i);
        cin >> barang.jumlahPembelian;
        for (Barang &b : gudang)
        {
            if (b.kode == barang.kode)
            {
                b.jumlahPembelian += barang.jumlahPembelian;
            }
        }
        totHg = (barang.jumlahPembelian * barang.Harga);
        gotoxy(75, 7 + i);
        cout << totHg;
        totByr += totHg;
        gotoxy(75, 21);
        cout << totByr;

        gudang.push_back(barang);
        time_t now = time(0);
        tm *localTime = localtime(&now);
        char dateBuffer[80];
        strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", localTime);
        gudang.back().tanggalTransaksi = dateBuffer;

        gudang.back().namaPetugas = pegawai1.nama;

        gotoxy(40, 4);
        cout << "ISI DATA LAGI [Y/T] : ";
        cin >> jw;
        i++;
        gotoxy(40, 4);
        cout << "                          ";
    } while (jw == 'y' || jw == 'Y');
    do
    {
        gotoxy(75, 22);
        cin >> bayar;
        if (bayar < totByr)
        {
            gotoxy(40, 4);
            cout << "Uang Anda Kurang....";
            getch();
            gotoxy(40, 4);
            cout << "                          ";
        }
    } while (bayar < totByr);
    kembali = bayar - totByr;
    gotoxy(75, 23);
    cout << kembali;
    getch();

    char kembaliMenu;
    do
    {
        gotoxy(75, 25);
        cout << "Kembali Ke Menu? [Y/T] : ";
        cin >> kembaliMenu;
    } while (kembaliMenu != 'Y' && kembaliMenu != 'y');

    return (kembaliMenu == 'Y' || kembaliMenu == 'y');
}

void GenerateReport(const vector<Barang> &gudang)
{
    system("cls");
    cout << "=============================================================================" << endl;
    cout << "|                             LAPORAN PENJUALAN                             |" << endl;
    cout << "=============================================================================" << endl;
    cout << "|   Tanggal   |   Barang   |   Jumlah   |   Pendapatan   |   Nama Petugas   |" << endl;
    cout << "=============================================================================" << endl;

    int totalQuantitySold = 0;
    int totalRevenue = 0;


     for (int i = 0; i < gudang.size(); i++)
    {

         cout << "| " << setw(11) << left << gudang[i].tanggalTransaksi << " | "
             << setw(10) << left << gudang[i].nama << " | "
             << setw(10) << left << gudang[i].jumlahPembelian << " | "
             << setw(10) << left << (gudang[i].jumlahPembelian * gudang[i].Harga) << "     | "
             << setw(13) << left << gudang[i].namaPetugas << "    |" << endl;

        totalQuantitySold += gudang[i].jumlahPembelian;
        totalRevenue += (gudang[i].jumlahPembelian * gudang[i].Harga);
    }


    cout << "=============================================================================" << endl;
    cout << "| TOTAL       |            | " << setw(7) << left << totalQuantitySold << "    | "
         << setw(10) << left << totalRevenue << "     |" << endl;
    cout << "=============================================================================" << endl;

    // You can add any other summary information here

    // Add a prompt to return to the main menu or exit
    char kembaliMenu;
    do
    {
        cout << "Kembali Ke Menu? [Y/T] : ";
        cin >> kembaliMenu;
    } while (kembaliMenu != 'Y' && kembaliMenu != 'y');
}


void CariBarang(vector<Barang> &gudang)
{
    string kodeCari;
    cout << "Masukkan kode barang yang dicari: ";
    cin >> kodeCari;

    gotoxy(0, 0);
    cout << "===========================================================================";
    gotoxy(0, 1);
    cout << "| No | kode | Nama Barang | Stok Barang | Harga Satuan | Jumlah Pembelian |";
    gotoxy(0, 2);
    cout << "===========================================================================";


    bool found = false;
    for (int i = 0; i < gudang.size(); i++)
    {
        if (gudang[i].kode == kodeCari)
        {
            gotoxy(0, 3);
            cout << "| " << setw(3) << left << gudang[i].No << "| "
                 << setw(4) << left << gudang[i].kode << " | "
                 << setw(11) << left << gudang[i].nama << " | "
                 << setw(11) << left << gudang[i].stok << " | "
                 << setw(12) << left << gudang[i].Harga << " | "
                 << setw(17) << left << gudang[i].jumlahPembelian << "|";

            found = true;
        }
    }
    gotoxy(0, 4);
    cout << "===========================================================================";
    if (!found)
    {
        gotoxy(0, 3);
        cout << "Barang dengan kode " << kodeCari << " tidak ditemukan.";
    }

    getch();
}

void EditBarang(vector<Barang> &gudang)
{
    system("cls");
    TampilkanGudang(gudang);

    string kodeEdit;
    cout << "Masukkan kode barang yang akan diedit : ";
    cin >> kodeEdit;

    for (Barang &b : gudang)
    {
        if (b.kode == kodeEdit)
        {
            cout << "Masukkan Nama Barang Baru : ";
            cin >> b.nama;

            cout << "Masukkan Stok Barang Baru : ";
            cin >> b.stok;

            cout << "Masukkan Harga Satuan Baru : ";
            cin >> b.Harga;

            cout << "Data Barang Berhasil Diupdate." << endl;
            getch();
            return;
        }
    }
    cout << " Barang dengan kode " << kodeEdit << " Tidak Ditemukan. " << endl;
    getch();
}

void NormalisasiNomor(vector<Barang> &gudang)
{
    int nomor = 1;
    for (Barang &b : gudang)
    {
        b.No = nomor++;
    }
}

void menuUtama()
{
    system("cls");
    gotoxy(2,4);cout << "=====================================" << endl;
    gotoxy(2,5);cout << "|            MENU ADMIN             |" << endl;
    gotoxy(2,6);cout << "|         SELAMAT DATANG " << admin.namaAdmin << "\t      | " << endl;
    gotoxy(2,7);cout << "=====================================" << endl;
    gotoxy(2,8);cout << "========== APLIKASI GUDANG ==========" << endl;
    gotoxy(2,9);cout << "|\t                              |" << endl;
    gotoxy(2,10);cout << "|\t                              |" << endl;
    gotoxy(2,11);cout << "|\t                              |" << endl;
    gotoxy(2,12);cout << "|\t                              |" << endl;
    gotoxy(2,13);cout << "|\t                              |" << endl;
    gotoxy(2,14);cout << "|\t                              |" << endl;
    gotoxy(2,15);cout << "=====================================" << endl;
    int posisi = 1;
    int tekan = 0;
    while (tekan != 13)
    {
        gotoxy(5,9);
        panah(1, posisi);printf(" 1. Tambah Barang ");
        gotoxy(5,10);
        panah(2, posisi);printf(" 2. Tampilkan Gudang ");
        gotoxy(5,11);
        panah(3, posisi);printf(" 3. Cari Barang ");
        gotoxy(5,12);
        panah(4, posisi);printf(" 4. Edit Barang ");
        gotoxy(5,13);
        panah(5, posisi);printf(" 5. Laporan ");
        gotoxy(5,14);
        panah(6, posisi);printf(" 6. Keluar");

        tekan = _getch();

        if(tekan == 80){
            posisi = (posisi % 6) + 1;
        }else if(tekan == 72){
            posisi = (posisi -2 + 6) % 6 + 1;
        }
        int x = posisi;

        if(tekan == 13) {
        switch (x) {
            case 1:
               system("cls");
               TambahBarang(gudang, nomorBarang);

               menuUtama();
               break;

            case 2:
               system("cls");
               TampilkanGudang(gudang);

               menuUtama();
               break;

            case 3:
               system("cls");
               CariBarang(gudang);

               menuUtama();
               break;

            case 4:
               EditBarang(gudang);

               menuUtama();
               break;

            case 5:
               GenerateReport(gudang);

               menuUtama();
               break;
            case 6:
            system("cls");
              return;
            }
        }
    }
}

void pegawaiGudang()
{
    system("cls");
    gotoxy(2,4);cout << "======================================" << endl;
    gotoxy(2,5);cout << "|            MENU PEGAWAI            |" << endl;
    gotoxy(2,6);cout << "|         SELAMAT DATANG " << pegawai1.nama << "\t       | " << endl;
    gotoxy(2,7);cout << "======================================" << endl;
    gotoxy(2,8);cout << "========== APLIKASI PEGAWAI ==========" << endl;
    gotoxy(2,9);cout << "|                                    |" << endl;
    gotoxy(2,10);cout << "|                                    |" << endl;
    gotoxy(2,11);cout << "|                                    |" << endl;
    gotoxy(2,12);cout << "|                                    |" << endl;
    gotoxy(2,13);cout << "======================================" << endl;
    int posisi = 1;
    int tekan = 0;

    while (tekan != 13)
    {


        gotoxy(5, 9);
        panah(1, posisi);printf(" 1. Cari Barang");
        gotoxy(5, 10);
        panah(2, posisi);printf(" 2. Jumlah Pembelian");
        gotoxy(5, 11);
        panah(3, posisi);printf(" 3. Print Sturk");
        gotoxy(5, 12);
        panah(4, posisi);printf(" 4. Keluar");

        tekan = _getch();

        if (tekan == 80)
        {
            posisi = (posisi % 4) + 1;
        }
        else if (tekan == 72)
        {
            posisi = (posisi - 2 + 4) % 4 + 1;
        }

        int x = posisi;

        if (tekan == 13)
        {
            switch (x)
            {
            case 1:
                system("cls");
                CariBarang(gudang);

                pegawaiGudang();
                break;
            case 2:
                system("cls");
                TampilkanGudang(gudang);

                pegawaiGudang();
                break;
            case 3:
                system("cls");
                if (!PrintStruk(gudang))
                {
                    return;
                }
                pegawaiGudang();
                break;
            case 4:
            system("cls");
                return;
            }
        }
    }
}

const int MAX_LOGIN_TRIES = 3;

bool login(string &username, string &pin, bool &isAdmin, bool &isPegawai)
{
    int attempts = 0;

    while (attempts < MAX_LOGIN_TRIES)
    {
        cout << "MASUKKAN USERNAME : ";
        cin >> username;
        cout << "MASUKKAN PIN : ";
        pin = "";
        char ch;
        while((ch = _getch()) != '\r') {
        if(ch != '\b') {
	    cout << '*';
            pin += ch;
        }
        else {
            if(pin.length() > 0) {
                cout << "\b \b";
                pin.pop_back();
            }
        }
    }

        if (username == admin.usernameAdmin && pin == admin.pinAdmin)
        {
            isAdmin = true;
            return true;
        }

        for (Pegawai &p : pegawais)
        {
            if (username == p.username && pin == p.pin)
            {
                isPegawai = true;
                return true;
            }
        }
        attempts++;
        cout << endl;
        cout << "Gagal login! Sisa percobaan : " << MAX_LOGIN_TRIES - attempts << endl;
    }
    cout << "Percobaan login melebihi batas. Akun diblokir!" << endl;
    return false;
}

int main()
{
system("COLOR F0");
openDatabase();
bacaDataBarangSQLite();
    admin.pinAdmin = "1111";
    admin.namaAdmin = "Edho";
    admin.usernameAdmin = "edho";

    pegawai1.nama = "Fuad";
    pegawai1.pin = "1234";
    pegawai1.username = "121212";
    pegawais.push_back(pegawai1);

    bool isAdmin = false;
    bool isPegawai = false;
    string username, pin;

    Barang barang1 = {"001", "VGA", "", "", 1, 3000, 30000, 0};
    Barang barang2 = {"002", "CPU", "", "", 2, 2500, 20000, 0};
    Barang barang3 = {"003", "FAN", "", "", 3, 2000, 25000, 0};

    gudang.push_back(barang1);
    gudang.push_back(barang2);
    gudang.push_back(barang3);

    while (true)
    {
        bool loginResult = login(username, pin, isAdmin, isPegawai);

        if (loginResult)
        {
            isAdmin = (username == admin.usernameAdmin && pin == admin.pinAdmin);
            isPegawai = !isAdmin;

            if (isAdmin)
            {

                menuUtama();
            }
            else if (isPegawai)
            {
                pegawaiGudang();
            }
            isAdmin = false;
            isPegawai = false;

        }
        else
        {
            cout << "Gagal login!\n";
            break;
        }
    }
    closeDatabase();
    return 0;
}
