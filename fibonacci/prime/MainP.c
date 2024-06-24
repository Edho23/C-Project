#include <stdio.h>
#include "prime.h"

int main() {
    int rentang_awal, rentang_akhir, jumlah_prima = 0;

    printf("Masukkan rentang awal: ");
    scanf("%d", &rentang_awal);

    printf("Masukkan rentang akhir: ");
    scanf("%d", &rentang_akhir);

    for (int i = rentang_awal; i <= rentang_akhir; i++) {
        if (isPrime(i)) {
            jumlah_prima++;
        }
    }

    printf("Jumlah bilangan prima dalam rentang tersebut adalah: %d\n", jumlah_prima);

    return 0;
}
