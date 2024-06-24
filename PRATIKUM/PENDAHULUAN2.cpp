// AGUSTINO EDWARD HARTONO
// 1462300061
#include <iostream>

using namespace std;

int main() {

    char ulangi;

    do {

        int N ;

        cout << "MASUKKAN NILAI BILANGAN : ";
        cin >> N;
        cout << endl;

        cout << "DERETAN BILANGAN : " << endl;
        for(int i=1; i <= N; i += 2) {
            cout << i << " ";
        }
         cout << endl; 
        cout <<"INGIN MENGULANG [Y/T] : ";
        cin >> ulangi;


    } while(ulangi == 'y' || ulangi == 'Y');

    cout << "PROGRAM SELESAI..."; 
    cin.get();
    return 0;
}