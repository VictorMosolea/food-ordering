//
// Created by Victor on 11/3/2019.
//
#include <stdio.h>
#include <string.h>

#define MAX_FOOD_NAME 10
#define MAX_SPECIALITY_NAME 11
#define MAX_NR_FOODS 3
#define MAX_NR_OF_PRICES 3
#define MAX_DRINK_NAME 10

void signIn(char Username[], char Password[]) {

    printf("Welcome to Food Thingies!\n");
    printf("Please sign in to continue\n");
    printf("---Username:\n>");
    gets(Username);
    printf("---Password:\n>");
    gets(Password);
}

void printUserOrder(char Username[], char foodOptions[][MAX_FOOD_NAME], int foodsChoice, char foods[MAX_NR_FOODS][MAX_NR_FOODS][MAX_SPECIALITY_NAME],
                    int specialityChoice, char YesNo[][4], int prices[MAX_NR_FOODS][MAX_NR_OF_PRICES], char drink[][MAX_DRINK_NAME],
                    int drinksChoice, int cutleryChoice, int sum, char userInput[], int drinkPrices[]) {
    printf("This is your order:\n-------------------\n");
    printf("Name: %s\n",Username);
    printf("Food items:\n");
    printf("---%s %s: %d\n",foodOptions[foodsChoice],foods[foodsChoice][specialityChoice],prices[foodsChoice][specialityChoice]);
    printf("---Drink: %s: %d\n",drink[drinksChoice],drinkPrices[drinksChoice]);
    printf("Cutlery: %s\n",YesNo[cutleryChoice]);
    if(strlen(userInput)>0)
        printf("Additional info: %s\n",userInput);
    sum=prices[foodsChoice][specialityChoice]+drinkPrices[drinksChoice];
    printf("Payment amount: %d\n",sum);
    printf("-------------------\n");
}