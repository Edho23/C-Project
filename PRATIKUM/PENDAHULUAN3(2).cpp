//AGUSTINO EDWARD HARTONO
//1462300061
#include <iostream>

using namespace std;

void fungsi(int *b){
    cout << "address b " << b << endl;
    cout << "Nilai b " << *b << endl; 
}

int main() {
    int a = 5;
    cout << "adress a " << &a << endl;
    cout << "Nilai a " << a << endl;

    fungsi(&a);

    cin.get();
    return 0;
}