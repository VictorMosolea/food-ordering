#include <stdio.h>
#include "getUserData.h"
#include "printOptions.h"
#include "printOrder.h"
#include "constants.h"

int getChoiceIndex();

int cutleryChoice;
char YesNo[][4]={"Yes","No"};
int sum=0;
int drinksChoice;
int nrOfFoods=3;
int nrOfDrinks=4;
char foodOptions[3][MAX_FOOD_NAME] = {"Pizza", "Pasta", "Salad"};
int foodsChoice;
int specialityChoice;
char drink[][MAX_DRINK_NAME]= {"Fanta","Cola","Lemonade","Water","No"};
int drinkPrices[]= {5,4,8,6,0};
char foods[3][3][MAX_FOOD_NAME] = {
        {"Margherita", "Diavola", "Caro"},
        {"Canneloni",  "Ravioli", "Lasagna"},
        {"Nicoise",    "Cobb",    "Caesar"}
};
int prices[3][3] = {
        {19, 16, 24},
        {23, 22, 28},
        {20, 21, 25}
};
char Username[20];
char Password[20];
char userInput[20];

int main() {
    Intro:
       signIn(Username, Password);
    Food: {
    printFoodOptions(nrOfFoods,foodOptions);
        foodsChoice=getChoiceIndex();
        if (foodsChoice == 3)
            goto Intro;
        else
            goto FoodPick;
    };
    FoodPick: {
        printFoodSpecialities(foodOptions[foodsChoice], nrOfFoods, foods[foodsChoice], prices[foodsChoice]);
           specialityChoice=getChoiceIndex();
            if(specialityChoice==3)
                goto Food;
            else
                goto DrinkPick;
       };
    DrinkPick: {
        printDrinkOptions(foodOptions[foodsChoice], nrOfDrinks, drinkPrices, drink);
        drinksChoice=getChoiceIndex();
        if(drinksChoice==5)
            goto FoodPick;
        else
            goto Cutlery;
       };
    Cutlery: {
        printCutleryOptions();
        cutleryChoice=getChoiceIndex();
        if (cutleryChoice==2)
            goto DrinkPick;
        else
            goto End;
       };
    End: {   printf("Any additional info?\n");
        gets(userInput);
        printUserOrder(Username, foodOptions[foodsChoice], foods[foodsChoice][specialityChoice],
                YesNo[cutleryChoice], prices[foodsChoice][specialityChoice], drink[drinksChoice], sum, userInput, drinkPrices[drinksChoice]);
        printf("a) Confirm order\nb) Go back\n>");
        int choice=getChoiceIndex();
        if (choice==1)
            goto Cutlery;
        else
            printf("Order confirmed! Thank you for buying from us, %s!", Username);
       };
    return 0;
}

int getChoiceIndex() {
    char choice;
    choice = getchar();
    getchar();
    int choiceIndex = choice - 'a';
    return choiceIndex;
}



