//
// Created by Victor on 11/6/2019.
//

#ifndef FOOD_ORDERING_USERDATA_H
#define FOOD_ORDERING_USERDATA_H

#include "constants.h"

typedef struct _user {
    char *Username;
    char *Password;
} user;

void signIn(user *u);

void storeUsers(int noOfUsers, char *alphabet, char *key, user **userDataBase, FILE *g);

user createUser();


#endif //FOOD_ORDERING_USERDATA_H
