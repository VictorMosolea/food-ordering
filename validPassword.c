//
// Created by Victor on 11/23/2019.
//
#include "constants.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lowerString(char *string);

int noUsernameInPassword(char *Username, char *Password) {
    char lowerPassword[MAX_PASSWORD];
    strcpy(lowerPassword, Password);
    char lowerUsername[MAX_USERNAME];
    strcpy(lowerUsername, Username);
    lowerString(lowerUsername);
    lowerString(lowerPassword);
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

void lowerString(char *string) {
    for (int i = 0; i < strlen(string); i++)
        string[i] = tolower(string[i]);
}
