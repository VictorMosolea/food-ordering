//
// Created by Victor on 12/8/2019.
//
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

void storeFoodData(int nrOfFoods, char ***foods, char **foodOptions, int *noOfSpecialities, double **prices, FILE *f) {
    char s[MAX_LINE];
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
            while (isalpha(s[j])) {
                readUntil(aux, s, '-', &j);
                strcat(foods[i][noOfSpecialities[i]], "-");
                strcat(foods[i][noOfSpecialities[i]], aux);
            }
            readUntil(aux, s, ')', &j);
            sscanf(aux, " %lf", &prices[i][noOfSpecialities[i]]);
            noOfSpecialities[i]++;
        }
    }
}

void storeDrinkData(char **drink, double *drinkPrices, FILE *f) {
    char s[MAX_LINE];
    fgets(s, MAX_LINE, f);
    s[strlen(s) - 1] = '\0';
    int j = 0, i = 0;
    while (j < strlen(s)) {
        char aux[MAX_LINE];
        drink[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        readUntil(aux, s, '(', &j);
        readUntil(drink[i], s, '-', &j);
        while (isalpha(s[j])) {
            readUntil(aux, s, '-', &j);
            strcat(drink[i], "-");
            strcat(drink[i], aux);
        }
        readUntil(aux, s, ',', &j);
        sscanf(aux, " %lf)", &drinkPrices[i]);
        i++;
    }
}

