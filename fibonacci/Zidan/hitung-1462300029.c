#include "Ratarata.h"
#include <stdio.h>

void PrintRata(int n){
    int i;
    float num, sum = 0.0, average;
        for (i = 1; i <= n; ++i) {
        printf("Masukkan angka ke-%d: ", i);
        scanf("%f", &num);
        sum += num;
    }

    average = sum / n;

    printf("Rata-rata dari %d angka adalah: %.1f\n", n, average);
}
