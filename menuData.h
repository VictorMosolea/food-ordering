//
// Created by Victor on 12/8/2019.
//

#ifndef FOOD_ORDERING_MENUDATA_H
#define FOOD_ORDERING_MENUDATA_H

#include <stdio.h>


typedef struct speciality {
    char *name;
    double price;
} speciality;

typedef struct foods {
    char *name;
    int noOfSpecialities;
    speciality *specialities;
} foods;

typedef struct drink {
    char *name;
    double price;
} drink;

speciality createSpeciality();

foods createFoods();

drink createDrink();

void storeFoodData(int nrOfFoods, FILE *f, foods *foodOptions);

void storeDrinkData(FILE *f, drink *drinks);

#endif //FOOD_ORDERING_MENUDATA_H
