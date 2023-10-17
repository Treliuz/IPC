/******************************************************************************
                          Workshop - #4 (P2)
Full Name  : Joseph Mwamba-Mukuna
Student ID#: 163997216
Email      : jmwamba-mukuna@myseneca.ca
Section    : NRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int apples, oranges, pears, tomatoes, cabbages;
    int remainingApples, remainingOranges, remainingPears, remainingTomatoes, remainingCabbages;
    int moreShopping = 1;

    while (moreShopping)
    {
        int picked = 0, applesPicked = 0, orangesPicked = 0, pearsPicked = 0, tomatoesPicked = 0, cabbagesPicked = 0;
        printf("\nGrocery Shopping\n");
        printf("================\n");

        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);

            if (apples < 0)
            {
            printf("ERROR: Value must be 0 or more.\n");
            }

        } while (apples < 0);
        printf("\n");

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);

            if (oranges < 0)
            {
            printf("ERROR: Value must be 0 or more.\n");
            }
        } while (oranges < 0);
        printf("\n");

        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);

            if (pears < 0)
            {
            printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pears < 0);
        printf("\n");

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);

            if (tomatoes < 0)
            {
            printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tomatoes < 0);
        printf("\n");

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);

            if (cabbages < 0)
            {
            printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabbages < 0);
        printf("\n");

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        if (apples > 0)
        {
            do
            {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &picked); 

            if (picked <= 0) 
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if (applesPicked + picked > apples)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apples - applesPicked);
            }

            else if (applesPicked + picked == apples)
            {
                printf("Great, that's the apples done!\n\n");
                applesPicked += picked;        
            }

            else if (applesPicked != apples)
            {
                printf("Looks like we still need some APPLES...\n");
                applesPicked += picked;
            }

            } while (applesPicked < apples);
        }

        if (oranges > 0)
        {
            do
            {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &picked); 

            if (picked <= 0) 
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if (orangesPicked + picked > oranges)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges - orangesPicked);
            }
            else if (orangesPicked + picked == oranges)
            {
                printf("Great, that's the oranges done!\n\n");
                orangesPicked += picked;        
            }

            else if (orangesPicked != oranges)
            {
                printf("Looks like we still need some ORANGES...\n");
                orangesPicked += picked;
            }

            } while (orangesPicked < oranges);
        }

        if (pears > 0)
        {
            do
            {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &picked); 

            if (picked <= 0) 
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if (pearsPicked + picked > pears)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pears - pearsPicked);
            }

            else if (pearsPicked + picked == pears)
            {
                printf("Great, that's the pears done!\n\n");
                pearsPicked += picked;        
            }

            else if (pearsPicked != pears)
            {
                printf("Looks like we still need some PEARS...\n");
                pearsPicked += picked;
            }

            } while (pearsPicked < pears);
        }

        if (tomatoes > 0)
        {
            do
            {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &picked); 

            if (picked <= 0) 
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if (tomatoesPicked + picked > tomatoes)
            {
                printf("You picked too many... only %d more TOMATOE(S) are needed.\n", tomatoes - tomatoesPicked);
            }

            else if (tomatoesPicked + picked == tomatoes)
            {
                printf("Great, that's the tomatoes done!\n\n");
                tomatoesPicked += picked;        
            }

            else if (tomatoesPicked != tomatoes)
            {
                printf("Looks like we still need some TOMATOES...\n");
                tomatoesPicked += picked;
            }

            } while (tomatoesPicked < tomatoes);
        }

        if (cabbages > 0)
        {
            do
            {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &picked); 

            if (picked <= 0) 
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if (cabbagesPicked + picked > cabbages)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages - cabbagesPicked);
            }

            else if (cabbagesPicked + picked == cabbages)
            {
                printf("Great, that's the cabbages done!\n\n");
                cabbagesPicked += picked;        
            }

            else if (cabbagesPicked != cabbages)
            {
                printf("Looks like we still need some CABBAGES...\n");
                cabbagesPicked += picked;
            }

            } while (cabbagesPicked < cabbages);
        }

        if (applesPicked == apples && orangesPicked == oranges && pearsPicked == pears && tomatoesPicked == tomatoes && cabbagesPicked == cabbages)
        {
            printf("All the items are picked!\n\n");
            printf("Do another shopping? (0=NO): ");
            scanf("%d", &moreShopping);
        } 
    }
    return 0;
}