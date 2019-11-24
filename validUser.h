//
// Created by Victor on 11/23/2019.
//

#ifndef FOOD_ORDERING_VALIDUSER_H
#define FOOD_ORDERING_VALIDUSER_H

int userNameExists(char *Username, int noOfUsers, char ***userDataBase);

int passwordCorrect(char *Password, int noOfUsers, char ***userDataBase);

int validUsername(char *Username, char ***userDataBase, int noOfUsers);

#endif //FOOD_ORDERING_VALIDUSER_H
