#include <stdio.h>
#include "Ratarata.h"

int main(){
    int n,i;
    printf("Masukkan jumlah angka: ");
    scanf("%d", &n);

        if (n <= 0) {
        printf("Jumlah angka harus lebih dari nol.\n");
        return 1;
        }
        PrintRata(n);

    return 0;
}
