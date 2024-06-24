#include <stdio.h>

// Deklarasi fungsi yang akan diimplementasikan di fibo.c
void printFibonacci(int n);

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer.\n");
    } else {
        printFibonacci(n);
    }

    return 0;
}
