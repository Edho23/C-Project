// agustino edward hartono
// 1462300061
#include <iostream>

using namespace std;

int main(){

int* bil = new int;
do {
*bil = 0;
int hasil;
do{
	cout << "Masukkan angka : ";
	cin >> hasil;
	
	if (hasil > 0){
		cout << "Program berhenti hasil positif\n";
		delete bil;
		return 0;
	} else if(hasil < 0) {
		cout << "Hasil minus! Ulangi.\n";
	}
	*bil += hasil;

}while(*bil < 0);


}while(true);

cout << "Program Selesai . Total akhir : " << *bil << "\n";

delete bil;
return 0;
}


