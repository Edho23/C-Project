#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 23;
    int low = 0, high = n - 1;
    int found = -1;

    cout << "Key : " << key << endl;
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            found = mid;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found != -1)
    {
        cout << "Nomor ditemukan di indeks: " << found << endl;
    }
    else
    {
        cout << "Nomor tidak ditemukan" << endl;
    }
    cin.get();
    return 0;
}
