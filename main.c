#include <stdio.h>
#include <string.h>


int main() {
    int cutleryChoice;

    char YesNo[][4]={"Yes","No"};

    int sum=0;

    int drinksChoice;

    int nrOfFoods=3;

    int nrOfDrinks=5;

    char foodOptions[][10] = {"Pizza", "Pasta", "Salad"};

    int foodsChoice;

    char choice;

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
    Intro:
    {   sum=0;
        printf("Welcome to Food Thingies!\n");
        printf("Please sign in to continue\n");
        printf("---Username:\n>");
        gets(Username);
        printf("---Password:\n>");
        gets(Password);
    };
    Food:
    {
        printf("Please choose the food you feel like eating today:\n");

        for (int i = 1; i <= nrOfFoods; i++) {
            putchar('a' + i - 1);
            printf(") %s\n", foodOptions[i - 1]);
        }
        printf("d)Go back\n>");
        choice = getchar();
        getchar();
        foodsChoice = choice - 'a';
        if (foodsChoice == 3)
            goto Intro;
        else
            goto FoodPick;
    };

    FoodPick:
    {
        printf("Please choose the type of %s:\n",foodOptions[foodsChoice]);
        for(int i=1;i<=nrOfFoods;i++) {
                putchar('a'+i-1);
                printf(") %s %d\n",foods[foodsChoice][i-1], prices[foodsChoice][i-1]);
            }
            printf("d)Go back\n>");
            choice=getchar();
            getchar();
              specialityChoice=choice-'a';
            if(specialityChoice==3)
                goto Food;
            else
                goto DrinkPick;

    };

    DrinkPick:
    {
        printf("Please choose a drink to go with your %s:\n",foodOptions[foodsChoice]);
        for(int i=1;i<=nrOfDrinks;i++) {
            putchar('a' + i - 1);
            printf(") %s", drink[i-1]);
            if(drinkPrices[i-1]>0) printf(" %d\n",drinkPrices[i-1]);
        }
        printf("\nf) Go back\n>");
        choice = getchar();
        getchar();
        drinksChoice = choice-'a';
        if(drinksChoice==5)
            goto FoodPick;
        else if(drinksChoice!=4)
            goto Cutlery;

    };
    Cutlery:
    {
        printf("Do you want any cutlery?\n");
        for(int i=0;i<2;i++){
            putchar('a'+i);
            printf(") %s\n",YesNo[i]);
        }
        printf("c) Go back\n>");
        choice=getchar();
        getchar();
        cutleryChoice=choice-'a';
        if(cutleryChoice==2)
        {
            sum=sum-drinkPrices[drinksChoice];
            goto DrinkPick;
        }
        else goto End;
    };
    End:
    {   char userInput[20];
        printf("Any additional info?\n>");
        gets(userInput);
        printf("This is your order:\n-------------------\n");
        printf("Name: %s\n",Username);
        printf("Food items:\n");
        printf("---%s %s: %d\n",foodOptions[foodsChoice],foods[foodsChoice][specialityChoice],prices[foodsChoice][specialityChoice]);
        printf("---Drink: %s: %d\n",drink[drinksChoice],drinkPrices[drinksChoice]);
        printf("Cutlery: %s\n",YesNo[cutleryChoice]);
        if(strlen(userInput)>0)
        printf("Additional info: %s\n",userInput);
        sum=prices[foodsChoice][specialityChoice]+drinkPrices[drinksChoice];
        printf("Payment amount: %d\n",sum);
        printf("-------------------\n");
        printf("a) Confirm order\nb) Go back\n>");
        choice=getchar();
        getchar();
        if(choice=='a')
            printf("Order confirmed! Thank you for buying from us, %s!",Username);
        if(choice=='b')
            goto Cutlery;

    };


    return 0;
}