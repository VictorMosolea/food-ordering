#include <stdio.h>
#include "userData&Order.h"
#include "printOptions.h"

int getChoiceIndex();

int main() {
    int cutleryChoice;
    char YesNo[][4]={"Yes","No"};
    int sum=0;
    int drinksChoice;
    int nrOfFoods=3;
    int nrOfDrinks=5;
    char foodOptions[][10] = {"Pizza", "Pasta", "Salad"};
    int foodsChoice;
    int specialityChoice;
    char drink[][10]= {"Fanta","Cola","Lemonade","Water","No"};
    int drinkPrices[]= {5,4,8,6,0};
    char foods[3][3][11] = {
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
    Intro:
       signIn(Username, Password);
    Food:
    {
        printFoodOptions(nrOfFoods, foodOptions);
        foodsChoice=getChoiceIndex();
        if (foodsChoice == 3)
            goto Intro;
        else
            goto FoodPick;
    };

    FoodPick:
    {
        printFoodSpecialities(foodOptions, foodsChoice, nrOfFoods, foods, prices);
           specialityChoice=getChoiceIndex();
            if(specialityChoice==3)
                goto Food;
            else
                goto DrinkPick;

    };

    DrinkPick:
    {
        printDrinkOptions(foodOptions, foodsChoice, nrOfDrinks, drinkPrices, drink);

        drinksChoice = getChoiceIndex();
        if(drinksChoice==5)
            goto FoodPick;
        else
            goto Cutlery;

    };
    Cutlery:
    {
        printCutleryOptions(YesNo);

        cutleryChoice=getChoiceIndex();
        if(cutleryChoice==2)
        {
            sum=sum-drinkPrices[drinksChoice];
            goto DrinkPick;
        }
        else goto End;
    };
    End:
    {   printf("Any additional info?\n");
        gets(userInput);
        printUserOrder(Username, foodOptions, foodsChoice, foods, specialityChoice, YesNo, prices, drink, drinksChoice,
                cutleryChoice, sum, userInput, drinkPrices);
        printf("a) Confirm order\nb) Go back\n>");
        if ('a' != getchar())
            goto Cutlery;
        else
            printf("Order confirmed! Thank you for buying from us, %s!", Username);
    };

    return 0;
}

int getChoiceIndex() {
    char choice = getchar();
    getchar();
    int choiceIndex = choice - 'a';
    return choiceIndex;
}



