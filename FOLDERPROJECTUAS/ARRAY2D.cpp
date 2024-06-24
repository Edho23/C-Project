#include <iostream>
#include <iomanip> // Untuk mengatur lebar kolom
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main() {

    gotoxy(0,0); cout << "TOKO SERBA ADA";
    gotoxy(0,1); cout << "AKSESORIS COMPUTER";
    gotoxy(0,2); cout << "SURABAYA";
    gotoxy(0,4); cout << "Nama Pembeli : ";
    gotoxy(0,5); cout << "===============================================================================";
    gotoxy(0,6); cout << "| No | Kode Barang | Nama Barang | Jumlah barang | Harga Satuan | Total Harga |";
    gotoxy(0,7); cout << "===============================================================================";
    for(int i=1; i <= 12; i++) {

        gotoxy(0,7+i);
        cout << "|    |             |             |               |              |             |";

    }
    gotoxy(0,20); cout << "===============================================================================";
    gotoxy(0,21); cout << "|                                                    TOTAL BAYAR|             |";
    gotoxy(0,22); cout << "|                                                   TOTAL BARANG|             |";
    gotoxy(0,23); cout << "|                                                          BAYAR|             |";
    gotoxy(0,24); cout << "|                                                        KEMBALI|             |";
    gotoxy(0,25); cout << "===============================================================================";


    int i=1;
    char jw, namapebeli[30], namabrg[30], kodebrg[30];
    int jmlBarang, hgSat,totHg,totByr=0,totBarang=0,bayar,kembali=0;
    gotoxy(15,4);cin >> namapebeli;
    do {

        gotoxy(2,7+i); cout << i;
        gotoxy(7,7+i);cin >> kodebrg;
        gotoxy(22,7+i);cin >> namabrg;
        gotoxy(37,7+i);cin >> jmlBarang;
        gotoxy(52,7+i);cin >> hgSat;
        totHg = (jmlBarang*hgSat);
        gotoxy(67,7+i);cout << setw(10) << totHg;
        totByr = totByr+totHg;
        totBarang = totBarang+jmlBarang;
        gotoxy(65,21);cout << setw(10) << totByr;
        gotoxy(65,22);cout << setw(10) << totBarang;
        gotoxy(40,4);cout << "Isi Data Lagi [Y/T] : ";
        cin >> jw;
        i++;
        gotoxy(40,4);cout << "                          ";

        

    } while(jw=='y' || jw=='Y');
    do {
      gotoxy(65,23);cin >> bayar;
      gotoxy(65,23);cout << setw(10) << bayar;
       if(bayar<totByr){
         gotoxy(40,4);cout << "UANG TIDAK MENCUKUPI... Total Bayar : " << totByr;
         getch();
         gotoxy(40,4);cout << "                                                        ";
       }  
    } while(bayar<totByr);
      kembali=bayar-totHg;
      gotoxy(65,24);cout << setw(10) << kembali;
      getch();







    cin.get();
    return 0;
}
