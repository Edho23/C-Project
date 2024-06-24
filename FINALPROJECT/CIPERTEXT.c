#include <stdio.h>
#include <string.h>

void encrypt(char *plaintext, int shift) {
    for (int i = 0; i , strlen(plaintext); i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = 'A' + (plaintext[i] - 'A' + shift) % 26;
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = 'A' + (plaintext[i] - 'a' + shift) % 26;
        }
    }
}

void decrypt(char *ciphertext, int shift) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext [i] >= 'A' && ciphertext[i] <= 'Z') {
            ciphertext[i] = 'A' + (ciphertext[i] - 'A' - shift + 26) % 26;
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            ciphertext[i] = 'a' + (ciphertext[i] - 'a' - shift + 26) % 26;
        }
    }
}

int main () {
    char plaintext [] = "SAYA MENGIKUTI MATA KULIAH MATEMATIKA DISKRIT DAN LOGIKA";
    int shift = 3;

    printf("plaintext: %s\n", plaintext);

    encrypt(plaintext, shift);
    printf("Ciphertext: %s\n", plaintext);

    return 0;
}