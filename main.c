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

void freeMemory(user u, user *userDataBase, foods *foodOptions, drink *drinks, int noOfUsers, int nrOfFoods, int nrOfDrinks);

int main() {
    int cutleryChoice, drinksChoice, noOfFoods, noOfDrinks, foodsChoice, specialityChoice, introChoice, noOfUsers, newUser = 0;
    char YesNo[][4] = {"Yes", "No"};
    char s[MAX_LINE];
    FILE *g;
    g = fopen("userDataBase.txt", "r+");
    char alphabet[MAX_LINE], key[MAX_LINE];
    fscanf(g, "%s %s", alphabet, key);
    fgetc(g);
    fgets(s, MAX_LINE, g);
    sscanf(s, "%d", &noOfUsers);
    user *userDataBase;
    storeUsers(noOfUsers, alphabet, key, &userDataBase, g);
    FILE *f;
    if (fileExists("data.txt") == 1)
        f = fopen("data.txt", "r");
    else {
        f = stdin;
        fprintf(stdout, "%s\n", LOAD_DATA);
    }
    //storing menu data
    fgets(s, MAX_LINE, f);
    sscanf(s, "%d:", &noOfFoods);
    foods *foodOptions = (foods *) malloc(noOfFoods * sizeof(foods));
    storeFoodData(noOfFoods, f, foodOptions);
    fgets(s, MAX_LINE, f);
    sscanf(s, "%d:", &noOfDrinks);
    drink *drinks = (drink *) malloc((noOfDrinks) + 1 * sizeof(drink));
    storeDrinkData(f, drinks);
    char userInput[MAX_LINE];
    printf("Welcome to Food Thingies!\n");
    user u = createUser();
    Intro:
    {
        printf("%s\na) %s\nb) %s\n>", SIGN_IN_UP, SIGN_IN, SIGN_UP);
        introChoice = getChoiceIndex();
        if (introChoice == 0) {
            signIn(&u);
            if (userNameExists(u.Username, noOfUsers, userDataBase) == 0)
                goto Intro;
            IncorrectPassword:
            if (passwordCorrect(u.Password, noOfUsers, userDataBase) == 0) {
                printf("Password:\n");
                gets(u.Password);
                goto IncorrectPassword;
            }
            goto Food;
        } else
            SignUp:
            {
                printf("%s\n", SIGNING_UP);
                printf("Username:\n>");
                gets(u.Username);
                printf("Password:\n>");
                PasswordError:
                gets(u.Password);
                if (validUsername(u.Username, userDataBase, noOfUsers) == 0)
                    goto SignUp;
                if (passwordLongEnough(u.Password) == 0)
                    goto PasswordError;
                if (noUsernameInPassword(u) == 0)
                    goto PasswordError;
                if (passwordLacksChars(u.Password) == 1)
                    goto PasswordError;
                if (passwordContainsDigits(u.Password) == 0)
                    goto PasswordError;
                newUser = 1;
                goto Food;
            };
    };
    Food:
    {
        printFoodOptions(noOfFoods, foodOptions);
        foodsChoice = getChoiceIndex();
        if (foodsChoice == noOfFoods) {
            if (newUser == 1)
                newUser = 0;
            goto Intro;
        } else goto FoodPick;
    };
    FoodPick:
    {
        printFoodSpecialities(foodOptions[foodsChoice], foodOptions[foodsChoice].noOfSpecialities);
        specialityChoice = getChoiceIndex();
        if (specialityChoice == foodOptions[foodsChoice].noOfSpecialities)
            goto Food;
        else goto DrinkPick;
    };
    DrinkPick:
    {
        printDrinkOptions(foodOptions[foodsChoice].name, noOfDrinks, drinks);
        drinksChoice = getChoiceIndex();
        if (drinksChoice == noOfDrinks + 1)
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
        printUserOrder(u.Username, foodOptions[foodsChoice].name,
                       foodOptions[foodsChoice].specialities[specialityChoice].name,
                       YesNo[cutleryChoice], foodOptions[foodsChoice].specialities[specialityChoice].price, userInput,
                       drinks[drinksChoice]);
        printf("a) Confirm order\nb) Go back\n>");
        int choice = getChoiceIndex();
        if (choice == 1)
            goto Cutlery;
        else printf("Order confirmed! Thank you for buying from us, %s!", u.Username);
    };
    if (newUser == 1) {
        noOfUsers++;
        encryptPassword(u.Password, alphabet, key);
        fgetc(g);
        fseek(g, strlen(alphabet) + strlen(key) + 3, SEEK_SET);
        fprintf(g, "%d", noOfUsers);
        fclose(g);
        g = fopen("userDataBase.txt", "a+");
        fprintf(g, "\n%s %s", u.Username, u.Password);
    }

    freeMemory(u, userDataBase, foodOptions, drinks, noOfUsers, noOfFoods, noOfDrinks);

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

void freeMemory(user u, user *userDataBase, foods *foodOptions, drink *drinks, int noOfUsers, int noOfFoods, int noOfDrinks) {
    free(u.Username);
    free(u.Password);
    /*for (int i = 0; i < noOfUsers; i++) {
        free(userDataBase[i].Username);
        free(userDataBase[i].Password);
    }*/ //this doesn't work for some reason
    free(userDataBase);
    for (int i = 0; i < noOfFoods; i++) {
        for (int j = 0; j < foodOptions[i].noOfSpecialities; j++)
            free(foodOptions[i].specialities[j].name);
        free(foodOptions[i].specialities);
        free(foodOptions[i].name);
    }
    free(foodOptions);
    for(int i=0;i<noOfDrinks;i++)
        free(drinks[i].name);
    free(drinks);
}









