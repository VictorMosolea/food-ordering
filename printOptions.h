//
// Created by Victor on 11/3/2019.
//
#ifndef FOOD_ORDERING_PRINTOPTIONS_H
#define FOOD_ORDERING_PRINTOPTIONS_H
#define MAX_FOOD_NAME 10
#define MAX_SPECIALITY_NAME 11
#define MAX_NR_FOODS 3
#define MAX_NR_OF_PRICES 3
#define MAX_DRINK_NAME 10

void printFoodOptions(int nrOfFoods, char foodOptions[][MAX_FOOD_NAME]);
void printFoodSpecialities(char foodOptions[][MAX_FOOD_NAME], int foodsChoice, int nrOfFoods, char foods[MAX_NR_FOODS][MAX_NR_FOODS][MAX_SPECIALITY_NAME],
                           int prices[MAX_NR_FOODS][MAX_NR_OF_PRICES]);
void printDrinkOptions(char foodOptions[][MAX_FOOD_NAME], int foodsChoice, int nrOfDrinks, int drinkPrices[], char drink[][MAX_DRINK_NAME]);
void printCutleryOptions(char YesNo[][4]);


#endif //FOOD_ORDERING_PRINTOPTIONS_H
