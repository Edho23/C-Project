#include <stdio.h>
#include <stdlib.h>

int binerTodecimal(int num) {
    int result = 0;
    int sign = 1;
    if (num < 0) {
        sign = -1;
        num = ~num + 1;
    }
    while (num > 0) {
        result = (result << 1) | (num & 1);
        num >>= 1;
    }
    return result * sign;
}
