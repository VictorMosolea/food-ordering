//
// Created by Victor on 11/3/2019.
//
#include <stdio.h>
#include "constants.h"

void printFoodOptions(int nrOfFoods, char **foodOptions) {
    printf("Please choose the food you feel like eating today:\n");

    for (int i = 1; i <= nrOfFoods; i++) {
        putchar('a' + i - 1);
        printf(") %s\n", foodOptions[i - 1]);
    }
   printf("%c) Go back\n",'a'+nrOfFoods);
}

void printFoodSpecialities(char foodOptions[MAX_FOOD_NAME], int nrOfFoods, char **foods, double *prices) {
    printf("Please choose the type of %s:\n",foodOptions);
    for(int i=1;i<=nrOfFoods;i++) {
        putchar('a'+i-1);
        printf(") %s %lf\n",foods[i-1], prices[i-1]);
    }
    printf("%c) Go back\n>",'a'+nrOfFoods);
}

void printDrinkOptions(char foodOptions[MAX_FOOD_NAME], int nrOfDrinks, double *drinkPrices, char **drink) {
    printf("Please choose a drink to go with your %s:\n", foodOptions);
    for (int i = 1; i <= nrOfDrinks; i++) {
        putchar('a' + i - 1);
        printf(") %s %lf\n", drink[i - 1], drinkPrices[i - 1]);
    }
    printf("%c) No\n%c) Go back\n>",nrOfDrinks+'a',nrOfDrinks+1+'a');
}

    void printCutleryOptions() {
    printf("Do you want any cutlery?\na) Yes\nb) No\nc) Go back\n");
}
