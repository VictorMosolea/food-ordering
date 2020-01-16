//
// Created by Victor on 11/6/2019.
#include <stdio.h>
#include "constants.h"
#include "crypto.h"
#include <stdlib.h>
#include "userData.h"

user createUser() {
    user u;
    u.Username = (char *) malloc(MAX_USERNAME * sizeof(char));
    u.Password = (char *) malloc(MAX_PASSWORD * sizeof(char));
    return u;
}

void signIn(user *u) {
    printf("%s\n", SIGNING_IN);
    printf("---Username:\n>");
    gets(u->Username);
    printf("---Password:\n>");
    gets(u->Password);
}

void storeUsers(int noOfUsers, char *alphabet, char *key, user **userDataBase, FILE *g) {
    *userDataBase = (user *) malloc(noOfUsers * sizeof(user));
    char s[MAX_LINE];
    for (int i = 0; i < noOfUsers; i++) {
        (*userDataBase)[i] = createUser();
        fgets(s, MAX_LINE, g);
        sscanf(s, "%s %s", (*userDataBase)[i].Username, (*userDataBase)[i].Password);
        decryptPassword((*userDataBase)[i].Password, alphabet, key);
    }
}