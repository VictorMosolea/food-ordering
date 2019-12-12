#include <stdio.h>
#include "userData.h"
#include "options.h"
#include "order.h"
#include "constants.h"
#include <stdlib.h>
#include "validPassword.h"
#include "validUser.h"
#include "crypto.h"
#include "menuData.h"
#include <string.h>

int getChoiceIndex();

int fileExists(char *fileName);

void
freeMemory(int nrOfFoods, int *noOfSpecialities, char ***foods, double **prices, char **foodOptions, int nrOfDrinks,
           char **drink, double *drinkPrices,
           int noOfUsers, char ***userDataBase);

int main() {
    int cutleryChoice, drinksChoice, nrOfFoods, nrOfDrinks, foodsChoice, specialityChoice, introChoice, noOfUsers, newUser = 0;
    char YesNo[][4] = {"Yes", "No"};
    char s[MAX_LINE];
    FILE *g;
    g = fopen("userDataBase.txt", "r+");
    char alphabet[MAX_LINE], key[MAX_LINE];
    fscanf(g, "%s %s", alphabet, key);
    fgetc(g);
    fgets(s, MAX_LINE, g);
    sscanf(s, "%d", &noOfUsers);
    char ***userDataBase = (char ***) malloc(noOfUsers * sizeof(char **));
    storeUsers(noOfUsers, alphabet, key, userDataBase, g);
    FILE *f;
    if (fileExists("data.txt") == 1)
        f = fopen("data.txt", "r");
    else {
        f = stdin;
        fprintf(stdout, "%s\n", LOAD_DATA);
    }
    //storing menu data
    fgets(s, MAX_LINE, f);
    sscanf(s, "%d:", &nrOfFoods);
    char **foodOptions = (char **) malloc(nrOfFoods * sizeof(char *));
    char ***foods = (char ***) malloc(nrOfFoods * sizeof(char **));
    int *noOfSpecialities = (int *) malloc(nrOfFoods * sizeof(int));
    double **prices = (double **) malloc(nrOfFoods * sizeof(double *));
    storeFoodData(nrOfFoods, foods, foodOptions, noOfSpecialities, prices, f);
    fgets(s, MAX_LINE, f);
    sscanf(s, "%d:", &nrOfDrinks);
    char **drink = (char **) malloc(nrOfDrinks * sizeof(char *));
    double *drinkPrices = (double *) malloc((nrOfDrinks + 1) * sizeof(double));
    drinkPrices[nrOfDrinks] = 0;
    storeDrinkData(drink, drinkPrices, f);
    char Username[MAX_USERNAME], Password[MAX_PASSWORD], userInput[MAX_LINE];

    printf("Welcome to Food Thingies!\n");
    Intro:
    {
        printf("%s\na) %s\nb) %s\n>", SIGN_IN_UP, SIGN_IN, SIGN_UP);
        introChoice = getChoiceIndex();
        if (introChoice == 0) {
            signIn(Username, Password);
            if (userNameExists(Username, noOfUsers, userDataBase) == 0)
                goto Intro;
            IncorrectPassword:
            if (passwordCorrect(Password, noOfUsers, userDataBase) == 0) {
                printf("Password:\n");
                gets(Password);
                goto IncorrectPassword;
            }
            goto Food;
        } else
            SignUp:
            {
                printf("%s\n", SIGNING_UP);
                printf("Username:\n>");
                gets(Username);
                printf("Password:\n>");
                PasswordError:
                printf(">");
                gets(Password);
                if (validUsername(Username, userDataBase, noOfUsers) == 0)
                    goto SignUp;
                if (passwordLongEnough(Password) == 0)
                    goto PasswordError;
                if (noUsernameInPassword(Username, Password) == 0)
                    goto PasswordError;
                if (passwordLacksChars(Password) == 1)
                    goto PasswordError;
                if (passwordContainsDigits(Password) == 0)
                    goto PasswordError;
                newUser = 1;
                goto Food;
            };
    };
    Food:
    {
        printFoodOptions(nrOfFoods, foodOptions);
        foodsChoice = getChoiceIndex();
        if (foodsChoice == nrOfFoods) {
            if (newUser == 1)
                newUser = 0;
            goto Intro;
        } else goto FoodPick;
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
    if (newUser == 1) {
        noOfUsers++;
        encryptPassword(Password, alphabet, key);
        fgetc(g);
        fseek(g, strlen(alphabet) + strlen(key) + 3, SEEK_SET);
        fprintf(g, "%d", noOfUsers);
        fclose(g);
        g = fopen("userDataBase.txt", "a+");
        fprintf(g, "\n%s %s", Username, Password);
    }

    freeMemory(nrOfFoods, noOfSpecialities, foods, prices, foodOptions, nrOfDrinks,
               drink, drinkPrices,
               noOfUsers, userDataBase);
    return 0;
}

int getChoiceIndex() {
    char choice;
    choice = getchar();
    getchar();
    int choiceIndex = choice - 'a';
    return choiceIndex;
}

int fileExists(char *fileName) {
    FILE *file;
    if ((file = fopen(fileName, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

void
freeMemory(int nrOfFoods, int *noOfSpecialities, char ***foods, double **prices, char **foodOptions, int nrOfDrinks,
           char **drink, double *drinkPrices,
           int noOfUsers, char ***userDataBase) {
    for (int i = 0; i < nrOfFoods; i++) {
        for (int j = 0; j < noOfSpecialities[i]; j++)
            free(foods[i][j]);
        free(prices[i]);
        free(foodOptions[i]);
        free(foods[i]);
    }
    free(prices);
    free(foodOptions);
    free(foods);
    free(noOfSpecialities);

    for (int i = 0; i < nrOfDrinks; i++)
        free(drink[i]);
    free(drink);
    free(drinkPrices);

    /*for (int i = 0; i < noOfUsers; i++) {
        for (int j = 0; j < 2; j++)
            free(userDataBase[i][j]);
        free(userDataBase[i]);
    }
    free(userDataBase);*/ //this doesn't work for some reason
}








