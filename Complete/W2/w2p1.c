/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name :Joseph Mwamba-Mukuna
Student ID#: 163997216
Email :jmwamba-mukuna@myseneca.ca
Section :NRA

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double smallPrice, medPrice, largePrice;
    double subtotal;
    double Taxtotal;
    double Total;
    int shirtNum;
    int intSubtotal;
    int intTax;
    int intTotal;
    //Input price for shirt sizes
    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("\n%lf", &smallPrice);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("\n%lf", &medPrice);

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largePrice);
    //Displaying previously stored prices
    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", smallPrice);
    printf("MEDIUM : $%.2lf\n", medPrice);
    printf("LARGE  : $%.2lf\n\n", largePrice);
    //Input number of shirts bought
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirtNum);
    //Calculating receipt information
    intSubtotal = (int)(smallPrice * 100);
    subtotal = (float)(intSubtotal * shirtNum) / 100;

    intTax = (int)((subtotal * TAX + 0.005) * 100);
    Taxtotal = (float)(intTax) / 100;

    intTotal = (int)((subtotal + Taxtotal + 0.005) * 100);
    Total = (float)(intTotal) / 100;
    //Printing receipt
    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", shirtNum);
    printf("Sub-total: $%8.4lf\n", subtotal);
    printf("Taxes    : $%8.4lf\n", Taxtotal);
    printf("Total    : $%8.4lf\n", Total);
    
    return 0;
}