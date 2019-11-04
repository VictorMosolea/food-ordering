//
// Created by Victor on 11/3/2019.
//
#include <stdio.h>
#define MAX_FOOD_NAME 10
#define MAX_SPECIALITY_NAME 11
#define MAX_NR_FOODS 3
#define MAX_NR_OF_PRICES 3
#define MAX_DRINK_NAME 10

void printFoodOptions(int nrOfFoods, char foodOptions[][MAX_FOOD_NAME]) {
    printf("Please choose the food you feel like eating today:\n");

    for (int i = 1; i <= nrOfFoods; i++) {
        putchar('a' + i - 1);
        printf(") %s\n", foodOptions[i - 1]);
    }
    printf("d)Go back\n>");
}

void printFoodSpecialities(char foodOptions[MAX_FOOD_NAME], int nrOfFoods, char foods[MAX_NR_FOODS][MAX_SPECIALITY_NAME], int prices[MAX_NR_FOODS]) {
    printf("Please choose the type of %s:\n",foodOptions);
    for(int i=1;i<=nrOfFoods;i++) {
        putchar('a'+i-1);
        printf(") %s %d\n",foods[i-1], prices[i-1]);
    }
    printf("d)Go back\n>");
}

void printDrinkOptions(char foodOptions[MAX_FOOD_NAME], int nrOfDrinks, int drinkPrices[], char drink[][MAX_DRINK_NAME]) {
    printf("Please choose a drink to go with your %s:\n", foodOptions);
    for (int i = 1; i <= nrOfDrinks; i++) {
        putchar('a' + i - 1);
        printf(") %s %d\n", drink[i - 1], drinkPrices[i-1]);

    }
    printf("e) No\nf) Go back\n>");
}

void printCutleryOptions() {
    printf("Do you want any cutlery?\na) Yes\nb) No\nc) Go back\n");
}
