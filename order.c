//
// Created by Victor on 11/6/2019.
//
#include <stdio.h>
#include <string.h>
#include "constants.h"

void printUserOrder(char Username[MAX_USERINPUT], char foodOptions[MAX_FOOD_NAME], char foods[MAX_FOOD_NAME], char YesNo[],
        int foodPrice, char drink[MAX_DRINK_NAME], int sum, char userInput[MAX_USERINPUT], int drinkPrice) {
    printf("This is your order:\n-------------------\n");
    printf("Name: %s\n",Username);
    printf("Food items:\n");
    printf("---%s %s: %d\n",foodOptions, foods, foodPrice);
    if(drinkPrice!=0)
        printf("---Drink: %s: %d\n", drink, drinkPrice);
    printf("Cutlery: %s\n", YesNo);
    if(strlen(userInput)>0)
        printf("Additional info: %s\n", userInput);
    sum=foodPrice+drinkPrice;
    printf("Payment amount: %d\n", sum);
    printf("-------------------\n");
}
