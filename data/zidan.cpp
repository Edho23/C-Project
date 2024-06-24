#include <iostream>
#include <vector>
#include <iomanip>
#include <unistd.h>
#include <termios.h>
#include <ctime>
#include <algorithm>
#include <ncurses.h>

using namespace std;

struct Mahasiswa
{
    string nbi;
    string nama;
    string nilaiUts;
    string nilaiUas;
    string nilaiAkhir;
    string mataKuliah;
    string reason;
};

struct Dosen
{
    string nama;
    string pin;
    string username;
};

struct Admin
{
    string namaAdmin;
    string pinAdmin;
    string usernameAdmin;
};

Admin admin;
Dosen dosen1;
vector<Dosen> dosens;
vector<Mahasiswa> dataMhs;
Mahasiswa mahasiswa;

const int MAX_LOGIN_TRIES = 3;
bool login(string &username, string &pin, bool &isAdmin, bool &isDosen);
void awalMenu();
void menuAdmin();
void menuDosen();

void gotoxy(int x, int y)
{
    move(y, x);
}

const char *panah(int pilihan, int posisi)
{
    if (pilihan == posisi)
    {
        return "==>";
    }
    else
    {
        return "   ";
    }
}

void tambahMahasiswa(vector<Mahasiswa> &dataMhs)
{
    Mahasiswa newMhs;
    cout << "Masukkan NBI: ";
    cin >> newMhs.nbi;
    cout << "Masukkan Nama: ";
    cin >> newMhs.nama;

    dataMhs.push_back(newMhs);
    cout << "Mahasiswa berhasil ditambahkan.\n";
}

void ubahDataMahasiswa(vector<Mahasiswa> &dataMhs)
{
    string nbiInput;
    cout << "Masukkan NBI mahasiswa yang ingin diubah: ";
    cin >> nbiInput;
    bool ditemukan = false;
    for (int i = 0; i < dataMhs.size(); ++i)
    {
        if (dataMhs[i].nbi == nbiInput)
        {
            cout << "Masukkan NBI baru: ";
            cin >> dataMhs[i].nbi;
            cout << "Masukkan Nama baru: ";
            cin >> dataMhs[i].nama;
            ditemukan = true;
            cout << "Data mahasiswa berhasil diubah.\n";
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "NBI tidak ditemukan.\n";
    }
}

void tampilkanDataMahasiswa(vector<Mahasiswa> &dataMhs)
{
    bool found = false;
    for (int i = 0; i < dataMhs.size(); i++)
    {
        cout << "NBI : " << dataMhs[i].nbi << endl;
        cout << "Nama : " << dataMhs[i].nama << endl;
        cout << "Nilai Uts : " << dataMhs[i].nilaiUts << endl;
        cout << "Nilai Uas : " << dataMhs[i].nilaiUas << endl;
        cout << "Nilai Akhir : " << dataMhs[i].nilaiAkhir << endl;

        if (!dataMhs[i].nilaiAkhir.empty())
        {
            double nilai = stod(dataMhs[i].nilaiAkhir);
            if (nilai >= 66)
            {
                dataMhs[i].reason = "LULUS";
            }
            else
            {
                dataMhs[i].reason = "TIDAK LULUS";
            }
            cout << "LULUS/TIDAK LULUS : " << dataMhs[i].reason << endl;
            cout << "Mata Kuliah Mahasiswa : " << dataMhs[i].mataKuliah << endl;
            cout << endl
                 << endl;

            found = true;
        }
    }

    cin.ignore();
    cin.get();
}

void tambahMataKuliah(vector<Mahasiswa> &dataMhs)
{
    string nbiMhs;
    string mataKuliah;
    cout << "Masukkan Nbi yang dicari : ";
    cin >> nbiMhs;

    bool found = false;
    for (int i = 0; i < dataMhs.size(); i++)
    {
        if (dataMhs[i].nbi == nbiMhs)
        {
            cout << "Masukkan Mata Kuliah Mahasiswa : ";
            cin >> mataKuliah;

            dataMhs[i].mataKuliah = mataKuliah;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << " Data Dengan Nbi " << nbiMhs << " tidak ditemukan.";
    }

    cin.ignore();
    cin.get();
}

void inputNilai(vector<Mahasiswa> &dataMhs)
{
    string nbiMhs;
    cout << "Masukkan Nbi yang dicari : ";
    cin >> nbiMhs;

    bool found = false;
    for (int i = 0; i < dataMhs.size(); i++)
    {
        if (dataMhs[i].nbi == nbiMhs)
        {
            cout << "Masukkan Nilai UTS untuk mahasiswa " << dataMhs[i].nama << ": ";
            cin >> dataMhs[i].nilaiUts;
            cout << "Masukkan Nilai UAS untuk mahasiswa " << dataMhs[i].nama << ": ";
            cin >> dataMhs[i].nilaiUas;
            double bobotUts = 0.4;
            double bobotUas = 0.6;
            double rataRata = (stod(dataMhs[i].nilaiUts) * bobotUts) + (stod(dataMhs[i].nilaiUas) * bobotUas);

            dataMhs[i].nilaiAkhir = to_string(rataRata);
            size_t found = dataMhs[i].nilaiAkhir.find_last_not_of('0');
            if (found != string::npos)
            {
                if (dataMhs[i].nilaiAkhir[found] == '.')
                {
                    found--;
                }
                dataMhs[i].nilaiAkhir = dataMhs[i].nilaiAkhir.substr(0, found + 1);
            }
            found = dataMhs[i].nilaiAkhir.find('.');
            if (found != string::npos && dataMhs[i].nilaiAkhir.substr(found + 1).empty())
            {
                dataMhs[i].nilaiAkhir = dataMhs[i].nilaiAkhir.substr(0, found);
            }

            found = true;
            cout << "Nilai berhasil diinput." << endl;
        }
    }

    cin.ignore();
    cin.get();
}

void menuAdmin()
{
    int pilihan;
    system("cls");
    gotoxy(2, 4);
    cout << "=====================================" << endl;
    gotoxy(2, 5);
    cout << "|            MENU ADMIN             |" << endl;
    gotoxy(2, 6);
    cout << "|         SELAMAT DATANG " << admin.namaAdmin << "\t      | " << endl;
    gotoxy(2, 7);
    cout << "=====================================" << endl;
    gotoxy(2, 8);
    cout << "========== APLIKASI GUDANG ==========" << endl;
    gotoxy(2, 9);
    cout << "|\t                              |" << endl;
    gotoxy(2, 10);
    cout << "|\t                              |" << endl;
    gotoxy(2, 11);
    cout << "|\t                              |" << endl;
    gotoxy(2, 12);
    cout << "|\t                              |" << endl;
    gotoxy(2, 13);
    cout << "|\t                              |" << endl;
    gotoxy(2, 14);
    cout << "=====================================" << endl;
    int posisi = 1;
    int tekan = 0;

    while (tekan != 13)
    {

        gotoxy(5, 9);
        panah(1, posisi);
        printf("1. Tambahkan Mahasiswa");
        gotoxy(5, 10);
        panah(2, posisi);
        printf("2. Ubah Data Mahasiswa");
        gotoxy(5, 11);
        panah(3, posisi);
        printf("3. Tampilkan data Mahasiswa");
        gotoxy(5, 12);
        panah(4, posisi);
        printf("4. Tambahkan Mata Kuliah");
        gotoxy(5, 13);
        panah(5, posisi);
        printf("5. Keluar");

        tekan = _getch();

        if (tekan == 80)
        {
            posisi = (posisi % 5) + 1;
        }
        else if (tekan == 72)
        {
            posisi = (posisi - 2 + 5) % 5 + 1;
        }
        int x = posisi;

        if (tekan == 13)
        {
            switch (pilihan)
            {
            case 1:
                tambahMahasiswa(dataMhs);
                break;
            case 2:
                ubahDataMahasiswa(dataMhs);
                break;
            case 3:
                tampilkanDataMahasiswa(dataMhs);
                break;
            case 4:
                tambahMataKuliah(dataMhs);
                break;
            case 5:
                awalMenu();
                break;
            }
        }
    }
}

void menuDosen()
{
    system("cls");
    gotoxy(2, 4);
    cout << "======================================" << endl;
    gotoxy(2, 5);
    cout << "|            MENU PEGAWAI            |" << endl;
    gotoxy(2, 6);
    cout << "|         SELAMAT DATANG " << pegawai1.nama << "\t       | " << endl;
    gotoxy(2, 7);
    cout << "======================================" << endl;
    gotoxy(2, 8);
    cout << "========== APLIKASI PEGAWAI ==========" << endl;
    gotoxy(2, 9);
    cout << "|                                    |" << endl;
    gotoxy(2, 10);
    cout << "|                                    |" << endl;
    gotoxy(2, 11);
    cout << "|                                    |" << endl;
    gotoxy(2, 12);
    cout << "======================================" << endl;
    int posisi = 1;
    int tekan = 0;

    while (tekan != 13)
    {
        gotoxy(5, 9);
        panah(1, posisi);
        printf("1. Data Mahasiswa");
        gotoxy(5, 10);
        panah(2, posisi);
        printf("2. Input Nilai");
        gotoxy(5, 11);
        panah(3, posisi);
        printf("3. Keluar");

        tekan = _getch();

        if (tekan == 80)
        {
            posisi = (posisi % 3) + 1;
        }
        else if (posisi == 72)
        {
            posisi = (posisi - 2 + 3) % 3 + 1;
        }

        int x = posisi;

        if (tekan == 13)
        {
            switch (x)
            {
            case 1:
                tampilkanDataMahasiswa(dataMhs);
                break;
            case 2:
                inputNilai(dataMhs);
                break;
            case 3:
                awalMenu();
                return;
            }
        }
    }
}

void awalMenu()
{
    bool isAdmin = false;
    bool isDosen = false;
    string username, pin;
    int posisi = 1;
    int tekan = 0;

    gotoxy(2, 4);
    cout << "====================================";
    gotoxy(2, 5);
    cout << "|             MAIN MENU            |";
    gotoxy(2, 6);
    cout << "====================================";
    gotoxy(2, 7);
    cout << "|                                  |";
    gotoxy(2, 8);
    cout << "|                                  |";
    gotoxy(2, 9);
    cout << "|                                  |";
    gotoxy(2, 10);
    cout << "====================================";

    while (tekan != 13)
    {
        gotoxy(5, 7);
        panah(1, posisi);
        printf(" 1. LOGIN ADMIN")
            gotoxy(5, 8);
        panah(2, posisi);
        printf(" 2. LOGIN DOSEN")
            gotoxy(5, 9);
        panah(3, posisi);
        printf(" 3. EXIT")

            tekan = _getch(); // Gunakan getch() untuk membaca input tanpa menunggu Enter

        if (tekan == 80)
        {
            posisi = (posisi % 3) + 1;
        }
        else if (tekan == 72)
        {
            posisi = (posisi - 2 + 3) % 3 + 1;
        }
        int x = posisi;
        if (tekan == 13) // Gunakan 10 untuk Enter, bukan 13
        {
            switch (x)
            {
            case 1:
                if (login(username, pin, isAdmin, isDosen))
                {
                    isAdmin = (username == admin.usernameAdmin && pin == admin.pinAdmin);
                    isDosen = !isAdmin;

                    if (isAdmin)
                    {
                        menuAdmin();
                    }
                    isAdmin = false;
                    isDosen = false;
                }
                break;
            case 2:
                if (login(username, pin, isAdmin, isDosen))
                {
                    isAdmin = (username == admin.usernameAdmin && pin == admin.pinAdmin);
                    isDosen = !isAdmin;

                    if (isDosen)
                    {
                        menuDosen();
                    }
                    isAdmin = false;
                    isDosen = false;
                }
                break;
            case 3:
                return;
            }
        }
    }
}

bool login(string &username, string &pin, bool &isAdmin, bool &isDosen)
{
    int attempts = 0;

    while (attempts < MAX_LOGIN_TRIES)
    {
        cout << "MASUKKAN USERNAME : ";
        cin >> username;
        cout << "MASUKKAN PIN : ";
        pin = "";
        char ch;
        while ((ch = getchar()) != '\r')
        {
            if (ch != '\b')
            {
                cout << '*';
                pin += ch;
            }
            else
            {
                if (pin.length() > 0)
                {
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

        for (Dosen &p : dosens)
        {
            if (username == p.username && pin == p.pin)
            {
                isDosen = true;
                return true;
            }
        }
        attempts++;
        cout << endl;
        cout << "Gagal login! Sisa Percobaan : " << MAX_LOGIN_TRIES - attempts << endl;
    }
    cout << "Percobaan login melebihi batas." << endl;
    return false;
}

int main()
{
    admin.pinAdmin = "1111";
    admin.namaAdmin = "Zidan";
    admin.usernameAdmin = "zidan";

    dosen1.nama = "Alfin";
    dosen1.pin = "1234";
    dosen1.username = "Alfin";
    dosens.push_back(dosen1);

    Mahasiswa mahasiswa1 = {"14623001", "Zidan"};
    Mahasiswa mahasiswa2 = {"14623002", "alfin"};

    dataMhs.push_back(mahasiswa1);
    dataMhs.push_back(mahasiswa2);

    awalMenu();
    return 0;
}
