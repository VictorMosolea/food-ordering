//
// Created by Victor on 11/3/2019.
//
#ifndef FOOD_ORDERING_PRINTOPTIONS_H
#define FOOD_ORDERING_PRINTOPTIONS_H
#include "constants.h"

void printFoodOptions(int nrOfFoods, char foodOptions[][MAX_FOOD_NAME]);
void printFoodSpecialities(char foodOptions[MAX_FOOD_NAME], int nrOfFoods, char foods[MAX_NR_FOODS][MAX_FOOD_NAME],
                           int prices[MAX_NR_FOODS]);
void printDrinkOptions(char foodOptions[MAX_FOOD_NAME], int nrOfDrinks, int drinkPrices[MAX_NR_DRINKS], char drink[MAX_NR_DRINKS][MAX_DRINK_NAME]);
void printCutleryOptions();


#endif //FOOD_ORDERING_PRINTOPTIONS_H
