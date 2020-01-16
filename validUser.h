//
// Created by Victor on 11/23/2019.
//

#ifndef FOOD_ORDERING_VALIDUSER_H
#define FOOD_ORDERING_VALIDUSER_H

int userNameExists(char *Username, int noOfUsers, user *userDataBase);

int passwordCorrect(char *Password, int noOfUsers, user *userDataBase);

int validUsername(char *Username, user *userDataBase, int noOfUsers);

#endif //FOOD_ORDERING_VALIDUSER_H
