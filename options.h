//
// Created by Victor on 11/3/2019.
//
#ifndef FOOD_ORDERING_OPTIONS_H
#define FOOD_ORDERING_OPTIONS_H

#include "constants.h"
#include "menuData.h"

void printFoodOptions(int nrOfFoods, foods *foodOptions);

void printFoodSpecialities(foods chosenFood, int nrOfFoods);

void printDrinkOptions(char foodOptions[MAX_FOOD_NAME], int nrOfDrinks, drink *drinks);

void printCutleryOptions();


#endif //FOOD_ORDERING_OPTIONS_H
