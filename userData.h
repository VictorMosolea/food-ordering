//
// Created by Victor on 11/6/2019.
//

#ifndef FOOD_ORDERING_USERDATA_H
#define FOOD_ORDERING_USERDATA_H

#include "constants.h"

void signIn(char Username[MAX_USERNAME], char Password[MAX_PASSWORD]);

void storeUsers(int noOfUsers, char *alphabet, char *key, char ***userDataBase, FILE *g);

#endif //FOOD_ORDERING_USERDATA_H
