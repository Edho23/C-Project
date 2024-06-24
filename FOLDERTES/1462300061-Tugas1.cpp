//AGUSTINO EDWARD HARTONO
//1462300061
#include <iostream>

using namespace std;

int main(){
    int A,B,C,D,E;

    cout << "MASUKKAN BILANGAN A : ";
    cin >> A;

    cout << "MASUKKAN BILANGAN B : ";
    cin >> B;

    cout << "MASUKKAN BILANGAN C : ";
    cin >> C;

    cout << "MASUKKAN BILANGAN D : ";
    cin >> D;

    cout << "MASUKKAN BILANGAN E : ";
    cin >> E;

    int terbesar = A;
    if(B > terbesar){
        terbesar = B;
    }
    if(C > terbesar){
        terbesar = C;
    }
    if(D > terbesar){
        terbesar = D;
    }
    if(E > terbesar){
        terbesar = E;
    }

    cout << "HASIL BILANGAN PALING TERBESAR : " << terbesar << endl;

    cin.ignore();
    cin.get();
    return 0;
}