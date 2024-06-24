//AGUSTINO EDWARD HARTONO
//1462300061
#include <iostream>

using namespace std;

class Bilangan
{
private:
    int A, B, C, D, E;

public:
    void input() {
        cout << "Masukkan Bilangan A : ";
        cin >> A;
        cout << "Masukkan Bilangan B : ";
        cin >> B;
        cout << "Masukkan Bilangan C : ";
        cin >> C;
        cout << "Masukkan Bilangan D : ";
        cin >> D;
        cout << "Masukkan Bilangan E : ";
        cin >> E;
    }

    void DisplayTerbesar(){
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
    }
};

int main(){
    Bilangan bilangan;
    bilangan.input();
    bilangan.DisplayTerbesar();

    cin.ignore();
    cin.get();
    return 0;
}