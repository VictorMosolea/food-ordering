//
// Created by Victor on 11/6/2019.
#include <stdio.h>
#include "constants.h"

void signIn(char Username[MAX_USERNAME], char Password[MAX_PASSWORD]) {
    printf("%s\n", SIGNING_IN);
    printf("---Username:\n>");
    gets(Username);
    printf("---Password:\n>");
    gets(Password);
}