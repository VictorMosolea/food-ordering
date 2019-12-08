//
// Created by Victor on 11/23/2019.
//
#include <string.h>
#include <stdio.h>
#include "constants.h"


int userNameExists(char *Username, int noOfUsers, char ***userDataBase) {
    int ok = 0;
    for (int i = 0; i < noOfUsers; i++)
        if (strcmp(Username, userDataBase[i][0]) == 0)
            ok = 1;
    if (ok == 0) {
        printf("%s\n", USER_NOT_FOUND);
        return 0;
    }
}

int passwordCorrect(char *Password, int noOfUsers, char ***userDataBase) {
    int ok = 0;
    for (int i = 0; i < noOfUsers; i++)
        if (strcmp(Password, userDataBase[i][1]) == 0)
            ok = 1;
    if (ok == 0) {
        printf("%s\n", INCORRECT_PASSWORD);
        return 0;
    }
}

int validUsername(char *Username, char ***userDataBase, int noOfUsers) {
    for (int i = 0; i < noOfUsers; i++)
        if (strcmp(Username, userDataBase[i][0]) == 0) {
            printf("%s\n", DUPLICATE_USER);
            return 0;
        }
    return 1;
}


