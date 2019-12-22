//
// Created by Victor on 12/8/2019.
//
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "menuData.h"

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

speciality createSpeciality() {
    speciality s;
    s.name = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
    return s;
}

foods createFoods() {
    foods f;
    f.name = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
    return f;
}

drink createDrink() {
    drink d;
    d.name = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
    return d;
}

void storeFoodData(int nrOfFoods, FILE *f, foods *foodOptions) {
    char s[MAX_LINE];
    for (int i = 0; i < nrOfFoods; i++) {
        foodOptions[i] = createFoods();
        fgets(s, MAX_LINE, f);
        s[strlen(s) - 1] = '\0';
        int j = 0;
        readUntil(foodOptions[i].name, s, ':', &j);
        foodOptions[i].noOfSpecialities = 0;
        foodOptions[i].specialities = (speciality *) malloc((foodOptions[i].noOfSpecialities + 1) * sizeof(speciality));
        while (j < strlen(s)) {
            char aux[MAX_LINE];
            readUntil(aux, s, '(', &j);
            foodOptions[i].specialities = realloc(foodOptions[i].specialities,
                                                  (foodOptions[i].noOfSpecialities + 1) * sizeof(speciality));
            foodOptions[i].specialities[foodOptions[i].noOfSpecialities] = createSpeciality();
            readUntil(foodOptions[i].specialities[foodOptions[i].noOfSpecialities].name, s, '-', &j);
            while (isalpha(s[j])) {
                readUntil(aux, s, '-', &j);
                strcat(foodOptions[i].specialities[foodOptions[i].noOfSpecialities].name, "-");
                strcat(foodOptions[i].specialities[foodOptions[i].noOfSpecialities].name, aux);
            }
            readUntil(aux, s, ')', &j);
            sscanf(aux, " %lf", &foodOptions[i].specialities[foodOptions[i].noOfSpecialities].price);
            foodOptions[i].noOfSpecialities++;
        }
    }
}

void storeDrinkData(FILE *f, drink *drinks) {
    char s[MAX_LINE];
    fgets(s, MAX_LINE, f);
    s[strlen(s) - 1] = '\0';
    int j = 0, i = 0;
    while (j < strlen(s)) {
        char aux[MAX_LINE];
        drinks[i] = createDrink();
        readUntil(aux, s, '(', &j);
        readUntil(drinks[i].name, s, '-', &j);
        while (isalpha(s[j])) {
            readUntil(aux, s, '-', &j);
            strcat(drinks[i].name, "-");
            strcat(drinks[i].name, aux);
        }
        readUntil(aux, s, ',', &j);
        sscanf(aux, " %lf)", &drinks[i].price);
        i++;
    }
    drinks[i] = createDrink();
    drinks[i].name = "No";
    drinks[i].price = 0;
}

