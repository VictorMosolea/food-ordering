//
// Created by Victor on 11/3/2019.
//
#ifndef FOOD_ORDERING_OPTIONS_H
#define FOOD_ORDERING_OPTIONS_H

#include "constants.h"

void printFoodOptions(int nrOfFoods, char **foodOptions);

void printFoodSpecialities(char foodOptions[MAX_FOOD_NAME], int nrOfFoods, char **foods,
                           double *prices);

void printDrinkOptions(char foodOptions[MAX_FOOD_NAME], int nrOfDrinks, double *drinkPrices, char **drink);

void printCutleryOptions();


#endif //FOOD_ORDERING_OPTIONS_H
