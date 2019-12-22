//
// Created by Victor on 11/23/2019.
//
#include "constants.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "userData.h"

int noUsernameInPassword(user u) {
    char lowerPassword[MAX_PASSWORD];
    strcpy(lowerPassword, u.Password);
    char lowerUsername[MAX_USERNAME];
    strcpy(lowerUsername, u.Username);
    strlwr(lowerUsername);
    strlwr(lowerPassword);
    if (strstr(lowerPassword, lowerUsername) != NULL) {
        printf("%s\n", ERROR_PASSWORD_NOT_USERNAME);
        return 0;
    }
    return 1;
}

int passwordLacksChars(char *Password) {
    char dummy[MAX_LINE];
    strcpy(dummy, Password);
    if (strcmp(strtok(dummy, "!._"), Password) == 0) {
        printf("%s\n", ERROR_PASSWORD_SPECIAL_CHAR);
        return 1;
    }
    return 0;
}

int passwordContainsDigits(char *Password) {
    int ok = 0;
    for (int i = 0; i < strlen(Password); i++)
        if (isdigit(Password[i]))
            ok = 1;
    if (ok == 0) {
        printf("%s\n", ERROR_PASSWORD_DIGITS);
        return 0;
    }
    return 1;
}

int passwordLongEnough(char *Password) {
    if (strlen(Password) < 7) {
        printf("%s\n", ERROR_PASSWORD_LONG);
        return 0;
    }
    return 1;
}
