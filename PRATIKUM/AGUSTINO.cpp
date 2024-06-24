// AGUSTINO EDWARD HARTONO
// 1462300061
#include <iostream>
using namespace std;
 
 int main(){
 	char ulangi;
 	
 	do {
	 
    string nama;
    int nbi,bilangan;
    
    cout << "NAMA SAYA ADALAH : ";
    cin >> nama;
    
    cout << "NBI : ";
    cin >> nbi;
    
    
    cout << "Nama Saya Adalah " <<" : " << nama << endl;
    cout << "Nbi " << " : "<< nbi << endl;
    
    if (nbi == 160 ){
       cout << "LU PUNYA NBI BENAR OOO...";
	}else {
		cout << "SALAH" << endl;
	}
    
    
    cout << "APAKAH ANDA INGIN MENGINPUT NBI LAIN [Y/T] :";
    cin >> ulangi;

   
	}while(ulangi == 'y' || ulangi == 'Y');
	
	int bilangan;
	
    
    cout << "LU PUNYA TANGAN ELU KETIK A... LU PUNYA ANGKA HARI : ";
    cin >> bilangan;
    
    if (bilangan == 1){
    	cout << "HARI SENIN" << endl;
	}else if (bilangan == 2){
		cout << "HARI SELASA" << endl;
	}else if (bilangan == 3){
		cout << "HARI SELASA" << endl;
	}else if (bilangan == 3){
		cout << "HARI RABU" << endl;
	}else if (bilangan == 4){
		cout << "SAYA MENGIKUTI PRATIKUM DASPRO DI HARI KAMIS DAN DI KELAS K310" << endl;
	}
    cin.get();
 	return 0;
 }
