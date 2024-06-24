#include <iostream>

using namespace std;

int main()
{

    int A[] = {50, 15, 49, 65, 23, 47, 57, 94};
    int j = sizeof(A) / sizeof(*A);
    int temp;

    cout << " A : ";
    for (int i = 0; i < j; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    // Proses sorting
    for (int i = 0; i < j; i++)
    {
        int acak = 0;
        for (int h = 0; h < j; h++)
        {
            if (A[h] > A[h + 1])
            {
                temp = A[h];
                A[h] = A[h + 1];
                A[h + 1] = temp;
                acak++;
            }
        }
        //Proses jika sdh mendapat hasil maka langsung di cut 
        if(acak == 0){
            break;
        }
        cout << endl;
        cout << " HASIL " << i + 1 << " : ";
        for (int a = 0; a < j; a++)
        {
            cout << A[a] << " ";
        }
    }
    cout << endl;
    cout << endl;
    cout << "hasil : ";
    for(int a = 0; a < j; a++){
        cout << A[a] << " ";
    }
    return 0;
}