/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name  : Joseph Mwamba-Mukuna
Student ID#: 163997216
Email      : jmwamba-mukuna@myseneca.ca
Section    : NRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ITEMS 10

#include <stdio.h>

int main(void)
{
    const double minIncome = 500.00;
    const double maxIncome = 400000.00;
    const double minCost = 100.00;
    int wishlistInput=0;
    int prioInput[MAX_ITEMS];
    int i;
    int k;
    int validInput=0;
    double incomeInput;
    double costsInput[MAX_ITEMS];
    double sum=0;
    char financeInput[MAX_ITEMS];
    char valid[] = "y";
    char invalid[] ="n";

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    do
    {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &incomeInput);

        if (incomeInput < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }

        else if (incomeInput > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }

    } while (incomeInput < minIncome || incomeInput > maxIncome);

    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &wishlistInput);
        
        if (wishlistInput <= 0 || wishlistInput > MAX_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        } 

    } while (wishlistInput <= 0 || wishlistInput > MAX_ITEMS);

    for (i = 0; i < wishlistInput; i++)
    {
        printf("\nItem-%d Details:\n", i + 1);

        validInput = 1;
        while (validInput)
        {
            printf("   Item cost: $");
            scanf("%lf", &costsInput[i]);
            if (costsInput[i] < minCost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }

            else 
            {
                validInput=0;
            }
        }

        validInput = 1;
        while (validInput)
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &prioInput[i]);

            if (prioInput[i] < 1 || prioInput[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else
            { 
                validInput=0;
            }
        }

        validInput = 1;
        while (validInput)
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf("%s", &financeInput[i]);
            if (financeInput[i] == valid[0] || financeInput[i] == invalid[0])
            {
                validInput=0;
            }

            else
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        }
    }

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (k = 0; k < i; k++)
    {
            printf("%3d  %5d    %5c    %11.2lf\n", k + 1, prioInput[k], financeInput[k], costsInput[k]);
            sum = sum + costsInput[k];
    }

    printf("---- -------- -------- -----------\n"); 
    printf("                      $%11.2lf\n\n",sum);
    printf("Best of luck in all your future endeavours!\n");
    return 0;
}