#include <stdio.h>
#include "userData.h"
#include "options.h"
#include "order.h"
#include "constants.h"
#include <stdlib.h>
#include <string.h>

int getChoiceIndex();

void readUntil(char *sentence, char *text, char sep, int *i);

int fileExists(char *fname);

int main() {
    FILE *f;
    if (fileExists("data.txt") == 1)
        f = fopen("data.txt", "r");
    else {
        f = stdin;
        fprintf(stdout, "%s\n", LOAD_DATA);
    }

    int cutleryChoice, drinksChoice, nrOfFoods, nrOfDrinks, foodsChoice, specialityChoice, sum = 0;
    char YesNo[][4] = {"Yes", "No"};

    char s[MAX_USERINPUT];
    fgets(s, MAX_USERINPUT, f);
    sscanf(s, "%d", &nrOfFoods);


    char **foodOptions = (char **) malloc(nrOfFoods * sizeof(char *));
    char ***foods = (char ***) malloc(nrOfFoods * sizeof(char **));
    int *noOfSpecialities = (int *) malloc(nrOfFoods * sizeof(int));
    double **prices = (double **) malloc(nrOfFoods * sizeof(double *));
    for (int i = 0; i < nrOfFoods; i++) {
        foodOptions[i] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
        fgets(s, MAX_USERINPUT, f);
        s[strlen(s) - 1] = '\0';
        int j = 0;
        readUntil(foodOptions[i], s, ':', &j);
        noOfSpecialities[i] = 0;
        foods[i] = (char **) malloc((noOfSpecialities[i] + 1) * sizeof(char *));
        prices[i] = (double *) malloc((noOfSpecialities[i] + 1) * sizeof(double));
        while (j < strlen(s)) {
            char dummy[MAX_USERINPUT];
            readUntil(dummy, s, '(', &j);
            foods[i] = realloc(foods[i], (noOfSpecialities[i] + 1) * sizeof(char *));
            prices[i] = realloc(prices[i], (noOfSpecialities[i] + 1) * sizeof(double));
            foods[i][noOfSpecialities[i]] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
            readUntil(foods[i][noOfSpecialities[i]], s, '-', &j);
            readUntil(dummy, s, ')', &j);
            sscanf(dummy, " %lf", &prices[i][noOfSpecialities[i]]);
            noOfSpecialities[i]++;
        }
    }

    fgets(s, MAX_USERINPUT, f);
    sscanf(s, "%d", &nrOfDrinks);
    char **drink = (char **) malloc(nrOfDrinks * sizeof(char *));
    double *drinkPrices = (double *) malloc((nrOfDrinks + 1) * sizeof(double));
    drinkPrices[nrOfDrinks] = 0;
    fgets(s, MAX_USERINPUT, f);
    s[strlen(s) - 1] = '\0';
    int j = 0, i = 0;
    while (j < strlen(s)) {
        char dummy[MAX_USERINPUT];
        drink[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        readUntil(dummy, s, '(', &j);
        readUntil(drink[i], s, '-', &j);
        readUntil(dummy, s, ',', &j);
        sscanf(dummy, " %lf)", &drinkPrices[i]);
        i++;
    }

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
                       YesNo[cutleryChoice], prices[foodsChoice][specialityChoice], drink[drinksChoice], userInput,
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

void readUntil(char *sentence, char *text, char sep, int *i) {

    int j = 0;
    while (text[*i] != sep && (*i) < strlen(text)) {
        sentence[j] = text[*i];
        (*i)++;
        j++;
    }
    sentence[j] = '\0';
    (*i)++;
}

int fileExists(char *fname) {
    FILE *file;
    if ((file = fopen(fname, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}



