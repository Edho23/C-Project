// AGUSTINO EDWARD HARTONO 
// 1462300061
#include <iostream>

using namespace std;

int main() {
	
	 int a;
	 int b;
	 
	 cout << "Masukkan Angka 1 : ";
	 cin >> a;
	 
	 cout << "Masukkan Angka 2 : ";
	 cin >> b;
	 
	 int Pertambahan = a + b;
	 int pengurangan = a - b;
	 int kali = a * b;
	 double bagi = static_cast<double>(a)/b;
	 int hasilbagi= a % b;
	 
	 bool samadengan = a == b;
	 bool tidaksamadengan = a != b;
	 bool lebihdari = a > b;
	 bool kurangdari = a < b;
	 bool besardari = a >= b;
	 bool kecildari = a <= b;
	 
	 
	 cout << " HASIL PERHITUNGAN ARITMATIKA " << endl;
	 cout << "Pertambahan : " << Pertambahan << endl;
	 cout << "Pengurangan : " << pengurangan << endl;
	 cout << "Perkalian : " << kali << endl;
	 cout << "Pembagian : " << bagi << endl;
	 cout << "Hasil Bagi : " << hasilbagi << endl << endl;
	 
	 cout << " HASIL PERHITUNGAN RELASIONAL" << endl;
	 cout << "Apakah A lebih besar dari B : " << (samadengan ? "True" : "False") << endl;
	 cout << "Apakah A lebih besar dari B : " << (tidaksamadengan ? "True" : "False")<< endl;
	 cout << "Apakah A lebih besar dari B : "  << (lebihdari ? "True" : "False")<< endl;
	 cout << "Apakah A lebih besar dari B : "  << (kurangdari ? "True" : "False")<< endl;
	 cout << "Apakah A lebih besar dari B : " << (besardari ? "True" : "False")<< endl;
	 cout << "Apakah A lebih besar dari B : " << (kecildari ? "True" : "False")<< endl;


	 return 0;	 
}
