#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <algorithm>

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

int nomorBarang = 1;
void animasi();
bool login(string &username, string &pin, bool &isAdmin, bool &isPegawai);
void menuUtama();
void pegawaiGudang();
void mainMenu();

void SimpanKeDatabase(const vector<Barang> &gudang)
{
    ofstream file("database.txt");

    if (!file.is_open())
    {
        cerr << "Gagal membuka file database.txt" << endl;
        return;
    }

    for (const Barang &barang : gudang)
    {
        file << barang.No << "," << barang.kode << "," << barang.nama << ","
             << barang.stok << "," << barang.Harga << "," << barang.jumlahPembelian << "\n";
    }

    file.close();
}

// Fungsi untuk memuat data barang dari file teks
void LoadDatabase(vector<Barang> &gudang)
{
    ifstream file("database.txt");

    if (!file.is_open())
    {
        cerr << "File database.txt tidak ditemukan. Membuat file baru." << endl;
        return;
    }

    gudang.clear();

    string line;
    while (getline(file, line))
    {
        Barang barang;
        stringstream ss(line);

        // Membaca data dari setiap kolom
        ss >> barang.No >> ws;
        getline(ss, barang.kode, ',');
        getline(ss, barang.nama, ',');
        ss >> barang.stok >> ws;
        ss >> barang.Harga >> ws;
        ss >> barang.jumlahPembelian;

        gudang.push_back(barang);
    }

    file.close();
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

void TambahBarang(vector<Barang> &gudang, int &nomorBarang)
{
    Barang barang;
    if(gudang.empty()) {
        barang.No = 1;
    } else {
        barang.No = gudang.back().No + 1;
    }

    cout << "Masukkan Kode : ";
    cin >> barang.kode;

    for (Barang &b : gudang) {
        if(b.kode == barang.kode) {
            cout << "Barang denga kode" << barang.kode << "Sudah ada digudang" << endl;
            char tambahstok;
            cout << "Apakah ingin menambahkan Barang? [Y/T] : ";
            cin >> tambahstok;
            if(tambahstok == 'Y' || tambahstok == 'y') {
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

    gudang.push_back(barang);

    SimpanKeDatabase(gudang);
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
    gotoxy(0, 3);
    cout << "Nama Petugas : " << pegawai1.nama;
    gotoxy(0,4);
    cout << "Nama Pembeli : ";
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
    char jw,namapembeli[10];
    int totHg, totByr = 0;
    float bayar, kembali;
    bool displayStaffInfo = false;
    gotoxy(15,4);
    cin >> namapembeli;
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
                if(barang.jumlahPembelian > b.stok){
                    gotoxy(40,3);cout << "Jumlah pembelian melebihi stok barang" << endl;
                    getch();
                    return true;
                }
                b.jumlahPembelian += barang.jumlahPembelian;
                b.stok -= barang.jumlahPembelian;
            }
        }
        totHg = (barang.jumlahPembelian * barang.Harga);
        gotoxy(75, 7 + i);
        cout << totHg;
        totByr += totHg;
        gotoxy(75, 21);
        cout << totByr;

        time_t now = time(0);
        tm *localTime = localtime(&now);
        char dateBuffer[80];
        strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", localTime);
        gudang[i - 1].tanggalTransaksi = dateBuffer;
        gudang[i - 1].namaPetugas = pegawai1.nama;

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
         << setw(10) << left << totalRevenue << "     |" << "                  |" << endl;
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

    for(Barang &b : gudang){
        if(b.kode == kodeEdit){
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

void animasi()
{
    int x;
    double y;
    char Pembuat[] = "\t\t\t   Pembuat :";
    char NIM1[] = "\t\t\t   Agustino Edward Hartono (1462300061)";
    char NIM2[] = "\t\t\t   Fuad Ubaidillah Muzaki (1462300056)";
    

    printf("\n\n\n");
    for (x = 0; Pembuat[x] != '\0'; x++)
    {
        printf(" %c", Pembuat[x]);
        for (y = 0; y <= 9999999; y++)
        {
        }
    }
    printf("\n");
    for (x = 0; NIM1[x] != '\0'; x++)
    {
        printf(" %c", NIM1[x]);
        for (y = 0; y <= 9999999; y++)
        {
        }
    }
    printf("\n");
    for (x = 0; NIM2[x] != '\0'; x++)
    {
        printf(" %c", NIM2[x]);
        for (y = 0; y <= 9999999; y++)
        {
        }
    }
    printf("\n");
    _getch();
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
                mainMenu();
              break;
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
    gotoxy(2,12);cout << "======================================" << endl;
    int posisi = 1;
    int tekan = 0;

    while (tekan != 13)
    {
    

        gotoxy(5, 9);
        panah(1, posisi);printf(" 1. Jumlah Pembelian");
        gotoxy(5, 10);
        panah(2, posisi);printf(" 2. Print Struk");
        gotoxy(5, 11);
        panah(3, posisi);printf(" 3. Keluar");
        

        tekan = _getch();

        if (tekan == 80)
        {
            posisi = (posisi % 3) + 1;
        }
        else if (tekan == 72)
        {
            posisi = (posisi - 2 + 3) % 3 + 1;
        }
        
        int x = posisi;

        if (tekan == 13)
        {
            switch (x)
            {
            case 1:
                system("cls");
                TampilkanGudang(gudang);

                pegawaiGudang();
                break;
            case 2:
                system("cls");
                if (!PrintStruk(gudang))
                {
                    return;
                }
                pegawaiGudang();
                break;
            case 3:
            system("cls");
                mainMenu();
                break;
            }
        }
    }
}

void mainMenu(){
    system("cls");
    gotoxy(2,4);cout << "====================================" << endl;
    gotoxy(2,5);cout << "|             MAIN MENU            |" << endl;
    gotoxy(2,6);cout << "====================================" << endl;
    gotoxy(2,7);cout << "|                                  |" << endl;
    gotoxy(2,8);cout << "|                                  |" << endl;
    gotoxy(2,9);cout << "|                                  |" << endl;
    gotoxy(2,10);cout << "====================================" << endl;
    int posisi = 1;
    int tekan = 0;

    bool isAdmin = false;
    bool isPegawai = false;
    string username, pin;
    
    while(tekan != 13){ 
    gotoxy(5, 7);panah(1, posisi);printf(" 1. Login Admin");
    gotoxy(5, 8);panah(2, posisi);printf(" 2. Login Pegawai");
    gotoxy(5, 9);panah(3, posisi);printf(" 3. Exit");

    tekan = _getch();

    if(tekan == 80){
        posisi = (posisi % 3) + 1;
    } else if(tekan == 72){
        posisi = (posisi - 2 + 3) % 3 + 1;
    }
     int x = posisi;

       if(tekan == 13){
            switch(x){
               case 1:
               system("cls"); 
                 if(login(username, pin, isAdmin, isPegawai)){
                    isAdmin = (username == admin.usernameAdmin && pin == admin.pinAdmin);
                    isPegawai = !isAdmin;

                    if(isAdmin){
                        menuUtama();
                    } 
                    isAdmin = false;
                    isPegawai = false;
               }
               break;

               case 2:
               system("cls");
                 if(login(username, pin, isAdmin, isPegawai)){
                    isAdmin = (username == admin.usernameAdmin && pin == admin.pinAdmin);
                    isPegawai == !isAdmin;

                    if(isPegawai){
                        pegawaiGudang();
                    }
                    isAdmin = false;
                    isPegawai = false;
                 }
                 break;

               case 3:
               system("cls");
                  animasi();
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
    admin.pinAdmin = "1111";
    admin.namaAdmin = "Edho";
    admin.usernameAdmin = "edho";

    pegawai1.nama = "Fuad";
    pegawai1.pin = "1234";
    pegawai1.username = "Edho";
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

    LoadDatabase(gudang);

    mainMenu();

    SimpanKeDatabase(gudang);
   
    return 0;
}
