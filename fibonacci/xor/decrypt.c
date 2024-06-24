#include <stdio.h>

int encrypt(int angka, int desimal);
int main(){

    int angka, bil;
    printf("Masukkan angka 1-9 = ");
    scanf("%d", &angka);
    printf("Masukkan angka desimal 8-bit untuk enkripsi =  ");
    scanf("%d", &bil);
    bil = bil &0x000000FF;
    printf("Hasil = ");
    printf("%d\n", encrypt(angka, bil));
}


