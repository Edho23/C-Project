#include <stdio.h>

// Definisi fungsi untuk mencetak deret Fibonacci
void printFibonacci(int n) {
    int t1 = 1, t2 = 1, nextTerm;
    if (n >= 1) printf("Fibonacci Series: %d", t1);
    if (n >= 2) printf(", %d", t2);

    for (int i = 3; i <= n; ++i) {
        nextTerm = t1 + t2;
        printf(", %d", nextTerm);
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}
