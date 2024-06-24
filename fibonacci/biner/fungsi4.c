#include <stdio.h>
#include <stdlib.h>

int pengurangan(int a, int b) {
    // Konversi dari bilangan biner ke desimal
    int num1 = binerTodecimal(a);
    int num2 = binerTodecimal(b);

    // Pengurangan pada bilangan desimal
    int result = num1 - num2;

    // Konversi dari desimal ke bilangan biner
    return decimalTobiner(result);
}
