//
// Created by Victor on 12/8/2019.
//

#ifndef FOOD_ORDERING_MENUDATA_H
#define FOOD_ORDERING_MENUDATA_H
#include <stdio.h>

void storeFoodData(int nrOfFoods, char ***foods, char **foodOptions, int *noOfSpecialities, double **prices, FILE *f);

void storeDrinkData(char **drink, double *drinkPrices, FILE *f);

#endif //FOOD_ORDERING_MENUDATA_H
