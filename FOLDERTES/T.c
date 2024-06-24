#include <stdio.h>

int main() {
    float celcius, reamur, fahrenheit;

    // Input suhu dalam Celcius
    printf("Masukkan suhu dalam Celcius: ");
    scanf("%f", &celcius);

    // Membersihkan buffer input
    getchar();

    // Konversi suhu ke Reamur dan Fahrenheit
    reamur = 4.0 / 5.0 * celcius;
    fahrenheit = 9.0 / 5.0 * celcius + 32.0;

    // Menampilkan hasil konversi
    printf("Suhu dalam Reamur: %.2f\n", reamur);
    printf("Suhu dalam Fahrenheit: %.2f\n", fahrenheit);

    return 0;
}
