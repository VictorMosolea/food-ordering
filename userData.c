//
// Created by Victor on 11/6/2019.
#include <stdio.h>
#include "constants.h"
void signIn(char Username[MAX_USERINPUT], char Password[MAX_USERINPUT]) {

    printf("Welcome to Food Thingies!\n");
    printf("Please sign in to continue\n");
    printf("---Username:\n>");
    gets(Username);
    printf("---Password:\n>");
    gets(Password);
}