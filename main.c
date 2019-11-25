#include <stdio.h>
#include "userData.h"
#include "options.h"
#include "order.h"
#include "constants.h"
#include <stdlib.h>
#include <string.h>
#include "validPassword.h"
#include "validUser.h"
#include <ctype.h>

int getChoiceIndex();

void readUntil(char *sentence, char *text, char sep, int *i);

int fileExists(char *fileName);

int main() {
    int cutleryChoice, drinksChoice, nrOfFoods, nrOfDrinks, foodsChoice, specialityChoice, introChoice, noOfUsers = 0;
    char YesNo[][4] = {"Yes", "No"};
    char ***userDataBase = (char ***) malloc(noOfUsers * sizeof(char **));
    char s[MAX_LINE];
    FILE *g;
    g = fopen("userDataBase.txt", "a+");
    while (feof(g) == 0) {
        noOfUsers++;
        userDataBase = realloc(userDataBase, noOfUsers * sizeof(char **));
        userDataBase[noOfUsers - 1] = (char **) malloc(2 * sizeof(char *));
        userDataBase[noOfUsers - 1][0] = (char *) malloc(MAX_USERNAME * sizeof(char));
        userDataBase[noOfUsers - 1][1] = (char *) malloc(MAX_PASSWORD * sizeof(char));
        fgets(s, MAX_LINE, g);
        sscanf(s, "%s %s", userDataBase[noOfUsers - 1][0], userDataBase[noOfUsers - 1][1]);
    }
    FILE *f;
    if (fileExists("data.txt") == 1)
        f = fopen("data.txt", "r");
    else {
        f = stdin;
        fprintf(stdout, "%s\n", LOAD_DATA);
    }
    fgets(s, MAX_LINE, f);
    sscanf(s, "%d", &nrOfFoods);
    char **foodOptions = (char **) malloc(nrOfFoods * sizeof(char *));
    char ***foods = (char ***) malloc(nrOfFoods * sizeof(char **));
    int *noOfSpecialities = (int *) malloc(nrOfFoods * sizeof(int));
    double **prices = (double **) malloc(nrOfFoods * sizeof(double *));
    for (int i = 0; i < nrOfFoods; i++) {
        foodOptions[i] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
        fgets(s, MAX_LINE, f);
        s[strlen(s) - 1] = '\0';
        int j = 0;
        readUntil(foodOptions[i], s, ':', &j);
        noOfSpecialities[i] = 0;
        foods[i] = (char **) malloc((noOfSpecialities[i] + 1) * sizeof(char *));
        prices[i] = (double *) malloc((noOfSpecialities[i] + 1) * sizeof(double));
        while (j < strlen(s)) {
            char aux[MAX_LINE];
            readUntil(aux, s, '(', &j);
            foods[i] = realloc(foods[i], (noOfSpecialities[i] + 1) * sizeof(char *));
            prices[i] = realloc(prices[i], (noOfSpecialities[i] + 1) * sizeof(double));
            foods[i][noOfSpecialities[i]] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
            readUntil(foods[i][noOfSpecialities[i]], s, '-', &j);
            if (isalpha(s[j])) {
                readUntil(aux, s, '-', &j);
                strcat(foods[i][noOfSpecialities[i]], "-");
                strcat(foods[i][noOfSpecialities[i]], aux);
            }
            readUntil(aux, s, ')', &j);
            sscanf(aux, " %lf", &prices[i][noOfSpecialities[i]]);
            noOfSpecialities[i]++;
        }
    }
    fgets(s, MAX_LINE, f);
    sscanf(s, "%d", &nrOfDrinks);
    char **drink = (char **) malloc(nrOfDrinks * sizeof(char *));
    double *drinkPrices = (double *) malloc((nrOfDrinks + 1) * sizeof(double));
    drinkPrices[nrOfDrinks] = 0;
    fgets(s, MAX_LINE, f);
    s[strlen(s) - 1] = '\0';
    int j = 0, i = 0;
    while (j < strlen(s)) {
        char aux[MAX_LINE];
        drink[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        readUntil(aux, s, '(', &j);
        readUntil(drink[i], s, '-', &j);
        if (isalpha(s[j])) {
            readUntil(aux, s, '-', &j);
            strcat(drink[i], "-");
            strcat(drink[i], aux);
        }
        readUntil(aux, s, ',', &j);
        sscanf(aux, " %lf)", &drinkPrices[i]);
        i++;
    }
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
                printf("Password:\n");
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
                fprintf(g, "\n%s %s", Username, Password);
                goto Food;
            };
    };
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

    for (i = 0; i < nrOfFoods; i++) {
        for (j = 0; j < noOfSpecialities[i]; j++)
            free(foods[i][j]);
        free(prices[i]);
        free(foodOptions[i]);
        free(foods[i]);
    }
    free(prices);
    free(foodOptions);
    free(foods);

    for (i = 0; i < nrOfDrinks; i++)
        free(drink[i]);
    free(drink);
    free(drinkPrices);

    for (i = 0; i < noOfUsers; i++) {
        for (j = 0; j < 2; j++)
            free(userDataBase[i][j]);
        free(userDataBase[i]);
    }
    free(userDataBase);

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

int fileExists(char *fileName) {
    FILE *file;
    if ((file = fopen(fileName, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}





