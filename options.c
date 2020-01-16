//
// Created by Victor on 11/3/2019.
//
#include <stdio.h>
#include "constants.h"
#include "menuData.h"

void printFoodOptions(int nrOfFoods, foods *foodOptions) {
    printf("Please choose the food you feel like eating today:\n");

    for (int i = 1; i <= nrOfFoods; i++) {
        putchar('a' + i - 1);
        printf(") %s\n", foodOptions[i - 1].name);
    }
    printf("%c) Go back\n>", 'a' + nrOfFoods);
}

void printFoodSpecialities(foods chosenFood, int nrOfFoods) {
    printf("Please choose the type of %s:\n", chosenFood.name);
    for (int i = 1; i <= nrOfFoods; i++) {
        putchar('a' + i - 1);
        printf(") %s %.2lf\n", chosenFood.specialities[i - 1].name, chosenFood.specialities[i - 1].price);
    }
    printf("%c) Go back\n>", 'a' + nrOfFoods);
}

void printDrinkOptions(char foodOptions[MAX_FOOD_NAME], int nrOfDrinks, drink *drinks) {
    printf("Please choose a drink to go with your %s:\n", foodOptions);
    for (int i = 1; i <= nrOfDrinks; i++) {
        putchar('a' + i - 1);
        printf(") %s ", drinks[i - 1].name);
        if (drinks[i - 1].price > 0)
            printf("%.2lf\n", drinks[i - 1].price);
    }
    printf("\n%c) Go back\n>", nrOfDrinks + 1 + 'a');
}

void printCutleryOptions() {
    printf("Do you want any cutlery?\na) Yes\nb) No\nc) Go back\n");
}
