//[
// Created by Victor on 11/6/2019.
//
#include <stdio.h>
#include <string.h>
#include "constants.h"

void printUserOrder(char Username[MAX_USERINPUT], char foodOptions[MAX_FOOD_NAME], char foods[MAX_FOOD_NAME], char YesNo[],
        double foodPrice, char drink[MAX_DRINK_NAME], char userInput[MAX_USERINPUT], double drinkPrice) {
    printf("This is your order:\n-------------------\n");
    printf("Name: %s\n",Username);
    printf("Food items:\n");
    printf("---%s %s: %.2lf\n",foodOptions, foods, foodPrice);
    if(drinkPrice!=0)
        printf("---Drink: %s: %.2lf\n", drink, drinkPrice);
    printf("Cutlery: %s\n", YesNo);
    if(strlen(userInput)>0)
        printf("Additional info: %s\n", userInput);
    double sum=foodPrice+drinkPrice;
    printf("Payment amount: %.2lf\n", sum);
    printf("-------------------\n");
}
