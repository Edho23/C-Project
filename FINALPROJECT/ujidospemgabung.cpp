#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

double luasTrapesium(double panjangAtas, double panjangBawah, double tinggi) {
    return 0.5 * (panjangAtas + panjangBawah) * tinggi;
}

double luasLingkaran(double jariJari) {
    return M_PI * pow(jariJari, 2);
}

bool prima(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void programLuasTrapesium() {
    double panjangAtas, panjangBawah, tinggiTrapesium;

    cout << "Masukkan panjang sisi atas trapesium: ";
    cin >> panjangAtas;
    cout << "Masukkan panjang sisi bawah trapesium: ";
    cin >> panjangBawah;
    cout << "Masukkan tinggi trapesium: ";
    cin >> tinggiTrapesium;

    double luasTrapesiumhasil = luasTrapesium(panjangAtas, panjangBawah, tinggiTrapesium);
    cout << "Luas Trapesium: " << luasTrapesiumhasil << endl;

    double jariJariLingkaran;

    cout << "Masukkan jari-jari lingkaran di dalam trapesium: ";
    cin >> jariJariLingkaran;

    double luasLingkaranResult = luasLingkaran(jariJariLingkaran);
    cout << "Luas Lingkaran di dalam Trapesium: " << luasLingkaranResult << endl;

    if (luasLingkaranResult <= luasTrapesiumhasil) {
        double luasSisaTrapesium = luasTrapesiumhasil - luasLingkaranResult;
        cout << "Luas Sisa Trapesium: " << luasSisaTrapesium << endl;
    } else {
        cout << "Lingkaran tidak berada di dalam trapesium." << endl;
    }
}

void programPilihanWarnaMotif() {
    int warna, motif;

    cout << "pilih warna yang anda sukair:\n";
    cout << "1. merah\n";
    cout << "2. putih\n";
    cout << "3. biru\n";
    cout << "4. kuning\n";
    cout << "5. hijau\n";
    cout << "masukkan nomer: ";
    cin >> warna;

    cout << "\npilih motif yang kamu sukai:\n";
    cout << "1. banteng\n";
    cout << "2. bintang\n";
    cout << "3. bulan\n";
    cout << "masukkan nomer: ";
    cin >> motif;

    cout << "\npilihanmu: ";
    if (warna == 1)
        cout << "merah ";
    else if (warna == 2)
        cout << "putih ";
    else if (warna == 3)
        cout << "biru ";
    else if (warna == 4)
        cout << "kuning ";
    else if (warna == 5)
        cout << "hijau ";
    else
        cout << "pilih warna yang ada di atas ooo ";

    switch (motif) {
        case 1:
            cout << "banteng";
            break;
        case 2:
            cout << "bintang";
            break;
        case 3:
            cout << "bulan";
            break;
        default:
            cout << "motif kamu tidak ada ooo...";
    }

    cout << endl;
}

void programBilanganPrima() {
    int n;

    cout << "Masukkan nilai n untuk menemukan bilangan prima hingga n: ";
    cin >> n;

    bool isPrima[n + 1];
    memset(isPrima, true, sizeof(isPrima));

    cout << "Bilangan prima hingga " << n << " adalah:\n";

    for(int p = 2; p * p <= n; ++p){
        if (isPrima[p] == true){
            for(int i = p * p; i <= n; i+= p)
            isPrima[i] = false;
            
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (prima(i)) {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main() {
    int choice;

    do {
        cout << "Pilih program:\n";
        cout << "1. Program Luas Trapesium\n";
        cout << "2. Program Pilihan Warna dan Motif\n";
        cout << "3. Program Bilangan Prima\n";
        cout << "4. Keluar\n";
        cout << "Masukkan nomor program: ";
        cin >> choice;

        switch (choice) {
            case 1:
                programLuasTrapesium();
                break;
            case 2:
                programPilihanWarnaMotif();
                break;
            case 3:
                programBilanganPrima();
                break;
            case 4:
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 4);

    return 0;
}

