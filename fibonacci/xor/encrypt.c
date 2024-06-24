#include <stdio.h>

int encrypt(int angka, int desimal){

    int byte1, byte2, byte3, byte4;
    byte1 = (angka ^ desimal) &0x000000FF;
    byte2 = (((angka>> 8) ^ desimal) << 8) &0x0000FF00;
    byte3 = (((angka>>16) ^ desimal) << 16) &0x00FF0000;
    byte4 = (((angka>>24) ^ desimal) << 24) &0xFF000000;
    return (byte1 + byte2 + byte3 + byte4);
}
