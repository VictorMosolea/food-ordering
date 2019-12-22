//
// Created by Victor on 11/23/2019.
//
#include <string.h>
#include <stdio.h>
#include "constants.h"
#include "userData.h"

int userNameExists(char *Username, int noOfUsers, user *userDataBase) {
    int ok = 0;
    for (int i = 0; i < noOfUsers; i++)
        if (strcmp(Username, userDataBase[i].Username) == 0)
            ok = 1;
    if (ok == 0) {
        printf("%s\n", USER_NOT_FOUND);
        return 0;
    }
}

int passwordCorrect(char *Password, int noOfUsers, user *userDataBase) {
    int ok = 0;
    for (int i = 0; i < noOfUsers; i++)
        if (strcmp(Password, userDataBase[i].Password) == 0)
            ok = 1;
    if (ok == 0) {
        printf("%s\n", INCORRECT_PASSWORD);
        return 0;
    }
}

int validUsername(char *Username, user *userDataBase, int noOfUsers) {
    for (int i = 0; i < noOfUsers; i++)
        if (strcmp(Username, userDataBase[i].Username) == 0) {
            printf("%s\n", DUPLICATE_USER);
            return 0;
        }
    return 1;
}


