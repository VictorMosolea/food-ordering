#include <stdio.h>
#include "userData.h"
#include "options.h"
#include "order.h"
#include "constants.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getChoiceIndex();

void readUntil(char *sentence, char sep) {
    char c;
    c = getchar();
    while (c == '\n') c = getchar();
    int i = 0;
    while (c != sep) {
        sentence[i] = c;
        c = getchar();
        i++;
    }

    sentence[i] = '\0';
}

int main() {
    int cutleryChoice, drinksChoice, nrOfFoods, nrOfDrinks, foodsChoice, specialityChoice, sum = 0;
    char YesNo[][4] = {"Yes", "No"};
    printf("%s\n", LOAD_DATA);
    scanf("%d", &nrOfFoods);

    double **prices = (double **) malloc(nrOfFoods * sizeof(double *));
    char **foodOptions = (char **) malloc(nrOfFoods * sizeof(char *));
    char ***foods = (char ***) malloc(nrOfFoods * sizeof(char **));
    int *noOfSpecialities = (int *) malloc(nrOfFoods * sizeof(int));

    for (int i = 0; i < nrOfFoods; i++) {
        foodOptions[i] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
        readUntil(foodOptions[i], ':');
        noOfSpecialities[i] = 0;
        foods[i] = (char **) malloc((noOfSpecialities[i] + 1) * sizeof(char *));
        prices[i] = (double *) malloc((noOfSpecialities[i] + 1) * sizeof(double));
        char c = getchar();
        while (c != '\n') {
            char dummy[MAX_USERINPUT];
            if (c != '(') // in case user inputs something like ")("
                readUntil(dummy, '(');
            foods[i] = realloc(foods[i], (noOfSpecialities[i] + 1) * sizeof(char *));
            foods[i][noOfSpecialities[i]] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
            readUntil(foods[i][noOfSpecialities[i]], '-');
            prices[i] = realloc(prices[i], (noOfSpecialities[i] + 1) * sizeof(double));
            scanf("%lf", &prices[i][noOfSpecialities[i]]);
            readUntil(dummy, ')');
            noOfSpecialities[i]++;
            c = getchar();
        }
    }

    scanf("%d", &nrOfDrinks);
    char **drink = (char **) malloc(nrOfDrinks * sizeof(char *));
    double *drinkPrices = (double *) malloc((nrOfDrinks + 1) * sizeof(double));
    drinkPrices[nrOfDrinks + 1] = 0;
    for (int i = 0; i < nrOfDrinks; i++) {
        drink[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        char dummy[MAX_USERINPUT];
        readUntil(dummy, '(');
        readUntil(drink[i], '-');
        scanf("%lf", &drinkPrices[i]);
        readUntil(dummy, ')');
    }
    getchar();
    char Username[MAX_USERINPUT], Password[MAX_USERINPUT], userInput[MAX_USERINPUT];
    Intro:
    signIn(Username, Password);
    Food:
    {
        printFoodOptions(nrOfFoods, foodOptions);
        foodsChoice = getChoiceIndex();
        if (foodsChoice == nrOfFoods)
            goto Intro;
        else goto FoodPick;
    };
    FoodPick:
    {
        printFoodSpecialities(foodOptions[foodsChoice], noOfSpecialities[foodsChoice], foods[foodsChoice],
                              prices[foodsChoice]);
        specialityChoice = getChoiceIndex();
        if (specialityChoice == noOfSpecialities[foodsChoice])
            goto Food;
        else goto DrinkPick;
    };
    DrinkPick:
    {
        printDrinkOptions(foodOptions[foodsChoice], nrOfDrinks, drinkPrices, drink);
        drinksChoice = getChoiceIndex();
        if (drinksChoice == nrOfDrinks + 1)
            goto FoodPick;
        else goto Cutlery;
    };
    Cutlery:
    {
        printCutleryOptions();
        cutleryChoice = getChoiceIndex();
        if (cutleryChoice == 2)
            goto DrinkPick;
        else goto End;
    };
    End:
    {
        printf("Any additional info?\n");
        gets(userInput);
        printUserOrder(Username, foodOptions[foodsChoice], foods[foodsChoice][specialityChoice],
                       YesNo[cutleryChoice], prices[foodsChoice][specialityChoice], drink[drinksChoice],userInput,
                       drinkPrices[drinksChoice]);
        printf("a) Confirm order\nb) Go back\n>");
        int choice = getChoiceIndex();
        if (choice == 1)
            goto Cutlery;
        else printf("Order confirmed! Thank you for buying from us, %s!", Username);
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



