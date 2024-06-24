#include <iostream>

using namespace std;

int main()
{

    int a = 16;
    int b = 14;
    int hasil;

    hasil = a + b;
    cout << a << "+" << b << "=" << hasil;
    cout << endl;
    hasil = a - b;
    cout << a << "-" << b << "=" << hasil;
    cout << endl;
    hasil = a * b;
    cout << a << "x" << b << "=" << hasil;
    cout << endl;
    hasil = a % b;
    cout << a << "%" << b << "=" << hasil;
    cout << endl;
    hasil = a / b;
    cout << a << "/" << b << "=" << hasil;

    cin.get();
    return 0;
}