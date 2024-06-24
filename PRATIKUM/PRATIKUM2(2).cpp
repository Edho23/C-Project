#include <iostream>

using namespace std;

int main() {

    int a = 3;
    int b = 2;

    bool hasil1, hasil2;

    hasil1 = (a < b);
    hasil2 = (a > b);
    cout << "Hasil kurang Dari : " << hasil1 << endl;
    cout << "Hasil lebih Dari : " << hasil2 << endl;

    hasil1 = (a == b);
    hasil2 = (a != b);
    cout << "Hasil sama dengan : " << hasil1 << endl;
    cout << "Hasil tidak sama dengan : " << hasil2 << endl;

    hasil1 = (a <= b);
    hasil2 = (a >= b);
    cout << "Hasil Lebih kecil dari atau sama dengan : " << hasil1 << endl;
    cout << "Hasil Lebih besar dari atau ama dengan : " << hasil2 << endl;

    cin.get();
    return 0;
}