#include <stdio.h>

// Deklarasi fungsi sum dan variabel accum
int sum(int x, int y);
extern int accum;

int main() {
    int a = 5, b = 10;
    int result = sum(a, b);
    
    printf("The sum of %d and %d is: %d\n", a, b, result);
    printf("The accumulated value is: %d\n", accum);
    
    return 0;
}
