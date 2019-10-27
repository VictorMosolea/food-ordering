#include <stdio.h>



int main() {
    int cutlerychoice;

    char YN[][4]={"Yes","No"};

    int sum=0;

    int drinkschoice;

    int nrofFoods=3;

    int nrofDrinks=4;

    char foodoptions[][10] = {"Pizza", "Pasta", "Salad"};

    int foodschoice;

    char choice;

    int specialitychoice;

    char drink[][10]= {"Fanta","Cola","Lemonade","Water","No, thanks"};

    int drinkprices[]= {5,4,8,6};

    char foods[3][3][11] = {
            {"Margherita", "Diavola", "Carbonara"},
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

        for (int i = 1; i <= nrofFoods; i++) {
            putchar('a' + i - 1);
            printf(") %s\n", foodoptions[i - 1]);
        }
        printf("d)Go back\n>");
        choice = getchar();
        getchar();
        foodschoice = choice - 'a';
        if (foodschoice == 3)
            goto Intro;
        else
            goto Foodpick;
    };

    Foodpick:
    {
        printf("Please choose the type of %s:\n",foodoptions[foodschoice]);
        for(int i=1;i<=nrofFoods;i++) {
                putchar('a'+i-1);
                printf(") %s %d\n",foods[foodschoice][i-1], prices[foodschoice][i-1]);
            }
            printf("d)Go back\n>");
            choice=getchar();
            getchar();
              specialitychoice=choice-'a';
            if(specialitychoice==3)
                goto Food;
            else
                goto Drinkpick;

    };

    Drinkpick:
    {
        printf("Please choose a drink to go with your %s:\n",foodoptions[foodschoice]);
        for(int i=1;i<=nrofDrinks;i++) {
            putchar('a' + i - 1);
            printf(") %s %d\n", drink[i-1],drinkprices[i-1]);
        }
        printf("e) No, thanks\n");
        printf("f) Go back\n>");
        choice = getchar();
        getchar();
        drinkschoice = choice-'a';
        if(drinkschoice==5)
            goto Foodpick;
        else if(drinkschoice!=4)
            goto Cutlery;

    };
    Cutlery:
    {
        printf("Do you want any cutlery?\n");
        for(int i=0;i<2;i++){
            putchar('a'+i);
            printf(") %s\n",YN[i]);
        }
        printf("c) Go back\n>");
        choice=getchar();
        getchar();
        cutlerychoice=choice-'a';
        if(cutlerychoice==2)
        {
            sum=sum-drinkprices[drinkschoice];
            goto Drinkpick;
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
        printf("---%s %s: %d\n",foodoptions[foodschoice],foods[foodschoice][specialitychoice],prices[foodschoice][specialitychoice]);
        printf("---%s: %d\n",drink[drinkschoice],drinkprices[drinkschoice]);
        printf("Cutlery: %s\n",YN[cutlerychoice]);
        printf("Additional info: %s\n",userInput);
        sum=prices[foodschoice][specialitychoice]+drinkprices[drinkschoice];
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