#include <stdio.h>

int main() {
    int n, i;
    float num, sum = 0.0, average;

    printf("Masukkan jumlah angka: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Jumlah angka harus lebih dari nol.\n");
        return 1;
    }

    for (i = 1; i <= n; ++i) {
        printf("Masukkan angka ke-%d: ", i);
        scanf("%f", &num);
        sum += num;
    }

    average = sum / n;

    printf("Rata-rata dari %d angka adalah: %.2f\n", n, average);
    
    printf("Tekan enter untuk keluar...");
    getchar(); // Untuk menangkap karakter newline yang tersisa di buffer
    getchar(); // Menunggu pengguna menekan enter

    return 0;
}
