//
// Created by Victor on 11/3/2019.
//
#include <stdio.h>
#include <string.h>


void signIn(char Username[], char Password[]) {

    printf("Welcome to Food Thingies!\n");
    printf("Please sign in to continue\n");
    printf("---Username:\n>");
    gets(Username);
    printf("---Password:\n>");
    gets(Password);
}

void printUserOrder(char Username[], char foodOptions[], char foods[], char YesNo[], int foodPrice, char drink[], int sum, char userInput[], int drinkPrice) {
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