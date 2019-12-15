//
// Created by Victor on 11/6/2019.
#include <stdio.h>
#include "constants.h"
#include "crypto.h"
#include <stdlib.h>
void signIn(char Username[MAX_USERNAME], char Password[MAX_PASSWORD]) {
    printf("%s\n", SIGNING_IN);
    printf("---Username:\n>");
    gets(Username);
    printf("---Password:\n>");
    gets(Password);
}

void storeUsers(int noOfUsers, char *alphabet, char *key, char ***userDataBase, FILE *g) {
    char s[MAX_LINE];
    for(int i=0;i<noOfUsers;i++){
        fgets(s, MAX_LINE, g);
        userDataBase[i] = (char **) malloc(2 * sizeof(char *));
        userDataBase[i][0] = (char *) malloc(MAX_USERNAME * sizeof(char));
        userDataBase[i][1] = (char *) malloc(MAX_PASSWORD * sizeof(char));
        sscanf(s, "%s %s", userDataBase[i][0], userDataBase[i][1]);
        decryptPassword(userDataBase[i][1], alphabet, key);
     }
}