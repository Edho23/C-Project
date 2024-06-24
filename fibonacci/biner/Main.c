#include <stdio.h>

int penjumlahan(int a, int b);
int pengurangan(int a, int b);
int decimalTobiner(int num);
int binerTodecimal(int num);

int main() {
    int a;
    int b;
    int sum;
    int diff;

    printf("Masukkan angka pertama: ");
    scanf("%d", &a);

    printf("Masukkan angka kedua: ");
    scanf("%d", &b);

    //a= decimalTobiner(a);
    //b= decimalTobiner(b);

    sum = penjumlahan(a, b);
    printf("Penjumlahan: %d\n", sum);

    diff = pengurangan(a, b);
    printf("Pengurangan: %d\n", diff);

    printf("Hasil penjumlahan: %d\n", binerTodecimal(sum));
    printf("Hasil pengurangan: %d\n", binerTodecimal(diff));

    return 0;
}
