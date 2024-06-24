#include <iostream>

using namespace std;

int main(){
    int nilai[] = {50,15,49,65,23,47,57,94};
    int lenght = sizeof(nilai)/sizeof(*nilai);
    int temp;
    // untuk mengsorting dari A0 ke A1 sampai terkecil ke terbesar
    for(int a = 1; a < lenght; a++){
        for(int b = 0; b < lenght-a; b++){
            if(nilai[b] > nilai[b+1]){
                temp = nilai[b];
                nilai[b] = nilai[b+1];
                nilai[b+1] = temp;
            }
        }  
    }
    cout << "SEBELUM DI SORTING" << endl;
    cout << "A = 50,15,49,65,23,47,57,94" << endl << endl;
    cout << "SETELAH DI SORTING" << endl;
    cout << "A = ";
    for(int x = 0; x < lenght; x++){
        cout << " "<< nilai[x];
    }
    cin.get();
    return 0;
}