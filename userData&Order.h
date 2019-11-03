//
// Created by Victor on 11/3/2019.
//
#ifndef FOOD_ORDERING_USERDATA_ORDER_H
#define FOOD_ORDERING_USERDATA_ORDER_H
#define MAX_FOOD_NAME 10
#define MAX_SPECIALITY_NAME 11
#define MAX_NR_FOODS 3
#define MAX_NR_OF_PRICES 3
#define MAX_DRINK_NAME 10

void signIn(char Username[], char Password[]);
void printUserOrder(char Username[], char foodOptions[][MAX_FOOD_NAME], int foodsChoice, char foods[MAX_NR_FOODS][MAX_NR_FOODS][MAX_SPECIALITY_NAME], int specialityChoice,
                    char YesNo[][4], int prices[MAX_NR_FOODS][MAX_NR_OF_PRICES], char drink[][MAX_DRINK_NAME], int drinksChoice, int cutleryChoice, int sum, char userInput[], int drinkPrices[]);

#endif //FOOD_ORDERING_USERDATA_ORDER_H
