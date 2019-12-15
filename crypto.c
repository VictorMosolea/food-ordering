//
// Created by Victor on 12/8/2019.
//
#include <string.h>

void encryptPassword(char *Password, char *alphabet, char *key) {
    strlwr(Password);
    for (int i = 0; i < strlen(Password); i++) {
        for (int j = 0; j < strlen(alphabet); j++)
            if (Password[i] == alphabet[j]) {
                Password[i] = key[j];
                j = strlen(alphabet);
            }
    }
}

void decryptPassword(char *Password, char *alphabet, char *key) {
    strlwr(Password);
    for (int i = 0; i < strlen(Password); i++) {
        for (int j = 0; j < strlen(key); j++)
            if (Password[i] == key[j]) {
                Password[i] = alphabet[j];
                j = strlen(key);
            }
    }
}
