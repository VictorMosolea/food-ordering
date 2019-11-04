//
// Created by Victor on 11/3/2019.
//
#ifndef FOOD_ORDERING_PRINTOPTIONS_H
#define FOOD_ORDERING_PRINTOPTIONS_H
#define MAX_FOOD_NAME 10
#define MAX_SPECIALITY_NAME 11
#define MAX_NR_FOODS 3
#define MAX_DRINK_NAME 10

void printFoodOptions(int nrOfFoods, char foodOptions[][MAX_FOOD_NAME]);
void printFoodSpecialities(char foodOptions[MAX_FOOD_NAME], int nrOfFoods, char foods[MAX_NR_FOODS][MAX_SPECIALITY_NAME],
                           int prices[MAX_NR_FOODS]);
void printDrinkOptions(char foodOptions[MAX_FOOD_NAME], int nrOfDrinks, int drinkPrices[], char drink[][MAX_DRINK_NAME]);
void printCutleryOptions();


#endif //FOOD_ORDERING_PRINTOPTIONS_H
