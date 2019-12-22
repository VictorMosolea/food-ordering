//
// Created by Victor on 11/23/2019.
//

#ifndef FOOD_ORDERING_VALIDPASSWORD_H
#define FOOD_ORDERING_VALIDPASSWORD_H

int noUsernameInPassword(user u);

int passwordLacksChars(char *Password);

int passwordContainsDigits(char *Password);

int passwordLongEnough(char *Password);

#endif //FOOD_ORDERING_VALIDPASSWORD_H
